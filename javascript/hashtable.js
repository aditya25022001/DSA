class HashTable{
    constructor(){
        this.size=0;
        this.buckets=new Array(127);
    }
    _hash(key){
        let hash = 0;
        for(let i=0;i<key.length;++i){
            hash+=key.charCodeAt(i)
        }
        return hash%this.buckets.length
    }
    set(key,value){
        const index = this._hash(key)
    }
    get(key){
        const index = this._hash(key)
    }
    remove(key){}
    displace(){}
}