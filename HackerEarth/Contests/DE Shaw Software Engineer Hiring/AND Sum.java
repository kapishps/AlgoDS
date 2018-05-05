import java.io.*;
import java.util.*;
 
public class Solution {
    static long mod = (long)1E9 + 7;
    static long pow2[] = new long[100009];
    static void calc_pow2(int n){
        pow2[0]=1;
        for (int i = 1; i < n; ++i) {
            pow2[i] =2*pow2[i-1];
            pow2[i] %=mod;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());
        calc_pow2(100009);
        while(t-- > 0){
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            int array[] = new int[n + 1];
            for(int i = 1;i <= n;i++)
                array[i] = Integer.parseInt(st.nextToken());
            long ans = 0;
            for(int i = 0;i < 30;i++){
                int ones = 0;
                for(int j = 1;j <= n;j++){
                    if((array[j] & (1L << i)) != 0)
                        ++ones;
                }
                long afected_subsets = (pow2[ones] -1) % mod;
                ans += (pow2[i] *afected_subsets);
                ans %=mod;
            }
            System.out.println(ans);
        }
 
    }
}
