#include "controller.h"
#include "user.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    m_user = new User();
    m_login = new Login();
    m_signUp = new SignUp();
    m_Info = new Info();
    m_mainWindow = new MainWindow();

    connect(m_mainWindow, &MainWindow::mainWindowLogin, this, &Controller::onLogin);
    connect(m_mainWindow, &MainWindow::mainWindowSignUp, this, &Controller::onSignUp);
    connect(m_mainWindow, &MainWindow::mainWindowInfo, this, &Controller::onInfo);

    connect(m_login, &Login::loginMainWindow, this, &Controller::onMainWindow);
    connect(m_login, &Login::sendData, this, &Controller::onLoginData);

    connect(m_signUp, &SignUp::signUpMainWindow, this, &Controller::onMainWindow);
    connect(m_signUp, &SignUp::sendData, this, &Controller::onSignUpData);

    connect(m_Info, &Info::InfoMainWindow, this, &Controller::onMainWindow);
}

void Controller::start()
{
    m_mainWindow->show();
}

void Controller::onLogin()
{
    m_mainWindow->hide();
    m_login->show();
}

void Controller::onSignUp()
{
    m_mainWindow->hide();
    m_signUp->show();
}

void Controller::onInfo()
{
    m_mainWindow->hide();
    m_Info->show();

    emit m_Info->setLabel(m_user);
}

void Controller::onMainWindow()
{
    m_mainWindow->show();
}

void Controller::onSignUpData(const QString &t_name, const QString &t_surname)
{
    m_user->name = t_name;
    m_user->surname = t_surname;

    emit m_signUp->signUpCheck(m_user->name, m_user->surname);
}

void Controller::onLoginData()
{
    emit m_login->loginCheck(m_user->name, m_user->surname);
}
