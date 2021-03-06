#include <bits/stdc++.h>
#include "HuffmanCompDecoder.hpp"

int main(int argc, char** argv)
{
	string InputFileName = argv[1];
	string OutputFileName = argv[2];

	HuffmanCompDecoder decoder(InputFileName, OutputFileName);
	try {
		decoder.decode();
	} catch (const std::invalid_argument& e) {
		cout << "Invalid file path" << endl;
	}
}
