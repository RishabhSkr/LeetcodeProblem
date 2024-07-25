class Solution {
public:

    void merge(vector<int>&nums,int low,int mid,int high){
        int size1 = mid-low+1;
        int size2 = high-mid;
        int arr1[size1];
        int arr2[size2];
        int k = low; // first partition
        for(int i = 0 ;i<size1;++i)arr1[i]=nums[k++];
        k = mid+1; // second partition
        for(int i = 0 ;i<size2;++i)arr2[i]=nums[k++];

        // merge
        int i =0,j =0;
        k=low; // start from low
        while(i<size1 && j<size2){
            if(arr1[i]<=arr2[j]){
                nums[k]=arr1[i];
                k++,i++;
            }else{
                nums[k]=arr2[j];
                k++,j++;
            }
        }
        // if any remainin part left
        while(i<size1)nums[k++]=arr1[i++];
        while(j<size2)nums[k++]=arr2[j++];
    }
    void mergeSort(vector<int>&nums,int low,int high){
        if(low>=high)return ;
        int mid = low + (high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};