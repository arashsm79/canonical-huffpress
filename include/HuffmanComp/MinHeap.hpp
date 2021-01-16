#ifndef MIN_HEAP
#define MIN_HEAP
#include <bits/stdc++.h>

class HeapNode {
	
	private:
		char key;
		int data;
		HeapNode* left;
		HeapNode* right;
                bool intermediate;

              public:
		HeapNode(char key, int data): key(key), data(data), left(NULL), right(NULL), intermediate(false){};
                HeapNode(char key, int data, bool isIntermediate)
                    : key(key), data(data), left(NULL), right(NULL),
                      intermediate(isIntermediate){};
                HeapNode(char key, int data, bool isIntermediate,
                         HeapNode &left, HeapNode &right)
                    : key(key), data(data), left(&left), right(&right),
                      intermediate(isIntermediate){};

                char getKey(){return key;};
		void setKey(char key){this->key = key;};

		int getData(){return data;};
		void setData(int data){this->data = data;};

		HeapNode* getLeftChild(){return left;};
		void setLeftChild(HeapNode &left){this->left = &left;};

		HeapNode* getRightChild(){return right;};
		void setRightChild(HeapNode &right){this->right = &right;};

		void setIntermediate(bool isIntermediate){
                  this->intermediate = isIntermediate;
                };
                bool isIntermediate() { return this->intermediate; };
};

class MinHeap {
	private:
		std::vector<HeapNode *> heapVec;

	public:
		MinHeap(){};
		void insert(HeapNode& element);
		HeapNode* pop();
		void heapify(int index);
		void printHeap();
		int parent(int index);
		int leftChild(int index);
		int rightChild(int index);
		unsigned long size(){return heapVec.size();};
};


#endif
