#include<bits/stdc++.h>

using namespace std;

class error
{
  int len,price;
public:
  void input(int);
  void output();
};

void error::input(int i)
{
    try
    {
      if(i==1)
      {
        cout<<"\nenter the length : ";
        cin>>len;
        if(len<10||len>99)//len should be from 10 to 99
        {
          throw 1;
        }
      }
      if(i==2)
      {
        cout<<"\nenter the price : ";
        cin>>price;
        if(price<10||price>99)
        {
          throw 2;
        }
      }
    }
    catch(int x)
    {
      if(x==1)
      {
        cout<<"\nthe length entered is invalid !! plz re-enter";
        input(1);
      }
      else if(x==2)
      {
        cout<<"\nthe price entered is invalid !! plz re-enter";
        input(2);
      }
    }
}

int main()
{
  error e;
  e.input(1);
  e.input(2);

  return 0;
}
