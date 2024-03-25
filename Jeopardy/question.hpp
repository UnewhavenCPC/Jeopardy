// question.hpp

#include <vector>
#include <string>
using namespace std;
class Question {
private:
    string question;
    string answer;
    int points;
    bool answered;

public:
    Question(string q, string a, int p);
    string getQuestion() const;
    string getAnswer() const;
    int getPoints() const;
    bool isAnswered() const;
    void markAnswered();
};

vector<vector<Question>> setupGame();
void displayBoard(const vector<vector<Question>>& board);
void handleQuestion(vector<vector<Question>>& board);

