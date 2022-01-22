
Node* insert(Node* node, int data, Node*& succ)
{
	if (node == NULL)
		return node = newNode(data);
	if (data < node->data) {
		succ = node;
		node->left = insert(node->left, data, succ);
	}
	else if (data > node->data)
		node->right = insert(node->right, data, succ);
	return node;
}

void replace(int arr[], int n)
{
	Node* root = NULL;
	for (int i = n - 1; i >= 0; i--) {
		Node* succ = NULL;

		// insert current element into BST and
		// find its inorder successor
		root = insert(root, arr[i], succ);

		// replace element by its inorder
		// successor in BST
		if (succ)
			arr[i] = succ->data;
		else // No inorder successor
			arr[i] = -1;
	}
}

