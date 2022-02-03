// time conplexity = O(n^2)
// space conplexity = O(n)
const selectionSort = (arr) => {
    let min, temp;
    for(let i=0;i<arr.length;++i){
        min=i;
        for(let j=i+1;j<arr.length;++j){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(min!==i){
            temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    return arr
}