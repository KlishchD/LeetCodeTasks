class Solution {
    public int maxProfit(int[] a) {
        int n = a.length;
        
        int min = a[0];
        int[] l = new int[n];
        for (int i = 1; i < n; ++i) {
            l[i] = Math.max(0, a[i] - min);
            min = Math.min(min, a[i]);
        }
        
        int max = a[n - 1];
        int[] r = new int[n];
        for (int i = n - 2; i >= 0; --i) {
            r[i] = Math.max(0, max - a[i]);
            max = Math.max(max, a[i]);
        }
        
        for (int i = 1; i < n; ++i) {
            l[i] = Math.max(l[i], l[i - 1]);   
            r[n - 1 - i] = Math.max(r[n - 1 - i], r[n - i]);
        }
        
        int ans = Math.max(l[n - 1], r[0]);
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n) {
                ans = Math.max(ans, l[i] + r[i + 1]);
            }
            if (i - 1 >= 0) {
                ans = Math.max(ans, l[i - 1] + r[i]);
            }
        }
        return ans;
    }
}
