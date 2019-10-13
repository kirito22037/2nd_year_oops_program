#include<iostream>
using namespace std;
class wheather
{
   int ht,lt,ar,as;
   static int Aht,Alt,Aar,Aas;
   public:

   wheather()
   {
    ht=0;
    lt=0;
    ar=0;
    as=0;
   }
   void getdata();
   void displaydata(int dayno);
   void average(int );
};
int wheather::Aht;
int wheather::Alt;
int wheather::Aar;
int wheather::Aas;
void wheather::getdata()
{
  cout<<"Enter data for days:";
  cout<<"Hightemp   Lowtemp    Avgrain    Avgsnow:\n";
  cin>>ht>>lt>>ar>>as;
  Aht+=ht;
  Alt+=lt;
  Aar+=ar;
  Aas+=as;
}
void wheather::displaydata(int dayno)
{
  cout<<"\n"<<dayno<<"       "<<ht<<"          "<<lt<<"         "<<ar<<"      "<<as<<"\n";
}
void wheather::average(int n)
{
    cout<<"\n "<<"Avg     "<<wheather::Aht/n<<"          "<<wheather::Alt/n<<"         "<<wheather::Aar/n<<"      "<<wheather::Aas/n<<"\n";
}

int main()
{
  wheather w[31];
  int c,n,dayno,i;
  c=1;
  while(c!=5)
  {
    cout<<"::::MENU::::";
    cout<<"\nEnter your choice:";
    cout<<"\n1.Enter data\n2.display specific\n3.display all\n4.monthly report\n5.quit\n";
    cin>>c;
    switch(c)
    {
     case 1:cout<<"\nEnter number of days:";
            cin>>n;
            for(i=0;i<n;i++)
            {
              cout<<"\nEnter the day no:";
              cin>>dayno;
              w[dayno].getdata();
            }
            break;
     case 2:cout<<"\nEnter the dayno:";
            cin>>dayno;
            cout<<"Dayno   Hightemp   Lowtemp   Rain   Snow   \n";
            w[dayno].displaydata(dayno);
            break;
     case 3:cout<<"\n::::::::::::::::::TABLE::::::::::::::::::::\n";
            cout<<"\nDayno   Hightemp   Lowtemp   Rain   Snow   ";
            for(i=1;i<31;i++)
            {
              w[i].displaydata(i);
            }cout<<"\n";
            break;
     case 4:cout<<"\nMonthly report:";
            cout<<"\nDayno   Hightemp   Lowtemp   Rain   Snow   ";
            for(i=1;i<31;i++)
            {
              w[i].displaydata(i);
            }
            w[0].average(n);
            break;
     case 5:cout<<"Thank for visit";
            break;
    }
  }
  return 0;
}
