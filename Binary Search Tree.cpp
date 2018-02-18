#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;

node* CreateNode(int data)
{
	node* NewNode = (node*)malloc(sizeof(node));
	NewNode->data = data;
	NewNode->left = NewNode->right = NULL;
	return NewNode;
}

node* insert(node* root, int data)
{
	if(root == NULL)
	{
		root = CreateNode(data);
	}
	else if(data<=root->data)
	{
		root->left = insert(root->left,data);
	}
	else
	{
		root->right = insert(root->right,data);
	}
	return root;
}

void preorder(node* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int height(node* root)
{
	if(root == NULL)
	{
		return -1;
	}
	int leftHeight= height(root->left);
	int rightHeight= height(root->right);
	return max(leftHeight, rightHeight) + 1;
}

void LevelOrder(node* root)
{
	if(root == NULL)
	{
		return;
	}
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		node* current = Q.front();
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();
	}
}                              

int main()
{
	node* root = NULL;
	char create;
	cout<<"Press c to create and insert new node. \n";
	cin>>create;
	while(create == 'c')
	{
		int data;
		cout<<"Enter data to be inserted. \n";
		cin>>data;
		root = insert(root, data);
		cout<<"Press c to create and insert new node and any other key to exit. \n";
		cin>>create;
	}
	cout<<"Tree Created! \n";
	cout<<"Pre-order traversal of the tree: ";
	preorder(root);
	cout<<"\nHeight of the created tree: ";
	int h;
	h= height(root);
	cout<<h<<"\n";
	cout<<"Level-order traversal of the tree: ";
	LevelOrder(root);
	return 0;
}
