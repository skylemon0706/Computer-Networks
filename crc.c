#include <stdio.h>
#include <string.h>
#define N strlen(gen_poly)
char data[28];
char gen_poly[28];
char check_value[28];
int data_length,i,j;

void XOR(){
    for(int i=0;i<N;i++){
        check_value[i]=((check_value[i]==gen_poly[i])?'0':'1');
    }
}
void receiver(){
    printf("Enter received data\n");
    scanf("%s",data);
    printf("\nReceived data\n");
    printf("%s",data);

    crc();

    int flag=0;
    for(i=0;i<data_length-1;i++){
        if(check_value[i]=='1'){
            flag=1;
        }
    }
    if(flag==1){
        printf("Error detected\n");
    }
    else{
        printf("No Error detected\n");
    }
}
void crc(){

    for(i=0;i<N;i++){
        check_value[i]=data[i];
    }
    do{
        if(check_value[0]=='1'){
            XOR();
        }
        for(j=0;j<N-1;j++){
            check_value[j]=check_value[j+1];
        }
        check_value[j]=data[i++];
    }while(i<=data_length+N-1);
}


int main()  
{   
    printf("\nEnter data to be transmitted: ");  
    scanf("%s",data);

    printf("\nEnter the Generating polynomial: ");  
    scanf("%s",gen_poly);  

    data_length=strlen(data);  
    
    for(i=data_length;i<data_length+N-1;i++)  
        data[i]='0';  

    printf("\nData padded with n-1 zeros : %s",data);  

    crc();  

    printf("\nCRC or Check value is : %s",check_value);  

    for(i=data_length;i<data_length+N-1;i++)  
        data[i]=check_value[i-data_length];  
     
    printf("\nFinal data to be sent : %s\n",data);  
    
    receiver();  
    
    return 0;  
}  