#include<bits/stdc++.h>
using namespace std;

//senergic class
template <class T>
class matrix
{
  T **m;// matrix dynamically
  int c,r;

public:
  void input();
  void output();
};

//template for function
template <class T>
void matrix<T>::input()
{
  cout<<"enter the number of rows n column : ";
  cin>>r>>c;

  //dynamic memory allocating
  m=new T*[r]; // the rows carry elemts that are of pointer type for T datatype elements
  for(int i=0;i<r;i++)
  {
    m[i]=new T[c]; // for each row we make c number of columns which store datatype of T
  }

  cout<<"enter the elements of the matrix : ";
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      cin>>m[i][j];
    }
  }
}

template <class T>
void matrix<T>::output()
{
    cout<<"\nTHE matrix is :\n\n";
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        cout<<m[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
}

int main()
{
  matrix <int> m1,m2;
  m1.input();
  m2.input();
  m1.output();
  m2.output();

}
