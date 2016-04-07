/*	快排的基本思想是：
*	1）首先选定一个元素作为主元，一般选择最左或最右元素作为主元
*	2）将数组中比主元小的元素移动到主元的左边，比主元大的元素移动到主元的右边
*	3）分别对主元左、右两部分元素继续上述操作
*/



/*  快速排序的代码非常简单，首先调用partion过程，得到主元元素在一次排序后的下标，然后对左、右子数组分别递归调用quick_sort()  */
void quick_sort(vector<int>& nums,int start,int end){
	if(start<end){
		int mid=partion2(nums,start,end);
		quick_sort(nums,start,mid-1);
		quick_sort(nums,mid+1,end);
	}
}

/*可以发现快速排序的关键是partion过程*/
int partion(vector<int>& nums,int start,int end){         //算法导论上的方案，以末尾元素作为主元，从左到右进行调整
	int pivot=nums[end];
	int j=start-1;
	for(int i=start;i<end;++i){
		if(nums[i]<=pivot){
			++j;
			swap(nums[i],nums[j]);
		}
	}
	swap(nums[j+1],nums[end]);
	return j+1;
}

int partion2(vector<int>& nums,int start,int end){        //另一种解法：挖坑填数
	int pivot=nums[start];
	int i=start,j=end;
	while(i<j){
		while(i<j&&nums[j]>=pivot)	--j;
		if(i<j){
			nums[i]=nums[j];
			++i;
		}
		while(i<j&&nums[i]<pivot)	++i;
		if(i<j){
			nums[j]=nums[i];
			--j;
		}
	}
	nums[j]=pivot;
	return j;
}

