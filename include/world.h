#ifndef world_h
#define world_h

#include <vector>

#include "tile.h"


class world{
	public:
		world();
		world(int, int);
		void setTile(int, int, char);	
		void setTile(int, int, tile);
		tile getTile(int, int);
		
		int getWidth();
		int getHeight();
		


	private:
		void initTiles();
		std::vector<std::vector<tile> > tileMap;
		int width;
		int height;
};
#endif
