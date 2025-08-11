#include<iostream>
#include<climits>

using namespace std;

//Memoization approach
int memo[100][100];

int matrixChainMemo(int p[],int i ,int j){
    if(i == j){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int minCost =   INT_MAX;
    for(int k = i ;k < j; k++){
        int cost = matrixChainMemo(p,i,k)+matrixChainMemo(p,k+1,j)+p[i-1]*p[k]*p[j];

        minCost = min(minCost,cost);
    }
    memo[i][j]= minCost;
    return minCost;
}

// Bottom Up approach (Tabulation)

int matrixChainBottomUp(int p[],int n){
    int dp[n][n];

    // Cost is zero when multiplying one matrix

    for (int i = 1;i<n;i++){
        dp[i][i] = 0;
    }
    // l is chain length

    for(int l = 2; l<n;l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l -1;
            dp[i][j] = INT_MAX;
            for(int k = i; k<=j-1; k++){
                int cost = dp[i][k] + dp[k+1][j]+p[i-1]*p[k]*p[j];
                dp[i][j] = min(dp[i][j],cost);
            }
        }
    }
    return dp[1][n-1];
}

int main(){
    int n;
    cout<<"Enter number of matrices: ";
    cin>>n;

    int p[n+1];
    cout<<"Enter dimensions (n+1 values): ";
    for(int i = 0; i<=n; i++){
        cin>>p[i];
    }

    //Initialize memoization array

    for(int i = 0; i<=n;i++){
        for(int j = 0; j<= n; j++){
            memo[i][j] = -1;
        }
    }

    cout<<"Minimum multiplications (Memoization): "<<matrixChainMemo(p,1,n)<<endl;
    cout<<"Minimum multiplications (Bottom UP): "<<matrixChainBottomUp(p,n+1)<<endl;

    return 0;
}