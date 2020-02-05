#include <iostream>
#include <fstream>

#include "compressor.hpp" 


int main( void ){	
   lz_compressor< 4096 > compressor;
 
   std::ifstream input;
   input.open( "wilhelmus.txt" );
   std::ofstream output;
   output.open( "compressed.asm" );

   // Check whether input file is opened correctly
   if( ! input.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   // Check whether output file is opened correctly
   if( ! output.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }

   // Compress input file into output file

   output << ".global compressed\n.data\n\ncompressed:\n\t.ascii \"";

   compressor.compress( 
      [ &input ]()-> int { auto c = input.get(); return input.eof() ? '\0' : c; },
      [ &output ]( char c ){ output << c;  }
   );

   output << "\"\"";
   
   input.close();
   output.close();
}