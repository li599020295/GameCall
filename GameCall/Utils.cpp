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

//��������Ȩ��
BOOL Utils::ImproveProcPriv()
{
	HANDLE token;
	QString error = StringValue::getStringValue(1);
	QString error1 = StringValue::getStringValue(2);
	QString error2 = StringValue::getStringValue(3);
	//����Ȩ��
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
	GetWindowThreadProcessId(hwnd, &dwPID);	//��ȡ���̱�ʶ
	if (dwPID == 0)
	{
		printf_s("��ȡPIDʧ��\n");
		dwPID = NULL;
	}

	hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPID);
	if (hProcess == NULL)
	{
		printf_s("���̴�ʧ��\n");
		hProcess = NULL;
	}
	return; 
}


//************************************************************************************** 
//��������InfusionFunc 
//����  ����װԶ��ע��ĺ��� 
//���� 1������ID  
//���� 2����ע�뺯��ָ��<������>  
//���� 3������  
//���� 4����������  
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
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcId);//�򿪱�ע��Ľ���
	ThreadAdd = VirtualAllocEx(hProcess, NULL, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	BO = WriteProcessMemory(hProcess, ThreadAdd, mFunc, 4096, &lpNumberOfBytes);//д�뺯����ַ
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
