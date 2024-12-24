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
int main()
{
	string S1 = ReadString();
	char Letter = ReadCharacter();
	short counter = 0;
	counter = CountCharacter(S1, Letter);
	cout << "\nThe number of repetition of the  character in the string is: " << counter;
	cout << endl << endl;
	cin.get();
	system("pause");
	return 0;
}