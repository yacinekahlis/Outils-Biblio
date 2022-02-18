/********************************************************************************
** Form generated from reading UI file 'OuvrageInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUVRAGEINTERFACE_H
#define UI_OUVRAGEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OuvrageInterface
{
public:
    QPushButton *Ok;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *Auteurs;
    QLabel *label_2;
    QLineEdit *Titre;
    QLabel *label_5;
    QSpinBox *Annee;
    QLabel *label_3;
    QLineEdit *Ville;
    QLabel *label_4;
    QLineEdit *Editeur;
    QLabel *label_6;
    QLineEdit *Isbn;

    void setupUi(QDialog *OuvrageInterface)
    {
        if (OuvrageInterface->objectName().isEmpty())
            OuvrageInterface->setObjectName(QString::fromUtf8("OuvrageInterface"));
        OuvrageInterface->resize(800, 364);
        Ok = new QPushButton(OuvrageInterface);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setGeometry(QRect(700, 330, 80, 24));
        layoutWidget = new QWidget(OuvrageInterface);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 661, 271));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Auteurs = new QLineEdit(layoutWidget);
        Auteurs->setObjectName(QString::fromUtf8("Auteurs"));

        gridLayout->addWidget(Auteurs, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        Titre = new QLineEdit(layoutWidget);
        Titre->setObjectName(QString::fromUtf8("Titre"));

        gridLayout->addWidget(Titre, 1, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        Annee = new QSpinBox(layoutWidget);
        Annee->setObjectName(QString::fromUtf8("Annee"));
        Annee->setMinimum(1);
        Annee->setMaximum(2021);

        gridLayout->addWidget(Annee, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        Ville = new QLineEdit(layoutWidget);
        Ville->setObjectName(QString::fromUtf8("Ville"));

        gridLayout->addWidget(Ville, 3, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        Editeur = new QLineEdit(layoutWidget);
        Editeur->setObjectName(QString::fromUtf8("Editeur"));

        gridLayout->addWidget(Editeur, 4, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        Isbn = new QLineEdit(layoutWidget);
        Isbn->setObjectName(QString::fromUtf8("Isbn"));
        Isbn->setInputMask(QString::fromUtf8(""));
        Isbn->setMaxLength(40);
        Isbn->setClearButtonEnabled(false);

        gridLayout->addWidget(Isbn, 5, 1, 1, 1);


        retranslateUi(OuvrageInterface);
        QObject::connect(Ok, SIGNAL(clicked()), OuvrageInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(OuvrageInterface);
    } // setupUi

    void retranslateUi(QDialog *OuvrageInterface)
    {
        OuvrageInterface->setWindowTitle(QApplication::translate("OuvrageInterface", "OuvrageInterface", nullptr));
        Ok->setText(QApplication::translate("OuvrageInterface", "Ok", nullptr));
        label->setText(QApplication::translate("OuvrageInterface", "Auteur(s) :", nullptr));
        label_2->setText(QApplication::translate("OuvrageInterface", "Titre :", nullptr));
        label_5->setText(QApplication::translate("OuvrageInterface", "Ann\303\251e d'\303\251dition :", nullptr));
        Annee->setPrefix(QString());
        label_3->setText(QApplication::translate("OuvrageInterface", "Ville d'\303\251dition :", nullptr));
        label_4->setText(QApplication::translate("OuvrageInterface", "\303\211diteur :", nullptr));
        label_6->setText(QApplication::translate("OuvrageInterface", "ISBN :", nullptr));
        Isbn->setText(QString());
        Isbn->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class OuvrageInterface: public Ui_OuvrageInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUVRAGEINTERFACE_H
