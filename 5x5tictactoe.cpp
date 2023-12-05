#include <iostream>

using namespace std;

#include <iostream>0


class TicTacToe
{
private:
    char board[26] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ',' ',' ',' ',' '
            ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
    };
    char current_turn = 'X';
    bool playing = true;
    int state = 0;
    int input;

public:
    void print_board();
    int play_move(int index, char move);
    int check_win(char move);
    void start();
    void rules();
};

int main()
{
    TicTacToe game;
    game.rules();
    game.start();
    return 0;
}
void TicTacToe :: rules()
{
    cout<<"Welcome to 5x5 Tic Tac Toe."<<endl;
    cout<<"First to get five in a row wins"<<endl;
    cout<<"To chose where you want to make your move enter the number that corresponds to the space you want."<<endl;
    cout<<"For example:";
    cout<<endl;
    cout<<"\n | 1 | 2 | 3 | 4 |5";
    cout<<"\n--------------------";
    cout<<"\n | 6 | 7 | 8 | 9 |10";
    cout<<"\n--------------------";
    cout<<"\n |11 |12 |13 |14 |15";
    cout<<"\n--------------------";
    cout<<"\n |16 |17 |18 |19 |20";
    cout<<"\n--------------------";
    cout<<"\n |21 |22 |23 |24 |25";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
}
void TicTacToe :: start()
{
    while (playing == true)
    {
        print_board();
        cout << "Play your move " << current_turn << std::endl;
        cin >> input;
        if(input < 1 || input > 25){
            cout<<"Invalid Input please enter a number between 1 and 25"<<endl;
        }

        if (play_move(input, current_turn) == 0)
        {
            cout << "Box already occupied" << std::endl;
            continue;
        };
        state = check_win(current_turn);
        if (state == 1)
        {
            print_board();
            cout << current_turn << " wins the game!" << std::endl;
            break;
        }
        else if (state == 2)
        {
            cout << "Draw!" << std::endl;
            break;
        };
        current_turn = (current_turn == 'X') ? 'O' : 'X';
    };
};

void TicTacToe :: print_board()
{
    for (int i = 1; i < 26; i++) {
        if (i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 ||
            i == 11 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19 ||
            i == 20 || i == 21 || i == 22
            || i == 23 || i == 24 || i==25) {

            cout << " | ";
        }
        cout << board[i];
        if (i == 5 || i==10 || i==15 || i==20){
            cout << endl;
            cout << "--------------------" << endl;
        }
    }



    cout << endl;
};

int TicTacToe :: play_move(int index, char move)
{
    if (index >= 1 && index < 26)
    {
        if (board[index] == ' ')
        {
            board[index] = move;
            return 1;
        }
    }
    return 0;
};


int TicTacToe ::check_win(char move)
{
    if (
            (board[1] == move && board[2] == move && board[3] == move && board[4] == move && board[5] == move) ||
            (board[6] == move && board[7] == move && board[8] == move && board[9] == move && board[10] == move) ||
            (board[11] == move && board[12] == move && board[13] == move && board[14] == move && board[15] == move) ||
            (board[16] == move && board[17] == move && board[18] == move && board[19] == move && board[20] == move) ||
            (board[21] == move && board[22] == move && board[23] == move && board[24] == move && board[25] == move) ||

            (board[1] == move && board[6] == move && board[11] == move && board[16] == move && board[21] == move) ||
            (board[2] == move && board[7] == move && board[12] == move && board[17] == move && board[22] == move) ||
            (board[3] == move && board[8] == move && board[13] == move && board[18] == move && board[23] == move) ||
            (board[4] == move && board[9] == move && board[14] == move && board[19] == move && board[24] == move) ||
            (board[5] == move && board[10] == move && board[15] == move && board[20] == move && board[25] == move) ||

            (board[1] == move && board[7] == move && board[13] == move && board[19] == move && board[25] == move) ||
            (board[5] == move && board[9] == move && board[13] == move && board[17] == move && board[21] == move))
    {
        return 1;
    }
    else
    {
        bool draw = true;
        for (int i = 1; i < 26; i++)
        {
            if (board[i] == ' ')
            {
                draw = false;
                break;
            }
        }
        if (draw == true)
        {
            return 2;
        }
    }
    return 0;
};
