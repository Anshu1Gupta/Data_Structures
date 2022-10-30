                                                  //ASSIGNMENT-1  QUESTION-2
  //Below is the program which takes  a list having next and random pointers as an input and  to create another copy of the same list
                                //The program takes linear(Time Complexity O(n))
                                           // Space complexity O(1)
                                   //++++++++++++    BY ANSHU GUPTA++++++++
    // -----------------------------------------------------------------------------------------------------------------------                                   
                                
#include<stdio.h>
#include<stdlib.h>
// Structure of linked list node
struct node
{
int data;
struct node *next;
struct node  *random;
	
};
// Function to create a new node by passing data values
struct node* create(int x)
	{
        struct node*new=(struct node*)malloc(sizeof(struct node));
		new->data = x;
		new->next =NULL; 
        new->random = NULL;
        return new;
	}
//Function to print the node
void print(struct node *start)
{
	struct node *ptr = start;
	while (ptr!=NULL)
	{
        printf(" Data = %d",ptr->data);
        printf(" Random= %d",ptr->random->data);
        printf("\n");
        ptr=ptr->next;
	}
}
// The Below  Function Clones The given linked list in O(1) space
struct node* clone(struct node *start)
{
	struct node* curr = start;
    struct node *temp;
	// insert additional node after every node of original list
	while (curr)
	{
		temp = curr->next;
		// Inserting node
		curr->next = create(curr->data);
		curr->next->next = temp;
		curr = temp;
	}

	curr = start;
	// adjusting  the random pointers of the newly added nodes
	while (curr!=NULL)
	{
		if(curr->next){
			curr->next->random = curr->random ?curr->random->next : curr->random;
        }
		// move to the next newly added node by
		// skipping an original node
		curr = curr->next?curr->next->next:curr->next;
	}

struct node* original = start;
struct node *copy = start->next;

	// save the start of copied linked list
	temp = copy;

	// now separate the original list and copied list
	while (original && copy)
	{
		original->next =original->next? original->next->next : original->next;
		copy->next = copy->next?copy->next->next:copy->next;
		original = original->next;
		copy = copy->next;
	}
	return temp;
}
int main()
{
	struct node* start = create(1);
	start->next = create(2);
	start->next->next = create(3);
	start->next->next->next = create(4);
	start->next->next->next->next = create(5);

	// 1's random points to 3
	start->random = start->next->next;

	// 2's random points to 1
	start->next->random = start;

	// 3's and 4's random points to 5
	start->next->next->random =start->next->next->next->next;
	start->next->next->next->random =start->next->next->next->next;

	// 5's random points to 2
	start->next->next->next->next->random =start->next;
    printf("The original list os given below\n");
	print(start);
	printf("The cloned list is dhow below\n");
	struct node *cloned_list = clone(start);
	print(cloned_list);

	return 0;
}
