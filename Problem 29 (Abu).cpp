#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string read() {
    string num;
    cout << "Please Enter Your Name  :\n";
    getline(cin, num);
    return num;

}

void count(string s) {
    int csmall=0, ccapital=0;
    for (int i = 0; i < s.length();i++) {
        if (islower(s[i])) {
            csmall++;
        }
        else if (isupper(s[i])) {
            ccapital++;
        }
    }

    cout << "\nThe total string number is  :" << s.length() << endl;
    cout << "\nThe Number Capital Letter  is :" << ccapital << endl;
    cout << "\nThe Number Small Letter is  :" << csmall << endl;
}

int main()
{
    count(read());
}
