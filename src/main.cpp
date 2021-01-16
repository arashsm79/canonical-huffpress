#include <bits/stdc++.h>
#include "HuffmanCompEncoder.hpp"

int main(int argc, char** argv)
{
	string InputFileName = argv[1];
	string OutputFileName = argv[2];

	HuffmanCompEncoder encoder(InputFileName, OutputFileName);
	encoder.encode();

}
