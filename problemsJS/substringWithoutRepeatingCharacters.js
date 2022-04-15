var lengthOfLongestSubstring = function(s) {
    let left=0, right=0, max=0;
    const map = new Map()
    while(right<s.length){
        if(!map.has(s.charAt(right))){
            map.set(s.charAt(right))
            right++;
            max = Math.max(max,map.size)
        }
        else{
            map.delete(s.charAt(left))
            left++;
        }
    }
    return max;
};