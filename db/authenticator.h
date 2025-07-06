#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <QString>

class Authenticator
{
public:
    Authenticator();
    bool authenticate(const QString &username, const QString &password);
    bool isValidCredentials(const QString &username, const QString &password);

private:
    bool validateInput(const QString &username, const QString &password);
};

#endif // AUTHENTICATOR_H
