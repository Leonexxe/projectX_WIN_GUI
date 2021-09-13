#define _UNICODE
#define UNICODE
#define wxUSE_UNICODE
//#define WXUSINGDLL
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define PX_NET_NO_SERVER
#define NO_MOD_SERVER
#define PX_APP_NO_USE_NET_SERVER
#define NO_RANDKEY
#define NO_MAIN
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "projectX_CLI.lib")
#pragma warning(disable:4146)

#include "LNL.cpp"
#include "cApp.cpp"
#include "include.h"
int main(int argc, char** argv)
{
	//- get DLL handle
	getDLL_CLI_HANDLE();
	//- launch
	//launchUI = &main_UI;
	//UI_LOG = &log_UI;
	launchCLI(argc,argv);
	getINI("THEME","backgroundImage");
	return 0;
}
