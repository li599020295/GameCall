#pragma once
#include <Windows.h>
#include <QtWidgets/QWidget> 
#include <QMap> 
class StringValue
{
public:
	StringValue();
	~StringValue();
	static QString getStringValue(int v);
	static StringValue * getInstance();
private:
	static StringValue * pStringValue;
	static QMap<int,QString> stringValueMap;
};

