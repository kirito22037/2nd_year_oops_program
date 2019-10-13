#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//base class
class shape
{
  float x;
  float y;

  public:

    float getdata()
    {
      float x1,y1;
      cout<<"\nenter the data : ";
      cout<<endl<<endl;
      cout<<"enter the value of x = ";
      cin>>x1;
      cout<<"enter the value of y = ";
      cin>>y1;

      x=x1;
      y=y1;

      return x*y;
    }

    // pure virtual function
    virtual void compute_area()=0;
   /*{
      cout<<"base class";
    }*/

};

//derived class1
class triangle:public shape
{
  float area1;

  public:

  void compute_area()
  {

    //cout<<"derived class triangle"<<endl;
    area1=getdata();
    cout<<"\nthe area of triangle is = ";
    cout<<area1/2<<endl;
  }
};

//derived class 2
class rectangle:public shape
{
  float area2;

  public:

    void compute_area()
    {
      //cout<<"\nderived class rectangle"<<endl;
      area2=getdata();
      cout<<"\nthe area of the rectangle is = ";
      cout<<area2<<endl;
    }
};


int main()
{
    int ch;
    //shape *s;

    do{
    cout<<"1. for triangle !"<<endl;
    cout<<"2. for rectangle !"<<endl;
    cout<<"3. to exit !"<<endl;
    cout<<endl;

    cout<<"enter your choice = ";
    cin>>ch;

     shape *s;
     //s=new shape;
     triangle t;
     rectangle r;

    switch(ch)
    {
         case 1:
            {
            s=&t;
            s->compute_area();
            break;
            }
           case 2:
            {
            s=&r;
            s->compute_area();
            break;
            }
            case 3:
            {
              exit(0);
            }
        default:
            cout<<"you entered wrong choice !!"<<endl;
            break;
    }
  }while(1);

    return 0;
}
