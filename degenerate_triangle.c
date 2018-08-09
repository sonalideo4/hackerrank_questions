/* Degenerate triangle */

bool* notDegenerateTriangle(int* a, int* b, int* c, int numSides)
{   
    bool result[numSides];
    for(int i=0; i<numSides; i++) {
        if((a[i]+b[i] > c[i]) && (a[i]+c[i] > b[i]) && (c[i]+b[i] > a[i])) {
            result[i] = true;
        } else {
            result[i] = false;
        }
    }
    return &result;
}

int main()
{
    int a[3] = [1,2,3,4];
    int b[3] = [3,8,9,10];
    int c[3] = [8,8,8,8];
    bool *result = notDegenerateTriangle(a, b, c, 4);
    
    printf("Results\n");
    for(int i=0; i<4; i++) {
        printf("%b", result[i], " ");
    }
    return 0;
}