using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        var tmp = Console.ReadLine().Split(' ');
        int n = int.Parse(tmp[0]);

        if(n == 1)
            Console.WriteLine(1);
        else{
            int[] a = new int[n];
            tmp = Console.ReadLine().Split(' ');

            int[] cnt = new int[10];
            for (int i = 0; i < n; i++) {
                a[i] = int.Parse(tmp[i]);
                bool[] present = new bool[10];
                while(a[i] > 0){
                    present[a[i]%10] = true;
                    a[i] /= 10;
                }
                for (int j = 0; j < 10; j++)
                    if(present[j])
                        cnt[j]++;
            }

            int sum = 0;
            for (int i = 0; i < 10; i++)
                sum = Math.Max(sum, cnt[i]);
            Console.WriteLine(sum);
        }
    }
}
