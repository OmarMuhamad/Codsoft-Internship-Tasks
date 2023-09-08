// Omar Mohammad
#include <iostream>
using namespace std;
string board[3][3] = { 
    {"(0, 0) 1", "(0, 1) 2", "(0, 2) 3"}, 
    {"(1, 0) 4", "(1, 1) 5", "(1, 2) 6"},
    {"(2, 0) 7", "(2, 1) 8", "(2, 2) 9"} 
};
int n_moves = 0;

void displayBoard() {
    cout << "|----------||----------||----------|\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " |";
        }
        cout << '\n';
        cout << "|----------||----------||----------|\n";
    }
}
bool checkMove(int pos) {
    int x = (pos - 1) / 3;
    int y = (pos - 1) % 3;
    if ((x >= 0 and x < 3) and (y >= 0 and y < 3)) {
        if ((board[x - 1][y - 1] != "O" and board[x - 1][y - 1] != "X")) {
            return true;

        }
    }
    else {
        return false;
    }
}
bool checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false; // No winner
}

bool checkDraw() {
    if (n_moves == 9) {
        return true;
    }
    return false;
}
void updateBoard(int pos, string ch) {
    int x = (pos - 1) / 3;
    int y = (pos - 1) % 3;
    board[x][y] = "    " + ch + "   ";
}
void GameRunner() {
    cout << "Welcome to Tic Tac Toe :]\n";
    string name1, name2;
    cout << "Enter Player One Name\n"; cin >> name1;
    cout << "Enter Player Two Name\n"; cin >> name2;
    cout << name1 << " => X\n";
    cout << name2 << " => O\n";
    //displayBoard();
    bool playerOne, playerTwo;
    playerOne = true, playerTwo = false;
    int x;

    while (true) {
        if (checkDraw()) {
            cout << "Sorry its a draw :(:(:(\n";
            break;
        }
        // if player one move
        if (playerOne) {
            n_moves++;
            displayBoard();
            cout << "Player " << name1 << "\nEnter Your Move:\n";
            cin >> x;
            while (!checkMove(x)) { // check for the validation of the move
                cout << "Please Enter a correct Move\n";
                cin >> x;
            }
            updateBoard(x, "X"); // update the board the player move
            swap(playerOne, playerTwo); // swap the turns
            if (checkWinner()) { 
                cout << name1 << " Won the GAME!!!! :):):)\n";
                break;
            }
        }
        else if (playerTwo) {
            n_moves++;
            displayBoard();
            cout << "Player " << name2 << "\nEnter Your Move:\n";
            cin >> x;
            while (!checkMove(x)) { // check for the validation of the move
                cout << "Please Enter a correct Move\n";
                cin >> x;
            }
            updateBoard(x, "O"); // update the board the player move
            swap(playerOne, playerTwo);
        }
        if (checkWinner()) { // swap the turns
            cout << name2 << " Won the GAME!!!! :):):)\n";
            break;
        }
    }
}
int main(){
    GameRunner();
}
