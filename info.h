#pragma once

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include "user.h"

class Info : public QMainWindow
{
    Q_OBJECT
public:
    explicit Info(QWidget *parent = nullptr);
    ~Info() = default;

private:
    User *m_user;
    QLabel *m_InfoHeader;
    QVBoxLayout *m_vLayout;
    QPushButton *m_mainWindowButton;

signals:
    void InfoMainWindow();
    void setLabel(User *t_user);

private slots:
    void onMainWindowButton();
    void onSetLabel(User *t_user);
};

