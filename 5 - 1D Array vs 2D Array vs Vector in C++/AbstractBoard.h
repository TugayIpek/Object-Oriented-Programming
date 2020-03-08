#ifndef ABSTRACTBOARD_H_
#define ABSTRACTBOARD_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

namespace Tugay{
	class AbstractBoard{
		protected:
			int column;
			int row;
			int zero_y;
			int zero_x;
			char last_move;
			int Moves;
			int Boards;
		public:
			AbstractBoard(){		//No parameter constructor
				column = 0;
				row = 0;
				zero_y = 0;
				zero_x = 0;
				last_move = 'S';
				Moves = 0;
				Boards = 0;
			}
			virtual int readFromFile(const string text) = 0;
			virtual void print() = 0;
			virtual void writeToFile(const string text) = 0;
			virtual void reset() = 0;
			virtual void setSize(int c, int r) = 0;
			virtual bool isSolved() = 0;
			virtual bool move(const char direction) = 0;
			virtual int operator () (int y, int x) = 0; 
			bool operator==(AbstractBoard &obj);
			
			virtual int zero_y_coor() = 0;
			virtual int zero_x_coor() = 0;
		  	/*  int getColumn(){	return column;	}
			int getRow(){	return row;	}*/
			
			/*
			int NumberOfBoards(){	return Boards;	}
			char lastMove(){	return last_move;	}
			int numberOfMoves(){	return Moves;	}*/
	};
}
#endif /*ABSTRACTBOARD_H_*/