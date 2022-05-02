#include <stdio.h>
#include <stdlib.h>
//wrting number n and n numbers after it in a text file
//reading the nums from the file and creating an array of size n with them
//finding odds and evens count
//sorting the array


void sortArr(int* arr, int size)//bubble sort the array
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}
int main()
{
    FILE *fp;
    fp=fopen("file.txt","w");
    if(fp==NULL)
    {
        return 1;
    }
    printf("Enter size: ");
    int n = 0, num=0;
    scanf("%d",&n);
    fprintf(fp,"%d ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        fprintf(fp,"%d ",num);
    }
    fclose(fp);
    fp=fopen("file.txt","r");
    fscanf(fp,"%d",&n);
    int arr[n];
    int counter=0;
    int evenNums=0, oddNums=0;
    while(!feof(fp))
    {
        fscanf(fp,"%d",&arr[counter]);
        counter++;
    }
    fclose(fp);
    sortArr(arr,n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            evenNums++;
        }else oddNums++;
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Even numbers count: %d\n",evenNums);
    printf("Odd numbers count: %d\n",oddNums);


    return 0;
}
