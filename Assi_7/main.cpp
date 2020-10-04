#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    int **cost;
public:
    graph(int v)
    {
        this->v = v;
        cost = new int*[v];

        for(int i = 0;i<v;i++)
            *(cost + i) = new int[v];
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
                cost[i][j] = 999;
        }
    }

    void read_graph()
    {
        int src,des;
        int e;
        cout<<"Enter The Number Of Edges\n";cin>>e;
        for(int i=0;i<e;i++)
        {
            cout<<"Enter The Source And Destination :: ";
            cin>>src>>des;

            cout<<"Enter The Cost\n";
            cin>>cost[src][des];

            cost[des][src] = cost[src][des];
        }
    }
    void print(int from[],int src)
    {
        if(src == 0)
        {
            cout<<src<<"->";
            return;
        }
        print(from,from[src]);
        cout<<src<<"->";
    }
    void display(int from[],int distance[])
    {
        for(int i=0;i<v;i++){
            cout<<i<<" ) ";
            print(from,i);
            cout<<" ( "<<distance[i]<<" )";
            cout<<"\n";
        }
    }
    void dijisktra(int strtnode)
    {
      
        int visited[v]={0};
        int distance[v];
        int from[v];
        int src = strtnode;
        for(int i=0;i<v;i++){
            from[i] = src;
            distance[i] = 999;
        }


        visited[src] = 1;
        distance[src] = 0;
        int temp;
        while(1)
        {
            
            visited[src] = 1;
            for(int i=0;i<v;i++)
            {
                if(visited[i] == 0)
                {
                    temp = distance[i];
                    distance[i] = min(distance[i],cost[src][i] + distance[src]);
                    if(temp!=distance[i])
                        from[i] = src;
                }
            }
            int flag = 0;
            int m = 999;

            for(int i=0;i<v;i++)
            {
                if(visited[i] == 0 &&  distance[i]<m)
                {
                    m = distance[i];
                    flag = 1;
                    src = i;
                }
            }
            if(flag == 0)
                break;
            /*else
                visited[src] = 1;*/
        }
        cout<<"\n The Distance Array\n";
        for(int i=0;i<v;i++)
            cout<<distance[i]<<"\t";
        cout<<endl;

        display(from,distance);
        cout<<endl;
    }
    void prim(int src)
    {
        int visited[v]={0};
        int distance[v];
        int from[v];
        for(int i=0;i<v;i++)
        {
            distance[i] = 999;
            from[i] = src;
        }
        distance[src] = 0;
        int temp;
        while(1)
        {
            visited[src] = 1;
            for(int i=0;i<v;i++)
            {
                if(visited[i]==0)
                {
                    temp = distance[i];
                    distance[i] = min(distance[i],cost[src][i]);
                    if(temp != distance[i])
                        from[i] = src;
                }
            }
            int m = 999,flag = 0;
            for(int i = 0;i<v;i++)
            {
                if(visited[i] == 0 &&  distance[i]<m)
                {
                    m = distance[i];
                    flag = 1;
                    src = i;
                }
            }
            if(flag == 0)
                break;

        }
        int sum = 0;
        cout<<"\n Distance Matrix\n";
        for(int i=0;i<v;i++){
            cout<<distance[i]<<"\t";
            sum += distance[i];
        }

        cout<<"\n From Matrix\n";
        for(int i=0;i<v;i++)
            cout<<from[i]<<"\t";

        cout<<endl;
        display(from,distance);

        cout<<"\n The Minimum cost Of the Given Graph is :: "<<sum<<"\n";
    }
};
int main()
{
    int v;
    cout<<"Enter The Number Of Vertex \n";
    cin>>v;

    graph g(v);
    g.read_graph();
    cout<<"\n-------------------Dijikstra Algorithm---------------------\n";
    g.dijisktra(0);
    cout<<"\n-------------------Prim-----------------------\n";
    g.prim(0);
}
