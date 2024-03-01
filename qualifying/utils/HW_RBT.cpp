#include <iostream>
#include <vector>

using namespace std;

enum Color
{
    RED,
    BLACK
};

struct RBTNode {
    int val;
    Color color;
    RBTNode *parent;
    RBTNode *left;
    RBTNode *right;
    RBTNode() : val(0), parent(nullptr), left(nullptr), right(nullptr), color(BLACK) {}
    RBTNode(int x): val(x), parent(nullptr), left(nullptr), right(nullptr), color(BLACK){}
};

class RBT {
    public:
        RBTNode* root;
        RBTNode* NIL;

        RBT(void) {
            NIL = new RBTNode;
            NIL->color = BLACK;
            NIL->left = nullptr;
            NIL->right = nullptr;
            NIL->parent = nullptr;
            root = NIL;
        }

        RBTNode* search_recursive(RBTNode* x, int k) {
            if (x == NIL || x->val == k) {
                return x;
            }
            if (k < x->val){
                return search_recursive(x->left, k);
            } else {
                return search_recursive(x->right, k);
            }
        }

        RBTNode* search_iterative(RBTNode* x, int k) {
            while(x != NIL && x->val != k){
                if (k < x->val){
                    x = x->left;
                } else {
                    x = x->right;
                }
            }
            return x;
        }

        RBTNode* minimum(RBTNode* x) {
            while(x->left != NIL){
                x = x->left;
            }
            return x;
        }

        RBTNode* successor(RBTNode* x) {
            if(x->right != NIL) {
                return minimum(x->right);
            } else {
                RBTNode* y = x->parent;
                while(x == y->right){
                    x = y;
                    y = x->parent;
                }
                return y;
            }
        }

        void leftRotate(RBTNode* x) {
            // define y
            RBTNode* y = x->right;

            // x & y->left
            x->right = y->left;
            if (y->left != NIL) {
                y->left->parent = x;
            }

            // y & x->parent
            y->parent = x->parent;
            if(x->parent == NIL) {
                root = y;
            } else if (x == x->parent->left) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }

            // x & y
            y->left = x;
            x->parent = y;
        }

        void rightRotate(RBTNode* x) {
            // define y
            RBTNode* y = x->left;

            // x & y->right
            x->left = y->right;
            if (y->right != NIL) {
                y->right->parent = x;
            }

            // y & x->parent
            y->parent = x->parent;
            if(x->parent == NIL) {
                root = y;
            } else if (x == x->parent->right) {
                x->parent->right = y;
            } else {
                x->parent->left = y;
            }

            // x & y
            y->right = x;
            x->parent = y;
        }

        void RBInsert(int k) {
            RBTNode* newNode = new RBTNode(k);

            RBTNode* y = NIL;
            RBTNode* x = root;

            // find location
            while (x != NIL) {
                y = x;
                if (k < x->val) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }

            newNode->parent = y;
            if(y == NIL) {
                root = newNode;
            } else if (k < y->val) {
                y->left = newNode;
            } else {
                y->right = newNode;
            }

            newNode->left = NIL;
            newNode->right = NIL;
            newNode->color = RED;

            // 색깔정하기 고고씽~
            RBInsertFixUp(newNode);
        }

        void RBInsertFixUp(RBTNode* z) {
            // 새로 넣은 node의 부모가 black이면 아무 문제 없음
            // 내가 red고, bh를 변화시키지 않으니까
            // but 새로 넣은 node의 부모가 red면, red가 두번 연속 나오는 거니까 문제가 됨
            while(z->parent->color == RED) {
                // 만약 z의 부모가 left child라면
                if (z->parent == z->parent->parent->left) {
                    // y 는 삼춘
                    RBTNode* y = z->parent->parent->right;
                    // Case 1: 만약 z의 부모==left child, 부모==red, 삼춘==red면?
                    // 내가 left인지 right인지는 상관 x
                    if(y->color == RED) {
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        // z를 z의 조부모로 재설정
                        // 조부모 색을 red로 바꿔놓았는데, 이게 규칙을 어기게 되면 다시 조부모의 위치에서 RBInsertFixUp을 불러야 하기 때문
                        z = z->parent->parent;
                    // 만약 부모는 red지만, 삼춘은 black이라면?
                    } else {
                        // Case 2: 만약 부모==left child, 부모==red, 삼춘==black, 나==right child라면?
                        // Case 2를 해결하여 Case 3과 같이 만들어줌.
                        if (z == z->parent->right) {
                            z = z->parent;
                            leftRotate(z);
                        }
                        // Case 3: red parent - red left child & black uncle
                        // Case 3: 만약 부모==left child, 부모==red, 삼춘 == black, 나==left child라면?
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        rightRotate(z->parent->parent);
                    }
                // 만약 z의 부모가 right child라면 위에거 뒤집기
                } else {
                    RBTNode* y = z->parent->parent->left;
                    if(y->color == RED) {
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent;
                    } else {
                        if (z == z->parent->left) {
                            z = z->parent;
                            rightRotate(z);
                        }
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        leftRotate(z->parent->parent);
                    }
                }
            }
            root->color = BLACK;
        }

        void transplant(RBTNode* x, RBTNode* y){
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

        void RBDelete(int k) {
            RBTNode* z = search_iterative(root, k);
            if (z==NIL) return;
            // y: z를 대체할 node
            RBTNode* y;
            RBTNode* x;

            // y_original_color = z->color
            y = z;
            Color y_original_color = y->color;
            if (z->left == NIL){
                x = z->right;
                // x가 NIL이더라도 transplant안에서 x->parent = z->parent
                transplant(z, z->right);
            } else if (z->right == NIL){
                x = z->left;
                // x가 NIL이더라도 transplant안에서 x->parent = z->parent
                transplant(z, z->left);
            } else {
                // 만약 애가 둘이야
                y = minimum(z->right);
                // y_original_color = successor 색깔
                y_original_color = y->color;
                // 만약 여기서
                // x가 black이라면 NIL일수밖에 없음
                // y->left == NIL이니까 bh 맞추려면!
                // x가 red라면 x의 자식은 NIL일수밖에 없음
                x = y->right;
                if (y != z->right) {
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                } else {
                    // 만약 x가 NIL일 경우
                    // x와 y의 관계 확립을 위하여 x의 부모를 설정
                    // NIL의 parent를 설정해주어도 구현에는 아무 문제 없음!
                    x->parent = y;
                }
                transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                // 원래 있었던 노드의 색깔 따라가기
                // 만약 bh에 문제가 생긴다면
                // 원래 y가 있던 subtree쪽에 생기게!
                // 즉 x를 root로 하는 subtree에
                y->color = z->color;
            }
            // y_original_color가 왜 중요하냐!
            // 1. no child & one child
            // 삭제된 노드가 검은색이면, 즉 y_original_color = z->color = black이면 bh가 바뀜
            // 반대로 빨간색이면 그냥 자식 올리면 아무 문제 x
            // 2. two child
            // y_original_color = right subtree의 minimum->color
            // 만약 red면 z의 right subtree는 아무 문제 x
            // red인 minimum을 z위치로 올린 후 black으로 바꾸면 z를 root로 했던 subtree의 bh도 안바뀜
            // but black이면 z의 right subtree는 bh가 1 낮아짐
            if (y_original_color == BLACK) {
                // y는 z를 대체한 node
                // x는 y의 right child
                RBDeleteFixUp(x);
            }
        }

        void RBDeleteFixUp(RBTNode* x) {
            // 여기 들어왔다면 y_original_color = black

            // 자식이 없는 노드가 삭제되어서 들어왔다면 x == NIL
            // 자식이 하나만 있는 노드가 삭제되어서 들어왔다면 x == NIL or x == red without children
            // 자식이 둘이 있는 노드가 삭제되어서 들어왔다면 x == NIL or x == red without children

            // y의 subtree 중 x가 존재하는 쪽 bh가 다른 subtree보다 1 낮음
            // 만약 x가 red라면 그냥 black으로 바꿔주면 됨
            // Why? 바뀌기 전 y->left == NIL 따라서 x가 red였다면 x의 자식은 무조건 NIL
            // 지금 문제는 x가 존재하는 쪽 y의 subtree bh가 반대쪽 subtree bh에 비해 1 낮은거니까
            // x를 black으로만 바꿔주면 됨
            // => 코드 맨 밑에서 처리
            while(x != root && x->color == BLACK) {
                if (x == x->parent->left) {
                    // w: sibling
                    RBTNode* w = x->parent->right;
                    // Case 1
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->parent->color = RED;
                        leftRotate(x->parent);
                        w = x->parent->right;
                    }
                    // Case 1이 끝나면 Case 2 or Case 3에 해당
                    // Case 1은 w->color == BLACK을 보장
                    // Case 2
                    if (w->left->color == BLACK && w->right->color == BLACK) {
                        w->color = RED;
                        x = x->parent;
                    } else {
                    // Case 2가 끝나면 x->parent의 양 옆 subtree bh는 동일하지만
                    // 새로운 x의 위치(x->parent)에서의 bh가 1 부족한 상황!
                    // 그래서 새로운 x가 red면 그냥 black으로 칠해주면 되고, 아니면 go up and up and up....

                        // w의 자식이 둘 중 하나라도 RED라면
                        if (w->right->color == BLACK) {
                            // Case 3: w->left->color == RED && w->right->color == BLACK
                            // left가 red겠죠?
                            w->left->color = BLACK;
                            w->color = RED;
                            rightRotate(w);
                            w = x->parent->right;
                        }
                        // Case 3가 끝나면 guarantee w->right->color == RED
                        // Case 4
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->right->color = BLACK;
                        leftRotate(x->parent);
                        x = root;
                    }
                // 뒤집기,,,
                } else {
                    // 즉, x == x->parent->right
                    RBTNode* w = x->parent->left;
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->parent->color = RED;
                        rightRotate(x->parent);
                        w = x->parent->left;
                    }
                    if (w->right->color == BLACK && w->left->color == BLACK) {
                        w->color = RED;
                        x = x->parent;
                    } else {
                        if(w->left->color == BLACK) {
                            w->right->color = BLACK;
                            w->color = RED;
                            leftRotate(w);
                            w = x->parent->left;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->left->color = BLACK;
                        rightRotate(x->parent);
                        x = root;
                    }
                }
            }
            x->color = BLACK;
        }

        void printTree() {
            if (root) {
                printHelper(root, "", true);
            }
        }

        void printHelper(RBTNode* x, string indent, bool last) {
            if (x != NIL) {
                cout << indent;
                if (last) {
                    cout << "R----";
                    indent += "   ";
                } else {
                    cout << "L----";
                    indent += "|  ";
                }

                string sColor = x->color ? "BLACK" : "RED";
                cout << x->val << "(" << sColor << ")" << endl;
                printHelper(x->left, indent, false);
                printHelper(x->right, indent, true);
            }
        }
};

int main(void) {
    RBT rbt;
    rbt.RBInsert(55);
    rbt.RBInsert(40);
    rbt.RBInsert(65);
    rbt.RBInsert(60);
    rbt.RBInsert(75);
    rbt.RBInsert(57);

    rbt.printTree();
    cout << endl
        << "After deleting" << endl;
    rbt.RBDelete(40);
    rbt.printTree();

}
