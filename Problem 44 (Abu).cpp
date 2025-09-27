#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string read() {
    string sent;
    cout << "The Orginal Sentence \n";
    getline(cin, sent);
    return sent;
}

string rejoin(string s) {
    string s1;
    for (int i = 0; i < s.length() - 1; i++) {
        if (!ispunct(s[i])) {
            s1+=s[i];
        }
    }
    return s1;
}

int main()
{
   cout<<"after   :  "<< rejoin(read());
}
