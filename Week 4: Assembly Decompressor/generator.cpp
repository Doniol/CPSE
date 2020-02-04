#include <iostream>
#include <fstream>

#include "compressor.hpp" 
#include "decompressor.hpp" 


int main( void ){	
   lz_compressor< 4096 > compressor;
 
   std::ifstream input;
   input.open( "wilhelmus.txt" );
   std::ofstream output;
   output.open( "compressed.asm" );

   // Check whether input file opens correctly
   if( ! input.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   // Check whether output file open correctly
   if( ! output.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }

   // Write first few lines to output file
   output << ".global compressed\n.rodata\n\ncompressed:\n\t.ascii \"";

   // Compress the desired file and write it to the desired file
   compressor.compress( 
      [ &input ]()-> int { auto c = input.get(); return input.eof() ? '\0' : c; },
      [ &output ]( char c ){ output << c;  }
   );

   output << "\"";
   
   input.close();
   output.close();
   
  
   // Decompress the file and display it using std::cout
   lz_decompressor decompressor;
   decompressor.decompress( 
      [ &input ]()-> int { auto c = input.get(); return input.eof() ? '\0' : c; },
      [ &output ]( char c ){ std::cout << c; }
   );

}