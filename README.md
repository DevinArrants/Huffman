# Huffman
bitio.cc is the implementation of the bitio.hh class that lets you read or write individual bytes from a file.
huffman.cc creates a huffman tree and either encodes or decodes symbols based on adaptive Huffman coding
endoder.cc takes filename as a command-line argument. It reads and compresses the file into an output file of
the same name with a .comp suffix.
decoder.cc takes in a filename, reads it, and decompressed it into a file with 
the same name and a .plaintext suffix. 

# Compression tests 
|File name|Raw file size|Compressed file size|Exact match|
|---|---|---|--- | 
|poem|364|368|yes| 
|art|1030|330|yes|
|beemovie|13486|8154 | yes|
|source.txt| 21093|13818|yes|
|alphabet.txt|77|201|yes|

# Getting Started

Download the Huffman file, Unzip it and place it somewhere easy to get to from your terminal

### Prerequisites

An basic understanding of using terminal

### Installing and Building

Download the files, use make file to compile, run ./encoder (filename) to compress and ./decoder (filename).comp to decompress
## Design Choices
## Authors

* **Becca Luff** - *Initial work* - [BeccaLuff](https://github.com/BeccaLuff)
* **Devin Arrants** - *Initial work* - [DevinArrants](https://github.com/DevinArrants)

