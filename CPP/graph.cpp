#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph{
    public:
        int adjacencyMatrix[20][20]={};
        int vertices; 
        int *visited;
        Graph(int v){
            vertices = v;
            visited = new int[v+1]();        
        }
        void takeInput(){
            cout<<endl<<"Enter 1 if adjacent and 0 if not"<<endl;
            for(int i=1;i<=vertices;++i){
                cout<<"For vertex : "<<i<<": "<<endl;
                for(int j=1;j<=vertices;++j){
                    cin>>adjacencyMatrix[i][j];
                } 
            }
        }
        void dfs(int start){
            if(visited[start]==0){
                cout<<start<<"->";
                visited[start]=1;
                for(int i=1;i<=vertices;++i){
                    if(adjacencyMatrix[start][i]==1){
                        dfs(i);
                    }
                }
            }
        }
        void bfs(int start){
            visited = new int[vertices+1] ();
            queue<int> q;
            int nextNode;
            cout<<start<<"->";
            visited[start]=1;
            q.push(start);
            while(!q.empty()){
                nextNode = q.front();
                q.pop();
                for(int i=1;i<=vertices;++i){
                    if(adjacencyMatrix[nextNode][i]==1 && visited[i]==0){
                        cout<<i<<"->";
                        q.push(i);
                        visited[i]=1;
                    }
                }
            }
        }
        void prims(){}
        void dijkstra(){}
        void kruskal(){}
        void topologicalSort(){}
        ~Graph(){
            delete visited;
        }
};
int main(){
    int vertices;
    cout<<"Enter vertices : ";
    cin>>vertices;
    Graph g = Graph(vertices);
    g.takeInput();
    return 0;
}
