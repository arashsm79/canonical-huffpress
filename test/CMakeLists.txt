set(EXECUTABLE_NAME
	MinHeapTest)

add_executable(${EXECUTABLE_NAME} test.cpp  ${CMAKE_SOURCE_DIR}/src/MinHeap.cpp  ${CMAKE_SOURCE_DIR}/include/HuffmanComp/MinHeap.hpp)

target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_20)

target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall -Wextra -Wpedantic)


set(LIBRARY_NAME
	HuffmanComp)

target_include_directories(${EXECUTABLE_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>)

target_include_directories(${EXECUTABLE_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
