include_directories(${PROJECT_SOURCE_DIR}/include/mangodb)
set(SOURCES database.cpp
            io_mgr.cpp
           )
add_executable("test" ${SOURCES})
