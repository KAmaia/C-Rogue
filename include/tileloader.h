#ifndef tileloader_h
#define tileloader_h

#include <fstream>
#include <iostream>
#include <vector>

#include "tile.h"

class tileLoader{

	public:
		std::vector<tile> getTileTypes();
		bool openFile(const char*);
	
	private:
		std::fstream tileFile;
		std::vector<tile> tileTypes;		
};
#endif
