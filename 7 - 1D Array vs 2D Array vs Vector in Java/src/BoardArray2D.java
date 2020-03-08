/**
 * This class is derived class of AbstractBoard base class.
 * Has an board and keep a gameboard in an 2D array.
 * @param <T>
 */
import java.io.*;
import java.util.Scanner;


public class BoardArray2D extends AbstractBoard
{
    private int[][] board;
    public final int readFromFile(String text) throws FileNotFoundException { //reads from file and creats game board array
        String cursor;
        int[][] gameboard = new int[9][9];

        File load = new File(text);
        Scanner temper = new Scanner(new BufferedReader( new FileReader(load)));

        for (int i = 0; i < 9; ++i)
        {
            for (int k = 0; k < 9; ++k)
            {
                gameboard[i][k] = -2;
            }
        }
        for (int i = 0; temper.next() != null ; ++i) //goes to end of file
        {
            for (int k = 0; !temper.next().equals('\n') && temper.next() != null; ++k) //goes to until end of row
            {
                cursor = temper.next();

                if (temper != null)
                {
                    if (cursor.equals("00"))
                    {
                        gameboard[i][k] = -2;
                    }
                    else
                    {
                        if (cursor.equals("bb"))
                        {
                            gameboard[i][k] = 0;
                        }
                        else
                        {
                            gameboard[i][k] = Integer.parseInt(cursor);
                        }
                    }
                }
                row = k + 1;
            }
            if (temper.equals('\n') && temper != null) // if it is not eof, it is skip '\n' character
            {
                temper.next();
            }
            column = i;
        }
        temper.close(); // it closes file

        board = new int[column][];

        for (int i = 0; i < column; ++i)
        {
            board[i] = new int[row];
        }

        for (int i = 0; i < column; ++i)
        {
            for (int k = 0; k < row; ++k)
            {
                board[i][k] = gameboard[i][k];
            }
        }

        return 1;
    }
    public boolean move(char direction)
    { //takes direction and if move is possible, it makes move
        int temp = 0;

        zero_y_coor();
        zero_x_coor();

        if ((direction == 'L' || direction == 'l') && zero_x > 0 && board[zero_y][zero_x - 1] >= 0)
        {
            temp = board[zero_y][zero_x - 1];
            board[zero_y][zero_x - 1] = 0;
            board[zero_y][zero_x] = temp;
            return true;
        }
        if ((direction == 'R' || direction == 'r') && zero_x < row - 1 && board[zero_y][zero_x + 1] >= 0)
        {
            temp = board[zero_y][zero_x + 1];
            board[zero_y][zero_x + 1] = 0;
            board[zero_y][zero_x] = temp;
            return true;
        }
        if ((direction == 'U' || direction == 'u') && zero_y > 0 && board[zero_y - 1][zero_x] >= 0)
        {

            temp = board[zero_y - 1][zero_x];
            board[zero_y - 1][zero_x] = 0;
            board[zero_y][zero_x] = temp;
            return true;
        }
        if ((direction == 'D' || direction == 'd') && zero_y < column - 1 && board[zero_y + 1][zero_x] >= 0)
        {
            temp = board[zero_y + 1][zero_x];
            board[zero_y + 1][zero_x] = 0;
            board[zero_y][zero_x] = temp;
            return true;
        }
        zero_y_coor();
        zero_x_coor();

        return false;
    }
    public void writeToFile(String text) throws IOException { //takes games board array and a filename, writes to file its

        File save = new File(text);
        BufferedWriter temp = new BufferedWriter(new FileWriter(save));

        for (int i = 0; i < column; ++i) // goes to end of colums
        {
            for (int k = 0; k < row; ++k) //goes to end of rows
            {
                if (board[i][k] != 0)
                {
                    if (board[i][k] < 0)
                    {
                        temp.write("00");
                    }
                    else if (board[i][k] > 9)
                    {
                        temp.write(board[i][k]);
                    }
                    else
                    {
                        temp.write("00" + board[i][k]);
                    }
                }
                else
                {
                    temp.write("bb");
                }

                if (k != row - 1)
                {
                    temp.write("  ");
                }
            }
            temp.write("\n");
        }
        temp.write("\0");
        temp.close(); // and it closes
    }
    public void reset()
    { //first filling function to board
        int number = 0;
        int last_index = 0;

        for (int k = row - 1; k > 0; --k)
        {
            if (board[column - 1][k] < -1);
            else
            {
                last_index = k;
                break;
            }
        }
        for (int i = 0; i < column; ++i)
        {
            for (int k = 0; k < row ; ++k)
            {
                if (board[i][k] == -2);
                else if (i == column - 1 && k == last_index)
                {
                    board[i][k] = 0;
                }
                else
                {
                    number++;
                    board[i][k] = number;
                }
            }
        }
    }
    public String toString()
    { //prints board
        System.out.print("\n");
        for (int i = 0; i < column; ++i)
        {
            for (int k = 0; k < row; ++k)
            {
                if (board[i][k] != 0)
                {
                    if (board[i][k] < 0)
                    {
                        System.out.print("00 ");
                    }
                    else if (board[i][k] > 9)
                    {
                        System.out.print(board[i][k]);
                        System.out.print(" ");
                    }
                    else
                    {
                        System.out.print("0");
                        System.out.print(board[i][k]);
                        System.out.print(" ");
                    }
                }
                else
                {
                    System.out.print("bb ");
                }
            }
            System.out.print("\n");
        }
        System.out.print("\n");
        return null;
    }
    public void setSize(int c, int r)
    {
        column = c;
        row = r;

        board = new int[column][];

        for (int i = 0 ; i < column; i++)
        {
            board[i] = new int[row];
        }
    }
    public int zero_y_coor()
    { // ordinate of zero coordinate
        for (int i = 0; i < column; ++i)
        {
            for (int k = 0; k < row; ++k) //founds place of zero
            {
                if (board[i][k] == 0)
                {
                    zero_y = i;
                    return zero_y;
                }
            }
        }
        return zero_y;
    }
    public int zero_x_coor()
    { // axis of zero coordinate
        for (int i = 0; i < column; ++i)
        {
            for (int k = 0; k < row; ++k) //founds place of zero
            {
                if (board[i][k] == 0)
                {
                    zero_x = k;
                    return zero_x;
                }
            }
        }
        return zero_x;
    }
    public boolean isSolved()
    { //checks the board from initial to goal
        int number = 0;
        int last_index = 0;

        for (int k = row - 1; k > 0; --k)
        {
            if (board[column - 1][k] < -1);
            else
            {
                last_index = k;
                break;
            }
        }
        for (int i = 0; i < column; ++i)
        {
            for (int k = 0; k < row ; ++k)
            {
                if (board[i][k] == -2);
                else if (i == column - 1 && k == last_index)
                {
                    if (board[i][k] == 0);
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    number++;
                    if (board[i][k] == number);
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
