#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>

using namespace std;

class Graph{
    private:
        map <int,vector<int>> adj;
        int *visited;
        int vertices, temp, current, adjV;
        queue<int> q; 
        queue<pair<int,int>> cb;
        vector<int> dfsVisited;
        vector<int> dfsColor;
        vector<int> inDegree;
        stack<int> topoSortDfs;
        vector<int> topoSortBfs;
    public:
        Graph(int v){
            vertices = v;
            visited = new int[v+1]();
            dfsVisited.resize(v+1,0);
            dfsColor.resize(v+1,-1);
            inDegree.resize(v+1,0);
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
        
        void calculateIndegree(){
            inDegree.clear();
            for(int i=1;i<=vertices;++i){
                for(auto j=adj[i].begin();j!=adj[i].end();++j){
                    inDegree[*j]+=1;
                }
            }
        }

        void dfs(int start){
            if(visited[start]==0){
                visited[start]=1;
                cout<<start<<"->";
                for(auto i=adj[start].begin();i!=adj[start].end();++i){
                    dfs(*i);
                }
            }
        }
    
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

        bool cycleBfsUndirected(int start){
            visited = new int[vertices+1]{0};
            visited[start] =1;
            cb.push({start,-1});
            while(!cb.empty()){
                int cur = cb.front().first;
                int parent = cb.front().second;
                cb.pop();
                for(auto i=adj[cur].begin();i!=adj[cur].end();++i){
                    if(visited[*i]==0){
                        visited[*i]=1;
                        cb.push({*i,cur});
                    }
                    else{
                        if(parent!=*i){
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        bool cycleDfsUndirected(int start, int parent){
            if(visited[start]==0){
                visited[start]=1;
                for(auto i=adj[start].begin();i!=adj[start].end();++i){
                    if(visited[*i]==0){
                        cycleDfsUndirected(*i,start);
                    }
                    else{
                        if(parent!=*i){
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        bool bipartiteBfs(int start){
            visited = new int[vertices+1]{0};
            int* visitedColor = new int[vertices+1]{-1};
            visited[start] = 1;
            queue<pair<int,bool>> color;
            color.push({start,0});
            visitedColor[start] = 0;
            while(!color.empty()){
                int cur = color.front().first;
                int c = color.front().second;
                color.pop();
                for(auto i=adj[cur].begin();i!=adj[cur].end();++i){
                    if(visited[*i]==0){
                        visited[*i]=1;
                        color.push({*i,!c});
                        visitedColor[*i]=!c;
                    }
                    else{
                        if(c==visitedColor[*i]){
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        bool bipartiteDfs(int start, int c){
            dfsColor[start]=c;
            for(auto i=adj[start].begin();i!=adj[start].end();++i){
                if(dfsColor[*i]==-1){
                    if(!bipartiteDfs(*i,1-c)){
                        return false;
                    }
                }                
                else{
                    if(dfsColor[*i]==c){
                        return false;
                    }
                }
            }
            return true;
        }

        bool cycleDfsDirected(int start){
            visited[start]=dfsVisited[start]=1;
            for(auto i=adj[start].begin(); i!=adj[start].end();++i){
                if(visited[*i]==0){
                    return cycleDfsDirected(*i);
                }
                else{
                    if(dfsVisited[*i]==1){
                        return true;
                    }
                }
            }
            dfsVisited[start]=false;
            return false;
        }

        bool cycleBfsDirected(){
            calculateIndegree();
            queue<int> bfsTopo;
            int current;
            int visCount=0;
            for(int i=1;i<=vertices;++i){
                if(inDegree[i]==0){
                    bfsTopo.push(i);
                }
            }
            while(!bfsTopo.empty()){
                current = bfsTopo.front();
                bfsTopo.pop();
                visCount++;
                for(auto i=adj[current].begin();i!=adj[current].end();++i){
                    inDegree[*i]-=1;
                    if(inDegree[*i]==0){
                        bfsTopo.push(*i);
                    }
                }
            }
            return visCount!=vertices;
        }

        void topologicalSortDfsUtility(int start){
            visited[start]=1;
            for(auto i=adj[start].begin();i!=adj[start].end();++i){
                if(visited[*i]==0){
                    topologicalSortDfsUtility(*i);
                }
            }
            topoSortDfs.push(start);
        }
        
        void topologicalSortDfs(){
            for(int i=1;i<=vertices;++i){
                if(visited[i]==0){
                    topologicalSortDfsUtility(i);
                }
            }
            while(!topoSortDfs.empty()){
                cout<<topoSortDfs.top()<<" ";
                topoSortDfs.pop();
            }
            cout<<endl;
        }
        
        void topologicalSortBfs(){
            int visCount = 0;
            calculateIndegree();
            queue<int> bfsTopo;
            int current;
            for(int i=1;i<=vertices;++i){
                if(inDegree[i]==0){
                    bfsTopo.push(i);
                }
            }
            while(!bfsTopo.empty()){
                current = bfsTopo.front();
                bfsTopo.pop();
                topoSortBfs.push_back(current);
                visCount++;
                for(auto i=adj[current].begin();i!=adj[current].end();++i){
                    inDegree[*i]-=1;
                    if(inDegree[*i]==0){
                        bfsTopo.push(*i);
                    }
                }
            }
            if(visCount==vertices){
                for(auto i=topoSortBfs.begin();i!=topoSortBfs.end();++i){
                    cout<<*i<<" ";
                }
            }
            else{
                cout<<"Not possible";
            }
        }
        
        int shortestDistanceUnweighted(int source){
            vector<int> distance(vertices+1,INT_MAX);
            queue<int> nodes;
            nodes.push(source);
            distance[source] = 0;
            
        }

        void prims(){

        }
        
        void kruskal(){

        }
        
        void dijkstra(){
            
        }
        
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

// Topological sort -> Linear ordering of vertices such that if u->v is an edge the u comes before v in the ordering
// Bipartite graph -> If a graph has odd length cycle it is not bipartite graph else it is, such a graph that can be coloured using two colors such that no two adjacent vertices have same color
// In finding topological sort using DFS we used utility function for each recursion call for every node( vertex, edge )
// Do the same for each function i.e. there might be components in graph so to take in count every component use main function to iterate through the vertices and if not visited do the required function