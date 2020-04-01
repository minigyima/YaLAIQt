#include "yalai.h"
#include "ui_yalai.h"
yalai::yalai(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::yalai)
{
    ui->setupUi(this);
    // Output console setup, disabled by default
    this->setFixedSize(674, 458);
    ui->TextOut->setVisible(false);
    ui->TextOut->setReadOnly(true);
    // Setting Phase to default (0)
    phase(phase_state);
    //phase(7);
    // Application title
    QString version = "3.1";
    debug_msg(QString("Starting YaLAI (version: %1)...").arg(version), "msg");
    QString title = QString("YaLAI (version: %1, Running in: %2 mode)").arg(version, isEFI());
    this->setWindowTitle(title);
}

yalai::~yalai()
{
    delete ui;
}
// Output console handling: Execution
void yalai::exec(QString cmd, QStringList parameters) {
    if (p)
    {
      p->setEnvironment( QProcess::systemEnvironment() );
      p->setProcessChannelMode( QProcess::MergedChannels );
      p->start( cmd, parameters);
      p->waitForStarted();

      connect( p, SIGNAL(readyReadStandardOutput()), this, SLOT(readOutput()) );
      connect( p, SIGNAL(readyReadStandardError()), this, SLOT(readErr()) );
      connect(p, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),

      [=]  ()
      {

      }

      );
    }
}
// Output console handling: Command output
void yalai::readOutput()  {
    QProcess *p = dynamic_cast<QProcess *>( sender() );
    debug_msg(p->readAllStandardOutput(), "output");
    qDebug() << p->readAllStandardOutput();
}
// Output console handling: Error output
void yalai::readErr()  {
    QProcess *p = dynamic_cast<QProcess *>( sender() );
    debug_msg(p->readAllStandardError(), "error");
}
// Output console hide/show
void yalai::on_checkBox_stateChanged(int arg1)
{
    switch (arg1) {
        case 2:
        this->setFixedSize(674, 681);
        ui->TextOut->setVisible(true);
        break;
        case 0:
        this->setFixedSize(674, 458);
        ui->TextOut->setVisible(false);
        break;
    }
}
// Phase switcher
void yalai::phase(int phase_call) {
    QString aursupport_text = NULL;
    switch (phase_call) {
        case 0:
            debug_msg("# Phase 0 (Welcome text, preseed)", "phase");
            // Phase 0 (aka welcome message)
            ui->Back_btn->setVisible(false);
            ui->Next_btn->setVisible(true);
            if (preseed == false) {
                indicatorSetup();
            }
            else {
                preseedSetup();
            }
            ui->PhaseWidget->setCurrentIndex(0);
            ui->indicator_intro->setStyleSheet("background-color: #5090DC; color: white;");
            // End of Phase 0
        break;
        case 1:
            // Phase 1
            debug_msg("# Phase 1 (Partition selection)", "phase");
            indicatorSetup();
            ui->Back_btn->setVisible(true);
            ui->Next_btn->setVisible(true);
            ui->PhaseWidget->setCurrentIndex(1);
            ui->indicator_part->setStyleSheet("background-color: #5090DC; color: white;");
            dropdownConfig("HideAll");
            ui->label_required->setVisible(false);
            ui->dropdown_root->setStyleSheet("");
            ui->dropdown_efi->setStyleSheet("");
            ui->dropdown_swap->setStyleSheet("");
            ui->dropdown_block->setStyleSheet("");
            dropdownConfig("Initialize_block");
            mkdrivelist();
            ui->dropdown_block->setCurrentIndex(disk_int);
            // End of Phase 1
        break;
        case 2:
            debug_msg("# Phase 2 (Phase 1: Verifier)", "phase");
            // Phase 2
            ui->dropdown_root->setStyleSheet("");
            ui->dropdown_efi->setStyleSheet("");
            ui->dropdown_swap->setStyleSheet("");
            ui->dropdown_block->setStyleSheet("");
            ui->label_required->setVisible(false);
            verify_phase1();
            // End of Phase 2
        break;
        case 3:
            // Phase 3
            debug_msg("# Phase 3 (Localiation)", "phase");
            indicatorSetup();
            ui->PhaseWidget->setCurrentIndex(2);
            ui->Next_btn->setVisible(true);
            ui->Back_btn->setVisible(true);
            ui->indicator_locale->setStyleSheet("background-color: #5090DC; color: white;");
            ui->label_required_2->setVisible(false);
            if (locale_has_run == false) {
                mklanglist();
                mkkeymaplist();
                mkzonelist();
            }
            // End of Phase 3
        break;
        case 4:
            // Phase 4
            debug_msg("# Phase 4 (Phase 3: Verifier)", "phase");
            ui->dropdown_language->setStyleSheet("");
            ui->dropdown_keylayout->setStyleSheet("");
            ui->dropdown_timezone->setStyleSheet("");
            ui->dropdown_subzone->setStyleSheet("");
            ui->label_required_2->setVisible(false);
            verify_phase3();
            // End of Phase 4
        break;
        case 5:
            // Phase 5
            debug_msg("# Phase 5 (User details)", "phase");
            ui->label_required_3->setVisible(false);
            ui->label_passwd_nomatch->setVisible(false);
            ui->label_rtpasswd_nomatch->setVisible(false);
            ui->Next_btn->setVisible(true);
            ui->Back_btn->setVisible(true);
            indicatorSetup();
            ui->indicator_user->setStyleSheet("background-color: #5090DC; color: white;");
            ui->PhaseWidget->setCurrentIndex(3);
            inputConfig();
            ui->username_LineED->setText(username);
            ui->password_LineED_1->setText(passwd1);
            ui->password_LineED_2->setText(passwd2);
            ui->rootpasswd_LineED_1->setText(rootpasswd1);
            ui->rootpasswd_LineED_2->setText(rootpasswd2);
            ui->hostname_LineED->setText(hostname);
            ui->appPreseed_LineED->setText(appPreseed_path);
            // End of Phase 5
        break;
        case 6:
            // Phase 6
            debug_msg("# Phase 6 (Phase 5: Verifier)", "phase");
            ui->label_required_3->setVisible(false);
            ui->label_passwd_nomatch->setVisible(false);
            ui->label_rtpasswd_nomatch->setVisible(false);
            inputConfig();
            verify_phase5();
            //debug_msg(ui->username_LineED->text(), "msg");
            // End of Phase 6
        break;
        case 7:
            // Phase 7
            debug_msg("# Phase 7 (Personalization)", "phase");
            ui->Next_btn->setVisible(true);
            ui->Back_btn->setVisible(true);
            ui->label_required_4->setVisible(false);
            ui->dropdown_de->setStyleSheet("");
            ui->dropdown_dm->setStyleSheet("");
            ui->dropdown_shell->setStyleSheet("");
            indicatorSetup();
            ui->indicator_personalization->setStyleSheet("background-color: #5090DC; color: white;");
            ui->appPreseed_LineED->setText("./appPreseed.conf");
            ui->checkBox_aursupport->setChecked(aursupport);
            ui->label_required_4->setVisible(false);
            ui->PhaseWidget->setCurrentIndex(4);
            // End of Phase 7
        break;
        case 8:
            debug_msg("# Phase 8 (Phase 7: Verifier)", "phase");
            // Phase 8 (Phase 7: Verifier)
            ui->label_required_4->setVisible(false);
            ui->dropdown_de->setStyleSheet("");
            ui->dropdown_dm->setStyleSheet("");
            ui->dropdown_shell->setStyleSheet("");
            verify_phase7();
            // End of Phase 8
        break;
        case 9:
            // Phase 9
            debug_msg("# Phase 9 (Summary)", "phase");
            ui->Next_btn->setVisible(true);
            ui->Back_btn->setVisible(true);
            if (preseed == false) {
                indicatorSetup();
            }
            else {
                preseedSetup();
            }
            ui->indicator_summary->setStyleSheet("background-color: #5090DC; color: white;");
            ui->PhaseWidget->setCurrentIndex(5);
            // Labels - Partitions
            ui->label_sum_part_root->setText(QString("Root partition: %1").arg(root_part));
            ui->label_sum_part_swap->setText(QString("Swap partition: %1").arg(swap_part));
            if (isEFI() == "UEFI") {
                ui->label_sum_part_efi->setText(QString("EFI partition: %1").arg(efi_part));
            }
            // Labels - Localization
            ui->label_sum_language->setText(QString("Language: %1").arg(lang));
            ui->label_sum_keylayout->setText(QString("Keyboard layout: %1").arg(keylayout));
            ui->label_sum_timezone->setText(QString("Timezone, subzone: %1, %2").arg(zone, subzone));
            // Labels - User details
            ui->label_sum_username->setText(QString("Username: %1").arg(username));
            ui->label_sum_hostname->setText(QString("Hostname: %1").arg(hostname));
            // Labels - Personalization
            ui->label_sum_desktop->setText(QString("Desktop environment: %1").arg(de));
            ui->label_sum_dm->setText(QString("Display manager: %1").arg(dm));
            ui->label_sum_shell->setText(QString("Shell: %1").arg(shell));
            if (aursupport == true) {
                aursupport_text = "YES";
            }
            else {
                aursupport_text = "NO";
            }
            ui->label_sum_aurSupport->setText(QString("AUR support: %1").arg(aursupport_text));
            // End of Phase 9
        break;
        case 10:
            // Install start
            debug_msg("# Phase 10 (Installation)", "phase");
            ui->Next_btn->setVisible(false);
            ui->Back_btn->setVisible(true);
            if (preseed == false) {
                indicatorSetup();
            }
            else {
                preseedSetup();
            }
            ui->indicator_install->setStyleSheet("background-color: #5090DC; color: white;");
            ui->PhaseWidget->setCurrentIndex(6);
            install();
            // Install end
        break;
        case 100:
            // Pressed phase
            debug_msg("# Phase '100' (Preseed phase)", "phase");
            ui->PhaseWidget->setCurrentIndex(7);
            preseedSetup();
            ui->Back_btn->setVisible(true);
            ui->Next_btn->setVisible(true);
            ui->indicator_preseed->setStyleSheet("background-color: #5090DC; color: white;");
            ui->btn_open_pr->setStyleSheet("");
            ui->btn_open_ap_pr->setStyleSheet("");
            ui->label_passwd_nomatch_pr->setVisible(false);
            ui->label_rtpasswd_nomatch_pr->setVisible(false);
            ui->label_required_5->setVisible(false);
            ui->appPreseed_LineED_2->setText(appPreseed_path);
            ui->preseed_LineED->setText(preseed_path);
            ui->password_LineED_pr->setText(passwd1);
            ui->password_LineED_pr_2->setText(passwd2);
            ui->rootpasswd_LineED_pr->setText(rootpasswd1);
            ui->rootpasswd_LineED_pr2->setText(rootpasswd2);
            ui->password_LineED_pr->setStyleSheet("border: 1px solid #5090DC");
            ui->password_LineED_pr_2->setStyleSheet("border: 1px solid #5090DC");
            ui->rootpasswd_LineED_pr->setStyleSheet("border: 1px solid #5090DC");
            ui->rootpasswd_LineED_pr2->setStyleSheet("border: 1px solid #5090DC");
            // End of preseed phase
        break;
        case 101:
            // Phase '101' (Phase 100 - Verifier)
            debug_msg("# Phase '101' (Preseed phase - Verifier)", "phase");
            ui->label_passwd_nomatch_pr->setVisible(false);
            ui->label_rtpasswd_nomatch_pr->setVisible(false);
            ui->label_required_5->setVisible(false);
            ui->btn_open_pr->setStyleSheet("");
            ui->btn_open_ap_pr->setStyleSheet("");
            ui->password_LineED_pr->setStyleSheet("border: 1px solid #5090DC");
            ui->password_LineED_pr_2->setStyleSheet("border: 1px solid #5090DC");
            ui->rootpasswd_LineED_pr->setStyleSheet("border: 1px solid #5090DC");
            ui->rootpasswd_LineED_pr2->setStyleSheet("border: 1px solid #5090DC");
            verify_phase100();
            // End of Phase '101'
        break;
        case 102:
            // Phase '102' - The preseed loader
            debug_msg("# Phase '102' (Preseed phase - The preseed loader)", "phase");
            loadPreseed();
            // End of Phase '102'
        break;
    }

}
// Sidebar indicator setup
void yalai::indicatorSetup() {
    // Disable preseed indicators && Enable normal indicators
    ui->indicator_intro->setVisible(true);
    ui->indicator_part->setVisible(true);
    ui->indicator_locale->setVisible(true);
    ui->indicator_user->setVisible(true);
    ui->indicator_personalization->setVisible(true);
    ui->indicator_summary->setVisible(true);
    ui->indicator_install->setVisible(true);
    ui->indicator_preseed->setVisible(false);
    // Indicator style - state
    ui->indicator_intro->setDisabled(true);
    ui->indicator_part->setDisabled(true);
    ui->indicator_locale->setDisabled(true);
    ui->indicator_user->setDisabled(true);
    ui->indicator_personalization->setDisabled(true);
    ui->indicator_summary->setDisabled(true);
    ui->indicator_install->setDisabled(true);
    // Indicator style - color
    ui->indicator_part->setStyleSheet("background-color: #404756;");
    ui->indicator_intro->setStyleSheet("background-color: #404756;");
    ui->indicator_locale->setStyleSheet("background-color: #404756;");
    ui->indicator_user->setStyleSheet("background-color: #404756;");
    ui->indicator_personalization->setStyleSheet("background-color: #404756;");
    ui->indicator_summary->setStyleSheet("background-color: #404756;");
    ui->indicator_install->setStyleSheet("background-color: #404756;");
}
// Next button handling
void yalai::on_Next_btn_clicked()
{
    if (preseed == true && phase_state == 0) {
        phase_state = 100;
        phase(phase_state);
    }
    else {
        int newphase = phase_state + 1;
        phase_state = newphase;
        phase(newphase);
    }
}
// Back button handling
void yalai::on_Back_btn_clicked()
{
    if (phase_state == 3 || phase_state == 5 || phase_state == 7 || (phase_state == 9 && preseed == false)) {
        phase_state = phase_state - 2;
        phase(phase_state);
    }
    else if (phase_state == 100) {
        phase_state = 0;
        phase(phase_state);
    }
    else if (phase_state == 9 && preseed == true) {
        phase_state = 100;
        phase(phase_state);
    }
    else {
        int newphase = phase_state - 1;
        phase_state = newphase;
        phase(newphase);
    }
}
// Phase 0
    void yalai::on_checkBox_preseed_stateChanged(int arg1)
    {
        switch (arg1) {
            case 2:
            debug_msg("Preseed mode!", "msg");
            preseed = true;
            preseedSetup();
            // Null all varriables
            nullAll();
            ui->indicator_intro->setStyleSheet("background-color: #5090DC; color: white;");
            break;
            case 0:
            debug_msg("Normal mode!", "msg");
            nullAll();
            preseed = false;
            indicatorSetup();
            ui->indicator_intro->setStyleSheet("background-color: #5090DC; color: white;");
            break;
        }
    }
    // Null all varriables
    void yalai::nullAll()  {
        debug_msg("Clearing all varriables...", "phase");
        QString preseed_path = "";
        // Partition selection
        root_part = "";
        swap_part = "";
        efi_part = "";
        disk = "";
        root_part_int = 0;
        swap_part_int = 0;
        efi_part_int = 0;
        disk_int = 0;
        // Localization
        lang = "";
        keylayout = "";
        zone = "";
        subzone = "";
        locale_has_run = false;
        // User details
        username = "";
        passwd1 = "";
        passwd2 = "";
        rootpasswd1 = "";
        rootpasswd2 = "";
        hostname = "";
        // Personalization
        de = "";
        de_int = 0;
        dm = "";
        dm_int = 0;
        shell = "";
        shell_int = 0;
        appPreseed_path = "";
        preseed_path = "";
        aursupport = false;
        captureProgress = false;
    }
    // Set the interface up for preseed support
    void yalai::preseedSetup() {
        // Disable normal indicators
        ui->indicator_intro->setVisible(true);
        ui->indicator_part->setVisible(false);
        ui->indicator_locale->setVisible(false);
        ui->indicator_user->setVisible(false);
        ui->indicator_personalization->setVisible(false);
        ui->indicator_summary->setVisible(true);
        ui->indicator_preseed->setVisible(true);
        ui->indicator_install->setVisible(true);
        // Set up needed indicators - state
        ui->indicator_intro->setDisabled(true);
        ui->indicator_summary->setDisabled(true);
        ui->indicator_preseed->setDisabled(true);
        ui->indicator_install->setDisabled(true);
        // Set up needed indicators - color
        ui->indicator_summary->setStyleSheet("background-color: #404756;");
        ui->indicator_preseed->setStyleSheet("background-color: #404756;");
        ui->indicator_intro->setStyleSheet("background-color: #404756;");
        ui->indicator_install->setStyleSheet("background-color: #404756;");
    }
// End of Phase 0
// Phase '100' Preseed phase
    void yalai::on_btn_open_pr_clicked()
    {
        QString file = NULL;
        file =  (QFileDialog::getOpenFileName(this, tr("YaLAI - Open Preseed"), "./"));
        if (file != NULL) {
            ui->preseed_LineED->setText(file);
            preseed_path = file;
        }
    }
    void yalai::on_btn_open_ap_pr_clicked()
    {
        QString file = NULL;
        file =  (QFileDialog::getOpenFileName(this, tr("YaLAI - Open AppPreseed"), "./"));
        if (file != NULL) {
            ui->appPreseed_LineED_2->setText(file);
            appPreseed_path = file;
        }
    }
// End of Phase '100'
// Phase '101' - Phase 100 Verifier
    void yalai::verify_phase100() {
        if (ui->appPreseed_LineED_2->text() == NULL) {
            debug_msg("Please specify an AppPreseed file...", "error");
            ui->btn_open_ap_pr->setStyleSheet("border: 1px solid red");
            ui->label_required_5->setVisible(true);
            phase_state = 100;
        }
        if (ui->preseed_LineED->text() == NULL) {
            debug_msg("Please specify a Preseed file...", "error");
            ui->btn_open_pr->setStyleSheet("border: 1px solid red");
            ui->label_required_5->setVisible(true);
            phase_state = 100;
        }
        if (ui->password_LineED_pr->text() == NULL) {
            debug_msg("Please specify a password...", "error");
            ui->password_LineED_pr->setStyleSheet("border: 1px solid red");
            ui->label_required_5->setVisible(true);
            phase_state = 100;
        }
        if (ui->password_LineED_pr_2->text() == NULL) {
            debug_msg("Please type in your password again...", "error");
            ui->password_LineED_pr_2->setStyleSheet("border: 1px solid red");
            ui->label_required_5->setVisible(true);
            phase_state = 100;
        }
        if (ui->rootpasswd_LineED_pr->text() == NULL) {
            debug_msg("Please specify a root password...", "error");
            ui->rootpasswd_LineED_pr->setStyleSheet("border: 1px solid red");
            ui->label_required_5->setVisible(true);
            phase_state = 100;
        }
        if (ui->rootpasswd_LineED_pr2->text() == NULL) {
            debug_msg("Please type in your root password again...", "error");
            ui->rootpasswd_LineED_pr2->setStyleSheet("border: 1px solid red");
            ui->label_required_5->setVisible(true);
            phase_state = 100;
        }
        if (ui->password_LineED_pr->text() != ui->password_LineED_pr_2->text()) {
            debug_msg("Sorry, the passwords don't match...", "error");
            ui->password_LineED_pr->setStyleSheet("border: 1px solid red");
            ui->password_LineED_pr_2->setStyleSheet("border: 1px solid red");
            ui->label_passwd_nomatch_pr->setVisible(true);
            phase_state = 100;
        }
        if (ui->rootpasswd_LineED_pr->text() != ui->rootpasswd_LineED_pr2->text()) {
            debug_msg("Sorry, the passwords don't match...", "error");
            ui->rootpasswd_LineED_pr->setStyleSheet("border: 1px solid red");
            ui->rootpasswd_LineED_pr2->setStyleSheet("border: 1px solid red");
            ui->label_rtpasswd_nomatch_pr->setVisible(true);
            phase_state = 100;
        }
        if (ui->preseed_LineED->text() != NULL &&
                ui->password_LineED_pr->text() != NULL && ui->password_LineED_pr_2->text() != NULL
                && ui->rootpasswd_LineED_pr->text() != NULL &&
                ui->rootpasswd_LineED_pr2->text() != NULL &&
                ui->appPreseed_LineED_2->text() != NULL &&
                ui->rootpasswd_LineED_pr->text() == ui->rootpasswd_LineED_pr2->text() && ui->password_LineED_pr->text() == ui->password_LineED_pr_2->text()) {
            // If start
            passwd1 = ui->password_LineED_pr->text();
            passwd2 = ui->password_LineED_pr_2->text();
            rootpasswd1 = ui->rootpasswd_LineED_pr->text();
            rootpasswd2 = ui->rootpasswd_LineED_pr2->text();
            appPreseed_path = ui->appPreseed_LineED_2->text();
            preseed_path = ui->preseed_LineED->text();
            debug_msg("All values present! Continuing...", "success");
            phase_state = 102;
            phase(phase_state);
            // If end
        }
    }
    void yalai::loadPreseed() {
        debug_msg("Copying preseed...", "msg");
        exec("cp", QStringList() << preseed_path << "./preseed.conf");
        p->waitForFinished();
        debug_msg("Copying appPreseed...", "msg");
        exec("cp", QStringList() << appPreseed_path << "./appreseed.conf");
        p->waitForFinished();
        debug_msg("Sorting preseed by varriables...", "msg");
        exec("bash", QStringList() << "./scripts/sepPreseed.sh");
        p->waitForFinished();
        // Disk values
            debug_msg("Getting disk varriables...", "msg");
            // Open files
            QFile disk_file("./preseed_values/disk.txt");
            QFile root_file("./preseed_values/root.txt");
            QFile swap_file("./preseed_values/swap.txt");
            QFile efi_file("./preseed_values/efi.txt");
            // Set file open type
            disk_file.open(QIODevice::ReadOnly);
            root_file.open(QIODevice::ReadOnly);
            swap_file.open(QIODevice::ReadOnly);
            efi_file.open(QIODevice::ReadOnly);
            // Read files
            disk = QTextStream(&disk_file).readLine();
            root_part = QTextStream(&root_file).readLine();
            swap_part = QTextStream(&swap_file).readLine();
            efi_part = QTextStream(&efi_file).readLine();
            // Close files
            disk_file.close();
            root_file.close();
            swap_file.close();
            efi_file.close();
        // End of disk values
        // Localization
            debug_msg("Getting localization varriables...", "msg");
            // Open files
            QFile locale_file("./preseed_values/locale.txt");
            QFile keylayout_file("./preseed_values/keylayout.txt");
            QFile timezone_file("./preseed_values/timezone.txt");
            QFile subzone_file("./preseed_values/subzone.txt");
            // Set file open type
            locale_file.open(QIODevice::ReadOnly);
            keylayout_file.open(QIODevice::ReadOnly);
            timezone_file.open(QIODevice::ReadOnly);
            subzone_file.open(QIODevice::ReadOnly);
            // Read files
            lang = QTextStream(&locale_file).readLine();
            keylayout = QTextStream(&keylayout_file).readLine();
            zone = QTextStream(&timezone_file).readLine();
            subzone = QTextStream(&subzone_file).readLine();
            // Close files
            locale_file.close();
            keylayout_file.close();
            timezone_file.close();
            subzone_file.close();
        // End of localization
        // User details
            debug_msg("Getting user details...", "msg");
            // Open files
            QFile username_file("./preseed_values/username.txt");
            QFile hostname_file("./preseed_values/hostname.txt");
            // Set file open type
            username_file.open(QIODevice::ReadOnly);
            hostname_file.open(QIODevice::ReadOnly);
            // Read files
            username = QTextStream(&username_file).readLine();
            hostname = QTextStream(&hostname_file).readLine();
            // Close files
            username_file.close();
            hostname_file.close();
        // End of user details
        // Personalization
            debug_msg("Getting personalization varriables...", "msg");
            // Open files
            QFile shell_file("./preseed_values/shell.txt");
            QFile desktop_file("./preseed_values/desktop.txt");
            QFile dm_file("./preseed_values/dm.txt");
            QFile aursupport_file("./preseed_values/aur_support.txt");
            // Set file open type
            shell_file.open(QIODevice::ReadOnly);
            desktop_file.open(QIODevice::ReadOnly);
            dm_file.open(QIODevice::ReadOnly);
            aursupport_file.open(QIODevice::ReadOnly);
            // Read files
            shell = QTextStream(&shell_file).readLine();
            de = QTextStream(&desktop_file).readLine();
            dm = QTextStream(&dm_file).readLine();
            if (QTextStream(&aursupport_file).readLine() == "true") {
                aursupport = true;
            }
            else {
                aursupport = false;
            }
            // Close files
            shell_file.close();
            desktop_file.close();
            dm_file.close();
            aursupport_file.close();
        // End of personalization
            debug_msg("Finished! Loading summary...", "success");
            phase_state = 9;
            phase(phase_state);
    }
// End of Phase '101'
// Phase 1
    // Configure dropdowns for partitions
    void yalai::dropdownConfig(QString action) {
        int data = 0;
        if (action == "HideAll") {
            ui->label_swap->setVisible(false);
            ui->label_efi->setVisible(false);
            ui->label_root->setVisible(false);
            ui->dropdown_swap->setVisible(false);
            ui->dropdown_efi->setVisible(false);
            ui->dropdown_root->setVisible(false);
        }
        // Show all of the dropdowns
        if (action == "ShowAll") {
            if (isEFI() == "BIOS") {
                ui->label_swap->setVisible(true);
                ui->label_root->setVisible(true);
                ui->dropdown_swap->setVisible(true);
                ui->dropdown_root->setVisible(true);
            }
            else if (isEFI() == "UEFI") {
                ui->label_swap->setVisible(true);
                ui->label_efi->setVisible(true);
                ui->label_root->setVisible(true);
                ui->dropdown_swap->setVisible(true);
                ui->dropdown_efi->setVisible(true);
                ui->dropdown_root->setVisible(true);
            }
        }
        // Show all the dropdowns except EFI boot
        // Initialize all the dropdowns
        if (action == "Initialize") {
            // Clears all content from dropdowns
            ui->dropdown_efi->clear();
            ui->dropdown_root->clear();
            ui->dropdown_swap->clear();
            // Adds "---Select---" to each dropdown
            ui->dropdown_efi->addItem("---Select---", data);
            ui->dropdown_root->addItem("---Select---", data);
            ui->dropdown_swap->addItem("---Select---", data);
        }
        if (action == "Initialize_block") {
            // Clears content from dropdown_block
            ui->dropdown_block->clear();
            // Adds "---Select---" to dropdown_block
            ui->dropdown_block->addItem("---Select---", data);
        }
    }
    // Drive listing
    void yalai::mkdrivelist() {
        dropdownConfig("Initialize");
        int i = 0;
        debug_msg("Listing drives...", "msg");
        exec("bash", QStringList() << "./scripts/mkdrivelist.sh");
        p->waitForFinished();
        QFile inputFile("list.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while (!in.atEnd())
           {
              i = i+1;
              QString line = in.readLine();
              ui->dropdown_block->addItem(line, i);
           }
           inputFile.close();
        }
    }
    // Partition listing
    void yalai::mkpartlist(QString disk) {
        int i = 0;
        dropdownConfig("Initialize");
        debug_msg("Listing partitions...", "msg");
        exec("bash", QStringList() << "./scripts/mkpartlist.sh" << disk);
        p->waitForFinished();
        QFile inputFile("partlist.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while (!in.atEnd())
           {
               i = i+1;
               QString line = in.readLine();
               ui->dropdown_swap->addItem(line, i);
               ui->dropdown_root->addItem(line, i);
               ui->dropdown_efi->addItem(line, i);
           }
           inputFile.close();
        }
        dropdownConfig("ShowAll");
        ui->dropdown_root->setCurrentIndex(root_part_int);
        ui->dropdown_swap->setCurrentIndex(swap_part_int);
        ui->dropdown_efi->setCurrentIndex(efi_part_int);
    }
    // GParted button
    void yalai::on_pushButton_clicked()
    {
        debug_msg("Starting GParted...", "msg");
        exec("gparted", QStringList());
        p->waitForFinished();
        disk_int = 0;
        root_part_int = 0;
        swap_part_int = 0;
        efi_part_int = 0;
        phase(1);
    }
    // Block device dropdown handling
    void yalai::on_dropdown_block_currentIndexChanged(int index)
    {
        int i = 0;
        disk = "";
        //QString teszt = ui->dropdown_block->currentData().toString();
        if (index > 0) {
            QFile inputFile("drives.txt");
            if (inputFile.open(QIODevice::ReadOnly))
            {
               QTextStream in(&inputFile);
               while (!in.atEnd())
               {
                  i = i+1;
                  QString line = in.readLine();
                  if (i == index) {
                    disk = line;
                    disk_int = ui->dropdown_block->currentIndex();
                  }
               }
               inputFile.close();
            }
            debug_msg(QString("Block device (disk): %1").arg(disk), "output");
            mkpartlist(disk);
        }
        else {
            dropdownConfig("HideAll");
            dropdownConfig("Initialize");
        }
    }
    // Root dropdown handling
    void yalai::on_dropdown_root_currentIndexChanged(int index)
    {
        root_part = "";
        int i = 0;
        if (index > 0) {
            QFile inputFile("part.txt");
            if (inputFile.open(QIODevice::ReadOnly))
            {
               QTextStream in(&inputFile);
               while (!in.atEnd())
               {
                  i = i+1;
                  //debug_msg(in.readAll());
                  QString line = in.readLine();
                  if (i == index) {
                    root_part = line;
                    root_part_int = ui->dropdown_root->currentIndex();
                    debug_msg(QString("Root partition: %1").arg(root_part), "output");
                  }
               }
               inputFile.close();
            }
        }
    }
    // Swap dropdown handling
    void yalai::on_dropdown_swap_currentIndexChanged(int index)
    {
        swap_part = "";
        int i = 0;
        if (index > 0) {
            QFile inputFile("part.txt");
            if (inputFile.open(QIODevice::ReadOnly))
            {
               QTextStream in(&inputFile);
               while (!in.atEnd())
               {
                  i = i+1;
                  //debug_msg(in.readAll());
                  QString line = in.readLine();
                  if (i == index) {
                    swap_part = line;
                    swap_part_int = ui->dropdown_swap->currentIndex();
                    debug_msg(QString("Swap partition: %1").arg(swap_part), "output");
                  }
               }
               inputFile.close();
            }
        }
    }
    // EFI dropdown handling
    void yalai::on_dropdown_efi_currentIndexChanged(int index)
    {
        efi_part = "";
        int i = 0;
        if (index > 0) {
            QFile inputFile("part.txt");
            if (inputFile.open(QIODevice::ReadOnly))
            {
               QTextStream in(&inputFile);
               while (!in.atEnd())
               {
                  i = i+1;
                  //debug_msg(in.readAll());
                  QString line = in.readLine();
                  if (i == index) {
                    efi_part = line;
                    efi_part_int = ui->dropdown_efi->currentIndex();
                    debug_msg(QString("EFI boot partition: %1").arg(efi_part), "output");
                  }
               }
               inputFile.close();
            }
        }
    }
// End of Phase 1
// Phase 2
    void yalai::verify_phase1() {
        // BootMode handling
        if (disk == NULL) {
            debug_msg("Please specify a block device...", "error");
            ui->dropdown_block->setStyleSheet("border: 1px solid red");
            ui->label_required->setVisible(true);
            phase_state = 1;
        }
        if (isEFI() == "UEFI") {
            if (root_part == NULL && disk != NULL) {
                debug_msg("Please specify a Root partition...", "error");
                phase_state = 1;
                ui->label_required->setVisible(true);
                ui->dropdown_root->setStyleSheet("border: 1px solid red");
            }
            if (swap_part == NULL && disk != NULL) {
                debug_msg("Please specify a Swap partition...", "error");
                ui->dropdown_swap->setStyleSheet("border: 1px solid red");
                ui->label_required->setVisible(true);
                phase_state = 1;
            }
            if (efi_part == NULL && disk != NULL) {
                debug_msg("Please specify an EFI partition...", "error");
                ui->dropdown_efi->setStyleSheet("border: 1px solid red");
                ui->label_required->setVisible(true);
                phase_state = 1;
            }
            if (root_part != NULL && swap_part != NULL && efi_part != NULL) {
                debug_msg("All values present! Continuing...", "success");
                QMessageBox partMsg;
                partMsg.setWindowTitle(this->windowTitle());
                partMsg.setText(QString("Root partition: %1\nSwap partition: %2\nEFI boot partition: %3\n\nWould you like to continue?").arg(root_part, swap_part, efi_part));
                partMsg.setStandardButtons(QMessageBox::Yes);
                partMsg.addButton(QMessageBox::No);
                if (partMsg.exec() == QMessageBox::Yes) {
                    phase(3);
                    phase_state = 3;
                }
                else {
                    phase_state = 1;
                }
                //QMessageBox::warning(this, this->windowTitle(),);
            }
        }
        else if (isEFI() == "BIOS") {
            if (root_part == NULL && disk != NULL) {
                debug_msg("Please specifiy a Root partition...", "error");
                ui->dropdown_root->setStyleSheet("border: 1px solid red");
                ui->label_required->setVisible(true);
                phase_state = 1;
            }
            if (swap_part == NULL && disk != NULL) {
                debug_msg("Please specify a Swap partition...", "error");
                ui->dropdown_swap->setStyleSheet("border: 1px solid red");
                ui->label_required->setVisible(true);
                phase_state = 1;
            }
            if (root_part != NULL && swap_part != NULL) {
                debug_msg("All values present! Continuing...", "success");
                QMessageBox partMsg;
                partMsg.setWindowTitle(this->windowTitle());
                partMsg.setText(QString("Root partition: %1\nSwap partition: %2\n\nWould you like to continue?").arg(root_part, swap_part));
                partMsg.setStandardButtons(QMessageBox::Yes);
                partMsg.addButton(QMessageBox::No);
                if (partMsg.exec() == QMessageBox::Yes) {
                    phase(3);
                    phase_state = 3;
                }
                else {
                    phase_state = 1;
                }
                //QMessageBox::warning(this, this->windowTitle(),);
            }
        }
     }
// End of Phase 2
// Phase 3
    // Language listing
    void yalai::mklanglist() {
        debug_msg("Getting languages...", "msg");
        exec("bash", QStringList() << "./scripts/mklanglist.sh");
        p->waitForFinished();
        ui->dropdown_language->clear();
        ui->dropdown_language->addItem("---Select---");
        QFile inputFile("locales.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while (!in.atEnd())
           {
              QString line = in.readLine();
              ui->dropdown_language->addItem(line);
           }
           ui->dropdown_language->setCurrentText(lang);
           inputFile.close();
        }
    }
    // Keyboard layout listing
    void yalai::mkkeymaplist() {
        debug_msg("Getting keymaps...", "msg");
        exec("bash", QStringList() << "./scripts/mkkeymaplist.sh");
        p->waitForFinished();
        ui->dropdown_keylayout->clear();
        ui->dropdown_keylayout->addItem("---Select---");
        QFile inputFile("keymaps.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while (!in.atEnd())
           {
              QString line = in.readLine();
              ui->dropdown_keylayout->addItem(line);
           }
           inputFile.close();
        }
    }
    // Timezone listing
    void yalai::mkzonelist() {
        debug_msg("Getting timezones...", "msg");
        exec("bash", QStringList() << "./scripts/mkzonelist.sh");
        p->waitForFinished();
        ui->dropdown_timezone->clear();
        ui->dropdown_timezone->addItem("---Select---");
        QFile inputFile("zonelist.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while (!in.atEnd())
           {
              QString line = in.readLine();
              ui->dropdown_timezone->addItem(line);
           }
           inputFile.close();
        }
    }
    // Subzone listing
    void yalai::mksubzonelist(QString zone) {
        if (zone != "null") {
            debug_msg("Getting subzones...", "msg");
            exec("bash", QStringList() << "./scripts/mksubzonelist.sh" << zone);
            p->waitForFinished();
            ui->dropdown_subzone->clear();
            ui->dropdown_subzone->addItem("---Select---");
            QFile inputFile("subzonelist.txt");
            if (inputFile.open(QIODevice::ReadOnly))
            {
               QTextStream in(&inputFile);
               while (!in.atEnd())
               {
                  QString line = in.readLine();
                  ui->dropdown_subzone->addItem(line);
               }
               inputFile.close();
            }
        }
    }
    // Language dropdown handling
    void yalai::on_dropdown_language_currentTextChanged(const QString &arg1)
    {
        if (ui->dropdown_language->currentIndex() != 0) {
            lang=arg1;
            debug_msg(QString("Language: %1").arg(lang), "output");
        }
    }
    // Keyboard layout dropdown handling
    void yalai::on_dropdown_keylayout_currentTextChanged(const QString &arg1)
    {
        if (ui->dropdown_keylayout->currentIndex() != 0) {
            keylayout=arg1;
            debug_msg(QString("Keyboard layout: %1").arg(keylayout), "output");
        }
    }
    // Timezone (zone) dropdown handling
    void yalai::on_dropdown_timezone_currentTextChanged(const QString &arg1)
    {
            if (ui->dropdown_timezone->currentIndex() == 0) {
                ui->dropdown_subzone->setVisible(false);
                ui->label_subzone->setVisible(false);
            }
            //debug_msg(QString::number(ui->dropdown_timezone->currentIndex()));
            if (ui->dropdown_timezone->currentIndex() != 0) {
                if (zone != arg1) {
                    zone=arg1;
                    locale_has_run = false;
                }
                debug_msg(QString("Timezone: %1").arg(zone), "output");
                if (locale_has_run == false) {
                    mksubzonelist(zone);
                    ui->dropdown_subzone->setVisible(true);
                    ui->label_subzone->setVisible(true);
                    locale_has_run = true;
                }
                else {
                    ui->dropdown_subzone->setVisible(true);
                    ui->label_subzone->setVisible(true);
                }
            }
    }
    // Subzone dropdown handling
    void yalai::on_dropdown_subzone_currentTextChanged(const QString &arg1)
    {
        if (ui->dropdown_subzone->currentIndex() != 0) {
            subzone = arg1;
            debug_msg(QString("Subzone: %1").arg(subzone), "output");
        }
    }
// End of Phase 3
// Phase 4
    void yalai::verify_phase3() {
        if (lang == NULL) {
            debug_msg("Please specify your language...", "error");
            ui->dropdown_language->setStyleSheet("border: 1px solid red");
            ui->label_required_2->setVisible(true);
            phase_state = 3;
        }
        if (keylayout == NULL) {
            debug_msg("Please specify your keyboard layout...", "error");
            ui->dropdown_keylayout->setStyleSheet("border: 1px solid red");
            ui->label_required_2->setVisible(true);
            phase_state = 3;
        }
        if (zone == NULL) {
            debug_msg("Please specify your timezone...", "error");
            ui->dropdown_timezone->setStyleSheet("border: 1px solid red");
            ui->label_required_2->setVisible(true);
            phase_state = 3;
        }
        if (subzone == NULL) {
            debug_msg("Please specify your subzone...", "error");
            ui->dropdown_subzone->setStyleSheet("border: 1px solid red");
            ui->label_required_2->setVisible(true);
            phase_state = 3;
        }
        if (lang != NULL && keylayout != NULL && zone != NULL && subzone != NULL) {
            debug_msg("All values present! Continuing...", "success");
            phase_state = 5;
            phase(phase_state);
        }
    }
// End of Phase 4
// Phase 5
    void yalai::inputConfig() {
        // Username_LineED
        ui->username_LineED->setStyleSheet("border: 1px solid #5090DC");
        // password_LineED_1
        ui->password_LineED_1->setStyleSheet("border: 1px solid #5090DC");
        // password_LineED_2
        ui->password_LineED_2->setStyleSheet("border: 1px solid #5090DC");
        // rootpasswd_LineED_1
        ui->rootpasswd_LineED_1->setStyleSheet("border: 1px solid #5090DC");
        // rootpasswd_LineED_2
        ui->rootpasswd_LineED_2->setStyleSheet("border: 1px solid #5090DC");
        // Hostname_LineED
        ui->hostname_LineED->setStyleSheet("border: 1px solid #5090DC");
    }
// End of phase 5
// Phase 6
    void yalai::verify_phase5() {
        if (ui->username_LineED->text() == NULL) {
            ui->username_LineED->setStyleSheet("border: 1px solid red");
            ui->label_required_3->setVisible(true);
            debug_msg("Please specify your username...", "error");
            phase_state = 5;
        }
        if (ui->password_LineED_1->text() == NULL) {
            ui->password_LineED_1->setStyleSheet("border: 1px solid red");
            ui->label_required_3->setVisible(true);
            debug_msg("Please specify your password...", "error");
            phase_state = 5;
        }
       if (ui->password_LineED_2->text() == NULL) {
            ui->password_LineED_2->setStyleSheet("border: 1px solid red");
            ui->label_required_3->setVisible(true);
            debug_msg("Please type in your password again...", "error");
            phase_state = 5;
        }
        if (ui->rootpasswd_LineED_1->text() == NULL) {
            ui->rootpasswd_LineED_1->setStyleSheet("border: 1px solid red");
            ui->label_required_3->setVisible(true);
            debug_msg("Please specify your root password...", "error");
            phase_state = 5;
        }
        if (ui->rootpasswd_LineED_2->text() == NULL) {
            ui->rootpasswd_LineED_2->setStyleSheet("border: 1px solid red");
            ui->label_required_3->setVisible(true);
            debug_msg("Please type in your root password again...", "error");
            phase_state = 5;
        }
        if (ui->hostname_LineED->text() == NULL) {
            ui->hostname_LineED->setStyleSheet("border: 1px solid red");
            ui->label_required_3->setVisible(true);
            debug_msg("Please specify your hostname...", "error");
            phase_state = 5;
        }
        if (ui->password_LineED_1->text() != ui->password_LineED_2->text()) {
            ui->password_LineED_1->setStyleSheet("border: 1px solid red");
            ui->password_LineED_2->setStyleSheet("border: 1px solid red");
            ui->label_passwd_nomatch->setVisible(true);
            debug_msg("Sorry, the passwords don't match", "error");
            phase_state = 5;

        }
        if (ui->rootpasswd_LineED_1->text() != ui->rootpasswd_LineED_2->text()) {
            ui->rootpasswd_LineED_1->setStyleSheet("border: 1px solid red");
            ui->rootpasswd_LineED_2->setStyleSheet("border: 1px solid red");
            ui->label_rtpasswd_nomatch->setVisible(true);
            debug_msg("Sorry, the root passwords don't match", "error");
            phase_state = 5;

        }
        if (ui->username_LineED->text() != NULL &&
                ui->password_LineED_1->text() != NULL && ui->password_LineED_2->text() != NULL
                && ui->rootpasswd_LineED_1->text() != NULL &&
                ui->rootpasswd_LineED_2->text() != NULL &&
                ui->hostname_LineED->text() != NULL &&
                ui->rootpasswd_LineED_1->text() == ui->rootpasswd_LineED_2->text() && ui->password_LineED_1->text() == ui->password_LineED_2->text()) {
            // If start
            username = ui->username_LineED->text();
            passwd1 = ui->password_LineED_1->text();
            passwd2 = ui->password_LineED_2->text();
            rootpasswd1 = ui->rootpasswd_LineED_1->text();
            rootpasswd2 = ui->rootpasswd_LineED_2->text();
            hostname = ui->hostname_LineED->text();
            debug_msg("All values present! Continuing...", "success");
            phase_state = 7;
            phase(phase_state);
            // If end
        }
    }
// End of Phase 6
// Phase 7
    // DE dropdown
    void yalai::on_dropdown_de_currentTextChanged(const QString &arg1)
    {
            de = arg1;
    }
    // DM Dropdown
    void yalai::on_dropdown_dm_currentTextChanged(const QString &arg1)
    {
            dm = arg1;
    }
    // Shell dropdown
    void yalai::on_dropdown_shell_currentTextChanged(const QString &arg1)
    {
            shell = arg1;
    }
    // AppPreseed button
    void yalai::on_btn_open_ap_clicked()
    {
        QString file = NULL;
        file =  (QFileDialog::getOpenFileName(this, tr("YaLAI - Open AppPreseed"), "./"));
        if (file != NULL) {
            ui->appPreseed_LineED->setText(file);
            appPreseed_path = file;
        }
    }
    // AUR support checkbox
    void yalai::on_checkBox_aursupport_stateChanged(int arg1)
    {
        switch (arg1) {
            case 2:
            aursupport = true;
            break;
            case 0:
            aursupport = false;
            break;
        }

    }
// End of Phase 7
// Phase 8 (Phase 7: Verifier)
    void yalai::verify_phase7() {
        if (de == NULL || de == "---Select---") {
            debug_msg("Please select a desktop environment...", "error");
            ui->dropdown_de->setStyleSheet("border: 1px solid red");
            phase_state = 7;
            ui->label_required_4->setVisible(true);
        }
        if (dm == NULL || dm == "---Select---") {
            debug_msg("Please select a display manager...", "error");
            ui->dropdown_dm->setStyleSheet("border: 1px solid red");
            phase_state = 7;
            ui->label_required_4->setVisible(true);
        }
        if (shell == NULL || shell == "---Select---") {
            debug_msg("Please select a shell...", "error");
            ui->dropdown_shell->setStyleSheet("border: 1px solid red");
            phase_state = 7;
            ui->label_required_4->setVisible(true);
        }
        if (de != NULL && de != "---Select---" && dm != NULL && dm != "---Select---" && shell != NULL && shell != "---Select---" ) {
            debug_msg("All values present! Continuing...", "success");
            debug_msg("Copying appPreseed...", "msg");
            appPreseed_path = ui->appPreseed_LineED->text();
            exec("cp", QStringList() << appPreseed_path << "./appreseed.conf");
            p->waitForFinished();
            phase_state = 9;
            phase(phase_state);
        }
    }
// End of Phase 8
// Phase 9
    void yalai::on_savePreseed_btn_clicked()
    {
        QString filename = QFileDialog().getSaveFileName(this, "Save file", "", ".conf");
        debug_msg(QString("Saving preseed as: %1").arg(filename), "msg");
        QFile file(filename);
        if (filename != NULL && file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream preseedStream(&file);
            preseedStream << QString("# Preseed file for the YaLAI installer.") << endl;
            preseedStream << QString("# Generated by YaLAI on %1").arg(QDateTime::currentDateTime().toString()) << endl;
            preseedStream << QString("disk=%1").arg(disk) << endl;
            preseedStream << QString("root_partition=%1").arg(root_part) << endl;
            preseedStream << QString("swap_partition=%1").arg(swap_part) << endl;
            preseedStream << QString("efi_partition=%1").arg(efi_part) << endl;
            preseedStream << QString("locale=%1").arg(lang) << endl;
            preseedStream << QString("keylayout=%1").arg(keylayout) << endl;
            preseedStream << QString("tzone=%1").arg(zone) << endl;
            preseedStream << QString("subzone=%1").arg(subzone) << endl;
            preseedStream << QString("hostname=%1").arg(hostname) << endl;
            preseedStream << QString("username=%1").arg(username) << endl;
            preseedStream << QString("shell=%1").arg(shell) << endl;
            preseedStream << QString("desktop=%1").arg(de) << endl;
            preseedStream << QString("display_manager=%1").arg(dm) << endl;
            if (aursupport == true) {
                preseedStream << QString("aur_support=true") << endl;
            }
            else {
                preseedStream << QString("aur_support=false") << endl;
            }
            preseedStream << QString("# --- End of preseed ---") << endl;
        }
        file.close();
    }
// End of phase 9
// Install
    void yalai::install() {
        QString filename;
        filename = ".installVars.conf";
        QFile file(filename);
        if (filename != NULL && file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream preseedStream(&file);
            preseedStream << QString("# Varriables for installation.") << endl;
            preseedStream << QString("# Generated by YaLAI on %1").arg(QDateTime::currentDateTime().toString()) << endl;
            preseedStream << QString("# DO NOT EDIT!") << endl;
            preseedStream << QString("disk=%1").arg(disk) << endl;
            preseedStream << QString("root=%1").arg(root_part) << endl;
            preseedStream << QString("swap=%1").arg(swap_part) << endl;
            preseedStream << QString("efi=%1").arg(efi_part) << endl;
            preseedStream << QString("lang=%1").arg(lang) << endl;
            preseedStream << QString("key=%1").arg(keylayout) << endl;
            preseedStream << QString("tzone=%1").arg(zone) << endl;
            preseedStream << QString("szone=%1").arg(subzone) << endl;
            preseedStream << QString("hname=%1").arg(hostname) << endl;
            preseedStream << QString("uname=%1").arg(username) << endl;
            preseedStream << QString("shell=%1").arg(shell) << endl;
            preseedStream << QString("de=%1").arg(de) << endl;
            preseedStream << QString("dm=%1").arg(dm) << endl;
            preseedStream << QString("passwd1=%1").arg(passwd1) << endl;
            preseedStream << QString("passwd2=%1").arg(passwd2) << endl;
            preseedStream << QString("rtpass1=%1").arg(rootpasswd1) << endl;
            preseedStream << QString("rtpass2=%1").arg(rootpasswd2) << endl;

            if (aursupport == true) {
                preseedStream << QString("asup=true") << endl;
            }
            else {
                preseedStream << QString("asup=false") << endl;
            }
            preseedStream << QString("# --- End of file ---") << endl;
        }
        file.close();
        captureProgress = true;
        exec("bash", QStringList() << "./scripts/installer.sh");

    }
// Progress changed
    void yalai::progressChanged() {
        if (captureProgress == true) {
            QFile progressFile("./progress.txt");
            progressFile.open(QIODevice::ReadOnly);
            QString progress = QTextStream(&progressFile).readLine();
            progressFile.close();
            debug_msg(QString("Progress changed! (%1)").arg(progress), "success");
            ui->install_indicator_ph->setText(progress);
            if (progress == "# Install finished! ") {
                captureProgress = false;
                installFinished();
            }
        }
    }
// Install finished
    void yalai::installFinished() {
        debug_msg("Install finished!", "success");
        QMessageBox msgBox;
        msgBox.setText("Install finished! What would you like to do now?");
        msgBox.setWindowTitle("YaLAI - Install finished");
        QAbstractButton* pButtonYes = msgBox.addButton(tr("Reboot"), QMessageBox::YesRole);
        msgBox.addButton(tr("Quit"), QMessageBox::NoRole);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        if (msgBox.clickedButton()==pButtonYes) {
            exec("reboot", QStringList());
        }
        else {
            close();
        }
    }
// Console messages
void yalai::debug_msg(QString msg, QString type) {
    if (type == "success") {
        ui->TextOut->appendHtml("<p style=\"color:lime;white-space:pre\">" + msg + "</p>");
    }
    if (type == "error") {
        ui->TextOut->appendHtml("<p style=\"color:red;white-space:pre\">" + msg + "</p>");
    }
    if (type == "msg") {
        ui->TextOut->appendHtml("<p style=\"color:cyan;white-space:pre\">" + msg + "</p>");
    }
    if (type == "output") {
        if(msg != NULL && msg != "\n" && msg != " " && msg != "") {
            ui->TextOut->appendPlainText(msg.trimmed());
        }
    }
    if (type == "phase") {
        ui->TextOut->appendHtml("<p style=\"color:orange;white-space:pre\">" + msg + "</p>");
    }
    qDebug() << QString("debug_msg - Type: %1, Message: %2").arg(type, msg);
}
// BootMode handling (BIOS/UEFI)
QString yalai::isEFI() {
    exec("bash", QStringList() << "./scripts/IsEFI.sh");
    p->waitForFinished();
    QFile inputFile("IsEFI.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString out = in.readLine();
    debug_msg(QString("BootMode: %1").arg(out), "output");
    if (out == "UEFI") {
        return "UEFI";
    }
    else {
        return "BIOS";
    }
}