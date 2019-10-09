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
	//获取到得句柄
	HWND AppWnd;
	//打开游戏线程
	HANDLE hProcess;
	//句柄得原视窗口大小
	RECT orgRect;
	
signals:
	///@brief 在别的线程有函数对象传来  
	void commingc(QList<QString>data);

private:
	
	void initUI();
	void initData(); 
};
