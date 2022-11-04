// List deletion for given value using an array

#include <stdio.h>
#define MAX 10
int cnoe = 0;

void delete(int *arr, int val){
    int i;
    for(i = 0; i < cnoe; i++){
        if(val == arr[i]){
            break;
        }
    }
    if(i == cnoe){
        printf("Element not found");
    }else{
        for(int j = i; j < cnoe; j++){
            arr[j-1] = arr[j];
        }
        cnoe--;
    }
}

int main(){
    int arr[MAX];
    delete(arr, 3);
    return 0;
}