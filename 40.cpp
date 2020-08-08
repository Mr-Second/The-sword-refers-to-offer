/*
    https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&&tqId=11214&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(!root)
            return nullptr;
        string str = "";
        SerializeCore(root, str);
        char* res = new char[str.length() + 1];
        strcpy(res, str.c_str());
        return res;
    }

    void SerializeCore(TreeNode* root, string& str) {
        if(!root) {
            str += "$,";
            return;
        }
        str += to_string(root->val) + ',';
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);
    }


    TreeNode* Deserialize(char *str) {
        if(!str)
            return nullptr;
        string s(str);
        return DeserializeCore(s);
    }

    TreeNode* DeserializeCore(string& str) {
        if(str.empty())
            return nullptr;
        if(str.at(0) == '$') {
            str = str.substr(2);
            return nullptr;
        }

        TreeNode *res = new TreeNode(stoi(str));
        str = str.substr(str.find_first_of(',') + 1);
        res->left = DeserializeCore(str);
        res->right = DeserializeCore(str);
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    string str = s.Serialize(root);
    cout << str << endl;
    root = nullptr;
    root = s.Deserialize(const_cast<char*> (str.data()));
    return 0;
}
