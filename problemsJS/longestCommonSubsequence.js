var longestCommonSubsequence = function(text1, text2) {
    let dp = Array(text1.length+1).fill().map(()=>Array(text2.length+1).fill(0))
    for(let i=text1.length-1;i>-1;--i){
        for(let j=text2.length-1;j>-1;--j){
            if(text1.charAt(i)===text2.charAt(j)){
               dp[i][j]=1+dp[i+1][j+1]
            }
            else{
                dp[i][j]=Math.max(dp[i+1][j],dp[i][j+1])
            }
        }
    }
    return dp[0][0]
}