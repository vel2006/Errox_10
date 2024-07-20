#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

int main()
{
    int mode;
    bool loopCheck = true;
    while (loopCheck)
    {
        //Getting the instalation method through a multable choice
        printf("[+] Which instalation method do you wish to use\n[1] Create Server\n[2] Create Client\n[3] Help\n");
        printf(">");
        scanf("%d", &mode);
        switch (mode)
        {
            case 1:
                printf("Work in progress\n");
                loopCheck = false;
                break;
            case 2:
                // Creating a file opening variable
                FILE *fptr;
                // Creating a batch file for checking that python version and so forth
                fptr = fopen("systemCheck.bat", "w");
                fprintf(fptr, "@echo off\nsetlocal\necho Checking For Python\nwhere python >nul 2>&1\nif %%errorLevel%% equ 0 (\n\techo Python Installed\n\tgoto installed\n) else (\n\tset \"pythonURL=https://www.python.org/ftp/python/3.10.5/python-3.10.5-amd64.exe\"\n\tset \"pythonInstaller=python-3.10.5-amd64.exe\"\n\tbitsadmin /transfer mydownloadjob /download /priority normal %%pythonInstallerUrl%% %%pythonInstaller%%\n\tif not exist %%pythonInstaller%% (\n\t\techo Failed to Install Python, do it manually\n\t\tgoto end\n\t) else (\n\t\t%%pythonInstaller%% /quiet InstallAllUsers=1 PrependPath=1\n\t)\n\twhere python >nul 2>&1\n\tif %%errorLevel%% equ 0(\n\t\techo Python Installed safely.\n\t) else (\n\t\techo Python didnt Install correctly, install it manually.\n\t)\n)");
                fclose(fptr);
                // Creating a python file for installing the page information
                fptr = fopen("install.py", "w");
                fprintf(fptr, "import requests\nimport os\nimport sys\n \ndef getInbetween(text_in, start_point, end_point):\n\tstart_index = text_in.find(start_point)\n\tend_index = text_in.find(end_point, start_index + len(start_point))\n\tif start_index != -1 and end_index != -1:");
                fprintf(fptr, "\n\t\treturn text_in[start_index + len(start_point):end_index]\n \nurl = \"https://vel2006.github.io/Errox_10/Windows.html\"\nres = requests.get(url)\nif res.status_code == 200:\n\tsource = getInbetween(res.text, \"<body>\", \"</body>\")");
                fprintf(fptr, "\n\tfor line in source.splitlines():\n\t\tif \"<p>\" in line:\n\t\t\twith open(os.getcwd()+\"\\Bordie.py\", 'a') as file:\n\t\t\t\tfile.write((getInbetween(line, \"<p>\", \"</p>\")) + '\\n')\n\turl = \"https://vel2006.github.io/Errox_10/Windows_Per.html\"");
                fprintf(fptr, "\n\tres2 = requests.get(url)\n\tif res2.status_code == 200:\n\t\tsource2 = getInbetween(res2.text, \"<body>\", \"</body>\")\n\t\tfor line in source2.splitlines():\n\t\t\tif \"<p>\" in line:\n\t\t\t\twith open(os.getcwd()+\"\\Per.bat\", 'a') as file:");
                fprintf(fptr, "\n\t\t\t\t\tfile.write((getInbetween(line, \"<p>\", \"</p>\")) + '\\n')\nelse:\n\ttry:\n\t\tos.remove(os.getcwd()+\"\\runner.bat\")\n\t\tos.remove(os.getcwd()+\"\\Install.py\")\n\texcept OSError as error:\n\t\tpass");
                fclose(fptr);
                loopCheck = false;
                break;
            case 3:
                printf("[+] Help menu:\n[#] Server mode: Used on the admin side of Errox_10. It will allow you to see the device's usage and remotly access a client through it's CMD\n[#] Client mode: Used on the client side of Errox_10. It is what allows 'server' mode to access the client and get its information.\n");
                printf("[+] Support the creator at:\n[#] https:github.com/vel2006\n[#] https://www.youtube.com/@That1EthicalHacker");
            default:
                printf("[+] Error, invalid option.\n[#] Options are:\n[1] = Installs server mode for Errox_10\n[2] = Installs client mode for Errox_10\n[3] = Displays help menu\n");
        }
    }
    printf("[+] Press <Enter> To Quit ...");
    getchar();
    return 0;
}
