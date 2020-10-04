#include<bits/stdc++.h>
using namespace std;
struct n
{
	string name;
	struct n *next;
};
typedef struct n node;
struct l
{
	string name;
	int day,mon,year;
	int comments;
	node *head;
};
typedef struct l lst;
class graph
{
	int v,e;
	lst *arr;
	map<string,node*> m;
	public:
	graph(int v)
	{	
		//cout<<"Running\n";
		this->v = v;
		arr = new lst[v];
		for(int i=0;i<v;i++)
			arr[i].head = NULL;
	}
	void create_graph()
	{
		string name;
		cout<<"Enter The Details Of each Friend\n";
		for(int i=0;i<v;i++)
		{
			cout<<"\tEnter The Name\n";
			cin>>name;
			arr[i].name = name;
			cout<<"\tFor Date of Birth\n";
			cout<<"\tEnter the Date\n";
			cin>>arr[i].day;
			cout<<"\tEnter the Month\n";
			cin>>arr[i].mon;
			cout<<"\tEnter the Year\n";
			cin>>arr[i].year;
			cout<<"\tEnter The Number Of Commets\n";
			cin>>arr[i].comments;
			
			m[name] = arr[i].head;
		}
		cout<<"\n--------------------------\n";
		int c = 1;
		while(c)
		{
			cout<<"\nEnter The name of Friend\n";
			cin>>name;
			
			node *temp1 = new node;
			node *temp2 = new node;
			temp2->name = name;temp2->next = NULL;
			
			cout<<"Enter For The Friend of "<<name<<" \n";
			cout<<"Enter The Name\n";
			cin>>temp1->name;
			temp1->next = NULL;
			
			temp1->next = m[name];
			m[name] = temp1;
			
			temp2->next = m[temp1->name];
			m[temp1->name] = temp2;
			
			cout<<"Do You Have More Connection \t(1,0) \n";			
			cin>>c;
		}
	}
	void display_graph()
	{
		map<string,node*>::iterator it = m.begin();
		node *ptr;
		for(;it!=m.end();it++)
		{
			cout<<"\nFriends Of "<<it->first<<" ,are \n";
			ptr = it->second;
			while(ptr!=NULL)
			{
				cout<<"\t"<<ptr->name<<"\n";
				ptr = ptr->next;
			}
		}
	}
	void max_comments()
	{
		int max = 0;
		int col = 0;
		for(int i=0;i<v;i++)
		{
			if(arr[i].comments > max )
			{
				max = arr[i].comments;
				col = i;
			}
		}
		cout<<"The Maximun Number Of Comments Are by "<<arr[col].name<<" :: "<<max;
	}
	void Birthday()
	{
		vector<string>v;
		int n,cnt=0;
		cout<<"Enter The Month Number\n";
		cin>>n;
		if(n>12 || n<1)
			return;
		for(int i=0;i<n;i++)
		{
			if(arr[i].mon == n){
				v.push_back(arr[i].name);
				cnt++;
			}
		}
		cout<<"There Are Exactly "<<cnt<<" Friend those have Birthday on "<<n<<"th month\n";
		for(int i=0;i<v.size();i++)
			cout<<"\t"<<v[i]<<endl; 
	}
};
int main()
{
	int v;
	cout<<"How Many Friends are there in Connection\n";
	cin>>v;
	graph g(v);
	g.create_graph();
	cout<<"\n";
	g.display_graph();
	cout<<"\n";
	g.max_comments();
	cout<<"\n";
	g.Birthday();
}
