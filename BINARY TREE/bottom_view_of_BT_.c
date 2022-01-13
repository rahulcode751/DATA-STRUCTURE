// qustion link  -> https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> v;
        map<int,int> m;
        queue<pair<Node*,int>> q;
        if(root == NULL) return v;
        q.push({root,0});
        while(!q.empty()){
            Node* temp = q.front().first;
            int h = q.front().second;
            q.pop();

            m[h] = temp->data;

            if(temp->left) q.push({temp->left,h-1});
            if(temp->right) q.push({temp->right,h+1});
        }

        for(auto i:m){
            v.push_back(i.second);
        }
        //Your code here
    }
