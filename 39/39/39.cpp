
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string JoinNamesInVector(vector <string> vNames, string Delim) {
    string OneString;
    for (string Name : vNames) {
        OneString.append(Name);
        OneString.append(Delim);
    }
    return OneString.substr(0,OneString.length()-Delim.length());

}
using namespace std;
int main()
{
    string OneString;
    vector <string> vNames = { "Meriem","Karima","Souad","Sanaa" };
    OneString = JoinNamesInVector(vNames,"&&&");
    cout << OneString << endl;
    system("pause>0");

}

