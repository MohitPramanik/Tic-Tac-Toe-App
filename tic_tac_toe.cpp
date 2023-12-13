#include <iostream>
using namespace std;

class game
{
private:
    string player1, player2;
    char position[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // for all positions of board so that player can give their input to reflect it on board
    int index;                                                        // index positions of gameboard
    char play_again;

public:
    int moves = 0; // to check whether all 9 moves are done or not
    void welcomeMessage();
    void gameRule();
    void setPlayerName();
    void gameName();
    void gameBoard();
    void isWin();
    void playAgain();      // to ask weather players want to play again or not
    int ifAlreadyFilled(); // to check if the position on the board already filled or not
    void play();
};

void game::welcomeMessage()
{
    system("Color 9");
    cout << "\n\n\n";
    cout << "\t\t\t\t\t\t\t __________________________\n";
    cout << "\t\t\t\t\t\t\t|                          |\n";
    cout << "\t\t\t\t\t\t\t|  Welcome to Tic-Tac-Toe  |\n";
    cout << "\t\t\t\t\t\t\t|__________________________|\n\n\n\n\n\n";
}

void game::gameRule()
{
    system("cls");
    cout << "  Rules: " << endl;
    cout << "\t"
         << "1. Enter the position number to put your character on the game board." << endl
         << "\t"
         << "2. The player 1 will get a chance to play first." << endl
         << "\t"
         << "3. Player whose characters will be on one line either horizontally,\n\t   vertically or diagonally will win this match." << endl;
    getchar();
}

void game::setPlayerName()
{
    cout << "\t\t\t\t\t\t\tPlayer 1 : ";
    cin >> player1;
    cout << "\n\t\t\t\t\t\t\tPlayer 2 : ";
    cin >> player2;
}

void game::gameName()
{
    cout << "\t\t\t\t\t\t\t   ____________________";
    cout << "\n\t\t\t\t\t\t\t  |                    |";
    cout << "\n\t\t\t\t\t\t\t  |  Tic-Tac-Toe Game  |";
    cout << "\n\t\t\t\t\t\t\t  |____________________|\n\n\n";
}

void game::gameBoard() // Player will enter the position and the value on board will change accordingly.
{
    gameName();
    cout << "\t\t\t\t\t\t\t|-------|-------|-------|" << endl;
    cout << "\t\t\t\t\t\t\t|   " << position[0] << "   |   " << position[1] << "   |   " << position[2] << "   |" << endl;
    cout << "\t\t\t\t\t\t\t|-------|-------|-------|\n";
    cout << "\t\t\t\t\t\t\t|   " << position[3] << "   |   " << position[4] << "   |   " << position[5] << "   |" << endl;
    cout << "\t\t\t\t\t\t\t|-------|-------|-------|\n";
    cout << "\t\t\t\t\t\t\t|   " << position[6] << "   |   " << position[7] << "   |   " << position[8] << "   |" << endl;
    cout << "\t\t\t\t\t\t\t|-------|-------|-------|\n";
}

void game::playAgain()
{
    cout << endl
         << endl
         << "Wanna play again(y/n) : ";
    cin >> play_again;
    if (play_again == 'y')
    {
        position[0] = '1', position[1] = '2', position[2] = '3', position[3] = '4', position[4] = '5', position[5] = '6', position[6] = '7', position[7] = '8', position[8] = '9';
        moves = 0; // Reset the positions on board and moves
        play();
    }
    else
    {
        cout << endl
             << endl
             << "Exited...";
        exit(0);
    }
}

void game::isWin()
{
    if (moves < 9)
    {
        if ((position[0] == 'X' && position[1] == 'X' && position[2] == 'X') ||
            (position[3] == 'X' && position[4] == 'X' && position[5] == 'X') ||
            (position[6] == 'X' && position[7] == 'X' && position[8] == 'X') ||
            (position[0] == 'X' && position[3] == 'X' && position[6] == 'X') ||
            (position[1] == 'X' && position[4] == 'X' && position[7] == 'X') ||
            (position[2] == 'X' && position[5] == 'X' && position[8] == 'X') ||
            (position[0] == 'X' && position[4] == 'X' && position[8] == 'X') ||
            (position[2] == 'X' && position[4] == 'X' && position[6] == 'X'))
        {
            cout << "WOHOOOO!!!, " << player1 << " won" << endl;
            playAgain(); // to ask weather players want to play again or not
        }
        else if ((position[0] == 'O' && position[1] == 'O' && position[2] == 'O') ||
                 (position[3] == 'O' && position[4] == 'O' && position[5] == 'O') ||
                 (position[6] == 'O' && position[7] == 'O' && position[8] == 'O') ||
                 (position[0] == 'O' && position[3] == 'O' && position[6] == 'O') ||
                 (position[1] == 'O' && position[4] == 'O' && position[7] == 'O') ||
                 (position[2] == 'O' && position[5] == 'O' && position[8] == 'O') ||
                 (position[0] == 'O' && position[4] == 'O' && position[8] == 'O') ||
                 (position[2] == 'O' && position[4] == 'O' && position[6] == 'O'))
        {
            cout << "WOHOOOO!!!, " << player2 << " won" << endl;
            playAgain(); // to ask weather players want to play again or not
        }
    }

    else
    {
        printf("Match Tied!!!");
        playAgain(); // to ask weather players want to play again or not
    }
}

int game::ifAlreadyFilled()
{
    if (position[index - 1] == 'X' || position[index - 1] == 'O')
    {
        cout << "Alredy filled " << position[index - 1] << " at position " << index << endl
             << "Press enter to choose another position...";
        getchar();
        getchar();
        return 1; // Already filled
    }
    return 0; // Not filled
}

void game::play()
{
// Player 1 move
again1: // In case player1 entered the position which is already filled then we have to take the input again.
    system("cls");
    gameBoard();

    cout << endl
         << endl
         << "\t\t\t\t\t\t\t\t" << player1 << " turn" << endl
         << endl;
    cin >> index;
    if (ifAlreadyFilled())
    {
        goto again1;
    }
    else
    {
        position[index - 1] = 'X'; // index-1 because index start from 0 and the position mentioned on gameBoard is from 1.
        moves++;                   // one move done
        system("cls");
        gameBoard();
    }

    // Now after taking input check whether player won or not
    isWin(); // to check after every input that one of the player won the match or not

// Player 1 move
again2: // In case player1 entered the position which is already filled then we have to take the input again.
    system("cls");
    gameBoard();

    cout << endl
         << endl
         << "\t\t\t\t\t\t\t\t" << player2 << " turn" << endl
         << endl;
    cin >> index;
    if (ifAlreadyFilled())
    {
        goto again2;
    }
    else
    {
        position[index - 1] = 'O'; // index-1 because index start from 0 and the position mentioned on gameBoard is from 1.
        moves++;                   // one move done
        system("cls");
        gameBoard();
    }

    // Now after taking input check whether player won or not
    isWin(); // to check after every input that one of the player won the match or not
}

int main()
{
    system("cls");
    game p;
    p.welcomeMessage(); // show welcome message
start:                  // when players want to play the game again
    p.setPlayerName();  // then take player names
    p.gameRule();

    cout << endl
         << endl
         << "\t\t\t\t\t\t  "
         << "Press enter to continue...";
    getchar();
    // After this new screen appears

    // Now the game starts
    while (p.moves != 9)
    {
        system("Color 6");
        p.play();
    }
    return 0;
}