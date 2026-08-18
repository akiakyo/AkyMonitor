#pragma once

#include <QMainWindow>

class QLabel;
class QProgressBar;


class MainWindow : public QMainWindow
{

public:

    explicit MainWindow(QWidget *parent = nullptr);


private:

    QLabel *cpuValue;
    QLabel *memoryValue;

    QProgressBar *cpuBar;
    QProgressBar *memoryBar;

};