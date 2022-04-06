#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

map<string, string> knowledge = { 
    {"hello", "Oh, hello hooman!"}, // {"question", "answer"}
    {"how are you", "Not too bad for a machine"},
    {"what is your name", "My creator gave me name ChatBot3000"},
    {"what are you up to", "Answering stupid question"},
};

string exitPhrases[] = {"exit", "bye", "have a good day"};

string to_lower(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

void botSays(string text) {
    cout << "[BOT]: " << text << "\n";
}

// Question from the user
string userQuestion() {
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    question = to_lower(question);
    return question;
}

bool isExit(string text) {
    for (auto phrase : exitPhrases) {
        regex expression = regex(".*" + phrase + ".*");
        if (regex_match(text, expression)) {
            botSays("Ok, byeeee!!!");
            return true; // phrase for exit
        }
    }
    return false; 
}

// Outputs an answer for the question
void botAnswer(string question) {
    bool foundAnswer = false; 
    for (auto entry : knowledge) { 
        // entry.first - вопрос
        // entry.second - ответ
        regex expression = regex(".*" + entry.first + ".*");
        if (regex_match(question, expression)) {
            // Дать ответ!
            botSays(entry.second);
            foundAnswer = true;
        }
    }
    if (!foundAnswer) { // If there is no answer
        botSays("Do not comprende");
    }
}

int main() {

    cout << "Hello, Welcome to ChatBot3000\n";

    string question;


    while (!isExit(question)) { // Execute the code untill the exit phrase 
        question = userQuestion();
        botAnswer(question);
    }
}
