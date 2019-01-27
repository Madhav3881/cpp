#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Entry{
    private:
        unsigned int bowlerID;
        unsigned int wickets;
    
    public:
        Entry(){

        }

        void makeEntry(unsigned int BowlerID,unsigned int Wickets){
            bowlerID = BowlerID;
            wickets = Wickets;
        }

        unsigned int getID(){
            return bowlerID;
        }

        unsigned int getWickets(){
            return wickets;
        }
};

class ScoreCard{
    private:
        unsigned int series;
        vector<Entry> LeaderBoard;
    
    public:
        ScoreCard(){
            series = 0;
        }

        void readEntries(unsigned int n){
            unsigned int id;
            unsigned int w;
            Entry temp;
            for(unsigned int i = 0; i < n; i++){        //checking for each id and if does not exist then insert at last
                cin>>id >>w;
                if(searchBowler(id) == -1){
                    temp.makeEntry(id, w);
                    LeaderBoard.push_back(temp);    // inserting at last of the vector
                }
                else{
                    w = LeaderBoard[searchBowler(id)].getWickets() + w;
                    LeaderBoard[searchBowler(id)].makeEntry(id, w);
                }
            }
        }

        int searchBowler(unsigned int ID){
            for(int i = 0; i < LeaderBoard.size(); i++){
                if(ID == LeaderBoard[i].getID()){
                    return i;
                }
            }
            return -1;
        }

        void sortEntries(){                                         //sorting the current leader board with inseet sort
            for(unsigned int i = 0; i < LeaderBoard.size(); i++){
                unsigned int id = LeaderBoard[i].getID();
                unsigned int w = LeaderBoard[i].getWickets();
                Entry temp;
                temp.makeEntry(id,w);
                for(int j = i-1; j>=0; j--){
                    if(temp.getWickets() > LeaderBoard[j].getWickets()){
                        LeaderBoard[j+1] = LeaderBoard[j];    //swapping the elements
                        LeaderBoard[j] = temp;
                    }
                    if(temp.getWickets() == LeaderBoard[j].getWickets() && temp.getID() < LeaderBoard[j].getID()){
                        LeaderBoard[j+1] = LeaderBoard[j];    //swapping the elements
                        LeaderBoard[j] = temp;
                    }
                }
            }
        }

        void printEntries(){
            for(unsigned int i = 0; i < LeaderBoard.size(); i++){
                cout<<LeaderBoard[i].getID() <<" " <<LeaderBoard[i].getWickets() <<"\n";
            }
        }  
};

int main() {
    unsigned int numSeries;
    unsigned int numEntries;
    ScoreCard s;
    cin>>numSeries;
    for(unsigned int i = 0; i < numSeries; i++){
        cin>>numEntries;
        s.readEntries(numEntries);
        s.sortEntries();
        cout<<"Leaderboard after Series:"<<i+1 <<"\n";
        s.printEntries();
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
