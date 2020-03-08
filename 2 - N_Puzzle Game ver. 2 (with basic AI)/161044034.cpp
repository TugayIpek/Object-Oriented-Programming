#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void game(int board[][9],int column,int line);
void load_from_file(string text);
void save_to_file(int board[][9], string text,int column,int line);
int intelligent(int board[][9],int goal_board[][9], int column, int line, int zero_y, int zero_x, int pre_move);
void suffle(int board[][9], int column, int line);
int check_goal(int board[][9],int goal_board[][9]);
void final_board(int board[][9], int column, int line);
void copy_board(int board[][9],int goal_board[][9]);
int left(int board[][9], int size, int zero_y, int zero_x);
int right(int board[][9], int size, int zero_y, int zero_x);
int up(int board[][9], int size, int zero_y, int zero_x);
int down(int board[][9], int size, int zero_y, int zero_x);
int zero_y_coor(int board[][9], int column, int line);
int zero_x_coor(int board[][9], int column, int line);
void print_board(int board[][9],int column, int line);

int main(int argc, char** argv)
{
	srand((unsigned)time(0));
	if(argc == 1){		//if just there is one argument, starts first game (N-Puzzle)
		int board[9][9];
		int size = 0;
		for (int i = 0; i < 9; ++i){
			for (int k = 0; k < 9; ++k){
				board[i][k] = -1;
			}
		}
		while(size < 3 || size > 9) {		//while loop for take right number
		cout << "Please enter the problem size" << endl;
		cin >> size;
		}
		final_board(board, size,size);		//first filling of board
		suffle(board,size,size);		//for random initial board
		game(board,size,size);
	}
	else if(argc == 2) load_from_file(argv[1]);		//if there is second argument, reads from file
	else cout << argv[2] << ": wrong command line { too inputs }" <<endl;	//if there are many argument gives error message
	
	return 0;
}
void game(int board[][9],int column,int line){

	string direction;
	string text;
	int goal_board[9][9];
	int zero_x = 0, zero_y = 0;
	int finish = 0;
	int tot_mov = 0;
	int control = 0;
	int int_move = 0;
	int pre_move = 0;
	int max = 0;

	copy_board(board,goal_board);
	final_board(goal_board,column,line);
	cout << "Your initial random board is" << endl;
	while(finish == 0 && (direction != "Q" && direction != "q")){ 	//main while loop
		print_board(board,column,line);
		zero_y = zero_y_coor(board,column,line);
		zero_x = zero_x_coor(board,column,line);

		cout << "Your move : ";
		cin >> direction;
		if (direction == "L" || direction == "l"){
			control = left(board, line, zero_y, zero_x);
			if(control == 0);
			else tot_mov++;
		}
		else if (direction == "R" || direction == "r"){
			control = right(board, line, zero_y, zero_x);
			if(control == 0);
			else tot_mov++;
		}
		else if (direction == "U" || direction == "u"){
			control = up(board, column, zero_y, zero_x);
			if(control == 0);
			else tot_mov++;
		}
		else if (direction == "D" || direction == "d"){
			control = down(board, column, zero_y, zero_x);
			if(control == 0); 
			else tot_mov++;
		}
		else if (direction == "S" || direction == "s"){
			final_board(board,column,line);
			suffle(board, column,line);
			tot_mov = 0;
		}
		else if (direction == "E" || direction == "e"){
			cout << "Filename to save : ";
			cin >> text;
			save_to_file(board,text,column,line);
			cout << "Succesfully. File is saved." << endl;
		}
		else if (direction == "Y" || direction == "y"){
			cout << "Filename to load : ";
			cin >> text;
			load_from_file(text);
			direction = "Q";
		}
		else if (direction == "T" || direction == "t"){
			cout <<endl<< tot_mov << " moves were made." <<endl
			<< "Puzzle is not yet solved." <<endl<<endl;
		}
		else if (direction == "I" || direction == "i"){
			control = 0;
			int_move = intelligent(board,goal_board, column,line, zero_y, zero_x,pre_move);
			if(int_move == 1){
    			control = left(board, line, zero_y, zero_x);
    			cout << "Intelligent move chooses L" << endl;
	    	}
	    	else if(int_move == 2){
	    		control = right(board, line, zero_y, zero_x);
	    		cout << "Intelligent move chooses R" << endl;
	    	}
	    	else if(int_move == 3){
	    		control = up(board, column, zero_y, zero_x);
	    		cout << "Intelligent move chooses U" << endl;
	    	}
	    	else if(int_move == 4){
	    		control = down(board, column, zero_y, zero_x);
	    		cout << "Intelligent move chooses D" << endl;
	    	}
	    	pre_move = int_move;
			if(control == 0); 
			else if(int_move > 0) tot_mov++;
		}
		else if (direction == "V" || direction == "v"){
			max = 0;
			control = 0;
			while(finish != 1 && max != 100000){
				zero_y = zero_y_coor(board,column,line);
				zero_x = zero_x_coor(board,column,line);
				
				int_move = intelligent(board,goal_board, column,line, zero_y, zero_x,pre_move);
				
				if(int_move == 1){
	    			control = left(board, line, zero_y, zero_x);
	    			cout << "Intelligent move chooses L" << endl;
	    			print_board(board,column,line);
		    	}
		    	else if(int_move == 2){
		    		control = right(board, line, zero_y, zero_x);
		    		cout << "Intelligent move chooses R" << endl;
		    		print_board(board,column,line);
		    	}
		    	else if(int_move == 3){
		    		control = up(board, column, zero_y, zero_x);
		    		cout << "Intelligent move chooses U" << endl;
		    		print_board(board,column,line);
		    	}
		    	else if(int_move == 4){
		    		control = down(board, column, zero_y, zero_x);
		    		cout << "Intelligent move chooses D" << endl;
		    		print_board(board,column,line);
		    	}
		    	pre_move = int_move;
				
				if(control == 0);
				else if(int_move > 0){
					tot_mov++;
					max++;
				} 
				
				finish = check_goal(board,goal_board);
			}
			if (finish != 1)
				cout << "Could not be solved, you can try again." << endl << endl;
		}
		finish = check_goal(board,goal_board);
		if(finish == 1){
			print_board(board,column,line);
			cout	<< "Problem Solved!"
					<< endl
					<< "Total number of moves " << tot_mov
					<< endl;		
		}
	}
}
void load_from_file(string text){		//reads from file and creats game board array
	int board[9][9];
	string cursor;
	int line = 0, column = 0; 

	ifstream load;
	load.open(text);

	if (load.is_open() != 1) 		//if user enters wrong filename, gives error message
	{
		cout << "No such file !" << endl;
	}
	else{
		for (int i = 0; i < 9; ++i){
			for (int k = 0; k < 9; ++k){
				board[i][k] = -1;
			}
		}
		for (int i = 0; !load.eof(); ++i)		//goes to end of file
		{
			for (int k = 0; load.peek() != '\n' && !load.eof(); ++k)	//goes to until end of line
			{
				load >> cursor; 
				
				if(!load.eof()){
					if(cursor == "00"){
						board[i][k] = -2;
					}
					else{
						if (cursor == "bb"){
							board[i][k] = 0;
						}
						else{
							board[i][k] = stoi(cursor);
						}
					}
				}
				line = k+1;
			}
			if (load.peek() == '\n' && !load.eof())		// if it is not eof, it is skip '\n' character
			{
			 	load.ignore(1);
			}	 
			column = i;
		}
		load.close();		// it closes file
		game(board,column,line);	// and goes to game function
	}
}
void save_to_file(int board[][9], string text,int column,int line){		//takes games board array and a filename, writes to file its
	
	ofstream save;
	save.open(text);

	for (int i = 0; i < column; ++i)	// goes to end of colums
	{
		for (int k = 0; k < line; ++k)	//goes to end of lines
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
			
			if(k != line-1)
				save << " ";
		}
		save << "\n";	
	}
	save.eof();		//makes end of file process
	save.close();	// and it closes
}
int intelligent(int board[][9],int goal_board[][9], int column, int line, int zero_y, int zero_x,int pre_move){		//intelligent move function

    int l = -81,r = -81, u = -81, d = -81;
    int x_coor = 0, y_coor = 0;
	int r_num = 0;
    int number = 0;
    //this part basicly calculates manhattan distance and desicion to move
    if (zero_x - 1 >= 0 && board[zero_y][zero_x-1] > 0)	//if it can go to left
    {
    	number = board[zero_y][zero_x-1];
		
		for (int i = 0; i < column; ++i)
	    {
	    	for (int k = 0; k < line; ++k)
	    	{
	    		if (goal_board[i][k] == number)
	    		{
	    			y_coor = i;
	    			x_coor = k;
	    			break;
	    		}
	    	}
	    }

		l = abs(zero_x-1 - x_coor) - abs(zero_x - x_coor);
    }
    if (zero_x + 1 < line && board[zero_y][zero_x+1] > 0)		//if it can go to right
    {
    	number = board[zero_y][zero_x+1];
		
			for (int i = 0; i < column; ++i)
		    {
		    	for (int k = 0; k < line; ++k)
		    	{
		    		if (goal_board[i][k] == number)
		    		{
		    			y_coor = i;
		    			x_coor = k;
		    			break;
		    		}
		    	}
		    }

		r = abs(zero_x+1 - x_coor) - abs(zero_x - x_coor);
    }
    if (zero_y - 1 >= 0 && board[zero_y-1][zero_x] > 0)		//if it can go to up
    {
    	number = board[zero_y-1][zero_x];
		
	    for (int i = 0; i < column; ++i)
	    {
	    	for (int k = 0; k < line; ++k)
	    	{
	    		if (goal_board[i][k] == number)
	    		{
	    			y_coor = i;
	    			x_coor = k;
	    			break;
	    		}
	    	}
	    }

		u = abs(zero_y-1 - y_coor) - abs(zero_y - y_coor);
    }
    if (zero_y + 1 < column && board[zero_y+1][zero_x] > 0)		//if it can go to up
    {
    	number = board[zero_y+1][zero_x];
		
	    for (int i = 0; i < column; ++i)
	    {
	    	for (int k = 0; k < line; ++k)
	    	{
	    		if (goal_board[i][k] == number)
	    		{
	    			y_coor = i;
	    			x_coor = k;
	    			break;
	    		}
	    	}
	    }

		d = abs(zero_y+1 - y_coor) - abs(zero_y - y_coor);
    }

    if(l > r && l > u && l > d && pre_move != 2){	//if logical move is left
    	return 1;
    }
    else if (r > l && r > u && r > d && pre_move != 1){	//if logical move is right
    	return 2;
    }
    else if (u > l && u > r && u > d && pre_move != 4){	//if logical move is up
    	return 3;
    }
    else if (d > l && d > r && d > u && pre_move != 3){		//if logical move is down
    	return 4;
    }
    else if(l > 0 && (l == r || l == d || l == u)){		// if there is equality between moves
    	r_num = (rand()%2)+1;
    	if (l == r){
    		if(r_num == 1) return 1;
    		else return 2;
    	}
    	else if (l == u){
    		if(r_num == 1) return 1;
    		else return 3;
    	}
    	else if (l == d){
    		if(r_num == 1) return 1;
    		else return 4;
    	}
    }
    else if(r > 0 && (r == l || r == u || r == d)){
    	r_num = (rand()%2)+1;
    	if (r == l){
    		if(r_num == 1) return 2;
    		else return 1;
    	}
    	else if (r == u){
    		if(r_num == 1) return 2;
    		else return 3;
    	}
    	else if (r == d){
    		if(r_num == 1) return 2;
    		else return 4;
    	}
    }
    else if(u > 0 && (u == l || u == r || u == d)){
    	r_num = (rand()%2)+1;
    	if (u == l){
    		if(r_num == 1) return 3;
    		else return 1;
    	}
    	else if (u == r){
    		if(r_num == 1) return 3;
    		else return 2;
    	}
    	else if (u == d){
    		if(r_num == 1) return 3;
    		else return 4;
    	}
    }
    else if(d > 0 && (d == l || d == r || d == u)){
    	r_num = (rand()%2)+1;
    	if (d == l){
    		if(r_num == 1) return 4;
    		else return 1;
    	}
    	else if (d == r){
    		if(r_num == 1) return 4;
    		else return 2;
    	}
    	else if (d == u){
    		if(r_num == 1) return 4;
    		else return 3;
    	}
    }
    else	// else, there is no logical move
    {	
    	while (1)	 
		{	
			r_num = (rand()%4)+1;		//creates random number for random move
			
			//this part checks move loops
			if(r_num == 1 && board[zero_y][zero_x-1] > 0 && l != -81)
				return 1;
			else if (r_num == 2 && board[zero_y][zero_x+1] > 0 && r != -81)
				return 2;
			else if (r_num == 3 && board[zero_y-1][zero_x] > 0 && u != -81)
				return 3;
			else if (r_num == 4 && board[zero_y+1][zero_x] > 0 && d != -81)
				return 4;
		}
    }
}
void suffle(int board[][9], int column, int line){		//suffle function of final board
	 
    int r_num = 0,pre_num = 0;
    int zero_y = 0, zero_x = 0;
    int control = 0;
    int move = 0;
	
	while (move < column*line)		//this part suffles size x size times  
	{	
		zero_y = zero_y_coor(board,column,line);
		zero_x = zero_x_coor(board,column,line);
		
		pre_num = r_num;
		r_num = (rand()%4)+1;		//creates random number for random move
		//this part checks move loops
		if(r_num == 1 && pre_num != 2){
			control = left(board, line, zero_y, zero_x);
			if(control == 1) move++;
		}
		else if (r_num == 2 && pre_num != 1){
			control = right(board, line, zero_y, zero_x);
			if(control == 1) move++;
		}
		else if (r_num == 3 && pre_num != 4){
			control = up(board, column, zero_y, zero_x);
			if(control == 1) move++;
		}
		else if (r_num == 4 && pre_num != 3){
			control = down(board, column, zero_y, zero_x);
			if(control == 1) move++;
		}
	}
}
int check_goal(int board[][9],int goal_board[][9]){		//checks the board from initial to goal
	int check = 1;								//and if board is goal board return 1
	for (int i = 0; i < 9; ++i)
	{
		for (int k = 0; k < 9; ++k)
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
void final_board(int board[][9], int column, int line){	//first filling function to board
	int number = 0;
	int last_index = 0;

	for (int k = line-1; k > 0; --k)
	{
		if(board[column-1][k] < -1);
		else {
			last_index = k;
			break;
		}
	}
	for (int i = 0; i < column; ++i)
	{
		for (int k = 0; k < line ; ++k)
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
void copy_board(int board[][9],int goal_board[][9]){
	for (int i = 0; i < 9; ++i)
	{
		for (int k = 0; k < 9; ++k)
		{
			goal_board[i][k] = board[i][k];
		}
	}
}
int left(int board[][9], int size, int zero_y, int zero_x){		//left move fuction
	int temp = 0;
	int control = 0;
	if (zero_x > 0 && board[zero_y][zero_x-1] >= 0)
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
	if (zero_x < size-1 && board[zero_y][zero_x+1] >= 0)
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
	if (zero_y > 0 && board[zero_y-1][zero_x] >= 0)
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
	if (zero_y < size-1 && board[zero_y+1][zero_x] >= 0)
	{
		temp = board[zero_y+1][zero_x];
		board[zero_y+1][zero_x] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}
	
	return control;
}
int zero_y_coor(int board[][9], int column, int line){		// ordinate of zero coordinate
	int zero_y;
	for (int i = 0; i < column; ++i)
		{
		   	for (int k = 0; k < line; ++k)		//founds place of zero
		   	{
		   		if (board[i][k] == 0){
		   			zero_y = i;
		   			break;
		   			} 
		   	}
		}
	return zero_y;
}
int zero_x_coor(int board[][9], int column, int line){		// axis of zero coordinate
	int zero_x;
	for (int i = 0; i < column; ++i)
		{
		   	for (int k = 0; k < line; ++k)		//founds place of zero
		   	{
		   		if (board[i][k] == 0){
		   			zero_x = k;
		   			break;
		   		} 
		   	}
		}
	return zero_x;
}
void print_board(int board[][9],int column, int line){
	for (int i = 0; i < column; ++i)
	{
		for (int k = 0; k < line; ++k)
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