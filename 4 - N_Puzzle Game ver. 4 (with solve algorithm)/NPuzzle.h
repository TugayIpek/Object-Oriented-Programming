#ifndef NPUZZLE_H_
#define NPUZZLE_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class NPuzzle{
private:
	class Board{
	private:
		vector<vector<int>> board;
		vector<vector<int>> goal_board;
		int column;
		int row;
		int zero_y;
		int zero_x;
		int total;
		char last_move;
		int Moves;
		int Boards;
	public:
		Board(){		//No parameter constructor
			column = 0;
			row = 0;
			zero_y = 0;
			zero_x = 0;
			total = 0;
			last_move = 'S';
			Moves = 0;
			Boards = 0;
		}
		void print();
		int readFromFile(const string text);
		void writeToFile(const string text);
		void reset();
		void setSize(int c, int r);
		bool move(const char direction);
		bool isSolved();
		char lastMove(){	return last_move;	}
		int numberOfMoves(){	return Moves;	}
		int NumberOfBoards(){	return Boards;	}
		int operator () (int y, int x)const	 {	return board[y][x]; }
		bool operator == (const Board &Obj){
			if(board == Obj.board)	return true;
			else return false;
		}

		//after that; auxiliary functions
		///////////////////////////////////////////////////////////////////////////
		void copy_board();
		int zero_y_coor();
		int zero_x_coor();
		void reset_goal();
		int getColumn()const 	{ return column;}
		int getRow()const 	{ return row;}
		inline int getBoardElement(int y, int x){	return board[y][x];	}
		inline int getGoalElement(int y, int x){	return goal_board[y][x];	}
		inline int getTotalMove(){	return total;	}
		inline void setTotalMove(int tot_mov){	total = tot_mov;	}
		inline void setLastMove(char direction){	last_move = direction;	}
		inline void setNumberOfMoves(int moves) {	Moves = moves;	}
		inline void setNumberOfBoards(int boards) {	Boards = boards;	}
		///////////////////////////////////////////////////////////////////////////
	};
	Board objBoard;
	vector<Board> vecBoard;
public:
	inline void print(){	objBoard.print();	}
	void printReport();
	inline int readFromFile(const string text){	return objBoard.readFromFile(text);	}
	inline void writeToFile(const string text){	objBoard.writeToFile(text);	}
	void shuffle(int N);
	inline void reset(){	objBoard.reset();	}
	inline void setSize(int c,int r){	objBoard.setSize(c,r);	}
	int moveRandom();
	inline bool move(const char direction){	return	objBoard.move(direction);	}
	int solvePuzzle();
	friend ostream& operator << (ostream &oS, const NPuzzle &puzzle);
	friend istream& operator >> (istream &iS, const NPuzzle &puzzle);
	
	//after that; auxiliary functions
	//////////////////////////////////////////////////////////////
	void game();
	inline void copy_board(){	objBoard.copy_board();	}
	inline int zero_y_coor(){	return objBoard.zero_y_coor();	}
	inline int zero_x_coor(){	return objBoard.zero_x_coor();	}
	inline void reset_goal(){	objBoard.reset_goal();	}
	bool isPossible(NPuzzle::Board Copy, char direction);
	void shortCut();
	//////////////////////////////////////////////////////////////
};

#endif /*NPUZZLE_H_*/
