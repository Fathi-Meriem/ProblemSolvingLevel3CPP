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

vector <string> Split(string S1,string delim) {

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
void PrintVector(vector <string> &vStrings) {
	cout << "Words of Strings are: \n";
	for (string &word:vStrings) {
		cout << word << endl;

	}

}
int main()
{
	string S1 = ReadString();
	vector<string> words = Split(S1, " "); 
	cout << "Tokens= " << words.size()<<endl;
	PrintVector(words);
	
}


