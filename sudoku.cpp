#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool possible(int r, int c, int num, vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++) {
            if(board[r][i] == '0' + num || board[i][c] == '0' + num) {
                return false;
            }
        }

        for(int i = (r/3) * 3; i < ((r/3) * 3) + 3; i++) {
            for(int j = (c/3) * 3; j < ((c/3) * 3) + 3; j++) {
                if(board[i][j] == '0' + num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool fun(int row, int col, vector<vector<char>>& board) {
        if(row == board.size()) {
            return true;
        }

        if(board[row][col] == '.') {
            for(int i = 1; i <= 9; i++) {
                if(possible(row, col, i, board)) {
                    board[row][col] = '0' + i;
                    if(col < 8) {
                        if(fun(row, col + 1, board)) return true;
                    } else {
                        if(fun(row + 1, 0, board)) return true;
                    }
                    board[row][col] = '.';
                }
            }
            return false;
        }

        if(col < 8) {
            return fun(row, col + 1, board);
        } else {
            return fun(row + 1, 0, board);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        fun(0, 0, board);
    }
};

int main() {
    // Define a 9x9 Sudoku board
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Print the Sudoku board before solving
    cout << "Sudoku board before solving:\n";
    for (const auto& row : board) {
        for (const auto& ch : row) {
            cout << ch << ' ';
        }
        cout << endl;
    }

    Solution sol;
    sol.solveSudoku(board);

    // Print the Sudoku board after solving
    cout << "\nSudoku board after solving:\n";
    for (const auto& row : board) {
        for (const auto& ch : row) {
            cout << ch << ' ';
        }
        cout << endl;
    }

    return 0;
}
