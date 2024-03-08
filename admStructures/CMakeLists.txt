set(CMAKE_CXX_STANDARD 17)
add_library(adm INTERFACE lists.hpp sequences.hpp)
target_include_directories(adm INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})