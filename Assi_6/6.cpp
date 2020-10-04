#include<bits/stdc++.h>
using namespace std;

struct stack_node
{
    struct head *point;
    struct stack_node *next;
};

struct head
{
    int val;
    char nm[30];
    int noc;
    int date;
    int mon;
    int year;
    struct node *point_next;
    struct head *next;
};
struct node
{
    int val;
    struct node *next;
};

class Stack
{
    struct stack_node *top;

    public:Stack()
           {
                top=NULL;
           }
           void push(struct head *ptr)
           {
                struct stack_node *p=new stack_node;
                p->point=ptr;
                p->next=NULL;

                if(top==NULL)
                    top=p;
                else
                {
                    p->next=top;
                    top=p;
                }
           }
           void pop()
           {
                struct stack_node *p;
                p=top;
                top=top->next;
                delete(p);
           }
           struct head* ret()
           {
                if(top==NULL)
                    return NULL;
                return top->point;
           }

};

class Graph
{
    struct head *head_main ;
    int len;

    public: Graph()
            {
                head_main=NULL;
            }

            void create()
            {
                struct head *p;
                int fri;
                int i;

                cout<<"\nEnter number of users in Facebook:";
                cin>>len;

                for(i=0;i<len;i++)
                {
                    struct head *ptr=new struct head;
                    ptr->next=NULL;
                    ptr->point_next=NULL;
                    ptr->val=i+1;
                    cout<<"\nEnter name of user "<<i+1<<":";
                    cin>>ptr->nm;
                    cout<<"\nEnter number of comments by "<<ptr->nm<<":";
                    cin>>ptr->noc;
                    cout<<"\nEnter Date of Birth of user "<<ptr->nm<<":";
                    cout<<"\nEnter Date:";
                    cin>>ptr->date;
                    cout<<"\nEnter month:";
                    cin>>ptr->mon;
                    cout<<"\nEnter year:";
                    cin>>ptr->year;

                    if(head_main==NULL)
                       head_main=ptr;
                    else
                    {
                        p->next=ptr;
                    }
                    p=ptr;
                }
                struct head *x=head_main;
                struct node *y;

                while(x!=NULL)
                {
                    cout<<"Enter the friends of "<<x->nm<<" (Enter user number and enter -1 to stop):";


                    while(1)
                    {
                        cin>>fri;

                        if(fri==-1)
                            break;

                        if(fri==x->val)
                        {
                            cout<<"\nCant be friend of self!!";
                            continue;
                        }
                        struct node *ptr=new struct node;
                        ptr->val=fri;
                        ptr->next=NULL;

                        if(x->point_next==NULL)
                            x->point_next=ptr;
                        else
                        {
                            y->next=ptr;
                        }
                        y=ptr;
                    }
                    x=x->next;
                }
            }

           void display_friend()
           {
                struct head *ptr=head_main;
                struct node *p;

                while(ptr!=NULL)
                {
                    cout<<"\nFriends of "<<ptr->nm<<":";
                    p=ptr->point_next;

                    while(p!=NULL)
                    {
                        cout<<p->val;
                        p=p->next;
                        cout<<",";
                    }
                    ptr=ptr->next;
                }
                cout<<"\n";
           }

           void max_friend()
           {
                struct head *ptr=head_main;
                struct head *pos;
                struct node *p;
                int cnt;
                int maxa=0;

                while(ptr!=NULL)
                {
                    cnt=0;
                    p=ptr->point_next;
                    while(p!=NULL)
                    {
                        cnt++;
                        p=p->next;
                    }
                    if(maxa==0)
                    {
                        maxa=cnt;
                        pos=ptr;
                    }
                    else if(cnt>maxa)
                    {
                        maxa=cnt;
                        pos=ptr;
                    }
                    ptr=ptr->next;
                }
                cout<<"\n"<<pos->nm<<" has MAXIMUM NUMBER OF FRIENDS="<<maxa<<"\n";
           }
           void max_min_com_DFS_NR()
           {
                int i,visited[len];
                int mina=0,maxa=0;
                struct head *min_pos,*max_pos;
                struct head *ptr,*xy;
                struct node *p;
                Stack S;

                for(i=0;i<len;i++)
                    visited[i]=0;

                S.push(head_main);

                while(S.ret()!=NULL)
                {

                    ptr=S.ret();
                    S.pop();

                    if(visited[ptr->val-1]==0)
                    {
                        visited[ptr->val-1]=1;

                        if(mina==0 && maxa==0)
                        {
                            mina=ptr->noc;
                            maxa=ptr->noc;
                            min_pos=ptr;
                            max_pos=ptr;
                        }
                        else if(ptr->noc<mina)
                        {
                            mina=ptr->noc;
                            min_pos=ptr;
                        }
                        else if(ptr->noc>maxa)
                        {
                            maxa=ptr->noc;
                            max_pos=ptr;
                        }
                    }
                    p=ptr->point_next;

                    while(p!=NULL)
                    {
                        if(visited[p->val-1]==0)
                        {
                            xy=head_main;

                            for(int i=0;i<(p->val)-1;i++)
                                xy=xy->next;

                            S.push(xy);
                            break;
                        }
                        else
                            p=p->next;
                    }
                }
                cout<<"\n";
                cout<<"\nMinimum number of comments:"<<mina;
                cout<<"\nUser with minimum number of comments:"<<min_pos->nm;
                cout<<"\nMaximum number of comments:"<<maxa;
                cout<<"\nUser with maximum number of comments:"<<max_pos->nm;
                }

                void month_BFS_Rec()
                {
                    int month;
                    cout<<"\n\nEnter the month number ";
                    cin>>month;
                    cout<<"\n\nUsers whose birthday lies in this month are:\n";
                    queue<struct head*> Q;
                    int visited[len];

                    for(int i=0;i<len;i++)
                        visited[i]=0;

                    struct head *ptr;
                    struct head *xy;
                    struct node *p;

                    Q.push(head_main);


                    while(!Q.empty())
                    {
                        ptr=Q.front();
                        Q.pop();
                        visited[ptr->val-1]=1;

                        if(month==ptr->mon)
                        {
                            cout<<"\nName:"<<ptr->nm;
                            cout<<"\nDOB:"<<ptr->date<<":"<<ptr->mon<<":"<<ptr->year;
                        }
                        p=ptr->point_next;
                        while(p!=NULL)
                        {
                            if(visited[p->val-1]==0)
                            {
                                visited[p->val-1]=1;
                                xy=head_main;

                                for(int i=0;i<(p->val)-1;i++)
                                    xy=xy->next;
                                Q.push(xy);

                            }
                            p=p->next;
                        }
                    }
                }
};

int main()
{
    Graph G;
    cout<<"\n::::::FACEBOOK NETWORK:::::::::\n";

    G.create();
    G.display_friend();
    G.max_friend();
    G.max_min_com_DFS_NR();
    G.month_BFS_Rec();
    return 0;
}
