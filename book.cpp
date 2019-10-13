#include <bits/stdc++.h>
using namespace std;

class book
{
    char t[100],a[100],pu[100];
    int p,s;
    static int tra1,tra2;;
    public:
    void add();
    void update();
    int search(char []);
    int purchase(char [],int,int);
    void display(int,int );
    void trans();

};
int book::tra1;
int book::tra2;
void book::add()
{
    cout<<"\nenter title\n-->";
     cin>>t;;
    cout<<"\nenter author name\n-->";
    cin>>a;
    cout<<"\nenter publisher name\n-->";
    cin>>pu;
    cout<<"\nenter price\n-";
    cin>>p;
    cout<<"\nenter stock\n-";
    cin>>s;
}
void book::update()
{
    cout<<"\n enter new stock\n";
    cin>>s;
}
int book::search(char n1[])
{

    if(strcmp(n1,t)==0)
      return 1;

    return 0;
}
int book::purchase(char n1[],int n,int tr)
{

    if(strcmp(n1,t)==0)
    {
    if(n<=s)
    {
      book::tra2+=tr;
    	book::tra1+=1;
    	s=s-n;
    	cout<<"\nsuccess transacion\n new stock is--"<<s;
    }

    else
    {
      book::tra2+=tr;
    book::tra2+=1;
    cout<<"\n unsuccessful transaction\n";
    }
      return 1;
    }
    return 0;
}
void book::display(int n,int i)
{

  cout<<"\n";
  cout<<t<<"\t"<<a<<"\t"<<pu<<"\t\t"<<p<<"\t\t"<<s;
  if(i==n-1)
  {
    cout<<"\n successful transctions are \n"<<book::tra1;
    cout<<"\n unsuccessful transctions are \n"<<book::tra2;
  }

}



int main() {
    int c,n,i=0,u,c1,rn,f,nb,tr,total=0;
    char name[100];
    book b[100];
    do{
    cout<<"\t 1-add\n\t2-update\n\t3-search\n\t4-purchase\n\t5-display\n";
    cin>>c;
    switch(c)
    {
        case 1:cout<<"\nenter no of parameters of to add\n\t";
                cin>>n;
                total+=n;
                for(;i<total;i++)
                  b[i].add();
                  break;
        case 2:cout<<"\nenter no of records u want to update\n\t";
                cin>>u;
                for(i=0;i<u;i++)
                {
                    cout<<"\nenter the record no\t";
                    cin>>rn;
                    b[rn-1].update();
                }
                break;
        case 3:
                cout<<"\nenter the name of the book u want to search\n--";
                cin>>name;
                for(i=0;i<total;i++)
                  { f=b[i].search(name);
                  if(f==1)
                      {f=1;break;}
                  }
                  cout<<f<<" ";
                if(f==1)
                  cout<<"\n book is present\n ";
                else
                  cout<<"\nbook not present\n";
                break;
        case 4: tr=0;
                do{
                    cout<<"\nenter the name of the book u want to purchase\n";
                    cin>>name;
                    for(i=0;i<total;i++)
                      { f=b[i].search(name);
                      if(f==1)
                          break;
                      }
                    if(f==1)
                      cout<<"\n book is present\n ";
                    else
                      {cout<<"\nbook not present\n";tr++;};

                }while(f==0);
                cout<<"\nenter no of books u want to buy--";
                cin>>nb;

                for(i=0;i<total;i++)
                {f= b[i].purchase(name,nb,tr);
                  if(f==1)
                    break;
                  }
                break;
        case 5:cout<<"name\tauthor\tpublisher\tprice\tstock\n";
                for(i=0;i<total;i++)
                  b[i].display(total,i);





    }
    cout<<"\n\t do u want to continue -press--1\n";
    cin>>c1;

    }while(c1==1);
	return 0;
}
