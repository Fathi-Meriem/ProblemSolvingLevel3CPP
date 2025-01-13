// 49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> 
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
string ReadAccountNumber(string message) {
    string AccountNumber;
    cout << message << endl;
    cin >> AccountNumber;
    return AccountNumber;
}
vector <string> SplitString(string S1, string Delim) {
    vector <string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}
ClientData ConvertLineToRecord(string S1, string Delim = "#//#") {
    vector <string> vString;
    ClientData Info;
    vString = SplitString(S1, Delim);
    Info.AccountNumber = vString[0];
    Info.PinCode = vString[1];
    Info.Name = vString[2];
    Info.Phone = vString[3];
    Info.AccountBalance = vString[4];
    return Info;
}

vector <ClientData> LoadClientsDataFromFile() {
    fstream MyFile;
    ClientData Client;
    vector <ClientData> vInfo;
    MyFile.open("File.txt", ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vInfo.push_back(Client);

        }

        MyFile.close();
    }
    return vInfo;
}
bool FindAccountNumber(ClientData Info,string AccountNumber) {
    if (Info.AccountNumber == AccountNumber)
        return true;
    else
        return false;
}
void PrintClientData() {
    vector <ClientData> info;
    info = LoadClientsDataFromFile();
    string AccountNumber = ReadAccountNumber("Please enter your account number: \n");
    for (ClientData Info : info) {
        if (FindAccountNumber(Info, AccountNumber)) {
            cout << "The following are the cleint details: \n";
            cout << " Account number :" << Info.AccountNumber << endl;
            cout << " Pin Code :" << Info.PinCode << endl;
            cout << " Name:" << Info.Name << endl;
            cout << " Phone Number :" << Info.Phone << endl;
            cout << " Account Balance :" << Info.AccountBalance << endl;
            return ;
        }
           
      
    }
    cout << "Client with account number ( " << AccountNumber << " ) not found! \n";
}

int main()
{
    PrintClientData();
    system("pause>0");

}

