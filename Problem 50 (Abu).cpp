#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector <string> ReadLine(string Line, string delmi="#//#") {
    vector<string> vLine;
    int pos = 0;
    string sWord;
    while ((pos = Line.find(delmi)) != std::string::npos) {
        sWord = Line.substr(0, pos);
        if (sWord != "") {
            vLine.push_back(sWord);
        }
        Line.erase(0, pos + delmi.length());
    }
    if (Line != "") {
        vLine.push_back(Line);
    }
    return vLine;
}

sClient ReadFromVector(string Line) {
    sClient Client;
    vector <string> vLine = ReadLine(Line);
    Client.AccountNumber = vLine[0];
    Client.PinCode = vLine[1];
    Client.Name = vLine[2];
    Client.Phone = vLine[3];
    Client.AccountBalance = stod(vLine[4]);

    return Client;
}

vector <sClient> LoadFromFile(string FileName) {
    vector <sClient> VecLine;
    fstream MyFile(FileName, ios::in);
        if (MyFile.is_open()) {
            string Line;
            sClient sLine;
            while (getline(MyFile, Line)) {
                sLine = ReadFromVector(Line);
                VecLine.push_back(sLine);
            }
        }
        return VecLine;
}

bool IsExist(vector <sClient> vLine , string Num, sClient &Line) {

    for (sClient& s : vLine) {
        if (s.AccountNumber == Num) {
            Line = s;
            return true;
        }
    }
    return false;
}



void PrintClient(sClient Line ){

    cout << "\t\t\t Clinet Info\n\n";
    cout <<"Account Number : " << Line.AccountNumber << endl;
    cout << "Pin Code  : " << Line.PinCode << endl;
    cout << "Name : " << Line.Name << endl;
    cout << "Phone  :  " << Line.Phone << endl;
    cout << "Account Balance  : " << Line.AccountBalance << endl;
}

int main()
{
    vector<sClient> Client = LoadFromFile("Client.txt");
    string Acc;
    sClient Line;
    cout << "Enter  Your Account Number";
    cin >> Acc;
    if (IsExist(Client, Acc, Line)) {
        PrintClient(Line);
    }
    else {
        cout << "No Found !!";
    }
    
}
