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
    ${PROJECT_SOURCE_DIR}/UI/pages     # ✅ Added this
    ${PROJECT_SOURCE_DIR}/Utils
)

# Source files
set(SOURCES
    main.cpp

    pages/loginpage.cpp
    pages.cpp

    Data/DataProvider.cpp

    Models/Stock.cpp
    Models/Portfolio.cpp
    Models/Trade.cpp

    UI/StockListView.cpp
    UI/TradeDialog.cpp

    Utils/Logger.cpp
    Utils/Config.cpp
)

# Header files
set(HEADERS
    pages.h

    pages/loginpage.h
    Data/DataProvider.h

    Models/Stock.h
    Models/Portfolio.h
    Models/Trade.h

    UI/StockListView.h
    UI/TradeDialog.h

    Utils/Logger.h
    Utils/Config.h
)

# UI files (with correct paths)
set(UIS
    pages.ui
    pages/loginpage.ui
)


# Create the executable
add_executable(StockMarketSimulator
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
    ${UIS}
)

# Link Qt libraries
target_link_libraries(StockMarketSimulator
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
