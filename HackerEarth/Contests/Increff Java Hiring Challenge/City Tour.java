import java.io.*;
import java.util.*;


public class Solution {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int a[] = new int[n];
        long sum =0,ans = -10000001;
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
            sum += a[i];
            ans = Math.max(ans, a[i]);
        }

        ans = Math.max(ans, sum);
        for(int i = 2; i <= n/2; i++){
            if(n%i == 0){
                for(int j = 0; j<i;j++){
                    long t=0;
                    for(int k = j; k<n;k+=i){
                        t += a[k];
                    }
                    ans = Math.max(ans, t);
                }
            }
        }
        System.out.println(ans);

    }
}

