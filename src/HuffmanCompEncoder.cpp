#include <bits/stdc++.h>
#include <cstdint>
#include <fstream>
#include <unordered_map>
#include "MinHeap.hpp"
#include "HuffmanCompEncoder.hpp"


using namespace std;

void HuffmanCompEncoder::encode()
{
	std::ifstream f(inputFileName);

	if (f)
	{
		f.seekg(0, std::ios::end);
		const auto size = f.tellg();
		string inputText(size, ' ');
		f.seekg(0);
		f.read(&inputText[0], size);
		std::for_each(inputText.begin(), inputText.end(), [](char & c){
				c = ::tolower(c);
				});

		f.close();

		getFrequency(inputText, this->freqMap);
		HeapNode* root = createHuffmanTree(this->freqMap, this->freqTree);
		getCodeLength(root, 0);
		generateCanonicalCode(this->codeLengthMap, this->canonicalCodeMap);

		ofstream outFile(outputFileName, ios::out | ios::binary);

		wrtieHeader(outFile, this->canonicalCodeMap);
		writeEncodedText(outFile, inputText, this->canonicalCodeMap);
		outFile.close();

	}else{
		cout << "invalid file." << endl;
	}
}


HuffmanCompEncoder::~HuffmanCompEncoder()
{
	// Clean up code length map
	for(auto& p : this->codeLengthMap)
	{
		if(p.second)
			delete p.second;
	}
}

void HuffmanCompEncoder::wrtieHeader(ofstream& outFile, unordered_map<char, pair<int, int>>& canonicalCodeMap)
{

	std::vector<pair<char, pair<int, int>> > vec;

	std::copy(canonicalCodeMap.begin(),
			canonicalCodeMap.end(),
			std::back_inserter<std::vector<pair<char, pair<int, int>>>>(vec));

	std::sort(vec.begin(), vec.end(),
			[](const pair<char, pair<int, int>>& l, const pair<char, pair<int, int>>& r) {
			if( l.second.first == r.second.first)
				return l.first < r.first;
			else 
				return l.second.first < r.second.first;
			});

	uint8_t maxLength = (uint8_t) vec[vec.size()-1].second.first;
	uint8_t charNum = (uint8_t) vec.size();

	outFile.write((char *)&maxLength, 1);

	unsigned long  searchIndex = 0;

	for(int i =1; i <= maxLength; i++)
	{
		uint8_t count = 0;
		while(searchIndex < vec.size())
		{
			if(i == vec[searchIndex].second.first)
			{
				count++;
				searchIndex++;
			}else
				break;
		}
		outFile.write((char *)&count, 1);
	}

	outFile.write((char *)&charNum, 1);
	for(auto& p : vec)
	{
		char symbol = p.first;
		outFile.write(&symbol, 1);
	}
}

void HuffmanCompEncoder::writeEncodedText(ofstream& outFile, string& inputText, unordered_map<char, pair<int, int>>& canonicalCodeMap)
{
	int bitCount = 0;
	char buffer = 0;
	for(auto& c : inputText)
	{
		char length = canonicalCodeMap[c].first;
		char code = canonicalCodeMap[c].second;

		for(int i = length; i > 0; i--)
		{
			if(bitCount == 8)
			{
				outFile.write(&buffer, 1);
				buffer = 0;
				bitCount = 0;
			}

			char bit = ((1<<(i-1)) & code) ? 1 : 0;

			buffer |= (bit << (7-bitCount));
			bitCount++;
		}
	}

	outFile.write(&buffer, 1);

	// Write the number of useful bits of the second to last byte in the last byte
	buffer = bitCount;
	outFile.write(&buffer, 1);
	
	outFile.flush();

}
HeapNode* HuffmanCompEncoder::createHuffmanTree(unordered_map<char, int>& freqMap, MinHeap& freqTree)
{
	for(auto& it : freqMap){
		HeapNode* hp = new HeapNode(it.first, it.second);
		freqTree.insert(*hp);
	}

	HeapNode* root = NULL;

	while (freqTree.size() > 1) {
		HeapNode* hn1 = freqTree.pop();
		HeapNode* hn2 = freqTree.pop();

		HeapNode* hn3 = new HeapNode((char)NULL, hn1->getData() + hn2->getData(), true, *hn1, *hn2);
		root = hn3;
		freqTree.insert(*hn3);
	}
	return root;
}


unordered_map<char, pair<int, int>>& HuffmanCompEncoder::generateCanonicalCode(map<int, set<char>*>& codeLengthMap, unordered_map<char, pair<int, int>>& canonicalCodeMap)
{
	int previousLength = 0;
	int currVal = 0;
	int canonicalLength = 0;
	for (auto& it : codeLengthMap)
	{
		set<char>* charSet = it.second;
		canonicalLength += (it.first - previousLength);
		currVal = (currVal) << (it.first - previousLength);
		for(auto c : *charSet)
		{
			canonicalCodeMap.insert({c, pair<int, int>{canonicalLength, currVal}});
			currVal += 1;
		}
		previousLength = it.first;
	}
	return canonicalCodeMap;
}

void HuffmanCompEncoder::getCodeLength(HeapNode* fraqTreeRoot, int length){

	if(fraqTreeRoot == NULL)
		return;

	if(fraqTreeRoot->getLeftChild() == NULL && fraqTreeRoot->getRightChild() == NULL)
	{
		auto kvPair = this->codeLengthMap.find(length);
		if(kvPair == this->codeLengthMap.end())
		{
			set<char>* charSet = new set<char>;
			charSet->insert(fraqTreeRoot->getKey());
			this->codeLengthMap.insert({length, charSet});
		}else
		{
			auto charSet = kvPair->second;
			charSet->insert(fraqTreeRoot->getKey());
		}
		return;
	}
	getCodeLength(fraqTreeRoot->getLeftChild(), length+1);
	getCodeLength(fraqTreeRoot->getRightChild(), length+1);
}
unordered_map<char, int>& HuffmanCompEncoder::getFrequency(string inputText, unordered_map<char, int>& freqMap) {

	for (int i = 0; inputText[i]; i++) {
		if (freqMap.find(inputText[i]) == freqMap.end()) {
			freqMap.insert(make_pair(inputText[i], 1));
		} else {
			freqMap[inputText[i]]++;
		}
	}
	return freqMap;
}
