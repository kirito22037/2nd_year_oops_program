#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void divid(double x,double y)
{
    double z;
    try
    {
          if(y==0)
          {
                throw y;
          }
          else
          {
              z=x/y;
              cout<<"ans : "<<z<<endl;
          }
    }

    catch(double j)
    {
          cout<<"the dividend cant be 0 !!\n";
    }


}

int main()
{
    double x,y;

    cin>>x>>y;

    divid(x,y);
    //cout<<x/y;
    return 0;
}
