#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include "replacer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initializeUI();

private:
    Ui::MainWindow *ui;

    QLabel *beforeLabel;
    QLabel *afterLabel;
    QLineEdit *beforeEdit;
    QLineEdit *afterEdit;
    QCheckBox *deleteEnterBox;
    QPushButton *startButton;
    QPushButton *stopButton;

    Replacer *replacer;

private slots:
    void start();
    void stop();
};
#endif // MAINWINDOW_H
