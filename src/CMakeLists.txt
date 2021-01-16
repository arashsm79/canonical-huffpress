set(EXECUTABLE_NAME
	HuffmanComp)

add_executable(${EXECUTABLE_NAME} main.cpp HuffmanCompEncoder.cpp  MinHeap.cpp  ${CMAKE_SOURCE_DIR}/include/HuffmanComp/MinHeap.hpp)


target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_20)

target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall -Wextra -Wpedantic)


target_include_directories(${EXECUTABLE_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/${EXECUTABLE_NAME}>
    $<INSTALL_INTERFACE:include/${EXECUTABLE_NAME}>)

target_include_directories(${EXECUTABLE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
