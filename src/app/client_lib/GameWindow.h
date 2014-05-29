/*
 * GameWindow.h
 *
 *  Created on: May 18, 2014
 *      Author: klis
 */

#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include "Grid.h"
#include "GlutFunctions.h"
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <GL/glui.h>
#include <map>
#include <string>

/*
 * Class using Signleton pattern, because there can be only one window to
 * display game content
 *
 */

class GameWindow: public Grid, public GlutFunctions{
public:
	static GameWindow& getInstance();

	void init();
//	void display(Grid& grid);
	void display1();
	void display2();
//	void reshape(int w, int h);
	void myGlutIdle();
//	void mouseFunc(int button, int state, int x, int y, Grid& grid);
	void mouseFunc1(int button, int state, int x, int y);
	void mouseFunc2(int button, int state, int x, int y);

//	void drawSquares(GLenum mode, Grid& grid);
//	void processHits(GLint hits, GLuint buffer[], Grid& grid);
	void initMyGlut();
	void createGLUI();
	void startGameWindow(int argc, char *argv[]);

	static void displayWrapper1();
	static void displayWrapper2();
	static void idleWrapper();
	static void reshapeWrapper(int w, int h);
	static void mouseFuncWrapper1(int button, int state, int x, int y);
	static void mouseFuncWrapper2(int button, int state, int x, int y);

	void setShipsQuantity(std::map<int,int>& configuration);
	void addLineToShipsToAdd(int shipSize, int quantity);

private:
	GameWindow();
	GameWindow(const GameWindow&) = delete;
	GameWindow& operator=(const GameWindow&) = delete;

	Grid grid1_;
	Grid grid2_;

	int mainWindow_;
//	GLUI* glui_;
//
	int pickedX_;
	int pickedY_;

	int shipSize_;
	int horizontal_;

	std::map<int,int> shipsQuantity_;
	std::string shipsToAdd_;

};
#endif /* GAMEWINDOW_H_ */