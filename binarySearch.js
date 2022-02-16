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