/**
 * This class is a abstract base class for BoardArray1D and BoardArray1D classes.
 * Has many methods for many operations.
 */

import java.io.FileNotFoundException;
import java.io.IOException;

public abstract class AbstractBoard
{
    protected int column;
    protected int row;
    protected int zero_y;
    protected int zero_x;
    protected char last_move;
    protected int Moves;
    protected int Boards;
    public AbstractBoard()
    {
        column = 0;
        row = 0;
        zero_y = 0;
        zero_x = 0;
        last_move = 'S';
        Moves = 0;
        Boards = 0;
    }
    public abstract String toString();
    public abstract int readFromFile(String text) throws FileNotFoundException;
    public abstract void writeToFile(String text) throws IOException;
    public abstract void reset();
    public abstract void setSize(int c, int r);
    public abstract boolean move(char direction);
    public abstract boolean isSolved();

    public abstract int zero_y_coor();
    public abstract int zero_x_coor();

    int getColumn(){	return column;	}
    int getRow(){	return row;	}
    int NumberOfBoards(){	return Boards;	}
    char lastMove(){	return last_move;	}
    int numberOfMoves(){	return Moves;	}
}
