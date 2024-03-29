#pragma once

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr)
        : QObject{parent}
    {}
    ~User() = default;

    QString name{};
    QString surname{};
};
