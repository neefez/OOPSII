#include "stdafx.h"
#include "Maze.h"

Maze::Maze(Panel ^ drawingPanel, ifstream & ifs)
{
	valid = true;
	panel = drawingPanel;

	ifs >> width >> height;

	// Check if width or height are out of bounds
	if (width <= 0 || width > MAXSIZE || 
		height <= 0 || height > MAXSIZE)
	{
		valid = false;
		return;
	}

	// Read in maze
	for (int i = 0; i < height; i++)
	{
		ifs.ignore('\n');
		for (int j = 0; j < width; j++)
			// set maze values and check for eof
			if (!ifs.get(orig[j][i]))
			{
				valid = false;
				break;
			}
		// ensure characters are correct
			else
			{
				char c = orig[j][i];
				if (c != OPEN && c != DEADEND &&
					c != EXIT && c != START && 
					c != VISITED && c != '\n')

				{
					valid = false;
					break;
				}
			}
	}
}

void Maze::Solve(int xPixel, int yPixel)
{
	// copy original maze to solved maze array
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			solved[i][j] = orig[i][j];

	// set free to false and let RecSolve handle it
	free = false;

	// convert pixel position to cell position
	int row = xPixel / CELLSIZE;
	int col = yPixel / CELLSIZE;

	// call RecSolve with converted position
	RecSolve(row, col);
}

void Maze::RecSolve(int row, int col)
{
	// Check if the maze has already been solved
	if (free == true)
		return;

	char tile = solved[row][col];

	// Check for exit
	if (tile == EXIT)
	{
		free = true;
		return;
	}
	
	// Proceed if the tile is open
	if (tile == OPEN)
	{
		solved[row][col] = VISITED;
		// Move +1 x value
		if (row < MAXSIZE)
			RecSolve(row + 1, col);
		// Move +1 y value
		if (col < MAXSIZE)
			RecSolve(row, col + 1);
		// Move -1 x value
		if (row < MAXSIZE)
			RecSolve(row - 1, col);
		// Move -1 y value
		if (col < MAXSIZE)
			RecSolve(row, col - 1);
	}
}