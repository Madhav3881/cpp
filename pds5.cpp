#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class City{
    private:
        long int city_id;
        long long int city_population;
        long int state_id;

    public:
        City(){

        }

        City(long int cid, long long int cp){
            city_id = cid;
            city_population = cp;
        }
    
        City(int c_id, long int s_id, long long int c_p ){
            city_id = c_id;
            state_id = s_id;
            city_population = c_p;
        }
    
        long int getStateId(){
            return state_id;
        }

        long int getCityId(){
            return city_id;
        }

        long long int getCityPopulation(){
            return city_population;
        }
    
};

class State{
    private:
        long int state_id;
        City* cities;
        long int numCities;
        long long int totalStatePopulation;

    public:
        State(){

        }

        State(long int sid, long int nc){
            state_id = sid;
            numCities = nc;
            cities = new City[nc];
        }

        // ~State(){
        //     delete [] cities;
        // }

        long int getStateId(){
            return state_id;
        }

        long int getNumCities(){
            return numCities;
        }

        void readStateDetails(){
            long int cid;
            long long int cp;
            for(int i = 0; i < numCities; i++){
                cin>>cid >> cp;
                cities[i] = City(cid, state_id, cp);
            }
        }
    
        City* MergeSort(long int l,long int h){
            long int a = (h+l)/2;
            if(l >= h){
                return &cities[a];
            }
            City *c1 = MergeSort(l,a);
            City *c2 = MergeSort(a+1,h);
            // City* c = new City[h-l+1];
            City* c = (City* )malloc(sizeof(City)* (h-l+1));
            long int i = 0;
            long int j = 0;
            long int k = 0;
            while(i < (a-l+1) && j < (h-a)){
                if(c1[i].getCityPopulation() > c2[j].getCityPopulation()){
                    c[k] = c1[i];
                    i++;
                    k++;
                }
                else{
                    c[k] = c2[j];
                    j++;
                    k++;
                }
            }
            while(i < (a-l+1)){
                c[k] = c1[i];
                i++;
                k++;
            }
            while(j < (h-a)){
                c[k] = c2[j];
                j++;
                k++;
            }
            return c;
        }

        City* sortCitiesOfState(){
            return MergeSort(0,numCities-1);
        }

        void setTotalStatePopulation(){
            totalStatePopulation = 0;
            for(int i = 0; i < numCities; i++){
                totalStatePopulation = totalStatePopulation+cities[i].getCityPopulation();
            }
        }

        long long int getTotalStatePopulation(){
            setTotalStatePopulation();
            return totalStatePopulation;
        }
};

class Country{
    private:
        State* states;
        long int numStates;
        long long int total_nc;
        City* cities;
    
    public:
        Country(int n_s){
            numStates = n_s;
            states = new State[n_s];
            total_nc = 0;
        }

        // ~Country(){
        //     delete [] states;
        //     delete [] cities;
        // }

        void readInput(){
            long int sid;
            long int nc;
            for(long int i = 0; i < numStates; i++){
                cin>>sid>>nc;
                
                total_nc = total_nc+nc;
                State *temp = new State(sid, nc);
                states[i] = *temp;
                states[i].readStateDetails();
            }
        }

        void sortAllCities(){
            long int i = 0;
            long int j = 0;
            long long int k;
            long long int size = 0;
            cities = new City[total_nc];
            for(long int a = 0; a < numStates; a++){
                City* c;
                c = states[a].sortCitiesOfState();
                i = 0;
                j = 0;
                k = 0;
                City temp[size + states[a].getNumCities()];
                while(i < size && j < states[a].getNumCities()){
                    if(cities[i].getCityPopulation() > c[j].getCityPopulation()){
                        temp[k] = cities[i];
                        i++;
                        k++;
                    }
                    else{
                        temp[k] = c[j];
                        j++;
                        k++;
                    }
                }
                while(i < size){
                    temp[k] = cities[i];
                    i++;
                    k++;
                }
                while(j < states[a].getNumCities()){
                    temp[k] = c[j];
                    j++;
                    k++;
                }
                size = size + states[a].getNumCities();
                for(long long int i=0;i<size;i++) {
                    cities[i] = temp[i];
                }
            }
            for(long long int i = 0; i < total_nc; i++){
                cout<<cities[i].getStateId()<<" "<<cities[i].getCityId()<<endl;
            }
        }
        
        long long int FindPivot(long int l, long int r){
            State temp;
            long int i = l-1;
            long int j = l;
            for(;j<=r-1;j++) {
                if(states[j].getTotalStatePopulation() <= states[r].getTotalStatePopulation()) {
                    i++;
                    temp = states[i];
                    states[i] = states[j];
                    states[j] = temp;
                }
            }
            temp = states[r];
            states[r] = states[i+1];
            states[i+1] = temp;
            return i+1;
        }    
    
        void QuickSort(long int l, long int r){
            if(l < r){
                long long int index;
                index = FindPivot(l,r);
                QuickSort(l,index-1);
                QuickSort(index+1,r);
            }
        }

        void sortStates(){
            QuickSort(0,numStates-1);
            reverse(states, states+numStates);
            for(long int i = 0; i < numStates; i++){
                cout<<states[i].getStateId();
                cout<<"\n";
            }
        }
        void fun() {
            for(int i=0;i<numStates;i++) {
                cout<<states[i].getTotalStatePopulation()<<endl;
            }
        }
};

int main() {
    
    int nos;
    cin>>nos;
    Country c(nos);
    c.readInput();
    c.sortAllCities();
    c.sortStates();
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}