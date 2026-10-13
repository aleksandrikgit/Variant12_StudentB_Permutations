add_library(PermutationStatic STATIC ../src/PermutationLib.cpp)
target_include_directories(PermutationStatic PUBLIC ../include)
target_compile_definitions(PermutationStatic PUBLIC PERMUTATION_STATIC)
target_compile_features(PermutationStatic PUBLIC cxx_std_20)

add_executable(StaticDemo main.cpp)
target_link_libraries(StaticDemo PRIVATE PermutationStatic)
