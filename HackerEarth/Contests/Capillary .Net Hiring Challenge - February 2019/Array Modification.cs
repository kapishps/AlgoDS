using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        var tmp = Console.ReadLine().Split(' ');

        int n = int.Parse(tmp[0]);
        List<long> a = new List<long>();
        long sum = 0, MOD = 1000000007, M = MOD*2000000000;
        tmp = Console.ReadLine().Split(' ');
        for (long i = 0L; i < n; i++) {
            a.Add(long.Parse(tmp[i]));
        }
        a.Sort();

        for (int i = 0; i < n; i++){
            if(a[i] < 0){
                if(i == 0)
                    sum += (((a[i]+M)%MOD)*((a[1]+M)%MOD))%MOD;
                else
                    sum += (((a[i]+M)%MOD)*((a[0]+M)%MOD))%MOD;
            }
            else{
                if(i == n-1)
                    sum += ((a[i]%MOD)*(a[n-2]%MOD))%MOD;
                else
                    sum += ((a[i]%MOD)*(a[n-1]%MOD))%MOD;
            }
            sum %= MOD;
        }
        Console.WriteLine(sum);
    }
}
