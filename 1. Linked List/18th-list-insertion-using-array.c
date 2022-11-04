// List insertion using an array

#include <stdio.h>
#define MAX 10
int cnoe = 0;

void insert (int *arr, int val, int pos){
    if(cnoe == MAX){
        printf("Not Possible");
        return;
    }
    if(pos >= cnoe){
        arr[cnoe] = val;
        cnoe++;
    }else{
        for(int i = cnoe-1; i >= pos; i--){
            arr[i++] = arr[i];
        }
        arr[pos] = val;
        cnoe++;
    }
}

int main(){
    int arr[MAX];
    insert(arr, 10, 3);
    insert(arr, 20, 4);
    insert(arr, 30, 5);
    for(int i = 0; i < MAX; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}