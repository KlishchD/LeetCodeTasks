import java.util.Arrays;

class Solution {
    
    public int check(int[] a, int delta) {
        int c = 0;
        
        for (int i = 0; i < a.length; ++i) {
            int l = i, r = a.length - 1, mid, ans = i;
            while (r >= l) {
                mid = l + (r - l) / 2;
                if (a[mid] - a[i] > delta) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                    ans = mid;
                }
            }
            c += ans - i;
        }
        
        return c;
    }
    
    public int smallestDistancePair(int[] a, int k) {
        int n = a.length;
    
        Arrays.sort(a);
        
        int l = 0, r = a[a.length - 1], mid, ans = -1;
        while (r >= l) {
            mid = l + (r - l) / 2;
            
            if (check(a, mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        System.out.println(check(a, 0));
        return ans;
    }
}
