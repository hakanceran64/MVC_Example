#pragma once

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    QLabel *m_infoLabel;
    QPushButton *m_login;
    QPushButton *m_signUp;
    QPushButton *m_Info;
    QHBoxLayout *m_hLayout;
    QVBoxLayout *m_vLayout;

signals:
    void mainWindowLogin();
    void mainWindowSignUp();
    void mainWindowInfo();

public slots:
    void onLoginButton();
    void onSignUpButton();
    void onInfoButton();
};
