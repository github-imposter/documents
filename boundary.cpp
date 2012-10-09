#include< iostream >
#include< stdio.h >
using namespace std;

struct node
{
int key_value;
node *left;
node *right;
}*p;

class btree
{
public:
btree();
~btree();

void insert(int key);
node *search(int key);
void destroy_tree();
void cirn(struct node * ref,struct node * root,int left,int right);

// private:
void destroy_tree(node *leaf);
void insert(int key, node *leaf);
node *search(int key, node *leaf);

void inorder(node* p)
{
if(p==NULL)
{
return ;
}
inorder(p->left);
cout<key_value< inorder((p->right));
}


node *root;
};

btree::btree()
{
root=NULL;
}

btree::~btree()
{
destroy_tree();
}

void btree::destroy_tree(node *leaf)
{
if(leaf!=NULL)
{
destroy_tree(leaf->left);
destroy_tree(leaf->right);
delete leaf;
}
}

void btree::insert(int key, node *leaf)
{
if(key< leaf->key_value)
{
if(leaf->left!=NULL)
insert(key, leaf->left);
else
{
leaf->left=new node;
leaf->left->key_value=key;
leaf->left->left=NULL; //Sets the left child of the child node to null
leaf->left->right=NULL; //Sets the right child of the child node to null
}
}
else if(key>=leaf->key_value)
{
if(leaf->right!=NULL)
insert(key, leaf->right);
else
{
leaf->right=new node;
leaf->right->key_value=key;
leaf->right->left=NULL; //Sets the left child of the child node to null
leaf->right->right=NULL; //Sets the right child of the child node to null
}
}
}


void btree::insert(int key)
{
if(root!=NULL)
insert(key, root);
else
{
root=new node;
root->key_value=key;
root->left=NULL;
root->right=NULL;
}
}

node *btree::search(int key)
{

return search(key, root);
}

void btree::destroy_tree()
{
destroy_tree(root);
}


node *btree::search(int key, node *leaf)
{
/* if(leaf!=NULL)
{
if(key==leaf->key_value)
return leaf;
if(keykey_value)
return search(key, leaf->left);
else
return search(key, leaf->right);
}
else return NULL;*/

//##########################
if(leaf!=NULL)
{
if(key==leaf->key_value)
{
cout<<"element found \n";
return leaf;
}

if(keykey_value)
return search(key, leaf->left);
else
return search(key, leaf->right);
}
else
{
cout<<"element not found\n";
return NULL;
}

//#########################
}

/*
void btree::cirn(struct node * ref,struct node * root,int left,int right)
{
if(root == NULL)
return;

if(root)
{
if(left==0 && right==0)
{
// printf("%d ",root->key_value);
cout<<"######################"<key_value< }

cirn(ref,root->left,left,right);
}
if(root->left==NULL && root->right==NULL && right>0)
{
//printf("%d ",root->key_value);
cout<<"######################"<key_value< }

if(root==ref)
{

left++;
}

if(root)
{
right++;
cout<<"$$$$$$$$$$ right is--------- \t"<key_value< cirn(ref,root->right,left,right);
}
if(left>0 && !(root->left==NULL && root->right==NULL))
{
//printf("%d ",root->key_value);
cout<<"######################"<key_value< }

}
*/



void btree::cirn(struct node * ref,struct node * root,int left,int right)
{
if(root == NULL)
return;

if(root)
{

if(right==0)
{

cout<<"######################"<key_value< }
int r=left+1;
cirn(ref,root->left,r,right);

// left++;

}
if(root->left==NULL && root->right==NULL && right>0)
{
//printf("%d ",root->key_value);
cout<<"######################"<key_value< }

if(ref==root)
{
// cout<<"@@@@@@@@@@@@@@@@@@ right value is\t"< left=0;
}


if(root)
{
//right++;
cirn(ref,root->right,left,right+1);
if(left==0)
{

if(right!=0)
{
cout<<"######################"<key_value< }


}




}









}

int main()
{
btree *b=new btree();
b->insert(10);
b->insert(5);
b->insert(3);
b->insert(8);
b->insert(6);
b->insert(7);
//b->insert(9);
b->insert(1);
b->insert(4);

b->insert(13);
b->insert(11);
b->insert(12);
b->insert(14);
b->insert(16);
b->insert(15);


b->search(10);
b->search(19);
p=b->search(10);
cout<<"p is "< b->inorder(p);
struct node * ref=p;
b->cirn(ref,p,0,0);

}
