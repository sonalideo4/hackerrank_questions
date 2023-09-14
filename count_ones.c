/* Convert int to binary. Return [] where index 0 is no. of 1's in binary representation and rest are indices of where 1's are */
#include <stdio.h>
#include <stdlib.h>


int* countOnes(int num) 
{
    int binaryNum[32];
    int num_ones = 0;
    
    int i = 0; //number of bits in binary representation
    while(num>0) {
        binaryNum[i] = num%2;
        num = num/2;
        if(binaryNum[i] == 1) {
            num_ones++;
        }
        i++;
    }
    //binaryNum contains LSB to MSB
    
    //reverse the number to get correct direction --> MSB to LSB
    int bin_num[i];
    int *result = (int*) calloc((num_ones+1), sizeof(int)); // array where result = [num_of_1s, indices...] is stored
    result[0] = num_ones;
    
    for(int j=i-1, k=0, l=1; j>=0; j--, k++) {
        bin_num[k] = binaryNum[j];
        if(bin_num[k] == 1) {
            result[l] = k+1; //indices from 1 not 0
            l++;
        }
    }
    return result;
}

int main()
{
    int num_ones = 0;
    int *result = countOnes(56);
    for(int i=0; i<(result[0]+1); i++)
        printf("%d ", result[i]);
    return 0;
}