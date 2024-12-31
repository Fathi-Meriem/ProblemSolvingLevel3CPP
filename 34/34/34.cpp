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
void PrintVowelInString(string S1) {
	for (short i = 0; i < S1.length(); i++) {
		if (IsCharacterVowel(S1[i]))

			cout << S1[i] << "  ";
	}

}


int main()
{
	
	string S1 = ReadString();
	PrintVowelInString(S1);
	cout << endl << endl;
	cin.get();
	system("pause");
	return 0;
}