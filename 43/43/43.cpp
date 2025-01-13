#include <string>
#include <iostream>
#include<vector>
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
	vector <string> ::iterator iter = vNames.end();
	string OneString;
	while (iter != vNames.begin())
	{
		iter--;
		OneString.append(*iter);
		OneString.append(Delim);
	}
	return OneString.substr(0, OneString.length() - Delim.length());

}
string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}
string ReplaceWords(string S1, string word,string newWord,bool MatchCase) {
	    vector <string> vStrings;
		 vStrings=Split(S1, " ") ;

		for (string Word : vStrings) {
			if (MatchCase) {
				if (Word == word) {
					Word = newWord;
				}
			}
			else {
				if (LowerAllString(Word) == LowerAllString(word)) {
					Word = newWord;
				}
			}
		}
		return JoinNamesInVector(vStrings, " ");

}

int main()
{
	string S1 = "Welcome Fathi Meriem to Morocco";
	cout << S1 << endl << endl;

	cout << "The string after changing words (Match Case) is: \n" << ReplaceWords(S1, "Morocco", "Jordan"," ") << endl;
	cout << "The string after changing words (Don't Match Case) is: \n" << ReplaceWords(S1, "morocco", "Jordan"," ") << endl;

	system("pause>0");


}

