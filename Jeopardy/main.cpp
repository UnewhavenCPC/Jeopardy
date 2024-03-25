// Main.cpp Created By Computer Programming Club
#include "question.hpp"
#include <iostream>
using namespace std;

int main() {
    vector<vector<Question>> board = setupGame();
    bool gameOver = false;

    cout << "Welcome to the Jeopardy Game! Select a category and a point value to answer a question.\n";

    while (!gameOver) {
        displayBoard(board);
        handleQuestion(board);

        // Check if all questions have been answered
        gameOver = true;
        for (const auto& cat : board) {
            for (const auto& q : cat) {
                if (!q.isAnswered()) {
                    gameOver = false;
                    break;
                }
            }
            if (!gameOver) break;
        }
    }

    cout << "\nGame over. Thanks for playing!\n";
    return 0;
}
