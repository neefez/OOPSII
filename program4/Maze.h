// You must properly comment, and remove all my "commentary".
// Remember, comment blocks go on the method in here (the H file).

#pragma once      // This is insetad of the "#ifndef guard"

// Needed for gcroot declaration:  allow use of GC class in non-GC class
#include <vcclr.h>   

#include <fstream>



using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Maze
{
public:

	//---------------------------------------------------------------------
	// Constructor; Sets panel to be drawn on, reads in the maze file
	// and determines if it's valid.
	//---------------------------------------------------------------------
	Maze(Panel ^ drawingPanel, ifstream & ifs);

	//---------------------------------------------------------------------
	// Returns true if the maze is valid, false if not.
	//---------------------------------------------------------------------
	bool IsValid() const { return valid; }

	//---------------------------------------------------------------------
	// Returns true if the maze has been solved, false if it has not.
	//---------------------------------------------------------------------
	bool IsFree() const { return free; }

	//---------------------------------------------------------------------
	// Solves the maze - converts xPixel and yPixel to cell coordinates and
	// passes them to RecSolve.
	//---------------------------------------------------------------------
	void Solve(int xPixel, int yPixel);

	void ShowOriginal() { Show(orig); }

	void ShowSolved() { Show(solved); }


private:

	static const int CELLSIZE = 16; // Width and height of a maze cell
	static const int MAXSIZE = 30;  // Maximum width and height of maze

	static const char OPEN = 'O';    // Traversable tile
	static const char DEADEND = '+'; // Nontraversable tile
	static const char EXIT = 'E';    // Exit (win condition)
	static const char START = 'S';   // Starting tile
	static const char VISITED = 'X'; // Visited tile

	int width, height;          // Size of maze
	bool free;                    // Has the maze been solved?
	bool valid;                   // Is Maze Valid?

	gcroot<Panel ^> panel;        // Panel on which to show the Maze.

	char orig[MAXSIZE][MAXSIZE];    // Original Maze Data
	char solved[MAXSIZE][MAXSIZE];  // "Solved" Maze Data

	//---------------------------------------------------------------------
	// Recursively solves the maze. Sets free to true if the maze was
	// solved, false if it was not.
	//---------------------------------------------------------------------
	void RecSolve(int row, int col);

	void Show(char cells[][MAXSIZE]);
};
