const linearSearch = (arr, number) => {
    let index = -1
    for(let i=0;i<arr.length;++i) {
        if(arr[i]===number){
            index = i
            break;
        }
    }
    return index
}
