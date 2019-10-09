#include "GameCall.h"
#include <QMessageBox>
#include "StringValue.h"
//�������л�ľ��
QVector<HWND> vHandleWindow;
//ȫ�־�̬ʵ��
GameCall *GameCall::gameCall = nullptr; 
//ȫ��ʵ��
GameCall *globalGameCall = nullptr;
//ȫ��CallStr
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
	//�����Ƿ����
	if (!::IsWindowVisible(hwnd))
		return TRUE;

	//�����Ƿ�ɼ���
	if (!::IsWindowEnabled(hwnd))
		return TRUE;

	//ȷ�����������Ƿ�����С����ͼ�껯���Ĵ��ڡ�
	//if(IsIconic(hwnd))
	//  return TRUE;

	//�����Ƿ���и����ڣ�
	HWND hParent = (HWND)GetWindowLong(hwnd, GWL_HWNDPARENT);
	//�������Ƿ�ɼ��
	//�� Spy++ �۲죬�硰���С��Ի���ȱ�Ӧ�����б�ĳ�����һ�����صģ����� WS_DISABLED �ĸ�����
	if (IsWindowEnabled(hParent))
		return TRUE;
	//�������Ƿ���ӣ�
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
	//��������Ȩ��
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
	//��ȡ���ھ�� 
	if (AppWnd == NULL)
	{
		QMessageBox::information(NULL, "note", "No Window", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	//��ȡ���ڽ���Id
	DWORD Pid = 0;
	::GetWindowThreadProcessId(AppWnd, &Pid);

	//�򿪴��ڽ���
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, TRUE, Pid);
	if (hProcess == NULL)
	{
		//AfxMessageBox(_T("�򿪴��ڽ���ʧ��!"));
		return;
	}

	//Զ�̵���Call
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
	QMessageBox msg(this);//�Ի������ø����
	msg.setWindowTitle(StringValue::getStringValue(4));//�Ի������
	msg.setText(StringValue::getStringValue(5));//�Ի�����ʾ�ı�
	msg.setIcon(QMessageBox::Information);//����ͼ������
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );//�Ի����ϰ����İ�ť
	msg.exec(); 
}



