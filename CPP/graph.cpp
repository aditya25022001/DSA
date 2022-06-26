#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#include<climits>

using namespace std;

class Graph{
    private:
        map <int,vector<pair<int,int>>> adj;
        int *visited;
        int vertices, temp, current, adjV, tempW;
        queue<int> q; 
        queue<pair<int,int>> cb;
        vector<int> dfsVisited;
        vector<int> dfsColor;
        vector<int> inDegree;
        stack<int> topoSortDfs;
        vector<int> topoSortBfs;
        vector<pair<int,int>> primMst;
        vector<int> rank;
        vector<int> parent; 
    public:
        Graph(int v){
            vertices = v;
            visited = new int[v+1]();
            dfsVisited.resize(v+1,0);
            dfsColor.resize(v+1,-1);
            inDegree.resize(v+1,0);
            rank.resize(v+1,0);
            parent.resize(v+1,0);
            for(int i=0;i<=vertices; ++i) parent[i]=i;
            adj={
                {1,{{5,4},{2,2},{4,1}}},
                {2,{{1,2},{3,3},{4,3},{6,7}}},
                {3,{{2,3},{4,5},{6,8}}},
                {4,{{5,9},{2,3},{3,5},{1,1}}},
                {5,{{1,4},{4,9}}},
                {6,{{2,7},{3,8}}},
            };
        }

        void takeInput(bool weighted){
            adj.clear();
            if(!weighted){
                for(int i=1;i<=vertices;++i){
                    cout<<"Enter no of adjacent vertices for vertex : "<<i<<": "<<endl;
                    cin>>adjV;
                    cout<<"Enter adjacent vertices "<<endl;
                    for(int j=1;j<=adjV;++j){
                        cin>>temp;
                        adj[i].push_back({temp,1});
                    }
                }
            }
            else{
                for(int i=1;i<=vertices;++i){
                    cout<<"Enter no of adjacent vertices for vertex : "<<i<<": "<<endl;
                    cin>>adjV;
                    cout<<"Enter adjacent vertices and weight"<<endl;
                    for(int j=1;j<=adjV;++j){
                        cin>>temp>>tempW;
                        adj[i].push_back({temp, tempW});
                    }
                }
            }
        }  
        
        void calculateIndegree(){
            inDegree.clear();
            for(int i=1;i<=vertices;++i){
                for(auto j:adj[i]){
                    inDegree[j.first]+=1;
                }
            }
        }

        void dfs(int start){
            if(visited[start]==0){
                visited[start]=1;
                cout<<start<<"->";
                for(auto i:adj[start]){
                    dfs(i.first);
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
                for(auto i:adj[current]){
                    if(visited[i.first]==0){
                        cout<<i.first<<"->";
                        q.push(i.first);
                        visited[i.first]=1;
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
                for(auto i:adj[cur]){
                    if(visited[i.first]==0){
                        visited[i.first]=1;
                        cb.push({i.first,cur});
                    }
                    else{
                        if(parent!=i.first){
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
                for(auto i:adj[start]){
                    if(visited[i.first]==0){
                        cycleDfsUndirected(i.first,start);
                    }
                    else{
                        if(parent!=i.first){
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
                for(auto i:adj[cur]){
                    if(visited[i.first]==0){
                        visited[i.first]=1;
                        color.push({i.first,!c});
                        visitedColor[i.first]=!c;
                    }
                    else{
                        if(c==visitedColor[i.first]){
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        bool bipartiteDfs(int start){
            if(dfsColor[start]==-1) dfsColor[start]=1;
            for(auto i:adj[start]){
                if(dfsColor[i.first]==-1){
                    dfsColor[i.first]=1-dfsColor[start];
                    if(!bipartiteDfs(i.first)){
                        return false;
                    }
                }                
                else{
                    if(dfsColor[i.first]==dfsColor[start]){
                        return false;
                    }
                }
            }
            return true;
        }

        bool cycleDfsDirected(int start){
            visited[start]=dfsVisited[start]=1;
            for(auto i:adj[start])
                if(visited[i.first]==0) return cycleDfsDirected(i.first);
                else if(dfsVisited[i.first]==1) return true;
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
                for(auto i:adj[current]){
                    inDegree[i.first]-=1;
                    if(inDegree[i.first]==0){
                        bfsTopo.push(i.first);
                    }
                }
            }
            return visCount!=vertices;
        }

        void topologicalSortDfsUtility(int start){
            visited[start]=1;
            for(auto i:adj[start]){
                if(visited[i.first]==0){
                    topologicalSortDfsUtility(i.first);
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
                for(auto i:adj[current]){
                    inDegree[i.first]-=1;
                    if(inDegree[i.first]==0){
                        bfsTopo.push(i.first);
                    }
                }
            }
            if(visCount==vertices) for(auto i:topoSortBfs) cout<<i<<" ";
            else cout<<"Not possible";
        }
        
        int shortestDistanceUnweighted(int source, int destination){
            vector<int> distance(vertices+1,INT_MAX);
            queue<int> nodes;
            nodes.push(source);
            distance[source] = 0;
            int current;
            while(!nodes.empty()){
                current = nodes.front();
                nodes.pop();
                for(auto i:adj[current]){
                    if(distance[i.first]>distance[current]+1){
                        distance[i.first] = distance[current]+1;
                        nodes.push(i.first);
                    }
                }
            }
            return distance[destination];
        }

        int shortestDistanceDAG(int source, int destination){
            topologicalSortBfs();
            vector<int> distance(vertices+1,INT_MAX);
            distance[source]=0;
            for(auto i:topoSortBfs)
                if(distance[i]!=INT_MAX)
                    for(auto j:adj[i])
                        distance[j.first]=min(distance[i]+j.second,distance[j.first]);
            return distance[destination];
        }
        
        int dijkstraUndirected(int source, int destination){
            vector<int> distance(vertices+1,INT_MAX);
            int current;
            distance[source]=0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
            p.push({ 0, source });
            while(!p.empty()){
                current = p.top().second;
                p.pop();
                for(auto i:adj[current]){
                    if(distance[i.first]>distance[current]+i.second){
                        distance[i.first] = distance[current]+i.second;
                        p.push({ distance[current]+i.second, i.first });
                    }
                }                
            }
            return distance[destination];
        }

        int prims(){

        }

        void makeUnion(int u, int v){
            u=findParent(u);
            v=findParent(v);
            if(rank[u]<rank[v]) parent[u]=v;
            else if(rank[v]<rank[u]) parent[v]=u;
            else {
                parent[v]=u;
                rank[u]++;
            }
        }

        int findParent(int u){
            if(parent[u]==u) return u;
            return parent[u]=findParent(parent[u]);
        }
        
        int kruskal(){
            int cost=0;
            vector<pair<int,int>> mstEdges;
            priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> edges;
            for(auto i:adj) for(auto j:i.second) edges.push({j.second,{i.first, j.first}});
            while(!edges.empty()){
                auto i = edges.top();
                edges.pop(); 
                int u=i.second.first, v=i.second.second;
                if(findParent(u)!=findParent(v)){
                    cost+=i.first;
                    mstEdges.push_back(i.second);
                    makeUnion(u,v);
                }   
            }
            for(auto i:mstEdges) cout<<i.first<<"->"<<i.second<<" ";
            cout<<endl;
            return cost;
        }
        
        ~Graph(){
            delete visited;
        }
};

int main(){
    int vertices;
    bool weighted = false;
    char yes;
    cout<<"Enter vertices : ";
    cin>>vertices;
    cout<<"Weighted ? (Y/N) : ";
    cin>>yes;
    Graph g = Graph(vertices);
    g.takeInput(yes=='Y'|| yes=='y' ? !weighted : weighted);
    cout<<endl<<"MST weight : "<<g.kruskal();
    return 0;
}

// Topological sort -> Linear ordering of vertices such that if u->v is an edge the u comes before v in the ordering
// Bipartite graph -> If a graph has odd length cycle it is not bipartite graph else it is, such a graph that can be coloured using two colors such that no two adjacent vertices have same color
// In finding topological sort using DFS we used utility function for each recursion call for every node( vertex, edge )
// Do the same for each function i.e. there might be components in graph so to take in count every component use main function to iterate through the vertices and if not visited do the required function
// Dijkstra can handle cycle and any weighted graph but not negative weights
// minimum spanning tree -> N nodes and E-1 edges and every node is reachable from any node of the tree and the cost of tree is least in all possible trees
// In cycle detection of undirected graph run the algorithm for every vertex and return accordingly 