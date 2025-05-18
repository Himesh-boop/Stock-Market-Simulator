#ifndef PAGES_H
#define PAGES_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPushButton>

namespace Ui {
class pages;
}

class pages : public QMainWindow
{
    Q_OBJECT

public:
    explicit pages(QWidget *parent = nullptr);
    ~pages();

private slots:
    void onButtonToggled(bool checked);

private:
    Ui::pages *ui;
    QPropertyAnimation *currentAnimation;
    QPushButton *lastCheckedButton;
};

#endif // PAGES_H
