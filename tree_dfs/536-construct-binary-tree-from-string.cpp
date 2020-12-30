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
class Solution {
public:
    TreeNode* str2tree(string s) {
        TreeNode* cur = NULL;
        while(pos<s.size()) {
            if(s[pos] == '(')  {
                pos++;
                if(cur->left == NULL)
                    cur->left = str2tree(s);
                else
                    cur->right = str2tree(s);                
            } else if(s[pos] == ')') {
                pos++;
                return cur;
            } else {
                int val = 0;
                bool neg = false;
                while(pos<s.size() && s[pos]!='(' && s[pos]!=')') {
                    std::cout<<pos;
                    if(s[pos] == '-')
                        neg = true;
                    else {
                        val = val*10 + (s[pos] - '0');                        
                    }
                    pos++;
                }
                val = neg? (-1*val) : val;
                cur = new TreeNode(val);
            }
        }
        return cur;        
    }
    int pos = 0;
};
