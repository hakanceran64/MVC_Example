#pragma once

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

class SignUp : public QMainWindow
{
    Q_OBJECT
public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp() = default;

private:
    QLineEdit *m_nameLineEdit;
    QLineEdit *m_surnameLineEdit;
    QLabel *m_signUpInfoLabel;
    QPushButton *m_sendButton;
    QHBoxLayout *m_hLayout;
    QVBoxLayout *m_vLayout;
    QPushButton *m_mainWindowButton;

    QString m_name{};
    QString m_surname{};

signals:
    void signUpMainWindow();
    void sendData(const QString &t_name, const QString &t_surname);
    void signUpCheck(const QString &t_name, const QString &t_surname);

private slots:
    void onSendButton();
    void onMainWindowButton();
    void onSignUpCheck(const QString &t_name, const QString &t_surname);
};
