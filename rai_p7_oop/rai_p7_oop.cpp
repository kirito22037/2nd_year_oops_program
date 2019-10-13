#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//template of class
template <class T>
class mat
{
      T **m,**ans;
      int r,c;

      public:

        void inputm();
        void outputm();
        void add(mat);
        void sub(mat);
        void multi(mat);
        void trans(mat);
};

template <class T>
void mat<T>::inputm()
{
    cout<<"enter the row and column : ";
    cin>>r>>c;

    //allocating rows
    m=new T*[r];
    //allocating columns to each row
    for(int i=0;i<r;i++)
    {
          m[i]=new T[c];
    }

    for(int i=0;i<r;i++)
    {
          for(int j=0;j<c;j++)
          {
                cin>>m[i][j];
          }
    }

}
template <class T>
void mat<T>::outputm()
{
  cout<<endl;
  cout<<"THE MATRIX IS : \n";

  for(int i=0;i<r;i++)
  {
        for(int j=0;j<c;j++)
        {
              cout<<m[i][j]<<" ";
        }

        cout<<endl;
  }
}

template <class T>
void mat<T>::add(mat x)
{


    if(r==x.r&&c==x.c)
    {
      // allocating memory
      ans=new T*[r];
      for(int i=0;i<r;i++)
      {
          ans[i]=new T[c];
      }

          for(int i=0;i<r;i++)
          {
            for(int j=0;j<c;j++)
            {
                  ans[i][j]=m[i][j]+x.m[i][j];
            }
          }

          cout<<"\nafter addition : \n";
          for(int i=0;i<r;i++)
          {
                for(int j=0;j<c;j++)
                {
                      cout<<ans[i][j]<<" ";
                }

                cout<<endl;
          }

    }

    else
    {
        cout<<"\n The operation cant be performed !!\n";
    }
}

template <class T>
void mat<T>::sub(mat x)
{
          if(r==x.r&&c==x.c)
          {
                for(int i=0;i<r;i++)
                {
                  for(int j=0;j<c;j++)
                  {
                        ans[i][j]=m[i][j]-x.m[i][j];
                  }
                }

                cout<<"\n\nafter subtraction : \n";
                for(int i=0;i<r;i++)
                {
                      for(int j=0;j<c;j++)
                      {
                            cout<<ans[i][j]<<" ";
                      }

                      cout<<endl;
                }

          }

          else
          {
              cout<<"\n The operation cant be performed !!\n";
          }
}

template <class T>
void mat<T>::multi(mat x)
{
          int i,j,k,sum=0;
          if(c == x.r)
          {
              //cout<<"\nMultiplied Matrix is\n";
          for(i=0;i<r;i++)
              {
                  for(j=0;j<x.c;j++)
                      {
                          for(k=0;k<c;k++)
                          {
                              sum = sum + m[i][k] * x.m[k][j];
                          }
                          //cout<<sum<<" ";
                          ans[i][j]=sum;
                          sum=0;
                      }
                      cout<<endl;
              }

              cout<<"\nNOW THE PRODUCT OF THE MATRIX IS :\n";
              for(int i=0;i<r;i++)
              {
                    for(int j=0;j<c;j++)
                    {
                          cout<<ans[i][j]<<" ";
                    }

                    cout<<endl;
              }

          }
          else
              cout<<"\nThe matrices cannot be multiplied\n";
}

template <class T>
void mat<T>::trans(mat x)
{
      cout<<"\nThe transpose of 1st matrix is :\n";
      for(int i=0;i<r;i++)
      {
          for(int j=0;j<c;j++)
          {
              cout<<m[j][i]<<" ";
          }
          cout<<endl;
      }

      cout<<"\nThe transpose of 2nd matrix is :\n";
      for(int i=0;i<x.r;i++)
      {
          for(int j=0;j<x.c;j++)
          {
              cout<<x.m[j][i]<<" ";
          }
          cout<<endl;
      }
}

int main()
{

  int ch;

  do{
          cout<<"\n\n1. for integer data type !! \n";
          cout<<"2. for float data type !! \n";
          cout<<"3. to exit !! \n\n";

           cout<<"enter your choice : ";
           cin>>ch;

           switch(ch)
           {
                case 1:
                //the datatype of the member variable of class is define 
                mat <int> m1,m2;
                cout<<"\nenter matrix 1 : \n";
                m1.inputm();
                cout<<"\nenter matrix 2 : \n";
                m2.inputm();

                m1.outputm();
                m2.outputm();

                //cout<<"\n the sum of the two int matrix is : \n";
                m1.add(m2);
                m1.sub(m2);
                m1.multi(m2);
                m1.trans(m2);
                break;

                case 2:
                mat <float> m3,m4;
                cout<<"\nenter matrix 1 : \n";
                m3.inputm();
                cout<<"\nenter matrix 2 : \n";
                m4.inputm();

                m3.outputm();
                m4.outputm();

                //cout<<"\nthe sum of the two float matrix is : \n";
                m3.add(m4);

                //cout<<"\nthe difference of two matrix is : \n";
                m3.sub(m4);
                m3.multi(m4);
                m3.trans(m4);
                break;

                case 3:
                exit(0);
           }

    }
    while(1);



  return 0;
}
