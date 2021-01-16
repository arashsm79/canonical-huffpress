#ifndef HUFFMAN_COMP_DECODER
#define HUFFMAN_COMP_DECODER

#include <bits/stdc++.h>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include "MinHeap.hpp"

using namespace std;



class HuffmanCompDecoder {
	private:
		string inputFileName, outputFileName;
		map<char, int> canonicalLengthMap;
		HeapNode* canonicaltreeRoot;

	public:
		HuffmanCompDecoder(string inputFileName, string outputFileName):inputFileName(inputFileName), outputFileName(outputFileName){};
		void decode();
		map<char, int>& readHeader(ifstream& inputFile, map<char, int>& canonicalLengthMap);


};
#endif
