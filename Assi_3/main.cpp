#include<bits/stdc++.h>
using namespace std;
struct n
{
    int data;
    struct n *lt;
    struct n *rt;
};
typedef struct n node;
struct stac
{
    node *add;
    struct stac *next;
};
typedef struct stac stk;
class tree
{
    stk *top;
public:
    tree(){
        top = NULL;
    }
    void push(node *ptr){
        stk *temp = new stk;
        temp->add = ptr;
        temp->next = NULL;
        if(top!= NULL)
            temp->next = top;
        top = temp;
    }
    void pop(){
        stk *ptr = top;
        top = top->next;
        delete ptr;
    }
    bool isempty(){
        if(top == NULL)
            return true;
        else
            return false;
    }
    node *create(node *ptr){
        int x;
        cout<<"\n1-> Enter Value\t2-> Enter -1 For Null >> ";
        cin>>x;
        if(x == -1)
            return NULL;

        ptr = new node;
        ptr->data = x;
        ptr->lt = ptr->rt = NULL;

        cout<<"\nFor Left Child of "<<x<<"\n";
        ptr->lt = create(ptr->lt);

        cout<<"\nFor right Child of "<<x<<"\n";
        ptr->rt = create(ptr->rt);

        return ptr;

    }
    void display(node *ptr){
        if(ptr == NULL)
            return;

        cout<<ptr->data<<" ";
        this->display(ptr->lt);
        this->display(ptr->rt);
    }
    void display_leaf(node *ptr){
       //node *p = ptr;
       if(ptr == NULL)
       {
           cout<<"------Tree Is Empty-----\n";
           return;
       }
       int cnt=0;
       while(ptr!=NULL){
            push(ptr);
            if(ptr->lt == NULL && ptr->rt == NULL){
                cnt++;
                cout<<ptr->data<<" ";
            }
            //cout<<ptr->data<<" ";
            ptr = ptr->lt;
       }
       while(!isempty()){
            ptr = top->add;
            pop();
            //cout<<ptr->data<<" ";
            ptr = ptr->rt;
            while(ptr != NULL){
                push(ptr);
                if(ptr->lt == NULL && ptr->rt == NULL){
                    cnt++;
                    cout<<ptr->data<<" ";
                }
                //cout<<ptr->data<<" ";
                ptr = ptr->lt;
            }
       }
       cout<<"\nTotal Count of Leaf Nodes are :: ";
       cout<<cnt<<"\n";
    }
    int depth(node *ptr){
       if(ptr == NULL)
       {
           cout<<"------Tree Is Empty-----\n";
           return 0;
       }
       int len=0;
       int m = 0;

       vector<int>v;
       while(ptr!=NULL){
            push(ptr);
            v.push_back(m);
            m++;
            ptr = ptr->lt;
       }
       if(m>len)
            len = m;
       while(!isempty()){
            ptr = top->add;
            pop();
            m = v.back();
            v.pop_back();
            m++;
            ptr = ptr->rt;
            while(ptr != NULL){
                push(ptr);
                v.push_back(m);
                m++;
                ptr = ptr->lt;
            }
            if(m>len)
                len = m;
       }
       return len;
    }

};
int main()
{
    int ch,x;
    cout<<"Create Tree\n";
    node *ptr = NULL;
    tree t;
    ptr = t.create(ptr);

    do
    {
        cout<<"\n1.InOrder Traversal\n2.No.of Leaf Nodes\n3.Height Of tree\n4.Exit\n";
        cin>>ch;
        switch(ch)
        {

            case 1 :cout<<"\nPreOrder Traversal of The tree\n";
                    t.display(ptr);
                    break;
            case 2 :cout<<"\nThe Leaf Nodes in the Tree Are\n";
                    t.display_leaf(ptr);
                    break;
            case 3: cout<<"\nThe Depth of the Tree :: ";
                    x = t.depth(ptr);
                    cout<<x-1<<"\n";
        }
    }while(ch!=4);
}
