
find_package(PkgConfig REQUIRED)
# libdbus-1-dev
pkg_search_module(DBUS REQUIRED dbus-1)

include_directories(${DBUS_INCLUDE_DIRS})

set(MAIN_SOURCES
        main.cpp
        )

set(LINK_LIBS
    stdc++
    )

add_executable(main
        ${MAIN_SOURCES})

target_link_libraries(main ${DBUS_LIBRARIES})        

#设置生成目标二进制的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
install(TARGETS main RUNTIME DESTINATION bin)