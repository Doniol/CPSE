compressor: generator.cpp compressor.hpp wilhelmus.txt
	g++ -std=c++17 generator.cpp compressor.hpp -o compressor
	./compressor
	rm ./compressor
	make run
