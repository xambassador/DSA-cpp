#include <bits/stdc++.h>
using namespace std;

void compressString(char* arr){
    int i{};
    int j = strlen(arr);
    while(i<j){
        int cnt{1};
        int t{i+1};
        while(t<j){
            if(arr[t]!=arr[t-1]){
                break;
            }
            cnt++;
            t++;
        }
        if(cnt==1){
            i++;
        }else if(cnt==2){
            arr[i+1] = cnt+'0';
            i+=cnt;
        }else{
            arr[i+1] = cnt+'0';
            int t{i+2};
            while(t<j){
                arr[t] = arr[t+1];
                t++;
            }
            arr[t] = arr[j];
            j--;
            i = cnt-1;
        }
    }
}

int main(){
    char arr[100];
    cin >> arr;
    compressString(arr);
    cout << arr << endl;
}