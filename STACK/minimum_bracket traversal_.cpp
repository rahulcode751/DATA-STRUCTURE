int count_bracket_reversal(string input){
    int size = input.size();
    if(size == 0) return 0;
    if(size%2 != 0) return -1;
    stack<char> s;
    for(int i=0; i<size; i++){
        if(input[i] == '{') s.push(input[i]);
        else if(input[i] == '}'){
            if(!s.empty() && s.top() == '{') s.pop();
            else s.push(input[i]);
        }
    }
    int count = 0;
    while(!s.empty()){
        char a = s.top();
        s.pop();
        char b = s.top();
        s.pop();
        if(a == b) count++;
        else count count + 2;
    }
    return count;
}
