#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define NL printf("\n");

typedef struct Vehicle
{
    char brand[SIZE];
    char model[SIZE];
    int engineVolume;
    double price;
    char isRegistrated;//Y or N
}Vehicle;

void printCarInfo(Vehicle v1)//Prints on the console
{
    printf("Brand - %s\n",v1.brand);
    printf("Model - %s\n",v1.model);
    printf("Engine volume - %d\n",v1.engineVolume);
    printf("Price - %lg\n",v1.price);
    printf("Has registration - %c\n",v1.isRegistrated);
}

void writeCarInfoInFile(Vehicle v1)//Writes the struct to file
{
    FILE* fp = fopen("cardb.txt","a");
    if(fp==NULL)
    {
        exit(1);
    }
    fprintf(fp,"Brand - %s\nModel - %s\nEngine volume - %d\nPrice -  %lg\nHas registration - %c\n",
            v1.brand,v1.model,v1.engineVolume,v1.price,v1.isRegistrated);
    fprintf(fp,"\n");
    fclose(fp);
}

void printCarsInfoFromFile()//Prints everything from the file
{
    FILE* fp = fopen("cardb.txt","r");
    if(fp==NULL)
    {
        exit(1);
    }
    char line[SIZE];
    while(!feof(fp))
    {
        fgets(line,sizeof(line),fp);
        printf("%s",line);
    }
    fclose(fp);
}

Vehicle enterVehicle()//User enter data for the struct on the console
{
    Vehicle v1;
    char stringInputs[SIZE];
    printf("Enter vehicle brand: \n");
    gets(stringInputs);
    strcpy(v1.brand,stringInputs);
    printf("Enter vehicle model: \n");
    gets(stringInputs);
    strcpy(v1.model,stringInputs);
    printf("Enter vehicle engine volume: \n");
    scanf("%d",&v1.engineVolume);
    printf("Enter vehicle price: \n");
    scanf("%lg",&v1.price);
    printf("Enter vehicle has registration(Y/N): \n");
    scanf(" %c",&v1.isRegistrated);
    return v1;
}

int main()
{
    Vehicle vw;
    strcpy(vw.brand,"VW");
    strcpy(vw.model,"Golf");
    vw.engineVolume=1900;
    vw.price=2500.5;
    vw.isRegistrated='Y';

    Vehicle bmw;
    strcpy(bmw.brand,"BMW");
    strcpy(bmw.model,"530");
    bmw.engineVolume=3000;
    bmw.price=5500.55;
    bmw.isRegistrated='N';

    printCarInfo(vw);
    NL;
    printCarInfo(bmw);
    NL;
    writeCarInfoInFile(vw);
    writeCarInfoInFile(bmw);
    writeCarInfoInFile(enterVehicle());
    NL;
    printCarsInfoFromFile();
    return 0;
}
