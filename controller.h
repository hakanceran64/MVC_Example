#pragma once

#include <QObject>

#include "info.h"       // View
#include "login.h"      // View
#include "mainwindow.h" // View
#include "signup.h"     // View
#include "user.h"       // Model

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller() = default;

    void start();

private:
    User *m_user;
    Login *m_login;
    SignUp *m_signUp;
    Info *m_Info;
    MainWindow *m_mainWindow;

private slots:
    void onLogin();
    void onSignUp();
    void onInfo();
    void onMainWindow();
    void onSignUpData(const QString &t_name, const QString &t_surname);
    void onLoginData();
};
