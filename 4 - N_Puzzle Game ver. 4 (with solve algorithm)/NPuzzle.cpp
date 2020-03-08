#include "NPuzzle.h"

using namespace std;

void NPuzzle::game(){

	char direction;
	string text;
	int finish = 0;
	int tot_mov = 0;
	int control = 0;
	int max = 0;
	int N = 0;
	
	cout << "Your initial random board is" << endl;
	while(finish == 0 && (direction != 'Q' && direction != 'q' )){ 	//main while loop
		print();
		vecBoard.clear();
		vecBoard.push_back(objBoard);
		
		cout << "Your move : ";
		cin >> direction;

		if (direction == 'V' || direction == 'v'){
			solvePuzzle();
			tot_mov += objBoard.numberOfMoves();
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
			vecBoard.clear();
			vecBoard.push_back(objBoard);
		}
		else if (direction == 'S' || direction == 's'){
			reset();
			N = objBoard.getColumn()*objBoard.getRow();	//N is calculated with row and column
			shuffle(N);
			vecBoard.clear();
			vecBoard.push_back(objBoard);
			tot_mov = 0;
		}
		else{
			control = move(direction);
			if(control == 0);
			else tot_mov++;
		}
		
		finish = objBoard.isSolved();		//If solved, it returns 1 and game is finished
		if(finish == 1){
			print();
			cout	<< "Problem Solved!"
					<< endl
					<< "Total number of moves " << tot_mov
					<< endl;
		}
		else objBoard.setTotalMove(tot_mov);
	}
}
ostream& operator << (ostream &oS, const NPuzzle &puzzle){
	int column;
	column = puzzle.objBoard.getColumn();
	int row = puzzle.objBoard.getRow();
	oS<<endl;
	for (int i = 0; i < column; ++i)
	{
		for (int k = 0; k < row; ++k)
		{	
			if(puzzle.objBoard(i,k) != 0){
				if(puzzle.objBoard(i,k) < 0)
					oS << "00 ";
				else if(puzzle.objBoard(i,k) > 9)
					oS << puzzle.objBoard(i,k) << " ";
				else 
					oS << "0" << puzzle.objBoard(i,k) << " ";
			}	
			else	oS << "bb ";
		}
		oS <<endl;
	}
	oS <<endl;
	return oS;
}
istream& operator >> (istream &iS, const NPuzzle &puzzle){
	return iS;	
}
int NPuzzle::solvePuzzle(){
	bool check = false;
	int boards = 0;

	for (int i = 0; check != true; ++i)
	{	
		if(check != true) check = isPossible(vecBoard[i], 'R');
		if(check != true) check = isPossible(vecBoard[i], 'L');
		if(check != true) check = isPossible(vecBoard[i], 'U');
		if(check != true) check = isPossible(vecBoard[i], 'D');
		boards = i;
	}
	
	shortCut();
	objBoard.setNumberOfBoards(boards);
}
bool NPuzzle::isPossible(NPuzzle::Board Copy, char direction){
	int push = 1;
	
	if(Copy.move(direction) == true){
		for (int i = 0; i < vecBoard.size(); ++i){
			if(vecBoard[i] == Copy){
				push = 0;
				i = vecBoard.size();
			}
		}
		if(push == 1){
			Copy.setLastMove(direction);
			vecBoard.push_back(Copy);
		}
	}
	if(Copy.isSolved() == true) return true;
	else return false;
}
void NPuzzle::shortCut(){
	vector<char> moves;
	Board objTemp;

	objTemp = vecBoard[vecBoard.size() - 1];

	for (int i = 0; objTemp.lastMove() != 'S'; ++i)
	{
		moves.push_back(objTemp.lastMove());
		if (objTemp.lastMove() == 'R')
			objTemp.move('L');
		else if (objTemp.lastMove() == 'L')
			objTemp.move('R');
		else if (objTemp.lastMove() == 'U')
			objTemp.move('D');
		else if (objTemp.lastMove() == 'D')
			objTemp.move('U');
		for (int k = 0; k < vecBoard.size(); ++k)
		{
			if(objTemp == vecBoard[k]){
				objTemp = vecBoard[k];
				k = vecBoard.size();
			}
		}
	}
	objBoard.setNumberOfMoves(moves.size());
	//print solve
	for (int i = moves.size()-1; i >= 0; --i){
		objBoard.move(moves[i]);
		cout << moves.size()-i<< "nd move of the solution."<<"("<< moves[i] << ")" <<endl;
		objBoard.print();
		
	}
}
bool NPuzzle::Board::move(char direction){		//takes direction and if move is possible, it makes move
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
int NPuzzle::moveRandom(){
	int zero_x = objBoard.zero_x_coor();
	int zero_y = objBoard.zero_y_coor();
	int r_num = 0;
	while (1)	 
	{	
		r_num = (rand()%4)+1;		//creates random number for random move
		//this part checks move loops
		if(r_num == 1 && objBoard.getBoardElement(zero_y,zero_x-1) > 0)
			return 1;
		else if (r_num == 2 && objBoard.getBoardElement(zero_y,zero_x+1) > 0)
			return 2;
		else if (r_num == 3 && objBoard.getBoardElement(zero_y-1,zero_x) > 0)
			return 3;
		else if (r_num == 4 && objBoard.getBoardElement(zero_y+1,zero_x) > 0)
			return 4;
	}
}
int NPuzzle::Board::readFromFile(string text){		//reads from file and creats game board array
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

		board.resize(column, vector<int>(row));

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
void NPuzzle::shuffle(int N){		//shuffle function of final board
	 
    int r_num = 0;
    int control = 0;
    int moves = 0;
    int pre_num = 0;
	
	while (moves < N*2)		//this part shuffles size x size times
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
void NPuzzle::printReport(){		//
	int tot_mov = objBoard.getTotalMove();
	cout <<endl<< tot_mov << " moves were made." <<endl
	<< "Puzzle is not yet solved." <<endl<<endl;
}
void NPuzzle::Board::setSize(int c, int r){
	column = c;
	row = r;
	board.resize(column,vector<int>(row));
}	
bool NPuzzle::Board::isSolved(){		//checks the board from initial to goal
	if(board == goal_board)
		return true;
	else	
		return false;
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
	goal_board.resize(column, vector<int>(row));
	goal_board = board;
}