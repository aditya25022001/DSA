var maxArea = function(height) {
    let left = 0, right = height.length-1
    let max = 0, temp;
    while(left<right){
        temp = Math.min(height[left],height[right])*(right-left)
        max = Math.max(max,temp)
        if(height[right]>height[left]){
            left+=1
        }
        else{
            right-=1
        }
    }
    return max
};