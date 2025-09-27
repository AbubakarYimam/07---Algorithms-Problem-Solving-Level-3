#include <iostream>
#include <string>
using namespace std;

string read() {
    cout << "Enter a name\n";
    string s;
    getline(cin, s);
    return s;
}

char convert(char a) {
    return isupper(a) ? tolower(a) : toupper(a);
}

void print(string s) {
    for (int i = 0;i < s.length();i++) {
        s[i] = convert(s[i]);
    }
    cout << s;
}

int main()
{
    print(read());
}