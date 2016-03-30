/********************************************************************************
** Form generated from reading UI file 'picSelect.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICSELECT_H
#define UI_PICSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *next;
    QPushButton *delete_2;
    QPushButton *prior;
    QLabel *imagelabel;
    QLabel *name;
    QLabel *imagelabel_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(360, 233);
        next = new QPushButton(Dialog);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(250, 140, 75, 23));
        delete_2 = new QPushButton(Dialog);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        delete_2->setGeometry(QRect(250, 90, 75, 23));
        prior = new QPushButton(Dialog);
        prior->setObjectName(QStringLiteral("prior"));
        prior->setGeometry(QRect(250, 40, 75, 23));
        imagelabel = new QLabel(Dialog);
        imagelabel->setObjectName(QStringLiteral("imagelabel"));
        imagelabel->setGeometry(QRect(140, 40, 71, 101));
        name = new QLabel(Dialog);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(70, 160, 101, 20));
        imagelabel_2 = new QLabel(Dialog);
        imagelabel_2->setObjectName(QStringLiteral("imagelabel_2"));
        imagelabel_2->setGeometry(QRect(20, 40, 71, 101));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        next->setText(QApplication::translate("Dialog", "\344\270\213\344\270\200\344\270\252", 0));
        delete_2->setText(QApplication::translate("Dialog", "\345\210\240\351\231\244", 0));
        prior->setText(QApplication::translate("Dialog", "\344\270\212\344\270\200\344\270\252", 0));
        imagelabel->setText(QApplication::translate("Dialog", "TextLabel", 0));
        name->setText(QApplication::translate("Dialog", "TextLabel", 0));
        imagelabel_2->setText(QApplication::translate("Dialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICSELECT_H
