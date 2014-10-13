#include <stack>
#include "node.cpp"
#include <iostream>
using namespace std;
class tree
{
	node* root;
public:
	tree()
	{
		root = NULL;
	}
	void insert(const char* s, int f)
	{
		node* newnode = new node();
		newnode->setData(s);
		newnode->setFreq(f);
		newnode->setLeft(NULL);
		newnode->setRight(NULL);
		newnode->setP(NULL);
		node* temp = root;
		node* r=NULL;
		if (temp == NULL)
		{
			root = newnode;
		}
		else
		{
			while (temp != NULL)
			{
				r = temp;
				if (temp->getFreq()>f)
					temp = temp->getLeft();
				else
					temp = temp->getRight();
			}
			if (r->getFreq()>f)
			{
				r->setLeft(newnode);
				newnode->setP(r);
			}
			else
			{
				r->setRight(newnode);
				newnode->setP(r);
			}
		}
	}

	void inorder(node *p)
	{
		if (p != NULL)
		{
			inorder(p->getLeft());
			cout << " " << p->getData();
			inorder(p->getRight());
		}
	}

	

	void preorder(node* root)
	{
		if (root)
		{
			cout << " " << root->getData();
			preorder(root->getLeft());
			preorder(root->getRight());
		}
	}

	
	void postorder(node* root)
	{
		if (root)
		{
			postorder(root->getLeft());
			postorder(root->getRight());
			cout << " " << root->getData();
		}
	}

	

	/*void print()
	{
		cout << "Inorder" << endl;
		inorder(root);
		cout << endl;
		cout << "\nPreorder" << endl;
		//preorder(root);
		preorderS(root);
		cout << "\nPostorder" << endl;
		//postorder(root);
		postorderS(root);
		cout << endl;
	}*/

	node* search(int x, const char* su, node* p)
	{
		stack<node*> s;
		node* temp = p;
		bool done = false;
		while (!done)
		{
			if (temp)
			{
				s.push(temp);
				temp = temp->getLeft();
			}
			else
			{
				if (s.empty())
					done = true;
				else
				{
					temp = s.top();
					s.pop();
					if (temp->getFreq() == x && temp->getData() == su)
						return temp;
					temp = temp->getRight();
				}
			}
		}
		return NULL;
	}

		

	node* minimum(node* y)
	{
		while (y->getLeft())
			y = y->getLeft();
		return y;
	}

	node* maximum(node* y)
	{
		while (y->getRight())
			y = y->getRight();
		return y;
	}

	node* successor(int x,const char* s)
	{
		if (search(x,s, root))
		{
			node* z = search(x, s, root);
			if (z->getRight())
				return minimum(z->getRight());
			node* y = z->getP();
			while (y->getRight() && y != NULL)
			{
				z = y;
				y = y->getP();
			}
			return y;
		}
		else
		{
			cout << "\nDoes not exist" << endl;
			return NULL;
		}
	}

	
	void del(const char* s, int x)
	{

		if (search(x, s, root))
		{

			node* z = search(x,s, root);
			if (!z->getLeft() && !z->getRight())
			{
				if (z == root)
					root = NULL;
				delete z;
			}

			else if ((z->getLeft() && !z->getRight()) || (!z->getLeft() && z->getRight()))
			{
				node* y = z->getP();

				if (z == root)
				{
					if (z->getLeft())
						root = z->getLeft();
					else
						root = z->getRight();
				}

				else if (z == y->getLeft())
				{
					if (z->getLeft())
					{
						(z->getLeft())->setP(y);
						y->setLeft(z->getLeft());
					}
					else
					{
						(z->getRight())->setP(y);
						y->setLeft(z->getRight());
					}
				}

				else
				{
					if (z->getLeft())
					{
						(z->getLeft())->setP(y);
						y->setRight(z->getLeft());
					}
					else
					{
						(z->getRight())->setP(y);
						y->setRight(z->getRight());
					}
				}

				delete z;
			}

			else
			{
				node* y = successor(x,s);

				int d = z->getFreq();
				z->setFreq(y->getFreq());
				y->setFreq(d);

				const char* k = z->getData();
				z->setData(y->getData());
				y->setData(k);

				if (z == root)
				{
					if (y == z->getRight())
					{
						if (y->getRight())
							(y->getP())->setRight(y->getRight());
					}

					else
					{
						if (y->getRight())
							(y->getP())->setLeft(y->getRight());
					}
				}

				else
				{

					if (y->getRight())
						(z->getRight())->setLeft(y->getRight());

				}
				delete y;
			}

		}

		else
			cout << "\nNode not present" << endl;
	}

};
