#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class stud
{
      int roll;
      char name[20];
      float marks;

    public:

        void getdata()
        {
              cout<<"roll:";
              cin>>roll;

              cout<<"name:";
              cin>>name;

              cout<<"marks:";
              cin>>marks;

              cout<<endl;


        }

        void display()
        {
          cout<<"roll : "<<roll<<endl;
          cout<<"name : "<<name<<endl;
          cout<<"marks : "<<marks<<endl;
          cout<<endl;
        }
};

int main()
{
      stud rai;

      fstream fl;

      fl.open("file_cpp.dat",ios::out);

      for(int i=0;i<3;i++)
      {
            rai.getdata();
            fl.write((char*)&rai,sizeof(rai));
      }


      fl.close();

      cout<<"/n/nTHE OUTPUT IS :-\n\n";
      fl.open("file_cpp.dat",ios::in);

      for(int i=0;i<3;i++)
      {
        fl.read((char*)&rai,sizeof(rai));
        rai.display();
      }

      fl.close();

      return 0;
}
