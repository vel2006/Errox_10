import os
#create a method for error handling
def DisplayError(errorProneMethod, error):
    print(f"Error when running method: \"{errorProneMethod}\"\nError: {error}")
    print("Press <Enter> to exit file...")
    input()
    exit()
#cerate a method for installing needed packages
def InstallNeededPackages(clientOrServer):
    if clientOrServer == "client":
        try:
            with open("requirements.txt", "w") as file:
                file.write("requests==2.32.3\n")
                file.close()
            os.system("python -m pip install -r requirements.txt")
        except Exception as error:
            DisplayError("InstallNeededPackages", str(error))
    else:
        try:
            with open("requirements.txt", "w") as file:
                file.write("requests==2.32.3\n")
                file.close()
            os.system("python -m pip install -r requirements.txt")
        except Exception as error:
            DisplayError("InstallNeededPackages", str(error))
#create a method for getting values inbetween strings
def GetInbetween(inputText, inputStartingPoint, inputEndingPoint):
    startIndex = inputText.find(inputStartingPoint)
    endingIndex = inputText.find(inputEndingPoint, startIndex + len(inputText))
    if startIndex != -1 and endingIndex != -1:
        return inputText[startIndex + len(inputStartingPoint):endingIndex]
    else:
        DisplayError("GetInbetween", "Range not in bounds.")
#create a method for testing to see if the client is connected to the internet / can access github pages
def TestInternet():
    print("Work in prgress")
    import requests
    if requests.get("https://vel2006.github.io/Errox_10/testConnectionPage.html").status_code == 200:
        return True
    else:
        return False
#create a method for installing something from the web / spesific page
def InstallFileFromWeb(inputPageLink, outputFileLocation):
    try:
        import requests
        responseFromWebPage = requests.get(inputPageLink)
        if responseFromWebPage.status_code == 200:
            with open(outputFileLocation, "w") as file:
                for line in GetInbetween(responseFromWebPage.text, "<body>", "</body>").splitlines():
                    if "<p>" in line:
                        file.write(GetInbetween(line, "<p>", "</p>") + '\n')
                file.close()
    except Exception as error:
        DisplayError("InstallFileFromWeb", error)
#create a method for creating needed files if the web is down or not avalable
def CreateFromScratch(inputInstallVersion, outputFileLocation):
    try:
        if inputInstallVersion == "client":
            with open(outputFileLocation, "w") as file:
                file.write("VERSION:0.1\n")
                file.close()
        else:
            with open(outputFileLocation, "w") as file:
                file.write("VERSION:0.1\n")
                file.close()
    except Exception as error:
        DisplayError("CreateFromScratch", error)
#create a method for checking to see if Errox_10 has already been installed
def CheckForAlreadyInstalled():
    if "<CHANGEME>" == "INSTALLEDERROX_10":
        return True
    else:
        return False
#create a method for updating the passed script
def CheckNeedToUpdateCurrentVersion(clientOrServer):
    import re
    import requests
    if TestInternet():
        try:
            pattern = r'VERSION:(.*)'
            versionLine = ""
            with open(f"C:\\Users\\{os.getlogin()}\\Errox_10\\{clientOrServer}.py", "r") as file:
                versionLine = file.readline().strip()
                file.close()
            patternMatch = re.search(pattern, versionLine)
            currentVersion =  patternMatch.group(1).strip()
            pageResponse = requests.get("https://vel2006.github.io/Errox_10/newestWindowsVersions.html")
            updatedVersion = ""
            pageClientPattern = r'CLIENT_VERSION:(.*)'
            pageServerPattern = r'SERVER_VERSION:(.*)'
            for line in GetInbetween(pageResponse.text, "<body>", "</body>").splitlines():
                if "<p>" in line:
                    patternPageMatch = ""
                    pageLineContent = GetInbetween(line, "<p>", "</p>")
                    if clientOrServer == "client":
                        patternPageMatch = re.search(pageClientPattern, pageLineContent)
                    else:
                        patternPageMatch = re.search(pageServerPattern, pageLineContent)
                    if patternPageMatch:
                        updatedVersion = patternPageMatch.group(1).strip()
                        break
            if clientOrServer == "client":
                if updatedVersion != currentVersion:
                    return "Needs Update"
                else:
                    return "Up To Update"
        except Exception as error:
            DisplayError("UpdateCurrentVersion", error)
    else:
        DisplayError("UpdateCurrentVersion", "No internet conenction")
#create a method for the user handling
def HandleUser():
    #Put ASCII art here...
    print("<art for ERROX_10...>")
    print("Welcome to the insaller program, here is a list of commands to use for instalation:")
    print(" COMMAND    |    OUTPUT \n    Help    | Displays this message")
    print("   Install  | Will install the prompted version (client or server)\n    End     | Will end this program")
    print("   Update   | Will check the current version of Errox_10 and update it if there is a newer version")
    while True:
        print("")
        choice = input(">")
        match choice:
            case "Help":
                print(" COMMAND    |    OUTPUT \n    Help    | Displays this message")
                print("   Install  | Will install the prompted version (client or admin)\n    End     | Will end this program")
                print("   Update   | Will check the current version of Errox_10 and update it if there is a newer version")
            case "Install":
                print("Which version of Errox_10 do you wish to install?")
                print("Client (end user / staff) or Server (admin)")
                installType = ""
                while True:
                    print("")
                    installType = input(">")
                    if installType != "Client" and installType != "client" and installType != "Server" and installType != "server":
                        print("Invalid selection, available ones: Client or Server")
                    else:
                        break
                try:
                    os.mkdir(f"C:\\Users\\{os.getlogin()}\\Errox_10")
                except Exception as error:
                    DisplayError("HandleUser", error)
                if TestInternet():
                    if installType.lower() == "client":
                        InstallNeededPackages("client")
                        InstallFileFromWeb("https://vel2006.github.io/Errox_10/windowsClient.html", f"C:\\Users\\{os.getlogin()}\\Errox_10\\client.py")
                    else:
                        InstallNeededPackages("server")
                        InstallFileFromWeb("https://vel2006.github.io/Errox_10/windowsServer.html", f"C:\\Users\\{os.getlogin()}\\Errox_10\\server.py")
                else:
                    if installType.lower() == "client":
                        InstallNeededPackages("client")
                        CreateFromScratch("client", f"C:\\Users\\{os.getlogin()}\\Errox_10\\client.py")
                    else:
                        InstallNeededPackages("server")
                        CreateFromScratch("server", f"C:\\Users\\{os.getlogin()}\\Errox_10\\server.py")
            case "Update":
                print("Checking for current version...")
                if os.path.exists(f"C:\\Users\\{os.getlogin()}\\Errox_10"):
                    print("Errox_10 folder found, checking for type...")
                    if os.path.exists(f"C:\\Users\\{os.getlogin()}\\Errox_10\\client.py"):
                        print("Client version found, checking version...")
                        if CheckNeedToUpdateCurrentVersion("client") == "Needs Update":
                            print("Updating Errox_10 client...")
                            os.remove(f"C:\\Users\\{os.getlogin()}\\Errox_10\\client.py")
                            InstallFileFromWeb("https://vel2006.github.io/Errox_10/windowsClient.html")
                        else:
                            print("Errox_10 client is up to date!")
                    elif os.path.exists(f"C:\\Users\\{os.getlogin()}\\Errox_10\\server.py"):
                        print("Server version found, checking version...")
                        if CheckNeedToUpdateCurrentVersion("server") == "Needs Update":
                            print("Updating Errox_10 server...")
                            os.remove(f"C:\\Users\\{os.getlogin()}\\Errox_10\\server.py")
                            InstallFileFromWeb("https://vel2006.github.io/Errox_10/windowsServer.html")
                        else:
                            print("Errox_10 server is up to date!")
                    else:
                        DisplayError("HandleUser", "No version of Errox_10 is installed")
            case default:
                print("Error, invalid selection, use \"Help\" for list of usable commands")
HandleUser()
