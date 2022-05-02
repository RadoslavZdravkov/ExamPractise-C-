#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
#define NL printf("\n")

int higherIncomeArrSize=2;
int counter=0;
int innerCounter=0;
int fileArtistsCounter=0;
typedef struct Artist
{
    char name[SIZE];
    int age;
    char country[SIZE];
    double income;
    int oscars;
}Artist;
Artist* higherIncomeArtists;
Artist* fileArtists;

void printArtist(Artist artist)
{
    printf("name - %s\n",artist.name);
    printf("age - %d\n",artist.age);
    printf("country - %s\n",artist.country);
    printf("income - %lg\n",artist.income);
    printf("oscars - %d\n",artist.oscars);
}

void AddNewArtist(Artist* artists)
{
    if(counter==SIZE-1)
    {
        artists=(Artist*)realloc(artists,sizeof(Artist)*(SIZE*2));
    }
    Artist a1;
    printf("Enter artist name:\n");
    fflush(stdin);
    gets(a1.name);
    printf("Enter artist age:\n");
    scanf("%d",&a1.age);
    fflush(stdin);
    printf("Enter artist country:\n");
    gets(a1.country);
    printf("Enter artist income:\n");
    scanf("%lg",&a1.income);
    printf("Enter artist oscars count:\n");
    scanf("%d",&a1.oscars);
    artists[counter]=a1;
    counter++;
}

Artist* returnCertainIncomeArtistArray(Artist* artists, double income)
{
   for(int i=0;i<counter;i++)
   {
       if(artists[i].income>income)
       {
           strcpy(higherIncomeArtists[innerCounter].name,artists[i].name);
           higherIncomeArtists[innerCounter].age=artists[i].age;
           strcpy(higherIncomeArtists[innerCounter].country,artists[i].country);
           higherIncomeArtists[innerCounter].income=artists[i].income;
           higherIncomeArtists[innerCounter].oscars=artists[i].oscars;
           innerCounter++;
       }
       if(innerCounter==higherIncomeArrSize)
       {
           higherIncomeArtists = realloc(higherIncomeArtists,SIZE*sizeof(Artist));
       }
   }
   return higherIncomeArtists;
}

Artist* ArtistsFromFile()
{
    FILE* fp;
    fp = fopen("artists.txt","r");
    char line[256];
    char* token;
    while(!feof(fp))
    {
        fscanf(fp,"%s",line);
        token=strtok(line,";");
        strcpy(fileArtists[fileArtistsCounter].name,token);
        token=strtok(NULL,";");
        fileArtists[fileArtistsCounter].age=atoi(token);
        token=strtok(NULL,";");
        strcpy(fileArtists[fileArtistsCounter].country,token);
        token=strtok(NULL,";");
        fileArtists[fileArtistsCounter].income=atof(token);
        token=strtok(NULL,";");
        fileArtists[fileArtistsCounter].oscars=atoi(token);
        fileArtistsCounter++;
    }
    fclose(fp);
    return fileArtists;
}

int main()
{
    Artist artists[SIZE];
    int command;
    printf("Enter command(0 - to add artist, 1 - to close):\n");
    scanf("%d",&command);
    while(command==0)
    {
        AddNewArtist(artists);
        printf("Enter command(0 - to add artist, 1 - to close):\n");
        scanf("%d",&command);
    }
    for(int i=0;i<counter;i++)
    {
        printf("Artist %d:\n",counter);
        printArtist(artists[i]);
    }
    higherIncomeArtists = (Artist*)malloc(sizeof(Artist)*higherIncomeArrSize);
    if(higherIncomeArtists==NULL)
    {
        printf("Couldn't allocate memory for the array!");
        return 1;
    }
    higherIncomeArtists = returnCertainIncomeArtistArray(artists,1000);
    for(int i=0;i<innerCounter;i++)
    {
        printArtist(higherIncomeArtists[i]);
        printf("\n");
    }
    free(higherIncomeArtists);

    fileArtists = (Artist*)malloc(sizeof(Artist)*SIZE);
    fileArtists = ArtistsFromFile();
    for(int i=0;i<fileArtistsCounter;i++)
    {
        printArtist(fileArtists[i]);
        NL;
    }
    free(fileArtists);
    return 0;
}
