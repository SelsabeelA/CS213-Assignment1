#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(string decStr) {
    BigDeci = decStr;
}

BigDecimalInt::BigDecimalInt(int decInt) {
    BigDeci = std::to_string(decInt);
}

bool BigDecimalInt::operator> (BigDecimalInt anotherDec){
    for(int i=0;i<BigDeci.length();i++){
        if(anotherDec.BigDeci[i] < BigDeci[i]){
            return false;
        }
    }
    return true;
}

bool BigDecimalInt::operator== (BigDecimalInt anotherDec){
    for(int i=0;i<BigDeci.length();i++){
        if(anotherDec.BigDeci[i] != BigDeci[i]){
            return false;
        }
    }
    return true;
}

BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec){
    for(int i=0;i<BigDeci.length();i++){
        BigDeci[i] = anotherDec.BigDeci[i];
    }
    return BigDeci;
}

int BigDecimalInt::size(){
    return BigDeci.length();
}

int BigDecimalInt::sign(){
    if(BigDeci[0] == '-'){
        return -1;
    }
    else return 1;
}

ostream& operator << (ostream& out, BigDecimalInt b){
    for(int i=0;i<b.BigDeci.length();i++){
        out << b.BigDeci[i];
    }
    return out;
}
