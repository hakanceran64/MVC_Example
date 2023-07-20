#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(QSize(300, 200));
    this->setWindowTitle("Main Window View");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    m_login = new QPushButton("Login");
    m_signUp = new QPushButton("Sign Up");

    m_infoLabel = new QLabel();
    m_infoLabel->setText("Welcome!");
    m_infoLabel->setAlignment(Qt::AlignCenter);

    m_Info = new QPushButton("Info");

    m_hLayout = new QHBoxLayout;
    m_hLayout->addWidget(m_login);
    m_hLayout->addWidget(m_signUp);

    m_vLayout = new QVBoxLayout;
    m_vLayout->addLayout(m_hLayout);
    m_vLayout->addWidget(m_infoLabel);
    m_vLayout->addWidget(m_Info);
    centralWidget->setLayout(m_vLayout);

    connect(m_login, &QPushButton::clicked, this, &MainWindow::onLoginButton);
    connect(m_signUp, &QPushButton::clicked, this, &MainWindow::onSignUpButton);
    connect(m_Info, &QPushButton::clicked, this, &MainWindow::onInfoButton);
}

void MainWindow::onLoginButton()
{
    emit mainWindowLogin();
}

void MainWindow::onSignUpButton()
{
    emit mainWindowSignUp();
}

void MainWindow::onInfoButton()
{
    emit mainWindowInfo();
}
