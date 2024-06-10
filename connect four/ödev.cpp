#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 8;
const int COLS = 8;

class ConnectFour {
private:
    vector<vector<char > > board;
    char currentPlayer;

public:
    ConnectFour() : board(ROWS, vector<char>(COLS, '.')), currentPlayer('X') {}

    void displayBoard() const {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "---------------" << endl;
    }

    bool placeDisk(int col) {
        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == '.') {
                board[i][col] = currentPlayer;
                return true;
            }
        }
        return false;
    }

    bool checkWinner(char currentPlayer) const {
        
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i][j + 1] == currentPlayer &&
                    board[i][j + 2] == currentPlayer &&
                    board[i][j + 3] == currentPlayer) {
                    return true; 
                }
            }
        }

       
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j] == currentPlayer &&
                    board[i + 2][j] == currentPlayer &&
                    board[i + 3][j] == currentPlayer) {
                    return true;
                }
            }
        }

       
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j + 1] == currentPlayer &&
                    board[i + 2][j + 2] == currentPlayer &&
                    board[i + 3][j + 3] == currentPlayer) {
                    return true; 
                }
            }
        }

      
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = COLS - 1; j >= 3; --j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j - 1] == currentPlayer &&
                    board[i + 2][j - 2] == currentPlayer &&
                    board[i + 3][j - 3] == currentPlayer) {
                    return true; 
                }
            }
        }

        return false; 
    }

    void changePlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool isBoardFull() const {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == '.') {
                    return false; 
                }
            }
        }
        return true; 
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    ConnectFour game;
    int column;

    while (true) {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << "'s turn. Enter column number (1-8): ";
        cin >> column;

        if (column < 1 || column > COLS) {
            cout << "Invalid column. Please enter a number between 1 and 8." << endl;
            continue;
        }

        if (!game.placeDisk(column - 1)) {
            cout << "Column is full. Please choose another column." << endl;
            continue;
        }

        if (game.checkWinner(game.getCurrentPlayer())) {
            game.displayBoard();
            cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
            break;
        }

        if (game.isBoardFull()) {
            game.displayBoard();
            cout << "It's a tie! Board is full." << endl;
            break;
        }

        game.changePlayer();
    }

    return 0;
}

