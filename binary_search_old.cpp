#include <iostream>
using namespace std;

void binarySearch(int arr[], int target, int low_index, int high_index);
int main()
{
    int arr[6] = {1,3,2,4,24,12};
    int target=3, low_index=0, high_index=9;

    binarySearch(arr, target, low_index, high_index);



    return 0;
}

//void binarySearch(int arr[], int target, int low_index, int high_index){
//void binarySearch(int arr[6], int target, int low_index, int high_index){

void binarySearch(int *arr[], int target, int low_index, int high_index){

    int mid_index = int((low_index+high_index)/2);
    if (low_index>high_index){
        cout << "Not in the list..." << endl;

    }else {
        if (arr[mid_index]==target){
            cout << "Element " << target << " is present in " << mid_index << " index location (index starting from zero)." << endl;
            }else {
                if (arr[mid_index]>target){
                    binarySearch(arr,target, low_index, mid_index-1);
                }else if (arr[mid_index]<target){
                    binarySearch(arr,target, mid_index+1, high_index);

                }
            }

    }



}

