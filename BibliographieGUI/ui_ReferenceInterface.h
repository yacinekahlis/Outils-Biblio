/********************************************************************************
** Form generated from reading UI file 'ReferenceInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFERENCEINTERFACE_H
#define UI_REFERENCEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReferenceInterface
{
public:
    QAction *actionSupprimer_une_r_f_rence;
    QAction *actionQuitter;
    QAction *actionOuvrage;
    QAction *actionJournal;
    QWidget *centralwidget;
    QTextEdit *Affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_une_r_f_rence;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ReferenceInterface)
    {
        if (ReferenceInterface->objectName().isEmpty())
            ReferenceInterface->setObjectName(QString::fromUtf8("ReferenceInterface"));
        ReferenceInterface->resize(826, 692);
        actionSupprimer_une_r_f_rence = new QAction(ReferenceInterface);
        actionSupprimer_une_r_f_rence->setObjectName(QString::fromUtf8("actionSupprimer_une_r_f_rence"));
        actionQuitter = new QAction(ReferenceInterface);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionOuvrage = new QAction(ReferenceInterface);
        actionOuvrage->setObjectName(QString::fromUtf8("actionOuvrage"));
        actionJournal = new QAction(ReferenceInterface);
        actionJournal->setObjectName(QString::fromUtf8("actionJournal"));
        centralwidget = new QWidget(ReferenceInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Affichage = new QTextEdit(centralwidget);
        Affichage->setObjectName(QString::fromUtf8("Affichage"));
        Affichage->setGeometry(QRect(10, 10, 801, 631));
        ReferenceInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ReferenceInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 826, 21));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_une_r_f_rence = new QMenu(menuMenu);
        menuAjouter_une_r_f_rence->setObjectName(QString::fromUtf8("menuAjouter_une_r_f_rence"));
        ReferenceInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(ReferenceInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ReferenceInterface->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(menuAjouter_une_r_f_rence->menuAction());
        menuMenu->addAction(actionSupprimer_une_r_f_rence);
        menuMenu->addAction(actionQuitter);
        menuAjouter_une_r_f_rence->addAction(actionOuvrage);
        menuAjouter_une_r_f_rence->addAction(actionJournal);

        retranslateUi(ReferenceInterface);
        QObject::connect(actionQuitter, SIGNAL(triggered()), ReferenceInterface, SLOT(close()));
        QObject::connect(actionOuvrage, SIGNAL(triggered()), ReferenceInterface, SLOT(dialogOuvrage()));
        QObject::connect(actionJournal, SIGNAL(triggered()), ReferenceInterface, SLOT(dialogJournal()));
        QObject::connect(actionSupprimer_une_r_f_rence, SIGNAL(triggered()), ReferenceInterface, SLOT(dialogSuppression()));

        QMetaObject::connectSlotsByName(ReferenceInterface);
    } // setupUi

    void retranslateUi(QMainWindow *ReferenceInterface)
    {
        ReferenceInterface->setWindowTitle(QApplication::translate("ReferenceInterface", "ReferenceInterface", nullptr));
        actionSupprimer_une_r_f_rence->setText(QApplication::translate("ReferenceInterface", "Supprimer une r\303\251f\303\251rence", nullptr));
        actionQuitter->setText(QApplication::translate("ReferenceInterface", "Quitter", nullptr));
        actionOuvrage->setText(QApplication::translate("ReferenceInterface", "Ouvrage", nullptr));
        actionJournal->setText(QApplication::translate("ReferenceInterface", "Journal", nullptr));
        menuMenu->setTitle(QApplication::translate("ReferenceInterface", "Menu", nullptr));
        menuAjouter_une_r_f_rence->setTitle(QApplication::translate("ReferenceInterface", "Ajouter une r\303\251f\303\251rence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReferenceInterface: public Ui_ReferenceInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFERENCEINTERFACE_H
