// 44.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;
string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

string RemovePunctuations(string S1) {
    for (short i = 0; i < S1.length(); i++) {
        if (ispunct(S1[i])) {
            S1.erase(i,1);
        }

    }
    return S1;

}

int main()
{
    string S1="welcome to Jordan, jordan is a nice country; it's amazing.";
    cout << S1 << endl << endl;
    cout<<"The string after removing punctuations is: \n"<<RemovePunctuations(S1)<<endl<<endl;
    cin.get();
    return 0;
    
}

