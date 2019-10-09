#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "ui_GameCall.h"
#include "Utils.h"
class GameCall : public QMainWindow
{
	Q_OBJECT

public:
	GameCall(QWidget *parent = Q_NULLPTR);

public slots:
	void exec(QList<QString>data);
	void pidFreshBtn();
	void aboutBtn();
	void changeWinSizeBtn();
	void freshWinSizeBtn();
	void callBtn();
	void callSignBtn();
	void listDoubleclicked(QListWidgetItem* item);
private:
	Ui::GameCallClass ui;
	Utils *pUtils = nullptr;
	static GameCall *gameCall;
	//��ȡ���þ��
	HWND AppWnd;
	//����Ϸ�߳�
	HANDLE hProcess;
	//�����ԭ�Ӵ��ڴ�С
	RECT orgRect;
	
signals:
	///@brief �ڱ���߳��к���������  
	void commingc(QList<QString>data);

private:
	
	void initUI();
	void initData(); 
};
