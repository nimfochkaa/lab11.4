#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 
using namespace std;

void Create(const string& fname) {
    ofstream fout(fname);
    if (!fout) {
        cerr << "Помилка створення файлу!" << endl;
        return;
    }

    char ch;
    string s;
    do {
        cin.ignore(); 
        cout << "Введіть рядок: ";
        getline(cin, s);
        fout << s << endl;
        cout << "Продовжити введення? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    fout.close();
    cout << "Файл успішно створено.\n";
}

void Print(const string& fname) {
    ifstream fin(fname);
    if (!fin) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    string s;
    cout << "Вміст файлу:\n";
    while (getline(fin, s)) {
        cout << s << endl;
    }

    fin.close();
}

int CountWordsInLine(const string& line) {
    int wordCount = 0;
    bool inWord = false;

    for (char ch : line) {
        if (isspace(static_cast<unsigned char>(ch))) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            ++wordCount;
        }
    }
    return wordCount;
}

int CountPunctuationInLine(const string& line) {
    const string punctuation = ".,;:!?-\"'()[]{}";
    int punctuationCount = 0;

    for (char ch : line) {
        if (punctuation.find(ch) != string::npos) {
            ++punctuationCount;
        }
    }
    return punctuationCount;
}

void ProcessFile(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    if (!fin) {
        cerr << "Помилка відкриття вхідного файлу!" << endl;
        return;
    }

    ofstream fout(outputFile);
    if (!fout) {
        cerr << "Помилка створення вихідного файлу!" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        int wordCount = CountWordsInLine(line);
        int punctuationCount = CountPunctuationInLine(line);
        fout << wordCount << " " << line << " " << punctuationCount << endl;
    }

    fin.close();
    fout.close();
    cout << "Файл успішно оброблено.\n";
}

void DisplayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Створити файл\n";
    cout << "2. Вивести вміст файлу\n";
    cout << "3. Обробити файл\n";
    cout << "4. Вихід\n";
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputFileName, outputFileName;
    int choice;

    do {
        DisplayMenu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            cout << "Введіть ім'я файлу для створення: ";
            getline(cin, inputFileName);
            Create(inputFileName);
            break;
        case 2:
            cout << "Введіть ім'я файлу для виведення: ";
            getline(cin, inputFileName);
            Print(inputFileName);
            break;
        case 3:
            cout << "Введіть ім'я вхідного файлу: ";
            getline(cin, inputFileName);
            cout << "Введіть ім'я вихідного файлу: ";
            getline(cin, outputFileName);
            ProcessFile(inputFileName, outputFileName);
            break;
        case 4:
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 4);

    return 0;
}
