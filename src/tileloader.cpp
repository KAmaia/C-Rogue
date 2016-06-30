#include <iostream>
#include <fstream>

#include "../include/tileloader.h"

bool tileLoader::openFile(const char* fileName){
	bool success = false;
	tileFile.open("./test.txt", std::fstream::out|std::fstream::app);
	if(tileFile.is_open()){
		printf("File Opened!\n");
		tileFile.write("test", sizeof("test"));
		tileFile.close();
		success = true;
	}
	else{
		printf("Failed, like the shitty programmer I am.");
	}
	return success;		
}
	
