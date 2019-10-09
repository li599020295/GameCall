#include "StringValue.h"

StringValue* StringValue::pStringValue = nullptr;
QMap<int, QString> StringValue::stringValueMap;
StringValue::StringValue()
{
	stringValueMap.insert(1, QStringLiteral("����"));
	stringValueMap.insert(2, QStringLiteral("�򿪽�������ʧ��..."));
	stringValueMap.insert(3, QStringLiteral("��������Ȩ��ʧ��...")); 
	stringValueMap.insert(4, QStringLiteral("����")); 
	stringValueMap.insert(5, QStringLiteral("�����������ڷǷ�;��������������ڵ��ԺͲ��ԡ�Power By С�� QQ:599020295��"));
	stringValueMap.insert(6, QStringLiteral("���ޣ�˫�����ӽ��̣�"));
}

StringValue * StringValue::getInstance() {
	if (pStringValue == nullptr) {
		pStringValue = new StringValue();
	}
	return pStringValue;
}

QString StringValue::getStringValue(int v) {
	bool isExit = stringValueMap.contains(v);
	if (isExit) {
		QString values = stringValueMap.value(v, "");
		return values;
	}
	return QString("");
}

StringValue::~StringValue()
{
}
