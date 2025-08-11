#include<iostream>
using namespace std;

//Memoization approach

int memo[10000];

int rodCuttingMemo(int price[],int n){
    if(n<=0){
        return 0;
    }
    if(memo[n] != -1){
        return memo[n];
    }

    int maxVal = 0;
    for(int i = 1; i <= n; i++){
        maxVal = max(maxVal,price[i-1]+rodCuttingMemo(price,n-1));
    }

    memo[n] = maxVal;
    return maxVal;
}

//Bottom-up approach (Tabulation)

int rodCuttingBottomUp(int price[],int n){
    int dp[n+1];
    dp[0] = 0;

    for(int i = 1;i<=n; i++){
        int maxVal = 0;
        for(int j = 1; j <= i; j++){
            maxVal = max(maxVal,price[j-1]+dp[i-j]);
        }
        dp[i] = maxVal;
    }
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter length of rod: ";
    cin>>n;

    int price[n];
    cout<<"Enter pices for length 1 to "<<n<<" :";
    for(int i = 0; i<n;i++){
        cin>>price[i];
    }

    //Initialize memoization array

    for(int i = 0; i<=n;i++){
        memo[i]= -1;
    }

    cout<<"Maximum profit (Memoization): "<<rodCuttingMemo(price,n)<<endl;
    cout<<"Maximum profit (BottomUp): "<<rodCuttingBottomUp(price,n)<<endl;

    return 0;
}