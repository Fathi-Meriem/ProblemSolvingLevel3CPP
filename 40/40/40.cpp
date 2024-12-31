
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string JoinNames(vector <string> vNames, string Delim) {
    string OneString;
    for (string Name : vNames) {
        OneString.append(Name);
        OneString.append(Delim);
    }
    return OneString.substr(0, OneString.length() - Delim.length());

}
string JoinNames(string arr[],short length,string Delim) {
    string OneString;
    for (short i = 0; i < length;i++) {
        OneString.append(arr[i]);
        OneString.append(Delim);
    }
    return OneString.substr(0, OneString.length() - Delim.length());

}

using namespace std;
int main()
{
    string OneString;
    vector <string> vNames = { "Meriem","Karima","Souad","Sanaa" };
    string ArrNames[4] = { "Meriem","Karima","Souad","Sanaa" };
    cout << "Join Vector\n";
    cout << JoinNames(vNames, "&&&") <<endl<< endl;
    cout << "Join Arr\n";
    cout <<JoinNames(ArrNames,4,"###");
    system("pause>0");

}

