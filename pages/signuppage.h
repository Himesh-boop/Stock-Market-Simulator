#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QDialog>

namespace Ui {
class SignUpPage;
}

class SignUpPage : public QDialog
{
    Q_OBJECT

private slots:
    void onCreateAccButtonClicked();

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();

private:
    Ui::SignUpPage *ui;

    void storeInDatabase(const QString &username, const QString &email, const QString &password);
};

#endif // SIGNUPPAGE_H
