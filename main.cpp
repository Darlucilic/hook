#include <windows.h>
#include "vulkan/vulkan.h"

#if defined _M_X64
#pragma comment(lib, "vklibx64/vulkan-1.lib")
#elif defined _M_IX86
#pragma comment(lib, "vklibx86/vulkan-1.lib") 
#endif

#include "MinHook/include/MinHook.h"

bool FirstInit = false; //init once
int countnum = -1;

#include <fstream>
using namespace std;
char dlldir[320];
char* GetDirectoryFile(char *filename)
{
	static char path[320];
	strcpy_s(path, dlldir);
	strcat_s(path, filename);
	return path;
}

void Log(const char *fmt, ...)
{
	if (!fmt)	return;

	char		text[4096];
	va_list		ap;
	va_start(ap, fmt);
	vsprintf_s(text, fmt, ap);
	va_end(ap);

	ofstream logfile(GetDirectoryFile("log.txt"), ios::app);
	if (logfile.is_open() && text)	logfile << text << endl;
	logfile.close();
}

//==========================================================================================================================
