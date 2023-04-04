#include <iostream>

struct Node {
	Node* left;
	Node* right;
	int data;
};

void go_tree(Node* tree) {
	if (tree != nullptr) {
		go_tree(tree->left);
		std::cout << tree->data << ' ';
		go_tree(tree->right);
	}
}
int print_sum(Node* tree, int level=0) {
	if (tree == nullptr)
		return 0;
	if (level % 2 == 0)
		return tree->data + print_sum(tree->left, level + 1) + print_sum(tree->right, level + 1);
	else
		return - tree->data + print_sum(tree->left, level + 1) + print_sum(tree->right, level + 1);
}

void tree_brackets(Node* tree) {
	if (tree == nullptr)
		return;
	std::cout << "(";
	tree_brackets(tree->left);
	std::cout << tree->data;
	tree_brackets(tree->right);
	std::cout << ")";
}

int height(Node* tree) {
	if (tree == nullptr)
		return 0;
	return std::max(height(tree->left), height(tree->right)) + 1;
}

bool is_balanced(Node* tree) {
	if (tree == nullptr)
		return true;
	int left_height = height(tree->left);
	int right_height = height(tree->right);
	if (std::abs(left_height - right_height) > 1)
		return false;
	return is_balanced(tree->left) && is_balanced(tree->right);
}

bool isAVL(Node* tree) {
	if (tree == nullptr)
		return true;
	if (is_balanced(tree) && isAVL(tree->left) && isAVL(tree->right))
		return true;
	return false;
}

Node* add(Node* tree, Node* nnode) {
	if (tree == nullptr)
		return nnode;
	if (tree->data > nnode->data)
		tree->left = add(tree->left, nnode);
	else
		tree->right = add(tree->right, nnode);
	return tree;
}

 void v_add(Node** tree, Node* nnode) {
	 if (*tree == nullptr) {
		 *tree = nnode;
		 return;
	 }
	if ((*tree)->data > nnode->data)
		return v_add(&(*tree)->left, nnode);
	else
		return v_add(&(*tree)->right, nnode);
}

 void test(Node* tree, int a, int val) {
	 if (a == 1)
		 std::cout << print_sum(tree) << std::endl;
	 if (a == 2)
		 tree_brackets(tree);
	 if (a == 3)
		 std::cout << isAVL(tree) << std::endl;
	 if (a == 4) {
		 Node* node = new Node{ nullptr, nullptr, val };
		 v_add(&tree, node);
		 go_tree(tree);
	 }
	 if (a == 5) {
		 Node* node = new Node{ nullptr, nullptr, val };
		 add(tree, node);
		 go_tree(tree);
	 }
	 if (a == 6)
		 go_tree(tree);
	 if (a == 7)
		 std::cout << height(tree) << std::endl;
	 if ( a == 8)
		 std::cout << is_balanced(tree) << std::endl;
 }

int main() {
	int root, val=0, a;
	std::cout << "Enter the root element of tree" << std::endl;
	std::cin >> root;
	if (root == 0)
		val = 1;
	Node* tree = new Node{ nullptr, nullptr, root };
	std::cout << "Enter elements you want to add to the tree until it will be value of root" << std::endl;
	while (val != root) {
		std::cin >> val;
		if (val != root) {
			Node* node = new Node{ nullptr, nullptr, val };
			v_add(&tree, node);
		}
	}
	std::cout << "Enter a number from 1 to 8 to check:\n1 - print_sum\n2 - tree_brackets\n3 - isAVL\n4 - v_add\n5 - add\n6 - go_tree\n7 - height\n8 - is_balanced" << std::endl;
	std::cin >> a;
	if (a == 4 || a == 5) {
		std::cout << "Enter value of new node" << std::endl;
		std::cin >> val;
	}
	test(tree, a, val);
	return 0;
}