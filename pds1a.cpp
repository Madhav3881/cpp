#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class House{
    private:
    int size;
    char border = 'X';
    char fill = '*';
    
    public:
    
    House(int s,char c1,char c2) {
        if(s <= 3)
        {
            size = 3;
        }
        else if(s >= 37 )
        {
            size = 37;
        }
        else
        {
            size = s;
        }
        if(c1 >= '!' && c1 <= '~')
        {
            border = c1;
        }
        if(c2 >= '!' && c2 <= '~')
        {
            fill = c2;
        }
    }
    int GetSize(){
        return size;
    }
    int Perimeter(){
        int P = (3*size)+(2*(size+2))+2;
        return P;
    }
    double Area(){
        double A = (size*size)+((sqrt(3)*size*size)/4);
        return A;
    }
    void Grow(){
        if(size < 37){
            size = size+1;
        }
    }
    void Shrink(){
        if(size >3){
            size = size-1;
        }
    }
    void SetBorder(char b){
        if(b>= '!' && b<= '~'){
            border = b;
        }
    }
    void SetFill( char f){
        if(f>= '!' && f<= '~'){
            fill = f;
        }
    }
};

int main() {
    House h(10,'1','2');
    cout<<h.GetSize()<<"\n";
    cout<<h.Perimeter()<<"\n";
    cout<<h.Area()<<"\n";
    h.Grow();
    cout<<h.GetSize()<<"\n";
    h.Shrink();
    cout<<h.GetSize()<<"\n";
    h.SetBorder('g');
    h.SetFill('M');
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
