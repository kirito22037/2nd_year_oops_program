#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct node
{
    int prio;
    char name[30];
    struct node *next;
};
class que
{
    struct node *f,*r;
public:
    que(){
        f = NULL;
        r = NULL;
    }
    void insert_p(){
        int prio;
        cout<<"Enter The Priority Of the Patient >> ";
        cin>>prio;
        if(prio>3){
            cout<<"Patient Cannot be Added\n";
            return;
        }
        struct node *temp = new struct node;

        temp->prio = prio;

        cout<<"\nEnter The name of the Patient >> ";
        cin>>temp->name;

        temp->next = NULL;
        if(f == NULL && r == NULL){
            f = r = temp;
        }
        else{
            struct node *ptr = f;
            struct node *ptr1= f;
            int flag = 0;
            while(ptr != NULL && ptr->prio <= temp->prio){
                ptr1 = ptr;
                ptr = ptr->next;
                flag = 1;
            }
            if(flag == 0){
                temp->next = f;
                f = temp;
            }
            else if(ptr1 == r){
                r->next = temp;
                r = r->next;
            }
            else{
                ptr1->next = temp;
                temp->next = ptr;
            }
        }
    }
    void show()
    {
        if(f == NULL){
            cout<<"\n---------No Patient in the Queue----------\n";
            return;
        }
        struct node *ptr = f;
        cout<<"Priority\tName\n";
        while(ptr != NULL){
            cout<<ptr->prio<<"\t"<<ptr->name<<"\n";
            ptr = ptr->next;
        }
    }
    void del()
    {
        if(f == NULL){
            cout<<"\n---------No Patient in the Queue----------\n";
            return;
        }
        struct node *ptr = f;
        cout<<"\nAttending ::\t"<<f->name<<"\n";
        if(f == r)
        {
            f = r = NULL;
        }
        else{
            f = f->next;
        }
        delete ptr;
    }
    void display(){
        if(f == NULL){
            cout<<"\n---------No Patient in the Queue----------\n";
            return;
        }
        int x;
        cout<<"Enter the Priority to Display \n";
        cin>>x;
        if(x>3){
            cout<<"Invalid Priority\n";
            return;
        }
        else{
            struct node *ptr = f;
            while(ptr != NULL && ptr->prio != x)
                ptr = ptr->next;

            if(ptr == NULL)
            {
                cout<<"Queue Empty\n";
                return;
            }
            else{
                cout<<x<<"\tName\n";
                while(ptr != NULL && ptr->prio == x){
                    cout<<ptr->prio<<"\t"<<ptr->name<<"\n";
                    ptr = ptr->next;
                }
            }
        }
    }
};
int main()
{
    int ch,c;
    que q;
    do
    {
        cout<<"\n1.Add Patients\n2.Show the patients in queue\n3.Attend a Patient\n4.Display Specific\n5.Exit\n >> ";
        cin>>ch;

        switch(ch)
        {
            case 1 :do
                    {
                        q.insert_p();
                        cout<<"\nEnter -1 to stop \t else 0 to continue >> ";
                        cin>>c;
                    }while(c!=-1);
                    break;
            case 2 :q.show();
                    break;
            case 3 :q.del();
                    break;
            case 4 :q.display();
                    break;
        }
    }while(ch!=5);
}
