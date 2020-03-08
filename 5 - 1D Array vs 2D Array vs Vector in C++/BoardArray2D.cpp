#include "BoardArray2D.h"
namespace Tugay{
	int BoardArray2D::readFromFile(string text){		//reads from file and creats game board array
		string cursor;
		int gameboard[9][9];
		ifstream load;
		load.open(text);
		
		if (load.is_open() != 1) 		//if user enters wrong filename, gives error message
		{
			cout << "No such file !" << endl;
			return 0;
		}
		else{
			for (auto i = 0; i < 9; ++i){
				for (auto k = 0; k < 9; ++k){
					gameboard[i][k] = -2;
				}
			}
			for (auto i = 0; !load.eof(); ++i)		//goes to end of file
			{
				for (auto k = 0; load.peek() != '\n' && !load.eof(); ++k)	//goes to until end of row
				{
					load >> cursor; 
					
					if(!load.eof()){
						if(cursor == "00"){
							gameboard[i][k] = -2;
						}
						else{
							if (cursor == "bb"){
								gameboard[i][k] = 0;
							}
							else{
								gameboard[i][k] = stoi(cursor);
							}
						}
					}
					row = k+1;
				}
				if (load.peek() == '\n' && !load.eof())		// if it is not eof, it is skip '\n' character
				{
				 	load.ignore(1);
				}	 
				column = i;
			}
			load.close();		// it closes file

			board = new int*[column];

			for(int i = 0; i < column; ++i){
				board[i] = new int[row];
			}

			for (auto i = 0; i < column; ++i)
			{
				for (auto k = 0; k < row; ++k)
				{
					board[i][k] = gameboard[i][k];
				}
			}
			
			return 1;
		}
	}
	bool BoardArray2D::move(char direction){		//takes direction and if move is possible, it makes move
		int temp = 0;		

		zero_y_coor();
		zero_x_coor();

		if ((direction ==  'L' || direction == 'l') && 
			zero_x > 0 && board[zero_y][zero_x-1] >= 0)
		{
			temp = board[zero_y][zero_x-1];
			board[zero_y][zero_x-1] = 0;
			board[zero_y][zero_x] = temp;
			return true;
		}
		if ((direction == 'R' || direction == 'r') &&
			zero_x < row-1 && board[zero_y][zero_x+1] >= 0)
		{
			temp = board[zero_y][zero_x+1];
			board[zero_y][zero_x+1] = 0;
			board[zero_y][zero_x] = temp;
			return true;
		}
		if ((direction == 'U' || direction == 'u') &&
			zero_y > 0 && board[zero_y-1][zero_x] >= 0)
		{
			
			temp = board[zero_y-1][zero_x];
			board[zero_y-1][zero_x] = 0;
			board[zero_y][zero_x] = temp;
			return true;
		}
		if ((direction == 'D' || direction == 'd') &&
			zero_y < column-1 && board[zero_y+1][zero_x] >= 0)
		{
			temp = board[zero_y+1][zero_x];
			board[zero_y+1][zero_x] = 0;
			board[zero_y][zero_x] = temp;
			return true;
		}
		zero_y_coor();
		zero_x_coor();
		
		return false;
	}
	void BoardArray2D::writeToFile(string text){		//takes games board array and a filename, writes to file its
		
		ofstream save;
		save.open(text);

		for (auto i = 0; i < column; ++i)	// goes to end of colums
		{
			for (auto k = 0; k < row; ++k)	//goes to end of rows
			{	
				if(board[i][k] != 0){
					if(board[i][k] < 0)
						save << "00";
					else if(board[i][k] > 9)
						save << board[i][k];
					else 
						save << "0" << board[i][k];
				}	
				else	save << "bb";
				
				if(k != row-1)
					save << " ";
			}
			save << "\n";	
		}
		save.eof();		//makes end of file process
		save.close();	// and it closes
	}
	void BoardArray2D::reset(){	//first filling function to board
		int number = 0;
		int last_index = 0;

		for (int k = row-1; k > 0; --k)
		{
			if(board[column-1][k] < -1);
			else {
				last_index = k;
				break;
			}
		}
		for (auto i = 0; i < column; ++i)
		{
			for (auto k = 0; k < row ; ++k)
			{
				if(board[i][k] == -2);
				else if(i == column-1 && k == last_index){
					board[i][k] = 0;
				}
				else {
					number++;
					board[i][k] = number;
				}
			}	
		}
	}
	void BoardArray2D::print(){		//prints board
		cout <<endl;
		for (auto i = 0; i < column; ++i)
		{
			for (auto k = 0; k < row; ++k)
			{	
				if(board[i][k] != 0){
					if(board[i][k] < 0)
						cout << "00 ";
					else if(board[i][k] > 9)
						cout << board[i][k] << " ";
					else 
						cout << "0" << board[i][k] << " ";
				}	
				else	cout << "bb ";
			}
			cout <<endl;
		}
		cout <<endl;
	}
	void BoardArray2D::setSize(int c, int r){
		column = c;
		row = r;
		
		board = new int*[column];

		for(int i = 0 ; i < column; i++){
			board[i] = new int[row];
		}
	}	
	int BoardArray2D::zero_y_coor(){		// ordinate of zero coordinate
		for (auto i = 0; i < column; ++i)
		{
		   	for (auto k = 0; k < row; ++k)		//founds place of zero
		   	{
		   		if (board[i][k] == 0){
		   			zero_y = i;
		   			return zero_y;
		   		} 
		   	}
		}
	}
	int BoardArray2D::zero_x_coor(){		// axis of zero coordinate
		for (auto i = 0; i < column; ++i)
		{
		   	for (auto k = 0; k < row; ++k)		//founds place of zero
		   	{
		   		if (board[i][k] == 0){
		   			zero_x = k;
		   			return zero_x;
		   		}
		   	}
		}
	}
	bool BoardArray2D::isSolved(){		//checks the board from initial to goal
		int number = 0;
		int last_index = 0;

		for (int k = row-1; k > 0; --k)
		{
			if(board[column-1][k] < -1);
			else {
				last_index = k;
				break;
			}
		}
		for (auto i = 0; i < column; ++i)
		{
			for (auto k = 0; k < row ; ++k)
			{
				if(board[i][k] == -2);
				else if(i == column-1 && k == last_index){
					if(board[i][k] == 0);
					else return false;
				}
				else {
					number++;
					if(board[i][k] == number);
					else return false;
				}
			}	
		}
		return true;
	}
}