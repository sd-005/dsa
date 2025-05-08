/*

Read the marks obtained by students of second year in an online examination 
of particular subject. 
Find out maximum and minimum marks obtained in that subject. 
Use heap data structure. 
Analyze the algorithm 
-->
    Operation	        Time Complexity
    Input n elements	O(n)
    Build Max Heap	    O(n log n)
    Build Min Heap	    O(n log n)
    Get Max/Min	        O(1)

*/
#include <iostream>
#include <vector>
using namespace std;

class heap {
    private :
        vector<int> ans;
        
    public :
        void insert() {
            int n;
            cout<<"\nEnter number of students : ";
            cin>>n;

            cout<<"Enter the marks of students [0-100] --> "<<endl;
            ans.clear();               // Clear old data
            ans.push_back(-99);        // Dummy value at index 0
            int marks;
            for(int i = 1; i <=n; i++) {
                cout<<"Roll No. "<<i<<" : ";
                cin>>marks;
                ans.push_back(marks);
            }
            
            cout<<"Marks entered successfully..."<<endl;
        }

        void MaxHeap() {
            if (ans.empty()) {
                cout<<"\nNo marks available."<<endl;
                return;
            }

            int Max[100];
            Max[0] = -999;
            int size = 1;
            while(size < ans.size()) {
                //Max heap algorithm O(logn)
                int index = size;
                Max[index] = ans[index];

                while(index > 1) {
                    int parent = index / 2;
                    if(Max[parent] < Max[index] ) {
                        swap(Max[parent] , Max[index]);
                        index = parent;
                    }
                    else break;
                }
                size++;
            }
            cout<<"\nThe Maximum marks scored in the exam : "<<Max[1]<<endl;
        }

        void MinHeap() {
            if (ans.empty()) {
                cout<<"\nNo marks available."<<endl;
                return;
            }

            int Min[100];
            Min[0] = 999;
            int size = 1;
            while(size < ans.size()) {
                //Min heap algorithm O(logn)
                int index = size;
                Min[index] = ans[index];

                while(index > 1) {
                    int parent = index / 2;
                    if(Min[parent] > Min[index] ) {
                        swap(Min[parent] , Min[index]);
                        index = parent;
                    }
                    else break;
                }
                size++;
            }
            cout<<"\nThe Minimum marks scored in the exam : "<<Min[1]<<endl;
        }
};

int main() {

    heap h;

    while(true) {
        int ch;
        cout<<"\n1. Enter Marks of the students.";
        cout<<"\n2. Display Maximum marks obtained. ";
        cout<<"\n3. Display Minimum marks obtained. ";
        cout<<"\n4. Exit.";
        cout<<"\nSelect valid option : ";
        cin>>ch;

        if(ch == 1) {
            h.insert();
        }
        else if(ch == 2) {
            h.MaxHeap();
        }
        else if(ch == 3) {
            h.MinHeap();
        }
        else if(ch == 4) {
            cout<<"\nExited successfully..."<<endl;
        }
        else cout<<"\nInvalid option !!!"<<endl;
    }
}