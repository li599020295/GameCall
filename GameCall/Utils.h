#pragma once
#include <Windows.h>
#include <QtWidgets/QWidget>
class Utils
{
private:
	static Utils *utils;
public:
	Utils();
	~Utils();
	static Utils*getInstance();
	//提升进程权限
	static BOOL ImproveProcPriv();
	//获取访问进程
	static void getProcessAllAccess(QString progressName,HWND &hwnd,HANDLE& hProcess, RECT &orgRect);
	//调用call
	static void InfusionFunc(DWORD dwProcId, LPVOID mFunc, LPVOID pRemoteParam, DWORD ParamSize);
};

