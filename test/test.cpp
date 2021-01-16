#include <iostream>
#include "MinHeap.hpp"

using namespace std;

int main()
{
	MinHeap testMinHeap;

	HeapNode n1('a', 9);
	testMinHeap.insert(n1);
	HeapNode n2('b', 8);
	testMinHeap.insert(n2);
	HeapNode n3('c', 7);
	testMinHeap.insert(n3);
	HeapNode n4('d', 6);
	testMinHeap.insert(n4);
	HeapNode n5('e', 7);
	testMinHeap.insert(n5);
	HeapNode n6('f', 2);
	testMinHeap.insert(n6);
	HeapNode n7('g', 6);
	testMinHeap.insert(n7);
	HeapNode n8('h', 5);
	testMinHeap.insert(n8);
	HeapNode n9('i', 1);
	testMinHeap.insert(n9);

	for(int i = 0; i<9; i++){
		cout << testMinHeap.pop()->getData() << " Popped! " << endl;
	}
	cout << endl;
}
