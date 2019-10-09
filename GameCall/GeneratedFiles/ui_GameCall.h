/********************************************************************************
** Form generated from reading UI file 'GameCall.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMECALL_H
#define UI_GAMECALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameCallClass
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QPushButton *aboutBtn;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QPushButton *callBtn;
    QLabel *label_6;
    QPushButton *pidFreshBtn;
    QLabel *label_7;
    QLabel *clickTipslabel;
    QLineEdit *CKWidthEdit;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *CKHeightEdit;
    QPushButton *changeCKSizeBtn;
    QPushButton *refreshSizeButton;
    QLabel *label_10;
    QLineEdit *callAddresEdit;
    QPushButton *callSignButton;
    QTextEdit *callTextEdit;

    void setupUi(QMainWindow *GameCallClass)
    {
        if (GameCallClass->objectName().isEmpty())
            GameCallClass->setObjectName(QStringLiteral("GameCallClass"));
        GameCallClass->resize(600, 484);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        GameCallClass->setFont(font);
        centralWidget = new QWidget(GameCallClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(5, 30, 251, 411));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        aboutBtn = new QPushButton(centralWidget);
        aboutBtn->setObjectName(QStringLiteral("aboutBtn"));
        aboutBtn->setGeometry(QRect(520, 450, 75, 23));
        aboutBtn->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 10, 54, 21));
        label->setFont(font);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(300, 10, 113, 20));
        lineEdit->setFont(font);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(470, 10, 121, 20));
        lineEdit_2->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 10, 54, 21));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 180, 91, 31));
        label_3->setFont(font);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 70, 91, 23));
        pushButton_2->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 40, 71, 21));
        label_4->setFont(font);
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(330, 40, 161, 20));
        lineEdit_3->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 71, 71, 21));
        label_5->setFont(font);
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(330, 70, 161, 20));
        lineEdit_4->setFont(font);
        callBtn = new QPushButton(centralWidget);
        callBtn->setObjectName(QStringLiteral("callBtn"));
        callBtn->setGeometry(QRect(260, 450, 251, 23));
        callBtn->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 0, 61, 31));
        label_6->setFont(font);
        pidFreshBtn = new QPushButton(centralWidget);
        pidFreshBtn->setObjectName(QStringLiteral("pidFreshBtn"));
        pidFreshBtn->setGeometry(QRect(180, 0, 75, 31));
        pidFreshBtn->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 450, 91, 21));
        label_7->setFont(font);
        clickTipslabel = new QLabel(centralWidget);
        clickTipslabel->setObjectName(QStringLiteral("clickTipslabel"));
        clickTipslabel->setGeometry(QRect(100, 450, 131, 21));
        clickTipslabel->setFont(font);
        CKWidthEdit = new QLineEdit(centralWidget);
        CKWidthEdit->setObjectName(QStringLiteral("CKWidthEdit"));
        CKWidthEdit->setGeometry(QRect(290, 100, 71, 20));
        CKWidthEdit->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(260, 101, 54, 21));
        label_8->setFont(font);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(370, 101, 54, 21));
        label_9->setFont(font);
        CKHeightEdit = new QLineEdit(centralWidget);
        CKHeightEdit->setObjectName(QStringLiteral("CKHeightEdit"));
        CKHeightEdit->setGeometry(QRect(400, 100, 91, 20));
        CKHeightEdit->setFont(font);
        changeCKSizeBtn = new QPushButton(centralWidget);
        changeCKSizeBtn->setObjectName(QStringLiteral("changeCKSizeBtn"));
        changeCKSizeBtn->setGeometry(QRect(500, 100, 91, 23));
        changeCKSizeBtn->setFont(font);
        refreshSizeButton = new QPushButton(centralWidget);
        refreshSizeButton->setObjectName(QStringLiteral("refreshSizeButton"));
        refreshSizeButton->setGeometry(QRect(260, 130, 91, 23));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(260, 160, 91, 21));
        label_10->setFont(font);
        callAddresEdit = new QLineEdit(centralWidget);
        callAddresEdit->setObjectName(QStringLiteral("callAddresEdit"));
        callAddresEdit->setGeometry(QRect(360, 160, 131, 20));
        callAddresEdit->setFont(font);
        callSignButton = new QPushButton(centralWidget);
        callSignButton->setObjectName(QStringLiteral("callSignButton"));
        callSignButton->setGeometry(QRect(500, 160, 91, 23));
        callSignButton->setFont(font);
        callTextEdit = new QTextEdit(centralWidget);
        callTextEdit->setObjectName(QStringLiteral("callTextEdit"));
        callTextEdit->setGeometry(QRect(260, 210, 331, 231));
        GameCallClass->setCentralWidget(centralWidget);

        retranslateUi(GameCallClass);

        QMetaObject::connectSlotsByName(GameCallClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameCallClass)
    {
        GameCallClass->setWindowTitle(QApplication::translate("GameCallClass", "GameCall", Q_NULLPTR));
        aboutBtn->setText(QApplication::translate("GameCallClass", "\345\205\263\344\272\216", Q_NULLPTR));
        label->setText(QApplication::translate("GameCallClass", "\345\237\272\345\235\200\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("GameCallClass", "\345\201\217\347\247\273\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("GameCallClass", "\350\260\203\347\224\250\346\234\211\345\217\202\346\225\260\347\232\204Call\344\273\243\347\240\201", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("GameCallClass", "\344\277\256\346\224\271\346\210\226\350\200\205\350\216\267\345\217\226", Q_NULLPTR));
        label_4->setText(QApplication::translate("GameCallClass", "\350\246\201\344\277\256\346\224\271\347\232\204\345\200\274\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("GameCallClass", "\350\246\201\350\216\267\345\217\226\347\232\204\345\200\274\357\274\232", Q_NULLPTR));
        callBtn->setText(QApplication::translate("GameCallClass", "\350\260\203\347\224\250Call", Q_NULLPTR));
        label_6->setText(QApplication::translate("GameCallClass", "\350\277\233\347\250\213\345\220\215\345\255\227\357\274\232", Q_NULLPTR));
        pidFreshBtn->setText(QApplication::translate("GameCallClass", "\345\210\267\346\226\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("GameCallClass", "\345\275\223\345\211\215\351\200\211\344\270\255\347\250\213\345\272\217\357\274\232", Q_NULLPTR));
        clickTipslabel->setText(QApplication::translate("GameCallClass", "\346\232\202\346\227\240\357\274\210\345\217\214\345\207\273\351\231\204\345\212\240\350\277\233\347\250\213\357\274\211", Q_NULLPTR));
        label_8->setText(QApplication::translate("GameCallClass", "\345\256\275\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("GameCallClass", "\351\253\230\357\274\232", Q_NULLPTR));
        changeCKSizeBtn->setText(QApplication::translate("GameCallClass", "\344\277\256\346\224\271\347\252\227\345\217\243\345\244\247\345\260\217", Q_NULLPTR));
        refreshSizeButton->setText(QApplication::translate("GameCallClass", "\346\201\242\345\244\215\347\252\227\345\217\243\345\244\247\345\260\217", Q_NULLPTR));
        label_10->setText(QApplication::translate("GameCallClass", "\350\260\203\347\224\250\346\227\240\345\217\202\346\225\260\347\232\204Call\344\273\243\347\240\201", Q_NULLPTR));
        callAddresEdit->setPlaceholderText(QApplication::translate("GameCallClass", "\350\257\267\350\276\223\345\205\245Call\345\234\260\345\235\200", Q_NULLPTR));
        callSignButton->setText(QApplication::translate("GameCallClass", "\350\260\203\347\224\250Call", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameCallClass: public Ui_GameCallClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMECALL_H
