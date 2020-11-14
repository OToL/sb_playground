OPTION(SB_ENABLE_SAMPLE_SANDBOX "Enable Sunburst Sandbox sample" OFF)

if(SB_ENABLE_SAMPLE_SANDBOX)
    project(sb_playground LANGUAGES CXX)
    
    add_executable(sb_playground
        src/main.cpp)

    target_link_libraries(sb_playground 
        PRIVATE
            sb::core
            sb::cxx_common_private)

    sb_copy_target_shared_dependencies(sb_playground)
endif()