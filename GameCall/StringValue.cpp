#include "StringValue.h"

StringValue* StringValue::pStringValue = nullptr;
QMap<int, QString> StringValue::stringValueMap;
StringValue::StringValue()
{
	stringValueMap.insert(1, QStringLiteral("错误"));
	stringValueMap.insert(2, QStringLiteral("打开进程令牌失败..."));
	stringValueMap.insert(3, QStringLiteral("调整令牌权限失败...")); 
	stringValueMap.insert(4, QStringLiteral("警告")); 
	stringValueMap.insert(5, QStringLiteral("警告请勿用于非法途径，本软件仅用于调试和测试。Power By 小洪 QQ:599020295。"));
	stringValueMap.insert(6, QStringLiteral("暂无（双击附加进程）"));
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
