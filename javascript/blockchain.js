import crypto from "crypto-js";

class Block{
    constructor(data, index, timestamp, previousHash=""){   
        this.data = data;
        this.timestamp = timestamp;
        this.index = index;
        this.previousHash = previousHash;
        this.hash = this.generateHash();
    }
    generateHash(){
        return crypto.SHA256(JSON.stringify(this.data)+this.timestamp+this.index+this.previousHash).toString()
    }
}

class BlockChain{
    constructor(){
        this.chain = [this.createGenesisBlock()];
    }
    createGenesisBlock(){
        return new Block("Genesis block",0,"25/02/2022","0");
    }
    getLatestBlock(){
        return this.chain[this.chain.length-1];
    }
    addBlock(newBlock){
        newBlock.previousHash = this.getLatestBlock().hash;
        newBlock.hash = newBlock.generateHash();
        this.chain.push(newBlock);
    }
}

const myChain = new BlockChain();
myChain.addBlock(new Block({ name:'Aditya' },1,"26/02/2022"))
myChain.addBlock(new Block({ name:'Arpita' },2,"27/02/2022"))

console.log(JSON.stringify(myChain,null,4))