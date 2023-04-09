cmake_minimum_required(VERSION 3.24)
project(ModuleWeatherStation)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/qt5")
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(WEATHER_STATION_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/WeatherStation)
set(WEATHER_STATION_SRC_DIR ${CMAKE_SOURCE_DIR}/src/WeatherStation)

set(SENSOR_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/Sensor)
set(SENSOR_SRC_DIR ${CMAKE_SOURCE_DIR}/src/Sensor)
set(SENSOR_WINDOW_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/Sensor/Window)
set(SENSOR_WINDOW_SRC_DIR ${CMAKE_SOURCE_DIR}/src/Sensor/Window)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


add_subdirectory(src)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
