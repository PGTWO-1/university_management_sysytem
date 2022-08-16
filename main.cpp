#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
using namespace std;
class Person//base class
{
public:
    string name;
    string program;
    string gender;
    int ID;
    int age;
};

class Timetable
{
public:
    string date;
    string course_name;
    int credit;
    string venue;
};
class Student : public virtual Person, public virtual Timetable//Derived class
{
public:
    double CGPA;
};
class Teacher : public virtual Person,public virtual Timetable
{
public:
    int salary;

};

class Admin
{
public:
    vector<Student>Slist;
    vector<Teacher>Tlist;

    int ReadStudent();
    int ReadTeacher();

    void WriteStudent();
    void WriteTeacher();

    void DisplayStudent();
    void DisplayTeacher();

    void AddStudent();
    void AddTeacher();

    void FindStudent();
    void FindTeacher();

    void del_Student();
    void del_Teacher();

    void menu_Student();
    void menu_Teacher();

    void change_Student();
    void change_Teacher();

};
int Admin::ReadStudent()
{
    fstream readfile("Student.txt");
    int tow=0;
    if(readfile)
    {
        Student s;
        if(!(readfile>>s.name>>s.program>>s.gender>>s.ID>>s.age>>s.date>>s.course_name>>s.credit>>s.venue>>s.CGPA))
        {
            cout<<"It is empty"<<endl;
            return 1;
        }
        Slist.push_back(s);
        tow++;
        while(readfile>>s.name>>s.program>>s.gender>>s.ID>>s.age>>s.date>>s.course_name>>s.credit>>s.venue>>s.CGPA)
        {
            tow++;
            Slist.push_back(s);
        }
        cout<<"All the information upload successfully!"<<endl;
        readfile.close();
        return tow;
    }
    else
    {
        ofstream outfile;
        outfile.open("Student.txt");
        if(!outfile.is_open())
        {
            cout<<"Document is not be created!"<<endl;
            return -1;
        }
        else
        {
            cout<<"Document is not exist but it's created!"<<endl;
            cout<<"File is empty!";
        }
        outfile.close();
    }
    return 2;
}
int Admin::ReadTeacher()
{
    fstream readfile("Teacher.txt");
    int wow=0;
    if(readfile)
    {
        Teacher t;
        if(!(readfile>>t.name>>t.program>>t.gender>>t.ID>>t.age>>t.date>>t.course_name>>t.credit>>t.venue>>t.salary))
        {
            cout<<"It is empty"<<endl;
            return 1;
        }
        Tlist.push_back(t);
        wow++;
        while(readfile>>t.name>>t.program>>t.gender>>t.ID>>t.age>>t.date>>t.course_name>>t.credit>>t.venue>>t.salary)
        {
            wow++;
            Tlist.push_back(t);
        }
        cout<<"All the information upload successfully!"<<endl;
        readfile.close();
        return wow;
    }
    else
    {
        ofstream outfile;
        outfile.open("Teacher.txt");
        if(!outfile.is_open())
        {
            cout<<"Document is not be created!"<<endl;
            return -1;
        }
        else
        {
            cout<<"Document is not exist but it's created!"<<endl;
            cout<<"File is empty!";
        }
        outfile.close();
    }
    return 2;
}

void Admin::WriteStudent()
{
    ofstream outfile("Student.txt");
    vector<Student>::iterator iter;
    for(iter=this->Slist.begin(); iter!=this->Slist.end(); iter++)
    {
        outfile<<iter->name<<"\t"<<iter->program<<"\t"<<iter->gender<<"\t"<<iter->ID<<"\t"<<iter->age<<"\t"<<iter->date<<"\t"<<iter->course_name<<"\t"<<iter->credit<<"\t"<<iter->venue<<"\t"<<iter->CGPA<<endl;
    }
    outfile.close();
}
void Admin::WriteTeacher()
{
    ofstream outfile("Teacher.txt");
    vector<Teacher>::iterator iter;
    for(iter=this->Tlist.begin(); iter!=this->Tlist.end(); iter++)
    {
        outfile<<iter->name<<"\t"<<iter->program<<"\t"<<iter->gender<<"\t"<<iter->ID<<"\t"<<iter->age<<"\t"<<iter->date<<"\t"<<iter->course_name<<"\t"<<iter->credit<<"\t"<<iter->venue<<"\t"<<iter->salary<<endl;
    }
    outfile.close();
}

void Admin::DisplayStudent()
{
    vector<Student>::iterator iter;
    for(iter=this->Slist.begin(); iter!=this->Slist.end(); iter++)
    {
        cout<<"Name: "<<iter->name<<"\t"<<"Program: "<<iter->program<<"\t"<<"Gender: "<<iter->gender<<"\t"
        <<"ID: "<<iter->ID<<"\t"<<"Age: "<<iter->age<<"\t"<<"Date: "<<iter->date<<"\t"<<"Course name: "<<iter->course_name<<"\t"<<"Credit: "
        <<iter->credit<<"\t"<<"Venue: "<<iter->venue<<"\t"<<"CGPA: "<<iter->CGPA<<endl;
    }
}
void Admin::DisplayTeacher()
{
    vector<Teacher>::iterator iter;
    for(iter=this->Tlist.begin(); iter!=this->Tlist.end(); iter++)
    {
        cout<<"Name: "<<iter->name<<"\t"<<"Program: "<<iter->program<<"\t"<<"Gender: "<<iter->gender<<"\t"<<"ID: "<<iter->ID<<"\t"<<"Age: "<<iter->age<<"\t"<<"Date: "<<iter->date<<"\t"<<"Course name: "<<iter->course_name<<"\t"<<"Credit: "<<iter->credit<<"\t"<<"Venue: "<<iter->venue<<"\t"<<"Salary: "<<iter->salary<<endl;
    }
}

void Admin::AddStudent()
{
    Student s;
    cout<<"Input Name: ";
    cin>>s.name;
    cout<<"Input Program: ";
    cin>>s.program;
    cout<<"Input Gender: ";
    cin>>s.gender;
    cout<<"Input ID: ";
    cin>>s.ID;
    cout<<"Input Age: ";
    cin>>s.age;
    cout<<"Input Date: ";
    cin>>s.date;
    cout<<"Input Course name: ";
    cin>>s.course_name;
    cout<<"Input Credit: ";
    cin>>s.credit;
    cout<<"Input Venue: ";
    cin>>s.venue;
    cout<<"Input CGPA: ";
    cin>>s.CGPA;
    Slist.push_back(s);
    this->WriteStudent();
}
void Admin::AddTeacher()
{
    Teacher t;
    cout<<"Input Name: ";
    cin>>t.name;
    cout<<"Input Program: ";
    cin>>t.program;
    cout<<"Input Gender: ";
    cin>>t.gender;
    cout<<"Input ID: ";
    cin>>t.ID;
    cout<<"Input Age: ";
    cin>>t.age;
    cout<<"Input Date: ";
    cin>>t.date;
    cout<<"Input Course name: ";
    cin>>t.course_name;
    cout<<"Input Credit: ";
    cin>>t.credit;
    cout<<"Input Venue: ";
    cin>>t.venue;
    cout<<"Input Salary: ";
    cin>>t.salary;
    Tlist.push_back(t);
    this->WriteTeacher();
}

void Admin::FindStudent()
{
    string _name;
    cout<<"Input student name: ";
    cin>>_name;
    vector<Student>::iterator iter;
    for(iter=this->Slist.begin(); iter!=this->Slist.end(); iter++)
    {
        if(iter->name == _name)
        {
            cout<<"Name: "<<iter->name<<"\t"<<"Program: "<<iter->program<<"\t"<<"Gender: "<<iter->gender<<"\t"<<"ID: "
            <<iter->ID<<"\t"<<"Age: "<<iter->age<<"\t"<<"Date: "<<iter->date<<"\t"<<"Course name: "<<iter->course_name<<"\t"<<"Credit: "<<iter->credit<<"\t"
            <<"Venue: "<<iter->venue<<"\t"<<"CGPA: "<<iter->CGPA<<endl;
        }
    }
}
void Admin::FindTeacher()
{
    string _name;
    cout<<"Input teacher name: ";
    cin>>_name;
    vector<Teacher>::iterator iter;
    for(iter=this->Tlist.begin(); iter!=this->Tlist.end(); iter++)
    {
        if(iter->name == _name)
        {
            cout<<"Name: "<<iter->name<<"\t"<<"Program: "<<iter->program<<"\t"<<"Gender: "<<iter->gender<<"\t"<<"ID: "<<iter->ID<<"\t"<<"Age: "<<iter->age<<"\t"<<"Date: "<<iter->date<<"\t"<<"Course name: "<<iter->course_name<<"\t"<<"Credit: "<<iter->credit<<"\t"<<"Venue: "<<iter->venue<<"\t"<<"Salary: "<<iter->salary<<endl;
        }
    }
}

void Admin::del_Student()
{
    if(Slist.empty())
    {
        cout<<"Nothing to delete!"<<endl;
    }
    string _name;
    cout<<"Input student name: ";cin>>_name;
    vector<Student>::iterator iter;
    for(iter=this->Slist.begin(); iter!=this->Slist.end();)
    {
        if(iter->name == _name)
        {
            Slist.erase(iter);
            this->WriteStudent();
            cout<<"Delete Successfully!"<<endl;
        }
        else
            ++iter;
    }

}
void Admin::del_Teacher()
{
    if(Tlist.empty())
    {
        cout<<"Nothing to delete!"<<endl;
    }
    string _name;
    cout<<"Input teacher name: ";cin>>_name;
    vector<Teacher>::iterator iter;
    for(iter=this->Tlist.begin(); iter!=this->Tlist.end();)
    {
        if(iter->name == _name)
        {
            Tlist.erase(iter);
            this->WriteTeacher();
            cout<<"Delete Successfully!"<<endl;
        }
        else
            ++iter;
    }
}

void Admin::change_Student()
{
    string _name;
    cout<<"Input the name of the student you want to change: ";cin>>_name;
    vector<Student>::iterator iter;
    for(iter=this->Slist.begin(); iter!=this->Slist.end();)
    {
        if(iter->name == _name)
        {
            cout<<"Input the CGPA: ";cin>>iter->CGPA;
            this->WriteStudent();
        }
        else
            ++iter;
    }
    cout<<"Don't find this student!"<<endl;
}
void Admin::change_Teacher()
{
    string _name;
    cout<<"Input the name of the teacher you want to change: ";cin>>_name;
    vector<Teacher>::iterator iter;
    for(iter=this->Tlist.begin(); iter!=this->Tlist.end();)
    {
        if(iter->name == _name)
        {
            cout<<"Input the Salary: ";cin>>iter->salary;
            this->WriteTeacher();
        }
        else
            ++iter;
    }
    cout<<"Don't find this teacher!"<<endl;
}

void Admin::menu_Student()
{
    int k;//operation
    system("cls");
    cout<<"*******************************************************"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"**      Choose your operation:                       **"<<endl;
    cout<<"**          1. Display                               **"<<endl;
    cout<<"**          2. Search information by name            **"<<endl;
    cout<<"**          3. Add new student                       **"<<endl;
    cout<<"**          4. Delete                                **"<<endl;
    cout<<"**          5. Modify information                    **"<<endl;
    cout<<"**          0. Return to main menu                   **"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"             Please choose your operation: ";
    cin>>k;
    switch(k)
    {
        case 1:system("cls");DisplayStudent();_getch();break;
        case 2:system("cls");FindStudent();_getch();break;
        case 3:system("cls");AddStudent();_getch();break;
        case 4:system("cls");del_Student();_getch();break;
        case 5:system("cls");change_Student();_getch();break;
        case 0:return;
    }
}
void Admin::menu_Teacher()
{
    int k;//operation
    system("cls");
    cout<<"*******************************************************"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"**      Choose your operation:                       **"<<endl;
    cout<<"**          1. Display                               **"<<endl;
    cout<<"**          2. Search information by name            **"<<endl;
    cout<<"**          3. Add new teacher                       **"<<endl;
    cout<<"**          4. Delete                                **"<<endl;
    cout<<"**          5. Modify information                    **"<<endl;
    cout<<"**          0. Return to main menu                   **"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"             Please choose your operation: ";
    cin>>k;
    switch(k)
    {
        case 1:system("cls");DisplayTeacher();_getch();break;
        case 2:system("cls");FindTeacher();_getch();break;
        case 3:system("cls");AddTeacher();_getch();break;
        case 4:system("cls");del_Teacher();_getch();break;
        case 5:system("cls");change_Teacher();_getch();break;
        case 0:return;
    }
}

int main()
{
    Admin a;
    while(1)
    {
    int position;
    cout<<"*******************************************************"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"**                                                   **"<<endl;
    cout<<"**          Welcome to University system!!!          **"<<endl;
    cout<<"**             Choose your position:                 **"<<endl;
    cout<<"**                 1. Student                        **"<<endl;
    cout<<"**                 2. Teacher                        **"<<endl;
    cout<<"**                 0. Exit                           **"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"\n\t\tPlease choose ";cin>>position;
    switch(position)
    {
    case 1:
        a.menu_Student();
        _getch();
        system("cls");
        break;
    case 2:
        a.menu_Teacher();
        _getch();
        system("cls");
        break;
    case 0:
        return 0;
    }
    }

    return 0;
}
