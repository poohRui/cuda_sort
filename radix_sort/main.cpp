//
//  main.cpp
//  Radix Sort
//
//  This program is going to show the Radix Sort alogriam and how to parallel it.
//
//  Created by poohRui on 2018/11/13.
//  Copyright © 2018 poohRui. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define RADIX 10

/**
 * Get the bit number of the max value
 *
 * @param array    len * dim matrix, keep the data in one of the matrix
 * @param len      the size of the array
 */
int getMaxBit(int* arr,
              int  len){
    
    int maxValue = arr[0];
    for(int i = 1;i<len;i++){
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }
    }
    
    int bitNum = 0;
    while(maxValue !=0){
        maxValue = maxValue / RADIX;
        bitNum++;
    }
    return bitNum;
}

/**
 * To randomly initial value of array
 *
 * @param array    len * dim matrix, keep the data in one of the matrix
 * @param len      the size of the array
 */
void initialVector(int*  arr,
                   int   len){
    
    srand(time(NULL));
    
    for(int i = 0;i < len;i++){
        arr[i] = rand() % 1024;
    }
}

/**
 * Use radix sort to sort the whole array
 *
 * @param arr   the array that need to be sort
 * @param len   the length of the array
 */
void radixSort(int*  arr,
               int   len){
    
    int bitNum = getMaxBit(arr, len);
    int bucket[len];
    
    int x = 1;
    int count[RADIX];
    for(int i = 0;i<bitNum;i++){
        for(int j = 0;j<RADIX;j++){
            count[j] = 0;
        }
        
        for(int j = 0;j<len;j++){
            int bucketIndex = (arr[j] / x) % RADIX;
            count[bucketIndex]++;
        }
        for(int j = 1;j<RADIX;j++){
            count[j] += count[j-1];
        }

        for(int j = len-1;j>=0;j--){
            int bucketIndex = (arr[j] / x) % RADIX;
            bucket[--count[bucketIndex]] = arr[j];
        }
        for(int j = 0;j<len;j++){
            arr[j] = bucket[j];
        }
        x = x*RADIX;
    }
}

int main(){
    
    int len = 10;
    int* arr = new int[len];
    
    
    initialVector(arr, len);
    cout<<"The initial vector is:"<<endl;
    for(int i = 0; i< len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    radixSort(arr, len);
    
    cout<<"After using Radix Sort, the vector is:"<<endl;
    for(int i = 0; i< len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
