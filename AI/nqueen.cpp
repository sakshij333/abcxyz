#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(vector<int>& queens, int row, int n, int& count) {
    if (row == n) {
        // Print the solution
        count++;
        cout << "Solution " << count << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (queens[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    } else {
        for (int col = 0; col < n; col++) {
            if (isSafe(queens, row, col)) {
                queens[row] = col;
                solveNQueensUtil(queens, row + 1, n, count);
            }
        }
    }
}

void solveNQueens(int n) {
    vector<int> queens(n);
    int count = 0;
    solveNQueensUtil(queens, 0, n, count);
}

int main() {
    int n;
    cout << "Enter the number of queens (n): ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
