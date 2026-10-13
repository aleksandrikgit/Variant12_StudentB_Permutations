add_executable(ImplicitClient main.cpp)
target_include_directories(ImplicitClient PRIVATE ../include)
target_link_libraries(ImplicitClient PRIVATE PermutationDLL)
add_custom_command(TARGET ImplicitClient POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:PermutationDLL>" "$<TARGET_FILE_DIR:ImplicitClient>")
