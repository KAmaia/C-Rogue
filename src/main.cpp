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
void drawDebugInfo();
void exit();


//vars
bool running = false;
bool paused = true;
bool debug = false;

int ticks = 0;
int ROWS, COLS;
renderer rndr;
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
		case 'd':
			debug = !debug;
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
	ROWS;
	COLS;
	raw();
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);	
	rndr = renderer();
	wGen = worldgen(11, 100);
	gameWorld = wGen.generateworld();
	rndr.init(ROWS, COLS, gameWorld);
	running = true;
}

void updateDisplay(){
	//clear the screen	
	clear();
	//get a rendered frame;
	vector<vector<char> >render = rndr.renderFrame(gameWorld);
	drawWorld(render);
	//if debug mode is on, show debug info at bottom of screen.	
	if(debug){
		drawDebugInfo();
	}
	//and repaint.
	refresh();
	
}

void drawDebugInfo(){
	mvprintw(ROWS - 1, 0,"ticks: %i, worldHeight: %i, worldWidth: %i, Screen Height: %i, Screen Width %i, CenterRenderY: %i, CenterRenderX: %i",
				ticks, gameWorld.getHeight(), gameWorld.getWidth(),ROWS, COLS, rndr.getCenterRenderY(), rndr.getCenterRenderX()); 
	
}	

void drawWorld(vector<vector<char> > render){
	for(int y = 0; y < ROWS - 1; y++){
		for(int x = 0; x < COLS -1; x++){
			mvaddch(y,x,render[y][x]);
		}
	}
}

void exit(){
	endwin();
}
