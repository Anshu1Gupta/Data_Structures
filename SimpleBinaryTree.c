
// ------------------------------TREE USING ARRAYS--------------------------------------------
// #include<stdio.h>
// #include<stdlib.h>
//     int main(){
//     int n,arr[100],lchild,rchild;
//     printf("Enter the number of nodes you want to a tree contain\n");
//     scanf("%d",&n);
//     printf("Enter the root node data\n");
//     int i=0;
//     scanf("%d",&arr[i]);
//     int r=n;
//     if(n%2==1){
//         n=n-1;
//         n=n/2;
//         while(n--){
//         printf("Enter the left child data of %d:  ",arr[i]);
//         scanf("%d",&arr[2*i+1]);
//          printf("Enter the right child data of %d:  ",arr[i]);
//         scanf("%d",&arr[2*i+2]);
//         i++;
//     }
//     }
//     else{
//         n=n-1;
//         n=n/2;
//         while(n--){
//         printf("Enter the left child data of %d:  ",arr[i]);
//         scanf("%d",&arr[2*i+1]);
//          printf("Enter the right child data of %d:  ",arr[i]);
//         scanf("%d",&arr[2*i+2]);
//         i++;
//     }
//     printf("Enter the left child data of %d:  ",arr[i]);
//         scanf("%d",&arr[2*i+1]);

//     }
//     printf("Level Order traversal of tree is:\n");
//     for(int i=0;i<r;i++){
//         printf("%d\n",arr[i]);
//     }
//     return 0;
// }




// -----------------------TREE USING LINKED LIST -----------------------------------------------------

// #include<stdio.h>
// #include<stdlib.h>
// struct queue{
//     int size;
//     int f,r;
//     struct node * *arr;

// };
// struct node{
//     int data;
//     struct node*left;
//     struct node*right;
// };
// void enqueue(struct queue*q,struct node* data){
//     if(q->r==q->size-1){
//         printf("Queue is Full\n");

//     }
//     else{
//         if(q->r==-1){
//             q->r=0;
//             q->f=0;
//             q->arr[q->r]=data;
//         }
//         else
//         {
//                  q->r++;
//                  q->arr[q->r]=data;

//         }
//     }
// }
// struct node* createNode(int data){
//     struct node*new=(struct node*)malloc(sizeof(struct node));
//     new->data=data;
//     new->left=NULL;
//     new->right=NULL;
//     return new;
// }
// struct node* dequeue(struct queue*q){
// if(q->f==-1){
//     printf("Queue is Empty \n");

// }
// else{
//     if(q->f>q->r){
//         q->f=-1,q->r=-1;
//     }
//     else{
//     struct node* data=q->arr[q->f];
//         q->f++;
//         return data;

//     }
// }
// }
// int isEmpty(struct queue*q){
//     if(q->r==-1){
//         return q;
//     }
//     else{
//         return 0;
//     }
// }
// struct node* createTree(){
// struct queue *q=(struct queue*)malloc(sizeof(struct queue));
// q->size=100;
// q->r=-1;
// q->f=-1;
// q->arr=(struct node* *)malloc(sizeof(struct node*)*q->size);
// int data;
// printf("Enter the root node \n");
// scanf("%d",&data);
// struct node*root=createNode(data);
// enqueue(q,root);
// while(q->f!=-1){
//     struct node*p=dequeue(q);
//     printf("Enter the left child of %d\n",p->data);
//     scanf("%d",&data);  
//     if(data!=-1){
// struct node*left=createNode(data);
// p->left=left;
// enqueue(q,left);
//     }
//        printf("Enter the right child of %d\n",p->data);
//     scanf("%d",&data);  
//     if(data!=-1){
// struct node*right=createNode(data);
// p->right=right;
// enqueue(q,right);
//     }
// }
// return root;
// }
// void in(struct node*root){
//     if(root!=NULL){
//         in(root->left);
//         printf("%d\n",root->data);
//         in(root->right);
//     }
// }
// void post(struct node*root){
//     if(root!=NULL){
//        post(root->left);
//         post(root->right);
//         printf("%d\n",root->data);
//     }
// }
// void pre(struct node*root){
//     if(root!=NULL){
        
//         printf("%d\n",root->data);
//         pre(root->left);
//         pre(root->right);
//     }
// }

// int main(){
// struct node*p=createTree();
// in(p);
// }
