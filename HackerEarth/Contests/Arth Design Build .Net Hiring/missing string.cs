using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    public static int[] BuildKMPTable(string pattern){
        var kmpTable = new int[pattern.Length];

        if (kmpTable.Length < 2){
            if (kmpTable.Length > 0)
                kmpTable[0] = -1;

            return kmpTable;
        }

        int tableIndex = 2; // current position in table for computation
        int patSubstrIndex = 0; // index in the pattern of the current substring

        kmpTable[0] = -1;

        while (tableIndex < kmpTable.Length){
            if (pattern[tableIndex - 1] == pattern[patSubstrIndex]){
                kmpTable[tableIndex++] = ++patSubstrIndex;
            }
            else if (patSubstrIndex != 0){
                patSubstrIndex = kmpTable[patSubstrIndex];
            }
            else{
                kmpTable[tableIndex++] = 0;
            }
        }

        return kmpTable;
    }


    public static int KnuthMorrisPrattSearchFirst(string target, string pattern){
        if (target == null) throw new ArgumentNullException(nameof(target));
        if (pattern == null) throw new ArgumentNullException(nameof(pattern));

        var kmpTable = BuildKMPTable(pattern);

        int matchIndex = 0; // position of the current match
        int patternIndex = 0; // position in the pattern

        int targetLength = target.Length;
        int patternLength = pattern.Length;

        while (matchIndex + patternIndex < targetLength){
            if (pattern[patternIndex] == target[matchIndex + patternIndex]){
                patternIndex++;
                if (patternIndex == patternLength)
                    return matchIndex;
            }
            else{
                if (kmpTable[patternIndex] > -1){
                    matchIndex = matchIndex + patternIndex - kmpTable[patternIndex];
                    patternIndex = kmpTable[patternIndex];
                }
                else{
                    matchIndex++;
                    patternIndex = 0;
                }
            }
        }

        return -1;
    }

    public static string CharCombine(char c0, char c1, char c2, char c3){
        char[] nodes = new char[4];
        nodes[0] = c0;
        nodes[1] = c1;
        nodes[2] = c2;
        nodes[3] = c3;
        return new string(nodes).Trim();
    }


    static void Main(String[] args) {
        var tmp = Console.ReadLine().Split(' ');
        string s = tmp[0];
        string x = "abcdefghijklmnopqrstuvwxyz";

        // for(int i=0; i< 26; i++){
        //     string y = CharCombine(x[i], ' ', ' ', ' ');
        //     if(KnuthMorrisPrattSearchFirst(s,y) == -1){
        //         Console.WriteLine(y);
        //         return ;
        //     }
        // }

        for(int i=0; i< 26; i++){
            for(int j=0; j<26;j++){
                string y = CharCombine(x[i], x[j], ' ', ' ');
                if(KnuthMorrisPrattSearchFirst(s,y) == -1){
                    Console.WriteLine(y);
                    return ;
                }
            }
        }

        for(int i=0; i< 26; i++){
            for(int j=0; j<26;j++){
                for(int k=0;k<26;k++){
                    string y = CharCombine(x[i], x[j], x[k], ' ');
                    if(KnuthMorrisPrattSearchFirst(s,y) == -1){
                        Console.WriteLine(y);
                        return ;
                    }
                }
            }
        }

        for(int i=0; i< 6; i++){
            for(int j=0; j<26;j++){
                for(int k=0;k<26;k++){
                    for(int l=0;l<26;l++){
                        string y = CharCombine(x[i], x[j], x[k], x[l]);
                        if(KnuthMorrisPrattSearchFirst(s,y) == -1){
                            Console.WriteLine(y);
                            return ;
                        }
                    }
                }
            }
        }

    }
}