#include <iostream>
#include <string>
using namespace std;
char ReadCharacter() {
    char character;
    cout << "Enter a character \n";
    cin >> character;
    return character;
}
char InvertLetterCase(char character) {

    return (isupper(character) ? tolower(character):toupper(character));
}
int main()
{
    char  character = ReadCharacter();
    character = InvertLetterCase(character);
    cout << "The character after inverting Case: \n" << character << endl;
    system("pause>0");
}

