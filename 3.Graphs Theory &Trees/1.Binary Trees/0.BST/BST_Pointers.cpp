#include <bits/stdc++.h> 

using namespace std ; 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL; 
        
        if(root->val == val) return root ;   
         
        if(val <  root->val) return searchBST(root->left , val) ; 
        else  return searchBST(root->right , val) ;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL) 
           return new TreeNode(val) ;

        else if(val < root->val)  
            root->left = insertIntoBST(root->left, val);

        else if(val > root->val) 
            root->right = insertIntoBST(root->right, val);
        
        return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL ; 
        
        if(key < root -> val ) {
            
            root -> left = deleteNode(root->left , key);
            
        }else if(key > root -> val ) {
            
            root -> right = deleteNode(root->right , key); 
            
        }else if(key == root ->val) {
            
            if(root->left == NULL && root->right == NULL) {
                 
                 delete root ;
                 return NULL;
                 
             }else if(root->left == NULL) {
                 
                 auto right = root->right ; 
                 delete root ; 
                 return right; 
                 
             }else if(root->right == NULL) {
                 
                 auto left = root->left ; 
                 delete root ; 
                 return left; 
                 
             }else {
                 
                 auto successor = root->right; 
                 while(successor->left){
                     successor = successor->left ;
                 }
                 root->val = successor->val ; 
                 root->right = deleteNode(root->right , successor->val);
                 
             }
        }
        return root;
    }


  int main(){
    return 0 ;
  }