#include <iostream>
struct NodeTree
{
	int  key;
};
namespace btree
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Node                 //���� ��������� ������ 
	{
		void Node::MixedScan(void(*f) (void* n));
		void DescScan(void(*f) (void* n));
		Node* Parent;            // ��������� �� ��������  
		Node* Left;                 // ��������� �� ����� �����
		Node* Right;               // ��������� �� ������ �����
		void* Data;                  //  ������    
		Node(Node* p, Node* l, Node* r, void* d) // �����������
		{
			Parent = p; Left = l; Right = r; Data = d;
		}
		Node* Next();              // ��������� �� �����
		Node* Prev();              // ���������� �� �����
		Node* Min();               // ������� � ���������
		Node* Max();               // �������� � ���������  
		void ScanDown(void(*f)(void* n));    // ����� ��������� ������  ����     
		void Scan(int(*f)(void* n));
		void ScanLevel(void(*f)(void* n), int);
		int GetLevel();
		void ScanByLevel(void(*f)(void* n));
		void odin(void(*f)(void* n));
	};
	struct Object               // ��������� ��������� ������ 
	{
		void DescScan(void(*fobr) (void* n));
		Node* Root;             // ��������� �� ������
		CMP(*Compare)(void*, void*);   // ������� ���������	
		Object(CMP(*f)(void*, void*))
		{
			Root = NULL;      Compare = f;
		};
		Node* Max() { return Root->Max(); };
		Node* Min() { return Root->Min(); };
		bool isLess(void* x1, void* x2)
			const {
			return Compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2)
			const {
			return Compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2)
			const {
			return Compare(x1, x2) == EQUAL;
		};


		bool Insert(void* data);                     // �������� �������
		Node* Search(void* d, Node* n);    // ����� �� �����
		Node* Search(void* d) { return Search(d, Root); };
		bool Delete(Node* e);                         // ������� �� ������ �������� 
		bool Delete(void* data)
		{
			return Delete(Search(data));
		}; //������� �� �����
		void ScanDown(void(*f)(void* n))
		{
			Root->ScanDown(f);
		};               // ����� ������   	
		btree::Object BuildTree(char *);
		void SaveToFile(void *);
		void SaveTree(btree::Object tree, char *);
		void Balance(Node *);
	};
	Object Create(CMP(*f)(void*, void*));                          // ������� �������� ������    
};
