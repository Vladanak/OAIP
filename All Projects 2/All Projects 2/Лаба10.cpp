#include "Header.h"  
#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
int polo=0;
struct  Node
{
	int height;
	int key;
	int count;
	Node *left;
	Node *right;

};
Node *Tree;
Node  *Result;     //��������� �� ��������� �������
int B;             //������� ���������� ������� � ������
typedef struct Node *nodeptr;
Node  minimum(Node **x)      // ����� ��������
{
	if ((**x).left == NULL) return **x;
	return minimum(&(**x).left);
}
Node** getTree()
{
	return &Tree;
}
void search(int x, Node **p)   //����� ����� x
{
	if (*p == NULL)               //*p - ��������� �� ������� 
	{
		*p = new(Node);
		(**p).key = x;
		(**p).count = 1;
		(**p).left = (**p).right = NULL;
	}
	else
		if (x<(**p).key)
			search(x, &((**p).left));
		else
			if (x>(**p).key)
				search(x, &((**p).right));
			else
				(**p).count += 1;
}
void buildTree()                 //���������� ��������� ������
{
	int el;
	cout << "������� ����� ������ ������: \n";
	cin >> el;
	while (el != 0)
	{
		search(el, &Tree);
		cin >> el;
	}
}
void printTree(Node **w, int l)    //����� �� �����
{
	int i;
	if (*w != NULL)            //*w - ��������� �� ������ 
	{
		printTree(&((**w).right), l + 1);
		for (i = 1; i <= l; i++)
			cout << "   ";
		cout << (**w).key << endl;
		printTree(&((**w).left), l + 1);
	}
}
int findNode(int k)                 //����� ������� � ������ k 
{
	Node *p, *q = nullptr;
	B = FALSE;
	p = Tree;
	if (Tree != NULL)
		do
		{
			q = p;
			if ((*p).key == k)
				B = TRUE;
			else
			{
				q = p;
				if (k < (*p).key)
					p = (*p).left;
				else
					p = (*p).right;
			}
		} while (!B  &&  p != NULL);
		Result = q;
		return B;
}
void addNode(int k)                //���������� ����� k 
{
	Node *s;
	findNode(k);
	if (!B)
	{
		s = new(Node);
		(*s).key = k;
		(*s).count = 1;
		(*s).left = (*s).right = NULL;
		if (Tree == NULL)
			Tree = s;
		else
			if (k<(*Result).key)
				(*Result).left = s;
			else
				(*Result).right = s;
	}
	else
		(*Result).count += 1;
}
Node *findByKey(int k, Node **p)   //����� ������� � ������ k 
{
	if (*p == NULL)
		return (NULL);
	else
		if ((**p).key == k)
			return (*p);
		else
			if (k < (**p).key)
				return findByKey(k, &((**p).left));
			else
				return findByKey(k, &((**p).right));
}
void Delete_1(Node **r, Node **q)
{
	Node *s;
	if ((**r).right == NULL)
	{
		(**q).key = (**r).key;
		(**q).count = (**r).count;
		*q = *r;
		s = *r;
		*r = (**r).left;
		delete s;
	}
	else
		Delete_1(&((**r).right), q);
}
void Delete(Node **p, int k)      //�������� ������� k 
{
	Node *q;
	if (*p == NULL)
		cout << "������� � �������� ������ �� �������!\n";
	else
		if (k<(**p).key)
			Delete(&((**p).left), k);
		else
			if (k>(**p).key)
				Delete(&((**p).right), k);
			else
			{
				q = *p;
				if ((*q).right == NULL)
				{
					*p = (*q).left;
					delete q;
				}
				else
					if ((*q).left == NULL)
					{
						*p = (*q).right;
						delete q;
					}
					else    // ����� �������� ��� ������ ����� ������� k
					{
						(**p).key = minimum(&((**p).right)).key;
						Delete(&((*q).right), (**p).key);
					}
			}
}
void in_level(nodeptr &p)
{
	int h = 1 << (p->height + 1);
	nodeptr *mas = new nodeptr[h], q;
	int i = 0, k = 1;
	mas[0] = p;
	while (k - i > 0)
	{
		q = mas[i];
		cout << q->key << " ";
		i++;
		if (q->left)
		{
			mas[k] = q->left;
			k++;
		}
		if (q->right)
		{
			mas[k] = q->right;
			k++;
		}
		if ((q->left == NULL) && (q->right == NULL)&&(polo==i)) 
		{
			break;
		}
		if ((mas[i] && mas[i - 1]->key > mas[i]->key) || mas[i - 1]->right == mas[i])
			cout << "\n";
	}
	cout << endl;
}
void main13()
{
	setlocale(LC_CTYPE, "Russian");
	int el, dd;
	do
	{
		cout << "_______________________________________________________________" << endl;
		cout << "1. ���� ������ ������" << endl;
		cout << "2. ����� ������ �� �����" << endl;
		cout << "3. �������� ������� k" << endl;
		cout << "4. ����� ���� ��������� ������ �� �������" << endl;
		cout << "5. �����" << endl;
		cout << "�������: ";
		cin >> el;
		cout << "_______________________________________________________________" << endl;
		switch (el)
		{
		case 1:
		{
			cout << "������� ���� ����������� �������:" << endl;
			cin >> dd;
			addNode(dd);
			polo++;
			break;
		}
		case 2:
		{
			cout << "������:" << endl;
			printTree(getTree(), 0);
			break;
		}
		case 3:
		{
			int k;
			cout << "������� ����� �������" << endl;
			cin >> k;
			Delete(getTree(), k);
			break;
		}
		case 4:
		{
			in_level(Tree);
			break;
		}
		case 5:
		{
			break;
		}
		}
	} while (el != 5);
}