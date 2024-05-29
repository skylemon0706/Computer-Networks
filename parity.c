#include <stdio.h>
#include <string.h>
char data[100];
char received[100];
int i;
int countOnes(char binary[]){
    int count=0;
    for(i=0;i<strlen(binary);i++){
        if(binary[i]=='1'){
            count++;
        }
    }
    return count;
}
void addparity(char datafile[]){
    int oneNumber=countOnes(datafile);

    if(oneNumber%2==0){
        strcat(datafile,"0");
    }
    else{
        strcat(datafile,"1");
    }

}
int main(){
    printf("Enter data to be transmitted");
    scanf("%s",data);

    addparity(data);

    printf("\nData after parity addition");
    printf("%s",data);

    printf("\nEnter received data");
    scanf("%s",received);

    if(strcmp(data,received)==0){
        printf("No error\n");
        data[strlen(data)-1]='\0';
        printf("Data : %s\n",data);
    }
    else{
        printf("Error Received\n");
    }
    return 0;
}