#include <string>
#include <iostream>
using namespace std;



string read() {
    string s;
    cout << "Piease Enter Your String?\n";
    getline(cin, s);
    return s;
}

void printfirstletterofeachword(string s) {
    bool is_1st = true;
    cout << "\nFirst letter of this string: \n";

    for (short i = 0; i < s.length();i++) {
        if (s[i] != ' '  && is_1st) {
            cout << s[i] << endl;
        }
        is_1st = (s[i] == ' ' ? true : false);
    }
}

int main() {
    printfirstletterofeachword(read());
    system("pause>0");
}
