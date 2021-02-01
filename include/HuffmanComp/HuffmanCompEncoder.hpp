#ifndef HUFFMAN_COMP_ENCODER
#define HUFFMAN_COMP_ENCODER
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include "MinHeap.hpp"

using namespace std;



class HuffmanCompEncoder {
	private:
		MinHeap freqTree;
		unordered_map<char, int> freqMap;
		map<int, set<char>*> codeLengthMap;
		unordered_map<char, pair<int, int>> canonicalCodeMap;
		string inputFileName, outputFileName;
		unordered_map<char, int>& getFrequency(string str, unordered_map<char, int>& freqMap);
		HeapNode* createHuffmanTree(unordered_map<char, int>& freqMap, MinHeap& freqTree);
		void getCodeLength(HeapNode* freqTreeRoot, int length);
		unordered_map<char, pair<int, int>>& generateCanonicalCode(map<int, set<char>*>& codeLengthMap, unordered_map<char, pair<int, int>>& canonicalCodeMap);
		void writeHeader(ofstream& outFile, unordered_map<char, pair<int, int>>& canonicalCodeMap);
		void writeEncodedText(ofstream& outfile, string& inputText, unordered_map<char, pair<int, int>>& canonicalCodeMap);

	public:
		HuffmanCompEncoder(const string& inputFileName, const string& outputFileName):inputFileName(inputFileName), outputFileName(outputFileName){};
		~HuffmanCompEncoder();
		void encode();

};
#endif

