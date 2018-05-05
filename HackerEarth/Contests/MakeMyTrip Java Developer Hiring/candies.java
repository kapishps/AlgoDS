import java.io.*;
import java.util.*;

public class Solution {
    static int ispalindrome(int frq[]){
        int twoes=0,ones=0;
        for(int i=0;i<26;i++){
            if(frq[i]>=2)
                twoes+=frq[i]/2;
            ones += frq[i]%2;
        }
        if(ones > 0)
            return (twoes*2)+1;
        return twoes*2;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int frq[] = new int[26];
        for(int i=0;i<s.length();i++){
            frq[s.charAt(i)-'a']++;
        }

        int n = s.length();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());
            if(ispalindrome(frq)>=k){
                int a[] = new int[26];
                a[s.charAt(0)-'a']++;
                int i=0,j=1,ans=(int)1e6;
                while(i<j && j<=n){
                    if(ispalindrome(a)>=k){
                        ans = Integer.min(ans, j-i);
                        a[s.charAt(i)-'a']--;
                        i++;
                    }
                    else{
                        if(j<n)
                            a[s.charAt(j)-'a']++;
                        j++;
                    }
                }
                System.out.println(ans);
            }
            else
                System.out.println(-1);
        }
    }
}
