bool IsPossible(int arr[], int n, int k, int mid){
    int studentCount = 1;
    int PagesSum = 0;
    for(int i = 0; i< n; i++){
        if(PagesSum + arr[i] <= mid){
            PagesSum += arr[i];
        }
        else{
            studentCount++;
            PagesSum = arr[i];
            if(studentCount > k || arr[i] > mid){
                return false;
            }
        }
        
    }
    return true;
}
int findPages(int arr[], int n, int k) {
    // code here
    if(k > n) return -1;
    int s  = 0;
    int sum = 0;
    int ans = -1;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    
    int e = sum;
    int mid = s + (e - s)/2;
    while(s <= e){
        if(IsPossible(arr,n,k,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
