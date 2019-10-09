#include "Utils.h"
#include "StringValue.h"
Utils *Utils::utils = nullptr;
Utils::Utils()
{
}

Utils* Utils::getInstance() {
	if (utils == nullptr) {
		utils = new Utils();
	}
	return utils;
}

//提升进程权限
BOOL Utils::ImproveProcPriv()
{
	HANDLE token;
	QString error = StringValue::getStringValue(1);
	QString error1 = StringValue::getStringValue(2);
	QString error2 = StringValue::getStringValue(3);
	//提升权限
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &token))
	{
		MessageBox(NULL, error1.toStdWString().c_str(), error.toStdWString().c_str(), MB_ICONSTOP);
		return FALSE;
	}
	TOKEN_PRIVILEGES tkp;
	tkp.PrivilegeCount = 1;
	::LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tkp.Privileges[0].Luid);
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!AdjustTokenPrivileges(token, FALSE, &tkp, sizeof(tkp), NULL, NULL))
	{
		MessageBox(NULL, error2.toStdWString().c_str(), error.toStdWString().c_str(), MB_ICONSTOP);
		return FALSE;
	}
	CloseHandle(token);
	return TRUE;
}

void Utils::getProcessAllAccess(QString progressName,HWND &hwnd,HANDLE &hProcess, RECT &orgRect) {

	hwnd = ::FindWindowA(NULL, progressName.toStdString().c_str());
	::GetWindowRect(hwnd, &orgRect);
	//
	DWORD dwPID = 0;
	GetWindowThreadProcessId(hwnd, &dwPID);	//获取进程标识
	if (dwPID == 0)
	{
		printf_s("获取PID失败\n");
		dwPID = NULL;
	}

	hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPID);
	if (hProcess == NULL)
	{
		printf_s("进程打开失败\n");
		hProcess = NULL;
	}
	return; 
}


//************************************************************************************** 
//函数名：InfusionFunc 
//功能  ：封装远程注入的函数 
//参数 1：进程ID  
//参数 2：被注入函数指针<函数名>  
//参数 3：参数  
//参数 4：参数长度  
//************************************************************************************** 
void Utils::InfusionFunc(DWORD dwProcId, LPVOID mFunc, LPVOID pRemoteParam, DWORD ParamSize)
{
	HANDLE hProcess;
	LPVOID ThreadAdd;
	LPVOID ParamAdd = NULL;
	HANDLE hThread = NULL;
	DWORD lpNumberOfBytes;
	BOOL BO;

	ThreadAdd = mFunc;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcId);//打开被注入的进程
	ThreadAdd = VirtualAllocEx(hProcess, NULL, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	BO = WriteProcessMemory(hProcess, ThreadAdd, mFunc, 4096, &lpNumberOfBytes);//写入函数地址
	if (ParamSize != 0) {
		ParamAdd = VirtualAllocEx(hProcess, NULL, ParamSize, MEM_COMMIT, PAGE_READWRITE);
		BO = WriteProcessMemory(hProcess, ParamAdd, pRemoteParam, ParamSize, &lpNumberOfBytes);
	}
	hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)ThreadAdd, ParamAdd, 0, &lpNumberOfBytes);
	WaitForSingleObject(hThread, INFINITE);
	VirtualFreeEx(hProcess, ThreadAdd, 4096, MEM_RELEASE);

	if (ParamSize != 0) {
		VirtualFreeEx(hProcess, ParamAdd, ParamSize, MEM_RELEASE);
	}
	CloseHandle(hThread);
	CloseHandle(hProcess);
	
}

Utils::~Utils()
{
}
