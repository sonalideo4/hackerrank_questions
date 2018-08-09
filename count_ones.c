/* Convert int to binary. Return [] where index 0 is no. of 1's in binary representation and rest are indices of where 1's are */

int* countOnes(int* result_count, int num) 
{
    int binaryNum[1000];
    *result_count = 0;
    
    int i = 0;
    while(num>0) {
        binaryNum[i] = num%2;
        num = num/2;
        if(binaryNum[i] == 1) {
            *result_count++;
        }
        i++;
    }
    
    //reverse the number to get correct MSB to LSB
    int bin_num[i];
    int result[*result_count+1];
    result[0] = *result_count;
    
    for(int j=i-1, k=0, l=1; j>=0; j--) {
        bin_num[k] = binaryNum[j];
        if(bin_num[k] == 1) {
            result[l] = k+1;
            l++;
        }
        k++;
    }
    return &result;
}

int main()
{
    int num_ones = 0;
    int *result;
    result = countOnes(&num_ones, 56);
    for(int i=0; i<num_ones+1; i++)
        printf("%d ", result[i]);
    return 0;
}