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

string ReplaceName(string S1, string word,string NewWord) {
	short pos = 0;
	while ((pos = S1.find(word, pos)) != string::npos) { 
		
		S1.replace(pos,word.length(),NewWord);
		  
	}
	
	return S1;
}

int main()
{
	string S1 ="Welcome Fathi Meriem to Morocco";
	cout << S1 << endl << endl;

	cout << "The string after changing words is: \n"<<ReplaceName(S1,"Morocco","Jordan")<<endl;
	
	system("pause");


}

