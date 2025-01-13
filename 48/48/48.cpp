// 48.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> 
#include <fstream>
#include <vector>
#include<string>
using namespace std;
//string fileName = "clients.txt";
struct ClientData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    string AccountBalance;
};
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
    vString = SplitString(S1,Delim);
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
void PrintClientData(ClientData Info) {
    cout << " | " << left << setw(17) << Info.AccountNumber
        << " | " << left << setw(15) << Info.PinCode
        << " | " << left << setw(30) << Info.Name
        << " | " << left << setw(20) << Info.Phone
        << " | " << left << setw(20) << Info.AccountBalance
        << endl;
}
    
void PrintClientAllData() {
    vector <ClientData> Info;
    Info = LoadClientsDataFromFile();
     cout << "\t\t\t\t" << "Client List "<<Info.size()<<" Clients"<<"\t"<<endl;
     cout << "--------------------------------------------------------------------------------------------------------------------\n";
     cout << " | "<<left<<setw(17) << "Account Number"
          <<" | "<<left<< setw(15) << " Pin Code "
          << " | "<< left << setw(30) << "Client Name "
          <<" | "<< left << setw(20)  << " Phone "
          <<  " | " << left << setw(20)<< " Account Balance "
          << endl;
     cout << "--------------------------------------------------------------------------------------------------------------------\n";
     for ( ClientData info:Info) {
         PrintClientData(info);

     }
     cout<<"--------------------------------------------------------------------------------------------------------------------\n";
}


int main()
{
    PrintClientAllData();
    system("pause>0");
   
}

