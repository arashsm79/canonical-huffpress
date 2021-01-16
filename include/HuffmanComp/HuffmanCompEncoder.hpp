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
		map<char, pair<int, int>> canonicalCodeMap;
		string inputFileName, outputFileName;

	public:
		HuffmanCompEncoder(string inputFileName, string outputFileName):inputFileName(inputFileName), outputFileName(outputFileName){};
		unordered_map<char, int>& getFrequency(string str, unordered_map<char, int>& freqMap);
		HeapNode* createHuffmanTree(unordered_map<char, int>& freqMap, MinHeap& freqTree);
		void getCodeLength(HeapNode* freqTreeRoot, int length);
		map<char, pair<int, int>>& generateCanonicalCode(map<int, set<char>*>& codeLengthMap, map<char, pair<int, int>>& canonicalCodeMap);
		void encode();
		void wrtieHeader(ofstream& outFile, map<char, pair<int, int>>& canonicalCodeMap);
		void writeEncodedText(ofstream& outfile, string& inputText, map<char, pair<int, int>>& canonicalCodeMap);


};
#endif
