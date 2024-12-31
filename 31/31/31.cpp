#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
char ReadCharacter()
{
	char character;
	cout << "Please Enter a  character to check?\n";
	cin >> character;
	return character;
}
short CountCharacter(string S1, char Letter) {
	short counter = 0;
	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] == Letter)
			counter++;
	}
	return counter;
}
short CountCharacterIgnoringCase(string S1, char Letter) {
	short counter = 0;
	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] == toupper(Letter) || S1[i] == tolower(Letter))
			counter++;
	}
	return counter;
}
short CountLetter(string S1, char ch1, bool MatchCase = true) {
	short count=0;
	for (short i = 0; i < S1.length(); i++) {
		if (MatchCase) {
			if (S1[i] == ch1)
				count++;
		}
		else if (tolower(S1[i]) == tolower(ch1)) {
			count++;
		}
	}
	return count;
}
int main()
{
	string S1 = ReadString();
	char Letter = ReadCharacter();
	short counter0 = 0,counter1=0;
	counter0 = CountCharacter(S1, Letter);
	cout << "first method\n";
	cout << "\nThe number of repetition of the  character in the string is: " << counter0;
	cout << endl;
	counter1 = CountCharacterIgnoringCase(S1, Letter);
	cout << "\nThe number of repetition of the  character in the string ignoring case is: " << counter1;
	cout << endl << endl;



	cout << "second method \n";
	counter1 = CountLetter(S1, Letter);
	cout << "\nThe number of repetition of the  character in the string is: " << counter1;
	cout << endl;
	counter1 = CountLetter(S1, Letter, false);
	cout << "\nThe number of repetition of the  character in the string ignoring case is: " << counter1;
	cout << endl << endl;
	cin.get();
	system("pause");
	return 0;
}