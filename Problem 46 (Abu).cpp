#include <iostream>
#include <string>
#include <vector>
using namespace std;

void fromLineToRecord(string stline , string del ="#//#") {
	short p = 0;
	string sWord;
	p = stline.find(del);
	sWord = stline.substr(0, p);
	cout << "AccountNumber : " << sWord<<endl;
	stline.erase(0, p + del.length());
	p = stline.find(del);
	sWord = stline.substr(0, p);
	cout << "PinCode : " << sWord<<endl;
	stline.erase(0, p + del.length());
	p = stline.find(del);
	sWord = stline.substr(0, p);
	cout << "Name : " << sWord<<endl;
	stline.erase(0, p + del.length());
	p = stline.find(del);
	sWord = stline.substr(0, p);
	cout << "Phone : " << sWord<<endl;
	stline.erase(0, p + del.length());
	sWord = stline.substr(0, p);
	cout << "Account Balance  : " << stoi(sWord)<<endl;
	stline.erase(0, p + del.length());




}


int main()
{
	string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
	fromLineToRecord(stLine);
}
