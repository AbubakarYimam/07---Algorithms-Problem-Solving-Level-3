#include <string>
#include <iostream>
using namespace std;

string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

void PrintEachWordInString(string S1) {
    string delim = " "; // delimiter
    cout << "\nYour string words are: \n\n";
    short pos = 0;
    string sWord;
    int count = 0;

    // use find() function to get the position of the delimiter
    while ((pos = S1.find(delim)) != string::npos) {
        sWord = S1.substr(0, pos); // extract word before delimiter
        if (sWord != "") {
            count++;
        }
        S1.erase(0, pos + delim.length());
        // erase extracted word and delimiter, move to next
    }

    // print the last word
    if (S1 != "") {
        count++;
    }
    cout << "The Toatal String is : " << count;
}

int main() {
    PrintEachWordInString(ReadString());
    system("pause>0");
    return 0;
}
