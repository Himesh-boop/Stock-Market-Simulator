cmake_minimum_required(VERSION 3.16)
project(StockMarketSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts Sql)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/Core
    ${PROJECT_SOURCE_DIR}/Data
    ${PROJECT_SOURCE_DIR}/Models
    ${PROJECT_SOURCE_DIR}/UI
    ${PROJECT_SOURCE_DIR}/UI/pages
    ${PROJECT_SOURCE_DIR}/Utils
    ${PROJECT_SOURCE_DIR}/pages
)

# Source files
set(SOURCES
    main.cpp

    pages/signuppage.cpp
    pythonBackend/nepse_data_server.py
    db/dbUpdater.py

    pages/loginpage.cpp
    pages.cpp

    Data/DataProvider.cpp

    Models/Stock.cpp
    Models/Portfolio.cpp
    Models/Trade.cpp
    Models/candlestickChart.py

    UI/StockListView.cpp
    UI/TradeDialog.cpp

    Utils/Logger.cpp
    Utils/Config.cpp

    logindb.cpp
)

# Header files
set(HEADERS
    pages.h
    pages/signuppage.h
    pages/loginpage.h
    Data/DataProvider.h

    Models/Stock.h
    Models/Portfolio.h
    Models/Trade.h

    UI/StockListView.h
    UI/TradeDialog.h

    Utils/Logger.h
    Utils/Config.h

    logindb.h
)

# All UI files should be here directly (for AUTOUIC to work)
set(FORMS
    pages.ui
    pages/loginpage.ui
    pages/signuppage.ui
)

# Create executable with .ui files included directly
add_executable(StockMarketSimulator
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
    resources.qrc
)

# Link Qt libraries
target_link_libraries(StockMarketSimulator
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Charts
    Qt6::Sql
)
