#include "bitio.hh"
#include "huffman.hh"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv){
	if(argc<2){ //Make sure filename was provided
		std::cerr<<"Need input filename to encode\n";
		return -1;
	}
	std::ifstream inp(argv[1]);

	if(!inp.is_open()){ //Make sure file can be opened
		std::cerr<<"Can't open input file "<<argv[1]<<"\n";
		return -2; 
	}

	std::ofstream out(*argv[1]+".comp");
	char symbol;
	Huffman huff;
	BitIO bitio(&out, nullptr);

	while(inp.get(symbol)){
		auto bits = huff.encode(symbol);//Encodes symbol
		for(bool bit : bits){
			bitio.output_bit(bit); //Sends that code to file.comp
		}
	}
}


