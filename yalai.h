#ifndef YALAI_H
#define YALAI_H

#include <QMainWindow>
#include <QMessageBox>
#include <QProcess>
#include <QDateTime>
#include <QFileSystemWatcher>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class yalai; }
QT_END_NAMESPACE

class yalai : public QMainWindow
{
    Q_OBJECT

public:
    // Console messages
    void debug_msg(QString msg, QString type);
    // Progress monitoring
    void progressChanged();
    yalai(QWidget *parent = nullptr);
    ~yalai();

private slots:
    // La code executer
    void exec(QString cmd, QStringList parameters);
    void readErr();
    void readOutput();
    // Phase selector
    void phase(int phase);
    // Sidebar indicator setup
    void indicatorSetup();
    // Terminal checkbox
    void on_checkBox_stateChanged(int arg1);
    // Partition selection
    void mkdrivelist();
    void mkpartlist(QString disk);
    void on_dropdown_block_currentIndexChanged(int index);
    void on_dropdown_root_currentIndexChanged(int index);
    void on_dropdown_swap_currentIndexChanged(int index);
    void on_dropdown_efi_currentIndexChanged(int index);
    void on_pushButton_clicked();
    void dropdownConfig(QString action);
    // Phase 1: verifier
    void verify_phase1();
    // Phase 3
    void mklanglist();
    void mkkeymaplist();
    void mkzonelist();
    void mksubzonelist(QString zone);
    void on_dropdown_language_currentTextChanged(const QString &arg1);
    void on_dropdown_keylayout_currentTextChanged(const QString &arg1);
    void on_dropdown_timezone_currentTextChanged(const QString &arg1);
    void on_dropdown_subzone_currentTextChanged(const QString &arg1);
    // Phase 3: verifier
    void verify_phase3();
    // Phase 5
    void inputConfig();
    // Phase 5: verifier
    void verify_phase5();
    // Phase 7
    void on_dropdown_de_currentTextChanged(const QString &arg1);
    void on_dropdown_dm_currentTextChanged(const QString &arg1);
    void on_dropdown_shell_currentTextChanged(const QString &arg1);
    void on_btn_open_ap_clicked();
    void on_checkBox_aursupport_stateChanged(int arg1);
    // Phase 7: verifier
    void verify_phase7();
    // Phase 9
    void on_savePreseed_btn_clicked();
    // BootMode detector
    QString isEFI();
    // Back and next buttons
    void on_Next_btn_clicked();
    void on_Back_btn_clicked();
    // Phase 0
    void on_checkBox_preseed_stateChanged(int arg1);
    void preseedSetup();
    void nullAll();
    // Phase 100
    void on_btn_open_pr_clicked();
    void on_btn_open_ap_pr_clicked();
    // Phase 101
    void verify_phase100();
    void loadPreseed();
    // Installation
    void install();
    void installFinished();
private:
    // Phase select
    int phase_state = 0;
    // Preseed
    bool preseed = false;
    QString preseed_path = NULL;
    // Partition selection
    QString root_part = NULL;
    QString swap_part = NULL;
    QString efi_part = NULL;
    QString disk = NULL;
    int root_part_int = 0;
    int swap_part_int = 0;
    int efi_part_int = 0;
    int disk_int = 0;
    // Localization
    QString lang = NULL;
    QString keylayout = NULL;
    QString zone = NULL;
    QString subzone = NULL;
    bool locale_has_run = false;
    // User details
    QString username = NULL;
    QString passwd1 = NULL;
    QString passwd2 = NULL;
    QString rootpasswd1 = NULL;
    QString rootpasswd2 = NULL;
    QString hostname = NULL;
    // Personalization
    QString de = NULL;
    int de_int = 0;
    QString dm = NULL;
    int dm_int = 0;
    QString shell = NULL;
    int shell_int = 0;
    QString appPreseed_path = NULL;
    bool aursupport = false;
    // exec()
    QProcess *p = new QProcess( this );
    // Install
    bool captureProgress = false;
    // UI constructor
    Ui::yalai *ui;
};
#endif // YALAI_H
