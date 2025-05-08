/*
    Department maintains a student information. 
    The file contains roll number, name, division and address.
    Allow user to add, delete information of student.
    Display information of particular employee. 
    If record of student does not exist an appropriate message is displayed.
    If it is, then the system displays the student details. 
    Use sequential file to main the data.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SequentailFile {
    string name, address;
    int rno , targetRno;
    char div;

    public :
        void addInfo() {
            ifstream fin("student.txt"); //to read and write.
            
            bool found = false;
            cout<<"\nEnter Roll Number of student : ";
            cin>>targetRno;

            while(fin >> rno) { //it reads the roll no from the file.
                fin.ignore();
                getline(fin, name, ' ');
                fin >> div;
                fin.ignore();
                getline(fin, address);

                if(rno == targetRno) {
                    found = true;
                    cout<<"Student record already present."<<endl;
                    fin.close();
                    break;
                }
            }

            if(found == false) {
                ofstream fout("student.txt", ios::app);

                cout<<"Enter Name : ";
                cin.ignore();
                getline(cin, name);
                cout<<"Enter Division : ";
                cin>>div;
                cout<<"Enter Address : ";
                cin.ignore();
                getline(cin, address);

                fout << targetRno << " " << name << " " << div << " " << address << endl;
                fout.close();
                cout<<"Student added successfully."<<endl;
            }

        }

        void deleteInfo() {
            ifstream fin("student.txt");  //To read
            ofstream tempOut("temp.txt"); //To write
            
            bool found = false;
            cout<<"\nEnter Roll Number of student to delete : ";
            cin>>targetRno;

            while(fin >> rno) { //it reads the roll no from the file.
                fin.ignore();
                getline(fin, name, ' ');
                fin>>div;
                fin.ignore();
                getline(fin, address);

                if(rno == targetRno) {
                    found = true;
                    continue;
                }
                tempOut << rno << " " << name << " " << div << " " << address << endl;
            }

            fin.close();
            tempOut.close();
            remove("student.txt");
            rename("temp.txt" , "student.txt");

            if(found) cout<<"Record deleted successfully."<<endl;
            else cout<<"Record not found."<<endl;
        }

        void searchInfo() {
            ifstream fin("student.txt");

            bool found = false;
            cout<<"\nEnter Roll Number of student to search : ";
            cin>>targetRno;

            while(fin >> rno) {
                fin.ignore();
                getline(fin, name, ' ');
                fin>>div;
                fin.ignore();
                getline(fin,address);

                if(rno == targetRno) {
                    found = true;
                    cout<<"<--- Student Details --->"<<endl;
                    cout<<"Roll Number : "<<rno<<endl;
                    cout<<"Name : "<<name<<endl;
                    cout<<"Division : "<<div<<endl;
                    cout<<"Address : "<<address<<endl;
                    break;
                }
            }

            if(found == false) cout<<"Student record not found"<<endl;
            fin.close();
        }
};

int main() {

    SequentailFile obj;

    while(true) {
        int ch;
        cout<<"\n1. Add information of student."<<endl;
        cout<<"2. Delete information of student."<<endl;
        cout<<"3. Display information of particular student."<<endl;
        cout<<"4. Exit."<<endl;
        cout<<"Select the valid option : ";
        cin>>ch;

        if(ch == 1) obj.addInfo();
        else if(ch == 2) obj.deleteInfo();
        else if(ch == 3) obj.searchInfo();
        else if(ch == 4) {
            cout<<"\nExiting successfully...!"<<endl;
            break;
        }
        else cout<<"\nInvalid option !!!"<<endl;
    }
    return 0;
}