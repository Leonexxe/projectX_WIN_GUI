/*############################################################################################################
# File: c:\PX_WIN_UI\projectX_WIN_GUI\PROJECTX_CLI.cpp                                                       #
# Project: c:\PX_WIN_UI\projectX_WIN_GUI                                                                     #
# Created Date: Monday, September 13th 2021, 9:07:09 am                                                      #
# Author: Leonexxe (Leon Marcellus Nitschke-Höfer)                                                           #
# -----                                                                                                      #
# Copyright (c) 2021 Leon Marcellus Nitschke-Höfer (Leonexxe)                                                #
# -----                                                                                                      #
# You may not remove or alter this copyright header.                                                         #
############################################################################################################*/
#include "include.h"
#include "windows.h"
#include "csignal"

//typedefs
typedef std::string (CALLBACK* getINIFunc)(std::string,std::string);
typedef void (CALLBACK* launchCLIFunc)(int,char**);

HINSTANCE hDLL_CLI;              // Handle to CLI DLL
getINIFunc getINI;  // function pointer to the getINI function in the dll
launchCLIFunc launchCLI;  // function pointer to the getINI function in the dll

void getDLL_CLI_HANDLE()
{
    std::cout << "loading projectX_CLI.dll..." << std::endl;
    hDLL_CLI = LoadLibrary(LPCWSTR("C:/PX_WIN_UI/projectX_WIN_GUI/build/Debug/projectX_CLI.dll"));
    if(hDLL_CLI == NULL)
        std::cout << "ERROR: " << GetLastError() << std::endl;raise(3);

    //~ assign function pointers
    getINI = (getINIFunc)GetProcAddress(hDLL_CLI,"?getINI@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@0@Z");
    launchCLI = (launchCLIFunc)GetProcAddress(hDLL_CLI,"?launchCLI@@YAXHPAPAD@Z");
    if(!(getINI != NULL))
        std::cout << "Error: getINI function not found in dll" << std::endl;raise(3);
    if(!(launchCLI != NULL))
        std::cout << "Error: launchCLI function not found in dll" << std::endl;raise(3);
}
