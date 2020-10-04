#include<bits/stdc++.h>
using namespace std;
struct n
{
    char data;
    int flag;
    struct n *lt;
    struct n *rt;
};
typedef struct n node;
struct stac
{
    node *add;
    struct stac *next;
};
class stk
{
    struct stac *top;
public:
    stk(){
        top = NULL;
    }
    void push(node *ptr){
        struct stac *temp = new struct stac;
        temp->add = ptr;
        temp->next = NULL;
        if(top!=NULL)
            temp->next = top;
        top = temp;
    }
    void pop(){
        struct stac *temp = top;
        top = top->next;
        delete(temp);
    }
    bool isempty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }
    node *create_tree1(char *a){
        int i=0;
        node *t1,*t2;
        while(a[i]){
                //cout<<"HII\n";
            if(isalnum(a[i])){
                node *temp = new node;
                temp->data = a[i++];
                temp->lt = temp->rt = NULL;
                push(temp);
            }
            else{
                t1 = top->add;pop();
                t2 = top->add;pop();

                node *temp = new node;
                temp->data = a[i++];
                temp->rt = t1;
                temp->lt = t2;
                push(temp);
            }
        }
        node *ptr = top->add;
        pop();
        return ptr;
    }
    node *create_tree2(char *a){
        int i=strlen(a)-1;
        node *t1,*t2;
        for(;i>=0;i--){
            if(isalnum(a[i])){
                node *temp = new node;
                temp->data = a[i];
                temp->lt = temp->rt = NULL;
                push(temp);
            }
            else{
                t1 = top->add;pop();
                t2 = top->add;pop();

                node *temp = new node;
                temp->data = a[i];
                temp->rt = t2;
                temp->lt = t1;
                push(temp);
            }
        }
        node *ptr = top->add;
        pop();
        return ptr;
    }
    void InOrder(node *ptr){
        if(ptr == NULL)
            return;
        InOrder(ptr->lt);
        cout<<ptr->data<<" ";
        InOrder(ptr->rt);
    }
    void PreOrder(node *ptr){
        if(ptr == NULL)
            return;
        cout<<ptr->data<<" ";
        PreOrder(ptr->lt);
        PreOrder(ptr->rt);
    }
    void PostOrder(node *ptr){
        if(ptr == NULL)
            return;
        PostOrder(ptr->lt);
        PostOrder(ptr->rt);
        cout<<ptr->data<<" ";
    }
    void PreOrder_nonrecursive(node *ptr)
    {
        if(ptr == NULL){
            cout<<"\n------The Tree is Empty ------\n";
            return;
        }
        while(ptr!=NULL){
            push(ptr);
            cout<<ptr->data<<" ";
            ptr = ptr->lt;
       }
       while(!isempty()){
            ptr = top->add;
            pop();
            ptr = ptr->rt;
            while(ptr != NULL){
                push(ptr);
                cout<<ptr->data<<" ";
                ptr = ptr->lt;
            }
       }
    }
    void InOrder_nonrecursive(node *ptr){
        if(ptr == NULL){
            cout<<"\n------The Tree is Empty ------\n";
            return;
        }
        while(ptr != NULL){
            push(ptr);
            ptr = ptr->lt;
        }
        while(!isempty()){
            ptr = top->add;
            pop();
            cout<<ptr->data<<" ";
            ptr = ptr->rt;
            while(ptr!=NULL){
                push(ptr);
                ptr = ptr->lt;
            }
        }
    }
    void PostOrder_nonrecursive(node *ptr){
        while(ptr != NULL){
            ptr->flag=0;
            push(ptr);
            ptr = ptr->lt;
        }
        while(!isempty())
        {
            ptr = top->add;
            pop();
            if(ptr->flag == 0){
                ptr->flag = 1;
                push(ptr);
                ptr = ptr->rt;
                while(ptr!=NULL){
                    ptr->flag = 0;
                    push(ptr);
                    ptr = ptr->lt;
                }
            }
            else
                cout<<ptr->data<<" ";
        }
    }
};
int main()
{
    char post[30],pre[30];
    int ch;
    cout<<"\nEnter The Postfix Notation\n";
    cin>>post;

    stk s1;
    node *t1 = s1.create_tree1(post);

    cout<<"\nEnter The Prefix Notation\n";
    cin>>pre;

    node *t2 = s1.create_tree2(pre);//node *pr = s1.top();

    do
    {
        cout<<"\n\nRECCCURSIVE\n";
        cout<<"\n\tPostfix\n1.InOrder\n2.PreOrder\n3.Postorder\n\n\tPrefix\n4.InOrder\n5.PreOrder\n6.PostOrder\n";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"InOrder Traversal Of Tree from Postfix Sequence :: ";
                    s1.InOrder(t1);
                    break;
            case 2: cout<<"\nPreOrder Traversal Of Tree from Postfix Sequence :: ";
                    s1.PreOrder(t1);
                    break;
            case 3: cout<<"\nPostOrder Traversal Of Tree from Postfix Sequence :: ";
                    s1.PostOrder(t1);
                    break;
            case 4: cout<<"\nInOrder Traversal Of Tree from Prefix Sequence :: ";
                    s1.InOrder(t2);
                    break;
            case 5: cout<<"\nPreOrder Traversal Of Tree from Prefix Sequence :: ";
                    s1.PreOrder(t2);
                    break;
            case 6: cout<<"\nPostOrder Traversal Of Tree from Prefix Sequence :: ";
                    s1.PostOrder(t2);
                    break;
        }
    }while(ch!=7);

    do
    {
        cout<<"\n\nNON-RECCCURSIVE\n";
        cout<<"\n\tPostfix\n1.InOrder\n2.PreOrder\n3.Postorder\n\n\tPrefix\n4.InOrder\n5.PreOrder\n6.PostOrder\n";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"InOrder Traversal Of Tree from Postfix Sequence :: ";
                    s1.InOrder_nonrecursive(t1);
                    break;
            case 2: cout<<"\nPreOrder Traversal Of Tree from Postfix Sequence :: ";
                    s1.PreOrder_nonrecursive(t1);
                    break;
            case 3: cout<<"\nPostOrder Traversal Of Tree from Postfix Sequence :: ";
                    s1.PostOrder_nonrecursive(t1);
                    break;
            case 4: cout<<"\nInOrder Traversal Of Tree from Prefix Sequence :: ";
                    s1.InOrder_nonrecursive(t2);
                    break;
            case 5: cout<<"\nPreOrder Traversal Of Tree from Prefix Sequence :: ";
                    s1.PreOrder_nonrecursive(t2);
                    break;
            case 6: cout<<"\nPostOrder Traversal Of Tree from Prefix Sequence :: ";
                    s1.PostOrder_nonrecursive(t2);
                    break;
        }
    }while(ch!=7);
}
