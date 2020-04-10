#include <iostream>
//#include <cstdlib>

using namespace std;

int main()
{
    int arr[11] = {12, 23, 23, 34, 45, 55, 72, 93, 107, 157, 212};
    cout << "Enter a number you want to search" << endl;

    /*int first = 0, num, last = (sizeof(arr))/(sizeof(*arr)), mid;
    cin >> num;
    //cout << first << last;
    do
    {
        mid = (first+last)/2;
        //cout << "Number found at position " << arr[mid];
        if (arr[mid]==num)
        {
            cout << "Number found at position " << mid;
            break;
        }
        else if (arr[mid]>num)
            last = mid-1;
        else
            first = mid +1;

    }while (first<=last); */

    int num;
    cin >> num;
    int len = (sizeof(arr))/(sizeof(*arr));
    for (int i =0; i<len; i++)
    {
        if (arr[i] == num)
            {
                cout << "Found in position: " << i+1;
                break;
            }

    }
    return 0;
}

