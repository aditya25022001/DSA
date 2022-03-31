const depthFirstSearch = (node, result) => {
    if(node.left){
        depthFirstSearch(node.left, result)
    }
    result.push(node.val)
    if(node.right){
        depthFirstSearch(node.right,result)
    }
    return result
}

