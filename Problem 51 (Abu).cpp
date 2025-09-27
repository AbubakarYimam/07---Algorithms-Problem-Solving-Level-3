#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string ClientsFileName = "Client.txt";

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance=0;
    bool MarkForDelete = false;
};

vector<string> SplitString(string S1, string delim ="#//#") {
    vector <string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}

sClient ConvertLinetoRecord(string Line, string Sepatartor="#//#") {
    sClient Client;
    vector<string> vLine = SplitString(Line);
    Client.AccountNumber = vLine[0];
    Client.PinCode = vLine[1];
    Client.Name = vLine[2];
    Client.Phone = vLine[3];
    Client.AccountBalance = stod(vLine[4]);

    return Client;
}

string ConvertRecordToLine(sClient  Client, string Sepa = "#//#") {
    string Line="";
    Line += Client.AccountNumber + Sepa;
    Line += Client.PinCode + Sepa;
    Line += Client.Name + Sepa;
    Line += Client.Phone + Sepa;
    Line += to_string(Client.AccountBalance);
    return Line;

}

vector<sClient> LoadClientsDataFromFile(string FileName) {
    vector<sClient>vsClient;
    fstream MyFile(FileName, ios::in);
    if (MyFile.is_open()) {
        string sLine;
        sClient Client;
        while (getline(MyFile, sLine)) {
            Client = ConvertLinetoRecord(sLine);
            vsClient.push_back(Client);
        }
        MyFile.close();
    }
    return vsClient;
}

void PrintClientCard(sClient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number  : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client) {
    for (sClient C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    for (sClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

string ReadClientAccountNumber() {
    string AccountNumber = "";
    cout << "\nPlease enter Account Number? ";
    cin >> AccountNumber;
    return AccountNumber;
}

sClient Update(sClient Client) {
   
    Client.AccountNumber = "12345678";
    Client.PinCode = "6187";
    Client.Name ="Abu";
    Client.Phone = "09764345";
    Client.AccountBalance = 6543200;

    return Client;
}

vector<sClient> SaveClientsDataToFile(string FileName, vector<sClient> vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    string DataLine;

    if (MyFile.is_open()) {
        for (sClient C : vClients) {
            if (C.MarkForDelete == false) {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
            else {
                C = Update(C);
                string d1 = ConvertRecordToLine(C);
                MyFile << d1 << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want Update this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);

            // Refresh Clients
            vClients = LoadClientsDataFromFile(ClientsFileName);
            PrintClientCard(Client);

            cout << "\n\nClient Update Successfully.\n";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
        return false;
    }

    return false;
}

int main()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNumber(AccountNumber, vClients);

    system("pause>0");
    return 0;
}