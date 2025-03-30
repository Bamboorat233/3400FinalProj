// main.cpp
#include <QApplication>

#include "../HospitalSystem/header/HospitalSystem.h"
#include "header/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建一个 HospitalSystem 对象（你的 Controller）
    HospitalSystem hospitalSystem;

    // 创建并显示主窗口
    MainWindow mainWindow(&hospitalSystem);  // 将指针传递给主窗口

    mainWindow.show();

    // 运行事件循环
    return app.exec();
}
