#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initializeUI();

    replacer = new Replacer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeUI()
{
    setWindowTitle("ClipboardReplacer  --- Dev. by BIT_TYX");
    setFixedSize(520, 200);

    beforeLabel = new QLabel(this);
    beforeLabel ->setGeometry(50, 30, 100, 40);
    beforeLabel ->setFont(QFont("Timers", 18, QFont::Bold));
    beforeLabel ->setAlignment(Qt::AlignRight);
    beforeLabel ->setText("before");

    afterLabel = new QLabel(this);
    afterLabel ->setGeometry(270, 30, 100, 40);
    afterLabel ->setFont(QFont("Timers", 18, QFont::Bold));
    afterLabel ->setAlignment(Qt::AlignRight);
    afterLabel ->setText("after");

    beforeEdit = new QLineEdit(this);
    beforeEdit ->setGeometry(150, 30, 100, 40);
    beforeEdit ->setFont(QFont("Timers", 18, QFont::Bold));
    beforeEdit ->setAlignment(Qt::AlignCenter);
    beforeEdit ->setText("\\");

    afterEdit = new QLineEdit(this);
    afterEdit ->setGeometry(370, 30, 100, 40);
    afterEdit ->setFont(QFont("Timers", 18, QFont::Bold));
    afterEdit ->setAlignment(Qt::AlignCenter);
    afterEdit ->setText("/");

    deleteEnterBox = new QCheckBox(this);
    deleteEnterBox ->setGeometry(75, 75, 250, 40);
    deleteEnterBox ->setFont(QFont("Timers", 15, QFont::Bold));
    deleteEnterBox ->setText("Delete Enter?");

    startButton = new QPushButton(this);
    startButton ->setGeometry(85, 120, 150, 50);
    startButton ->setFont(QFont("Timers", 20, QFont::Bold));
    startButton ->setText("Start");
    QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(start()));

    stopButton = new QPushButton(this);
    stopButton ->setGeometry(275, 120, 150, 50);
    stopButton ->setFont(QFont("Timers", 20, QFont::Bold));
    stopButton ->setText("Stop");
    QObject::connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));
}

void MainWindow::start()
{
    replacer ->startListening(beforeEdit ->text(), afterEdit ->text(), deleteEnterBox ->isChecked());
}

void MainWindow::stop()
{
    replacer ->stopListening();
}
