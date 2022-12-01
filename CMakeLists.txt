cmake_minimum_required(VERSION 3.23)

project(calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/aa2e91fd6918519dafa3bee4aa706d04857e7d06.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB SRC_FILES *.cpp)
list(REMOVE_ITEM SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Source.cpp)
list(REMOVE_ITEM SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/testCalculator.cpp)

add_executable(calculator ${SRC_FILES} "Source.cpp")
add_executable(testCalculator ${SRC_FILES} "testCalculator.cpp")

target_link_libraries(testCalculator gtest_main gmock)
target_link_libraries(calculator gtest_main gmock)
add_test(NAME testCalculator COMMAND testCalculator)