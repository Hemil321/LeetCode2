/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) {
        this -> root = root;
        q.push(root);
        while(true){
            int size = q.size();
            bool end = false;
            while(size--){
                TreeNode* curr = q.front();
                if(!curr -> left){
                    end = true;
                    break;
                }else{
                    q.push(curr -> left);
                }
                if(!curr -> right){
                    end = true;
                    break;
                }else{
                    q.push(curr -> right);
                    q.pop();
                }
            }
            if(end) break;
        }
    }
    
    int insert(int val) {
        TreeNode* curr = q.front();
        int ans = curr -> val;
        TreeNode* newNode = new TreeNode(val);
        if(!curr -> left) 
            curr -> left = newNode;
        else if(!curr -> right) {
            curr -> right = newNode;
            q.pop();
        }
        q.push(newNode);
        return ans;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */