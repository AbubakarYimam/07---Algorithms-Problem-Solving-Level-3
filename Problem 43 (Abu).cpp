#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != string::npos) {
        sWord = S1.substr(0, pos);
        if (!sWord.empty()) {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (!S1.empty()) {
        vString.push_back(S1);
    }

    return vString;
}

string JoinString(vector<string> vString, string Delim) {
    string S1;
    for (string& s : vString) {
        S1 += s + Delim;
    }
    if (!S1.empty()) {
        S1 = S1.substr(0, S1.length() - Delim.length());
    }
    return S1;
}

string LowerAllString(string S1) {
    for (size_t i = 0; i < S1.length(); i++) {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

string ReplaceWordInStringUsingSplit(string S1, string sToReplace, string sReplaceTo, bool MatchCase = true) {
    vector<string> vString = SplitString(S1, " ");

    for (string& s : vString) {
        if (MatchCase) {
            if (s == sToReplace) {
                s = sReplaceTo;
            }
        }
        else {
            if (LowerAllString(s) == LowerAllString(sToReplace)) {
                s = sReplaceTo;
            }
        }
    }

    return JoinString(vString, " ");
}

int main() {
    string text = "I love USA because USA is powerful";

    cout << ReplaceWordInStringUsingSplit(text, "USA", "ETHIOPIA") << endl;
    cout << ReplaceWordInStringUsingSplit(text, "usa", "ETHIOPIA", false) << endl;

    return 0;
}
