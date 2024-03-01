#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), parent(nullptr), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), parent(nullptr), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class BST {
    public:
        TreeNode* root;
        BST(void) {
            root = nullptr;
        }

        TreeNode* search_recursive(TreeNode* x, int k){
            if(x == nullptr || x->val == k) {
                return x;
            }
            if (k < x->val){
                return search_recursive(x->left, k);
            } else {
                return search_recursive(x->right, k);
            }
        }

        TreeNode* search_iterative(TreeNode* x, int k){
            while(x != nullptr && x->val != k){
                if (k < x->val){
                    x = x->left;
                } else {
                    x = x->right;
                }
            }
            return x;
        }

        TreeNode* minimum(TreeNode* x){
            while(x->left != nullptr){
                x = x->left;
            }
            return x;
        }

        int successor_key(int key) {
            TreeNode* x = search_iterative(root, key);
            TreeNode* s = successor(x);
            return s->val;
        }

        TreeNode* successor(TreeNode* x) {
            if(x->right != nullptr) {
                return minimum(x->right);
            } else {
                TreeNode* y = x->parent;
                while(x == y->right &&  y != nullptr){
                    x = y;
                    y = x->parent;
                }
                return y;
            }
        }

        void insert(int k) {
            // 여기서 new로 동적할당을 해주지 않으면
            // ex. TreeNode newNode = TreeNode(k);
            // insert함수 끝나고 나서 노드가 사라짐!!!
            TreeNode* newNode = new TreeNode(k);
            TreeNode* x = root;
            TreeNode* y = nullptr;

            while(x != nullptr){
                y = x;
                if (k < x->val){
                    x = x->left;
                } else {
                    x = x->right;
                }
            }
            newNode->parent = y;
            if (y == nullptr) {
                root = newNode;
            } else if (k < y->val){
                y->left = newNode;
            } else {
                y->right = newNode;
            }
        }

        void transplant(TreeNode* x, TreeNode* y){
            // y의 부모를 x의 부모로 치환
            // x는 없어짐

            if (x->parent == nullptr){
                root = y;
            } else if (x == x->parent->left){
                x->parent->left = y;
            } else{
                x->parent->right = y;
            }
            if (y != nullptr)
            y->parent = x->parent;
        }

        void deleteNode(int k){
            // z는 삭제될 노드
            TreeNode* z = search_iterative(root, k);
            if (z==nullptr) return;
            if (z->left == nullptr){
                transplant(z, z->right);
            } else if (z->right == nullptr) {
                transplant(z, z->left);
            } else {
                // 양쪽 자식이 둘 다 있을 경우
                // 내 자리에 successor를 박아야 함.
                // y는 successor니까 left child가 없음
                TreeNode* y = successor(z);
                if (y != z->right) {
                    // 만약 successor가 내 바로 오른 자식이 아니면
                    // 바로 오른 자식으로 만들어버리기
                    // z의 오른 sub tree의 root가 왼 자식이 없게 만드는 과정

                    // successor 자리에 successor의 오른 자식 올리고
                    transplant(y, y->right);

                    // successor와 z의 오른자식간의 관계를 재정립
                    y->right = z->right;
                    y->right->parent = y;
                }
                // 부모 변경
                transplant(z, y);
                // 자식 변경
                y->left = z->left;
                z->left->parent = y;
            }
        }

        vector<int> inorder_T(){
            vector<int> res;
            inorder_helper(root, res);
            return res;
        }

        void inorder_helper(TreeNode* x, vector<int>& res){
            if(x != nullptr) {
                inorder_helper(x->left, res);
                res.push_back(x->val);
                inorder_helper(x->right, res);
            }
        }

        vector<int> preorder_T(){
            vector<int> res;
            preorder_helper(root, res);
            return res;
        }

        void preorder_helper(TreeNode* x, vector<int>& res){
            if(x!=nullptr) {
                cout<<x->val<< " ";
                preorder_helper(x->left, res);
                preorder_helper(x->right, res);
            }
        }
};


int main(void) {
    BST T;
    vector<int> path;
    T.insert(9);
    T.insert(4);
    T.insert(2);
    T.insert(5);
    T.insert(17);
    T.insert(13);
    T.insert(16);
    T.insert(23);
    T.insert(20);
    T.insert(34);
    T.insert(40);
    T.deleteNode(9);
    cout << T.root->val<<endl;
    // path = T.preorder_T();
    // for (int n: path) {
    //     cout << n << ' ';
    // }
    // cout << endl;

    // cout << T.successor_key(3) << endl;

    return 0;
}