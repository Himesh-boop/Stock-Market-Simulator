#include "loginpage.h"
#include "ui_loginpage.h"
#include "pages.h"


loginPage::loginPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginPage)
{
    ui->setupUi(this);
    
    // Set window properties
    this->setWindowTitle("Interactive Login System");
    this->setFixedSize(this->size());
    
    // Initialize components
    validationTimer = new QTimer(this);
    validationTimer->setSingleShot(true);
    validationTimer->setInterval(500);  // Delay validation by 500ms after typing
    
    settings = new QSettings("YourCompany", "LoginApp", this);
    
    // Setup connections and animations
    setupConnections();
    setupAnimations();
    loadSettings();
}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::setupConnections()
{
    // Connect login button click
    connect(ui->LoginButton, &QPushButton::clicked, this, &loginPage::onLoginButtonClicked);
    
    // Connect text changed signals for validation
    connect(ui->Username, &QLineEdit::textChanged, validationTimer, static_cast<void (QTimer::*)()>(&QTimer::start));
    connect(ui->Password, &QLineEdit::textChanged, validationTimer, static_cast<void (QTimer::*)()>(&QTimer::start));
    connect(validationTimer, &QTimer::timeout, this, &loginPage::validateInput);
    
    // Connect forgot password button
    connect(ui->forgotPasswordButton, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "Password Recovery", 
                                "Password recovery functionality will be implemented soon.");
    });
    
}

void loginPage::setupAnimations()
{
    // Create button hover animation
    buttonAnimation = new QPropertyAnimation(ui->LoginButton, "geometry", this);
    buttonAnimation->setDuration(100);
    
    // Connect hover events
    ui->LoginButton->installEventFilter(this);
}

bool loginPage::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->LoginButton) {
        if (event->type() == QEvent::Enter) {
            // Mouse entered button - grow slightly
            QRect geo = ui->LoginButton->geometry();
            QRect newGeo = geo.adjusted(-5, -2, 5, 2);
            
            buttonAnimation->setStartValue(geo);
            buttonAnimation->setEndValue(newGeo);
            buttonAnimation->start();
            
            return true;
        } else if (event->type() == QEvent::Leave) {
            // Mouse left button - shrink back
            QRect geo = ui->LoginButton->geometry();
            QRect originalGeo = QRect(370, 340, 201, 51);
            
            buttonAnimation->setStartValue(geo);
            buttonAnimation->setEndValue(originalGeo);
            buttonAnimation->start();
            
            return true;
        }
    }
    
    return QMainWindow::eventFilter(watched, event);
}

void loginPage::validateInput()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    
    // Simple validation example
    bool isValid = !username.isEmpty() && password.length() >= 6;
    
    // Set the login button enabled/disabled based on validation
    ui->LoginButton->setEnabled(isValid);
    
    // Visual feedback
    if (!username.isEmpty() && username.length() < 3) {
        ui->statusLabel->setText("Username too short");
        // ui->Username->setStyleSheet("background-color:rgba(0, 0, 0, 0); "
        //                          "border:2px solid rgba(0, 0, 0, 0); "
        //                          "border-bottom-color:rgba(255, 107, 107, 200); "
        //                          "color:rgba(0, 0, 0); "
        //                          "padding-bottom:7px;");
    } else if (!password.isEmpty() && password.length() < 6) {
        ui->statusLabel->setText("Password too short");
        // ui->Password->setStyleSheet("background-color:rgba(0, 0, 0, 0); "
        //                          "border:2px solid rgba(0, 0, 0, 0); "
        //                          "border-bottom-color:rgba(255, 107, 107, 200); "
        //                          "color:rgba(0, 0, 0); "
        //                          "padding-bottom:7px;");
    } else {
        ui->statusLabel->clear();
        // ui->Username->setStyleSheet("background-color:rgba(0, 0, 0, 0); "
        //                          "border:2px solid rgba(0, 0, 0, 0); "
        //                          "border-bottom-color:rgba(46, 82, 101, 200); "
        //                          "color:rgba(0, 0, 0); "
        //                          "padding-bottom:7px;");
        // ui->Password->setStyleSheet("background-color:rgba(0, 0, 0, 0); "
        //                          "border:2px solid rgba(0, 0, 0, 0); "
        //                          "border-bottom-color:rgba(46, 82, 101, 200); "
        //                          "color:rgba(0, 0, 0); "
        //                          "padding-bottom:7px;");
    }
}

void loginPage::onLoginButtonClicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    
    // Animate button press
    ui->LoginButton->setStyleSheet("padding-left: 5px; padding-top: 5px; "
                                "background-color: rgba(255, 107, 107, 255);");
    
    QTimer::singleShot(200, [this]() {
        ui->LoginButton->setStyleSheet("");  // Reset after animation
    });
    
    // Check credentials
    bool loginSuccess = checkCredentials(username, password);
    
    // Show success/failure
    showLoginResult(loginSuccess);
    
    // Save settings if remember me is checked
    if (ui->rememberMeCheckbox->isChecked()) {
        saveSettings();
    }
}

bool loginPage::checkCredentials(const QString &username, const QString &password)
{
    // Demo credentials - in a real app, you would check against a database or API
    if (username == "himesh" && password == "password123") {
        return true;
    } else if (username == "user" && password == "user123") {
        return true;
    }
    return false;
}

void loginPage::showLoginResult(bool success)
{
    if (success) {
        // // Success animation and message
        // ui->statusLabel->setStyleSheet("color: rgba(0, 128, 0, 200);");
        // ui->statusLabel->setText("Login successful!");
        
        // // After a short delay, you might redirect to the main application
        // QTimer::singleShot(1500, [this]() {
        //     QMessageBox::information(this, "Login Successful", "Welcome to the application!");
        //     // Here you would typically navigate to the main window or dashboard
        // });

        pages *landingPage = new pages(this);
        landingPage->show();
        this->hide();

    } else {
        // Failure animation and message
        ui->statusLabel->setStyleSheet("color: rgba(255, 0, 0, 200);");
        ui->statusLabel->setText("Invalid credentials!");
        
        // Shake animation for the login button
        QPropertyAnimation* shakeAnimation = new QPropertyAnimation(ui->LoginButton, "pos");
        shakeAnimation->setDuration(100);
        
        QPoint originalPos = ui->LoginButton->pos();
        
        QList<QPoint> positions = {
            originalPos + QPoint(5, 0),
            originalPos + QPoint(-5, 0),
            originalPos + QPoint(5, 0),
            originalPos + QPoint(-5, 0),
            originalPos
        };
        
        shakeAnimation->setKeyValueAt(0.0, originalPos);
        shakeAnimation->setKeyValueAt(0.25, positions[0]);
        shakeAnimation->setKeyValueAt(0.5, positions[1]);
        shakeAnimation->setKeyValueAt(0.75, positions[2]);
        shakeAnimation->setKeyValueAt(0.9, positions[3]);
        shakeAnimation->setKeyValueAt(1.0, positions[4]);
        
        shakeAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void loginPage::loadSettings()
{
    if (settings->contains("username")) {
        ui->Username->setText(settings->value("username").toString());
        ui->rememberMeCheckbox->setChecked(true);
    }
}

void loginPage::saveSettings()
{
    settings->setValue("username", ui->Username->text());
}
