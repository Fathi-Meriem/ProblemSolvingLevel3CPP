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

bool IsCharacterVowel(char ch1) {
	char c = tolower(ch1);
	return(c == 'a' || c == 'o' || c == 'u' || c == 'e' || c == 'i' || c == 'u');
}
short CountVowelInString(string S1) {
	short counter=0;
	for (short i = 0; i < S1.length(); i++) {
		if (IsCharacterVowel(S1[i]))
			counter++;

	}
	return counter;
}


int main()
{
	short counter;
	string S1 = ReadString();
	counter = CountVowelInString(S1);
	cout << "The string contains " << counter << " vowels";
	cout << endl << endl;
	cin.get();
	system("pause");
	return 0;
}