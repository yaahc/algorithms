#ifndef __SEARCH_CPP
#define __SEARCH_CPP

int linearSearch(int* arr, int length, int target) {
    //Start of algorithm
    for(int i = 0; i < length; i++)
        if(arr[i] == target)
            return i;

    return -1;
}

int binarySearch(int* arr, int start, int stop, int target) {
    if(stop < start) {
        return -1;
    }

    int mid = (start + stop)/2;

    if(arr[mid] == target) {
        return mid;
    } else if(arr[mid] > target) {
        return binarySearch(arr, start, mid-1, target);
    } else {
        return binarySearch(arr, mid+1, stop, target);
    }
}

#endif
