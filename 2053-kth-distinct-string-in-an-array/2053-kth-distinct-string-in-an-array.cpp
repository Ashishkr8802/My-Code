class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> str;
        

        for(int i=0 ; i < arr.size() ; i++) {
            bool flag = 0;
            for(int j=0 ; j < arr.size() ; j++) {
                if(arr[i] == arr[j] && i != j){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                str.push_back(arr[i]);
            }
        }
        if(str.size() >= k) {
            return str[k-1];
        }
        
        return "";
    }
};