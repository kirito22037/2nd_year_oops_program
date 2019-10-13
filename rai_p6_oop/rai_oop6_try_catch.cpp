#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class television
{
    int modelno;
    int screen;
    int price;

    public:
      void input(int k)
      {
          try{
                if(k==1)
                {
                      cout<<"enter the 4 digit model no :";
                      cin>>modelno;

                      if(modelno<1000||modelno>9999)
                          throw 1;

                }
                else if(k==2)
                {
                    cout<<"enter the screen size :";
                    cin>>screen;

                    if(screen<12 || screen>17)
                      throw 2;


                }

                else if(k==3)
                {
                    cout<<"enter the price :";
                    cin>>price;

                    if(price<0||price>5000)
                      throw 3;
                }
          }

          catch(int v)
          {
                if(v==1)
                {
                    cout<<"\nthe model no is not valid !! re-enter\n";
                    input(1);

                }

                else if(v==2)
                {
                    cout<<"\nthe screen size is not of valid range !! re-enter\n";
                    input(2);

                }

                else if(v==3)
                {
                    cout<<"\nthe price is not in the valid range !! re-enter\n";
                    input(3);

                }
          }


      }

    friend istream &operator>>(istream &,television &);

    void display()
      {

          cout<<"\nTHE OUTPUT IS : -\n";
          cout<<"\nmodeln0 :"<<modelno<<endl;
          cout<<"\nscreen size:"<<screen<<endl;
          cout<<"\nprice :"<<price<<endl;
      }


};

istream &operator>>(istream &inp,television &tx)
{

      tx.input(1);
      tx.input(2);
      tx.input(3);

      return inp;
}

int main()
{
    television t;
    cin>>t;

    t.display();

    return 0;
}
