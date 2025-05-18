#include "pages.h"
#include "ui_pages.h"

pages::pages(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pages)
    , currentAnimation(nullptr)
    , lastCheckedButton(nullptr)
{
    ui->setupUi(this);

    // Connect all buttons to the toggle slot
    connect(ui->Portfolio, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Cash, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Investment, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->Ledger, &QPushButton::toggled, this, &pages::onButtonToggled);
    connect(ui->News, &QPushButton::toggled, this, &pages::onButtonToggled);

    // Set Portfolio as initially selected
    ui->Portfolio->setChecked(true);
}

pages::~pages()
{
    if (currentAnimation) {
        delete currentAnimation;
    }
}

void pages::onButtonToggled(bool checked)
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button || !checked) return;

    // Delete any existing animation
    if (currentAnimation) {
        currentAnimation->stop();
        delete currentAnimation;
    }

    // Original position
    QRect origGeometry = button->geometry();

    // Create new animation
    currentAnimation = new QPropertyAnimation(button, "geometry");
    currentAnimation->setDuration(150); // 150ms animation
    currentAnimation->setStartValue(origGeometry);

    // Create target geometry (shifted 20px to the right)
    QRect targetGeometry = origGeometry;
    targetGeometry.setLeft(origGeometry.left() + 20);
    targetGeometry.setRight(origGeometry.right() + 20);

    currentAnimation->setEndValue(targetGeometry);
    currentAnimation->setEasingCurve(QEasingCurve::OutCubic);
    currentAnimation->start();

    // If there was a previously checked button, animate it back
    if (lastCheckedButton && lastCheckedButton != button) {
        QPropertyAnimation *reverseAnim = new QPropertyAnimation(lastCheckedButton, "geometry");
        reverseAnim->setDuration(150);

        QRect lastButtonGeom = lastCheckedButton->geometry();
        reverseAnim->setStartValue(lastButtonGeom);

        QRect origLastButtonGeom = lastButtonGeom;
        origLastButtonGeom.setLeft(lastButtonGeom.left() - 20);
        origLastButtonGeom.setRight(lastButtonGeom.right() - 20);

        reverseAnim->setEndValue(origLastButtonGeom);
        reverseAnim->setEasingCurve(QEasingCurve::OutCubic);

        // Auto-delete when done
        reverseAnim->start(QAbstractAnimation::DeleteWhenStopped);
    }

    lastCheckedButton = button;
}
