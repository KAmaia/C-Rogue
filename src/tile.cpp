#include "../include/tile.h"

tile::tile(){
	tileChar = '.';
}

tile::tile(char tileChar){
	this->tileChar = tileChar;
}

char tile::getChar(){
	return tileChar;
}

void tile::setChar(char c){
	tileChar = c;
}
