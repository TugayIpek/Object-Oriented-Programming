#include "NPuzzle.h"

using namespace std;

void NPuzzle::game(){

	char direction;
	string text;
	int finish = 0;
	int tot_mov = 0;
	int control = 0;
	int int_move = 0;
	int max = 0;
	int N = 0;

	cout << "Your initial random board is" << endl;
	while(finish == 0 && (direction != 'Q' && direction != 'q' )){ 	//main while loop
		print();
		
		cout << "Your move : ";
		cin >> direction;

		if (direction == 'V' || direction == 'v'){
			tot_mov += solvePuzzle();
		}
		else if (direction == 'T' || direction == 't'){
			printReport();
		}
		else if (direction == 'E' || direction == 'e'){
			cout << "Filename to save : ";
			cin >> text;
			writeToFile(text);
			cout << "Succesfully. File is saved." << endl;
		}
		else if (direction == 'O' || direction == 'o'){
			cout << "Filename to load : ";
			cin >> text;
			readFromFile(text);
		}
		else if (direction == 'I' || direction == 'i'){
			
			control = 0;
			int_move = moveIntelligent();	//if move is possible, it returns intelligent move (L,R,U,D)
			
			if (int_move <= 0){
				int_move = moveRandom();	//if move is possible, it returns random move (L,R,U,D)
			}

			if(int_move == 1){
    			control = move('L');
    			cout << "Intelligent move chooses L" << endl;
	    	}
	    	else if(int_move == 2){
	    		control = move('R');
	    		cout << "Intelligent move chooses R" << endl;
	    	}
	    	else if(int_move == 3){
	    		control = move('U');
	    		cout << "Intelligent move chooses U" << endl;
	    	}
	    	else if(int_move == 4){
	    		control = move('D');
	    		cout << "Intelligent move chooses D" << endl;
	    	}
	    	board.setPreMove(int_move);
			if(control == 0); 
			else tot_mov++;
		}
		else if (direction == 'S' || direction == 's'){
			reset();
			N = board.getColumn()*board.getRow();	//N is calculated with row and column
			suffle(N);
			tot_mov = 0;
		}
		else{
			control = move(direction);
			if(control == 0);
			else tot_mov++;
		}
		
		finish = board.isSolved();		//If solved, it returns 1 and game is finished
		if(finish == 1){
			print();
			cout	<< "Problem Solved!"
					<< endl
					<< "Total number of moves " << tot_mov
					<< endl;
		}
		else board.setTotalMove(tot_mov);
	}
}
int NPuzzle::Board::readFromFile(string text){		//reads from file and creats game board array
	string cursor;

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
				board[i][k] = -2;
			}
		}
		for (auto i = 0; !load.eof(); ++i)		//goes to end of file
		{
			for (auto k = 0; load.peek() != '\n' && !load.eof(); ++k)	//goes to until end of row
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
				row = k+1;
			}
			if (load.peek() == '\n' && !load.eof())		// if it is not eof, it is skip '\n' character
			{
			 	load.ignore(1);
			}	 
			column = i;
		}
		load.close();		// it closes file
		return 1;
	}
}
void NPuzzle::Board::writeToFile(string text){		//takes games board array and a filename, writes to file its
	
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
void NPuzzle::Board::reset(){	//first filling function to board
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
void NPuzzle::Board::reset_goal(){		//reset for goal board
	int number = 0;
	int last_index = 0;

	for (int k = row-1; k > 0; --k)
	{
		if(goal_board[column-1][k] < -1);
		else {
			last_index = k;
			break;
		}
	}
	for (auto i = 0; i < column; ++i)
	{
		for (auto k = 0; k < row ; ++k)
		{
			if(goal_board[i][k] == -2);
			else if(i == column-1 && k == last_index){
				goal_board[i][k] = 0;
			}
			else {
				number++;
				goal_board[i][k] = number;
			}
		}	
	}
}
void NPuzzle::suffle(int N){		//suffle function of final board
	 
    int r_num = 0;
    int control = 0;
    int moves = 0;
    int pre_num = 0;
	
	while (moves < N)		//this part suffles size x size times
	{	
		pre_num = r_num;
		r_num = (rand()%4)+1;		//creates random number for random move
		//this part checks move loops
		if(r_num == 1 && pre_num != 2){
			control = move('L');
			if(control == 1) moves++;
		}
		else if (r_num == 2 && pre_num != 1){
			control = move('R');
			if(control == 1) moves++;
		}
		else if (r_num == 3 && pre_num != 4){
			control = move('U');
			if(control == 1) moves++;
		}
		else if (r_num == 4 && pre_num != 3){
			control = move('D');
			if(control == 1) moves++;
		}
	}
}
void NPuzzle::Board::print(){		//prints board
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
void NPuzzle::printReport(){		//
	int tot_mov = board.getTotalMove();
	cout <<endl<< tot_mov << " moves were made." <<endl
	<< "Puzzle is not yet solved." <<endl<<endl;
}
void NPuzzle::Board::setSize(int c, int r){
	column = c;
	row = r;
}
int NPuzzle::solvePuzzle(){
	int max = 0;
	int control = 0;
	int int_move = 0;
	int finish = 0;
	while(finish != 1 && max != 100000){
		
		int_move = moveIntelligent();

		if (int_move <= 0){
			int_move = moveRandom();
		}

		if(int_move == 1){
			control = move('L');
			cout << "Intelligent move chooses L" << endl;
			print();
    	}
    	else if(int_move == 2){
    		control = move('R');
    		cout << "Intelligent move chooses R" << endl;
    		print();
    	}
    	else if(int_move == 3){
    		control = move('U');
    		cout << "Intelligent move chooses U" << endl;
    		print();
    	}
    	else if(int_move == 4){
    		control = move('D');
    		cout << "Intelligent move chooses D" << endl;
    		print();
    	}
    	board.setPreMove(int_move);
		
		if(control == 0);
		else	max++;
		
		finish = board.isSolved();
	}
	if (finish != 1)
		cout << "Could not be solved, you can try again." << endl << endl;
	return max;
}
	
int NPuzzle::Board::isSolved(){		//checks the board from initial to goal
	int check = 1;								//and if board is goal board return 1
	for (auto i = 0; i < 9; ++i)
	{
		for (auto k = 0; k < 9; ++k)
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
int NPuzzle::Board::move(char direction){		//takes direction and if move is possible, it makes move
	int temp = 0;
	int control = 0;		

	zero_y_coor();
	zero_x_coor();

	if ((direction ==  'L' || direction == 'l') && 
		zero_x > 0 && board[zero_y][zero_x-1] >= 0)
	{
		temp = board[zero_y][zero_x-1];
		board[zero_y][zero_x-1] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}
	if ((direction == 'R' || direction == 'r') &&
		zero_x < row-1 && board[zero_y][zero_x+1] >= 0)
	{
		temp = board[zero_y][zero_x+1];
		board[zero_y][zero_x+1] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}
	if ((direction == 'U' || direction == 'u') &&
		zero_y > 0 && board[zero_y-1][zero_x] >= 0)
	{
		temp = board[zero_y-1][zero_x];
		board[zero_y-1][zero_x] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}
	if ((direction == 'D' || direction == 'd') &&
		zero_y < column-1 && board[zero_y+1][zero_x] >= 0)
	{
		temp = board[zero_y+1][zero_x];
		board[zero_y+1][zero_x] = 0;
		board[zero_y][zero_x] = temp;
		control = 1;
	}

	zero_y_coor();
	zero_x_coor();
	
	return control;
}
int NPuzzle::moveIntelligent(){		//intelligent move function

    int l = -81,r = -81, u = -81, d = -81;
    int x_coor = 0, y_coor = 0;
	int r_num = 0;
    int number = 0;
    
    int zero_x = board.zero_x_coor();
	int zero_y = board.zero_y_coor();
	int column = board.getColumn();
	int row = board.getRow();
	int pre_move = board.getPreMove();

    //this part basicly calculates manhattan distance and desicion to move
    
    if (zero_x - 1 >= 0 && board.getBoardElement(zero_y,zero_x-1) > 0)	//if it can go to left
    {
    	number = board.getBoardElement(zero_y,zero_x-1);
		
		for (auto i = 0; i < column; ++i)
	    {
	    	for (auto k = 0; k < row; ++k)
	    	{
	    		if (board.getGoalElement(i,k) == number)
	    		{
	    			y_coor = i;
	    			x_coor = k;
	    			break;
	    		}
	    	}
	    }

		l = abs(zero_x-1 - x_coor) - abs(zero_x - x_coor);
    }
    if (zero_x + 1 < row && board.getBoardElement(zero_y,zero_x+1) > 0)		//if it can go to right
    {
    	number = board.getBoardElement(zero_y,zero_x+1);
		
			for (auto i = 0; i < column; ++i)
		    {
		    	for (auto k = 0; k < row; ++k)
		    	{
		    		if (board.getGoalElement(i,k) == number)
		    		{
		    			y_coor = i;
		    			x_coor = k;
		    			break;
		    		}
		    	}
		    }

		r = abs(zero_x+1 - x_coor) - abs(zero_x - x_coor);
    }
    if (zero_y - 1 >= 0 && board.getBoardElement(zero_y-1,zero_x) > 0)		//if it can go to up
    {
    	number = board.getBoardElement(zero_y-1,zero_x);
		
	    for (auto i = 0; i < column; ++i)
	    {
	    	for (auto k = 0; k < row; ++k)
	    	{
	    		if (board.getGoalElement(i,k) == number)
	    		{
	    			y_coor = i;
	    			x_coor = k;
	    			break;
	    		}
	    	}
	    }

		u = abs(zero_y-1 - y_coor) - abs(zero_y - y_coor);
    }
    if (zero_y + 1 < board.getBoardElement(zero_y+1,zero_x) > 0)		//if it can go to up
    {
    	number = board.getBoardElement(zero_y+1,zero_x);
		
	    for (auto i = 0; i < column; ++i)
	    {
	    	for (auto k = 0; k < row; ++k)
	    	{
	    		if (board.getGoalElement(i,k) == number)
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
    else	return 0;// else, there is no logical move
    
}
int NPuzzle::moveRandom(){
	int zero_x = board.zero_x_coor();
	int zero_y = board.zero_y_coor();
	int r_num = 0;
	while (1)	 
	{	
		r_num = (rand()%4)+1;		//creates random number for random move
		//this part checks move loops
		if(r_num == 1 && board.getBoardElement(zero_y,zero_x-1) > 0)
			return 1;
		else if (r_num == 2 && board.getBoardElement(zero_y,zero_x+1) > 0)
			return 2;
		else if (r_num == 3 && board.getBoardElement(zero_y-1,zero_x) > 0)
			return 3;
		else if (r_num == 4 && board.getBoardElement(zero_y+1,zero_x) > 0)
			return 4;
	}
}
int NPuzzle::Board::zero_y_coor(){		// ordinate of zero coordinate
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
int NPuzzle::Board::zero_x_coor(){		// axis of zero coordinate
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
void NPuzzle::Board::copy_board(){
	for (auto i = 0; i < 9; ++i)
	{
		for (auto k = 0; k < 9; ++k)
		{
			goal_board[i][k] = board[i][k];
		}
	}
}
void NPuzzle::Board::fill_board(){
	for (auto i = 0; i < 9; ++i){
		for (auto k = 0; k < 9; ++k){
			board[i][k] = -1;
		}
	}
}