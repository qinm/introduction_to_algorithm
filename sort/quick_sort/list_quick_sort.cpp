/*	单链表的快排
*	不交换节点，而是交换节点的值
*	每一轮partion都以起始节点作为key，然后对[pBegin,pEnd)之间的节点进行排序
*	时间复杂度O(nlgn），空间复杂度O(1)
*/


typedef struct listNode {
	int val;
	struct listNode *next;
	listNode(int num):val(num),next(NULL){}
}listNode;

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

listNode *partion(listNode *pBegin,listNode *pEnd){
	if(pBegin==pEnd)	return pBegin;
	int key=pBegin->val;    //以起始节点作为key，保证最后比key小的都在key的前面，比key大的都在key的后面，最后返回key对应的节点
	listNode *slow=pBegin;
	listNode *fast=pBegin;
	while(fast!=pEnd){
		if(fast->val<key){
			slow=slow->next;
			swap(&slow->val,&fast->val);
		}
		fast=fast->next;
	}
	swap(&slow->val,&pBegin->val);
	return slow;
}


void quick_sort(listNode *pBegin,listNode *pEnd){
	if(pBegin==pEnd)	return;
	listNode *mid=partion(pBegin,pEnd);
	quick_sort(pBegin,mid);
	quick_sort(mid->next,pEnd);
}
