#include <iostream>
#include <strings.h>
using namespace std;
#include <vector>
#include <string>
bool char_not_symbol(char c){
    return (c>='0'&&c<='9')||(c>= 'a' &&c<= 'z') || (c>= 'A' && c <= 'Z');
}

int main() {
  string pattern,str1;
  cin>>pattern>>str1;
  int len1 = pattern.size();
  int len2 = str1.size();
  vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,false));
  dp[0][0] = true;
  for(int i = 0; i<=len1; i++){
    for(int j = 0; j<=len2; j++){
        if(i == 0){
         continue;
        }
        if(j == 0){
          dp[i][j] = dp[i-1][j]&&(pattern[i-1]=='*');
          continue;
        }
        if(strncasecmp(&str1[j-1], &pattern[i-1],1)==0){
            dp[i][j] = dp[i-1][j-1];
            
        }else if(pattern[i-1]=='?'&&char_not_symbol(str1[j-1])){
            dp[i][j] = dp[i-1][j-1];
        }else if(pattern[i-1] == '*'&&char_not_symbol(str1[j-1])){
           dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];  
        }

    }
  }
  if(dp[len1][len2]){
    cout<<"true";
  }else{
   cout<<"false";
  }
  

}
// 64 位输出请用 printf("%lld")