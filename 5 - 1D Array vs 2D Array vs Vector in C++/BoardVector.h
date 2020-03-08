#ifndef BOARDVECTOR_H_
#define BOARDVECTOR_H_

#include "AbstractBoard.h"

namespace Tugay{
	class BoardVector :public AbstractBoard {
		private:
			vector<vector<int>> board;
		public:
			int readFromFile(const string text);
			void print();
			bool move(const char direction);
			void writeToFile(const string text);
			void reset();
			void setSize(int c, int r);
			bool isSolved();
			int operator () (int y, int x){	return board[y][x]; }

			int zero_y_coor();
			int zero_x_coor();
			int getColumn(){	return column;	}
			int getRow(){	return row;	}
	};
}

#endif