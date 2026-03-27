set(SRCS
    "src/Application/Core/Log.cpp"
    "src/Application/Core/Application.cpp"
    "src/Application/Routes/Route.cpp"
    "src/tdpch.h"
    "src/Application/Core/Log.h"
    "src/Application/Core/Application.h"
    "src/Application/Core/Core.h"
    "src/Application/Routes/Routes.h"
)
add_executable(todo ${SRCS})
set_property(TARGET todo PROPERTY CXX_STANDARD 20)

target_precompile_headers(todo PUBLIC src/tdpch.h)
target_include_directories(todo PRIVATE
    "src"
    "${CMAKE_SOURCE_DIR}/vendor/spdlog/include"
    "${CMAKE_SOURCE_DIR}/vendor/Spider/Spider/src"
)

target_link_libraries(todo
    spider
)

