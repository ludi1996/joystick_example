#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joy_thread.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void display_slot_row(joyinfoex_tag state_row);

private:
    void clearDisplay();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
