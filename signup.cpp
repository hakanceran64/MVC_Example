#include "signup.h"

SignUp::SignUp(QWidget *parent)
    : QMainWindow{parent}
{
    this->resize(QSize(300, 200));
    this->setWindowTitle("Sign Up View");

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    m_nameLineEdit = new QLineEdit();
    m_nameLineEdit->setPlaceholderText("Name:");

    m_surnameLineEdit = new QLineEdit();
    m_surnameLineEdit->setPlaceholderText("Surname:");

    m_signUpInfoLabel = new QLabel();
    m_signUpInfoLabel->setAlignment(Qt::AlignCenter);
    m_signUpInfoLabel->setText("Please fill in your information.");

    m_sendButton = new QPushButton("Send");

    m_mainWindowButton = new QPushButton("Main Window");

    m_hLayout = new QHBoxLayout();
    m_hLayout->addWidget(m_nameLineEdit);
    m_hLayout->addWidget(m_surnameLineEdit);

    m_vLayout = new QVBoxLayout();
    m_vLayout->addLayout(m_hLayout);
    m_vLayout->addWidget(m_signUpInfoLabel);
    m_vLayout->addWidget(m_sendButton);
    m_vLayout->addWidget(m_mainWindowButton);
    centralWidget->setLayout(m_vLayout);

    connect(m_mainWindowButton, &QPushButton::clicked, this, &SignUp::onMainWindowButton);
    connect(m_sendButton, &QPushButton::clicked, this, &SignUp::onSendButton);
    connect(this, &SignUp::signUpCheck, this, &SignUp::onSignUpCheck);
}

void SignUp::onMainWindowButton()
{
    this->hide();
    m_signUpInfoLabel->setText("Please fill in your information.");
    m_nameLineEdit->setText("");
    m_surnameLineEdit->setText("");

    emit signUpMainWindow();
}

void SignUp::onSendButton()
{
    if ((m_nameLineEdit->text() == "") || (m_surnameLineEdit->text() == "")) {
        m_signUpInfoLabel->setText("Name or surname cannot be empty.");
    } else {
        m_name = m_nameLineEdit->text();
        m_surname = m_surnameLineEdit->text();

        emit sendData(m_name, m_surname);
    }
}

void SignUp::onSignUpCheck(const QString &t_name, const QString &t_surname)
{
    if ((t_name == m_name) && (t_surname == m_surname)) {
        m_signUpInfoLabel->setText("Registration Successful.");
    } else {
        m_signUpInfoLabel->setText("Registration failed.");
    }
}
