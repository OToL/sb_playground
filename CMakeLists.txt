project(sb_playground LANGUAGES CXX)

add_executable(sb_playground
    src/main.cpp)

target_link_libraries(sb_playground 
    PRIVATE
        sb::core
        sb::cxx_properties_private)
