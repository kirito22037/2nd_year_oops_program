#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class student
{
  int rollno;
  char name[20];
  float marks;

public:
  void getdata(int a,char b[],float c);
  void display(fstream &fx);

  //void addrec();
  void modify(int n);
};

void student::getdata(int a,char b[],float c)
{
  rollno=a;
  strcpy(name,b);
  marks=c;
}

void student::display(fstream &fx)
{
  fx>>rollno>>name>>marks;
  cout<<"rollno : "<<rollno<<endl;
  cout<<"name : "<<name<<endl;
  cout<<"marks : "<<marks<<endl;
  cout<<endl;
}

/*void student::addrec()
{

}*/

void student::modify(int n)
{
    student z;


    fstream fl;
    fstream flx;
    fl.open("file_hand_8.txt",ios::in);
    flx.open("temp.txt",ios::out);
    cout<<"\nenter the rollno whose data we want to modify : ";
    cin>>z.rollno;
    cout<<"enter the new name : ";
    cin>>z.name;
    cout<<"enter the new marks : ";
    cin>>z.marks;

    for(int i=0;i<n;i++)
    {
      fl>>rollno>>name>>marks;
      if(rollno!=z.rollno)
      {
        flx<<rollno<<" "<<name<<" "<<marks<<endl;
      }
      else
      {
        flx<<z.rollno<<" "<<z.name<<" "<<z.marks<<endl;
      }
    }
    fl.close();
    flx.close();

    flx.open("temp.txt",ios::in);
    fl.open("file_hand_8.txt",ios::out);

    for(int i=0;i<n;i++)
    {
      flx>>rollno>>name>>marks;
      fl<<rollno<<" "<<name<<" "<<marks<<endl;
    }

    flx.close();
    fl.close();
}

int main()
{
  int ch,n,pos,ch2;
  student st,stx;
  int rollx,rollxy;
  char namex[20],namexy[20];
  float marksx,marksxy;


  fstream fl;
  fstream flx;

  do{
        cout<<"1. to create a dataset\n";
        cout<<"2. to display\n";
        cout<<"3. to add a record\n";
        cout<<"4. to delete a record\n";
        cout<<"5. to modify a record\n";
        cout<<"6. to exit !!\n";
        cout<<"\nenter your choice : ";
        cin>>ch;

        switch(ch)
        {
          case 1:
          cout<<"\nenter the number of records u want to enter : ";
          cin>>n;
          fl.open("file_hand_8.txt",ios::out);
          for(int i=0;i<n;i++)
          {
            cout<<endl;
            cout<<"rollno : ";
            cin>>rollx;
            cout<<"name : ";
            cin>>namex;
            cout<<"marks : ";
            cin>>marksx;

            st.getdata(rollx,namex,marksx);
            fl<<rollx<<" "<<namex<<" "<<marksx<<endl;
            //fl.write((char*)&st,sizeof(st));
            cout<<endl;
          }
          fl.close();
          break;

          case 2:
          cout<<"\nTHE DATESET : \n\n";
          fl.open("file_hand_8.txt",ios::in);
          //for(int i=0;i<n;i++)
          while(!fl.eof())
          {
            //fl.read((char*)&st,sizeof(st));
            //fl>>rollx>>namex>>marks;
            st.display(fl);
          }
          fl.close();
          break;

          case 3:
          cout<<"1.to append data \n";
          cout<<"2.to add data at specific location\n\n";

          cout<<"enter your choice : ";
          cin>>ch2;

          n+=1;

          if(ch2==1)
          {
              fl.open("file_hand_8.txt",ios::app);
              cout<<"Enter the new data to append in the exisiting file : \n";
              cout<<endl;
              cout<<"rollno : ";
              cin>>rollx;
              cout<<"name : ";
              cin>>namex;
              cout<<"marks : ";
              cin>>marksx;

              st.getdata(rollx,namex,marksx);
              fl<<rollx<<" "<<namex<<" "<<marksx<<endl;
              //st.getdata();
              //fl.write((char*)&st,sizeof(st));
              fl.close();
          }
          else
          {

              flx.open("temp.txt",ios::out);
              fl.open("file_hand_8.txt",ios::in);
              do {
                cout<<"\n\nEnter the position you want to enter : ";
                cin>>pos;
              } while(pos>n+1);// not complete


              cout<<"Enter the new data to append in the exisiting file : \n";
              cout<<endl;
              cout<<"rollno : ";
              cin>>rollxy;
              cout<<"name : ";
              cin>>namexy;
              cout<<"marks : ";
              cin>>marksxy;

              //stx.getdata(rollx,namex,marksx);

              //cout<<"n = "<<n<<endl;

              for(int i=0;i<n;i++)
              {
                  if(i==pos-1)
                  {

                      flx<<rollxy<<" "<<" "<<namexy<<" "<<marksxy<<endl;
                      //flx.write((char*)&stx,sizeof(stx));
                  }
                  else
                  {
                      fl>>rollx>>namex>>marksx;
                      flx<<rollx<<" "<<namex<<" "<<marksx<<endl;
                      //fl.read((char*)&st,sizeof(st));
                      //flx.write((char*)&st,sizeof(st));
                  }
              }
              flx.close();
              fl.close();

              cout<<endl;
              //cout<<"-----------file after deletion---------------";

              flx.open("temp.txt",ios::in);
              fl.open("file_hand_8.txt",ios::out);

              for(int i=0;i<n;i++)
              {
                flx>>rollx>>namex>>marksx;
                fl<<rollx<<" "<<namex<<" "<<marksx<<endl;
              }

              flx.close();
              fl.close();
          }
          break;

          case 4:
          cout<<"\nEnter the student roll no to be delete : ";
          cin>>pos;

          flx.open("temp.txt",ios::out);
          fl.open("file_hand_8.txt",ios::in);

          for(int i=0;i<n;i++)
          {
            fl>>rollx>>namex>>marksx;

            if(rollx!=pos)
            flx<<rollx<<" "<<namex<<" "<<marksx<<endl;
          }

          flx.close();
          fl.close();

          n=n-1;
          //copying temp data to original file
          flx.open("temp.txt",ios::in);
          fl.open("file_hand_8.txt",ios::out);

          for(int i=0;i<n;i++)
          {
            flx>>rollx>>namex>>marksx;
            fl<<rollx<<" "<<namex<<" "<<marksx<<endl;
          }

          flx.close();
          fl.close();
          break;

          case 5:
          st.modify(n);
          break;

          case 6:
          exit(0);
        }
      }while(1);
  return 0;
}
