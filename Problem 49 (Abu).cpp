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

vector<string> Spliting(string FileLine, string Saparator = "#//#") {
    vector<string> vClient;
    int pos = 0;
    string sWord;
    while ((pos = FileLine.find(Saparator)) != std::string::npos) {
        sWord = FileLine.substr(0, pos);
        if (sWord != "") {
            vClient.push_back(sWord);
        }
        FileLine.erase(0, pos + Saparator.length()); // FIXED
    }
    if (FileLine != "") {
        vClient.push_back(FileLine); // FIXED
    }
    return vClient;
}

sClient FromVectorToStructur(string File) {
    vector<string> sFile = Spliting(File);
    sClient vFile;
    vFile.AccountNumber = sFile[0];
    vFile.PinCode = sFile[1];
    vFile.Name = sFile[2];
    vFile.Phone = sFile[3];
    vFile.AccountBalance = stod(sFile[4]); // FIXED
    return vFile;
}

vector<sClient> ReadFromFile(string FileName) {
    vector<sClient> vLine;
    fstream MyFile(FileName, ios::in);

    if (MyFile.is_open()) {
        sClient sLine;
        string Line;
        while (getline(MyFile, Line)) {
            sLine = FromVectorToStructur(Line);
            vLine.push_back(sLine);
        }
        MyFile.close();
    }
    return vLine;
}

void display(sClient vsClient, bool is) {
    if (is) {
        cout << vsClient.AccountNumber << endl;
        cout << vsClient.PinCode << endl;
        cout << vsClient.Name << endl;
        cout << vsClient.Phone << endl;
        cout << vsClient.AccountBalance << endl;
    }
    else {
        cout << "No";
    }
}

bool check(vector<sClient> vsClient, string num) {
    for (sClient& s : vsClient) {
        if (s.AccountNumber == num) {
            return true;
        }
    }
    
}

sClient check1(vector<sClient> vsClient, string num) {
    for (sClient& s : vsClient) {
        if (s.AccountNumber == num) {
            return s;
        }
    }
    return {}; // return empty sClient if not found (FIXED)
}

int main()
{
    vector<sClient> Clients = ReadFromFile("Clients1.txt");
    string num;
    cout << "Enter File Name : ";
    cin >> num;

    display(check1(Clients, num), check(Clients,num));
}
