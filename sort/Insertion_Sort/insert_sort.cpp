
/*	直接插入排序(Insertion Sort)的基本思想是：每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中的适当位置，直到全部记录插入完成为止。
 
*	设数组为a[0…n-1]。
*	1.初始时，a[0]自成1个有序区，无序区为a[1..n-1]。令i=1
*	2.将a[i]并入当前的有序区a[0…i-1]中形成a[0…i]的有序区间。
*	3.当处理a[i]时，a[0…i-1]一定已经有序，因此向前遍历，找到最适合a[i]的位置插入
*	4.i++并重复第二步直到i==n-1。排序完成。
*/


void insertSort(vector<int>& nums){
	for(int i=1;i<nums.size();++i){
		int num=nums[i];
		int j=i-1;
		while(j>=0&&nums[j]>num){		//向前查找，找到最合适的位置插入a[i]
			nums[j+1]=nums[j];
			--j;
		}
		nums[j+1]=num;
	}
}