#ifndef BOARDARRAY2D_H_
#define BOARDARRAY2D_H_

#include "AbstractBoard.h"

namespace Tugay{
	class BoardArray2D :public AbstractBoard{
		private:
			int** board = nullptr;
		public:
			int readFromFile(const string text);
			void print();
			bool move(const char direction);
			void writeToFile(const string text);
			void reset();
			void setSize(int c, int r);
			bool isSolved();
			int operator () (int y, int x){	return board[y][x]; }

			~BoardArray2D(){
				for (int i = 0; i < column; ++i)
				{
					delete [] board[i];
				}
				delete [] board;
			}
			int zero_y_coor();
			int zero_x_coor();
	};
}
#endif