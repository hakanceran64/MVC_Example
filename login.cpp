#include "login.h"

Login::Login(QWidget *parent)
    : QMainWindow{parent}
{
    this->resize(QSize(300, 200));
    this->setWindowTitle("Login View");

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    m_nameLineEdit = new QLineEdit();
    m_nameLineEdit->setPlaceholderText("Name:");

    m_surnameLineEdit = new QLineEdit();
    m_surnameLineEdit->setPlaceholderText("Surname:");

    m_loginInfoLabel = new QLabel();
    m_loginInfoLabel->setAlignment(Qt::AlignCenter);
    m_loginInfoLabel->setText("Please fill in your information.");

    m_sendButton = new QPushButton("Send");

    m_mainWindowButton = new QPushButton("Main Window");

    m_hLayout = new QHBoxLayout();
    m_hLayout->addWidget(m_nameLineEdit);
    m_hLayout->addWidget(m_surnameLineEdit);

    m_vLayout = new QVBoxLayout();
    m_vLayout->addLayout(m_hLayout);
    m_vLayout->addWidget(m_loginInfoLabel);
    m_vLayout->addWidget(m_sendButton);
    m_vLayout->addWidget(m_mainWindowButton);
    centralWidget->setLayout(m_vLayout);

    connect(m_mainWindowButton, &QPushButton::clicked, this, &Login::onMainWindowButton);
    connect(m_sendButton, &QPushButton::clicked, this, &Login::onSendButton);
    connect(this, &Login::loginCheck, this, &Login::onLoginCheck);
}

void Login::onMainWindowButton()
{
    this->hide();
    m_loginInfoLabel->setText("Please fill in your information.");
    m_nameLineEdit->setText("");
    m_surnameLineEdit->setText("");

    emit loginMainWindow();
}

void Login::onSendButton()
{
    if ((m_nameLineEdit->text() == "") || (m_surnameLineEdit->text() == "")) {
        m_loginInfoLabel->setText("Name or surname cannot be empty.");
    } else {
        m_name = m_nameLineEdit->text();
        m_surname = m_surnameLineEdit->text();

        emit sendData();
    }
}

void Login::onLoginCheck(const QString &t_name, const QString &t_surname)
{
    if ((t_name == m_name) && (t_surname == m_surname)) {
        m_loginInfoLabel->setText("Login successful.");
    } else {
        m_loginInfoLabel->setText("Login failed.");
    }
}
