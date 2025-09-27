#include <iostream>
#include <string>
#include <vector>
using namespace std;

string join(vector<string>v, string de = " ") {
    string s1 = "";
    for (string& s : v) {
        s1 += s + de;
    }
    return s1.substr(0, s1.length() - de.length());
}

string revString(vector<string> v, string de = " ") {
    string s1 = "";
    for (int i = v.size() - 1;i >= 0;i--) {
        s1 += v[i] + de;
    }
    return s1.substr(0, s1.length() - de.length());
}


int main()
{
    vector <string>vString = { "Abubakar", "Yimam","Ahmed" };

    cout << "before reverse : \n" << join(vString) << endl;
    cout << "After reverse  :  \n" << revString(vString);

}
