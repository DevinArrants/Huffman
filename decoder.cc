#include "huffman.hh"
#include "bitio.hh"
#include <iostream>
#include <fstream>

//decoder takes in a filename, reads it, and decompressed it into a file with 
//the same name and a .plaintext suffix. 
int main (int argc, char **argv) 
{
    //looping through multiple command line arguments
    for(unsigned i = 1; i < argc; i++){     
        std::ofstream outputFile(string(argv[i]) + ".plaintext");
        std::ifstream inputFile(strng(argv[i]));
        if (!inputFile.is_open()) {
            cerr << "Can't open input file.";
            return -1;
        }

    }
    Huffman huf;
    BitIO bitio(nullptr, &inputFile);
    int symbol = huff.decode(bitio.input_bit());
    while(symbol != Huffman::HEOF) {
        if(symbol != -1) {
            outputFile.put(symbol)
        }
        huff.decode(bitio.input_bit());
        
    }
    return 0;
} 
 

