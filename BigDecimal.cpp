#include "BigDecimalInt.h"
BigDecimalInt::BigDecimalInt(string decStr) {
    BigDeci = decStr;
}
BigDecimalInt::BigDecimalInt(int decInt) {
    BigDeci = std::to_string(decInt);
}
string Add(string str1, string str2)
{
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int carry = 0;
    if (str1.length() > str2.length())
        swap(str1, str2);
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        // Calculate carry for next step
        carry = sum/10;
    }
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
    // reverse resultant string
    reverse(str.begin(), str.end());
    return str;
}
bool BigDecimalInt:: operator<(BigDecimalInt another_Dec){    // check the negative cases
    int n1 = BigDeci.length() ;
    int n2 = another_Dec.BigDeci.length();
    if(sign() > 0 && another_Dec.BigDeci[0] != '-'){
        if (n1<n2){
            return true;
        }
        else if (n1>n2){
            return false;
        }
        for (int i =0 ; i < n1 ; i++){
            if(BigDeci[i] < another_Dec.BigDeci[i]){
                return true;
            }
            if (BigDeci[i] > another_Dec.BigDeci[i]){
                return false;
            }
        }
    }
    if(sign()< 0 && another_Dec.BigDeci[0] == '-'){
        if (n1<n2){
            return true;
        }
        else if (n1>n2){
            return false;
        }
        for (int i =1 ; i < n1 ; i++){
            if(BigDeci[i] < another_Dec.BigDeci[i]){
                return true;
            }
            if (BigDeci[i] > another_Dec.BigDeci[i]){
                return false;
            }
        }
    }
    else if (BigDeci[0] == '-' && another_Dec.BigDeci[0] != '-'){
        return true;
    }
    else if ( BigDeci[0] != '-' && another_Dec.BigDeci[0] == '-'){
        return false;
    }
    return false;
}
string BigDecimalInt:: subtract(BigDecimalInt anotherDec){
    BigDecimalInt BigDec_container (BigDeci);
    string str1_origin = BigDeci ,  str2_origin = anotherDec.BigDeci;
    if(BigDec_container < anotherDec){
        swap(BigDec_container.BigDeci, anotherDec.BigDeci);}
    string result = "";
    int n1 = BigDec_container.BigDeci.length() , n2 =anotherDec.BigDeci.length();
    reverse(BigDec_container.BigDeci.begin(), BigDec_container.BigDeci.end());
    reverse(anotherDec.BigDeci.begin() , anotherDec.BigDeci.end());
    int carry =0 ;
    for (int i=0 ; i<n2 ; i++ ){
        int  sub = ((BigDec_container.BigDeci[i] - '0')- (anotherDec.BigDeci[i] - '0') - carry);
        if (sub < 0){
            sub = sub + 10;
            carry =1;
        }
        else {
            carry = 0;
        }
        result.push_back(sub+ '0');
    }
    for (int i=n2 ; i<n1 ; i++){
        int  sub = ((BigDec_container.BigDeci[i] - '0')-carry);
        if (sub < 0){
            sub += 10;
            carry =1;
        }
        else {
            carry = 0;
        }
        result.push_back(sub+ '0');
    }
    if (str1_origin <str2_origin){
        result.push_back('-');}
    reverse(result.begin() , result.end());
    return result;
}
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt another_Dec) {
    BigDecimalInt result("");
    string temp;
    if (BigDeci[0] == '+' && another_Dec.BigDeci[0] == '+' ){ // if both number start with + remove it
        BigDeci.erase(remove(BigDeci.begin(), BigDeci.end(), '+'), BigDeci.end());
        another_Dec.BigDeci.erase(remove(another_Dec.BigDeci.begin(), another_Dec.BigDeci.end(), '+'),
                                  another_Dec.BigDeci.end());
}
else if (BigDeci[0] == '+') { // else if only the first starts with + remove it
BigDeci.erase(remove(BigDeci.begin(), BigDeci.end(), '+'), BigDeci.end());
} else if (another_Dec.BigDeci[0] == '+') {  // else if only the second starts with + remove it
another_Dec.BigDeci.erase(remove(another_Dec.BigDeci.begin(), another_Dec.BigDeci.end(), '+'),
        another_Dec.BigDeci.end());
}
if (another_Dec.BigDeci[0] != '-' && BigDeci[0] != '-') { // first case that both numbers are +ve
// if (another_Dec.BigDeci[0] == '+') {
// 1- the first num is bigger than the second
result.BigDeci +=( subtract( another_Dec));
}
temp.clear();
if (another_Dec.BigDeci [0] == '-' && BigDeci[0] != '-'){
// second case if only the second num is negative
another_Dec.BigDeci.erase(remove(another_Dec.BigDeci.begin(), another_Dec.BigDeci.end(), '-'),
        another_Dec.BigDeci.end());
result.BigDeci += Add( BigDeci, another_Dec.BigDeci); // the operation turn into addition
}
temp.clear();
if (another_Dec.BigDeci[0] == '-' && BigDeci[0] == '-'){ // third case that both are negative
// so the first num stay negative and the second become +ve
// we subtract the first num from the second
swap (BigDeci, another_Dec.BigDeci);
BigDecimalInt BigDec_container (BigDeci);
result.BigDeci += subtract(another_Dec );
}
swap (BigDeci, another_Dec.BigDeci);
temp.clear();
if (another_Dec.BigDeci[0] != '-' && BigDeci[0] == '-'){ // fourth case if only the first num is negative
// ,so it turns into addition operation with negative sign
BigDeci.erase(remove(BigDeci.begin(), BigDeci.end(), '-'), BigDeci.end());
result.BigDeci += '-';
result.BigDeci += Add( BigDeci, another_Dec.BigDeci);
}
temp.clear();
return result;
}
bool BigDecimalInt::operator> (BigDecimalInt anotherDec){
    bool switch_sign =1;
    int mainlength, secondlength;
    if(  (BigDeci[0] == '+') || (BigDeci[0] == '-') ){
        mainlength = size() - 1;
    }
    else mainlength = size();

    if(  (anotherDec.BigDeci[0] == '+') || (anotherDec.BigDeci[0] == '-') ){
        secondlength = size() - 1;
    }
    else secondlength = size();

    // this switch variable is put so that if the numbers are both negative
    // it flips the return true/false statement since
    // with negative numbers, the bigger number is the one that is less in absolute value
    if(sign()!=anotherDec.sign()){
        if(sign()==1){ // if the first one is positive
            return true; // then it's bigger
        }
        else return false; // else the first one is negative and it's smaller
    }
    if(sign() == anotherDec.sign() == -1){
        switch_sign = -1;
    }
    if(mainlength!= secondlength){ // if they have differing lengths, assign the bigger one
        if(mainlength>secondlength){
            return (true*switch_sign);
        }
        else return (false*switch_sign);
    }
    int i=0;
    if(mainlength!=BigDeci.length()){
        i++; // this ensures that we don't compare the positive or negative sign
    }
    while(i<BigDeci.length()){
        if(anotherDec.BigDeci[i] < BigDeci[i]){
            return (false*switch_sign);
        }
    }
    return (true*switch_sign);

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
