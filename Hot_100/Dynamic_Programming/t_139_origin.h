#include <string.h>
                                        
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int length[wordDictSize];
    for(int i = 0;i < wordDictSize;i++){
        length[i] = strlen(wordDict[i]);
    }
    int length_s = strlen(s);
    bool reach[length_s + 1];
    reach[0] = true;
    for(int i = 1;i <= length_s;i++){  
        reach[i] = false;              
        for(int j = 0;j < wordDictSize;j++){
            if(length[j] > i || reach[i - length[j]] == false) continue;
            if(strncmp(s + i -length[j],wordDict[j],length[j] * sizeof(char)) == 0){
                reach[i] = true;
                break;
            }
        }
    }
    return reach[length_s];
}