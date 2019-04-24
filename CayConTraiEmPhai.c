/*
Cai dat cay tong quat dung con trai, em phai  (left most child, right sibling) 
- in ra danh sach duyet theo thu tu truoc
Cay o trong slice co nhan a,b,c,d,e,f,g,h,i,j
*/
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

struct _Tnode{
	char label;
	struct _Tnode *left_most_child;
	struct _Tnode *right_sibling;
};
typedef struct _Tnode TNode;

TNode *makeTreeNode(char ch)
{
	TNode *newNode = NULL;
	
	newNode = (TNode *)malloc(sizeof(TNode));
	if(newNode==NULL)
	{
		printf("Het bo nho \n");
		exit(1);
	}
	else
	{
		newNode->label = ch;
		newNode->left_most_child = NULL;
		newNode->right_sibling = NULL;
	}
	
	return newNode;
}
// Giai phong bo nho
void freeTree(TNode *tree)
{
     if(tree==NULL) return;
     else{
      freeTree(tree->left_most_child);
      freeTree(tree->right_sibling);
      free(tree);
      return;
     }
}
// Phep duyet truoc cay tong quat
void printPreOrder(TNode *tree)
{
	if(tree!=NULL){		
		printf(" %c ",tree->label);
		printPreOrder(tree->left_most_child);
		printPreOrder(tree->right_sibling);	    
	}
}

void printInOrder(TNode *tree)
{
	if(tree!=NULL){		
		printInOrder(tree->left_most_child);
		printf(" %c ",tree->label);
		printInOrder(tree->right_sibling);	    
	}
}

void printPostOrder(TNode *tree)
{
	if(tree!=NULL){		
		printPostOrder(tree->left_most_child);		
		printPostOrder(tree->right_sibling);
		printf(" %c ",tree->label);	    
	}
}

int depth = 0;
int height = 0;

void depthTree(TNode * tree) {
    if (tree->left_most_child != NULL) {
        depth++;
        depth > height ? height = depth : 1 ;
        depthTree(tree->left_most_child);
        depth--;
    }
    if (tree->right_sibling) {
        depthTree(tree->right_sibling);
    }
}

int maxDepth(TNode * node) {
    if (node == NULL) return 0;
    int leftChildDepth = maxDepth(node->left_most_child) + 1;
    int rightSibling = maxDepth(node->right_sibling);
    return leftChildDepth > rightSibling ? leftChildDepth : rightSibling;
}

int maxDepthTree(TNode * node) {

}

int main()
{
    TNode *root = NULL; // Con tro den nut goc
    TNode *a,*b,*c,*d,*e,*f,*g,*h,*i,*j, *k, *l;
	// Tao cac o du lieu doc lap
    a = makeTreeNode('a');
    b = makeTreeNode('b');c = makeTreeNode('c');d = makeTreeNode('d');
    e = makeTreeNode('e');f = makeTreeNode('f');g = makeTreeNode('g');
    i = makeTreeNode('i');j = makeTreeNode('j'); k=makeTreeNode('k') ; h = makeTreeNode('h');
    l = makeTreeNode('l');
    // Tao lien ket giua cac o du lieu
    root = a;
    a->left_most_child = b;
    b->right_sibling = c;
    b->left_most_child = d; c->left_most_child = f;
    d->right_sibling = e; f->right_sibling = j;
    f->left_most_child = g;
    g->right_sibling = h; h->right_sibling = i;
    h->left_most_child = k;
    k->left_most_child = l;
    // Duyet theo thu tu truoc
    printf("Duyet thu tu truoc \n");
    printPreOrder(root);
    printf("\n");
	// Duyet theo thu tu giua
    printf("Duyet thu tu giua \n");
    printInOrder(root);
    printf("\n");
	// Duyet theo thu tu sau
    printf("Duyet thu tu sau \n");
    printPostOrder(root);
    printf("\n");
    //getch();

    depthTree(root);
    printf("%d", maxDepth(root));

    return 0;
}
