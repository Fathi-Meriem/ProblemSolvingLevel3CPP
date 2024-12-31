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
/*void PritnWordsInString(string S1) {
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ')
			cout << S1[i];
		else cout <<"\n";
	}

}*/

void PritnWordsInString(string S1) {
	string delim = " ";
	string word;
	short pos = 0;
		while ((pos = S1.find(delim)) !=string::npos) {
			word = S1.substr(0, pos);
			if (word != " ")
				cout << word<<endl;
			S1.erase(0, pos + delim.length());
		}
		

		if (S1 != " ")
			cout << S1;

} 




int main()
{

	string S1 = ReadString();
	PritnWordsInString(S1);
	cout << endl << endl;
	cin.get();
	system("pause");
	return 0;
}