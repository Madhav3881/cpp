#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student{
  private:
    int student_id;// private integer type for storing student ids
    int marks;// private int type for storing marks of students
    
    public:
    Student(){   
    }
    Student(int sid, int m){
        student_id = sid;
        marks = m;
    }                          // constructor function for initializing student id and student marks
    int get_id(){
        return student_id;
    }                         // member function returning student id.
    int get_marks(){
        return marks;
    }                        // member function returning marks of the student. 
};

class School{
    private:
    Student* students;    //creating pointer of the type Student. 
    int size;           // private int type variable for storing size the input i.e. n
    
    public:
    School(int n){
       students = new Student[n]; 
       size = n; 
    }                               // constructor function for creating an array object of the type Student.
    ~School(){
        delete [] students;
    }                        // destructor function for deleting the space allocated to the Student object.
    void read_students(){
        int id;
        int m;
        for(int i =0; i<size; i++){
            cin>> id >>m;           // reading inputs id and marks for each line.  
        Student s = Student(id,m);      //creating a variable s of the type Student and storing the id and marks in it.
            students[i] = s; // storing the id and marks in the ith space of the students array.
        }
    }
    void sort(){
        for(int i= 1; i<size; i++){     //outer loop for selecting the values in the array for testing.
            int id = students[i].get_id();
            int m = students[i].get_marks();
            Student temp = Student(id,m);   // storing the value of the selected element in a temporary variable.
            for(int j = i-1; j>=0; j--){    //inner loop for testing the selected element with the ones prior to it one by one
                if(temp.get_marks() > students[j].get_marks()){ // codition checking for descending order
                    students[j+1] = students[j];    //swapping the elements
                    students[j] = temp;
                }
            }
        }
        for(int i = 0; i<size; i++){    //printing the array 
            cout<<students[i].get_id() <<" ";
        }
        cout<<"\n";
    }
    int linear_search(int marks){
        int id =-1;     //declearing an integer type variable for returning id and initilizing it to -1.
        sort();
        int pivot;  //variable for storing the value of pivot or middle element.
        int l = 0;  // lower bound index of the searching area.
        int u = size-1; // upper bound of the searching area.
        int index;  //index of the pivot element
        while(pivot != marks){  // loop until the searched value is found
            if(l > u){  // if the array does not have the value being searched
                id = -1;
                break;
            }
            index =(u + l)/2;   //middle index
            pivot = students[index].get_marks();    //marks value of middle index
            if(pivot > marks){  
                l = index + 1;
            }                       //comparing marks with pivot and changing the upper and lower bounds as required
            else if(pivot < marks){
                u = index - 1;
            }
            else if(pivot == marks){
                id = students[index].get_id();  
            }
        }
        return id;
    }
};


int main() {
    int n, id;      //declearing integer type id and n for takeing input
    cin >> n;       //takeing the input size and storing it in n
    School sch = School(n); //decreaging a class variable sch.
    sch.read_students();    //calling the read_students function from the class variable sch. 
    cin >> id;  // reading the input id and storing it in id
    cout << sch.linear_search(id) << endl;  // calling the linear search function from the class variable sch.
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
