
/*	归并排序，其基本思路就是将数组分成二组A，B，如果这二组组内的数据都是有序的，那么就可以很方便的将这二组数据进行排序。
*	如A为1、5、9，B为3、6、8，则合并后为1、3、5、6、8、9
*	如何让这二组组内数据有序了？可以将A，B组各自再分成二组。
*	当分出来的小组只有一个数据时，可以认为这个小组组内已经达到了有序，然后再合并相邻的二个小组就可以了。
*	这样通过先递归的分解数列，再合并数列就完成了归并排序。
*/



/*   此时nums[start...mid] 与 nums[mid+1...end]两部分已分别有序，利用temp数组将两部分合并，则合并后nums[start...end]有序  */
void merge(vector<int>& nums,int start,int end,int mid,vector<int>& temp){
	int i=start,j=mid+1;
	int k=start;
	while(i<=mid&&j<=end){
		if(nums[i]<=nums[j]){
			temp[k++]=nums[i++];
		}else{
			temp[k++]=nums[j++];
		}
	}
	while(i<=mid)	temp[k++]=nums[i++];
	while(j<=end)	temp[k++]=nums[j++];
	for(int i=start;i<=end;++i){
		nums[i]=temp[i];
	}
}

void mergeSort(vector<int>& nums,int start,int end,vector<int>& temp){
	if(start>=end)	return;
	int mid=start+(end-start)/2;			//不断二分，递归进行归并排序
	mergeSort(nums,start,mid,temp);			//左边有序
	mergeSort(nums,mid+1,end,temp);			//右边有序
	merge(nums,start,end,mid,temp);			//合并左右两部分
}
