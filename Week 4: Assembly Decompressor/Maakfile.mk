
jerkel: generator.cpp compressor.hpp decompressor.hpp
	g++ -std=c++17 generator.cpp compressor.hpp decompressor.hpp -o compressor
	./compressor
    make clean run;
