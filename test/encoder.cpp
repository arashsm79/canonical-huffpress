#include <bits/stdc++.h>
#include "HuffmanCompEncoder.hpp"

int main(int argc, char** argv)
{
	string InputFileName = argv[1];
	string OutputFileName = argv[2];

	HuffmanCompEncoder encoder(InputFileName, OutputFileName);
	try {
		encoder.encode();
	} catch (const std::invalid_argument& e) {
		cout << "Invalid file path" << endl;
	}

}
