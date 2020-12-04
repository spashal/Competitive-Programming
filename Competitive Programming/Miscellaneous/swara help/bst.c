#include <stdio.h>
#include <stdlib.h>
int n;
int a[100005], b[100005], ans, flag;

struct node{
	struct node* left_child;
	struct node* right_child;
	int k;
};

int comp(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

struct node* bst_build(int l, int r){
	// printf("%d %d\n", l, r);
	if( l <= r ){
		int mid = l + (r - l) / 2;
		struct node* cur = (struct node*)(malloc(sizeof(struct node)));
		cur -> k = a[mid];
		// printf(" %d\n", a[mid]);
		cur -> left_child = bst_build(l, mid - 1);
		cur -> right_child = bst_build(mid + 1, r);
		return cur;
	}
	return NULL;
}

void inorder_successor(struct node* cur, int num){
	if( cur != NULL){
		// printf("%d ", cur -> k);
		
		if( flag == 2 )
			return;	
		inorder_successor(cur -> left_child, num);

		if( flag == 1 ){
			flag = 2;
			ans = cur -> k;
			return; 
		}
		if( cur -> k == num )
			flag = 1;		
		inorder_successor(cur -> right_child, num);
	}
}

int main(){


	//n = length of inputd
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &a[i]);

	qsort(a, n, sizeof(int), comp);
	// for(int i = 0 ; i < n ; i++)
	// 	printf("%d \n", a[i]);
	// printf("\n");

	struct node* root = bst_build(0, n - 1);
	
	ans = -1;
	int k;
	printf("Please enter the number of queries for inorder successor\n");
	scanf("%d", &k); //k = no. of queries for inorder successor
	for(int i = 0 ; i < k ; i++){
		int find;
		scanf("%d", &find);
		ans = -1;
		inorder_successor(root, find);
		flag = 0;
		if( ans == -1 )
			printf("%d not found in the BST\n", find);
		else
			printf("The inorder successor of %d is %d\n", find, ans);
	}
	printf("\n");
	return (0);
}




Palash Sharma, [01.12.20 10:56]
to find the no. of occurences of a key in list:
int count_key(int key, struct dllnode * First){
	if(First == NULL)
		return 0;
	int count = 0;
	struct dllnode * temp = First;
	while(temp != NULL){
		if( temp -> data == key)
			count++;
		temp = temp -> next;
	}
	return count;
}

void deletelast(int key, struct dllnode * first){
	struct dllnode * new = (struct dllnode *)(malloc(sizeof(struct dllnode *)));
	struct dllnode * temp = first;
	int count;
	while( temp != NULL ){
		last = temp;
		temp = temp -> next;
		count++;
	}
	new -> data = count;
	new -> prev = NULL;
	new -> next = first;
	first -> prev = new;
	return new;
}















