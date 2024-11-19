#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 
using namespace std;

void Create(const string& fname) {
    ofstream fout(fname);
    if (!fout) {
        cerr << "������� ��������� �����!" << endl;
        return;
    }

    char ch;
    string s;
    do {
        cin.ignore(); 
        cout << "������ �����: ";
        getline(cin, s);
        fout << s << endl;
        cout << "���������� ��������? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    fout.close();
    cout << "���� ������ ��������.\n";
}

void Print(const string& fname) {
    ifstream fin(fname);
    if (!fin) {
        cerr << "������� �������� �����!" << endl;
        return;
    }

    string s;
    cout << "���� �����:\n";
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
        cerr << "������� �������� �������� �����!" << endl;
        return;
    }

    ofstream fout(outputFile);
    if (!fout) {
        cerr << "������� ��������� ��������� �����!" << endl;
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
    cout << "���� ������ ���������.\n";
}

void DisplayMenu() {
    cout << "\n����:\n";
    cout << "1. �������� ����\n";
    cout << "2. ������� ���� �����\n";
    cout << "3. �������� ����\n";
    cout << "4. �����\n";
    cout << "��� ����: ";
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
            cout << "������ ��'� ����� ��� ���������: ";
            getline(cin, inputFileName);
            Create(inputFileName);
            break;
        case 2:
            cout << "������ ��'� ����� ��� ���������: ";
            getline(cin, inputFileName);
            Print(inputFileName);
            break;
        case 3:
            cout << "������ ��'� �������� �����: ";
            getline(cin, inputFileName);
            cout << "������ ��'� ��������� �����: ";
            getline(cin, outputFileName);
            ProcessFile(inputFileName, outputFileName);
            break;
        case 4:
            cout << "����� � ��������.\n";
            break;
        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 4);

    return 0;
}
