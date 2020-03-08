#include "NPuzzle.h"

using namespace std;

int main(int argc, char** argv)
{
	srand((unsigned)time(0));

	NPuzzle puzzle;
	int isThere = 0; 

	if(argc == 1){		//if just there is one argument, starts Puzzle of HW1
		int size = 0;
		while(size < 3 || size > 9) {		//while loop for take right number
			cout << "Please enter the problem size" << endl;
			cin >> size;
		}
		puzzle.setSize(size,size);
		puzzle.fill_board();	//first filling of board
		puzzle.reset();		
		puzzle.copy_board();
		puzzle.suffle(size*size);	//for random initial board
		puzzle.game();
	}
	else if(argc == 2){		//if there is second argument, reads from file
		isThere = puzzle.readFromFile(argv[1]);
		if(isThere != 0){
			puzzle.copy_board();
			puzzle.reset_goal();
			puzzle.game();	// and goes to game function
		}
	} 
	else cout << argv[2] << ": wrong command row { too inputs }" <<endl;	//if there are many argument gives error message
	
	return 0;
}