import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String position = br.readLine();

        int pos[] = new int[26];
        for(int i = 0; i < 26; i++){
            pos[position.charAt(i)-'a'] = i;
        }

        int powr[] = new int[30];
        powr[0] = 1;
        for(int i = 1; i < 30; i++){
            powr[i] = powr[i-1]*2;
            powr[i] %= 26;
        }

        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < s.length(); i++){
            ans.append(position.charAt(powr[pos[s.charAt(i)-'a']]));
        }

        System.out.println(ans.toString());
    }
}
