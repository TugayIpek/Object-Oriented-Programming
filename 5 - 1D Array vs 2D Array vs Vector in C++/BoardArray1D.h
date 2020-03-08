#ifndef BOARDARRAY1D_H_
#define BOARDARRAY1D_H_

#include "AbstractBoard.h"

namespace Tugay{
	class BoardArray1D :public AbstractBoard{
		private:
			int* board = nullptr;
		public:
			int readFromFile(const string text);
			void print();
			void writeToFile(const string text);
			void reset();
			void setSize(int c, int r);
			bool move(const char direction);
			bool isSolved();
			int operator () (int y, int x){	return board[y*column + x]; }

			~BoardArray1D(){
				delete [] board;
			}
			int zero_y_coor();
			int zero_x_coor();
	};
}
#endif