# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\StockMarketSimulator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\StockMarketSimulator_autogen.dir\\ParseCache.txt"
  "StockMarketSimulator_autogen"
  )
endif()
