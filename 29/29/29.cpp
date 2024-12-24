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
enum TypeOfCase { Upper = 1, Lower = 2, All = 3 };
short CountLetters(string S1,TypeOfCase CaseCount=All) {
	short counter=0;
	for (short i = 0; i < S1.length(); i++) {
		if (CaseCount == All)
			return S1.length();
		if (isupper(S1[i]) && CaseCount == Upper)
			counter++;
		if (islower(S1[i]) && CaseCount == Lower)
			counter++;
	}
	return counter;

}
short CountOfUpperLetters(string S1)
{
	short counter=0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			counter++;
	}
	return counter;
}
short CountOfLowerLetters(string S1)
{
	short counter=0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
			counter++;
	}
	return counter;
}
int main()
{
	string S1 = ReadString();
	short upCounter=0, lowCounter=0;
	upCounter = CountOfUpperLetters(S1);
	lowCounter = CountOfLowerLetters(S1);
	cout << "First Method:\n";
	cout << "The length of the string is: " << S1.length();
	cout << "\nThe number of Upper letters is: " << upCounter;
	cout << "\nThe number of low letters is: " << lowCounter;
	cout << endl << endl;
	cout << "Second Method:\n";
	cout << "The length of the string is: " << CountLetters(S1);
	cout << "\nThe number of Upper letters is: " << CountLetters(S1,Upper);
	cout << "\nThe number of low letters is: " << CountLetters(S1, Lower);
	cout << endl << endl;
	
	cin.get(); 
	return 0;
}