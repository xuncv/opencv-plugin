#include <windows.h>
#include <stdio.h>
#include <stdarg.h>


void ShowDbgInfo(const char* data, ...)
{
	char temp[2048];

	auto logFile = fopen("debug.log", "a+");

	SYSTEMTIME st;
	GetLocalTime(&st);
	sprintf(temp, "DLL»’÷æ ‰≥ˆ: %d-%d-%d %02d£∫%02d£∫%02d£∫%03d ", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	OutputDebugStringA(temp);
	fprintf(logFile, "%s", temp);

	va_list ap;
	va_start(ap, data);
	vsprintf(temp, data, ap);
	OutputDebugStringA(temp);
	va_end(ap);

	fprintf(logFile, "%s \n", temp);
	fflush(logFile);
}