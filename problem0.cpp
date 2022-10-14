// Author: Selsabeel Asim Ali Elbagir
// ID: 20210714
//Date: 2022/10/09
// Second year, semester 1.
//Course:CS213 Object Oriented Programming
//Professor: Dr.El-Ramly
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    string sentence;
    int spaces = 0;
    cout << "Please enter your sentence: ";
    getline(std::cin,sentence);
    int length = sentence.length();
    for(int i=0;i<length;i++){
        sentence[i] = tolower(sentence[i]);
        if(sentence[i]==' '){
            spaces++;
            if(spaces>1){
                sentence.erase(sentence.begin() + i);
                i--;
            }
        }
        else{
            spaces =0;
        }
    }
    sentence[0] = toupper(sentence[0]);
    cout << sentence;
}

//example : the     Answer     to life, the    Universe, and     everything IS 42.