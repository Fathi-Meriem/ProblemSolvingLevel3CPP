#include <iostream>
#include <string>
using namespace std;

void FirstLetterOfEachWorld(string object) {
    bool IsFirstLetter = true;
    for (short  i = 0; i < object.length(); i++) {
        if (object[i] != ' '&& IsFirstLetter) {
            cout<<object.at(i)<<endl;
        }
        IsFirstLetter = (object[i] == ' ' ? true : false);
   }
}
int main()
{
    FirstLetterOfEachWorld("LouLou Cava C'est Meriem et Karima");
    system("pause>0");
}

