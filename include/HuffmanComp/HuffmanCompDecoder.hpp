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
		HeapNode *canonicalTreeRoot = NULL;

	public:
		HuffmanCompDecoder(string inputFileName, string outputFileName):inputFileName(inputFileName), outputFileName(outputFileName){};
		~HuffmanCompDecoder()
		{
			if (this->canonicalTreeRoot)
				delete this->canonicalTreeRoot;
		};
		void decode();
		HeapNode* readHeader(ifstream& inputFile);
		void addToCodeTree(HeapNode* root, char symbol, int length, int code);
		void readBody(ifstream& inputFile, ofstream& outputFile, HeapNode* codeTreeRoot);
};
#endif
