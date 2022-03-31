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

const binarySearch = (arr, number) => {
    arr.sort((a,b) => {return a-b})
    let mid, left = 0, right = arr.length-1
    while(right>=left){
        mid = Math.floor((left+right)/2)
        if(arr[mid]===number){
            return mid
        }
        if(arr[mid]>number){
            right = mid-1
        }
        else{
            left = mid+1
        }
    }
    return -1
}

const jumpSearch = (arr, number) => {

}

const interpolationSearch = (arr, number) => {

}

const exponentialSearch = (arr, number) => {

}

const fibonacciSearch = (arr, number) => {
    
}