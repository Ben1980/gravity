set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(app
        src/main.cpp
        resources/qml.qrc include/viewer.h src/viewer.cpp include/controller.h src/controller.cpp)

target_include_directories(app
        PRIVATE
        include)

target_compile_definitions(app PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(app PRIVATE Qt5::Core Qt5::Quick solver)