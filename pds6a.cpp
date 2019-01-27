#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MyVector{
  private:
    int size;
    int capacity;
    int* base;
    
  public:
    MyVector(){
        size = 0;
        capacity = 1;
        base = new int[capacity];
    }
    
    ~MyVector(){
        delete [] base;
    }
    
    void pushback(int val){
        base[size] = val;       //assigning val at the end of base array
        size++;
        if(size == capacity){
            reserve(capacity*2);      // calling the reserve function with double the capacity 
        }
    }
    
    int popback(){
        if(size == 0){
            return -1;
        }
        else{
            size--;                  // decrimenting size
            return base[size];      //returning the element which was removed
        }
    }
    
    void reserve(int newCapacity){
        int* newArray = new int[newCapacity];  // allocating new space
        for(int i = 0; i < size; i++){
            newArray[i] = base[i];      // putting values from b to new allocated space
        }
        delete [] base;               // deleting old memory
        base = new int[newCapacity];        //reallocating base with new capacity at new memory 
        for(int i = 0; i < size; i++){
            base[i] = newArray[i];
        }
        capacity = newCapacity;
        delete [] newArray;
    }
    
    int vec_size(){
        return size;
    }
    
    int vec_capacity(){
        return capacity;
    }
    
    bool empty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    int at(int index){
        if(index >= size){
            return -1;
        }
        else{
            return base[index];
        }
    }
    
    int front(){
        if(size == 0){
            return -1;
        }
        else{
            return base[0];
        }
    }
    
    int back(){
        if(size == 0){
            return -1;
        }
        else{
            return base[size-1];
        }
    }
    
    void clear(){
        size = 0;
    }
    
    void display(){
        for(int i =0; i < size; i++){
            cout<<base[i] <<" ";
        }
        cout<<endl;
    }
    MyVector & operator= (MyVector & temp){
        size = temp.vec_size();               // setting new size for the operator
        capacity = temp.vec_capacity();          // setting new capacity for the operator
        int* newArray = new int[temp.vec_capacity()];// allocating new memory as done earlier
        for(int i = 0; i < size; i ++){
            newArray[i] = temp.at(i);          
        }
        delete [] base;
        base = new int[capacity];
        for(int i = 0; i < size; i++){
            base[i] = newArray[i];
        }
        delete [] newArray;
            
        return * this;
    }
};

int main() {
    MyVector vec;
    int operations;         // reading the number of inputs operations   
    int param;          
    int index;      // now based on index reading inputs and calling functions and getting outputs
    int output;
    cin>>operations;
    for(int i = 0; i < operations; i++){
        cin>>index;
        if(index == 1){
            cin>>param;
            vec.pushback(param);
        }
        if(index == 2){
            output = vec.popback();
            cout<<output;
            cout<<endl;
        }
        if(index == 3){
            output = vec.vec_size();
            cout<<output;
            cout<<endl;
        }
        if(index == 4){
            output = vec.vec_capacity();
            cout<<output;
            cout<<endl;
        }
        if(index == 5){
            if(vec.empty() == true){
                cout<<"1";
                cout<<endl;
            }
            else{
                cout<<"0";
                cout<<endl;
            }
        }
        if(index == 6){
            cin>>param;
            output = vec.at(param);
            cout<<output;
            cout<<endl;
        }
        if(index == 7){
            output = vec.front();
            cout<<output;
            cout<<endl;
        }
        if(index == 8){
            output = vec.back();
            cout<<output;
            cout<<endl;
        }
        if(index == 9){
            vec.clear();
        }
        if(index == 10){
            vec.display();
        }
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
