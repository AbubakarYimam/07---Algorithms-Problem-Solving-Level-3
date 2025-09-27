#include <iostream>
#include <iomanip>
#include<string>
#include <vector>
using namespace std;

string join(vector <string> v,string d="  ") {
    string s = "";
    for (string& c : v) {
        s += c + d;
    }
    return s.substr(0, -2);
}


int main()
{
    vector <string> v = { "abubakar", "Yimam","Ahmed" };
    cout << join(v,",");
}
