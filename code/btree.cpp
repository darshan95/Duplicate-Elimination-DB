#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define ULL unsigned long long int


unsigned long create_hash_value(string temp_str)
{
	unsigned long hash_val = 5381;
	for(int i=0;i<temp_str.size();i++)
	{
		hash_val=((hash_val << 5) + hash_val) + temp_str[i];
	}
	return hash_val;
}

class BTreeNode
{
	ULL *keys;  
	int t;      
	BTreeNode **C; 
	int n;     
	bool leaf; 
	public:
	BTreeNode(int _t, bool _leaf);   

	void insertNonFull(ULL k);

	void splitChild(int i, BTreeNode *y);

	void traverse();

	BTreeNode *search(ULL k);   

	friend class BTree;
};

class BTree
{
	BTreeNode *root; 
	int t;  
	public:
	BTree(int _t)
	{  root = NULL;  t = _t; }

	void traverse()
	{  if (root != NULL) root->traverse(); }

	BTreeNode* search(ULL k)
	{  return (root == NULL)? NULL : root->search(k); }

	void insert(ULL k);
};

BTreeNode::BTreeNode(int t1, bool leaf1)
{
	t = t1;
	leaf = leaf1;

	keys = new ULL[2*t-1];
	C = new BTreeNode *[2*t];

	n = 0;
}

void BTreeNode::traverse()
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (leaf == false)
			C[i]->traverse();
		cout << " " << keys[i];
	}

	if (leaf == false)
		C[i]->traverse();
}

BTreeNode *BTreeNode::search(ULL k)
{
	int i = 0;
	while (i < n && k > keys[i])
		i++;

	if (keys[i] == k)
		return this;

	if (leaf == true)
		return NULL;

	return C[i]->search(k);
}

void BTree::insert(ULL k)
{
	if (root == NULL)
	{
		root = new BTreeNode(t, true);
		root->keys[0] = k;  
		root->n = 1; 
	}
	else 
	{
		if (root->n == 2*t-1)
		{
			BTreeNode *s = new BTreeNode(t, false);

			s->C[0] = root;

			s->splitChild(0, root);

			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->C[i]->insertNonFull(k);

			root = s;
		}
		else 
			root->insertNonFull(k);
	}
}

void BTreeNode::insertNonFull(ULL k)
{
	int i = n-1;

	if (leaf == true)
	{
		while (i >= 0 && keys[i] > k)
		{
			keys[i+1] = keys[i];
			i--;
		}

		keys[i+1] = k;
		n = n+1;
	}
	else 
	{
		while (i >= 0 && keys[i] > k)
			i--;

		if (C[i+1]->n == 2*t-1)
		{
			splitChild(i+1, C[i+1]);

			if (keys[i+1] < k)
				i++;
		}
		C[i+1]->insertNonFull(k);
	}
}

void BTreeNode::splitChild(int i, BTreeNode *y)
{
	BTreeNode *z = new BTreeNode(y->t, y->leaf);
	z->n = t - 1;

	for (int j = 0; j < t-1; j++)
		z->keys[j] = y->keys[j+t];

	if (y->leaf == false)
	{
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j+t];
	}

	y->n = t - 1;

	for (int j = n; j >= i+1; j--)
		C[j+1] = C[j];

	C[i+1] = z;

	for (int j = n-1; j >= i; j--)
		keys[j+1] = keys[j];
	keys[i] = y->keys[t-1];
	n = n + 1;
}


void Getnext(string filename,int number_of_attr,int number_of_blocks)
{
	ifstream inputstream(filename.c_str());
	string line;
	BTree size_tree(3);
	while(getline(inputstream,line))
	{
		unsigned long long int hash_value=create_hash_value(line);
		if(size_tree.search(hash_value) == NULL)
		{
			cout<<line<<endl;
			size_tree.insert(hash_value);
		}
	}
	inputstream.close();
	return;
}

void open(string filename,int number_of_attr,int number_of_blocks)
{
	Getnext(filename,number_of_attr,number_of_blocks);
	return;
}


void distinct(string filename,int number_of_attr,int number_of_blocks)
{
	open(filename,number_of_attr,number_of_blocks);
	return;
}


int main(int argc,char * argv[])
{
	if(argc<4)
	{
		exit(0);
	}
	else
	{
		string filename=argv[1];
		int number_of_attr=atoi(argv[2]);
		int number_of_blocks=atoi(argv[3]);
		distinct(filename,number_of_attr,number_of_blocks);
	}
	return 0;
}