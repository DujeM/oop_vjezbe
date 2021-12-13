#include "Board.h"
#include <iostream>
#include <string>
#include <vector>
#include "Point.h"

using namespace std;

Board::Board(int cols, int rows, char border)
{
	board = new char*[rows];

	setX(rows);
	setY(cols);

	for (int i = 0; i < x; i++)
	{
		board[i] = new char[y];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if ((i == 0 || i == x-1) || (j == 0 || j == y-1))
			{
				board[i][j] = border;
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
}

Board::Board(const Board &b)
{

}

void Board::draw_line(Point p1, Point p2, char ch) 
{

	while (p1.x <= p2.x && p1.y <= p2.y)
	{
		board[p1.x][p1.y] = ch;

		if (p1.x < x ) 
		{
			p1.x++;
		}

		if (p1.y < y)
		{
			p1.y++;
		}
	}
	
}

void Board::display()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

void Board::setX(int rows)
{
	x = rows;
}

int Board::getX()
{
	return x;
}

void Board::setY(int cols)
{
	y = cols;
}

int Board::getY()
{
	return y;
}