#include<iostream>
#include<fstream>
using namespace std;
class student
{
    int roll;
    int marks;
    string name;
public:
    student(int roll,int marks,string name)
    {
        this->roll = roll;
        this->marks = marks;
        this->name = name;
    }
    int getid(int id)
    {
        if(this->roll == id)
            return 1;
        else
            return 0;
    }
};
int main()
{
    student *s[10];
    int ch,i=-1;
    int roll,marks,pos,j,id,flag=0;
    string name;
    ifstream fout;
    ofstream fin;
    do
    {
        cout<<"SELECT YOUR CHOICE!!\n";
        cout<<"\t1.Create\n\t2.Display\n\t3.Insert\n\t4.Delete\n\t5.Modify\n\t6.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1 :fin.open("Data.txt");
                    do
                    {
                        i++;
                        cout<<"\nEnter The\n\tROLL NUMBER\n\tMARKS\n\tNAME\n";
                        cin>>roll;
                        cin>>marks;
                        cin>>name;
                        s[i] = new student(roll,marks,name);
                        fin<<roll<<" "<<marks<<" "<<name;
                        fin<<endl;
                        cout<<"Enter -1 To stop or 0 to Continue! >> ";
                        cin>>ch;
                    }while(ch!=-1);
                    fin.close();
                    break;
            case 2 :fout.open("Data.txt");
                    cout<<"ROLL_NO\tMARKS\tNAME\n";
                    for(j=0;j<=i;j++)
                    {
                        fout>>roll>>marks>>name;
                        cout<<roll<<"\t"<<marks<<"\t"<<name<<endl;
                    }
                    fout.close();
                    break;
            case 3 :cout<<"Enter The Position you want to insert\n";
                    cin>>pos;
                    fout.open("Data.txt");
                    fin.open("Temp.txt");
                    for(j=0;j<pos-1 && j<=i;j++)
                    {
                      fout>>roll>>marks>>name;
                      fin<<roll<<" "<<marks<<" "<<name<<endl;
                    }
                    for(int k=i;k>j;k--)
                        s[k+1] = s[k];
                    cout<<"\nEnter The\n\tROLL NUMBER\n\tMARKS\n\tNAME\n";
                    cin>>roll;
                    cin>>marks;
                    cin>>name;
                    s[j] = new student(roll,marks,name);
                    fin<<roll<<" "<<marks<<" "<<name<<endl;
                    for( ;j<=i;j++)
                    {
                      fout>>roll>>marks>>name;
                      fin<<roll<<" "<<marks<<" "<<name<<endl;
                    }
                    i++;
                    fin.close();
                    fout.close();
                    fout.open("Temp.txt");
                    fin.open("Data.txt",ios::trunc);
                    for(j=0;j<=i;j++)
                    {
                        fout>>roll>>marks>>name;
                        fin<<roll<<" "<<marks<<" "<<name<<endl;
                    }
                    fin.close();
                    fout.close();
                    break;
            case 4 :cout<<"Enter The Roll Number Of the >> ";
                    cin>>id;
                    for(j=0;j<=i;j++)
                    {
                        flag = s[j]->getid(id);
                        if(flag==1)
                            break;
                    }
                    if(flag==1)
                    {
                        fout.open("Data.txt");
                        fin.open("Temp.txt");
                        /*for(int k=j;k<=i-1;k++)
                            s[k] = s[k+1];

                        delete s[i];*/

                        for(int k=0;k<=i;k++)
                        {
                            fout>>roll>>marks>>name;
                            if(k!=j)
                                fin<<roll<<" "<<marks<<" "<<name<<endl;
                        }
                        i--;
                        fin.close();
                        fout.close();
                        fout.open("Temp.txt");
                        fin.open("Data.txt",ios::trunc);
                        for(j=0;j<=i;j++)
                        {
                            fout>>roll>>marks>>name;
                            fin<<roll<<" "<<marks<<" "<<name<<endl;
                        }
                        fin.close();
                        fout.close();
                    }
                    else
                        cout<<"The Entered Id is Not Present!\n\n";

                    break;
        }
    }while(ch!=6);
}
