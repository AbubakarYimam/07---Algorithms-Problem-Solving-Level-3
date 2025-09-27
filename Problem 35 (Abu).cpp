#include <iostream>
#include <string>
using namespace std;

string read() {
    string name;
    cout << "Enter Your Name :";
    getline(cin, name);
    return name;
}

void printbyline(string name) {
    bool is_1st = true;
    for (int i = 0;i < name.length();i++) {
        if (name[i] != ' ' && is_1st) {
            cout << "\n" << name[i];
        }
        else {
            cout << name[i];
        }
        is_1st = (name[i] == ' ' ? true : false);
    }

}


int main()
{
    string name = read();
    printbyline(name);
}
