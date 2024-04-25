int temp;
    int j;
    for(int i=1;i<size;i++){
        temp = arr[i];
        j = i-1;
        while((arr[j] > temp && (j>=0))){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }