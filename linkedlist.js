class ListNode{
    constructor(data){
        this.data=data
        this.next=null
    }
    attach(node){
        this.next=node
    }
}

class LinkedList{
    constructor(head=null){
        this.head=head
    }
    traverse(){
        let temp = this.head;
        while(temp!==null){
            console.log(temp.data)
            temp=temp.next
        }
    }
    delete(value){
        let temp = this.head, tempprev = this.head;
        while(temp!==null){
            if(temp.data===value){
                tempprev.next=temp.next
            }
            tempprev = temp;
            temp=temp.next;
        }
    }
}