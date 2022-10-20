// Author: Selsabeel Asim Ali Elbagir
// ID: 20210714
//Date: 2022/10/09
// Second year, semester 1.
//Course:CS213 Object Oriented Programming
//Professor: Dr.El-Ramly

#include<iostream>
using namespace std;
template <typename T, int length>

class MyArray{
private:
    T* array;
public:
    MyArray(){ //constructor
        array = new T[length];
        for(int i=0;i<length;i++){
            array[i] = 0;
            // I do this so that all elements are initialized
            // so that it doesn't crash
        }
    }
    MyArray(MyArray& rhs){ //copy constructor
        T* newArray = new T[rhs.size()];
        for(auto i=0;i<length;i++){
            newArray[i] = rhs[i];
        }
        delete[] array; // deletes old values in array
        array = newArray; // copies new values to original array
    }
    ~MyArray(){ //deconstruct
        delete[] array;
    }
    int size(){
        return length;
    }
    T& operator[](int k){
        while(k<0 || k>length){
            cout << "Please enter a valid index number: ";
            cin >> k;
        }
        return (array[k]);
    }
    MyArray& operator=(MyArray rhs){ //overloading the assignment operator
        //if(rhs.size()>=length){ //defensive programming
            for(int i=0; i<length; i++){
                array[i] = rhs.array[i];
            }
        //}
        return *this;
    }

};



int main(){
    MyArray<int, 10> testing;
    cout << "The size is: "<<testing.size() << endl;
    for(int i=0;i<10;i++){
        testing[i] = i;
        cout << testing[i] << endl;
    }


    testing[7] = 10;
    cout << "The 8th element is: " << testing[7] << endl;
    MyArray<int, 10> secondTesting;
    secondTesting = testing;
    secondTesting[7] *= 2;
    cout << "Testing's 8th element is now: " << testing[7] << " .. " << endl
    << "Let's multiply the new array's value by 2!\n"
    << "the new array we copied into's 8th element is now: " << secondTesting[7] << endl;

}