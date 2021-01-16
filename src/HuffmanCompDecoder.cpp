#include <bits/stdc++.h>
#include <cstdint>
#include <fstream>
#include "HuffmanCompDecoder.hpp"

void HuffmanCompDecoder::decode()
{
	std::ifstream f(inputFileName, ios::in | ios::binary);

	if (f)
	{
		

		f.close();
		ofstream outFile(outputFileName, ios::out | ios::binary);
		outFile.close();
	}else{
		cout << "invalid file." << endl;
	}

}

map<char, int>& HuffmanCompDecoder::readHeader(ifstream& inputFile, map<char, int>& canonicalLengthMap)
{
	char maxLength = 0;
	inputFile.read(&maxLength, 1);
	vector<char> length(maxLength);
	inputFile.read(&length[0], maxLength);

	char numberOfChar = 0;
	inputFile.read(&numberOfChar, 1);
	vector<char> symbols(numberOfChar);
	inputFile.read(&symbols[0], numberOfChar);
	
}
