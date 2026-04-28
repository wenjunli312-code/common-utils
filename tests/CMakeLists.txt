add_executable(test_vector3 test_vector3.cpp)
target_link_libraries(test_vector3 PRIVATE common_utils)
add_test(NAME test_vector3 COMMAND test_vector3)

add_executable(test_matrix4x4 test_matrix4x4.cpp)
target_link_libraries(test_matrix4x4 PRIVATE common_utils)
add_test(NAME test_matrix4x4 COMMAND test_matrix4x4)

add_executable(test_config test_config.cpp)
target_link_libraries(test_config PRIVATE common_utils)
add_test(NAME test_config COMMAND test_config)
