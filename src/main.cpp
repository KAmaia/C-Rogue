#include <stdio.h>
#include <ncurses.h>

#include "../include/world.h"
#include "../include/tileloader.h"
#include "../include/worldgen.h"

//methods.
void initialize();
void handleInput(int);
void updateDisplay();
void drawWorld();
void exit();

//vars
bool running = false;
bool paused = true;
int ticks = 0;
int ROWS, COLS;
world gameWorld;
worldgen wGen;

tileLoader tl;

int main(){
	initialize();
	//gameloop
	while(running == true){
		if(paused){
			//menu logic
		}
		else{
			//game logic
		}
		//handle input
		int ch = getch();
		handleInput(ch);
		ticks++;
		//update display
		updateDisplay();
		
	}
	exit();	
	return 0;
}	

void handleInput(int keyCode){
	switch(keyCode){
		case 27:
			running = false;
			break;
		default:
			//do nothing;
			break;	
	}
}		

void initialize(){
	initscr();
	getmaxyx(stdscr, ROWS, COLS);
	raw();
	nodelay(stdscr, true);
	noecho();
	keypad(stdscr, TRUE);
	wGen = worldgen();
	gameWorld = wGen.generateworld();
	running = true;
}

void updateDisplay(){
	int brrrt = ROWS - 1;
	drawWorld();
	mvprintw(1, 0, "%i, %i", ROWS, COLS);
	mvprintw(brrrt, 0,"%i", ticks); 
	refresh();
}

void drawWorld(){
	/*
	 *
	 * This method is totally wrong.  World is currently set to
	 * be generated 10x10 tiles, so, for right now, we can see if 
	 * we're drawing to the screen.  
	 *
	 */
	for(int y = 0; y < gameWorld.getWidth(); y++ ){
		for(int x = 0; x < gameWorld.getHeight(); x++){
			mvaddch( y, x, gameWorld.getTile(y, x).getChar()); 
		}
	}
}

void exit(){
	endwin();
}
