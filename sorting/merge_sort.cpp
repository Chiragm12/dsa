/*
the algo is like we keep dividing the array into two halves, and then we sort each half, and then we merge them
so->
merge_sort(arr,low,high){
    if(low==high){
        return;
    }
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
        
        finish it
}
}
*/