/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void coder_dfs(TreeNode* root, string &coded) {
        if (root == nullptr) {
            coded += "N,";
            return;
        }
        coded += (std::to_string(root->val) + ',');
        coder_dfs(root->left, coded);
        coder_dfs(root->right, coded);
    }
    
    TreeNode* decoder_dfs(vector<string> &tokens, int &i) {
        if (tokens[i].compare("N") == 0) {
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(tokens[i]));
        i++;
        
        root->left = decoder_dfs(tokens, i);
        root->right = decoder_dfs(tokens, i);
        
        return root;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string coded = "";
        coder_dfs(root, coded);
        coded.pop_back();
        //cout << coded << endl;
        return coded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string tok;
        
        vector<string> tokens;
        while (getline(ss, tok, ',')) {
            tokens.push_back(tok);
        }
        
        int i=0;
        return decoder_dfs(tokens, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
