#ifndef NPUZZLE_H_
#define NPUZZLE_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

class NPuzzle{
private:
	class Board{
	private:
		int board[9][9];
		int goal_board[9][9];
		int column = 0;
		int row = 0;
		int zero_y = 0;
		int zero_x = 0;
		int pre_move = 0;
		int total = 0;
	public:
		void print();
		int readFromFile(const string text);
		void writeToFile(const string text);
		void reset();
		void setSize(int c, int r);
		int move(const char direction);
		int isSolved();
		
		//after that; auxiliary functions
		void copy_board();
		int zero_y_coor();
		int zero_x_coor();
		void fill_board();
		void reset_goal();
		inline int getColumn(){ return column;}
		inline int getRow(){ return row;}
		inline int getPreMove(){ return pre_move;	}
		inline void setPreMove(int int_move){	pre_move = int_move;	}
		inline int getBoardElement(int y, int x){	return board[y][x];	}
		inline int getGoalElement(int y, int x){	return goal_board[y][x];	}
		inline int getTotalMove(){	return total;	}
		inline void setTotalMove(int tot_mov){	total = tot_mov;	}
	};
	Board board;
public:
	inline void print(){	board.print();	}
	inline int readFromFile(const string text){	return board.readFromFile(text);	}
	inline void writeToFile(const string text){	board.writeToFile(text);	}
	void suffle(int N);
	inline void reset(){	board.reset();	}
	inline int move(const char direction){	return	board.move(direction);	}
	inline void setSize(int c,int r){	board.setSize(c,r);	}
	int moveIntelligent();
	int moveRandom();
	int solvePuzzle();
	void printReport();
	
	//after that; auxiliary functions
	void game();
	inline void copy_board(){	board.copy_board();	}
	inline int zero_y_coor(){	return board.zero_y_coor();	}
	inline int zero_x_coor(){	return board.zero_x_coor();	}
	inline void fill_board(){	board.fill_board();	}
	inline void reset_goal(){	board.reset_goal();	}
};

#endif /*NPUZZLE_H_*/
