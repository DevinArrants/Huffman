//implementation of a class that lets you write or read individual bits from 
//an actual file. 
#include "bitio.hh"
#include <cassert>
#include <bitset>
//takes one non null pointer to a stream
//one fo teh pointers passed must be nullptr
//constructor will save this pointer for subsequent I/O
BitIO::BitIO(std::ostream* os, std::istream* is){
      os_ = os;
      is_ = is;
      assert( (os || is) && !(os && is));
      index_ = 0;
      if(os_){buffer_ = 0;}
      else{(*is_).get(buffer_);}
}
BitIO::~BitIO(){
    if(os_ && index_!=0){
       (*os_).put(buffer_); 
    }
}
//takes a single boolean and outputs bit
void BitIO::output_bit(bool bit){
        if(os_){
            buffer_ |= (bit<<index_);
            ++index_;
            if(index_ == 8){
                    (*os_).put(buffer_);
                    index_ = 0;
                    buffer_ = 0;
            }
        }

}

//returns true if next bit is of value 1
//returns false if next bit is of value 0
bool BitIO::input_bit(){
    assert(is_);
    char mask=1;
    mask=mask<<index_;
    bool result = (buffer_ & mask)!=0;
    index_++;
    if(index_ == 8){      
    (*is_).get(buffer_);
    index_=0;
  }
    return result;
}
