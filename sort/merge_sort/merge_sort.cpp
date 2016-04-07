
/*	�鲢���������˼·���ǽ�����ֳɶ���A��B�������������ڵ����ݶ�������ģ���ô�Ϳ��Ժܷ���Ľ���������ݽ�������
*	��AΪ1��5��9��BΪ3��6��8����ϲ���Ϊ1��3��5��6��8��9
*	�����������������������ˣ����Խ�A��B������ٷֳɶ��顣
*	���ֳ�����С��ֻ��һ������ʱ��������Ϊ���С�������Ѿ��ﵽ������Ȼ���ٺϲ����ڵĶ���С��Ϳ����ˡ�
*	����ͨ���ȵݹ�ķֽ����У��ٺϲ����о�����˹鲢����
*/




void merge(vector<int>& nums,int start,int end,int mid,vector<int>& temp){			//��ʱnums[start...mid] �� nums[mid+1...end]�������ѷֱ���������temp���齫�����ֺϲ�����ϲ���nums[start...end]����
	int i=start,j=mid+1;
	int k=0;
	while(i<=mid&&j<=end){			
		if(nums[i]<=nums[j]){
			temp[k++]=nums[i];
		}else{
			temp[k++]=nums[j];
		}
	}
	while(i<=mid)	temp[k++]=nums[i];
	while(j<=end)	temp[k++]=nums[j];
	fot(int i=0;i<k;++i){
		nums[i+start]=temp[i];
	}
}

void mergeSort(vector<int>& nums,int start,int end,vector<int>& temp){
	if(start>=end)	return;
	int mid=start+(end-start)/2;			//���϶��֣��ݹ���й鲢����
	mergeSort(nums,start,mid,temp);			//�������
	mergeSort(nums,mid+1,end,temp);			//�ұ�����
	merge(nums,start,end,mid,temp);			//�ϲ�����������
}