/*		
*		���ŵĻ���˼���ǣ�
*		1������ѡ��һ��Ԫ����Ϊ��Ԫ��һ��ѡ�����������Ԫ����Ϊ��Ԫ
*		2���������б���ԪС��Ԫ���ƶ�����Ԫ����ߣ�����Ԫ���Ԫ���ƶ�����Ԫ���ұ�
*		3���ֱ����Ԫ����������Ԫ�ؼ�����������
*/



/*  ��������Ĵ���ǳ��򵥣����ȵ���partion���̣��õ���ԪԪ����һ���������±꣬Ȼ�������������ֱ�ݹ����quick_sort()  */
void quick_sort(vector<int>& nums,int start,int end){
	if(start<end){
		int mid=partion2(nums,start,end);
		quick_sort(nums,start,mid-1);
		quick_sort(nums,mid+1,end);
	}
}

/*���Է��ֿ�������Ĺؼ���partion����*/
int partion(vector<int>& nums,int start,int end){                //�㷨�����ϵķ�������ĩβԪ����Ϊ��Ԫ�������ҽ��е���
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

int partion2(vector<int>& nums,int start,int end){             //��һ�ֽⷨ���ڿ�����
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

