#include <iostream>
#include <string>
using namespace std;

string UpOfFirstLetterOfEachWorld(string object) {
  
    bool IsFirstLetter = true;
    for (short i = 0; i < object.length(); i++) {
        if (object[i] != ' ' && IsFirstLetter) {
            object[i]=toupper(object[i]);
        }
        IsFirstLetter = (object[i] == ' ' ? true : false);
    }
    return object;
}
int main()
{
    string object;
    object= UpOfFirstLetterOfEachWorld("LouLou cava c'est meriem et karima");
    cout << object;
  
    system("pause>0");
}

