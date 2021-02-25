class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if(n==1)
            return k;
        int same=k,diff=k*(k-1);
        for (int i = 2; i <n ; i++) {
            int total=diff+same;
            same=diff;
            diff=total*(k-1);
        }
        return same+diff;
    }
};