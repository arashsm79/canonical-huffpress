set(INCLUDE_FOLDER
	HuffmanComp)

# Encode Test

set(ENCODE_TEST
	EncodeTest)

add_executable(${ENCODE_TEST} encoder.cpp)
target_link_libraries(${ENCODE_TEST} HuffmanCompEncoder)
target_compile_features(${ENCODE_TEST} PRIVATE cxx_std_20)
target_compile_options(${ENCODE_TEST} PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(${ENCODE_TEST} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/${INCLUDE_FOLDER}>
    $<INSTALL_INTERFACE:include/${INCLUDE_FOLDER}>)

target_include_directories(${ENCODE_TEST} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

# Decode Test

set(DECODE_TEST
	DecodeTest)

add_executable(${DECODE_TEST} decoder.cpp) 
target_link_libraries(${DECODE_TEST} HuffmanCompDecoder)
target_compile_features(${DECODE_TEST} PRIVATE cxx_std_20)
target_compile_options(${DECODE_TEST} PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(${DECODE_TEST} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/${INCLUDE_FOLDER}>
    $<INSTALL_INTERFACE:include/${INCLUDE_FOLDER}>)

target_include_directories(${DECODE_TEST} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

# MinHeap Test

set(MINHEAP_TEST
	MinHeapTest)

add_executable(${MINHEAP_TEST} 
	test.cpp  
	${CMAKE_SOURCE_DIR}/src/MinHeap.cpp  
	${CMAKE_SOURCE_DIR}/include/HuffmanComp/MinHeap.hpp)
target_compile_features(${MINHEAP_TEST} PRIVATE cxx_std_20)
target_compile_options(${MINHEAP_TEST} PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(${MINHEAP_TEST} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/${INCLUDE_FOLDER}>
    $<INSTALL_INTERFACE:include/${INCLUDE_FOLDER}>)
target_include_directories(${MINHEAP_TEST} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)


