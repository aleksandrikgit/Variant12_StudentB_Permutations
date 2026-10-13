add_executable(ExplicitClient main.cpp)
target_compile_features(ExplicitClient PRIVATE cxx_std_20)
target_include_directories(ExplicitClient PRIVATE ../include)
target_compile_definitions(ExplicitClient PRIVATE PERMUTATION_STATIC)
add_custom_command(TARGET ExplicitClient POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:PermutationDLL>" "$<TARGET_FILE_DIR:ExplicitClient>")
