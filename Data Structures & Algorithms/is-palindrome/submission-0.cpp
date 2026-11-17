class Solution {
public:
    bool isPalindrome(string s) {
     string ans = "";
     for(int i = 0; i < s.length(); i++) {
       if(isupper(s[i])){
        s[i] = tolower(s[i]);
       }
       if(isalnum(s[i])) {
        ans += s[i];
    }
  }
    int n = ans.length();
    int i=0;
    int j=n-1;
    
   while(i < j) {
            if(ans[i] != ans[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

};
