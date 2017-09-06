Brief Description:

Given an integer 
K
K being the size of permutation. 
Next line contains 
K
K single spaced numbers indicating the permutation. 
Each of next 
K
K lines contains 
K
K characters, character 
j
j 
of line 
i
i is equal to '
Y
Y' if you can exchange 
i
t
h
ith and 
j
t
h
jth 
element of a permutation, and '
N
N' otherwise.

Print 
K
K numbers with a space separating each of them 
indicating the lexicographically smallest permutation.

Pre-requisites: Graph Skills, DFS.

Difficulty Level: Easy - Medium.

Hints: Apply a DFS (
K
K) times to find the minimum
available number, then mark this number as chosen so as not 
to be chosen before.

Detailed Editorial:

This Question depends on your Graph Skills, DFS.

Firstly:

You should store all available swaps between numbers and form 
a graph where node represent (numbers), edges between nodes represent
available swaps between these numbers.

Secondly:

Apply a DFS (
K
K) times to find the minimum
available number, then mark this number as chosen so as not 
to be chosen before.

Note: You should use the graph you have formed before in each dfs
to find the minimum number so as to form the lexicographically 
smallest permutation.

Let's call the available swaps between numbers as edges(M).

Time Complexity: 
O
(
K
2
∗
(
K
+
M
)
)
O(K2∗(K+M)).

Memory Space Complexity: 
O
(
K
2
)
O(K2).
******************************************************************************************************************************************************************8888

#include <bits/stdc++.h>

using namespace std;

int arr [100 + 10];
char board [100 + 10][100 + 10];
bool chosen [100 + 10];
bool vis[100 + 10];
vector < int > v[100 + 10];
int pos [100 + 10];

int ans = -1;

void dfs(int index){

    vis[ index ] = true;
    if(!chosen[index]) ans = min(ans , arr[index]);         // check if the number isn't chosen before

    for(int i = 0; i < (int) v[index].size(); i++){

        if(vis[ v[index][i] ] ) continue;                   // check if the number was visited before
        int e = v[index][i];                                // check the available transitions
        dfs( e );
    }
}

int main()
{

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){

        cin >> arr[i];
        pos[ arr[i] ] = i;                          // store the original index of eah number
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            cin >> board[i][j];
            if(board[i][j] == 'Y')
                v[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++){

        memset(vis, false, sizeof vis);             // set all numbers as unvisited
        ans = 1e9;
        dfs(i);
        chosen[ pos[ans] ] = true;                  // put this index as already chosen
        cout << ans << " ";
    }

    return 0;
}
