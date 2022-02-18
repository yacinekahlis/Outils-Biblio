/********************************************************************************
** Form generated from reading UI file 'SuppressionInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRESSIONINTERFACE_H
#define UI_SUPPRESSIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_SuppressionInterface
{
public:
    QPushButton *Ok;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *Identifiant;

    void setupUi(QDialog *SuppressionInterface)
    {
        if (SuppressionInterface->objectName().isEmpty())
            SuppressionInterface->setObjectName(QString::fromUtf8("SuppressionInterface"));
        SuppressionInterface->resize(729, 175);
        Ok = new QPushButton(SuppressionInterface);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setGeometry(QRect(630, 130, 80, 24));
        splitter = new QSplitter(SuppressionInterface);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(30, 60, 661, 24));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        Identifiant = new QLineEdit(splitter);
        Identifiant->setObjectName(QString::fromUtf8("Identifiant"));
        splitter->addWidget(Identifiant);

        retranslateUi(SuppressionInterface);
        QObject::connect(Ok, SIGNAL(clicked()), SuppressionInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(SuppressionInterface);
    } // setupUi

    void retranslateUi(QDialog *SuppressionInterface)
    {
        SuppressionInterface->setWindowTitle(QApplication::translate("SuppressionInterface", "SuppressionInterface", nullptr));
        Ok->setText(QApplication::translate("SuppressionInterface", "Ok", nullptr));
        label->setText(QApplication::translate("SuppressionInterface", "Identifiant de la r\303\251f\303\251rence \303\240 supprimer :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuppressionInterface: public Ui_SuppressionInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRESSIONINTERFACE_H
