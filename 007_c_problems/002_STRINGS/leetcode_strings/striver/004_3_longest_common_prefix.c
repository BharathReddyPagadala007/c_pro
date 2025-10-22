char* longestCommonPrefix(char** strs, int strsSize) {
    int len=strlen(*strs);
    for(int i=1;i<strsSize;i++){
        for(int j=0;j<len&&j<strlen(strs[i]);j++){
            if(strs[0][j]!=strs[i][j]){
                len=j;
                break;
            }
        }
        if(len>strlen(strs[i]))len=strlen(strs[i]);
        if(len==0)return strdup("");
    }
    char* answer=malloc(sizeof(char)*(len+1));
    for(int i=0;i<len;i++){
        answer[i]=strs[0][i];
    }
    answer[len]='\0';
    return answer;
}
