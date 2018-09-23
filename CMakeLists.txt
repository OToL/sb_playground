project(sb_playground LANGUAGES CXX)

sbAddExecutable(sb_playground
    src/main.cpp)

target_link_libraries(sb_playground 
    PRIVATE
        sb::core)
