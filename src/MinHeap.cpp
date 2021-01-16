#include <bits/stdc++.h>
#include <climits>
#include "MinHeap.hpp"

void MinHeap::insert(HeapNode &element){
	// insert new key at the end of the heap
	heapVec.push_back(&element);

	int curIndex = heapVec.size() - 1;
	// Heapify 
	while (curIndex != 0 && heapVec[parent(curIndex)]->getData() > heapVec[curIndex]->getData()) 
	{ 
		std::swap(heapVec[curIndex], heapVec[parent(curIndex)]); 
		curIndex = parent(curIndex); 
	} 
	std::cout << "Insert: ";
	printHeap();
}

HeapNode* MinHeap::pop(){
	if(heapVec.empty())
		return NULL;
	else if (heapVec.size() == 1){
		HeapNode* minNode = heapVec[0];
		heapVec.pop_back();
		return minNode;
	}else {
		HeapNode* minNode = heapVec[0];
		heapVec[0] = heapVec[heapVec.size()-1];
		heapVec.pop_back();
		heapify(0);
		return minNode;
	}
}

void MinHeap::heapify(int index){
	HeapNode* left = NULL;
	int leftIndex;

	HeapNode* right = NULL;
	int rightIndex;

	int vecSize = heapVec.size();

	HeapNode* minNode = heapVec[index];
	int minIndex = index;

	HeapNode* currNode = minNode;
	int currIndex = index;

	do {
		leftIndex = leftChild(currIndex);
		if (leftIndex < vecSize ) {
			left = heapVec[leftIndex];
			if(left->getData() < currNode->getData()){
				minIndex = leftIndex;
				minNode = left;
			}
		}else
			left = NULL;

		rightIndex = rightChild(currIndex);
		if (rightIndex < vecSize ) {
			right = heapVec[rightIndex];
			if(right->getData() < minNode->getData()){
				minIndex = rightIndex;
				minNode = right;
			}
		}else
			right = NULL;

		if (currIndex == minIndex)
			break;

		std::swap(heapVec[minIndex], heapVec[currIndex]);	
		currIndex = minIndex;

	}while (!(left == NULL && right == NULL));
}

int MinHeap::parent(int i) { return (i-1)/2; } 
int MinHeap::leftChild(int i) { return (2*i + 1); } 
int MinHeap::rightChild(int i) { return (2*i + 2); } 

void MinHeap::printHeap(){
	for(unsigned long i = 0; i < heapVec.size(); i++)
		std::cout << heapVec[i]->getData() << " ";
	std::cout << std::endl;
}
