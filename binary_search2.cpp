#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr, int target);

int first_value_grt_or_equal_to_target(vector<int> arr, int target);

int main()
{
    /*vector <int> arr = {1,2,4,7,22,43,56,76,100};
    int target=43, index;

    index = binarySearch(arr, target);
    if(index==-1){
        cout << "Element not present";
    }
    else{
        cout << "Element is present at " << index << " position." << endl;
    }*/

    /*vector<int> arr = {2,3,5,6,8,10,12};
    int target = 4, answer;

    answer = first_value_grt_or_equal_to_target(arr, target);
    if(answer==-1){
        cout << "Condition not satisfied";
    }
    else{
        cout << "Element greater than or equat to " << target << " is " <<answer << " ." << endl;
    }*/


    return 0;
}


int binarySearch(vector <int> arr, int target){

    int left_index = 0, right_index=arr.size()-1, mid_index;

    while(left_index<=right_index){

        mid_index = left_index+int((right_index-left_index)/2);
        if(arr[mid_index]==target){
            return mid_index;
        }
        else if(arr[mid_index]<target){
            left_index=mid_index+1;
        }
        else{
            right_index=mid_index-1;
        }
    }
    return -1;// returning empty range
}

int first_value_grt_or_equal_to_target(vector<int> arr, int target){

    int left_index = 0, right_index = arr.size(), mid_index, answer = -1;

    while(left_index<=right_index){

        mid_index=left_index+int((right_index-left_index)/2);
        if (arr[mid_index]>=target){
            answer = arr[mid_index];
            right_index = mid_index-1;
        }
        else{
            left_index = mid_index+1;
        }
    }
    return answer;
}

