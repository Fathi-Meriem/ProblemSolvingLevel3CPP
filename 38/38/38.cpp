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

string TrimLeft(string S1) {
	string delim =" ";
	while (S1.find(delim) == 0) {
	
		S1 = S1.substr(1);
	}
	return S1;
}
string TrimRight(string S1) {
	string delim = " ";
	while (S1.find(delim) == S1.length()-1) {

		S1 = S1.substr(S1.length() - 1,1);
	}
	return S1;

}

int main(){
	string S1 = ReadString();
	cout<< endl;
	cout << "Trim Left:"<< TrimLeft(S1) << endl;
	cout << "Trim right:" << TrimRight(S1)<< endl;
	cout << "Trim      :" << TrimLeft(TrimRight(S1))<< endl;
	system("pause>0");
  
}

