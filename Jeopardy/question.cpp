//Question.cpp Created by Computer Programming Club
#include "question.hpp"

#include <iostream>
using namespace std;


Question::Question(string q, string a, int p) : question(q), answer(a), points(p), answered(false) {}

string Question::getQuestion() const {
    return question;
}

string Question::getAnswer() const {
    return answer;
}

int Question::getPoints() const {
    return points;
}

bool Question::isAnswered() const {
    return answered;
}

void Question::markAnswered() {
    answered = true;
}

vector<vector<Question>> setupGame() {
    vector<vector<Question>> board = {
        // Fun (Computer Trivia)
        {
            Question("What is the name of the first computer virus discovered?", "Creeper", 100),
            Question("Which company developed the first commercial antivirus software?", "McAfee", 200),
            Question("Who is known as the father of the Internet?", "Vint Cerf", 300),
            Question("What was the original name of Windows?", "Interface Manager", 400),
            Question("Which programming language is named after a British comedy group, aka it's an animal?", "Python", 500),
        },
        // Solve the Problem (Programming Challenges)
        {
            Question("If x = 8, then what is the value of x after x++?", "9", 100),
            Question("What is the output of 7 % 2 in most programming languages?", "1", 200),
            Question("In Python, how do you check if a list is empty?", "len(list) == 0", 300),
            Question("Given the string \"Hello, World!\", what index does 'W' hold in most zero-based indexing languages?", "7", 400),
            Question("What is the result of the boolean expression. \n Expression: 'not False or True')?", "True", 500),
        },
        // Name That Coding Language
        {
            Question("Which language uses `#include <iostream>` for basic input/output operations?", "C++", 100),
            Question("Which language introduced the `async/await` pattern for asynchronous programming in its 2017 update?", "JavaScript", 200),
            Question("Which language is best known for its effective memory management and use in developing operating systems?", "C", 300),
            Question("Which programming language is designed to have as few implementation dependencies as possible?", "Java", 400),
            Question("Which language is primarily used for scientific computing, data mining, and machine learning?", "Python", 500),
        },
        // Definition (Computer Science Terms)
        {
            Question("What is the term for the smallest unit of data in computing, represented by a 1 or 0?", "Bit", 100),
            Question("What does the acronym \"API\" stand for in computer programming?", "Application Programming Interface", 200),
            Question("What do we call an error in a program that causes it to operate incorrectly, but doesn't stop it from running?", "Bug", 300),
            Question("What is the term for a sequence of characters used to find or replace patterns inside strings?", "Regular Expression", 400),
            Question("In object-oriented programming, what is the term for creating a new instance of a class?", "Instantiation", 500),
        },
        // Computer Science (Historical and Conceptual)
        {
            Question("What is the name of the world's first programmable computer?", "Z3", 100),
            Question("Who is considered the father of computer science?", "Alan Turing", 200),
            Question("What pioneering computer network formed the basis for the Internet?", "ARPANET", 300),
            Question("What does the term \"algorithm\" derive from?", "The name of mathematician Al-Khwarizmi", 400),
            Question("Who co-founded Microsoft alongside Bill Gates?", "Paul Allen", 500),
        }
    };
    return board;
}

void displayBoard(const vector<vector<Question>>& board) {
    cout << "\nCategories:\n1. Fun (Computer Trivia)\n2. Solve the Problem (Programming Challenges)\n3. Name That Coding Language\n4. Definition (Computer Science Terms)\n5. Computer Science (Historical and Conceptual)\n" << endl;
    for (int i = 0; i < board.size(); ++i) {
        cout << "Category " << (i + 1) << ": ";
        for (const auto& q : board[i]) {
            if (!q.isAnswered()) {
                cout << q.getPoints() << " ";
            } else {
                cout << "X ";
            }
        }
        cout << "\n";
    }
}

void handleQuestion(vector<vector<Question>>& board) {
    int category, points;
    cout << "\nChoose a category and point value (e.g., 1 100): ";
    cin >> category >> points;

    if (category < 1 || category > 5) {
        cout << "Invalid category selection.\n";
        return;
    }

    bool found = false;
    for (auto& q : board[category - 1]) {
        if (q.getPoints() == points && !q.isAnswered()) {
            string userAnswer;
            cout << q.getQuestion() << "\nYour answer (type exactly as expected): ";
            cin.ignore(); // Clears input buffer
            getline(cin, userAnswer); // Handles multi-word answers
            
            if (userAnswer == q.getAnswer()) {
                cout << "Correct! You earned " << q.getPoints() << " points.\n";
            } else {
                cout << "Incorrect! The correct answer was: " << q.getAnswer() << ".\n";
            }
            
            q.markAnswered();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Question not found, already answered, or invalid point value.\n";
    }
}
