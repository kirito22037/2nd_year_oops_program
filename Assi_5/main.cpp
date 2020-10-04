#include<bits/stdc++.h>
using namespace std;
struct n
{
    int data;
    struct n *rt;
    struct n *lt;
};
typedef struct n node;
class tree
{
public:
    node *Insert(node *root,int key){
        node *temp = new node;
        temp->data = key;
        temp->lt = temp->rt = NULL;

        if(root == NULL){
            root = temp;
            return root;
        }
        node *ptr = root;
        node *ptr1 = ptr;
        while(1){
            if(ptr == NULL){
                if(ptr1->data > key)
                    ptr1->lt = temp;
                else
                    ptr1->rt = temp;
                break;
            }
            else if(key < ptr->data){
                ptr1 = ptr;
                ptr = ptr->lt;
            }
            else if(key > ptr->data){
                ptr1 = ptr;
                ptr = ptr->rt;
            }
            else if(ptr->data == key){
                cout<<"Already Present\n";
                break;
            }
        }
        return root;
    }
    void display(node *ptr){
        if(ptr == NULL){
            return;
        }
        cout<<ptr->data<<" ";
        display(ptr->lt);
        display(ptr->rt);
    }
    node *mirror(node *t){
        if(t == NULL){
            return NULL;
        }
        node *p = new node;
        p->data = t->data;
        p->lt = mirror(t->rt);
        p->rt = mirror(t->lt);
        return p;
    }

    node *minimun(node *t){
        while(t->lt != NULL){
            t = t->lt;
        }
        cout<<" "<<t->data;
        return t;
    }

    void maximun(node *t){
        while(t->rt != NULL){
            t = t->rt;
        }
        cout<<" "<<t->data;
    }
    void search_bst(node *root){
        int key ;
        cout<<"Enter The Element You Want To Find >> ";
        cin>>key;
        int m=0;
        while(root != NULL){
            if(root->data == key)
                break;
            else if(key < root->data){
                root = root->lt;
                m++;
            }
            else{
                root = root->rt;
                m++;
            }
        }
        if(root == NULL){
            cout<<"Not Found!!\n";
        }
        else{
            cout<<"Found at Level "<<m<<"\n";
        }
    }
    void display_level(node *root){

        if(root == NULL)
            return;

        queue<node *> q1;

        q1.push(root);
        while(q1.empty() == false){

            int nc = q1.size();
            while (nc > 0){

                node *ptr = q1.front();
                cout << ptr->data << " ";
                q1.pop();
                if(ptr->lt != NULL)
                    q1.push(ptr->lt);
                if(ptr->rt != NULL)
                    q1.push(ptr->rt);
                nc--;
            }
            cout << endl;
        }
    }
    node *delete_node(node *root,int key){
        if(root == NULL)
            return root;
        else if(key<root->data)
            root->lt = delete_node(root->lt,key);
        else if(key > root->data)
            root->rt = delete_node(root->rt,key);
        else{
            if(root->rt == NULL && root->lt == NULL)
            {
                delete root;
                root = NULL;
            }
            else if(root->rt == NULL){
                node *temp = root;
                root = root->lt;
                delete temp;
            }
            else if(root->lt == NULL){
                node *temp = root;
                root = root->rt;
                delete temp;
            }
            else
            {
                node *temp = minimun(root->rt);
                root->data = temp->data;
                root->rt = delete_node(root->rt,temp->data);
            }
        }
        return root;
    }
};
int main()
{
    tree t;
    node *root = NULL,*root1 = NULL;
    int x;
    cout<<"Please Enter A Tree \n";
    do
    {
        cout<<"Enter The Value of Node else -1 for NULL >> ";
        cin>>x;
        if(x != -1){
           root = t.Insert(root,x);
        }
    }while(x != -1);
    cout<<"The Tree Inserted is :: ";
    t.display(root);

    node *ptr;
    int ch,key;
    do
    {
        cout<<"\n1.Display The Tree Level Wise\n2.Maximum\n3.Minimum\n4.Mirror Image\n5.Search\n6.Insert Another Element\n7.Delete\n8.Exit >> ";
        cin>>ch;
        switch(ch)
        {
            case 1: t.display_level(root);
                    break;
            case 2: cout<<"The Maximum In the Tree is \n";
                    t.maximun(root);
                    break;
            case 3: cout<<"The Minimum In the Tree is \n";
                    ptr = t.minimun(root);
                    break;
            case 4: root1 = t.mirror(root);
                    t.display(root1);
                    break;
            case 5: t.search_bst(root);
                    break;
            case 6: cout<<"Enter The Element to Insert >> ";
                    cin>>x;
                    root = t.Insert(root,x);
                    //cout<<"Inserted SuccessFully \n";
                    break;
            case 7 :cout<<"Enter The Element You Want To Delete ? ";
                    cin>>key;
                    t.delete_node(root,key);
                    break;
        }
    }while(ch!=8);
}
