// 46.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
vector <string> SplitString(string S1, string Delim= "#//#"){
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
ClientData ConvertLineToRecord(vector <string> vString) {
    ClientData Info;
    Info.AccountNumber = vString[0];
    Info.PinCode = vString[1];
    Info.Name = vString[2];
    Info.Phone = vString[3];
    Info.AccountBalance = vString[4];
    return Info;
}
void PrintRecord(ClientData Info) {
    cout << "Account Number: " <<Info.AccountNumber<<endl;
    cout << "Pin Code: " << Info.PinCode << endl;
    cout << "Name: " << Info.Name << endl;
    cout << "Phone: " << Info.Phone << endl;
    cout << "Account Balance: " <<Info.AccountBalance << endl;
}
int main(){
    ClientData Info;
    string S1="A150#//#1234#//#Mohammed AbuHadhoud#//#079939999#//#5000";
    Info=ConvertLineToRecord(SplitString(S1));
    PrintRecord(Info);
    system("pause>0");

    
}

