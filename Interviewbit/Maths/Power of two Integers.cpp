
map<int,int> primefactorisation(int A){
    map<int,int> map1;
    while(A%2 == 0){
        map1[2]++;
        A /= 2;
    }

    for (int i = 3; i*i <= A; i += 2) {
        while(A%i == 0){
            map1[i]++;
            A /= i;
        }
    }
    if(A > 2)
        map1[A]++;
    return map1;
}


int Solution::isPower(int A) {
    if(A == 1)
        return 1;
    map<int,int> map1 = primefactorisation(A);
    int g = 0;
    for(auto i: map1){
        if(g == 0)
            g = i.second;
        g = __gcd(i.second, g);
    }
    return g != 1;
}
