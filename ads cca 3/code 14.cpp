

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */


node * insert(node * root,int val)
{
	
  if (root == NULL) {
    node* newNode = new node();
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    newNode->ht = 0;
    return newNode;
}

if (val < root->val)
    root->left = insert(root->left, val);
else if (val > root->val)
    root->right = insert(root->right, val);
else
    return root;

// helper lambdas inside this function
auto height = [](node* n) { return (n == NULL) ? -1 : n->ht; };
auto updateHeight = [&](node* n) {
    n->ht = max(height(n->left), height(n->right)) + 1;
};
auto balanceFactor = [&](node* n) {
    return height(n->left) - height(n->right);
};

// rotations
auto rotateRight = [&](node* y) -> node* {
    node* x = y->left;
    node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
};

auto rotateLeft = [&](node* x) -> node* {
    node* y = x->right;
    node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
};

// update height and balance
updateHeight(root);
int bf = balanceFactor(root);

// Left Left
if (bf > 1 && val < root->left->val)
    return rotateRight(root);

// Right Right
if (bf < -1 && val > root->right->val)
    return rotateLeft(root);

// Left Right
if (bf > 1 && val > root->left->val) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

// Right Left
if (bf < -1 && val < root->right->val) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

return root;

}
