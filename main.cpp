#include "BigDecimalInt.h"

int main(){
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}
