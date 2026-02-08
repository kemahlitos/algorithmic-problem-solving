#include "the1.h"

// DO NOT CHANGE ABOVE THIS LINE!
// you may implement helper functions below
    long no_recursion=0;
    
std::pair<unsigned short, unsigned short> partition(unsigned short *arr,int start,int end,long &swap){
    int i = start+1;
    int j = start+1;
    int k=end;
    unsigned short pivot = arr[start];
    
    while(j<=k){
        if(arr[j]==pivot){
            j=j+1;
        }
        else if(arr[j] < pivot){
            swap+=1;
            std::swap(arr[i],arr[j]);
            i=i+1;
            j=j+1;
        }
        else if(arr[j]>pivot){
            swap+=1;
            std::swap(arr[j],arr[k]);
            k=k-1;
        }
    }
    swap+=1;
    std::swap(arr[i-1],arr[start]);
    return std::make_pair(i-1,j);
}

void quicksort3(unsigned short *arr,int start,int end,long &no_recursion,long &swap){
    
    no_recursion+=1;
    
    if(end<=start){
        return;
    }
    
    std::pair<int,int> my_pivot_pair = partition(arr,start,end,swap);
    quicksort3(arr,start,my_pivot_pair.first-1,no_recursion,swap);
    quicksort3(arr,my_pivot_pair.second,end,no_recursion,swap);
    
}


std::pair<unsigned short, unsigned int> select_k_with_quick_sort3(unsigned short *arr,
                                                                  const unsigned int size,
                                                                  const unsigned int index,
                                                                  long &swap){
    // your code here
    no_recursion=0;
    int end=size-1;
    quicksort3(arr,0,end,no_recursion,swap);
    return std::make_pair(arr[index],no_recursion);
}


void quicksort3faster(unsigned short *arr,int start,int end,const unsigned int index,long &no_recursion,long &swap){
    
    no_recursion+=1;
    
    if(end<=start){
        return;
    }
    
    std::pair<int,int> my_pivot_pair = partition(arr,start,end,swap);
    
    if(index<=my_pivot_pair.first-1){
        quicksort3faster(arr,start,my_pivot_pair.first-1,index,no_recursion,swap);
    }
    else if(index>=my_pivot_pair.second){
        quicksort3faster(arr,my_pivot_pair.second,end,index,no_recursion,swap);
    }
    else{
        return;
    }
    
}

std::pair<unsigned short, unsigned int> quick_select3(unsigned short *arr,
                                                      const unsigned int size,
                                                      const unsigned int index,
                                                      long &swap){
    // your code here
    no_recursion=0;
    int end=size-1;
    
    quicksort3faster(arr,0,end,index,no_recursion,swap);
    return std::make_pair(arr[index],no_recursion);
}


