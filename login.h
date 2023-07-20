#pragma once

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

class Login : public QMainWindow
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login() = default;

private:
    QLineEdit *m_nameLineEdit;
    QLineEdit *m_surnameLineEdit;
    QLabel *m_loginInfoLabel;
    QPushButton *m_sendButton;
    QHBoxLayout *m_hLayout;
    QVBoxLayout *m_vLayout;
    QPushButton *m_mainWindowButton;

    QString m_name{};
    QString m_surname{};

signals:
    void loginMainWindow();
    void sendData();
    void loginCheck(const QString &t_name, const QString &t_surname);

private slots:
    void onSendButton();
    void onMainWindowButton();
    void onLoginCheck(const QString &t_name, const QString &t_surname);
};
