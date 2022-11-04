// List deletion for given position using an array

#include <stdio.h>
#define MAX 10
int cnoe = 0;

void delete(int *arr, int pos){
    if(cnoe == 0 || pos >= cnoe){
        printf("Not Possible");
        return;
    }
    for(int i = pos+1; i <= cnoe-1; i++){
        arr[i-1] = arr[i];
    }
    cnoe--;
}

int main(){
    int arr[MAX];
    delete(arr, 3);
    return 0;
}