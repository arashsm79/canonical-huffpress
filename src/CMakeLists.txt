set( ENCODE_LIB
	HuffmanCompEncoder)

add_library(${ENCODE_LIB} 
	HuffmanCompEncoder.cpp 
	${CMAKE_SOURCE_DIR}/include/HuffmanComp/HuffmanCompEncoder.hpp
	MinHeap.cpp
	${CMAKE_SOURCE_DIR}/include/HuffmanComp/MinHeap.hpp)  


set(INCLUDE_FOLDER
	HuffmanComp)

target_include_directories(${ENCODE_LIB} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/${INCLUDE_FOLDER}>
    $<INSTALL_INTERFACE:include/${INCLUDE_FOLDER}>)

target_include_directories(${ENCODE_LIB} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)


set( DECODE_LIB
	HuffmanCompDecoder)

add_library(${DECODE_LIB} 
	HuffmanCompDecoder.cpp 
	${CMAKE_SOURCE_DIR}/include/HuffmanComp/HuffmanCompDecoder.hpp
	MinHeap.cpp
	${CMAKE_SOURCE_DIR}/include/HuffmanComp/MinHeap.hpp)  


set(INCLUDE_FOLDER
	HuffmanComp)

target_include_directories(${DECODE_LIB} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/${INCLUDE_FOLDER}>
    $<INSTALL_INTERFACE:include/${INCLUDE_FOLDER}>)

target_include_directories(${DECODE_LIB} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
