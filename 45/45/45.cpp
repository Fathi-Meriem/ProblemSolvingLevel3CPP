// 45.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct ClientData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    string AccountBalance;
};
void FillClientData(ClientData &Info) {
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
/*vector <string> ClientRecord(ClientData Info) {
    vector <string> vClientData;
    vClientData.push_back(Info.AccountNumber);
    vClientData.push_back(to_string(Info.PinCode));
    vClientData.push_back(Info.Name);
    vClientData.push_back(to_string(Info.Phone));
    vClientData.push_back(to_string(Info.AccountBalance));
    return vClientData;
}
string JoinNamesInVector(ClientData Info,string Delim) {
    string OneString;
    vector <string> vNames;
    vNames = ClientRecord(Info);
    vector <string> ::iterator iter;
    for (iter = vNames.begin(); iter != vNames.end(); iter++){
        OneString.append(*iter);
        OneString.append(Delim);
    }
    return OneString.substr(0, OneString.length() - Delim.length());

}*/
string ConvertRecordToLine(ClientData Info,string Delim="#//#") {
    string S1 = "";
    S1 = S1 + Info.AccountNumber + Delim;
    S1 +=  Info.PinCode+Delim;
    S1 +=Info.Name+Delim;
    S1 += Info.Phone + Delim;
    S1 += Info.AccountBalance;
    return S1;
}
int main()
{
    ClientData Info;
    FillClientData(Info);
    cout << ConvertRecordToLine(Info);
  /*  cout<<JoinNamesInVector(Info, "#/ /#");*/
    system("pause>0");

    
}

