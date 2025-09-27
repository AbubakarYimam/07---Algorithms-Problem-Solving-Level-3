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
    for (int i = 0;i < s.length();i++) 
            s[i] = tolower(s[i]);
    
    cout << "all lower   \n\n" << s;
    for (int i = 0;i < s.length();i++)
        s[i] = toupper(s[i]);
    cout << "\nall upper \n\n " << s;
}


int main()
{
    makeupper(read());

}
