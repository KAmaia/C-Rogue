#include <stdio.h>
#include <ncurses.h>
#include <vector>

#include "../include/world.h"
#include "../include/tileloader.h"
#include "../include/worldgen.h"
#include "../include/renderer.h"

//methods.
void initialize();
void handleInput(int);
void updateDisplay();
void drawWorld(std::vector<char>);
void exit();

//vars
bool running = false;
bool paused = true;
int ticks = 0;
int ROWS, COLS;
renderer rndr;
world gameWorld;
worldgen wGen;

tileLoader tl;

int main(){
	initialize();
	gameWorld.setTile(10,3,'.');
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
	//pre-adjust these
	ROWS -=1;
	COLS -=1;
	raw();
	nodelay(stdscr, true);
	noecho();
	keypad(stdscr, TRUE);
	rndr = renderer();
	wGen = worldgen(ROWS+ 5 , COLS - 5);
	gameWorld = wGen.generateworld();
	running = true;
}

void updateDisplay(){
	//get a rendered frame;
	std::vector<char>render = rndr.renderFrame(ROWS, COLS, gameWorld);
	drawWorld(render);
	mvprintw(ROWS - 1, 0,"%i", ticks); 
	refresh();
}

void drawWorld(std::vector<char> render){
	for(int y = 0; y < ROWS - 1; y++){
		for(int x = 0; x < COLS - 1; x++){
			mvaddch(y,x,render[y*COLS + x]);
		}
	}
}

void exit(){
	endwin();
}
