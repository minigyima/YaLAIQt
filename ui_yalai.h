/********************************************************************************
** Form generated from reading UI file 'yalai.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YALAI_H
#define UI_YALAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yalai
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QStackedWidget *PhaseWidget;
    QWidget *welcome;
    QTextBrowser *textBrowser_welcome;
    QCheckBox *checkBox_preseed;
    QWidget *partition;
    QPushButton *pushButton;
    QTextBrowser *textBrowser_partsel;
    QLabel *label_swap;
    QLabel *label_efi;
    QLabel *label_root;
    QLabel *label_block;
    QComboBox *dropdown_block;
    QComboBox *dropdown_root;
    QComboBox *dropdown_swap;
    QComboBox *dropdown_efi;
    QLabel *label_required;
    QWidget *locale;
    QTextBrowser *textBrowser_locale;
    QComboBox *dropdown_keylayout;
    QLabel *lebel_keylayout;
    QLabel *label_lang;
    QLabel *label_timezone;
    QComboBox *dropdown_language;
    QLabel *label_subzone;
    QComboBox *dropdown_timezone;
    QComboBox *dropdown_subzone;
    QLabel *label_required_2;
    QWidget *user_details;
    QTextBrowser *textBrowser_user_details;
    QLabel *label_username;
    QLabel *label_password;
    QLineEdit *password_LineED_1;
    QLineEdit *username_LineED;
    QLineEdit *password_LineED_2;
    QLabel *label_hostname;
    QLineEdit *hostname_LineED;
    QLineEdit *rootpasswd_LineED_1;
    QLineEdit *rootpasswd_LineED_2;
    QLabel *label_rootpasswd;
    QLabel *label_required_3;
    QLabel *label_rtpasswd_nomatch;
    QLabel *label_passwd_nomatch;
    QWidget *personalization;
    QTextBrowser *textBrowser_personalization;
    QLabel *label_de;
    QLabel *label_shell;
    QComboBox *dropdown_dm;
    QLabel *label_required_4;
    QComboBox *dropdown_de;
    QLabel *lebel_dm;
    QComboBox *dropdown_shell;
    QLabel *label_appPreseed;
    QLineEdit *appPreseed_LineED;
    QPushButton *btn_open_ap;
    QCheckBox *checkBox_aursupport;
    QWidget *summary;
    QTextBrowser *textBrowser_summary;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_part;
    QLabel *label_sum_part;
    QLabel *label_sum_part_root;
    QLabel *label_sum_part_swap;
    QLabel *label_sum_part_efi;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_locale;
    QLabel *label_sum_locale;
    QLabel *label_sum_language;
    QLabel *label_sum_keylayout;
    QLabel *label_sum_timezone;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_userdet;
    QLabel *label_sum_userdet;
    QLabel *label_sum_username;
    QLabel *label_sum_hostname;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_pers;
    QLabel *label_sum_pers;
    QLabel *label_sum_desktop;
    QLabel *label_sum_dm;
    QLabel *label_sum_shell;
    QLabel *label_sum_aurSupport;
    QPushButton *savePreseed_btn;
    QWidget *install;
    QTextBrowser *textBrowser_install;
    QLabel *install_indicator_ph;
    QWidget *PreseedPage;
    QTextBrowser *textBrowser_preseed;
    QLineEdit *appPreseed_LineED_2;
    QLabel *label_appPreseed_pr;
    QPushButton *btn_open_ap_pr;
    QLabel *label_required_5;
    QPushButton *btn_open_pr;
    QLabel *label_preseed;
    QLineEdit *preseed_LineED;
    QLabel *label_rtpasswd_nomatch_pr;
    QLineEdit *password_LineED_pr_2;
    QLabel *label_rootpasswd_2;
    QLineEdit *rootpasswd_LineED_pr2;
    QLabel *label_passwd_nomatch_pr;
    QLineEdit *password_LineED_pr;
    QLabel *label_password_2;
    QLineEdit *rootpasswd_LineED_pr;
    QCheckBox *checkBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *indicator_intro;
    QPushButton *indicator_preseed;
    QPushButton *indicator_part;
    QPushButton *indicator_locale;
    QPushButton *indicator_user;
    QPushButton *indicator_personalization;
    QPushButton *indicator_summary;
    QPushButton *indicator_install;
    QPushButton *Next_btn;
    QPushButton *Back_btn;
    QPlainTextEdit *TextOut;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *yalai)
    {
        if (yalai->objectName().isEmpty())
            yalai->setObjectName(QString::fromUtf8("yalai"));
        yalai->resize(674, 689);
        yalai->setMinimumSize(QSize(674, 458));
        centralwidget = new QWidget(yalai);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(149, 9, 511, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        PhaseWidget = new QStackedWidget(gridLayoutWidget);
        PhaseWidget->setObjectName(QString::fromUtf8("PhaseWidget"));
        welcome = new QWidget();
        welcome->setObjectName(QString::fromUtf8("welcome"));
        textBrowser_welcome = new QTextBrowser(welcome);
        textBrowser_welcome->setObjectName(QString::fromUtf8("textBrowser_welcome"));
        textBrowser_welcome->setGeometry(QRect(0, 0, 511, 371));
        checkBox_preseed = new QCheckBox(welcome);
        checkBox_preseed->setObjectName(QString::fromUtf8("checkBox_preseed"));
        checkBox_preseed->setGeometry(QRect(380, 340, 121, 24));
        PhaseWidget->addWidget(welcome);
        partition = new QWidget();
        partition->setObjectName(QString::fromUtf8("partition"));
        pushButton = new QPushButton(partition);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 330, 101, 31));
        textBrowser_partsel = new QTextBrowser(partition);
        textBrowser_partsel->setObjectName(QString::fromUtf8("textBrowser_partsel"));
        textBrowser_partsel->setGeometry(QRect(0, 0, 511, 371));
        label_swap = new QLabel(partition);
        label_swap->setObjectName(QString::fromUtf8("label_swap"));
        label_swap->setGeometry(QRect(30, 210, 101, 21));
        label_efi = new QLabel(partition);
        label_efi->setObjectName(QString::fromUtf8("label_efi"));
        label_efi->setGeometry(QRect(30, 260, 141, 21));
        label_root = new QLabel(partition);
        label_root->setObjectName(QString::fromUtf8("label_root"));
        label_root->setGeometry(QRect(30, 160, 101, 21));
        label_block = new QLabel(partition);
        label_block->setObjectName(QString::fromUtf8("label_block"));
        label_block->setGeometry(QRect(30, 110, 81, 20));
        dropdown_block = new QComboBox(partition);
        dropdown_block->addItem(QString());
        dropdown_block->setObjectName(QString::fromUtf8("dropdown_block"));
        dropdown_block->setGeometry(QRect(180, 110, 291, 26));
        dropdown_root = new QComboBox(partition);
        dropdown_root->addItem(QString());
        dropdown_root->setObjectName(QString::fromUtf8("dropdown_root"));
        dropdown_root->setGeometry(QRect(180, 160, 291, 26));
        dropdown_swap = new QComboBox(partition);
        dropdown_swap->addItem(QString());
        dropdown_swap->setObjectName(QString::fromUtf8("dropdown_swap"));
        dropdown_swap->setGeometry(QRect(180, 210, 291, 26));
        dropdown_efi = new QComboBox(partition);
        dropdown_efi->addItem(QString());
        dropdown_efi->setObjectName(QString::fromUtf8("dropdown_efi"));
        dropdown_efi->setGeometry(QRect(180, 260, 291, 26));
        label_required = new QLabel(partition);
        label_required->setObjectName(QString::fromUtf8("label_required"));
        label_required->setGeometry(QRect(30, 330, 71, 31));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 127));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_required->setPalette(palette);
        PhaseWidget->addWidget(partition);
        textBrowser_partsel->raise();
        pushButton->raise();
        label_swap->raise();
        label_efi->raise();
        label_root->raise();
        label_block->raise();
        dropdown_block->raise();
        dropdown_root->raise();
        dropdown_swap->raise();
        dropdown_efi->raise();
        label_required->raise();
        locale = new QWidget();
        locale->setObjectName(QString::fromUtf8("locale"));
        textBrowser_locale = new QTextBrowser(locale);
        textBrowser_locale->setObjectName(QString::fromUtf8("textBrowser_locale"));
        textBrowser_locale->setGeometry(QRect(0, 0, 511, 371));
        dropdown_keylayout = new QComboBox(locale);
        dropdown_keylayout->setObjectName(QString::fromUtf8("dropdown_keylayout"));
        dropdown_keylayout->setGeometry(QRect(180, 160, 291, 26));
        lebel_keylayout = new QLabel(locale);
        lebel_keylayout->setObjectName(QString::fromUtf8("lebel_keylayout"));
        lebel_keylayout->setGeometry(QRect(30, 160, 101, 21));
        label_lang = new QLabel(locale);
        label_lang->setObjectName(QString::fromUtf8("label_lang"));
        label_lang->setGeometry(QRect(30, 110, 81, 20));
        label_timezone = new QLabel(locale);
        label_timezone->setObjectName(QString::fromUtf8("label_timezone"));
        label_timezone->setGeometry(QRect(30, 210, 71, 21));
        dropdown_language = new QComboBox(locale);
        dropdown_language->setObjectName(QString::fromUtf8("dropdown_language"));
        dropdown_language->setGeometry(QRect(180, 110, 291, 26));
        label_subzone = new QLabel(locale);
        label_subzone->setObjectName(QString::fromUtf8("label_subzone"));
        label_subzone->setGeometry(QRect(30, 260, 61, 21));
        dropdown_timezone = new QComboBox(locale);
        dropdown_timezone->setObjectName(QString::fromUtf8("dropdown_timezone"));
        dropdown_timezone->setGeometry(QRect(180, 210, 291, 26));
        dropdown_subzone = new QComboBox(locale);
        dropdown_subzone->setObjectName(QString::fromUtf8("dropdown_subzone"));
        dropdown_subzone->setGeometry(QRect(180, 260, 291, 26));
        label_required_2 = new QLabel(locale);
        label_required_2->setObjectName(QString::fromUtf8("label_required_2"));
        label_required_2->setGeometry(QRect(30, 330, 71, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_required_2->setPalette(palette1);
        PhaseWidget->addWidget(locale);
        user_details = new QWidget();
        user_details->setObjectName(QString::fromUtf8("user_details"));
        textBrowser_user_details = new QTextBrowser(user_details);
        textBrowser_user_details->setObjectName(QString::fromUtf8("textBrowser_user_details"));
        textBrowser_user_details->setGeometry(QRect(0, 0, 511, 371));
        label_username = new QLabel(user_details);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(30, 110, 81, 18));
        label_password = new QLabel(user_details);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(30, 160, 81, 18));
        password_LineED_1 = new QLineEdit(user_details);
        password_LineED_1->setObjectName(QString::fromUtf8("password_LineED_1"));
        password_LineED_1->setGeometry(QRect(180, 160, 135, 26));
        password_LineED_1->setEchoMode(QLineEdit::Password);
        username_LineED = new QLineEdit(user_details);
        username_LineED->setObjectName(QString::fromUtf8("username_LineED"));
        username_LineED->setGeometry(QRect(180, 110, 291, 26));
        username_LineED->setAutoFillBackground(false);
        username_LineED->setFrame(true);
        password_LineED_2 = new QLineEdit(user_details);
        password_LineED_2->setObjectName(QString::fromUtf8("password_LineED_2"));
        password_LineED_2->setGeometry(QRect(330, 160, 141, 26));
        password_LineED_2->setEchoMode(QLineEdit::Password);
        label_hostname = new QLabel(user_details);
        label_hostname->setObjectName(QString::fromUtf8("label_hostname"));
        label_hostname->setGeometry(QRect(30, 260, 81, 18));
        hostname_LineED = new QLineEdit(user_details);
        hostname_LineED->setObjectName(QString::fromUtf8("hostname_LineED"));
        hostname_LineED->setGeometry(QRect(180, 260, 291, 26));
        hostname_LineED->setAutoFillBackground(false);
        hostname_LineED->setFrame(true);
        rootpasswd_LineED_1 = new QLineEdit(user_details);
        rootpasswd_LineED_1->setObjectName(QString::fromUtf8("rootpasswd_LineED_1"));
        rootpasswd_LineED_1->setGeometry(QRect(180, 210, 135, 26));
        rootpasswd_LineED_1->setEchoMode(QLineEdit::Password);
        rootpasswd_LineED_2 = new QLineEdit(user_details);
        rootpasswd_LineED_2->setObjectName(QString::fromUtf8("rootpasswd_LineED_2"));
        rootpasswd_LineED_2->setGeometry(QRect(330, 210, 141, 26));
        rootpasswd_LineED_2->setEchoMode(QLineEdit::Password);
        label_rootpasswd = new QLabel(user_details);
        label_rootpasswd->setObjectName(QString::fromUtf8("label_rootpasswd"));
        label_rootpasswd->setGeometry(QRect(30, 210, 101, 18));
        label_required_3 = new QLabel(user_details);
        label_required_3->setObjectName(QString::fromUtf8("label_required_3"));
        label_required_3->setGeometry(QRect(30, 330, 71, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_required_3->setPalette(palette2);
        label_rtpasswd_nomatch = new QLabel(user_details);
        label_rtpasswd_nomatch->setObjectName(QString::fromUtf8("label_rtpasswd_nomatch"));
        label_rtpasswd_nomatch->setGeometry(QRect(180, 230, 191, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_rtpasswd_nomatch->setPalette(palette3);
        label_passwd_nomatch = new QLabel(user_details);
        label_passwd_nomatch->setObjectName(QString::fromUtf8("label_passwd_nomatch"));
        label_passwd_nomatch->setGeometry(QRect(180, 180, 191, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_passwd_nomatch->setPalette(palette4);
        PhaseWidget->addWidget(user_details);
        personalization = new QWidget();
        personalization->setObjectName(QString::fromUtf8("personalization"));
        textBrowser_personalization = new QTextBrowser(personalization);
        textBrowser_personalization->setObjectName(QString::fromUtf8("textBrowser_personalization"));
        textBrowser_personalization->setGeometry(QRect(0, 0, 511, 371));
        label_de = new QLabel(personalization);
        label_de->setObjectName(QString::fromUtf8("label_de"));
        label_de->setGeometry(QRect(30, 110, 141, 20));
        label_shell = new QLabel(personalization);
        label_shell->setObjectName(QString::fromUtf8("label_shell"));
        label_shell->setGeometry(QRect(30, 210, 61, 21));
        dropdown_dm = new QComboBox(personalization);
        dropdown_dm->addItem(QString());
        dropdown_dm->addItem(QString());
        dropdown_dm->addItem(QString());
        dropdown_dm->addItem(QString());
        dropdown_dm->addItem(QString());
        dropdown_dm->setObjectName(QString::fromUtf8("dropdown_dm"));
        dropdown_dm->setGeometry(QRect(180, 160, 291, 26));
        label_required_4 = new QLabel(personalization);
        label_required_4->setObjectName(QString::fromUtf8("label_required_4"));
        label_required_4->setGeometry(QRect(30, 330, 71, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_required_4->setPalette(palette5);
        dropdown_de = new QComboBox(personalization);
        dropdown_de->addItem(QString());
        dropdown_de->addItem(QString());
        dropdown_de->addItem(QString());
        dropdown_de->addItem(QString());
        dropdown_de->addItem(QString());
        dropdown_de->addItem(QString());
        dropdown_de->addItem(QString());
        dropdown_de->addItem(QString());
        dropdown_de->setObjectName(QString::fromUtf8("dropdown_de"));
        dropdown_de->setGeometry(QRect(180, 110, 291, 26));
        lebel_dm = new QLabel(personalization);
        lebel_dm->setObjectName(QString::fromUtf8("lebel_dm"));
        lebel_dm->setGeometry(QRect(30, 160, 131, 21));
        dropdown_shell = new QComboBox(personalization);
        dropdown_shell->addItem(QString());
        dropdown_shell->addItem(QString());
        dropdown_shell->addItem(QString());
        dropdown_shell->addItem(QString());
        dropdown_shell->setObjectName(QString::fromUtf8("dropdown_shell"));
        dropdown_shell->setGeometry(QRect(180, 210, 291, 26));
        label_appPreseed = new QLabel(personalization);
        label_appPreseed->setObjectName(QString::fromUtf8("label_appPreseed"));
        label_appPreseed->setGeometry(QRect(30, 260, 101, 21));
        appPreseed_LineED = new QLineEdit(personalization);
        appPreseed_LineED->setObjectName(QString::fromUtf8("appPreseed_LineED"));
        appPreseed_LineED->setGeometry(QRect(180, 300, 291, 26));
        appPreseed_LineED->setAutoFillBackground(false);
        appPreseed_LineED->setFrame(true);
        appPreseed_LineED->setAlignment(Qt::AlignCenter);
        appPreseed_LineED->setReadOnly(true);
        btn_open_ap = new QPushButton(personalization);
        btn_open_ap->setObjectName(QString::fromUtf8("btn_open_ap"));
        btn_open_ap->setGeometry(QRect(180, 260, 291, 26));
        checkBox_aursupport = new QCheckBox(personalization);
        checkBox_aursupport->setObjectName(QString::fromUtf8("checkBox_aursupport"));
        checkBox_aursupport->setGeometry(QRect(180, 330, 141, 24));
        PhaseWidget->addWidget(personalization);
        summary = new QWidget();
        summary->setObjectName(QString::fromUtf8("summary"));
        textBrowser_summary = new QTextBrowser(summary);
        textBrowser_summary->setObjectName(QString::fromUtf8("textBrowser_summary"));
        textBrowser_summary->setGeometry(QRect(0, 0, 511, 371));
        verticalLayoutWidget_2 = new QWidget(summary);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 80, 271, 111));
        verticalLayout_part = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_part->setObjectName(QString::fromUtf8("verticalLayout_part"));
        verticalLayout_part->setContentsMargins(0, 0, 0, 0);
        label_sum_part = new QLabel(verticalLayoutWidget_2);
        label_sum_part->setObjectName(QString::fromUtf8("label_sum_part"));
        label_sum_part->setAlignment(Qt::AlignCenter);

        verticalLayout_part->addWidget(label_sum_part);

        label_sum_part_root = new QLabel(verticalLayoutWidget_2);
        label_sum_part_root->setObjectName(QString::fromUtf8("label_sum_part_root"));
        label_sum_part_root->setAlignment(Qt::AlignCenter);

        verticalLayout_part->addWidget(label_sum_part_root);

        label_sum_part_swap = new QLabel(verticalLayoutWidget_2);
        label_sum_part_swap->setObjectName(QString::fromUtf8("label_sum_part_swap"));
        label_sum_part_swap->setAlignment(Qt::AlignCenter);

        verticalLayout_part->addWidget(label_sum_part_swap);

        label_sum_part_efi = new QLabel(verticalLayoutWidget_2);
        label_sum_part_efi->setObjectName(QString::fromUtf8("label_sum_part_efi"));
        label_sum_part_efi->setAlignment(Qt::AlignCenter);

        verticalLayout_part->addWidget(label_sum_part_efi);

        verticalLayoutWidget_3 = new QWidget(summary);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 200, 271, 121));
        verticalLayout_locale = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_locale->setObjectName(QString::fromUtf8("verticalLayout_locale"));
        verticalLayout_locale->setContentsMargins(0, 0, 0, 0);
        label_sum_locale = new QLabel(verticalLayoutWidget_3);
        label_sum_locale->setObjectName(QString::fromUtf8("label_sum_locale"));
        label_sum_locale->setAlignment(Qt::AlignCenter);

        verticalLayout_locale->addWidget(label_sum_locale);

        label_sum_language = new QLabel(verticalLayoutWidget_3);
        label_sum_language->setObjectName(QString::fromUtf8("label_sum_language"));
        label_sum_language->setAlignment(Qt::AlignCenter);

        verticalLayout_locale->addWidget(label_sum_language);

        label_sum_keylayout = new QLabel(verticalLayoutWidget_3);
        label_sum_keylayout->setObjectName(QString::fromUtf8("label_sum_keylayout"));
        label_sum_keylayout->setAlignment(Qt::AlignCenter);

        verticalLayout_locale->addWidget(label_sum_keylayout);

        label_sum_timezone = new QLabel(verticalLayoutWidget_3);
        label_sum_timezone->setObjectName(QString::fromUtf8("label_sum_timezone"));
        label_sum_timezone->setAlignment(Qt::AlignCenter);

        verticalLayout_locale->addWidget(label_sum_timezone);

        verticalLayoutWidget_4 = new QWidget(summary);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(310, 100, 191, 91));
        verticalLayout_userdet = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_userdet->setObjectName(QString::fromUtf8("verticalLayout_userdet"));
        verticalLayout_userdet->setContentsMargins(0, 0, 0, 0);
        label_sum_userdet = new QLabel(verticalLayoutWidget_4);
        label_sum_userdet->setObjectName(QString::fromUtf8("label_sum_userdet"));
        label_sum_userdet->setAlignment(Qt::AlignCenter);

        verticalLayout_userdet->addWidget(label_sum_userdet);

        label_sum_username = new QLabel(verticalLayoutWidget_4);
        label_sum_username->setObjectName(QString::fromUtf8("label_sum_username"));
        label_sum_username->setAlignment(Qt::AlignCenter);

        verticalLayout_userdet->addWidget(label_sum_username);

        label_sum_hostname = new QLabel(verticalLayoutWidget_4);
        label_sum_hostname->setObjectName(QString::fromUtf8("label_sum_hostname"));
        label_sum_hostname->setAlignment(Qt::AlignCenter);

        verticalLayout_userdet->addWidget(label_sum_hostname);

        verticalLayoutWidget_5 = new QWidget(summary);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(310, 200, 191, 121));
        verticalLayout_pers = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_pers->setObjectName(QString::fromUtf8("verticalLayout_pers"));
        verticalLayout_pers->setContentsMargins(0, 0, 0, 0);
        label_sum_pers = new QLabel(verticalLayoutWidget_5);
        label_sum_pers->setObjectName(QString::fromUtf8("label_sum_pers"));
        label_sum_pers->setAlignment(Qt::AlignCenter);

        verticalLayout_pers->addWidget(label_sum_pers);

        label_sum_desktop = new QLabel(verticalLayoutWidget_5);
        label_sum_desktop->setObjectName(QString::fromUtf8("label_sum_desktop"));
        label_sum_desktop->setAlignment(Qt::AlignCenter);

        verticalLayout_pers->addWidget(label_sum_desktop);

        label_sum_dm = new QLabel(verticalLayoutWidget_5);
        label_sum_dm->setObjectName(QString::fromUtf8("label_sum_dm"));
        label_sum_dm->setAlignment(Qt::AlignCenter);

        verticalLayout_pers->addWidget(label_sum_dm);

        label_sum_shell = new QLabel(verticalLayoutWidget_5);
        label_sum_shell->setObjectName(QString::fromUtf8("label_sum_shell"));
        label_sum_shell->setAlignment(Qt::AlignCenter);

        verticalLayout_pers->addWidget(label_sum_shell);

        label_sum_aurSupport = new QLabel(verticalLayoutWidget_5);
        label_sum_aurSupport->setObjectName(QString::fromUtf8("label_sum_aurSupport"));
        label_sum_aurSupport->setAlignment(Qt::AlignCenter);

        verticalLayout_pers->addWidget(label_sum_aurSupport);

        savePreseed_btn = new QPushButton(summary);
        savePreseed_btn->setObjectName(QString::fromUtf8("savePreseed_btn"));
        savePreseed_btn->setGeometry(QRect(390, 330, 111, 31));
        PhaseWidget->addWidget(summary);
        install = new QWidget();
        install->setObjectName(QString::fromUtf8("install"));
        textBrowser_install = new QTextBrowser(install);
        textBrowser_install->setObjectName(QString::fromUtf8("textBrowser_install"));
        textBrowser_install->setGeometry(QRect(0, 0, 511, 371));
        install_indicator_ph = new QLabel(install);
        install_indicator_ph->setObjectName(QString::fromUtf8("install_indicator_ph"));
        install_indicator_ph->setGeometry(QRect(30, 210, 451, 41));
        install_indicator_ph->setFrameShadow(QFrame::Plain);
        install_indicator_ph->setTextFormat(Qt::AutoText);
        install_indicator_ph->setAlignment(Qt::AlignCenter);
        PhaseWidget->addWidget(install);
        PreseedPage = new QWidget();
        PreseedPage->setObjectName(QString::fromUtf8("PreseedPage"));
        textBrowser_preseed = new QTextBrowser(PreseedPage);
        textBrowser_preseed->setObjectName(QString::fromUtf8("textBrowser_preseed"));
        textBrowser_preseed->setGeometry(QRect(0, 0, 511, 371));
        appPreseed_LineED_2 = new QLineEdit(PreseedPage);
        appPreseed_LineED_2->setObjectName(QString::fromUtf8("appPreseed_LineED_2"));
        appPreseed_LineED_2->setGeometry(QRect(180, 300, 291, 26));
        appPreseed_LineED_2->setAutoFillBackground(false);
        appPreseed_LineED_2->setFrame(true);
        appPreseed_LineED_2->setAlignment(Qt::AlignCenter);
        appPreseed_LineED_2->setReadOnly(true);
        label_appPreseed_pr = new QLabel(PreseedPage);
        label_appPreseed_pr->setObjectName(QString::fromUtf8("label_appPreseed_pr"));
        label_appPreseed_pr->setGeometry(QRect(30, 270, 101, 21));
        btn_open_ap_pr = new QPushButton(PreseedPage);
        btn_open_ap_pr->setObjectName(QString::fromUtf8("btn_open_ap_pr"));
        btn_open_ap_pr->setGeometry(QRect(180, 270, 291, 26));
        label_required_5 = new QLabel(PreseedPage);
        label_required_5->setObjectName(QString::fromUtf8("label_required_5"));
        label_required_5->setGeometry(QRect(30, 330, 71, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_required_5->setPalette(palette6);
        btn_open_pr = new QPushButton(PreseedPage);
        btn_open_pr->setObjectName(QString::fromUtf8("btn_open_pr"));
        btn_open_pr->setGeometry(QRect(180, 200, 291, 26));
        label_preseed = new QLabel(PreseedPage);
        label_preseed->setObjectName(QString::fromUtf8("label_preseed"));
        label_preseed->setGeometry(QRect(30, 200, 101, 21));
        preseed_LineED = new QLineEdit(PreseedPage);
        preseed_LineED->setObjectName(QString::fromUtf8("preseed_LineED"));
        preseed_LineED->setGeometry(QRect(180, 230, 291, 26));
        preseed_LineED->setAutoFillBackground(false);
        preseed_LineED->setFrame(true);
        preseed_LineED->setAlignment(Qt::AlignCenter);
        preseed_LineED->setReadOnly(true);
        label_rtpasswd_nomatch_pr = new QLabel(PreseedPage);
        label_rtpasswd_nomatch_pr->setObjectName(QString::fromUtf8("label_rtpasswd_nomatch_pr"));
        label_rtpasswd_nomatch_pr->setGeometry(QRect(180, 170, 191, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_rtpasswd_nomatch_pr->setPalette(palette7);
        password_LineED_pr_2 = new QLineEdit(PreseedPage);
        password_LineED_pr_2->setObjectName(QString::fromUtf8("password_LineED_pr_2"));
        password_LineED_pr_2->setGeometry(QRect(330, 100, 141, 26));
        password_LineED_pr_2->setEchoMode(QLineEdit::Password);
        label_rootpasswd_2 = new QLabel(PreseedPage);
        label_rootpasswd_2->setObjectName(QString::fromUtf8("label_rootpasswd_2"));
        label_rootpasswd_2->setGeometry(QRect(30, 150, 101, 18));
        rootpasswd_LineED_pr2 = new QLineEdit(PreseedPage);
        rootpasswd_LineED_pr2->setObjectName(QString::fromUtf8("rootpasswd_LineED_pr2"));
        rootpasswd_LineED_pr2->setGeometry(QRect(330, 150, 141, 26));
        rootpasswd_LineED_pr2->setEchoMode(QLineEdit::Password);
        label_passwd_nomatch_pr = new QLabel(PreseedPage);
        label_passwd_nomatch_pr->setObjectName(QString::fromUtf8("label_passwd_nomatch_pr"));
        label_passwd_nomatch_pr->setGeometry(QRect(180, 120, 191, 31));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_passwd_nomatch_pr->setPalette(palette8);
        password_LineED_pr = new QLineEdit(PreseedPage);
        password_LineED_pr->setObjectName(QString::fromUtf8("password_LineED_pr"));
        password_LineED_pr->setGeometry(QRect(180, 100, 135, 26));
        password_LineED_pr->setEchoMode(QLineEdit::Password);
        label_password_2 = new QLabel(PreseedPage);
        label_password_2->setObjectName(QString::fromUtf8("label_password_2"));
        label_password_2->setGeometry(QRect(30, 100, 81, 18));
        rootpasswd_LineED_pr = new QLineEdit(PreseedPage);
        rootpasswd_LineED_pr->setObjectName(QString::fromUtf8("rootpasswd_LineED_pr"));
        rootpasswd_LineED_pr->setGeometry(QRect(180, 150, 135, 26));
        rootpasswd_LineED_pr->setEchoMode(QLineEdit::Password);
        PhaseWidget->addWidget(PreseedPage);

        gridLayout->addWidget(PhaseWidget, 0, 0, 1, 1);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 410, 121, 24));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 131, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        indicator_intro = new QPushButton(verticalLayoutWidget);
        indicator_intro->setObjectName(QString::fromUtf8("indicator_intro"));
        indicator_intro->setStyleSheet(QString::fromUtf8(""));
        indicator_intro->setFlat(false);

        verticalLayout->addWidget(indicator_intro);

        indicator_preseed = new QPushButton(verticalLayoutWidget);
        indicator_preseed->setObjectName(QString::fromUtf8("indicator_preseed"));
        indicator_preseed->setStyleSheet(QString::fromUtf8(""));
        indicator_preseed->setFlat(false);

        verticalLayout->addWidget(indicator_preseed);

        indicator_part = new QPushButton(verticalLayoutWidget);
        indicator_part->setObjectName(QString::fromUtf8("indicator_part"));
        indicator_part->setStyleSheet(QString::fromUtf8(""));
        indicator_part->setFlat(false);

        verticalLayout->addWidget(indicator_part);

        indicator_locale = new QPushButton(verticalLayoutWidget);
        indicator_locale->setObjectName(QString::fromUtf8("indicator_locale"));
        indicator_locale->setStyleSheet(QString::fromUtf8(""));
        indicator_locale->setFlat(false);

        verticalLayout->addWidget(indicator_locale);

        indicator_user = new QPushButton(verticalLayoutWidget);
        indicator_user->setObjectName(QString::fromUtf8("indicator_user"));
        indicator_user->setStyleSheet(QString::fromUtf8(""));
        indicator_user->setFlat(false);

        verticalLayout->addWidget(indicator_user);

        indicator_personalization = new QPushButton(verticalLayoutWidget);
        indicator_personalization->setObjectName(QString::fromUtf8("indicator_personalization"));
        indicator_personalization->setStyleSheet(QString::fromUtf8(""));
        indicator_personalization->setFlat(false);

        verticalLayout->addWidget(indicator_personalization);

        indicator_summary = new QPushButton(verticalLayoutWidget);
        indicator_summary->setObjectName(QString::fromUtf8("indicator_summary"));
        indicator_summary->setStyleSheet(QString::fromUtf8(""));
        indicator_summary->setFlat(false);

        verticalLayout->addWidget(indicator_summary);

        indicator_install = new QPushButton(verticalLayoutWidget);
        indicator_install->setObjectName(QString::fromUtf8("indicator_install"));
        indicator_install->setStyleSheet(QString::fromUtf8(""));
        indicator_install->setFlat(false);

        verticalLayout->addWidget(indicator_install);

        Next_btn = new QPushButton(centralwidget);
        Next_btn->setObjectName(QString::fromUtf8("Next_btn"));
        Next_btn->setGeometry(QRect(560, 390, 101, 31));
        Back_btn = new QPushButton(centralwidget);
        Back_btn->setObjectName(QString::fromUtf8("Back_btn"));
        Back_btn->setGeometry(QRect(440, 390, 101, 31));
        TextOut = new QPlainTextEdit(centralwidget);
        TextOut->setObjectName(QString::fromUtf8("TextOut"));
        TextOut->setGeometry(QRect(10, 440, 651, 201));
        QPalette palette9;
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        TextOut->setPalette(palette9);
        TextOut->setReadOnly(true);
        yalai->setCentralWidget(centralwidget);
        menubar = new QMenuBar(yalai);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 674, 23));
        yalai->setMenuBar(menubar);
        statusbar = new QStatusBar(yalai);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        yalai->setStatusBar(statusbar);

        retranslateUi(yalai);

        PhaseWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(yalai);
    } // setupUi

    void retranslateUi(QMainWindow *yalai)
    {
        yalai->setWindowTitle(QCoreApplication::translate("yalai", "yalai", nullptr));
        textBrowser_welcome->setHtml(QCoreApplication::translate("yalai", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Welcome to YaLAI (Yet another Live Arch Installer)!</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:600;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">YaLAI was created, to help people get Arch Linux in"
                        "stalled quickly and easily.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Once you click the 'Next' button on this page, you will be prompted with a set of questions that will guide you through the installation.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">(Alternatively, you can click the 'Preseed mode' checkbox, if you want to perform a preseed installation.)</p></body></html>", nullptr));
        checkBox_preseed->setText(QCoreApplication::translate("yalai", "Preseed mode", nullptr));
        pushButton->setText(QCoreApplication::translate("yalai", "Open GParted", nullptr));
        textBrowser_partsel->setHtml(QCoreApplication::translate("yalai", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Partition selection</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Please select the path of the partitions that you would like to use for the installation of Arch.</p></body></html>", nullptr));
        label_swap->setText(QCoreApplication::translate("yalai", "Swap partition", nullptr));
        label_efi->setText(QCoreApplication::translate("yalai", "EFI Parition (/boot/EFI)", nullptr));
        label_root->setText(QCoreApplication::translate("yalai", "Root partition (/)", nullptr));
        label_block->setText(QCoreApplication::translate("yalai", "Block device", nullptr));
        dropdown_block->setItemText(0, QCoreApplication::translate("yalai", "---Select---", nullptr));

        dropdown_root->setItemText(0, QCoreApplication::translate("yalai", "---Select---", nullptr));

        dropdown_swap->setItemText(0, QCoreApplication::translate("yalai", "---Select---", nullptr));

        dropdown_efi->setItemText(0, QCoreApplication::translate("yalai", "---Select---", nullptr));

        label_required->setText(QCoreApplication::translate("yalai", "* Required", nullptr));
        textBrowser_locale->setHtml(QCoreApplication::translate("yalai", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Timezone and localization</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Please select your timezone, subzone, keyboard layout and desired language.</p></body></html>", nullptr));
        lebel_keylayout->setText(QCoreApplication::translate("yalai", "Keyboard layout", nullptr));
        label_lang->setText(QCoreApplication::translate("yalai", "Language", nullptr));
        label_timezone->setText(QCoreApplication::translate("yalai", "Timezone", nullptr));
        label_subzone->setText(QCoreApplication::translate("yalai", "Subzone", nullptr));
        label_required_2->setText(QCoreApplication::translate("yalai", "* Required", nullptr));
        textBrowser_user_details->setHtml(QCoreApplication::translate("yalai", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">User details and hostname</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Please enter your desired username, password, root password and hostname for your installation.</p></body></html>", nullptr));
        label_username->setText(QCoreApplication::translate("yalai", "Username", nullptr));
        label_password->setText(QCoreApplication::translate("yalai", "Password", nullptr));
        password_LineED_1->setText(QString());
        password_LineED_2->setText(QString());
        label_hostname->setText(QCoreApplication::translate("yalai", "Hostname", nullptr));
        hostname_LineED->setText(QString());
        rootpasswd_LineED_1->setText(QString());
        rootpasswd_LineED_2->setText(QString());
        label_rootpasswd->setText(QCoreApplication::translate("yalai", "Root password", nullptr));
        label_required_3->setText(QCoreApplication::translate("yalai", "* Required", nullptr));
        label_rtpasswd_nomatch->setText(QCoreApplication::translate("yalai", "Sorry, passwords do not match", nullptr));
        label_passwd_nomatch->setText(QCoreApplication::translate("yalai", "Sorry, passwords do not match", nullptr));
        textBrowser_personalization->setHtml(QCoreApplication::translate("yalai", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Personalization</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Please select your desired shell, desktop environment, display manager.</p></body></html>", nullptr));
        label_de->setText(QCoreApplication::translate("yalai", "Desktop environment", nullptr));
        label_shell->setText(QCoreApplication::translate("yalai", "Shell", nullptr));
        dropdown_dm->setItemText(0, QCoreApplication::translate("yalai", "---Select---", nullptr));
        dropdown_dm->setItemText(1, QCoreApplication::translate("yalai", "GDM", nullptr));
        dropdown_dm->setItemText(2, QCoreApplication::translate("yalai", "SDDM", nullptr));
        dropdown_dm->setItemText(3, QCoreApplication::translate("yalai", "LightDM", nullptr));
        dropdown_dm->setItemText(4, QCoreApplication::translate("yalai", "LXDM", nullptr));

        label_required_4->setText(QCoreApplication::translate("yalai", "* Required", nullptr));
        dropdown_de->setItemText(0, QCoreApplication::translate("yalai", "---Select---", nullptr));
        dropdown_de->setItemText(1, QCoreApplication::translate("yalai", "Gnome", nullptr));
        dropdown_de->setItemText(2, QCoreApplication::translate("yalai", "KDE_Plasma", nullptr));
        dropdown_de->setItemText(3, QCoreApplication::translate("yalai", "Mate", nullptr));
        dropdown_de->setItemText(4, QCoreApplication::translate("yalai", "Cinnamon", nullptr));
        dropdown_de->setItemText(5, QCoreApplication::translate("yalai", "Budgie", nullptr));
        dropdown_de->setItemText(6, QCoreApplication::translate("yalai", "Xfce", nullptr));
        dropdown_de->setItemText(7, QCoreApplication::translate("yalai", "Lxde", nullptr));

        lebel_dm->setText(QCoreApplication::translate("yalai", "Display manager", nullptr));
        dropdown_shell->setItemText(0, QCoreApplication::translate("yalai", "---Select---", nullptr));
        dropdown_shell->setItemText(1, QCoreApplication::translate("yalai", "Bash", nullptr));
        dropdown_shell->setItemText(2, QCoreApplication::translate("yalai", "Zsh", nullptr));
        dropdown_shell->setItemText(3, QCoreApplication::translate("yalai", "Fish", nullptr));

        label_appPreseed->setText(QCoreApplication::translate("yalai", "AppPreseed", nullptr));
        btn_open_ap->setText(QCoreApplication::translate("yalai", "Open preseed", nullptr));
        checkBox_aursupport->setText(QCoreApplication::translate("yalai", "AUR support (yay)", nullptr));
        textBrowser_summary->setHtml(QCoreApplication::translate("yalai", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Summary</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Here are the options you choose for the installation of Arch Linux. When you're ready, click the 'Next' button, to proceed with the installation.</p></body></html>", nullptr));
        label_sum_part->setText(QCoreApplication::translate("yalai", "<html><head/><body><p><span style=\" font-weight:600;\">Partitions:</span></p></body></html>", nullptr));
        label_sum_part_root->setText(QCoreApplication::translate("yalai", "Root partition", nullptr));
        label_sum_part_swap->setText(QCoreApplication::translate("yalai", "Swap partition", nullptr));
        label_sum_part_efi->setText(QCoreApplication::translate("yalai", "EFI partition", nullptr));
        label_sum_locale->setText(QCoreApplication::translate("yalai", "<html><head/><body><p><span style=\" font-weight:600;\">Localization:</span></p></body></html>", nullptr));
        label_sum_language->setText(QCoreApplication::translate("yalai", "Language", nullptr));
        label_sum_keylayout->setText(QCoreApplication::translate("yalai", "Keyboard layout", nullptr));
        label_sum_timezone->setText(QCoreApplication::translate("yalai", "Timezone, subzone", nullptr));
        label_sum_userdet->setText(QCoreApplication::translate("yalai", "<html><head/><body><p><span style=\" font-weight:600;\">User details:</span></p></body></html>", nullptr));
        label_sum_username->setText(QCoreApplication::translate("yalai", "Username", nullptr));
        label_sum_hostname->setText(QCoreApplication::translate("yalai", "Hostname", nullptr));
        label_sum_pers->setText(QCoreApplication::translate("yalai", "<html><head/><body><p><span style=\" font-weight:600;\">Personalization:</span></p></body></html>", nullptr));
        label_sum_desktop->setText(QCoreApplication::translate("yalai", "Desktop environment", nullptr));
        label_sum_dm->setText(QCoreApplication::translate("yalai", "Display manager", nullptr));
        label_sum_shell->setText(QCoreApplication::translate("yalai", "Shell", nullptr));
        label_sum_aurSupport->setText(QCoreApplication::translate("yalai", "AUR support", nullptr));
        savePreseed_btn->setText(QCoreApplication::translate("yalai", "Save preseed...", nullptr));
        textBrowser_install->setHtml(QCoreApplication::translate("yalai", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Installation</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Thank you for choosing YaLAI as your installer. Sit back, relax, maybe have a cup of coffee. Also, while YaLAI installs Arch, you can see the progress of the installation bellow.</p></body></html>", nullptr));
        install_indicator_ph->setText(QCoreApplication::translate("yalai", "Install phase", nullptr));
        textBrowser_preseed->setHtml(QCoreApplication::translate("yalai", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Preseed selection</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">In the previous phase you checked the 'Preseed mode' checkbox. This means, that the installer will gather all user input from a preseed configuration file. Please choose your preseed file.</p></body></html>", nullptr));
        label_appPreseed_pr->setText(QCoreApplication::translate("yalai", "AppPreseed", nullptr));
        btn_open_ap_pr->setText(QCoreApplication::translate("yalai", "Open preseed", nullptr));
        label_required_5->setText(QCoreApplication::translate("yalai", "* Required", nullptr));
        btn_open_pr->setText(QCoreApplication::translate("yalai", "Open preseed", nullptr));
        label_preseed->setText(QCoreApplication::translate("yalai", "Preseed", nullptr));
        label_rtpasswd_nomatch_pr->setText(QCoreApplication::translate("yalai", "Sorry, passwords do not match", nullptr));
        password_LineED_pr_2->setText(QString());
        label_rootpasswd_2->setText(QCoreApplication::translate("yalai", "Root password", nullptr));
        rootpasswd_LineED_pr2->setText(QString());
        label_passwd_nomatch_pr->setText(QCoreApplication::translate("yalai", "Sorry, passwords do not match", nullptr));
        password_LineED_pr->setText(QString());
        label_password_2->setText(QCoreApplication::translate("yalai", "Password", nullptr));
        rootpasswd_LineED_pr->setText(QString());
        checkBox->setText(QCoreApplication::translate("yalai", "Output console", nullptr));
        indicator_intro->setText(QCoreApplication::translate("yalai", "Introduction", nullptr));
        indicator_preseed->setText(QCoreApplication::translate("yalai", "Preseed options", nullptr));
        indicator_part->setText(QCoreApplication::translate("yalai", "Partition selection", nullptr));
        indicator_locale->setText(QCoreApplication::translate("yalai", "Localization", nullptr));
        indicator_user->setText(QCoreApplication::translate("yalai", "User details", nullptr));
        indicator_personalization->setText(QCoreApplication::translate("yalai", "Personalization", nullptr));
        indicator_summary->setText(QCoreApplication::translate("yalai", "Summary", nullptr));
        indicator_install->setText(QCoreApplication::translate("yalai", "Installation", nullptr));
        Next_btn->setText(QCoreApplication::translate("yalai", "Next", nullptr));
        Back_btn->setText(QCoreApplication::translate("yalai", "Back", nullptr));
        TextOut->setPlaceholderText(QCoreApplication::translate("yalai", "*Command output*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yalai: public Ui_yalai {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YALAI_H
