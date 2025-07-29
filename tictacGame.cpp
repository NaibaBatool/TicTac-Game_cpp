#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool isPair(vector<vector<int>> mat)
{
    // in col
    for (int i = 0; i < 3; i++)
    {
        if (mat[0][i] != 0 && mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i])
            return true;
    }

    // in row
    for (int j = 0; j < 3; j++)
    {
        if (mat[j][0] != 0 && mat[j][0] == mat[j][1] && mat[j][1] == mat[j][2])
            return true;
    }

    // in diagnol
    if (mat[0][0] != 0 && mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2])
        return true;
    if (mat[0][2] != 0 && mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])
        return true;
    return false;
}
class TicTac
{
    int player1, player2;
    int score1, score2;
    vector<vector<int>> Matrix;

public:
    TicTac(int play1, int play2) : player1(play1), player2(play2), score1(0), score2(0)
    {
        Matrix = vector<vector<int>>(3, vector<int>(3, 0));
        loadScore();
    }
    void resetBoard()
    {
        Matrix = vector<vector<int>>(3, vector<int>(3, 0));
    }

    bool GameDraw()
    {
        if (isPair(Matrix))
            return false;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (Matrix[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    void makeMove(int Player)
    {
        int rowNum, colNum;
        cout << "Enter the row and column(0-2): \n";
        cin >> rowNum >> colNum;

        if (rowNum >= 0 && rowNum <= 2 && colNum >= 0 && colNum <= 2)
        {
            if (Matrix[rowNum][colNum] == 0)
            {
                Matrix[rowNum][colNum] = Player;
            }
            else
            {
                cout << "That cell is already occupied!\n";
                makeMove(Player);
            }
        }
        else
        {
            cout << "Invalid input. Try again\n";
            makeMove(Player);
        }
    }
    void DisplayBoard()
    {
        cout << "Game Board\n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                char PlayerChar = (Matrix[i][j] == 1) ? 'X' : (Matrix[i][j] == 2) ? 'O'
                                                                                  : '.';
                cout << PlayerChar;
                if (j < 2)
                    cout << " | ";
            }
            cout << endl;
            if (i < 2)
                cout << "--+---+--\n";
        }
    }
    void loadScore()
    {
        ifstream in("PlayersScore.txt");
        if (in)
        {
            in >> score1 >> score2;
        }
        in.close();
    }
    void saveScore()
    {
        ofstream out("PlayersScore.txt");
        out << score1 << " " << score2;
        out.close();
    }
    void playGame()
    {
        char playAgain;
        do
        {
            resetBoard();
            int currentPlayer = 1;

            while (true)
            {
                DisplayBoard();
                makeMove(currentPlayer);

                if (isPair(Matrix))
                {
                    DisplayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    if (currentPlayer == 1)
                        score1++;
                    else
                        score2++;
                    saveScore();
                    break;
                }
                else if (GameDraw())
                {
                    DisplayBoard();
                    cout << "Game is draw!\n";
                    break;
                }

                currentPlayer = (currentPlayer == player1) ? player2 : player1;
            }

            cout << "\nCurrent Scores:\n";
            cout << "Player 1 score: " << score1 << "\n";
            cout << "Player 2 score: " << score2 << "\n";

            cout << "\nDo you want to play another round? (y/n): ";
            cin >> playAgain;

        } while (playAgain == 'y' || playAgain == 'Y');

        cout << "\nFinal Scores:\n";
        cout << "Player 1 score: " << score1 << "\n";
        cout << "Player 2 score: " << score2 << "\n";
        cout << "Thanks for playing!\n";
    }
};
int main()
{
    cout << "Welcome to TicTac Game!\n";

    string p1, p2;
    cout << "Player 1 name: ";
    getline(cin, p1);
    cout << "Player 2 name: ";
    getline(cin, p2);
    TicTac t(1, 2);
    t.playGame();
}