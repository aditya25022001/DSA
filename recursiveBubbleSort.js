// time complexity = O(n^2)
// space complexity = O(1)
const recursiveBubbleSort = (arr,length) => {
    let temp;
    if(length===1){
        return arr
    }
    for(let i=0;i<length-1;++i){
        if(arr[i]>arr[i+1]){
            temp = arr[i]
            arr[i]=arr[i+1]
            arr[i+1]=temp
        }
    }
    recursiveBubbleSort(arr,length-1)
}