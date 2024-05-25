set_project("referee_protocol")
set_version("1.0.0")

target("referee_protocol")
    set_kind("static")
    add_files("./referee_protocol.hpp",{rule = "c++"})

target("example")
    set_kind("binary")
    set_languages("gnuxx2b")
    add_files("./example.cpp")