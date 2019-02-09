using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
class Solution {
    static void Main(String[] args) {
        var tmp = Console.ReadLine().Split(' ');
        long n = long.Parse(tmp[0]);

        List<Tuple<long, long>> list = new List<Tuple<long, long>>();
        for (int i = 0; i < n; i++) {
            tmp = Console.ReadLine().Split(' ');
            long a = long.Parse(tmp[0]);
            long b = long.Parse(tmp[1]);

            Debug.Assert(a <= b);

            list.Add(new Tuple<long,long>(a,b));
        }
        list.Sort(Comparer<Tuple<long, long>>.Default);

        long sum = (1000000L*(1000000+1))/2;
        long diff = 0;
        if(n > 0){
            long l = list[0].Item1, r = list[0].Item2;
            for (int i = 1; i < n; i++){

                Debug.Assert(list[i].Item1 >= l);
                Debug.Assert(list[i].Item2 <= 1000000L);

                if(list[i].Item1 <= r+1){
                    r = Math.max(list[i].Item2,r);
                }
                else{
                    diff += (((r*(r+1))/2) - ((l*(l-1))/2));
                    l = list[i].Item1;
                    r = list[i].Item2;
                }
            }
            diff += (((r*(r+1))/2) - ((l*(l-1))/2));
        }

        Debug.Assert(sum >= diff);

        Console.WriteLine(sum - diff);
    }
}
