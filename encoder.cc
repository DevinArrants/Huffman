#include "bitio.hh"
#include "huffman.hh"
#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char const *argv[])
{  if(argc<2){ //Make sure filename was provided
    std::cerr<<"Need input filename to encode\n";
    return -1;
  }
  
  std::ifstream inp(argv[1]);

  if(!inp.is_open()){ //Make sure file can be opened
    std::cerr<<"Can't open input file "<<argv[1]<<"\n";
    return -2; 
  }
   std::fstream out; 
   out.open(std::string(argv[1])+".comp",std::ios::out); 
   char symbol;
   Huffman huff;
   BitIO bitio(&out, nullptr);

  while(inp.get(symbol)){
    auto bits = huff.encode(symbol);//Encodes symbol
    for(bool bit : bits){
      bitio.output_bit(bit); //Sends that code to file.comp
    }
  }

  for(auto bits: huff.encode(Huffman::HEOF)){
	  bitio.output_bit(bits);
  }
   out.close(); 
   return 0; 
} 
