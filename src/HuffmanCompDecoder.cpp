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
		readBody(f, outFile, codeTreeRoot);
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
		inputFile.seekg(currentLoc);
		inputFile.read(&body[0], bodySize);

		HeapNode* currNode = codeTreeRoot;
		char byte = 0;
		char bitCount = 8;

		for(auto it = body.begin(); it != body.end()-2; it++)
		{
			byte = *it;
			bitCount = 8;
			while(bitCount)
			{
				bitCount--;
				char bit = (byte & (1<<bitCount)) ? 1 :0;

				if(!currNode->isIntermediate())
				{
					outputFile << currNode->getKey();
					currNode = codeTreeRoot;
				}

				if(bit)
					currNode = currNode->getRightChild();
				else
					currNode = currNode->getLeftChild();
			}
		}

		// Handling EOF
		char validBits = *(body.end()-1);
		byte  = *(body.end()-2);
		bitCount = 8;
		while(bitCount && validBits)
		{
			bitCount--;
			validBits--;
			char bit = (byte & (1<<bitCount)) ? 1 :0;

			if(!currNode->isIntermediate())
			{
				outputFile << currNode->getKey();
				currNode = codeTreeRoot;
			}

			if(bit)
				currNode = currNode->getRightChild();
			else
				currNode = currNode->getLeftChild();
		}

		// Add line feed (POSIX standard for text files requires a 
		// newline character to indicate the end of a text file)
		outputFile << (char) 10;
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

	int previousCode = -1;
	int previousLength = 0;

	for(int i = 0; i < (int) length.size(); i++)
	{
		char n = length[i];
		if (n) {
			for(int j = 0; j < n; j++)
			{
				char c = symbols[symbolsIndex];

				currCode = (previousCode + 1) << (i - previousLength);

				addToCodeTree(root, c, i+1, currCode);
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
	}else {
		HeapNode* n = new HeapNode(symbol, 0, false);
		root->setLeftChild(*n);
	}
}
