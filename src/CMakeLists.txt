cmake_minimum_required(VERSION 3.24)


add_executable(${PROJECT_NAME}
        main.cpp
        ${WEATHER_STATION_INCLUDE_DIR}/IWeatherStation.h
        ${WEATHER_STATION_SRC_DIR}/WeatherStationWin.cpp ${WEATHER_STATION_INCLUDE_DIR}/WeatherStationWin.h
        ${WEATHER_STATION_SRC_DIR}/WeatherStation.cpp ${WEATHER_STATION_INCLUDE_DIR}/WeatherStation.h

#        AlgorithmZambretti.cpp ${MY_INCLUDE_DIR}/AlgorithmZambretti.h

        ${SENSOR_INCLUDE_DIR}/ISensor.h
        ${SENSOR_SRC_DIR}/Sensor.cpp ${SENSOR_INCLUDE_DIR}/Sensor.h
        ${SENSOR_SRC_DIR}/HumiditySensor.cpp ${SENSOR_INCLUDE_DIR}/HumiditySensor.h
        ${SENSOR_SRC_DIR}/BarometerSensor.cpp ${SENSOR_INCLUDE_DIR}/BarometerSensor.h
        ${SENSOR_SRC_DIR}/TemperatureSensor.cpp ${SENSOR_INCLUDE_DIR}/TemperatureSensor.h

        ${SENSOR_WINDOW_SRC_DIR}/DoubleSlider.cpp ${SENSOR_WINDOW_INCLUDE_DIR}/DoubleSlider.h
        ${SENSOR_WINDOW_SRC_DIR}/SensorWindow.cpp ${SENSOR_WINDOW_INCLUDE_DIR}/SensorWindow.h
        ${SENSOR_WINDOW_SRC_DIR}/BarometerSensorWin.cpp ${SENSOR_WINDOW_INCLUDE_DIR}/BarometerSensorWin.h
        ${SENSOR_WINDOW_SRC_DIR}/HumiditySensorWin.cpp ${SENSOR_WINDOW_INCLUDE_DIR}/HumiditySensorWin.h
        ${SENSOR_WINDOW_SRC_DIR}/TemperatureSensorWin.cpp ${SENSOR_WINDOW_INCLUDE_DIR}/TemperatureSensorWin.h
        )