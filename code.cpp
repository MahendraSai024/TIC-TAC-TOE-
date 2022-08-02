#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <vector>
#include <string>
using namespace std;

// Step1 : initialize a 3 X 3 board with blank spaces to fill
vector<vector<char>> board(3, vector<char>(3, ' '));

void printBoard()
{
    printf("\n\n>>>  TIC TAC TOE    \n\n");
    cout << "    |    |    "
         << "\n";
    printf(" %c  | %c  | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n");
    cout << "____|____|____"
         << "\n";
    cout << "    |    |    "
         << "\n";
    printf(" %c  | %c  | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n");
    cout << "____|____|____"
         << "\n";
    cout << "    |    |    "
         << "\n";
    printf(" %c  | %c  | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
    cout << "    |    |    "
         << "\n";
    printf("\nPlayer1 : 'X'  </> Player2 : 'O'\n\n");
    return;
}

// Function  to check whether player1 Won ? Tie
bool check_player1()
{
    // Checking diagonals
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    {
        cout << "PLAYER 1 WINS!" << endl;
        cout << "Congratulations Winner" << endl;
        return true;
    }
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
    {
        cout << "PLAYER 1 WINS!" << endl;
        cout << "Congratulations Winner" << endl;
        return true;
    }
    // checking rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
        {
            cout << "PLAYER 1 WINS!" << endl;
            cout << "Congratulations Winner" << endl;
            return true;
            break;
        }
    }
    // checking columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
        {
            cout << "PLAYER 1 WINS!" << endl;
            cout << "Congratulations Winner" << endl;
            return true;
            break;
        }
    }
    return false;
}

// Function  to check whether player2 Won ? Tie
bool check_player2()
{
    // checking diagonals
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {
        cout << "PLAYER 2 WINS!" << endl;
        cout << "Congratulations Winner" << endl;
        return true;
    }
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
    {
        cout << "PLAYER 2 WINS!" << endl;
        cout << "Congratulations Winner" << endl;
        return true;
    }
    // checking rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            cout << "PLAYER 2 WINS!" << endl;
            cout << "Congratulations Winner" << endl;
            return true;
            break;
        }
    }
    // checking columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            cout << "PLAYER 2 WINS!" << endl;
            cout << "Congratulations Winner" << endl;
            return true;
            break;
        }
    }
    return false;
}

vector<int> status = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// Function that makes the change according to the player
void mark(int digit, char x, int &i)
{
    // i is the number from the loop(I can change it when wrong input is given so that the player might get another chance)
    if (digit < 1 && digit > 9)
    {
        cout << "INVALID ENTRY" << endl;
        i = i - 1;
        return;
    }

    if (status[digit - 1] != 0)
    {
        switch (digit)
        {
        case 1:
        {
            board[0][0] = x;
            status[digit - 1] = 0;
            break;
        }
        case 2:
        {
            board[0][1] = x;
            status[digit - 1] = 0;
            break;
        }
        case 3:
        {
            board[0][2] = x;
            status[digit - 1] = 0;
            break;
        }
        case 4:
        {
            board[1][0] = x;
            status[digit - 1] = 0;
            break;
        }
        case 5:
        {
            board[1][1] = x;
            status[digit - 1] = 0;
            break;
        }
        case 6:
        {
            board[1][2] = x;
            status[digit - 1] = 0;
            break;
        }
        case 7:
        {
            board[2][0] = x;
            status[digit - 1] = 0;
            break;
        }
        case 8:
        {
            board[2][1] = x;
            status[digit - 1] = 0;
            break;
        }
        case 9:
        {
            board[2][2] = x;
            status[digit - 1] = 0;
            break;
        }
        default:
        {
            cout << "INVALID MOVE" << endl;
            i = i - 1;
            break;
        }
        }
    }
    else
    {
        // the player made a move that is already been done
        cout << "INVALID MOVE" << endl;
        cout << "Try to enter the digits thats are visible in the Board" << endl;
        i = i - 1;
        return;
    }
}

int main(void)
{
    char count = '1';
    // Intialise the board with numbers so that it becomes easy to place a move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = count;
            count++;
        }
    }

    // printing the board initially(No moves have been done yet)
    // printf("\n\n    TIC TAC TOE     GAME    \n\n");
    printBoard();

    int choice = 0;
    // There can be maximum 9 moves (Worst case - Draw! Match)
    for (int i = 0; i < 9; i++)
    {
        // Always Player1 makes the first move
        if (i % 2 == 0)
        {
            cout << "Player 1('X'): "
                 // player must try to fil the vacant places left
                 << " Enter a number" << endl;
            cin >> choice;
            mark(choice, 'X', i);
            printBoard();
            bool won;
            if (i >= 4)
            {
                won = check_player1();
                if (won == true)
                {
                    
                    sleep(5000);
                    return 0;
                }
                // Player1 makes the last move in worst case so
                else if (i == 8 && won == false)
                {
                    // printBoard();
                    cout << "Draw Match !" << endl;
                    cout << "Well Done both O.< !" << endl;
                    
                    sleep(5000);
                    return 0;
                }
            }
            // based on the value of number entered the Mark 'X' or 'O' will be marked on the board
        }
        else
        {
            cout << "Player 2('O'): "
                 << " Enter a number" << endl;
            cin >> choice;
            mark(choice, 'O', i);
            printBoard();
            bool won;
            if (i >= 4)
            {
                won = check_player1();
                if (won == true)
                {
                    
                    sleep(5000);
                    return 0;
                }
                // Player1 makes the last move in worst case so
                else if (i == 8 && won == false)
                {
                    // printBoard();
                    cout << "Draw Match !" << endl;
                    cout << "Well Done both O.< !" << endl;
                    
                    sleep(5000);
                    return 0;
                }
            }
        }
        // after 4th move there might be a possibilty to win
    }
    
    sleep(5000);
    return 0;
}