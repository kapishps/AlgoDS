string Solution::simplifyPath(string A) {
    deque<string> dq;
    string dirname = "";
    for(int i =0; i < A.size(); i++){
        if(A[i] == '/'){
            if(dirname.size() > 0){
                if(dirname == "."){
                    // nothing
                } else if (dirname == ".."){
                    if(!dq.empty()){
                        dq.pop_back();
                    }
                } else {
                    dq.push_back(dirname);
                }
            }
            dirname = "";
        } else {
            dirname += A[i];
        }
    }
    if(dirname.size() > 0){
        if(dirname == "."){
            // nothing
        } else if (dirname == ".."){
            if(!dq.empty()){
                dq.pop_back();
            }
        } else {
            dq.push_back(dirname);
        }
    }
    string ans = "/";
    while(!dq.empty()){
        ans += dq.front();
        ans += '/';
        dq.pop_front();
    }
    if(ans.size() > 1){
        ans.pop_back();
    }
    return ans;
}
