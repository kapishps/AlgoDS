using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        var tmp = Console.ReadLine().Split(' ');
        string a = tmp[0];
        tmp = Console.ReadLine().Split(' ');
        string b = tmp[0];

        int[] m = new int[26];
        int x,y=Convert.ToInt32('a');
        for (int i = 0; i < a.Length; i++) {
            x = Convert.ToInt32(a[i]);
            m[x-y]++;
            x = Convert.ToInt32(b[i]);
            m[x-y]++;
        }

        int sum =0;
        x =0;
        for (int i = 0; i < 26; i++) {
                sum += 2*(m[i]/2);
                if(m[i]%2!=0)
                    x++;
        }

        if(x > 0)
            Console.WriteLine(sum+1);
        else
            Console.WriteLine(sum);

    }
}
