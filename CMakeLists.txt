cmake_minimum_required(VERSION 3.16)

project(StockMarketSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Make sure CMake can find Qt6 properly
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Modern Qt6 setup (this enables qt_add_ui_files, qt_add_executable, etc.)
qt_standard_project_setup()

# Add source files
set(SOURCES
    main.cpp

    pages/loginpage.cpp
    pages.cpp
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

# Add header files
set(HEADERS

    pages/loginpage.h
    pages.h
    Core/MarketSimulator.h
    Core/OrderManager.h
    Core/PortfolioManager.h
    Data/DataProvider.h
    Models/Stock.h
    Models/Portfolio.h
    Models/Trade.h
    UI/StockListView.h
    UI/TradeDialog.h
    Utils/Logger.h
    Utils/Config.h
)

# Add UI files
set(UI_FILES

    pages.ui
    pages/loginpage.ui
    UI/ProfilePage.ui
)

qt_add_executable(StockMarketSimulator
    MANUAL_FINALIZATION
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    loginpage.h loginpage.cpp loginpage.ui
)

# Link Qt libraries
target_link_libraries(StockMarketSimulator PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

qt_finalize_executable(StockMarketSimulator)
