cmake_minimum_required(VERSION 3.16)

project(Stock-Market-Simulator LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# UI files
set(UI_FILES
    mainwindow.ui
)

# Header files
set(HEADERS
    MainWindow.h
    Models/Stock.h
    Models/Portfolio.h
    Models/Trade.h
    Core/MarketSimulator.h
    Core/OrderManager.h
    Core/PortfolioManager.h
    Data/DataProvider.h
    UI/StockListView.h
    UI/TradeDialog.h
    Utils/Logger.h
    Utils/Config.h
)

# Source files
set(SOURCES
    main.cpp
    MainWindow.cpp
    Models/Stock.cpp
    Models/Portfolio.cpp
    Models/Trade.cpp
    Core/MarketSimulator.cpp
    Core/OrderManager.cpp
    Core/PortfolioManager.cpp
    Data/DataProvider.cpp
    UI/StockListView.cpp
    UI/TradeDialog.cpp
    Utils/Logger.cpp
    Utils/Config.cpp
)

# Qt UI headers auto-generated from .ui
qt6_wrap_ui(UI_HEADERS ${UI_FILES})

# Create the executable
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
)

# Link Qt libraries
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Models
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Data
    ${CMAKE_CURRENT_SOURCE_DIR}/UI
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
)
