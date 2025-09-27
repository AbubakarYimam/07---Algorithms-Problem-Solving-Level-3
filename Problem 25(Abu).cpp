#include <iostream>
#include <string>
using namespace std;

string read() {
    string s;
    cout << "Enter a string   \n";
    getline(cin, s);
    return s;
}
void makeupper(string s) {
    bool is1st = true;
    for (int i = 0;i < s.length();i++) {
        if (s[i] != ' ' & is1st) {
            s[i] = tolower(s[i]);
            is1st = false;
        }
        is1st = (s[i] == ' ' ? true : false);
    }
    cout << "\n\n" << s;
}


int main()
{
    makeupper(read());

}
