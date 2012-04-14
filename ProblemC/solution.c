#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 8

int exist(int a[],int n ,int k);

int main(int argc, char const *argv[])
{

    FILE *input;
    FILE *output;
    input = fopen("input.txt","r");
    output = fopen("output.txt","w");
    if(input == NULL || output == NULL){
        printf("open file failed\n");
        exit(1);
    }

    int t,a,b,count,i,j,k,len;
    int case_count = 1;
    char str[MAXSIZE * 2];
    char *num;
    int passed[MAXSIZE];
    fscanf(input,"%d",&t);

    while(t > 0){
        fscanf(input, "%d %d", &a, &b);
        //printf("A: %d, B: %d\n",a, b);
        count = 0;
        for(i = a; i <= b; i++){
            // parsing the int to string
            sprintf(str,"%d", i);
            len = strlen(str);
            //printf("the string length: %d\n", len );

            // str size * 2   e.g. 1234 => 12341234
            for(j = 0; j < len; j++){
                str[len+j] = str[j];
            }
            str[len + j] = '\0';
            //printf("the new string is: %s\n", str);

            memset( passed , 0, MAXSIZE * sizeof(int));
            for(j = 0; j < len; j++){
                num = strndup(str + j, len);
                k = atoi(num);
                //printf("the rotate num: %d\n", k );
                if(k>i && a <= k && k <= b){
                    if(!hasExist(passed,j, k)){
                        passed[j] = k;
                        count++;
                        //printf("(%d %d)\n", i ,k );
                    }
                }
                free(num);
            }
        }

        fprintf(output, "Case #%d: %d\n", case_count++, count);
        printf("Case #%d: %d\n", case_count -1 , count);
        t--;
    }

    fclose(input);
    fclose(output);
    return 0;
}

int exist(int a[],int n ,int k)
{
    int i;
    for(i = n; i>0 && a[i-1] != k; i--)
        ;
    return i;
}


