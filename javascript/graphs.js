class Graph {
    constructor() {
        this.adjacencyList = {};
        this.dfsResult = []
        this.visited = {}
    }
    
    addVertex(vertex) {
        if (!this.adjacencyList[vertex]) {
            this.adjacencyList[vertex] = [];
        }
    }
    
    addEdge(source, destination) {
        if (!this.adjacencyList[source]) {
            this.addVertex(source);
        }
        if (!this.adjacencyList[destination]) {
            this.addVertex(destination);
        }
        this.adjacencyList[source].push(destination);
    }
    
    removeEdge(source, destination) {
        this.adjacencyList[source] = this.adjacencyList[source].filter(vertex => vertex !== destination);
        this.adjacencyList[destination] = this.adjacencyList[destination].filter(vertex => vertex !== source);
    }
    
    removeVertex(vertex) {
        while (this.adjacencyList[vertex]) {
            const adjacentVertex = this.adjacencyList[vertex].pop();
            this.removeEdge(vertex, adjacentVertex);
        }
        delete this.adjacencyList[vertex];
    }  

    bfs(start){
        const queue = [start];
        const result = [];
        const visited = {};
        visited[start] = true;
        let currentVertex;
        while (queue.length) {
            currentVertex = queue.shift();
            result.push(currentVertex);
            this.adjacencyList[currentVertex].forEach(neighbor => {
                if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
                }
            });
        }
        return result;
    }

    dfs(start){
        if(!this.visited[start]){
            this.visited[start] = true;
            this.dfsResult.push(start);
            this.adjacencyList[start].forEach(neighbor => {
                this.dfs(neighbor);
            })
        }
        return this.dfsResult
    }
}

const graph = new Graph();
graph.addVertex(1)
graph.addVertex(2)
graph.addVertex(3)
graph.addVertex(4)
graph.addVertex(5)
graph.addVertex(6)
graph.addEdge(1,2)
graph.addEdge(1,3)
graph.addEdge(1,6)
graph.addEdge(2,1)
graph.addEdge(2,3)
graph.addEdge(2,4)
graph.addEdge(3,1)
graph.addEdge(3,2)
graph.addEdge(3,4)
graph.addEdge(3,6)
graph.addEdge(4,2)
graph.addEdge(4,3)
graph.addEdge(4,5)
graph.addEdge(5,4)
graph.addEdge(5,6)
graph.addEdge(6,1)
graph.addEdge(6,5)
graph.addEdge(6,3)
console.log(graph.bfs(3))  
console.log(graph.dfs(3))  