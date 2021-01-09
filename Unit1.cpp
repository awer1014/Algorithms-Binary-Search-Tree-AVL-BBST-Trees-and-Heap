//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct BSTreeNode {
	struct BSTreeNode *leftchild;
	char data;
  struct BSTreeNode *rightchild;
};
struct BSTreeNode *root, *findnode = NULL;

String Lines;
int count_node;
String tree;
int* X;
int* Y;

int tempcount;

struct BSTreeNode *newNode (int x){
	struct BSTreeNode *node = new struct BSTreeNode;
	node->data = x;
	node->rightchild = NULL;
	node->leftchild = NULL;
	return node;
}

struct StackNode {
	struct BSTreeNode *treenode;
	struct StackNode *next;
};
struct StackNode *top;

struct DrawTreeNode {
	struct DrawTreeNode *leftchild;
	int data;
	int index;
	struct DrawTreeNode *rightchild;
};
struct DrawTreeNode *DrawRoot;

struct QNode {
	struct BSTreeNode *treenode;
	struct QNode *next;
};
struct QNode *front, *rear;

void push_node(struct BSTreeNode *node) {
	struct StackNode *old_top;
	old_top = top;
	top = new struct StackNode;
	top->treenode = node;
	top->next = old_top;
}

struct BSTreeNode *pop_node() {
	struct BSTreeNode *Tnode;
	struct StackNode *old_top;
	if (top == NULL) {
		Form1->Memo1->Lines->Add("Stack Empty");
	}
	else {
		Tnode = top->treenode;
		old_top = top;
		top = top->next;
		free(old_top);
		return Tnode;
	}
}

void print_inorder(struct BSTreeNode *node) {
	if (node != NULL) {
		print_inorder(node->leftchild);
		Lines += IntToStr(node->data)+"_";
		print_inorder(node->rightchild);
	}
}

void print_postorder(struct BSTreeNode *node) {
	if (node != NULL) {
		print_postorder(node->leftchild);
		print_postorder(node->rightchild);
		Lines += IntToStr(node->data)+"_";
	}
}

void print_preorder(struct BSTreeNode *node) {
	if (node != NULL) {
		Lines += IntToStr(node->data)+"_";
		print_postorder(node->leftchild);
		print_postorder(node->rightchild);
	}
}

void Inorder_Stack(struct BSTreeNode *node) {
	do {
		while (node != NULL) {
			push_node(node);
			node = node->leftchild;
		}
		if (top != NULL) {
			node = pop_node();
			tree +=IntToStr(node->data) + "_";
			node = node->rightchild;
		}
	} while((top != NULL)||(node != NULL));
}

void Postorder_Stack(struct BSTreeNode *node) {
	do {
		while (node != NULL) {
			tree = IntToStr(node->data) + "_" + tree;
			push_node(node);
			node = node->rightchild;
		}
		if (top != NULL) {
			node = pop_node();
			node = node->leftchild;
		}
	}while ((top != NULL)||(node != NULL));
}

void Preorder_Stack(struct BSTreeNode*node) {
	do {
		while (node != NULL) {
			tree += IntToStr(node->data) + "_";
			push_node(node);
			node = node->leftchild;
		}
		if (top != NULL) {
			node = pop_node();
			node = node->rightchild;
		}
	} while((top != NULL)||(node != NULL));
}

void AddQueue(struct BSTreeNode *Tnode) {
	struct QNode *node;
	node = (struct QNode *) malloc (sizeof (struct QNode));
	node->treenode = Tnode;
	node->next =NULL;
	if (front == NULL) {
		front = node;
	}
	else {
		rear->next = node;
	}
	rear = node;
}

struct BSTreeNode *DeleteQueue() {
	struct BSTreeNode *Tnode;
	struct QNode *old_front;
	if (rear == NULL) {
		Form1->Memo1->Lines->Add("Queue Empty");
	}
	else {
		Tnode = front->treenode;
		old_front = front;
		front = front->next;
		free(old_front);
		return Tnode;
	}
}

void LevelOrder(struct BSTreeNode *node)
{
 AddQueue(node);
 while (front != NULL){
  node = DeleteQueue();
	if(Form1->CheckBox1->Checked) {
	  Lines += (node->data) ;
		Lines += '_';
	}
	else {
		Lines += IntToStr(node->data);
		Lines += '_';
	}
  if (node->leftchild != NULL) {
   AddQueue(node->leftchild);
  }
  if (node->rightchild != NULL) {
   AddQueue(node->rightchild);
  }
 }
}

struct BSTreeNode *BSTreeNode_InfixPrefix(AnsiString prefix, AnsiString infix ) {
	int k;
	struct BSTreeNode *node;
	if (infix.Length() == 0) {
		return NULL;
	}
	node = new BSTreeNode;
	node->data = (int) prefix[1];
	k = AnsiPos(prefix[1],infix);
	Form1->Memo1->Lines->Add("Left: " + prefix.SubString(2,k-1) + " VS. " + infix.SubString(1,k-1));
	node->leftchild = BSTreeNode_InfixPrefix(prefix.SubString(2,k-1),infix.SubString(1,k-1));
	Form1->Memo1->Lines->Add("Right: " + prefix.SubString(k+1,prefix.Length()-k)+ " VS. " + infix.SubString(k+1,infix.Length()-k));
	node->rightchild= BSTreeNode_InfixPrefix(prefix.SubString(k+1, prefix.Length()-k+1),infix.SubString(k+1, infix.Length()-k+1));
	return node;
}

struct BSTreeNode * BSTreeNode_InfixPostfix(AnsiString postfix, AnsiString infix) {
	int k;
	struct BSTreeNode * node;
	if (infix.Length() == 0) {
		return NULL;
	}
	k = AnsiPos(postfix[postfix.Length()], infix);
	node = new struct BSTreeNode;
	node->data = (int)postfix[postfix.Length()];
	Form1->Memo1->Lines->Add("Left: " + postfix.SubString(1,k-1) + " VS. " + infix.SubString(1,k-1) );
	node->leftchild = BSTreeNode_InfixPostfix(postfix.SubString(1,k-1), infix.SubString(1,k-1) );
	Form1->Memo1->Lines->Add("Right: " + postfix.SubString(k,postfix.Length()-k) + " VS. " + infix.SubString(k+1 ,infix.Length()-k) );
	node->rightchild = BSTreeNode_InfixPostfix(postfix.SubString(k,postfix.Length()-k),infix.SubString(k+1 ,infix.Length()-k) );
	return node;
}

struct BSTreeNode * InsertBST(struct BSTreeNode *node, int x) {
	if (node == NULL) {
		return newNode(x);
	}
	if (x < node->data) {
		node->leftchild = InsertBST(node->leftchild, x);
	}
	else {
		node->rightchild = InsertBST(node->rightchild, x);
	}
	return node;
}

int InsertBST_iterative(int x) {
	struct BSTreeNode *p, *q;
	p = root;
	q = NULL;
	while (p != NULL) {
		q = p;
		if (x < p->data) {
			p = p->leftchild;
		}
		else {
			p = p->rightchild;
		}
	}

	p = new struct BSTreeNode;
	p->data = x;
	p->leftchild = p->rightchild = NULL;
	if (root == NULL) {
		root = p;
		count_node++;
	}
	else if (x < q->data) {
		q->leftchild = p;
		count_node++;
	}
	else {
		q->rightchild = p;
		count_node++;
	}
	return 1;
}

struct BSTreeNode *SearchBST(struct BSTreeNode *node, int x) {
	if (node == NULL) {
		return NULL;
	}
	if (x == node->data) {
		return node;
	}
	if (x < node->data) {
		return SearchBST(node->leftchild, x);
	}
	else {
		return SearchBST(node->rightchild, x);
	}
}

struct BSTreeNode *SearchBST_iterative(struct BSTreeNode *node, int x) {
	while (node != NULL) {
		if (x == node->data) {
			return node;
		}
		if (x < node->data) {
			node = node->leftchild;
		}
		else {
			node = node->rightchild;
		}
	}
	return NULL;
}

void Clear(struct BSTreeNode *node) {
	if (node != NULL) {
		Clear(node->leftchild);
		Clear(node->rightchild);
		delete(node);
	}
}

struct BSTreeNode *InoderSucc (struct BSTreeNode *node) {
	struct BSTreeNode *p;
	for (p = node; p->leftchild != NULL; p = p->leftchild)	{
		return p;
	}
}

struct BSTreeNode *DeleteBSTree (struct BSTreeNode *node, int x) {
	struct BSTreeNode *Temp;
	if (node == NULL) {
		return node;
	}
	if (x < node->data) {
		node->leftchild = DeleteBSTree(node->leftchild, x);
	}
	else if (x > node->data) {
		node->rightchild = DeleteBSTree(node->rightchild, x);
	}
	else {
		if ((node->leftchild == NULL)||(node->rightchild == NULL)) {
			Temp = (node->leftchild) ? node->leftchild : node->rightchild;
			if (Temp == NULL) {
				Temp = node;
				node = NULL;
			}
			else {
				*node = *Temp;
			}
			free (Temp);
		}
		else {
			Temp = InoderSucc(node->rightchild);
			node->data = Temp->data;
			node->rightchild = DeleteBSTree(node->rightchild,Temp->data);
		}
	}
	return node;
}

int DeleteBSTree_iterative (int x) {
	struct BSTreeNode *p, *father, *k, *f;
	p = root;
	father = NULL;
	while (p != NULL) {
		if (x == p->data) {
			if ((p->leftchild == NULL) && (p->rightchild == NULL)) {
				k = NULL;
			}
			else if (p->leftchild != NULL) {
				f = p;
				k = p->leftchild;
				while (k->rightchild != NULL) {
					f = k;
					k = k->rightchild;
				}
				if (p == f) {
					f->leftchild = k->leftchild;
				}
				else {
					f->rightchild = k->leftchild;
				}
			}
			else{
				f = p;
				k = p->rightchild;
				while (k->leftchild != NULL) {
					f = k ;
					k = k->leftchild;
				}
				if (p == f){
					f->rightchild = k ->rightchild;
				}
				else {
					f -> leftchild = k->rightchild;
				}
			}
			if (k != NULL) {
				k->leftchild = p->leftchild;
				k->rightchild = p->rightchild;
			}
			if (father == NULL) {
				root = k;
			}
			else if (x < father->data) {
				father->leftchild = k;
			}
			else {
				father->rightchild = k;
			}
			free(p);
			return 1;
		}
		else {
			father = p;
			if (x < p->data) {
				p = p->leftchild;
			}
			else {
				p = p->rightchild;
			}
		}
	}
	return 0;
}

void Draw_BST(struct DrawTreeNode *DrawRoot, int node_radius) {
	/* code */
}

	//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int data = Edit1->Text.ToInt();
	root = InsertBST(root, data);
	Lines = "";
	print_inorder(root);
	Form1->Memo1->Lines->Add("Target added(Recursive)" + Lines);
	Edit1->Text = IntToStr(data += 10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int data = Edit1->Text.ToInt();
	InsertBST_iterative(data);
	Lines = "";
	print_inorder(root);
	Form1->Memo1->Lines->Add("Target added(Non-Recursive)" + Lines);
	Edit1->Text = IntToStr(data += 10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int target = Edit2->Text.ToInt();
	Lines="";
	if (root != NULL) {
		findnode = SearchBST(root,target);
	}
	else {
		findnode = NULL;
	}
	if (findnode == NULL) {
		Form1->Memo1->Lines->Add("Target not found(Recursive)" + IntToStr(target));
		root = InsertBST(root, target);
		print_inorder(root);
		Form1->Memo1->Lines->Add("Target added(Recursive)" + Lines);
	}
	else{
		Form1->Memo1->Lines->Add("Target found(Recursive)" + IntToStr(target));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int target = Edit2->Text.ToInt();
	Lines="";
	if (root != NULL) {
		findnode = SearchBST(root,target);
	}
	else {
		findnode = NULL;
	}
	if (findnode == NULL) {
		Form1->Memo1->Lines->Add("Target not found(Non-Recursive)" + IntToStr(target));
		InsertBST_iterative(target);
		print_inorder(root);
		Form1->Memo1->Lines->Add("Target added(Non-Recursive)" + Lines);
	}
	else{
		Form1->Memo1->Lines->Add("Target found(Non-Recursive)" + IntToStr(target));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int num = Edit3->Text.ToInt();
	srand(time(NULL));
	int max = Edit4->Text.ToInt();
	int min = Edit5->Text.ToInt();
	if (max < min) {
		int temp;
		temp = min;
		min = max;
		max = temp;
	}
	int data;
	for (int i = 0; i < num; i++) {
		data = rand()%(max-min)+min+1;
		root = InsertBST(root, data);
	}
	Lines = "";
	print_inorder(root);
	Form1->Memo1->Lines->Add("Random: "+ Lines);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Lines = "";
	print_inorder(root);
	Form1->Memo1->Lines->Add("Inoder: "+ Lines);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Lines = "";
	print_postorder(root);
	Form1->Memo1->Lines->Add("Postorder: "+ Lines);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Lines = "";
	print_preorder(root);
	Form1->Memo1->Lines->Add("Preorder: "+ Lines);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Memo1->Text="";
	Clear(root);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	Edit3->Text = TrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
	Edit4->Text = TrackBar2->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar3Change(TObject *Sender)
{
	Edit5->Text = TrackBar3->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
	tree = "";
	Inorder_Stack(root);
	Form1->Memo1->Lines->Add("Inorder(Non-Recursive): "+tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	tree = "";
	Postorder_Stack(root);
	Form1->Memo1->Lines->Add("Postorder(Non-Recursive): "+tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	tree = "";
	Preorder_Stack(root);
	Form1->Memo1->Lines->Add("Preorder(Non-Recursive): "+tree);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
	Lines = "";
	int target = Edit6->Text.ToInt();
	findnode = SearchBST(root, target);
	if (findnode != NULL) {
		DeleteBSTree(root, target);
		Form1->Memo1->Lines->Add(IntToStr(target) + "Target have been deleted(Recursive)");
		count_node --;
	}
	else {
		Form1->Memo1->Lines->Add(IntToStr(target)+" Target not found(Recursive)");
	}
	Lines = "";
	print_inorder(root);
	Form1->Memo1->Lines->Add(Lines);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	int target = Edit6->Text.ToInt();
	int success = DeleteBSTree_iterative(target);
	if (success) {
		Form1->Memo1->Lines->Add(IntToStr(target) + "Target have been deleted(Non-Recursive)");
	}
	else {
		Form1->Memo1->Lines->Add(IntToStr(target)+" Target not found(Non-Recursive)");
	}
	Lines = "";
	print_inorder(root);
	Form1->Memo1->Lines->Add(Lines);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
	AnsiString infix = Edit7->Text;
	AnsiString prefix = Edit8->Text;
	Form1->Memo1->Lines->Add("Infix: " + infix);
	Form1->Memo1->Lines->Add("Prefix: " + prefix);
	root = BSTreeNode_InfixPrefix(prefix,infix);
	Form1->Memo1->Lines->Add("------------------------------------");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
	AnsiString infix = Edit7->Text;
	AnsiString postfix = Edit9->Text;
	Form1->Memo1->Lines->Add("Infix: " + infix);
	Form1->Memo1->Lines->Add("Postfix: " + postfix);
	root = BSTreeNode_InfixPostfix(postfix,infix);
	Form1->Memo1->Lines->Add("------------------------------------");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
  Lines = "";
  LevelOrder(root);
	Form1->Memo1->Lines->Add(Lines);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	Lines = "";
	LevelOrder(root);
	Form1->Memo1->Lines->Add(Lines);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button19Click(TObject *Sender)
{
	Memo1->Text="";
	Clear(root);
}
//---------------------------------------------------------------------------

