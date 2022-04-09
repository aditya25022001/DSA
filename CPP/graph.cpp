#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

class Graph{
    private:
        map <int,vector<int>> adj;
        int *visited;
        int vertices, temp, current, adjV;
        queue<int> q;
    public:
        
        Graph(int v){
            vertices = v;
            visited = new int[v+1]();
        }
        
        void takeInput(){
            for(int i=1;i<=vertices;++i){
                cout<<"Enter no of adjacent vertices for vertex : "<<i<<": "<<endl;
                cin>>adjV;
                cout<<"Enter adjacent vertices "<<endl;
                for(int j=1;j<=adjV;++j){
                    cin>>temp;
                    adj[i].push_back(temp);
                }
            }
        }
        
        void displayList(){
            for(int i=1;i<=adj.size();++i){
                for(auto j=adj[i].begin();j!=adj[i].end();++j){
                    cout<<*j<<" ";
                }
                cout<<endl;
            }
        }
        
        // TC : O(N+E) SC : O(N+E)+O(N)+O(N)        
        void dfs(int start){
            if(visited[start]==0){
                visited[start]=1;
                cout<<start<<"->";
                for(auto i=adj[start].begin();i!=adj[start].end();++i){
                    dfs(*i);
                }
            }
        }
        
        // TC : O(N+E) SC : O(N+E)+O(N)+O(N)
        void bfs(int start){
            visited = new int[vertices+1]();
            cout<<start<<"->";
            visited[start] = 1;
            q.push(start);
            while(!q.empty()){
                current = q.front();
                q.pop();
                for(auto i=adj[current].begin();i!=adj[current].end();++i){
                    if(visited[*i]==0){
                        cout<<*i<<"->";
                        q.push(*i);
                        visited[*i]=1;
                    }
                }
            } 
        }
        
        void topologicalSort(){}
        
        void prims(){}
        
        void kruskal(){}
        
        void dijkstra(){}
        
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
    g.displayList();
    g.dfs(2);
    g.bfs(3);
    return 0;
}