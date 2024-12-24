#include <iostream>
#include <string>
using namespace std;
string ReadString() {
    string expression;
    cout << "Enter the string\n";
    getline(cin, expression);
    return expression;
}
string UpOfLettersOfString(string object) {

    bool IsFirstLetter = true;
    for (short i = 0; i < object.length(); i++) {

        object[i] = toupper(object[i]);
    }
    return object;
}
string DownOfLettersOfString(string object) {

    bool IsFirstLetter = true;
    for (short i = 0; i < object.length(); i++) {
        object[i] = tolower(object[i]);

    }
    return object;
}
int main()
{
    string object = ReadString();
    object = UpOfLettersOfString(object);
    cout << "All the world in CapitalCase: \n" << object << endl;
    object = DownOfLettersOfString(object);
    cout << "All the world in CapitalCase: \n" << object << endl;
    cout << object;
    system("pause>0");
}

