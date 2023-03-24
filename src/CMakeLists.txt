include_directories(${PROJECT_SOURCE_DIR}/include/mangodb)
set(SOURCES database.cpp
            main.cpp)
add_executable("test" ${SOURCES})
