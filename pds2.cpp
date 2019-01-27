#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DateCalculator{
    private:
    int d;
    int m;
    int y;
    int day;
    int plus =0;
    
    public:
    DateCalculator(){
        d = 1;
        m = 1;
        y = 2018;
    }
    DateCalculator(int dd){
        if(dd>=1 && dd<=365){
            if(dd > 334){
                d = dd-334;
                m = 12;
            }
            else if(dd > 304){
                d = dd-304;
                m = 11;
            }
            else if(dd > 273){
                d = dd-273;
                m = 10;
            }
            else if(dd > 243){
                d = dd-243;
                m = 9;
            }
            else if(dd > 212){
                d = dd-212;
                m = 8;
            }
            else if(dd > 181){
                d = dd-181;
                m = 7;
            }
            else if(dd > 151){
                d = dd-151;
                m = 6;
            }
            else if(dd > 120){
                d = dd-120;
                m = 5;
            }
            else if(dd > 90){
                d = dd-90;
                m = 4;
            }
            else if(dd > 59){
                d = dd-59;
                m = 3;
            }
            else if(dd > 31){
                d = dd-31;
                m = 2;
            }
            else{
                d = dd;
                m =1;
            }
        }
        else{
            cout<<"error";
        }
    }
    DateCalculator(int dd, int mm){
        if(mm<= 12 &&mm>= 1){
            if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
                if(dd<= 31 && dd>= 1){
                    d = dd;
                    m = mm;
                    y = 2018;
                }
                else{
                    cout<<"error";
                }
            }
            else if(mm == 2 && dd <= 29 && dd >= 1){
                d = dd;
                m = mm;
                y = 2018;
            }
            else{
                if(dd<= 30 && dd>=1){
                    d = dd;
                    m = mm;
                    y = 2018;
                }
                else{
                    cout<<"error";
                }
            }
        }
        else{
            cout<<"error";
        }
    }
    void setdate(int dd, int mm){
        if(mm<= 12 &&mm>= 1){
            if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
                if(dd<= 31 && dd>= 1){
                    d = dd;
                    m = mm;
                }
                else{
                    cout<<"error";
                }
            }
            else if(mm == 2 && dd <= 29 && dd >= 1){
                d = dd;
                m = mm;
            }
            else{
                if(dd<= 30 && dd>=1){
                    d = dd;
                    m = mm;
                }
                else{
                    cout<<"error";
                }
            }
        }
        else{
            cout<<"error";
        }
    }
    void print(){
        if(m == 1){
            day = d;
        }
        else if(m == 2){
            day = d+31;
        }
        else if(m == 3 && y%4 == 0){
            day = d+60;
        }
        else if(m == 3){
            day = d+59;
        }
        else if(m == 4 && y%4 == 0){
            day = d+91;
        }
        else if(m == 4){
            day = d+90;
        }
        else if(m == 5 && y%4 == 0){
            day = d+121;
        }
        else if(m == 5){
            day = d+120;
        }
        else if(m == 6 && y%4 == 0){
            day = d+152;
        }
        else if(m == 6){
            day = d+151;
        }
        else if(m == 7 && y%4 == 0){
            day = d+182;
        }
        else if(m == 7){
            day = d+181;
        }
        else if(m == 8 && y%4 == 0){
            day = d+213;
        }
        else if(m == 8){
            day = d+212;
        }
        else if(m == 9 && y%4 == 0){
            day = d+244;
        }
        else if(m == 9){
            day = d+243;
        }
        else if(m == 10 && y%4 == 0){
            day = d+274;
        }
        else if(m == 10){
            day = d+273;
        }
        else if(m == 11 && y%4 == 0){
            day = d+305;
        }
        else if(m == 11){
            day = d+304;
        }
        else if(m == 12 && y%4 == 0){
            day = d+335;
        }
        else if(m == 12){
            day = d+334;
        }
        int dev = day+plus;
        int dow = dev%7;
        if(dow == 1){
            cout<<"Monday, ";
        }
        else if(dow == 2){
            cout<<"Tuesday, ";
        }
        else if(dow == 3){
            cout<<"Wednesday, ";
        }
        else if(dow == 4){
            cout<<"Thursday, ";
        }
        else if(dow == 5){
            cout<<"Friday, ";
        }
        else if(dow == 6){
            cout<<"Saturday, ";
        }
        else if(dow == 0){
            cout<<"Sunday, ";
        }
        if(m == 1){
            cout<<"January ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 2){
            cout<<"Feburary ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 3){
            cout<<"March ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 4){
            cout<<"April ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 5){
            cout<<"May ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 6){
            cout<<"June ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 7){
            cout<<"July ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 8){
            cout<<"August ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 9){
            cout<<"September ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 10){
            cout<<"October ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 11){
            cout<<"November ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
        if(m == 12){
            cout<<"December ";
            cout<<d;
            cout<<", ";
            cout<<y;
        }
    }
    void plusday(int days){
        int limit = (125*366)+(375*365);
        int year = 2018;
        int l = day+days;
        int month;
        if(l > limit){
            d = -1;
            m = -1;
            y = -1;
            cout<<"a date not in the range";
        }
        else{
            while(year<= 2518 && l>364){
                if(year%4 == 0){
                    l = l-366;
                    plus = plus+366;
                }
                else{
                    l = l-365;
                    plus = plus+365;
                }
                year = year+1;
            }
            if(year%4 == 0){
                if(l > 335){
                    month = 12;
                    l = l-335;
                }
                else if(l > 305){
                    month = 11;
                    l = l-305;
                }
                else if(l > 274){
                    month = 10;
                    l = l-274;
                }
                else if(l > 244){
                    month = 9;
                    l = l-244;
                }
                else if(l > 213){
                    month = 8;
                    l = l-213;
                }
                else if(l > 182){
                    month = 7;
                    l = l-182;
                }
                else if(l > 152){
                    month = 6;
                    l = l-152;
                }
                else if(l > 121){
                    month = 5;
                    l = l-121;
                }
                else if(l > 91){
                    month = 4;
                    l = l-91;
                }
                else if(l > 60){
                    month = 3;
                    l = l-60;
                }
                else if(l > 31){
                    month = 2;
                    l = l-31;
                }
                else{
                    month = 1;
                }
            }
            if(l > 334){
                month = 12;
                l = l-334;
            }
            else if(l > 304){
                month = 11;
                l = l-304;
            }
            else if(l > 273){
                month = 10;
                l = l-273;
            }
            else if(l > 243){
                month = 9;
                l = l-243;
            }
            else if(l > 212){
                month = 8;
                l = l-212;
            }
            else if(l > 181){
                month = 7;
                l = l-181;
            }
            else if(l > 151){
                month = 6;
                l = l-151;
            }
            else if(l > 120){
                month = 5;
                l = l-120;
            }
            else if(l > 90){
                month = 4;
                l = l-90;
            }
            else if(l > 59){
                month = 3;
                l = l-59;
            }
            else if(l > 31){
                month = 2;
                l = l-31;
            }
            else{
                month = 1;
            }
            d = l;
            m = month;
            y = year;
            print();
        }
    }
};

int main() {
    int a;
    int b;
    int c;
    cin>>a >>b >>c;
    cout<<c;
    cout<<" days after ";
    DateCalculator cal = DateCalculator(b,a);
    cal.print();
    cout<<" is ";
    cal.plusday(c);
    
    return 0;
}