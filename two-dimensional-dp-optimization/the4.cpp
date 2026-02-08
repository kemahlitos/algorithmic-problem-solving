#include "the4.h"

// DO NOT CHANGE ABOVE THIS LINE!
// You may implement helper functions below
unsigned int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}



unsigned int alice_cutting_cake(const unsigned short cake_width,
                                const unsigned short cake_height,
                                bool **perfect_cuts){
    int arr[cake_width+1][cake_height+1];
    for(int i=0;i<cake_width+1;i++){
        arr[i][0]=0;
    }
    for(int j=0;j<cake_height+1;j++){
        arr[0][j]=0;
    }

    for(int i=1; i<cake_width+1;i++){
        for (int j=1; j<cake_height+1;j++){
            if(perfect_cuts[i][j]){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=i*j;
                
                //vertical slices
                for(int k=1;k<i/2+1;k++){
                    arr[i][j]=min(arr[i][j],arr[k][j]+arr[i-k][j]);
                }
                //horizontal
                for(int m=1;m<j/2+1;m++){
                    arr[i][j]=min(arr[i][j],arr[i][m]+arr[i][j-m]);
                }
            }
            
        }
    }
    
    


    return arr[cake_width][cake_height];
}

