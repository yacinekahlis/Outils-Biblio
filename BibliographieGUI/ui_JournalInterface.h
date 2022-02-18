/********************************************************************************
** Form generated from reading UI file 'JournalInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALINTERFACE_H
#define UI_JOURNALINTERFACE_H

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

class Ui_JournalInterface
{
public:
    QPushButton *Ok;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *Page;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *Titre;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *Nom;
    QLabel *label_6;
    QLineEdit *Auteurs;
    QLineEdit *Issn;
    QSpinBox *Volume;
    QLabel *label_3;
    QSpinBox *Annee;
    QSpinBox *Numero;

    void setupUi(QDialog *JournalInterface)
    {
        if (JournalInterface->objectName().isEmpty())
            JournalInterface->setObjectName(QString::fromUtf8("JournalInterface"));
        JournalInterface->resize(822, 429);
        Ok = new QPushButton(JournalInterface);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setGeometry(QRect(730, 390, 80, 24));
        layoutWidget = new QWidget(JournalInterface);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 60, 661, 291));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Page = new QSpinBox(layoutWidget);
        Page->setObjectName(QString::fromUtf8("Page"));
        Page->setMaximum(4000);

        gridLayout->addWidget(Page, 7, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        Titre = new QLineEdit(layoutWidget);
        Titre->setObjectName(QString::fromUtf8("Titre"));

        gridLayout->addWidget(Titre, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        Nom = new QLineEdit(layoutWidget);
        Nom->setObjectName(QString::fromUtf8("Nom"));

        gridLayout->addWidget(Nom, 2, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        Auteurs = new QLineEdit(layoutWidget);
        Auteurs->setObjectName(QString::fromUtf8("Auteurs"));

        gridLayout->addWidget(Auteurs, 0, 1, 1, 1);

        Issn = new QLineEdit(layoutWidget);
        Issn->setObjectName(QString::fromUtf8("Issn"));

        gridLayout->addWidget(Issn, 4, 1, 1, 1);

        Volume = new QSpinBox(layoutWidget);
        Volume->setObjectName(QString::fromUtf8("Volume"));
        Volume->setMaximum(4000);

        gridLayout->addWidget(Volume, 6, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        Annee = new QSpinBox(layoutWidget);
        Annee->setObjectName(QString::fromUtf8("Annee"));
        Annee->setMinimum(1);
        Annee->setMaximum(2021);

        gridLayout->addWidget(Annee, 3, 1, 1, 1);

        Numero = new QSpinBox(layoutWidget);
        Numero->setObjectName(QString::fromUtf8("Numero"));
        Numero->setMaximum(4000);

        gridLayout->addWidget(Numero, 5, 1, 1, 1);

        QWidget::setTabOrder(Auteurs, Titre);
        QWidget::setTabOrder(Titre, Nom);
        QWidget::setTabOrder(Nom, Annee);
        QWidget::setTabOrder(Annee, Issn);
        QWidget::setTabOrder(Issn, Numero);
        QWidget::setTabOrder(Numero, Volume);
        QWidget::setTabOrder(Volume, Page);
        QWidget::setTabOrder(Page, Ok);

        retranslateUi(JournalInterface);
        QObject::connect(Ok, SIGNAL(clicked()), JournalInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(JournalInterface);
    } // setupUi

    void retranslateUi(QDialog *JournalInterface)
    {
        JournalInterface->setWindowTitle(QApplication::translate("JournalInterface", "JournalInterface", nullptr));
        Ok->setText(QApplication::translate("JournalInterface", "Ok", nullptr));
        label->setText(QApplication::translate("JournalInterface", "Auteur(s) :", nullptr));
        label_2->setText(QApplication::translate("JournalInterface", "Volume :", nullptr));
        label_8->setText(QApplication::translate("JournalInterface", "Nom du Journal :", nullptr));
        label_5->setText(QApplication::translate("JournalInterface", "Ann\303\251e d'\303\251dition : ", nullptr));
        label_4->setText(QApplication::translate("JournalInterface", "Num\303\251ro : ", nullptr));
        label_7->setText(QApplication::translate("JournalInterface", "Titre :", nullptr));
        label_6->setText(QApplication::translate("JournalInterface", "ISSN :", nullptr));
        label_3->setText(QApplication::translate("JournalInterface", "Page : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JournalInterface: public Ui_JournalInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALINTERFACE_H
