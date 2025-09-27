#include <iostream>
#include <string>
#include <vector>
using namespace std;

void read(string s,vector<string> & v) {
    string s1;
    cout << s << endl;
    cout << "\nEnter Account Number  ";
    cin >> s1;
    v.push_back(s1);
    cout << "\nEnter PinCode ";
    cin >> s1;
    v.push_back(s1);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter Name ";
    getline(cin, s1);
    v.push_back(s1);
    cout << "\nEnter Phone  ";
    cin >> s1;
    v.push_back(s1);
    cout << "\nEnter AccountBalance  ";
    cin >> s1;
    v.push_back(s1);
}

string print(vector <string> v) {
    string d = "#//#", sent;
    for (string& s : v) {
        sent += s + d;
    }
    return sent.substr(0, sent.length() - d.length());
}

int main()
{
    vector <string>v;
    read("Please Enter Client Date\n", v);
    cout <<"Client Record for Saving :  \n" << print(v);
}
