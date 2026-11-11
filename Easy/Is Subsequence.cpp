class Solution {
public:
    bool isSubsequence(string s, string t) {
    
        // get rid of edge cases
        
        // if "s" is empty, then it's always true no matter what "t" may be
        if(s == ""){
            return true;
        }
        
        // if "t" is empty and "s" is NOT, then return false (a non-empty "s" value will never be found in an empty "t", similar to how 0 divided by any number > 0 is just 0)
        if(t == "" && s != ""){
            return false;
        }
        
        // deal with another annoying edge-case: "s" values with only a single letter
        int size = 0;
        for(char skibidi : s){
            size++;
        }
        if(size == 1){
            bool found = false;
            for(char toilet : t){
                for(char skibidi : s){
                    if(skibidi == toilet){
                        found = true;
                    }
                }
            }
            // if that single letter is found in "t", then return "true"
            return found;
        }
        
        // initialize a vector-array for moving around "t" during searching
        vector<char> sigma;
        
        // add every letter in "t" to that array
        for(char tChar : t){
            sigma.push_back(tChar);
        }
        
        // looping for each individual letter in "s": 
        int z = 0;      // 1) initialize an index-holding number "z"
        for(char sChar : s){    // da loop
        
            // 2) for edge-cases where the next searching-for index is outside of the array's domain
            int n = z;
            if(n >= sigma.size()){
                break;
            }

            // 3) loop through the entire "t" char-array (sigma) following these rules:
            bool quitLoop = false;
            while (!quitLoop){
                if(sigma[n] != sChar){   // 3a) if the current index's value != search value,
                    sigma.erase(sigma.begin() + n); // delete it from that array
                    if(sigma.size() <= n){  // (see line below)
                        quitLoop = true;    // if we hit the end of the array, quit loop
                    }
                } else{             // 3b) else, if current index value == search value,
                    z = n + 1;      // increase search index by 1 (check next index in array)
                    quitLoop = true;   // quit loop for this search value, now that it's found
                }
            }

        }

        // now, the "sigma" array should contain only the searched-for values IN ORDER. any of those values in the array that weren't in order were deleted

        // for edge-cases where even after the final "s" value was found (or none at all), there still remains leftover values in the array. this gets rid of them (any value after the last searched-for index, a.k.a. the last letter in "s")
        for(int i = z; i < sigma.size();){
            sigma.erase(sigma.begin() + i);
        }
        
        // initialize a final str variable to hold the final "t" string after searching
        string searchedStr = "";
        
        // add each char value in "sigma" (t) to that final str variable
        for(int i = 0; i < sigma.size(); i++){
            searchedStr += sigma[i];
        }
        
        // and if that final str variable does NOT equal the initial "s", return false
        if(s != searchedStr){
            return false;
        }
        
        // else, return true ("s" was found in order in "t")
        return true;
    }
};
