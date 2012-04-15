#include <stdio.h>
#include <stdlib.h>

int leastTotal(int p);
int leastNotS(int p);

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
    int t,n,s,p;
    int count;
    int total[100];
    int case_count = 1;
    fscanf(input,"%d",&t);

    while(t > 0){
        
        fscanf(input,"%d %d %d",&n,&s,&p);
        int i;
        for(i=0;i < n; i++){
            fscanf(input," %d",&total[i]);
           // printf(" %d",total[i] );
        }
        count = 0;

        for(i=0; i < n; i++){
            if(total[i] >= leastNotS(p)){
                count ++;
            }else if(total[i] >= leastTotal(p)){
                if(s > 0){
                    s--;
                    count++;
                }
            }
        }
        fprintf(output, "Case #%d: ", case_count++);
        fprintf(output, "%d\n", count );
        t--;
    }
    fclose(input);
    fclose(output);

    return 0;
}

int leastTotal(int p)
{
    if(p > 1)
        return p + 2 * (p - 2);
    else
        return p;
}

int leastNotS(int p)
{
    if(p > 1)
        return p + 2 * (p -1);
    else
        return p;
}

