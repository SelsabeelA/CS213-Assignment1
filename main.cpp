// Author1: Selsabeel Asim Ali Elbagir
// ID1: 20210714

//Author2:

//Author3:

//Date: 2022/10/09
// Second year, semester 1.
//Course:CS213 Object Oriented Programming
//Professor: Dr.El-Ramly

#include "BigDecimalInt.h"

int main(){
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4(21322323123);
    BigDecimalInt num5(124343243279);
    cout << "num1 = " << num1 << endl; // initialized from integer
    cout << "num2 = " << num2 << endl; // positive sign
    //cout << "num3 = " << num3 << endl; // negative
    //cout << "num4 = " << num4 << endl; // initialized from integer
    //cout << "num5 = " << num5 << endl;
    cout << "num1 - num2 = " << (num1 - num2) << endl;
    if(num1>num2){
        cout << "num1 is larger";
    }
    else cout << "num2 is larger";
}
