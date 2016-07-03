#include <stdio.h>
#include <ncurses.h>
#include <vector>

#include "../include/world.h"
#include "../include/tileloader.h"
#include "../include/worldgen.h"
#include "../include/renderer.h"

using std::vector;

//methods.
void initialize();
void handleInput(int);
void updateDisplay();
void drawWorld(vector<vector<char> >);
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
	gameWorld.setTile(ROWS, 0, '-');
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
		case KEY_DOWN:
			rndr.moveCenterDown();
			break;
		case KEY_UP:
			rndr.moveCenterUp();
			break;
		case KEY_LEFT:
			rndr.moveCenterLeft();
			break;
		case KEY_RIGHT:
			rndr.moveCenterRight();
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
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	rndr = renderer();
	wGen = worldgen(80,100);
	gameWorld = wGen.generateworld();
	rndr.init(ROWS, COLS, gameWorld);
	running = true;
}

void updateDisplay(){
	//get a rendered frame;
	vector<vector<char> >render = rndr.renderFrame(gameWorld);
	drawWorld(render);
	mvprintw(ROWS, 0,"%i", ticks); 
	refresh();
}

void drawWorld(vector<vector<char> > render){
	for(int y = 0; y < ROWS; y++){
		for(int x = 0; x < COLS; x++){
			mvaddch(y,x,render[y][x]);
		}
	}
}

void exit(){
	endwin();
}
