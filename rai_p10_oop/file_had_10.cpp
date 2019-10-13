#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char c,s;

    ofstream fl;

    fl.open("roshanoop10.txt",ios::out);

    cout<<"enter the statement here : ";

    do
    {
        cin.get(c);
        //cin>>c;
        if(c=='\n')
        {
            break;
        }
        fl.put(c);
    }while(1);

    fl.close();


    cout<<"\n\nThe file output is :\n";

    ifstream flx;

    char ch[30];
    int i=0;
    flx.open("roshanoop10.txt",ios::in);
    while(!flx.eof())
    {
        flx.get(s);
        ch[i]=s;

        i++;


    }
    ch[i-1]='\0';


    cout<<ch<<endl;

    flx.close();

    return 0;
}
