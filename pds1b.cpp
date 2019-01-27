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
    House(int s,char c1,char c2){
        if(s < 3)
            size = 3;
        else if(s > 37)
            size = 37;
        else
            size = s;
        if(c1 <= '~' && c1 >= '!'){
            border = c1;
        }
        if(c2 <= '~' && c2 >= '!'){
            fill = c2;
        }
    }
    int GetSize(){
        return size;
    }
    int Perimeter(int size){
        int P = (3*size)+(2*(size+2))+2;
        return P;
    }
    double Area(int size){
        double A = (size*size)+((sqrt(3)*(size+2)*(size+2))/4);
        return A;
    }
    void Grow(){
        if(size < 37){
            size = size+1;
        }
    }
    void Shrink(){
        if(size > 3){
            size = size-1;
        }
    }
    void SetBorder(char b){
        if(b <= '~' && b >= '!'){
            border = b;
        }
    }
    void SetFill(char f){
        if(f <= '~' && f >= '!'){
            fill = f;
        }
    }
    void Draw(){
        int a = ((size*2)+2)/2;
        for(int i = 0; i < a; i++){
            cout<<" ";
        }
        cout<<border;
        cout<<"\n";
        int i = a-1;
        int j = a+1;
        while(i>0){
            for(int k = 0; k < i; k++){
                cout<<" ";
            }
            cout<<border;
            cout<<" ";
            for(int l = i+1; l < j-1; l++){
                cout<<fill;
                cout<<" ";
                l++;
            }
            cout<<border;
            i--;
            j++;
            cout<<"\n";
        }
        cout<<border;
        cout<<" ";
        cout<<border;
        cout<<" ";
        for(int k = 0;k < (size-2); k++){
            cout<<fill;
            cout<<" ";
        }
        cout<<border;
        cout<<" ";
        cout<<border;
        cout<<" ";
        cout<<"\n";
        for(int k = 0;k < (size-2); k++){
            cout<<"  ";
            cout<<border;
            cout<<" ";
            for(int l = 0;l < (size-2); l++){
                cout<<fill;
                cout<<" ";
            }
            cout<<border;
            cout<<"\n";
        }
        cout<<"  ";
        for(int k = 0;k < size; k++){
            cout<<border;
            cout<<" ";
        }
        cout<<"\n";
    }
};


int main() {
    int a,d,e;
    char b,c,f;
    
    cin>>a >>b >>c >>d >>e >>f;
    
    House h(a,b,c);
    
    h.Draw();
    
    
    if(d == 1)
    {
        h.Grow();
    }
    else
    {
        h.Shrink();
    }
    if(e == 1)
    {
        h.SetBorder(f);
    }
    else{
        h.SetFill(f);
    }
    h.Draw();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}