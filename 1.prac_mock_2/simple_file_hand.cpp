#include<bits/stdc++.h>
using namespace std;

int main()
{
  char c;
  fstream fl;
  fl.open("file1.txt",ios::out);
  cout<<"enter the statement here : ";
  do
  {
    cin.get(c);
    fl.put(c);
    if(c=='\n')
    break;
  }
  while(1);
  fl.close();

  //output
  fl.open("file1.txt",ios::in);
  cout<<"\nthe content of the file is : ";
  while(fl.eof())
  {
    fl.get(c);
    cout.put(c);
  }

}
