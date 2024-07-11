set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDES src/*.cpp)
add_library(referee_protocol OBJECT ${srcs})
target_include_directories(referee_protocol PUBLIC include toml11)


if (referee_protocol_BUILD_EXAMPLE)
    add_subdirectory(example)
endif ()
