#include<bits/stdc++.h>
using namespace std;

class student
{
  int roll;
  char name[20];
  float marks;

public:
  void getdata(fstream &flx);
  void putdata(fstream &flx);
};

void student::getdata(fstream &flx)
{
  cout<<"roll : ";
  cin>>roll;
  cout<<"name : ";
  cin>>name;
  cout<<"marks : ";
  cin>>marks;

  flx<<roll<<" "<<name<<" "<<marks<<endl;
}

void student::putdata(fstream &flx)
{
    flx>>roll>>name>>marks;
    cout<<"roll : "<<roll<<endl;
    cout<<"name : "<<name<<endl;
    cout<<"marks : "<<marks<<endl;
    cout<<endl;
}

int main()
{
  student st;
  fstream fl;
  int n;

  cout<<"enter the number of entries : ";
  cin>>n;
  fl.open("roshan.txt",ios::out);
  for(int i=0;i<n;i++)
  {
    cout<<endl;
  st.getdata(fl);
  }
  fl.close();

  //now printing

  fl.open("roshan.txt",ios::in);

  while(!fl.eof())
  {
    //cout<<"in loop"<<endl;
    st.putdata(fl);
  }
  fl.close();

  return 0;
}
