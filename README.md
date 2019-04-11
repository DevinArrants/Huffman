# Huffman
bitio.cc is the implementation of the bitio.hh class that lets you read or write individual bytes from a file.
huffman.cc creates a huffman tree and either encodes or decodes symbols based on adaptive Huffman coding
endoder.cc takes filename as a command-line argument. It reads and compresses the file into an output file of
the same name with a .comp suffix.
decoder.cc takes in a filename, reads it, and decompressed it into a file with 
the same name and a .plaintext suffix. 
