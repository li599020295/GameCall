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
	//��������Ȩ��
	static BOOL ImproveProcPriv();
	//��ȡ���ʽ���
	static void getProcessAllAccess(QString progressName,HWND &hwnd,HANDLE& hProcess, RECT &orgRect);
	//����call
	static void InfusionFunc(DWORD dwProcId, LPVOID mFunc, LPVOID pRemoteParam, DWORD ParamSize);
};

