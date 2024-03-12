#include <iostream>
#include <vector>
using namespace std;

void initVector(vector<char> &);   

int convertPosition(char);      

bool validPlacement(const vector<char> &, int);   

bool gameWon(const vector<char> &);

bool boardFull(const vector<char> &);  

int getPlay(const vector<char> &);    

void drawBoard(const vector<char> &);  

const bool CLEAR_SCREEN = true;
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main()
{
    vector<char> board(9);  
    int curPlay;             

    initVector(board);
    drawBoard(board);

    int turn = PLAYER1;
    do
    {
        curPlay = getPlay(board);

        if(turn == PLAYER1)
        {
            board[curPlay] = 'x';
            turn = PLAYER2;
        }
        else if(turn == PLAYER2)
        {
            board[curPlay] = 'o';
            turn = PLAYER1;
        }

        drawBoard(board);
    }
    while(!(boardFull(board) || gameWon(board)));

    if(gameWon(board) && turn == PLAYER1)
    {
        cout << "Player 2 wins!!\n";
    }
    else if(gameWon(board) && turn == PLAYER2)
    {
        cout << "Player 1 wins!!\n";
    }
    else
    {
        cout << "No one wins.\n";
    }

    return 0;
}

void initVector(vector<char> &v)  
{
    int first = 'a';
    for(unsigned int i = 0; i < 9; i++)
    {
        char let = static_cast<char>(first + i);
        v.insert(v.begin() + i, let);
    }
}

int convertPosition(char position) 
{
    return position - 'a';
}

bool validPlacement(const vector<char> &board, int position)    
{
    if(position < 9 && position >= 0)
    {
        if(board[position] != 'x' && board[position] != 'o')
            return true;
    }
    return false;
}

bool gameWon(const vector<char> &board)   
{
    char x = 'x', o = 'o';
    for(unsigned int i = 0, k = 0; i < 3; i++, k += 3)
    {
        if((board[i] == x && board[i + 3] == x && board[i + 6] == x) 
        || (board[k] == x && board[k + 1] == x && board[k + 2] == x)
        || (board[i] == o && board[i + 3] == o && board[i + 6] == o)
        || (board[k] == o && board[k + 1] == o && board[k + 2] == o))
            return true;
    }
    int i = 0, k = 2;
    if((board[i] == x && board[i + 4] == x && board[i + 8] == x) 
    || (board[k] == x && board[k + 2] == x && board[k + 4] == x)
    || (board[i] == o && board[i + 4] == o && board[i + 8] == o)
    || (board[k] == o && board[k + 2] == o && board[k + 4] == o))
        return true;
    return false;
}

bool boardFull(const vector<char> &board)  
{
    for(unsigned int i = 0; i < 9; i ++)
    {
        if(board[i] != 'x' && board[i] != 'o')
            return false;
    }
    return true;
}

int getPlay(const vector<char> &board)  
{
    char let;
    int pos;
    do
    {
        cout << "Please choose a position: ";
        cin >> let;
        pos = convertPosition(let);
    }
    while(!validPlacement(board, pos));
    return pos;
}

void drawBoard(const vector<char> &board) 
{
    for(int i = 0; i < 9; i += 3)
    {
        cout << "  " << board.at(i) << "  |  ";
        cout << board.at(i + 1) << "  |  ";
        cout << board.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}