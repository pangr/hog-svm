/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *yes;
    QPushButton *cancel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *truesampath;
    QLineEdit *falsesampath;
    QToolButton *falsetb;
    QToolButton *truetb;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *winwidth;
    QLineEdit *blockwidth;
    QLineEdit *blocksw;
    QLineEdit *bin;
    QLineEdit *winheight;
    QLineEdit *blockheight;
    QLineEdit *blocksh;
    QLineEdit *cellheight;
    QLineEdit *cellwidth;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(538, 297);
        QFont font;
        font.setFamily(QStringLiteral("SimSun-ExtB"));
        Dialog->setFont(font);
        yes = new QPushButton(Dialog);
        yes->setObjectName(QStringLiteral("yes"));
        yes->setGeometry(QRect(330, 250, 75, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("SimSun-ExtB"));
        font1.setPointSize(10);
        yes->setFont(font1);
        cancel = new QPushButton(Dialog);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(430, 250, 75, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(10);
        cancel->setFont(font2);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 170, 71, 20));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 200, 71, 20));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 20, 61, 20));
        truesampath = new QLineEdit(Dialog);
        truesampath->setObjectName(QStringLiteral("truesampath"));
        truesampath->setGeometry(QRect(130, 170, 281, 20));
        falsesampath = new QLineEdit(Dialog);
        falsesampath->setObjectName(QStringLiteral("falsesampath"));
        falsesampath->setGeometry(QRect(130, 200, 281, 20));
        falsetb = new QToolButton(Dialog);
        falsetb->setObjectName(QStringLiteral("falsetb"));
        falsetb->setGeometry(QRect(420, 200, 37, 21));
        truetb = new QToolButton(Dialog);
        truetb->setObjectName(QStringLiteral("truetb"));
        truetb->setGeometry(QRect(420, 170, 37, 21));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 22, 54, 20));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(123, 50, 61, 20));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(123, 80, 61, 21));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 110, 54, 21));
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 140, 41, 21));
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(200, 20, 16, 21));
        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(200, 50, 16, 21));
        label_11 = new QLabel(Dialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(200, 80, 16, 21));
        label_12 = new QLabel(Dialog);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(200, 110, 16, 21));
        label_13 = new QLabel(Dialog);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(270, 20, 16, 21));
        label_14 = new QLabel(Dialog);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(270, 50, 16, 21));
        label_15 = new QLabel(Dialog);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(270, 80, 16, 21));
        label_16 = new QLabel(Dialog);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(270, 110, 16, 21));
        winwidth = new QLineEdit(Dialog);
        winwidth->setObjectName(QStringLiteral("winwidth"));
        winwidth->setGeometry(QRect(220, 20, 31, 20));
        blockwidth = new QLineEdit(Dialog);
        blockwidth->setObjectName(QStringLiteral("blockwidth"));
        blockwidth->setGeometry(QRect(220, 50, 31, 20));
        blocksw = new QLineEdit(Dialog);
        blocksw->setObjectName(QStringLiteral("blocksw"));
        blocksw->setGeometry(QRect(220, 80, 31, 20));
        bin = new QLineEdit(Dialog);
        bin->setObjectName(QStringLiteral("bin"));
        bin->setGeometry(QRect(200, 140, 31, 20));
        winheight = new QLineEdit(Dialog);
        winheight->setObjectName(QStringLiteral("winheight"));
        winheight->setGeometry(QRect(290, 20, 31, 20));
        blockheight = new QLineEdit(Dialog);
        blockheight->setObjectName(QStringLiteral("blockheight"));
        blockheight->setGeometry(QRect(290, 50, 31, 20));
        blocksh = new QLineEdit(Dialog);
        blocksh->setObjectName(QStringLiteral("blocksh"));
        blocksh->setGeometry(QRect(290, 80, 31, 20));
        cellheight = new QLineEdit(Dialog);
        cellheight->setObjectName(QStringLiteral("cellheight"));
        cellheight->setGeometry(QRect(290, 110, 31, 20));
        cellwidth = new QLineEdit(Dialog);
        cellwidth->setObjectName(QStringLiteral("cellwidth"));
        cellwidth->setGeometry(QRect(220, 110, 31, 20));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        yes->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", 0));
        cancel->setText(QApplication::translate("Dialog", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("Dialog", "\346\255\243\346\240\267\346\234\254\350\267\257\345\276\204\357\274\232", 0));
        label_2->setText(QApplication::translate("Dialog", "\350\264\237\346\240\267\346\234\254\350\267\257\345\276\204\357\274\232", 0));
        label_3->setText(QApplication::translate("Dialog", "\350\256\255\347\273\203\345\217\202\346\225\260\357\274\232", 0));
        truesampath->setText(QApplication::translate("Dialog", "F:/96x104/true", 0));
        falsesampath->setText(QApplication::translate("Dialog", "F:/96x104/false", 0));
        falsetb->setText(QApplication::translate("Dialog", "...", 0));
        truetb->setText(QApplication::translate("Dialog", "...", 0));
        label_4->setText(QApplication::translate("Dialog", " win\345\244\247\345\260\217\357\274\232 ", 0));
        label_5->setText(QApplication::translate("Dialog", "block\345\244\247\345\260\217\357\274\232", 0));
        label_6->setText(QApplication::translate("Dialog", "block\346\255\245\351\225\277\357\274\232", 0));
        label_7->setText(QApplication::translate("Dialog", "cell\345\244\247\345\260\217\357\274\232", 0));
        label_8->setText(QApplication::translate("Dialog", " bin\346\225\260\357\274\232", 0));
        label_9->setText(QApplication::translate("Dialog", "\345\256\275", 0));
        label_10->setText(QApplication::translate("Dialog", "\345\256\275", 0));
        label_11->setText(QApplication::translate("Dialog", "\345\256\275", 0));
        label_12->setText(QApplication::translate("Dialog", "\345\256\275", 0));
        label_13->setText(QApplication::translate("Dialog", "\351\253\230", 0));
        label_14->setText(QApplication::translate("Dialog", "\351\253\230", 0));
        label_15->setText(QApplication::translate("Dialog", "\351\253\230", 0));
        label_16->setText(QApplication::translate("Dialog", "\351\253\230", 0));
        winwidth->setText(QApplication::translate("Dialog", "96", 0));
        blockwidth->setText(QApplication::translate("Dialog", "16", 0));
        blocksw->setText(QApplication::translate("Dialog", "8", 0));
        bin->setText(QApplication::translate("Dialog", "18", 0));
        winheight->setText(QApplication::translate("Dialog", "104", 0));
        blockheight->setText(QApplication::translate("Dialog", "16", 0));
        blocksh->setText(QApplication::translate("Dialog", "8", 0));
        cellheight->setText(QApplication::translate("Dialog", "8", 0));
        cellwidth->setText(QApplication::translate("Dialog", "8", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
