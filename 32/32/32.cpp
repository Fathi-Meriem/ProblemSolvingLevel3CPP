#include <string>
#include <iostream>
#include <vector>
using namespace std;

char ReadCharacter()
{
	char character;
	cout << "Please Enter a  character to check?\n";
	cin >> character;
	return character;
}
/*bool IsCharacterVowel(char ch1) {
	vector <char> vCharacters = { 'a', 'e', 'i','u', 'o'};
	for (char c:vCharacters) {
		if (tolower(ch1) == c)
			return true;
		else
			return false;

	}
}*/
bool IsCharacterVowel(char ch1) {
	char c = tolower(ch1);
	return(c == 'a' || c == 'o' || c == 'u' || c == 'e' || c == 'i' || c == 'u');
}

int main()
{
	char c=ReadCharacter();
	if (IsCharacterVowel(c))
		cout << "yes Letter '"<<c<<"' is vowel\n";
	else
		cout << "No Letter '" << c << "' is not vowel\n";
	cout << endl << endl;
	cin.get();
	system("pause");
	return 0;
}