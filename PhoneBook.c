#include<stdio.h>

void MainMenu();  // +
int AddPhoneNumber(); // +
void SearchPhoneBook(); // +
void DeletePhoneNumber();
void DisplayPhoneBook(); // +

void main()
{
    MainMenu();
}
void MainMenu()
{
    int choice;
    printf("\t****Main Menu****\n");
    printf("1)Add Phone Number\n");
    printf("2)Search Phone Book\n");
    printf("3)Delete Phone Number\n");
    printf("4)Display Phone Book\n");
    printf("Choose your Number\n");
   // printf("%d", findfileSize());
    scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            AddPhoneNumber();
            break;
        case 2:

            SearchPhoneBook();
            break;
        case 3:
            DeletePhoneNumber();
            break;
        case 4:
            DisplayPhoneBook();
            break;
        case 5:
            exit(0);

        default:
            MainMenu();
        }
}
int AddPhoneNumber()
{
    FILE *dosya;
    dosya = fopen("phonefile.txt", "a");
    char Name[1][50];
    char temp;
    char Mobile[1][11];

            printf("Enter Name: \n");
            scanf("%c", &temp);//temp statment to clear buffer,temp will store space taken after pressing number 1
            scanf("%[^\n]", Name[0]);//beacuse i hit enter when i choosed number 1 the compiler stored enter or null into string first and that why i use temp to avoid the problem
            printf("Enter Mobile Number: ");
            scanf("%10s", Mobile[0]);
            fprintf(dosya, "%s %s\n", Name[0],Mobile[0]);

    printf("%s %s deftere eklendi.\n" , Name[0],Mobile[0]);
  //  printf("%s %s\n", Name[1], Mobile[1]);
   // printf("%s %s\n", Name[2], Mobile[2]);
    fclose(dosya);
    MainMenu();
}
void SearchPhoneBook()
{

    char line[1024];
    char name[20];
    printf("Enter the name you want to search for: \n");
    scanf("%s", &name);
    FILE* fp = fopen("phonefile.txt", "r") ;
    while (fgets(line , sizeof(line) , fp )!= NULL){
    if (strstr(line , name )!= NULL){

        printf("%s",line);
      }
   }
    fclose(fp);


    MainMenu();
}
void DeletePhoneNumber()
{

    char line[1024];
    char name[20];
    char name2[20];
    printf("Enter the name you want to delete for: \n");
    scanf("%s", &name);
    FILE* fp = fopen("phonefile.txt", "r") ;
    FILE* fp2 = fopen("temp.txt", "w") ;
    while (fgets(line , sizeof(line) , fp )!= NULL){
    if (strstr(line , name )== NULL){
        fprintf(fp2, "%s", line);


        //printf("%s",line);
      }
   }

   fclose(fp);
  fclose(fp2);
  remove("phonefile.txt");
  rename("temp.txt", "phonefile.txt" );


    MainMenu();
}
void DisplayPhoneBook()
{
   FILE *dosya;
   char line[findfileSize()] ;
   dosya = fopen("phonefile.txt", "r") ;
   while (fgets(line, sizeof(line), dosya)) {

        printf("%s", line);
    }
    fclose(dosya);
    MainMenu();
}


int findfileSize() {
   FILE* dosya = fopen("phonefile.txt", "r"); // opening a file in read mode
   char chr = getc(dosya);
   int count_lines=0;
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(dosya);
    }
   fclose(dosya); //closing the file
   return count_lines;
}
