#include "yalai.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Application object
    QApplication app(argc, argv);
    // Object for the YaLAI class
    yalai yalai_obj;
    yalai_obj.show();
    // Progress.txt - QFileSystemWatcher
    yalai_obj.debug_msg("# Starting QFileSystemWatcher...", "msg");
    system("touch ./progress.txt");
    QFileSystemWatcher progressWatcher;
    progressWatcher.addPath(QString("%1/progress.txt").arg(QDir::currentPath()));
    QObject::connect( &progressWatcher, &QFileSystemWatcher::fileChanged, &yalai_obj, &yalai::progressChanged);
    // End
    return app.exec();
}