
#ifndef UNTITLED1_BIGDECIMALINT_H
#define UNTITLED1_BIGDECIMALINT_H


#include<iostream>
using namespace std;

class BigDecimalInt{
public:
    BigDecimalInt (std::string decStr); // Initializes from string & rejects bad input
    BigDecimalInt (int decInt); // Initialize from integer
    BigDecimalInt operator+ (BigDecimalInt anotherDec); // member fn
    BigDecimalInt operator- (BigDecimalInt anotherDec); // member fn
    bool operator< (BigDecimalInt anotherDec); // member fn

    bool operator> (BigDecimalInt anotherDec); // member fn
    bool operator==(BigDecimalInt anotherDec); // member fn
    BigDecimalInt operator= (BigDecimalInt anotherDec); // member fn
    int size(); // member fn
    int sign(); // member fn
    // overwrite the << operator as follows: (as friend or external function)
    friend ostream& operator << (ostream& out, BigDecimalInt b);

private:
    std::string BigDeci;
};


#endif //UNTITLED1_BIGDECIMALINT_H
