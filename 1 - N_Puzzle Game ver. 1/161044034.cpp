#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void game(int board[][9], int size);
int intelligent(int board[][9], int size, int zero_y, int zero_x, int pre_move);
int left(int board[][9], int size, int zero_y, int zero_x);
int right(int board[][9], int size, int zero_y, int zero_x);
int up(int board[][9], int size, int zero_y, int zero_x);
int down(int board[][9], int size, int zero_y, int zero_x);
int zero_y_coor(int board[][9], int size);
int zero_x_coor(int board[][9], int size);
void suffle(int board[][9], int size);
void initial_random(int board[][9], int size);
int check_goal(int board[][9],int size);
void print_board(int board[][9],int size );

int main()
{
	srand((unsigned)time(0));
	int board[9][9];
	int size = 0;
	game(board,size);
	
	return 0;
}
void game(int board[][9], int size){

	string direction;
	int zero_x = 0, zero_y = 0;
	int finish = 0;
	int tot_mov = 0;
	int control = 0;
	int int_move = 0;
	int pre_move = 0;

	while(size < 3 || size > 9) {		//while loop for take right number
		cout << "Please enter the problem size" << endl;
		cin >> size;
	}
	initial_random(board, size);		//first filling of board
	cout << "Your initial random board is" << endl;
	
	while(finish == 0 && (direction != "Q" && direction != "q")){ 	//main while loop
		print_board(board,size);
		zero_y = zero_y_coor(board,size);
		zero_x = zero_x_coor(board,size);

		cout << "Your move : ";
		cin >> direction;
		if (direction == "L" || direction == "l"){
			control = left(board, size, zero_y, zero_x);
			if(control == 0);
			else tot_mov++;
		}
		else if (direction == "R" || direction == "r"){
			control = right(board, size, zero_y, zero_x);
			if(control == 0);
			else tot_mov++;
		}
		else if (direction == "U" || direction == "u"){
			control = up(board, size, zero_y, zero_x);
			if(control == 0);
			else tot_mov++;
		}
		else if (direction == "D" || direction == "d"){
			control = down(board, size, zero_y, zero_x);
			if(control == 0); 
			else tot_mov++;
		}
		else if (direction == "I" || direction == "i"){
			int_move = intelligent(board, size, zero_y, zero_x,pre_move);
			if(int_move == 1){
    			left(board, size, zero_y, zero_x);
    			cout << "Intelligent move chooses L" << endl;
	    	}
	    	else if(int_move == 2){
	    		right(board, size, zero_y, zero_x);
	    		cout << "Intelligent move chooses R" << endl;
	    	}
	    	else if(int_move == 3){
	    		up(board, size, zero_y, zero_x);
	    		cout << "Intelligent move chooses U" << endl;
	    	}
	    	else if(int_move == 4){
	    		down(board, size, zero_y, zero_x);
	    		cout << "Intelligent move chooses D" << endl;
	    	}
	    	pre_move = int_move;
			tot_mov++;
		}
		else if (direction == "S" || direction == "s"){
			suffle(board, size);
		}
		finish = check_goal(board,size);
		if(finish == 1){
			print_board(board,size); 
			cout	<< "Problem Solved!"
					<< endl
					<< "Total number of moves " << tot_mov
					<< endl;		
		}
	}
}
int intelligent(int board[][9], int size, int zero_y, int zero_x,int pre_move){		//intelligent move function

	int r_num = 0,pre_num = 0;
    int l = -(size*size),r = -(size*size), u = -(size*size), d = -(size*size);
    int x_coor = 0, y_coor = 0;
    int x_diff = 0, y_diff = 0;
    float size_f = (float)size + 0.1;
    int number = 0;

    //this part basicly calculates manhattan distance and desicion to move
    if (zero_x - 1 >= 0)	//if it can go to left
    {
    	number = board[zero_y][zero_x-1];
		
		y_coor = (float)number/size_f;
		x_coor = number - (y_coor)*size - 1;

		l = abs(zero_x-1 - x_coor) - abs(zero_x - x_coor);
    }
    if (zero_x + 1 < size)		//if it can go to right
    {
    	number = board[zero_y][zero_x+1];
		
		y_coor = (float)number/size_f;
		x_coor = number - (y_coor)*size - 1;

		r = abs(zero_x+1 - x_coor) - abs(zero_x - x_coor);
    }
    if (zero_y - 1 >= 0)		//if it can go to up
    {
    	number = board[zero_y-1][zero_x];
		
		y_coor = (float)number/size_f;
		x_coor = number - (y_coor)*size - 1;

		u = abs(zero_y-1 - y_coor) - abs(zero_y - y_coor);
    }
    if (zero_y + 1 < size)		//if it can go to up
    {
    	number = board[zero_y+1][zero_x];
		
		y_coor = (float)number/size_f;
		x_coor = number - (y_coor)*size - 1;

		d = abs(zero_y+1 - y_coor) - abs(zero_y - y_coor);
    }

    if(l >= r && l >= u && l >= d && pre_move != 2){	//if logical move is left
    	return 1;
    }
    else if (r >= l && r >= u && r >= d && pre_move != 1){	//if logical move is right
    	return 2;
    }
    else if (u >= l && u >= r && u >= d && pre_move != 4){	//if logical move is up
    	return 3;
    }
    else if (d >= l && d >= r && d >= u && pre_move != 3){		//if logical move is down
    	return 4;	
    }
    else	// else, there is no logical move
    {	
    	if(l > -(size*size) && pre_move != 2 && pre_move != 1){
    		return 1;
    	}
    	else if(u > -(size*size) && pre_move != 4 && pre_move != 3){
    		return 3;
    	}
    	else if(r > -(size*size) && pre_move != 1 && pre_move != 2){
    		return 2;
    	}
    	else if(d > (size*size) && pre_move != 3 && pre_move != 4){
    		return 4;
    	}
    }

}
void print_board(int board[][9],int size ){		//print function for board
	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size; ++k)
		{	
			if(board[i][k] != 0){
				if(board[i][k] > 9)
					cout << board[i][k] << " ";
				else 
					cout << board[i][k] << "  ";
			}	
			else	cout << "   ";
		}
		cout <<endl;
	}
	cout <<endl;
}
int left(int board[][9], int size, int zero_y, int zero_x){		//left move fuction
	int temp = 0;
	int control = 0;
	if (zero_x > 0)
	{
		temp = board[zero_y][zero_x-1];
		board[zero_y][zero_x-1] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}

	return control;
}
int right(int board[][9], int size, int zero_y, int zero_x){	//right move fuction
	int temp = 0;
	int control = 0;
	if (zero_x < size-1)
	{
		temp = board[zero_y][zero_x+1];
		board[zero_y][zero_x+1] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}

	return control;
}
int up(int board[][9], int size, int zero_y, int zero_x){		////up move fuction
	int temp = 0;
	int control = 0;
	if (zero_y > 0)
	{
		temp = board[zero_y-1][zero_x];
		board[zero_y-1][zero_x] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}

	return control;
}
int down(int board[][9], int size, int zero_y, int zero_x){		//down move fuction
	int temp = 0;
	int control = 0;
	if (zero_y < size-1)
	{
		temp = board[zero_y+1][zero_x];
		board[zero_y+1][zero_x] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}
	
	return control;
}
int zero_y_coor(int board[][9], int size){		// ordinate of zero coordinate
	int zero_y;
	for (int i = 0; i < size; ++i)
		{
		   	for (int k = 0; k < size; ++k)		//founds place of zero
		   	{
		   		if (board[i][k] == 0){
		   			zero_y = i;
		   			break;
		   			} 
		   	}
		}
	return zero_y;
}
int zero_x_coor(int board[][9], int size){		// axis of zero coordinate
	int zero_x;
	for (int i = 0; i < size; ++i)
		{
		   	for (int k = 0; k < size; ++k)		//founds place of zero
		   	{
		   		if (board[i][k] == 0){
		   			zero_x = k;
		   			break;
		   		} 
		   	}
		}
	return zero_x;
}
void suffle(int board[][9], int size){		//suffle function of final board
	 
    int r_num = 0,pre_num = 0;
    int zero_y = 0, zero_x = 0;
    int control = 0;
    int l = 0,r = 0, u = 0, d = 0;
    for (int i = 0; i < 9; ++i)
	{
		for (int k = 0; k < 9; ++k)
		{
			board[i][k] = -1;
		}
	}	
	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size ; ++k)
		{
			if (i < size-1 || k < size-1)
				board[i][k] = (size*i) + k + 1;

			else board[i][k] = 0;
		}	
	}
	for (int i = 0; i < size*size; ++i)		//this part suffles size x size times  
	{	
		zero_y = zero_y_coor(board,size);
		zero_x = zero_x_coor(board,size);
		
		pre_num = r_num;
		r_num = (rand()%4)+1;		//creates random number for random move
		
		//this part checks move loops
		if(r_num == 1 && pre_num != 2)
			control = left(board, size, zero_y, zero_x);	
		else if (r_num == 2 && pre_num != 1)
			control = right(board, size, zero_y, zero_x);
		else if (r_num == 3 && pre_num != 4)
			control = up(board, size, zero_y, zero_x);	
		else if (r_num == 4 && pre_num != 3)
			control = down(board, size, zero_y, zero_x);
		if(control == 0) i--;
	}
}

void initial_random(int board[][9], int size){	//first filling function to board
	for (int i = 0; i < 9; ++i)
	{
		for (int k = 0; k < 9; ++k)
		{
			board[i][k] = -1;
		}
	}	
	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size ; ++k)
		{
			if (i < size-1 || k < size-1)
				board[i][k] = (size*i) + k + 1;

			else board[i][k] = 0;
		}	
	}
	suffle(board,size);		//for random initial board
}
int check_goal(int board[][9],int size){		//checks the board from initial to goal
	int check = 1;								//and if board is goal board return 1
	int goal_board[9][9];
	for (int i = 0; i < 9; ++i)
	{
		for (int k = 0; k < 9; ++k)
		{
			goal_board[i][k] = -1;
		}
	}
	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size ; ++k)
		{
			if (i < size-1 || k < size-1)
				goal_board[i][k] = (size*i) + k + 1;

			else goal_board[i][k] = 0;
		}	
	}
	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size ; ++k)
		{
			if(board[i][k] == goal_board[i][k]){
				check = 1;
			}
			else{
				check = 0;
				return check;
			}
		}	
	}
	return check;
	
}