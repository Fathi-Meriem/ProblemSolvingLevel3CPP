#include <string>
#include <iostream>
#include <vector>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
vector <string> Split(string S1, string delim) {

	vector <string> vStrings;
	string word;
	short pos = 0, counter = 0;
	while ((pos = S1.find(delim)) != string::npos) {
		word = S1.substr(0, pos);
		vStrings.push_back(word);
		S1.erase(0, pos + delim.length());
	}
	if (S1 != " ")
		vStrings.push_back(S1);
	return vStrings;
}
string JoinNamesInVector(vector <string> vNames, string Delim) {
	vector <string> ::iterator iter=vNames.end();
	string OneString;
	while(iter != vNames.begin())
	{
		iter--;
		OneString.append(*iter);
		OneString.append(Delim);
	}
	return OneString.substr(0, OneString.length() - Delim.length());

}

int main()
{
	string S1 = ReadString();
	vector <string> vStrings;
	vStrings = Split(S1, " ");
	cout << "The string after inversing is: \n";
	S1= JoinNamesInVector(vStrings," ");
	cout << S1<<endl;
	system("pause");


}

