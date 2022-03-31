const bubbleSort = (arr) => {
    let temp;
    for(let i=0;i<arr.length;++i){
        for(let j=0;j<arr.length-i-1;++j){
            if(arr[j]>arr[j+1]){
                temp = arr[j]
                arr[j]=arr[j+1]
                arr[j+1]=temp
            }
        }
    }
    return arr
}

const insertionSort = (arr) => {
    let n = arr.length;
        for (let i = 1; i < n; i++) {
            let current = arr[i];
            let j = i-1; 
            while ((j > -1) && (current < arr[j])) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = current;
        }
    return arr;
}

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

const mergeSort = (arr) => {
    const merge = (left,right) => {
        let arr = []
        while (left.length && right.length) {
            if (left[0] < right[0]) {
                arr.push(left.shift())  
            } else {
                arr.push(right.shift()) 
            }
        }
        return [ ...arr, ...left, ...right ]
    }
    const half = arr.length / 2
    if(arr.length < 2){
      return arr 
    }
    const left = arr.splice(0, half)
    return merge(mergeSort(left),mergeSort(arr))
}

const quickSort = (arr) => {

}

const heapSort = (arr) => {

}

const countingSort = (arr) => {

}

const radixSort = (arr) => {

}

const bucketSort = (arr) => {

}

const shellSort = (arr) => {

}

const timSort = (arr) => {

}

const combSort = (arr) => {

}

const binaryInsertionSort = (arr) => {}

const bitonicSort = (arr) => {}
