/*
Input: [8, 58, 71, 18, 31, 32, 63, 92, 
         43, 3, 91, 93, 25, 80, 28]
Output: [18, 63, 80, 25, 32, 43, 80, 93, 
         80, 25, 93, -1, 28, -1, -1]
*/
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

