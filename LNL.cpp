#ifdef INCLUDE_LNL
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define PX_NET_NO_SERVER
#define NO_MOD_SERVER
#define PX_APP_NO_USE_NET_SERVER
#pragma warning(disable:4146)
#include <PX_WCLI/main.h>

void main_UI(px::application<PX_THREADSLOTS>* app)
{
}

void log_UI(std::string* msg)
{
}
#pragma message "LNL compiled"
#endif