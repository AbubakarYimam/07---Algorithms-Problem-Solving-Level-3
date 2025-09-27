#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string readString() {
    string s;
    cout << "\nEnter a Name :  ";
    getline(cin, s);
    return s;
}

char readChar() {
    char s;
    cout << "\nEnter caharacter :  ";
    cin >> s;
    return s;
}

void countLetter(string s, char c) {
    int count = 0, countall=0;
    for (int i = 0;i < s.length();i++) {
        if (c == s[i]) {
            count++;
        }
        if (c == tolower(s[i]) || c == toupper(s[i])) {
            countall++;
        }
    }
    cout << "/nThe number '" << c << "'  :"<<count<<endl;
    cout << "/nThe Number '" << char(tolower(c)) << "' " << char(toupper(c)) << "  :" << countall;
}

int main()
{
    string s = readString();
    char c = readChar();
    countLetter(s, c);
}
