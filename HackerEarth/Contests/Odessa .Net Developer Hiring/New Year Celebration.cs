using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        var tmp = Console.ReadLine().Split(' ');
        int t = int.Parse(tmp[0]);
        while(t-->0){
            tmp = Console.ReadLine().Split(' ');
            long n = long.Parse(tmp[0]);
            long x = long.Parse(tmp[1]);
            List<long> a = new List<long>();

            for (int i = 0; i < n; i++) {
                a.Add(x);
                x/=2;
            }
            a.Reverse();

            bool flag = true;
            for (int i = 1; i < n; i++) {
                if(a[i] != 2*a[i-1]){
                    flag = false;
                    break;
                }
            }

            if(flag && a.Count > 1){
                Console.WriteLine(String.Join(" ", a));
            }
            else
                Console.WriteLine("No gifts this time");
        }
    }
}
