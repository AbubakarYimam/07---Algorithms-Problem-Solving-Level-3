#include <iostream>
#include <string>
using namespace std;

string read() {
    string name;
    cout << "Enter Your Name : \n";
    getline(cin, name);
    return name;
}

bool isVowel(char letter) {
    return (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u');
}

int countVowle(string name) {
    int countV = 0;
    for (int i = 0; i < name.length();i++) {
        if (isVowel(name[i])) {
            countV++;
        }
    }
    return countV;
}

int main()
{
    string name = read();
    cout<< "The Total Vowel Letter : "<<countVowle(name);
}
