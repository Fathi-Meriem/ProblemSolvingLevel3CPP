// 47.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;
struct ClientData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    string AccountBalance;
};
void FillClientData(ClientData& Info) {
    cout << "Enter Account Number?\n";
    cin >> Info.AccountNumber;
    cin.ignore();
    cout << "Enter PinCode?\n";
    cin >> Info.PinCode;
    cin.ignore();
    cout << "Enter Name?\n";
    getline(cin, Info.Name);
    cout << "Enter Phone?\n";
    cin >> Info.Phone;
    cin.ignore();
    cout << "Enter Account Balance?\n";
    cin >> Info.AccountBalance;
    cin.ignore();
}
string ConvertRecordToLine(ClientData Info, string Delim = "#//#") {
    string S1 = "";
    S1 = S1 + Info.AccountNumber + Delim;
    S1 += Info.PinCode + Delim;
    S1 += Info.Name + Delim;
    S1 += Info.Phone + Delim;
    S1 += Info.AccountBalance;
    return S1;
}
void SaveDataOnFiles(string S1) {
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << S1<<endl<<endl;
        MyFile.close();
    }
}
void StartRecording() {
    ClientData Info;
    char choice = 'Y';
    do{
        FillClientData(Info);
        SaveDataOnFiles(ConvertRecordToLine(Info));
        cout << "Client Added Successfully, do you want to add more clients? (Y||N)?";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

}
int main()
{
    StartRecording();
}

