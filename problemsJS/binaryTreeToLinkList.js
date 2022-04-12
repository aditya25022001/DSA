var flatten = function(root) {
    let res = [], current;
    if(!root){
        return root 
    }
    res.push(root)
    while(res.length!==0){
        current=res.pop()
        if(current.right)
            res.push(current.right)
        if(current.left)
            res.push(current.left)
        if(res.length!==0)
            current.right=res[res.length-1]
        current.left=null   
    }
    return root
};