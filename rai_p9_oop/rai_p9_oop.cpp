#include<bits/stdc++.h>
using namespace std;
class personal
{
	 char  *name;
	 char *dob;
	int age;
	char g;
	public:
	personal( char *name1, char *dob1,int age1,char g1)
	{
		//cout<<"\n personal"<<endl;
		name=name1;
		dob=dob1;
		g=g1;
		age=age1;
	}
	personal()
	{
		//(name,"no-one");
		//strcpy(dob,"none");
		//g='-';
		//age=0;
	}
	void showper();
};

void personal::showper()
{
	cout<<"\nName -->   "<<name;
	cout<<"\nAge is-->   "<<age;
	cout<<"\nBate of birth is-->"<<dob;
	cout<<"\nGender--   "<<g;
}

class prof1
{
	 char *s1;
	 char *s2;
	 char *s3;
	public:
	prof1()
	{
		//(s1,"none");
		//strcpy(s2,"none");
		//strcpy(s3,"none");
	}
	prof1( char *p1, char *p2, char *p3)
	{
		//cout<<"\nprofesional"<<endl;
		s1=p1;
		s2=p2;
		s3=p3;

	}
	void showpro();
};

void prof1::showpro()
{
	cout<<"\nSkill 1--> "<<s1;
	cout<<"\nSkill 2--> "<<s2;
	cout<<"\nSkill 3--> "<<s3;

}

class acad:public personal,public prof1
{
	 char *sn;
	float sm;
	 char *cn;
	float cm;
	public:
	acad( char *name1, char *dob1,int age1,char g1, char *p1, char *p2, char *p3, char *sn1,float sm1, char *cn1,float cm1):
	personal(name1,dob1,age1,g1),prof1(p1,p2,p3)
	{
		//cout<<"\nacad"<<endl;
		sn=sn1;
		cn=cn1;
		sm=sm1;
		cm=cm1;
	}
	acad()
	{
		//none
	}
	void showacad();

};

void acad::showacad()
{
	cout<<"\n School name is-->"<<sn;
	cout<<"\nSchool marks are -->"<<sm;
	cout<<"\n College name is-->"<<cn;
	cout<<"\nCollege sgpa is -->"<<cm;
}

int main()
{
	char name[20],dob[20],s1[30],s2[30],s3[30],sn[30],cn[30],g;
	int age;
	float sm,cm;
	acad *a;
	cout<<"\nenter name-";
	cin>>name;
	cout<<"\n enter date of birth-";
	cin>>dob;
	cout<<"\n enter age-";
	cin>>age;
	cout<<"\n enter gender-";
	cin>>g;
	cout<<"\n enter skill 1-";
	cin>>s1;
	cout<<"\n enter skill 2-";
	cin>>s2;
	cout<<"\n enter skill 3-";
	cin>>s3;
	cout<<"\n enter school name-";
	cin>>sn;
	cout<<"\n enter school marks-";
	cin>>sm;
	cout<<"\n enter college name-";
	cin>>cn;
	cout<<"\n enter college marks-";
	cin>>cm;

	a=new acad(name,dob,age,g,s1,s2,s3,sn,sm,sn,sm);
	cout<<"the personal details = "<<endl;
	a->showper();

	cout<<endl;
	cout<<"the professional detail = "<<endl;
	a->showpro();

	cout<<endl;
	cout<<"the academic detail ="<<endl;
	a->showacad();


	return 0;
}
