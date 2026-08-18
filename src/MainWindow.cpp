#include "MainWindow.h"
#include "CpuMonitor.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("AkyMonitor");
    resize(900, 600);


    QWidget *central = new QWidget(this);

    QVBoxLayout *layout =
        new QVBoxLayout(central);


    QLabel *title =
        new QLabel(
            "AkyMonitor System Monitor",
            central
        );


    QLabel *cpuLabel =
        new QLabel(
            "CPU Loading...",
            central
        );


    title->setStyleSheet(
        "font-size:28px;"
        "font-weight:bold;"
    );


    cpuLabel->setStyleSheet(
        "font-size:20px;"
    );


    layout->addWidget(title);
    layout->addWidget(cpuLabel);


    setCentralWidget(central);



    CpuMonitor *cpu =
        new CpuMonitor();


    QTimer *timer =
        new QTimer(this);


    connect(
        timer,
        &QTimer::timeout,
        this,
        [cpu, cpuLabel]()
        {
            double usage =
                cpu->getUsage();

            cpuLabel->setText(
                QString(
                "CPU Usage: %1%"
                )
                .arg(
                    usage,
                    0,
                    'f',
                    1
                )
            );
        }
    );


    timer->start(1000);
}