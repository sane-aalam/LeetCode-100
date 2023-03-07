vector<int> reverseLevelOrder(Node *root){
    
    vector<int> result;  
    
    if(root == nullptr) 
            return result;

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node *temp = q.front();
            q.pop();
            result.push_back(temp->data);
             if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }
    }
    
    reverse(result.begin(),result.end());
    
    return  result;
}
