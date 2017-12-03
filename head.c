#include <stdio.h>

int main(int argc, char * argv[])
{
    FILE    *   fp;          
    char    *   line = NULL;
    int         len  = 0;
 
    int cnt = 0;    
 
    if( argc < 2)
    {
        printf("Insufficient Arguments!!!\n");
        printf("Please use \"program-name file-name N\" format.\n");
        return -1;
    }
 
    if(argv[1][0] != '-'){
        fp = fopen(argv[1],"r");
 
        // checking for file is exist or not
        if( fp == NULL )
        {
            printf("\n%s file can not be opened !!!\n",argv[1]);
            return 1;   
        }
    
        // read lines from file one by one
        while (getline(&line, &len, fp) != -1)
        {
            cnt++;
            if ( cnt > 5 )
                break;
 
            printf("%s",line); fflush(stdout);
        }
    }

    
    // close file
    fclose(fp);
 
    return 0;
}
