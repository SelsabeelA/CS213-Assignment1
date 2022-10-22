// Author1: Selsabeel Asim Ali Elbagir
// ID1: 20210714

//Author2: Nada Ibrahim Khedr Ismail
// ID2: 20210423

//Author3:

//Date: 2022/10/09
// Second year, semester 1.
//Course:CS213 Object Oriented Programming
//Professor: Dr.El-Ramly

#include "BigDecimalInt.h"

int main(){
    BigDecimalInt num1("-123456789012345678901234567890");
    BigDecimalInt num2("-113456789011345678901134567890");
    BigDecimalInt num3("200000000000000000000000000000");
    BigDecimalInt num4("-223456789012345678901234567890");
    BigDecimalInt test1 ("455");
    BigDecimalInt test2 ("500");
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    BigDecimalInt R (num4 - num1);
    cout<<R<<endl;
    if ( num1 <num2)
        cout<<"true";
    else if ( num4== num3)
    {
        cout<<"equal";
    }
    else{ cout << "false";}
}
