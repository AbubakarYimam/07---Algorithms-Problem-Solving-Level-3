#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClient ReadClientInfo() {
    sClient ClientInfo;
    cout << "Adding New Client \n\n";
    cout << "Account Number : ";
    getline(cin, ClientInfo.AccountNumber);
    cout << "Pin Code : ";
    getline(cin, ClientInfo.PinCode);
    cout << "Name : ";
    getline(cin, ClientInfo.Name);
    cout << "Phone : ";
    getline(cin, ClientInfo.Phone);
    cout << "Account Balance : ";
    cin>>ClientInfo.AccountBalance;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return ClientInfo;

}

string FromRecordToLine(sClient ClientInfo, string del = "#//#") {
    string sentLine = "";
    sentLine += ClientInfo.AccountNumber + del;
    sentLine += ClientInfo.PinCode + del;
    sentLine += ClientInfo.Name + del;
    sentLine += ClientInfo.Phone + del;
    sentLine += to_string(ClientInfo.AccountBalance);

    return sentLine;
}


void ListClientInToFile(sClient ClientInfo, ofstream &MyFile) {

    char Order = 'y';
    while (Order == 'y' || Order == 'Y') {
        cout << "\n\n";
        ClientInfo = ReadClientInfo();
        MyFile<<FromRecordToLine(ClientInfo)<<endl;
        cout << "Do You Want To Add Another Client (Y/N) ? ";
        cin >> Order;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       
    }
   
}



int main()
{
    sClient ClientInfo;
    ofstream MyFile("Client.txt", ios::out);
    if (!MyFile.is_open()) {
        cout << "Error Can't Open The File";
        return 1;
    }

    ListClientInToFile(ClientInfo, MyFile );
    MyFile.close();
    cout << "Clients Add Succesfully ";
}
