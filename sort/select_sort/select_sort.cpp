
/*	遍历数组，每次找到剩余数组中的最小值，交换至剩余待排元素的起始位置
*/

void select_sort(vector<int>& nums){
	for(int i=0;i<nums.size()-1;++i){
		int min=i;
		for(int j=i+1;j<nums.size();++j){
			if(nums[j]<nums[min]){
				min=j;				//记录所有剩余元素中最小值的下标
			}
		}
		swap(nums[i],nums[min]);   //将最小值交换到起始位置
	}
}