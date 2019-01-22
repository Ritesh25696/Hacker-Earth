#include <iostream>
#include <vector>
using namespace std;

void returnEditedArray(int *A){
for(int i=0 ; i<5 ; i++){
    A[i] = A[i]+1;
}
}

int main()
{
    int A[5] = {1,1,1,1,1};
    returnEditedArray(A);
    for(int i=0 ; i<5 ; i++)
        cout<<A[i]<<endl;

}
