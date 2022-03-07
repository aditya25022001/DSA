function createNode(data){
    return {
        data:data,
        next:null
    }
}
class LinkedList{
    constructor(){
        this.head = null
        this.tail = null
        this.length = 0
    }
    
    size(){
        return this.length
    }
    
    addNode(data){
        let node = createNode(data)
        if(!this.tail){
            this.head = this.tail = node
            this.length++
            return node
        }
        this.tail.next = node
        this.tail = node
        this.length++
        return node
    }
    
    print(){
        let currentNode = this.head
        while(currentNode){
            console.log(currentNode.data)
            currentNode = currentNode.next
        }
    }
    
    reverse(){
        let node = this.head, previous, temporary;
        while(node){
            temporary = node.next
            node.next = previous
            previous = node
            node = temporary
        }
        this.head = previous
    }
}
let list = new LinkedList()
list.addNode(0)
list.addNode(1)
list.addNode(2)
list.addNode(3)
list.addNode(4)
list.addNode(5)