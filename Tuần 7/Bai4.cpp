#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canPlaceWordHorizontally(vector<string>& crossword, string word, int row, int col) {
    int len = word.length();
    if (col + len > crossword[row].size()) return false; 
    for (int i = 0; i < len; i++) {
        if (crossword[row][col + i] != '-' && crossword[row][col + i] != word[i]) return false; 
    }
    return true;
}

bool canPlaceWordVertically(vector<string>& crossword, string word, int row, int col) {
    int len = word.length();
    if (row + len > crossword.size()) return false; 
    for (int i = 0; i < len; i++) {
        if (crossword[row + i][col] != '-' && crossword[row + i][col] != word[i]) return false; 
    }
    return true;
}

void placeWordHorizontally(vector<string>& crossword, string word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        crossword[row][col + i] = word[i];
    }
}

void placeWordVertically(vector<string>& crossword, string word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        crossword[row + i][col] = word[i];
    }
}

void unplaceWordHorizontally(vector<string>& crossword, string word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        crossword[row][col + i] = '-';
    }
}

void unplaceWordVertically(vector<string>& crossword, string word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        crossword[row + i][col] = '-';
    }
}

bool crosswordPuzzleUtil(vector<string>& crossword, vector<string>& words, int wordIndex) {
    if (wordIndex == words.size()) return true;
    
    string word = words[wordIndex];
    
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (canPlaceWordHorizontally(crossword, word, row, col)) {
                placeWordHorizontally(crossword, word, row, col);
                if (crosswordPuzzleUtil(crossword, words, wordIndex + 1)) return true; 
                unplaceWordHorizontally(crossword, word, row, col); 
            }
        }
    }

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (canPlaceWordVertically(crossword, word, row, col)) {
                placeWordVertically(crossword, word, row, col);
                if (crosswordPuzzleUtil(crossword, words, wordIndex + 1)) return true; 
                unplaceWordVertically(crossword, word, row, col); 
            }
        }
    }
    
    return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> wordList;
    string word;
    for (char c : words) {
        if (c == ';') {
            wordList.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    wordList.push_back(word);
    
    crosswordPuzzleUtil(crossword, wordList, 0);
    
    return crossword;
}

int main() {
    vector<string> crossword;
    for (int i = 0; i < 10; i++) {
        string row;
        cin >> row;
        crossword.push_back(row);
    }
    string words;
    cin >> words;
    
    vector<string> result = crosswordPuzzle(crossword, words);
    for (string row : result) {
        cout << row << endl;
    }
    
    return 0;
}
