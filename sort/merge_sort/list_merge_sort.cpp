/*	单链表的归并排序
*	对于数组的排序，一般快排比归并排序效率要高。
*	但是对于链表，归并排序不再需要临时数组来保存数组，只需要改变next指针即可。
*	因此对于链表而言，归并排序也是一个非常好的办法。
*	时间复杂度O(nlgn），空间复杂度O(1)
*/


	ListNode* merge_sort(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode* head1 = head;
        ListNode* head2 = getMid(head);
        head1 = merge_sort(head1);
        head2 = merge_sort(head2);
        return merge(head1, head2);
    } 
	
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* newhead = new ListNode(-1);
        ListNode* newtail = newhead;
        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                newtail->next = head1;
                head1 = head1->next;
            }
            else
            {
                newtail->next = head2;
                head2 = head2->next;
            }
            newtail = newtail->next;
            newtail->next = NULL;
        }
        if(head1 != NULL)
            newtail->next = head1;
        if(head2 != NULL)
            newtail->next = head2;
        return newhead->next;
    } 
	
    ListNode* getMid(ListNode* head)
    {
        ListNode* fast = head->next;
        ListNode* slow = head->next;
        ListNode* prev = head;
        while(true)
        {
            if(fast == NULL) break;
            fast = fast->next;
            if(fast == NULL)    break;
            fast = fast->next;
            
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;  // cut
        return slow;
    }