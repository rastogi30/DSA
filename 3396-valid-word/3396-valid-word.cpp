class Solution {
public:
    bool isValid(string word) {
        bool vowel=false;
        bool consonant=false;

        if(word.size()<3){
            return false;
        }

        for(int i=0;i<word.size();i++){
            if((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')){
                char ch=tolower(word[i]);
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                  vowel=true;
                }
                else{
                    consonant=true;
                }
            }
            else if(!(word[i]>='0' && word[i]<='9')){
                return false;
            }
        }

        return vowel && consonant;
    }
};

// tc is O(N);

// use direct to check alphabet use isalpha and for number isdigit