#include <iostream>
#include <string>
using namespace std;

// Function declarations
void showHeader();
void showInstructions();
void startTest(string name);
int askQuestion(string q);
void showResult(int score, int total, string name);
void thankYou();

int main() {
    string name;
    int choice;

    showHeader();

    cout << "Enter your name: ";
    getline(cin, name);

    while (true) {
        cout << "\n====================================================\n";
        cout << "                     MAIN MENU\n";
        cout << "====================================================\n";
        cout << "1. Start Personality Test\n";
        cout << "2. Instructions\n";
        cout << "3. About This Project\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            startTest(name);
        else if (choice == 2)
            showInstructions();
        else if (choice == 3) {
            cout << "\n====================================================\n";
            cout << "                     ABOUT PROJECT\n";
            cout << "====================================================\n";
            cout << "This project is a C++ console-based Personality Test System.\n";
            cout << "It uses arrays, functions, loops, and conditional statements.\n";
            cout << "The test consists of 20 questions based on human behavior.\n";
            cout << "Results show Introvert, Extrovert, or Ambivert classification.\n";
            cout << "No classes or advanced data structures are used.\n";
        }
        else if (choice == 4) {
            thankYou();
            break;
        }
        else
            cout << "Invalid choice! Try again.\n";
    }

    return 0;
}

// Header
void showHeader() {
    cout << "============================================================\n";
    cout << "                PERSONALITY TEST SYSTEM (C++)\n";
    cout << "============================================================\n";
    cout << "Welcome to the Personality Analyzer Project!\n";
    cout << "Answer questions honestly to get accurate results.\n";
    cout << "============================================================\n\n";
}

// Instructions
void showInstructions() {
    cout << "\n====================================================\n";
    cout << "                     INSTRUCTIONS\n";
    cout << "====================================================\n";
    cout << "1. You will be asked 20 questions.\n";
    cout << "2. Answer each question on a scale from 1 to 5.\n";
    cout << "   1 = Strongly Disagree\n";
    cout << "   2 = Disagree\n";
    cout << "   3 = Neutral\n";
    cout << "   4 = Agree\n";
    cout << "   5 = Strongly Agree\n";
    cout << "3. Answer honestly for better results.\n";
    cout << "====================================================\n\n";
}

// Start Test
void startTest(string name) {
    const int total = 20;
    string questions[total] = {
        "I enjoy meeting new people.",
        "I prefer quiet evenings alone.",
        "I find it easy to talk to strangers.",
        "I feel tired after social gatherings.",
        "I like being in the center of attention.",
        "I prefer deep conversations over small talk.",
        "I avoid crowded places.",
        "I feel confident in group discussions.",
        "I enjoy group activities.",
        "I often reflect on my thoughts alone.",
        "I feel nervous around unfamiliar people.",
        "I like participating in events.",
        "I prefer planned routines over spontaneous events.",
        "I easily express my feelings.",
        "I enjoy social gatherings frequently.",
        "I like staying home more than going out.",
        "I feel motivated when working with people.",
        "I prefer working alone.",
        "I feel comfortable making new friends.",
        "I need quiet time to recharge."
    };

    int score = 0;

    cout << "\n====================================================\n";
    cout << "                STARTING TEST FOR " << name << "\n";
    cout << "====================================================\n";

    for (int i = 0; i < total; i++) {
        cout << "\nQ" << i + 1 << ": ";
        int ans = askQuestion(questions[i]);
        score += ans;
    }

    showResult(score, total, name);
}

// Ask Question
int askQuestion(string q) {
    int ans;
    cout << q << "\nYour answer (1-5): ";
    cin >> ans;
    return ans;
}

// Show Result
void showResult(int score, int total, string name) {
    int max = total * 5;
    int percent = (score * 100) / max;

    cout << "\n====================================================\n";
    cout << "                     FINAL RESULTS\n";
    cout << "====================================================\n";
    cout << "Name: " << name << endl;
    cout << "Total Score: " << score << " / " << max << endl;
    cout << "Extroversion Level: " << percent << "%\n";

    cout << "\nPersonality Type: ";

    if (percent <= 40)
        cout << "INTROVERT\n";
    else if (percent <= 60)
        cout << "AMBIVERT\n";
    else
        cout << "EXTROVERT\n";

    cout << "\n====================================================\n";
    cout << "               TEST COMPLETED SUCCESSFULLY\n";
    cout << "====================================================\n\n";
}

// Thank You
void thankYou() {
    cout << "\n====================================================\n";
    cout << "            Thank you for using the system!\n";
    cout << "====================================================\n";
}
