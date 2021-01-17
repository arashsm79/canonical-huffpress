#include <bits/stdc++.h>
#include <cstdint>
#include <fstream>
#include "HuffmanCompDecoder.hpp"
#include "MinHeap.hpp"

void HuffmanCompDecoder::decode()
{
	std::ifstream f(inputFileName, ios::in | ios::binary);
	if (f)
	{
		
		HeapNode* codeTreeRoot = readHeader(f);
		ofstream outFile(outputFileName);
		f.close();
		outFile.close();
	}else{
		cout << "invalid file." << endl;
	}
}

void HuffmanCompDecoder::readBody(ifstream& inputFile, ofstream& outputFile, HeapNode* codeTreeRoot)
{
		const auto currentLoc = inputFile.tellg();
		inputFile.seekg(0, inputFile.end);
		const auto bodySize = inputFile.tellg() - currentLoc;
		vector<char> body(bodySize);
		inputFile.read(&body[0], bodySize);

		HeapNode* currNode = codeTreeRoot;
		for(auto& byte : body)
		{
			char bitCount = 7;
			while(bitCount)
			{
				char bit = (byte & (1<<bitCount)) ? 1 :0;

				if(currNode->isIntermediate())
				{
					if(bit)
						currNode = currNode->getRightChild();
					else
						currNode = currNode->getLeftChild();
				}else
				{
					currNode = codeTreeRoot;
					outputFile << currNode->getKey();
				}

				bitCount--;
			}
		}
}
HeapNode* HuffmanCompDecoder::readHeader(ifstream& inputFile)
{
	char maxLength = 0;
	inputFile.read(&maxLength, 1);
	vector<char> length(maxLength);
	inputFile.read(&length[0], maxLength);

	char numberOfChar = 0;
	inputFile.read(&numberOfChar, 1);
	vector<char> symbols(numberOfChar);
	inputFile.read(&symbols[0], numberOfChar);

	HeapNode* root = new HeapNode(char(NULL), 0, true);

	int symbolsIndex = 0;

	int currCode = 0;

	int previousCode = 0;
	int previousLength = 0;

	for(int i = 0; i < (int) length.size(); i++)
	{
		char n = length[i];
		if (n) {
			for(int j = 0; j < n; j++)
			{
				char c = symbols[symbolsIndex];

				currCode = (previousCode + 1) << (i - previousLength);

				addToCodeTree(root, c, i, currCode);
				symbolsIndex++;
				previousCode = currCode;
				previousLength = i;
			}
		}
	}
	return root;
	
}
void HuffmanCompDecoder::addToCodeTree(HeapNode* root, char symbol, int length, int code)
{
	for(int i = length; i > 1; i--)
	{
		char bit = ((1<<(i-1)) & code) ? 1 : 0;

		if (bit) {
			if(root->getRightChild() == NULL)
			{
				HeapNode* n = new HeapNode(char(NULL), 0, true);
				root->setRightChild(*n);
				root = root->getRightChild();
			}else {
				root = root->getRightChild();
			}

		}else {
			if(root->getLeftChild() == NULL)
			{
				HeapNode* n = new HeapNode(char(NULL), 0, true);
				root->setLeftChild(*n);
				root = root->getLeftChild();
			}else {
				root = root->getLeftChild();
			}
			
		}
	}

	char bit = ((1) & code) ? 1 : 0;
	if(bit)
	{
		HeapNode* n = new HeapNode(symbol, 0, false);
		root->setRightChild(*n);
		root = root->getRightChild();
	}else {
		HeapNode* n = new HeapNode(symbol, 0, false);
		root->setLeftChild(*n);
		root = root->getLeftChild();
	}
}
