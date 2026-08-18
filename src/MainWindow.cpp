#include "MainWindow.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("AkyMonitor");
    resize(900, 600);

    QWidget *central = new QWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(central);

    QLabel *title = new QLabel("AkyMonitor System Monitor", central);
    QLabel *status = new QLabel("Initializing...", central);

    title->setStyleSheet(
        "font-size: 28px;"
        "font-weight: bold;"
    );

    status->setStyleSheet(
        "font-size: 18px;"
    );

    layout->addWidget(title);
    layout->addWidget(status);

    setCentralWidget(central);
}