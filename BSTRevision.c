#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
}*root=NULL;
int search(struct node* t,int key){
if(t==NULL){
    return -1;
}
else{
    if(t->data==key){
        return t->data;
    }
    else if(t->data>key){
        search(t->left,key);
    }
    else{
        search(t->right,key);
    }
}
}
struct node*insertOrCreateTree(struct node*t,int key){
    if(t==NULL){
        struct node*p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    if(t->data<key){
        t->right=insertOrCreateTree(t->right,key);
    }
    else{
           t->left=insertOrCreateTree(t->left,key);

    }
    return t;

}
void  traversal(struct node*t){
    if(t!=NULL){
        traversal(t->left);
        printf("%d\n",t->data);
        traversal(t->right);
    }
}
int main(){
    root=insertOrCreateTree(root,90);
    insertOrCreateTree(root,45);
    insertOrCreateTree(root,89);
        insertOrCreateTree(root,46);
    insertOrCreateTree(root,90);
        insertOrCreateTree(root,55);
    insertOrCreateTree(root,99);
        insertOrCreateTree(root,65);
    insertOrCreateTree(root,80);
    insertOrCreateTree(root,1);
traversal(root);
printf("Okay wait ............We are searching \n");
int x=search(root,99);
printf("%d",x);
}