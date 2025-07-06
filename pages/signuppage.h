#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class SignUpPage; }
QT_END_NAMESPACE

class SignUpPage : public QDialog
{
    Q_OBJECT

public:
    SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();

private slots:
    void onCreateAccButtonClicked();

private:
    Ui::SignUpPage *ui;

    // Database methods
    void storeInDatabase(const QString &username, const QString &email, const QString &password);
};
#endif //SINGUPPAGE_H
