#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void ReadFromFile(string arr[3]) {
    fstream MyFile("Clients.txt", ios::in);
    if (!MyFile.is_open()) {
        cout << "File not found!\n";
        return;
    }
    int i = 0;
    string line;
    while (getline(MyFile, line) && i < 3) {
        arr[i] = line;
        i++;
    }
    // الباقي نخليه فاضي
    for (; i < 3; i++) {
        arr[i] = "";
    }
}


struct sClient {
    string AccountName;
    string PinCode;
    string ClientName;
    string Phone;
    string Balance;
};

void FromArrayToStru(string arr[3],sClient arr1[3], string sepa = "#//#") {
    string sword;
    size_t p = 0;

    for (int i = 0; i < 3;i++) {
        p = arr[i].find(sepa);
        arr1[i].AccountName = arr[i].substr(0, p);
        arr[i].erase(0, p + sepa.length());
        p = arr[i].find(sepa);
        arr1[i].PinCode = arr[i].substr(0, p);
        arr[i].erase(0, p + sepa.length());
        p = arr[i].find(sepa);
        arr1[i].ClientName = arr[i].substr(0, p);
        arr[i].erase(0, p + sepa.length());
        p = arr[i].find(sepa);
        arr1[i].Phone = arr[i].substr(0, p);
        arr[i].erase(0, p + sepa.length());
        p = arr[i].find(sepa);
        arr1[i].Balance = arr[i].substr(0, p);
     

      }

}


void display(sClient arr1[3]) {
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << left << setw(15) << "Account Name"
        << left << setw(15) << "Pin Code"
        << left << setw(25) << "Client Name"
        << left << setw(20) << "Phone"
        << left << setw(15) << "Balance" << endl;
    cout << "--------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < 3; i++) {
        cout << left << setw(15) << arr1[i].AccountName
            << left << setw(15) << arr1[i].PinCode
            << left << setw(25) << arr1[i].ClientName
            << left << setw(20) << arr1[i].Phone
            << left << setw(15) << arr1[i].Balance << endl;
    }
}


const string ClientsFileName = "Clients.txt";

int main()
{
    string arr[3];
    sClient arr1[3];
    ReadFromFile(arr);
    FromArrayToStru(arr, arr1);

    display(arr1);
}
