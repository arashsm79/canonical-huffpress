# Canonical Huffman Coding Compression
> High-performance library for encoding and decoding ASCII text files using canonical Huffman code

An easy-to-use text compression C++ library that uses [Canonical Huffman Code](https://en.wikipedia.org/wiki/Canonical_Huffman_code) to encode and decode ASCII text files.

It's Fast and can cause up to 50% decrease in size for day-to-day text files.

## Table of Contents
- [Building](#Building)
- [Usage](#Usage)
- [How It Works](#How-It-Works)
- [See Also](#see-also)

## Building

There is a simple program that derives this library in the test folder.
It receives two arguments; The first one is the path of the text file that is going to be encoded and the second one is the path and name of where you want your decoded file to reside.

To build this application simply create a directory called build in the projects main folder, move to that folder and do:
```shell
cmake ..

make
```
Head over to the test directory.
You can then use the application like so:
```shell
./EncodeTest /path/to/InputTextFile /path/to/decodedFile


./DecodeTest /path/to/decodedFile /path/to/OutputTextFile
```

## Usage

This library uses CMAKE as a build system generator. Simply clone this library to the proper place in your project, set up and the correct include path and add it as a library:

```CMake
target_link_libraries(${TARGET_NAME} HuffmanCompDecoder)


target_link_libraries(${TARGET_NAME} HuffmanCompEncoder)
```

After including the header files, instantiate the class and use the encode method:
```cpp

HuffmanCompEncoder encoder("/path/to/InputTextFile", "/path/to/OutPutBinaryFile");
try {
	encoder.encode();
} catch (const std::invalid_argument& e) {
	cout << "Invalid file path" << endl;
}


HuffmanCompDecoder decoder("/path/to/InputBinaryFile", "/path/to/OutPutTextFile");
try {
	decoder.decode();
} catch (const std::invalid_argument& e) {
	cout << "Invalid file path" << endl;
}

```

## How It Works

* The program first creates a map of characters and their respective frequencies.

* It then uses that map and the MinHeap library that is included in this project to create a Huffman Tree.

* Using the Huffman Tree, it calculates the code length for each symbol.

* With the code lengths we can now generate the canonical code for each symbol.

* after the above steps, we write out the header and use the canonical code to encode the symbols in the input text file.


## See Also

* [Huffman Coding](https://en.wikipedia.org/wiki/Huffman_coding)

* [Canonical Huffman](https://en.wikipedia.org/wiki/Canonical_Huffman_code)

* The format of the header file is the same as the second way of encoding the header which is described here. [Encoding the codebook](https://en.wikipedia.org/wiki/Canonical_Huffman_code#Encoding_the_codebook)


