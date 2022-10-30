#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node*right;
}*root=NULL;

void inOrderTraversal(struct node* root){
    struct node* t=root ;
   if(t!=NULL){
    inOrderTraversal(t->left);
    printf("%d\n",t->data);
    inOrderTraversal(t->right);
    }
}
void postOrderTraversal(struct node* root){
    struct node* t=root ;
   if(t!=NULL){
    postOrderTraversal(t->left);
    postOrderTraversal(t->right);
      printf("%d\n",t->data);
    }
}
void preOrderTraversal(struct node* root){
    struct node* t=root ;
   if(t!=NULL){
    printf("%d\n",t->data);
    preOrderTraversal(t->left);
    preOrderTraversal(t->right);
      
    }
}
//insertion Using iterative Function---

// insertIterativeInBST(struct node*t,int key){
//     struct  node*r=NULL;
// struct  node*p;
    
   
//     while(t!=NULL){
//         r=t;
//         if(t->data==key){
//             return;
//         }
//         else if(t->data>key){
//             t=t->left;
//         }
//         else{
//             t=t->right;
//         }
    
// }
// p=(struct node*)malloc(sizeof(struct node));
// p->left=p->right=NULL;
// if(p->data<r->data)r->child=p;
// else r->child=p;
// }
//Insertion Using recursive function------
struct node* insertRecursiveInBST(struct node*p,int key){
   
    if(p==NULL){
        struct node* t=(struct node*)malloc(sizeof(struct node));
        t->data=key;
        t->left=NULL;
        t->right=NULL;
        return t;
    }
    if(p->data<key){
        p->right=insertRecursiveInBST(p->right,key);
    }
    else if(p->data>key){ 
        p->left=insertRecursiveInBST(p->left,key);
    }
    return p ;
}

//Recursive function For deletion in BST----------------------------------------------------------------------------
int Height(struct node*p){
    int x,y;
    if(p==NULL){
        return 0;
    }
    x=Height(p->left);
    y=Height(p->right);
    return x>y?x+1:y+1;
}
 struct node*InPre(struct node*p){
    while(p&&p->right!=NULL){
        p=p->right;
    }
    return p;
 }
  struct node*InSucc(struct node*p){
    while(p&&p->left!=NULL){
        p=p->left;
    }
    return p;
 }
struct node* DeleteNode(struct node*p,int key){
    struct node*q;
if(p==NULL){
    return NULL;
}
if(p->left==NULL &&p->right==NULL){
    if(p==root){
        root=NULL;
    }
    free(p);
    return NULL;
}
else if(p->data>key){
    DeleteNode(p->left,key);
}
else if(p->data<key){
    DeleteNode(p->right,key);
}
else{
    if(Height(p->left)>Height(p->right)){
        q=InPre(p->left);
        p->data=q->data;
        p->left=DeleteNode(p->left,q->data);
    }
    else{
        q=InSucc(p->right);
        p->data=q->data;
        p->right=DeleteNode(p->right,q->data);
    }
}
return p;
}
//Searching in Binary Tree
int Search(struct node* t,int key){
    
       N if(t==NULL){
        return -1;

    }
    else if(t->data==key){
        return  t->data;
    }
    else if(t->data>key){
       Search(t->left,key);
    }
    else{
        Search(t->right,key);
    }
   
}
    int main(){


//Insertion--------------------------------------------------
root=insertRecursiveInBST(root,90);
insertRecursiveInBST(root,45);
insertRecursiveInBST(root,46);
insertRecursiveInBST(root,37);
insertRecursiveInBST(root,78);
insertRecursiveInBST(root,19);
insertRecursiveInBST(root,7);
//Deletion---------------------------------------------------
DeleteNode(root,90);


//Searching -------------------------------------------------
// int x=Search(root,1);
// if(x==-1){
//     printf("The element is not present in the list\n");
// }
// else{
//    printf("The element found %d\n",x);
// }


//All Traversal Algorithms-----------------------------------
// printf("InOrder traversal\n");
// inOrderTraversal(root);
// printf("PostOrder traversal\n");
// postOrderTraversal(root);
printf("PreOrder  traversal\n");
preOrderTraversal(root);


    return 0;
}