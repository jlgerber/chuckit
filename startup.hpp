
#pragma once
#include <QObject>

namespace MyNamespace{
    class Settings : public QObject
    {
        Q_OBJECT
    public:
        explicit Settings(QObject *parent=0);

    private:
        explicit Settings(const Settings& rhs) = delete;
        Settings& operator= (const Settings& rhs) = delete;
    };
    }


