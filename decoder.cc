#include "huffman.hh"
#include "bitio.hh"
#include <iostream>
#include <fstream>
#include <string>

//decoder takes in a filename, reads it, and decompressed it into a file with 
//the same name and a .plaintext suffix. 
int main (int argc, char **argv) 
{
    if(argc < 2){
	    std::cerr <<"need filename to decode";
	    return -1;
    }
    std::ofstream outputFile(std::string(argv[1]) + ".plaintext", std::ios::out);
    std::ifstream inputFile(std::string(argv[1]), std::ios::in);
    if(!inputFile.is_open()){
	    std::cerr <<"Cannot open input file.\n";
	    return -2;
    }


    Huffman huff;
    BitIO bitio(nullptr, &inputFile);
    int symbol = huff.decode(bitio.input_bit());
    while(symbol != Huffman::HEOF) {
        if(symbol != -1) {
            outputFile.put(symbol);
        }
        symbol = huff.decode(bitio.input_bit());
        
    }
    return 0;
} 
 

