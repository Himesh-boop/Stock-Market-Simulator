cmake_minimum_required(VERSION 3.16)
project(StockMarketSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/Core
    ${PROJECT_SOURCE_DIR}/Data
    ${PROJECT_SOURCE_DIR}/Models
    ${PROJECT_SOURCE_DIR}/UI
    ${PROJECT_SOURCE_DIR}/Utils
)

# Source files
set(SOURCES
    main.cpp
    MainWindow.cpp
    mainwindow.ui

    pages/loginPage.cpp
    pages/Page1.cpp
    pages/Page2.cpp
    pages/Page3.cpp

    Core/MarketSimulator.cpp
    Core/OrderManager.cpp
    Core/PortfolioManager.cpp

    Data/DataProvider.cpp

    Models/Stock.cpp
    Models/Portfolio.cpp
    Models/Trade.cpp

    UI/StockListView.cpp
    UI/TradeDialog.cpp

    Utils/Logger.cpp
    Utils/Config.cpp
)

# Header files (optional but good practice)
set(HEADERS
    MainWindow.h
    Core/MarketSimulator.h
    Core/OrderManager.h
    Core/PortfolioManager.h

    pages/loginPage.h
    pages/Page1.h
    pages/Page2.h
    pages/Page3.h

    Data/DataProvider.h

    Models/Stock.h
    Models/Portfolio.h
    Models/Trade.h

    UI/StockListView.h
    UI/TradeDialog.h

    Utils/Logger.h
    Utils/Config.h
)

# UI files
set(UIS
    mainwindow.ui
)

# Create the executable
qt6_wrap_ui(UI_HEADERS ${UIS})

add_executable(StockMarketSimulator
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
    UI/ProfilePage.ui
)

# Link Qt libraries
target_link_libraries(StockMarketSimulator
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
