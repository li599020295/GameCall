#include "GameCall.h"
#include <QMessageBox>
#include "StringValue.h"
//保存所有活动的句柄
QVector<HWND> vHandleWindow;
//全局静态实例
GameCall *GameCall::gameCall = nullptr; 
//全局实例
GameCall *globalGameCall = nullptr;
//全局CallStr
std::string callStr = "";
GameCall::GameCall(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initData();
	initUI();
}

void GameCall::exec(QList<QString>data) {
	ui.listWidget->addItems(data);
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	QList<QString> dataList;
	//窗口是否可视
	if (!::IsWindowVisible(hwnd))
		return TRUE;

	//窗口是否可激活
	if (!::IsWindowEnabled(hwnd))
		return TRUE;

	//确定给定窗口是否是最小化（图标化）的窗口。
	//if(IsIconic(hwnd))
	//  return TRUE;

	//窗口是否具有父窗口？
	HWND hParent = (HWND)GetWindowLong(hwnd, GWL_HWNDPARENT);
	//父窗口是否可激活？
	//据 Spy++ 观察，如“运行”对话框等被应列入列表的程序有一个隐藏的，具有 WS_DISABLED 的父窗口
	if (IsWindowEnabled(hParent))
		return TRUE;
	//父窗口是否可视？
	if (IsWindowVisible(hParent))
		return TRUE;

	LONG gwl_style = GetWindowLong(hwnd, GWL_STYLE);
	if ((gwl_style & WS_POPUP) && !(gwl_style & WS_CAPTION))
		return TRUE;

	CHAR caption[512];
	memset(caption, 0, sizeof(caption));
	::GetWindowTextA(hwnd, caption, 511);

	if (strcmp(caption, ""))
	{
		if (GetClassLong(hwnd, GCL_HICON))
		{
			HICON hIcon = (HICON)GetClassLong(hwnd, GCL_HICON);
			if (hIcon)
			{
				//handleIcon.push_back(hIcon);
			}
			std::string strData = caption;
			dataList.push_back(QString::fromLocal8Bit(strData.data()));
			vHandleWindow.push_back(hwnd);
			emit globalGameCall->commingc(dataList);
		}
		
	}
	
	return TRUE;
}

void GameCall::initData() {
	connect(this, SIGNAL(commingc(QList<QString>)), this, SLOT(exec(QList<QString>)), Qt::AutoConnection);
	connect(ui.pidFreshBtn, SIGNAL(clicked()), this, SLOT(pidFreshBtn()));
	connect(ui.aboutBtn, SIGNAL(clicked()), this, SLOT(aboutBtn()));
	connect(ui.callBtn, SIGNAL(clicked()), this, SLOT(callBtn()));
	connect(ui.callSignButton, SIGNAL(clicked()), this, SLOT(callSignBtn()));
	connect(ui.changeCKSizeBtn, SIGNAL(clicked()), this, SLOT(changeWinSizeBtn()));
	connect(ui.refreshSizeButton, SIGNAL(clicked()), this, SLOT(freshWinSizeBtn()));
	connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(listDoubleclicked(QListWidgetItem*)));
	gameCall = this;
	globalGameCall = this;
	pUtils = Utils::getInstance();
	StringValue::getInstance();
	//提升进程权限
	BOOL isPro = Utils::ImproveProcPriv();
	if (!isPro) {
		return;
	}
	EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(this));
}

void GameCall::initUI() {}

void GameCall::pidFreshBtn() {
	ui.listWidget->clear();
	vHandleWindow.clear();
	EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(this));
}

void GameCall::listDoubleclicked(QListWidgetItem* item) {
	int datasIndex = ui.listWidget->currentRow();
	QString text = item->text(); 
	Utils::getProcessAllAccess(text, AppWnd, hProcess, orgRect);
	ui.CKWidthEdit->setText(QString::number(orgRect.right - orgRect.left));
	ui.CKHeightEdit->setText(QString::number(orgRect.bottom - orgRect.top));
}

void GameCall::changeWinSizeBtn() {
	int width = ui.CKWidthEdit->text().toInt();
	int height = ui.CKHeightEdit->text().toInt();
	if (AppWnd != NULL && IsWindow(AppWnd)) {
		::MoveWindow(AppWnd, orgRect.left, orgRect.top,  width,  height, TRUE);
	}
	/*if (AppWnd != NULL && IsWindow(AppWnd)) {
		::MoveWindow(AppWnd, orgRect.left, orgRect.top, orgRect.left + orgRect.right, orgRect.top + orgRect.bottom, TRUE);
	}*/
}

void GameCall::freshWinSizeBtn() {
	if (AppWnd != NULL && IsWindow(AppWnd)) {
		::MoveWindow(AppWnd, orgRect.left, orgRect.top, orgRect.right, orgRect.bottom, TRUE);
	}
}


void  CallAddhp()
{ 
	DWORD dwAddr = 0x00401362;
	_asm
	{
		pushad
		call dwAddr
		popad
	}
}

void RemoteCall(int callAddr, HWND AppWnd)
{
	//获取窗口句柄 
	if (AppWnd == NULL)
	{
		QMessageBox::information(NULL, "note", "No Window", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	//获取窗口进程Id
	DWORD Pid = 0;
	::GetWindowThreadProcessId(AppWnd, &Pid);

	//打开窗口进程
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, TRUE, Pid);
	if (hProcess == NULL)
	{
		//AfxMessageBox(_T("打开窗口进程失败!"));
		return;
	}

	//远程调用Call
	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)(callAddr), NULL, 0, NULL);

	CloseHandle(hThread);
	CloseHandle(hProcess);
}

void GameCall::callSignBtn() { 
	DWORD ProcessId = NULL;
	GetWindowThreadProcessId(AppWnd, &ProcessId);
	QString address = ui.callAddresEdit->text(); //0x00401362
	RemoteCall(address.toInt(NULL, 16), AppWnd);
}

void GameCall::callBtn() {
	callStr = ui.callTextEdit->windowIconText().toStdString();
	DWORD ProcessId = NULL;
	GetWindowThreadProcessId(AppWnd, &ProcessId); 
	QString address = ui.callAddresEdit->text(); //0x00401362
	RemoteCall(address.toInt(NULL, 16), AppWnd);
	//Utils::InfusionFunc(ProcessId, CallAddhp, NULL, NULL);
}

void GameCall::aboutBtn() {
	QMessageBox msg(this);//对话框设置父组件
	msg.setWindowTitle(StringValue::getStringValue(4));//对话框标题
	msg.setText(StringValue::getStringValue(5));//对话框提示文本
	msg.setIcon(QMessageBox::Information);//设置图标类型
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );//对话框上包含的按钮
	msg.exec(); 
}



