#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LENGTH 102

int main(int argc, char const *argv[])
{
    // the mapping table
    char mapping_table[26]={'y','h','e','s','o','c','v','x','d','u',
                                'i','g','l','b','k','r','z','t','n','w',
                                'j','p','f','m','a','q'};
    FILE *input;
    FILE *output;
    input = fopen("input.txt","r");
    output = fopen("output.txt","w");
    if(input == NULL || output == NULL){
        printf("open file failed\n");
        exit(1);
    }

    int line;
    int case_count = 1;
    int index, i;
    char str[MAX_STR_LENGTH] , clear;
    fscanf(input,"%d%c",&line , &clear);

    while(line > 0 ){
        fprintf(output, "Case #%d: ", case_count++);
        fgets(str,MAX_STR_LENGTH, input);
        for (i = 0; str[i] != '\n'; ++i){
            index = str[i] - 'a';
            if(0 <= index && index <=25)
                fprintf(output, "%c", mapping_table[index] );
            else
                fprintf(output, " ");
        }
        fprintf(output, "\n");
        line --;
    }
    fclose(input);
    fclose(output);
    return 0;
}