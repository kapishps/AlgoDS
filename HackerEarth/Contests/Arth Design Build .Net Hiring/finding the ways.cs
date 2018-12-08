using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        var tmp = Console.ReadLine().Split(' ');
        long n = long.Parse(tmp[0]);
        long k = long.Parse(tmp[1]);

        Dictionary<long, long> pFactors = GetPrimeFactorsOfNo(n);
        long ans = 1;
        foreach (KeyValuePair<long, long> entry in pFactors){
            if(entry.Value%k != 0){
                long y = modular_pow(entry.Key, k-(entry.Value%k), 1000000007);
                ans *= y;
                ans %= 1000000007;
            }
        }
        Console.WriteLine(ans);
    }


    public static long modular_pow(long bas, long exponent, long modulus){
        long result = 1;
        while(exponent > 0){
            if (exponent%2 == 1)
               result = (result * bas)%modulus;
            exponent /= 2;
            bas = (bas * bas)%modulus;
        }
        return result%modulus;
    }


    public static Dictionary<long, long> GetPrimeFactorsOfNo(long n){
        Dictionary<long, long> primeFactorsMap = new Dictionary<long, long>();

        while (n%2 == 0) {
            if (primeFactorsMap.ContainsKey(2)){
                long temp;
                primeFactorsMap.TryGetValue(2, out temp);
                primeFactorsMap[2] = temp + 1;
            }
            else{
                primeFactorsMap.Add(2, 1);
            }
            n /= 2;
        }

        for (int i = 3; i <= Math.Sqrt(n) +1; i = i+2) {
            while (n%i == 0) {
                if (primeFactorsMap.ContainsKey(i)){
                    long temp;
                    primeFactorsMap.TryGetValue(i, out temp);
                    primeFactorsMap[i] = temp + 1;
                }
                else{
                    primeFactorsMap.Add(i, 1);
                }
                n /= i;
            }
        }

        if (n >= 2){
            if (primeFactorsMap.ContainsKey(n)){
                long temp;
                primeFactorsMap.TryGetValue(n, out temp);
                primeFactorsMap[n] = temp + 1;
            }
            else{
                primeFactorsMap.Add(n, 1);
            }
        }

        return primeFactorsMap;
    }
}
