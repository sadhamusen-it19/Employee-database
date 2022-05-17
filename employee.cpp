#include <cmath>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
static int i=0,Rat[10],sum=0,Medium,n,avg,temp;

class Employee{
    public:
    int ID,Age,Rating;
    string Name;
    public:
    Employee(){
    return ;
}



void read(){
    cout<<"Enter the Employee ID :";
    cin>>ID;
    cout<<"Enter Employee Name :";
    cin.ignore(1);
    getline(cin,Name);
    cout<<"Age :";
    cin>>Age;
    cout<<"Rating :";
    cin>>Rating;
    sum+=Rating;
    Rat[i]=Rating;
    i++;
}
void display(){
    cout<<"Employee ID:"<<ID<<endl;
    cout<<"Employee Name:"<<Name<<endl;
    cout<<"Age:"<<Age<<endl;
    cout<<"Rating:"<<Rating<<endl;
}
void displayA(int final){
    int Afinal=final;
    cout<<"Average rating:"<<Afinal<<endl;
}
void displayM(int final){
    int Mfinal=final;
    cout<<"Medium rating:"<<Mfinal<<endl;
}


void displayH(int final){
    int Hfinal=final;
    cout<<"Highest rating:"<<Hfinal<<endl;
}
void displayL(int final){
    int Lfinal=final;
    cout<<"Lowest rating:"<<Lfinal<<endl;
}
void Update_name(string n){
    Name=n;
}
void Update_rating(int r){
    Rating=r;
}
void Update_age(int a){
    Age=a;
}
int getID(){return ID;}
    int getA_rating(){
    avg =sum/i;
    return avg;
}
int getH_rating(){
    int max;
    for(int i=0;i<::i;i++){
    for(int j=i+1;j<::i;j++){
    if(Rat[i]>Rat[j]){
    temp=Rat[i];



    Rat[i]=Rat[j];
    Rat[j]=temp; }}}
    max=Rat[::i
    -1];
    return max;
}
int getM_rating(){
    float f=::i;
    int n=round(f/2);
    for(int i=0;i<::i;i++){
    for(int j=i+1;j<::i;j++){
    if(Rat[i]>Rat[j]){
    temp=Rat[i];
    Rat[i]=Rat[j];
    Rat[j]=temp; }}}
    for(int i=0;i<n;i++)
    {Medium=Rat[i];}
    return Medium;
}

int getL_rating(){
    int min;
    for(int i=0;i<::n;i++){
    for(int j=i+1;j<::n;j++){
    if(Rat[i]>Rat[j]){
    temp=Rat[i];
    Rat[i]=Rat[j];
    Rat[j]=temp; }}}
    min=Rat[0];

    return min;
}

};

fstream file;
void New_record(){
    Employee *emp;
    emp = new Employee;
    file.open("theemployee.txt",ios::app);
    emp->read();
    if(!file)
    cout<<"ERROR IN CREATING THE FILE";
    else{
    file.write((char*)&emp,sizeof(emp));
    file.close();
    cout<<"record add successfully.."<<endl;
}
}
void Update_record(){

    Employee *emp;
    int id,opt,isfound=0;
    string word;
    cout<<"Employee ID:";
    cin>>id;

    file.open("theemployee.txt",ios::out|ios::in|ios::app);
    if(!file){cout<<"ERROR IN OPENING THE FILE.. ";return;}

    while(file){
    if( file.read((char*)&emp ,sizeof(emp)) ){

    if(emp->getID()==id){
    cout<<"1.Name "<<endl<<"2.Rating"<<endl<<"3.Age"<<endl<<"Enter the option:";
    cin>>opt;
    isfound=1;
    switch(opt){
    case 1:{

    string tmp_name;
    cout<<"Enter the Name:";
    cin.ignore(1);
    getline(cin,tmp_name);
    emp->Update_name(tmp_name);
    int pos = -1*static_cast<int>(sizeof(emp));
    file.seekp(pos,ios::cur);
    file.write((char*)&emp,sizeof(emp));
    break;
    }
    case 2:{

    int tmp_rating;



    cout<<"Enter the Rating:";
    cin>>tmp_rating;
    emp->Update_rating(tmp_rating);
    int pos = -1*static_cast<int>(sizeof(emp));
    file.seekp(pos,ios::cur);
    file.write((char*)&emp,sizeof(emp));
    break;
    }
    case 3:{

    int tmp_age;
    cout<<"Enter the age:";
    cin>>tmp_age;
    emp->Update_age(tmp_age);
    int pos =-1*static_cast<int>(sizeof(emp));
    file.seekp(pos,ios::cur);
    file.write((char*)&emp,sizeof(emp));
    break;
    }
    default:cout<<"Invalid option..";
    break;
    }

    }
    }
    }

    if(isfound==0)
    {
    cout<<"record not found";
    }

    file.close();
    cout<<"record Updated successfull..";
}
void view_specific_record()
{
    Employee *emp;

    int id,isfound=0;
    cout<<"Enter the ID:";
    cin>>id;
    file.open("theemployee.txt",ios::in|ios::out);
    if(!file){
    cout<<"ERROR IN OPENING THE FILE";return;}

    if(file.read((char*)&emp,sizeof(emp))){
    if(emp->getID()==id)
        {

            emp->display();
            isfound++;
            cout<<"record found"<<endl;

        }
}

if(isfound==0)
    {
        cout<<"record not found";
    }
file.close();
}
void view_all_records(){
    Employee *emp;

    int isfound=0;
    file.open("theemployee.txt",ios::in|ios::out);
    if(!file){
    cout<<"ERROR IN OPENING THE FILE";return;}
    while(file){
    if(file.read((char*)&emp,sizeof(emp))){
    if(emp->getID()){
    cout<<"record found"<<endl;
    emp->display();
    isfound=1;}
    }

    if(isfound==0){
    cout<<"record not found";
    }
    file.close();
    }
}

void Average_rating(){
    int final,isfound=0;
    Employee *emp;

    final=emp

    ->getA_rating();

    emp
    ->displayA(final);
}
void Medium_rating(){
    int final,isfound=0;
    Employee *emp;
    emp=new Employee;

    final=emp

    ->getM_rating();

    emp
    ->displayM(final);
}
void Highest_rating(){
    int final,isfound=0;
    Employee *emp;

    final=emp

    ->getH_rating();

    emp

    ->displayH(final);

}



void Lowest_rating(){
    int final;
    Employee *emp;

    final=emp->getL_rating();

    emp->displayL(final);

}
void deleteExistingFile()
{
    remove("theemployee.txt");
}
int main(){

    int ch,n;

    deleteExistingFile();

    while(true){
    cout<<"\n1. Add a new employee record"<<endl;
    cout<<"2. Update an employee record using Employee ID"<<endl;
    cout<<"3. View a specific record based on Employee ID"<<endl;
    cout<<"4. View all employee record"<<endl;
    cout<<"5. Average rating of employees"<<endl;
    cout<<"6. Medium rating of employees"<<endl;
    cout<<"7. Highest rating employee details"<<endl;
    cout<<"8. Lowest rating employee details"<<endl;
    cout<<"9. Exit"<<endl<<endl;
    cout<<"Enter your option (1..9):";
    cin>>ch;



    switch(ch){
        case 1:New_record();
        break;
        case 2:Update_record();
        break;
        case 3: view_specific_record();
        break;
        case 4:view_all_records();
        break;
        case 5:Average_rating();
        break;
        case 6:Medium_rating();
        break;
        case 7:Highest_rating();
        break;
        case 8:Lowest_rating();
        break;
        case 9:{cout<<"Exit";
                return 0;
            }
        break;
        default:
        cout<<"Invalid option";
        break;
        }
    }
return 0;
}

