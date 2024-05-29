#include <stdio.h>
#include <stdlib.h>
int sender(int arr[],int n)
{
    int sum=0,checksum;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    checksum=~sum;
    return checksum;

}
void receiver(int arr[],int n,int ch){
    int sum=0,checksum;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    sum=sum+ch;
    checksum=~sum;
    if(checksum==0)
        printf("No Error\n");
    else
        printf("Error detected\n");
}
int main()
{
    int n,send[100],received[100],checksum;
    printf("Enter the Number of bits : \n");
    scanf("%d",&n);
    printf("Enter the elements of array (SENDER SIDE)\n");
    for(int i=0;i<n;i++)
        scanf("%d",&send[i]);
    printf("MEssage transfered\n");
    checksum=sender(send,n);
    printf("Enter the received Message\n");
    for(int i=0;i<n;i++)
        scanf("%d",&received[i]);
    receiver(received,n,checksum);
    return 0;
}