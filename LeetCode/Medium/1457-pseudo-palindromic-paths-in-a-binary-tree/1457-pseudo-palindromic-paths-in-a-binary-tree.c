// Check if the path can form a palindrome
bool canBePalindrome(int *counter) {
    int oddCount = 0;
    for (int i = 0; i < 10; ++i) {
        if (counter[i] % 2 != 0) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}

// Depth-first search to count pseudo-palindromic paths
int dfs(struct TreeNode* node, int *counter) {
    if (!node) return 0;
    
    // Update the frequency counter for the current node's value
    counter[node->val]++;
    
    int result = 0;
    // Check if it's a leaf node
    if (!node->left && !node->right) {
        // Check if the path is pseudo-palindromic
        result = canBePalindrome(counter) ? 1 : 0;
    } else {
        // Continue DFS on left and right children
        result = dfs(node->left, counter) + dfs(node->right, counter);
    }
    
    // Backtrack - undo the frequency counter update
    counter[node->val]--;
    
    return result;
}

// Main function to be called with the root of the tree
int pseudoPalindromicPaths(struct TreeNode* root) {
    int counter[10] = {0}; // Assuming values are digits 0-9
    return dfs(root, counter);
}