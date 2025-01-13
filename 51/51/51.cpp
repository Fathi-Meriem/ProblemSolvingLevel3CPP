// 51.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    if (vString.size() == 5) {
        Info.AccountNumber = vString[0];
        Info.PinCode = vString[1];
        Info.Name = vString[2];
        Info.Phone = vString[3];
        Info.AccountBalance = vString[4];
    }
    else {

        cout << "Warning: Malformed line detected: " << S1 << endl;
        
    }
    return Info;
}
string ConvertRecordToLine(ClientData Client, string Separator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += Client.AccountBalance;
    return stClientRecord;
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
void PrintClientData(ClientData Info) {
    cout << "The following are the cleint details: \n";
    cout << " Account number :" << Info.AccountNumber << endl;
    cout << " Pin Code :" << Info.PinCode << endl;
    cout << " Name:" << Info.Name << endl;
    cout << " Phone Number :" << Info.Phone << endl;
    cout << " Account Balance :" << Info.AccountBalance << endl;

}
bool FindClientAccountNumber(vector <ClientData> Info, string AccountNumber, ClientData & C){
        bool result;
        for (ClientData &info : Info) {
            if (info.AccountNumber == AccountNumber) {
                C = info;
                return true;
            }
        }
        return false;
    }
void  LoadClientsDataToFile(vector <ClientData>& Info) {
    fstream MyFile;
    string Client;
    MyFile.open("File.txt", ios::out);

    if (MyFile.is_open())
    {

        for (ClientData info : Info)

        {
            Client = ConvertRecordToLine(info);
            MyFile << Client << endl;
        }
    }
        MyFile.close();
    }
void UpdateClientData(ClientData &info) {  
            info.AccountNumber = info.AccountNumber;
            cout << "Enter Pin Code: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,info.PinCode);
            cout << "Enter Name: ";
            getline(cin,info.Name);
            cout << "Enter Phone: ";
            getline(cin,info.Phone);
            cout << "Account Balance: ";
            getline(cin,info.AccountBalance);
}
void LoadClientInfo(vector <ClientData>& Info, string AccountNumber) {
    ClientData Client;
    char Answer = 'n';
    if (FindClientAccountNumber(Info, AccountNumber, Client)) {
        PrintClientData(Client);
        cout << "Are you sure you want to update this client y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            for (ClientData &C : Info)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    UpdateClientData(C);
                    break;
                }
               
                
            }
            LoadClientsDataToFile(Info);
            cout << "\n\nClient Updated Successfully.";

        }
      
        else
            cout << "Client not found! \n";
    }
}
int main() {
    string AccountNumber = ReadAccountNumber("Please enter your account number: ");
    vector <ClientData> Info = LoadClientsDataFromFile();
    LoadClientInfo(Info, AccountNumber);
}