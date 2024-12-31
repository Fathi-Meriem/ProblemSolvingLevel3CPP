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


short CountWordsInString(string S1) {
	string delim = " ";
	string word;
	short pos = 0, counter = 0;
	while ((pos = S1.find(delim)) != string::npos) {
		word = S1.substr(0, pos);
		if (word != " ")
			counter++;
		S1.erase(0, pos + delim.length());
	}
	if (S1 != " ")
		counter++;
	return counter;
}




int main()
{

	string S1 = ReadString();
	short counter=CountWordsInString(S1);
	cout << "The string contains " << counter << " words";
	cout << endl << endl;
	cin.get();
	system("pause");
	return 0;
}