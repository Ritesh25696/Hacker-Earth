#include <iostream>
#include <vector>
using namespace std;

void returnEditedArray(vector<int> &A){
for(int i=0 ; i<A.size() ; i++){
    A[i] = A[i]+1;
}
}

int main()
{
    vector<int> A(5,0);
    returnEditedArray(A);
    for(int i=0 ; i<A.size() ; i++)
        cout<<A[i]<<endl;

}
