import java.io.*;
import java.util.*;

public class Solution {

    static boolean isPowerOfTwo(long n) {
        if (n == 0)
            return false;
        while (n != 1) {
            if (n % 2 != 0)
                return false;
            n = n / 2;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            int array[] = new int[n];
            long sum = 0;
            for (int i = 0; i < n; i++) {
                array[i] = Integer.parseInt(st.nextToken());
                if (array[i] > 0)
                    sum += array[i];
            }
            if (isPowerOfTwo(sum))
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }
}
