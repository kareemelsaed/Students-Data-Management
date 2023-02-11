// hint: the program read data from text file "date.txt"
//hint : the max number of students in this program is 100 if you want change it just change in the variable n in the ninth line
#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;
#define max_letter 40
#define max_sub 10
#define n 100
int num_sub,num_students,final_score,open=1;
int *p_num_students=&num_students;
class student
{
    public:
        int num;
        char name[max_letter],department[max_letter];
        float marks[max_sub];
        struct address {
            char city[max_letter],residential_area[max_letter];
            long zip;
         };
        void edit();
        address ad;
};
student group[n];
// functions to sort the class Ascending order by numbers
void swap(int first, int second)
{
     student temp;
  temp = group[first];
group[first] = group[second];
group[second] = temp;
}
int partition (int first, int last)
{  int pivot;
    int index, smallIndex;
    pivot = group[first].num;
    smallIndex = first;
      for (index = first + 1; index <= last; index++)
     if (group[index].num <= pivot)
           {  smallIndex++; swap(smallIndex, index);  }
   swap(first, smallIndex);

return smallIndex; }
void QuickSort(int first, int last)
	{
	    int pivotLocation;
 	  if (first >= last) return;
  	 pivotLocation = partition(first, last);
  	 QuickSort( first, pivotLocation- 1);
  	 QuickSort( pivotLocation+ 1, last);
  	 cout<<"the class now is sorted in Ascending order"<<endl;
  	  }
// function to read the students information from file
void read()
{
// the function of insert student
    cout<<"please put the information in the file as shown:\n roll no \n name \n department \n address(city, residential area, zip code) \n marks in all subjects \n";
    cout<<"please enter the number of subjects of each one of student\n";
    cin>>num_sub;
    cout<<"please enter the number of students you want to read\n";
    cin>>num_students;
    cout<<"please enter the total final score of all students\n";
    cin>>final_score;
    ifstream date_file;
    date_file.open("date.txt");
    if (date_file.fail())
    {
        cerr<<"error in opening the file"<<endl;
        open=0;
    }
    else{
            for (int i=0;i<num_students;i++)
    {
    date_file>>group[i].num;
    date_file.ignore();
    date_file.getline(group[i].name,max_letter);
    date_file.getline(group[i].department,max_letter);
    date_file.getline(group[i].ad.city,max_letter);
    date_file.getline(group[i].ad.residential_area,max_letter);
    date_file>>group[i].ad.zip;
    for(int j=0;j<num_sub;j++)
    date_file>>group[i].marks[j];
    }
    cout<<"reading from file completed"<<endl;
    date_file.close();
    }
}
void insert_student ()
{ *p_num_students+=1;
    cout<<"please enter the roll no of the student"<<endl;
    cin>>group[num_students-1].num;
    cout<<"please enter the name of the student"<<endl;
    cin.ignore();
    cin.getline(group[num_students-1].name,max_letter);
    cout<<"please enter the department of the student"<<endl;
    cin.getline(group[num_students-1].department,max_letter);
    cout<<"please enter the address of the student"<<endl;
    cin.getline(group[num_students-1].ad.city,max_letter);
    cin.getline(group[num_students-1].ad.residential_area,max_letter);
    cout<<"please enter the zip code of the student\n";
    cin>>group[num_students-1].ad.zip;
    cout<<"please enter the marks of the student in each subject"<<endl;
    for(int j=0;j<num_sub;j++)
    cin>>group[num_students-1].marks[j];
    cout<<"inserting a student completed"<<endl;

}
student search_num(int target)
{
student a;
a.num=-1;
int first = 0;
int last =num_students - 1;
int mid;
while (first <= last )
{ mid = (first + last) / 2;
if (group[mid].num == target) return group[mid];
else if (group[mid].num > target)
last = mid - 1;
else   first = mid + 1; }
   return a;

}
student search_name(char target[max_letter])
{
     student b;
     b.num=-1;
     int compare;
for (int i=0;i<num_students;i++)
{
   compare=strcmp(group[i].name,target);
   if (!compare)
    return group[i];
}
return b;
}
void disply(student result)
{
    cout<<"the student information you searched for:"<<endl;
    cout<<"name: "<<result.name<<endl<<"roll no: "<<result.num<<endl<<"department: "<<result.department<<endl<<"address: "<<result.ad.city<<"\t"<<result.ad.residential_area<<endl<<"zip code: "<<result.ad.zip<<endl;
     cout<<"marks: ";
     for(int j=0;j<num_sub;j++)
     cout<<result.marks[j]<<"\t";
     cout<<endl;
}
void student :: edit()
{
    int num_option,num_option2;
    a2:cout<<"please choose the number of the information you wanna to edit it"<<endl;
    cout<<"1. student roll no \n 2. student name \n 3. student department \n 4. student address \n 5. student marks \n";
    cin>>num_option;
    switch (num_option)
    {
        case 1:
    cout<<"please enter the new roll no of the student"<<endl;
    cin>>num;
    QuickSort(0,num_students-1);
    break;
        case 2:
    cout<<"please enter the new name of the student"<<endl;
    cin.ignore();
    cin.getline(name,max_letter);
    break;
        case 3:
    cout<<"please enter the new department of the student"<<endl;
    cin.ignore();
    cin.getline(department,max_letter);
    break;
        case 4:
    cout<<"please enter the new address of the student"<<endl;
    cin.getline(ad.city,max_letter);
    cin.getline(ad.residential_area,max_letter);
    cout<<"please enter the new zip code of the student"<<endl;
    cin>>ad.zip;
    break;
        case 5:
    cout<<"please enter the new marks of the student in each subject"<<endl;
    for(int j=0;j<num_sub;j++)
    cin>>marks[j];
    }
    cout<<"your edit is recorded successfully"<<endl;
    cout<<"1. wanna edit any information else \n 2. No other edits \n";
    cin>>num_option2;
    switch (num_option2)
    {
        case 1: goto a2;
        break;
    }

}
float sum(student calculate)
{ float sum1=0;
    for(int i=0;i<num_sub;i++)
       sum1+=calculate.marks[i];
       return sum1;
}
float percentag(float sum1)
{
    float percentage=0;
    percentage=(sum1/final_score)*100;
    return percentage;
}
int main()
{
read();
if(!open)
    goto e;
QuickSort(0,num_students-1);

 int num_start,num_end;
 a1:cout<<"please enter the number of the option you want to do"<<endl;
cout<<"1. insert a student into the system \n 2. search for a student and print student information\n 3. edit student details again finding student must be done via their id number \n 4. calculate the total score and get grade of the student\n";
cin>>num_start;
 while (num_start>6)
    {
    cout<<"invalid number \n please enter number from 1 to 6 "<<endl;
    cout<<"1. insert a student into the system \n 2. search for a student via their id number or via their name and print his/her information \n 3. edit student details again \n 4. calculate the total score and get grade of the student\n";
cin>>num_start;
 }
switch (num_start)
    {
    case 1 :
        insert_student();
        QuickSort(0,num_students-1);
        break;
    case 2 :
        int option_of_search;
        cout<<"1.search by student roll no \n 2.search by student name "<<endl;
        cin>>option_of_search;
        switch (option_of_search)
        {
            case 1 : int num_target;
            student result1;
                cout<<"please enter the roll number of the student you wanna search for"<<endl;
                cin>>num_target;
                result1=search_num(num_target);
                if (result1.num==-1)
                    cout<<"the number you entered not found"<<endl;
             else disply(result1);
             break;
            case 2: char name_target[max_letter];      student result2;
                cout<<"please enter the name of the student you wanna search for"<<endl;
                cin.ignore();
                cin.getline(name_target,max_letter);
                result2=search_name(name_target);
                if (result2.num ==-1)
                    cout<<"the name you entered not found"<<endl;
                else disply(result2);
                break;
                }
        break;
    case 3 : int edit_num;         student result;
    cout<<"please enter the roll no of the student who you wanna edit his/her information"<<endl;
    cin>>edit_num;
    result=search_num(edit_num);
    if (result.num==-1)
    cout<<"the number you entered not found"<<endl;
    else cout<<"the number you entered found successfully"<<endl;
    for (int j=0;j<num_students;j++)
    {
        if (group[j].num==result.num)
        {
        group[j].edit();
        break;
        }
    }
        break;
    case 4 : int calculate_num;        student result1;   float sum1,percentage,avg;
       cout<<"please enter the roll no of the student who you wanna calculate his/her score and grade"<<endl;
    cin>>calculate_num;
    result1=search_num(calculate_num);
    if (result.num==-1)
    cout<<"the number you entered not found"<<endl;
    else cout<<"the number you entered found successfully"<<endl;
    for (int j=0;j<num_students;j++)
    {
        if (group[j].num==result1.num)
        {
        sum1=sum(group[j]);
        cout<<"the total score of this student= "<<sum1<<endl;
        //cout<<"the average score of this student= "<<(sum1/num_sub)<<endl;
        percentage=percentag(sum1);
        cout<<"the percentage of this student= "<<percentage<<"%\n";
        cout<<"grade ";
        if (percentage<50)
        cout<<"F\n";
        else if(percentage>=50&&percentage<65)
        cout<<"D\n";
        else if(percentage>=65&&percentage<75)
        cout<<"C\n";
        else if(percentage>=75&&percentage<85)
        cout<<"B\n";
        else cout<<"A\n";
        break;
        }
    }
        break;
    }
    cout<<"please enter the number of the option you want to do"<<endl;
    cout<<" 1. do any option also \n 2. close the program"<<endl;
    cin>>num_end;
    while (num_end>2)
    {
    cout<<"invalid number \n please enter number from 1 to 2 "<<endl;
    cout<<" 1. do any option also \n 2. close the program"<<endl;
    }
    if (num_end==1)
    goto a1;
    e:return 0;
}
