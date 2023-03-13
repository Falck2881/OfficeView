cmake_minimum_required(VERSION 3.18)

project(OfficeView VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Network REQUIRED)

qt_add_resources(RccStyle "${CMAKE_CURRENT_SOURCE_DIR}/RCC/RccStyle.qrc")



set(WIN_SOURCES
        Windows/WindowID.cpp
        Windows/WindowID.h
        Windows/WindowID.ui
)

set(SOURCES Sources/Input.h Sources/Input.cpp
            Sources/LinkerInput.h Sources/LinkerInput.cpp
            Sources/Check.h Sources/Check.cpp
            Sources/CheckInputSignIn.h Sources/CheckInputSignIn.cpp
            Sources/CheckInputSignUp.h Sources/CheckInputSignUp.cpp
            Sources/Command.h)

if(WIN32)
    add_executable(OfficeView WIN32 ${WIN_SOURCES} ${SOURCES} ${RccStyle} main.cpp)
else()
    add_executable(OfficeView ${WIN_SOURCES} ${SOURCES} ${RccStyle} main.cpp)
endif()

target_link_libraries(OfficeView PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                         Qt${QT_VERSION_MAJOR}::Core
                                         Qt${QT_VERSION_MAJOR}::Network)

target_include_directories(OfficeView PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Windows"
                                              "${CMAKE_CURRENT_SOURCE_DIR}/Sources")


include(FetchContent)
FetchContent_Declare(googletest
                     URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)


set(AllTestsColorView Tests/test_main.cpp ${WIN_SOURCES})

enable_testing()

add_executable(TestColorView ${AllTestsColorView} ${SOURCES} ${RccStyle})

target_include_directories(TestColorView PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Windows"
                                                 "${CMAKE_CURRENT_SOURCE_DIR}/Sources")

target_link_libraries(TestColorView PRIVATE GTest::gtest GTest::gtest_main
                                            Qt${QT_VERSION_MAJOR}::Widgets
                                            Qt${QT_VERSION_MAJOR}::Core
                                            Qt${QT_VERSION_MAJOR}::Network
                                            )

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set_target_properties(OfficeView PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(OfficeView)
endif()
