#include "info.h"

Info::Info(QWidget *parent)
    : QMainWindow{parent}
{
    this->resize(QSize(300, 200));
    this->setWindowTitle("Info View");

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    m_InfoHeader = new QLabel();
    m_InfoHeader->setAlignment(Qt::AlignCenter);

    m_mainWindowButton = new QPushButton("Main Window");

    m_vLayout = new QVBoxLayout();
    m_vLayout->addWidget(m_InfoHeader);
    m_vLayout->addWidget(m_mainWindowButton);
    centralWidget->setLayout(m_vLayout);

    connect(m_mainWindowButton, &QPushButton::clicked, this, &Info::onMainWindowButton);
    connect(this, &Info::setLabel, this, &Info::onSetLabel);
}

void Info::onMainWindowButton()
{
    this->hide();
    m_InfoHeader->setText("No data has been recorded.");

    emit InfoMainWindow();
}

void Info::onSetLabel(User *t_user)
{
    if ((t_user->name == "") && (t_user->surname == "")) {
        m_InfoHeader->setText("No data has been recorded.");
    } else {
        m_InfoHeader->setText(t_user->name + " " + t_user->surname);
    }
}
