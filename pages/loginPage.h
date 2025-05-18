#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QTimer>
#include <QPropertyAnimation>

namespace Ui {
class loginPage;
}

class loginPage : public QMainWindow
{
    Q_OBJECT

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

public:
    explicit loginPage(QWidget *parent = nullptr);
    ~loginPage();

private slots:
    // Add slots for handling user interactions
    void onLoginButtonClicked();
    void validateInput();
    void showLoginResult(bool success);

private:
    Ui::loginPage *ui;
    QTimer *validationTimer;
    QPropertyAnimation *buttonAnimation;
    QSettings *settings;

    void setupConnections();
    void loadSettings();
    void saveSettings();
    bool checkCredentials(const QString &username, const QString &password);
    void setupAnimations();
};

#endif // LOGINPAGE_H
