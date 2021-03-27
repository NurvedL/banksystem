#include <stdio.h>
#include <stdlib.h>

#define USER_MAX 20


typedef struct
{
    char name[10];
    char password[10];
} User;


User list[USER_MAX];


char* filename = "user.txt";

int i;






// Log function
User login()
{
    char name[10];
    char password[10];
    User lg;
    printf("enter name:");
    scanf("%s",name);
    strcpy(lg.name , name);
    printf("enter password:");
    scanf("%s",password);
    strcpy(lg.password,password);
    return lg;

}

// write txt file, there is a row for each user
void writeToFile(User u)
{
    FILE *fw = fopen(filename,"a+");
    fprintf(fw,u.name);
    fprintf(fw,"\t");
    fprintf(fw,u.password);
    fprintf(fw,"\n");
}

// determine whether the user exists
int exist(User u)
{
    int i;
    for(i=0; i<USER_MAX; i++)
    {
        if(0==strcmp(list[i].name ,u.name) && 0==strcmp(list[i].password ,u.password))
        {
            return 1;
        }
    }
    return -1;
}

//registered user
void registerUser()
{
    char name[10];
    char password[10];
    User user;
    int i;

    printf("enter your name:");
    scanf("%s",name);
    strcpy(user.name , name);

    // determine whether there has been a registered user
    for(i=0; i<USER_MAX; i++)
    {
        if(0==strcmp(list[i].name ,name))
        {
            printf("USER ALREADY EXIST");
            return;
        }
    }

    printf("enter your password:");
    scanf("%s",password);
    strcpy(user.password , password);
    writeToFile(user);
}

int menu()
{
    int choice;
    printf("1.login\n");
    printf("2.register\n");
    printf("#.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    return choice;
}




int main()
{ 
  char choice[100];
  char ChoiceBank[100];
  int balance;
  printf("Choose an option: \n");
  printf("Bank\n");
  printf("Shop\n");

  scanf("%s", choice);


  if (strcmp(choice, "Bank") == 0 || strcmp(choice, "bank") == 0) {
    User test[USER_MAX];
    FILE *fp = fopen(filename,"r");
    int i=0;
    User u;
    if(NULL == fp)
    {
        printf("FILE NOT FOUND");
        return -1;
    }
    for(i=0; i<USER_MAX; i++)
    {
        char uname[10];
        char upassword[10];
        fscanf(fp,"%s%s",uname,upassword);

        strcpy(list[i].name , uname);
        strcpy(list[i].password , upassword);
    }

    int choice = menu();
    if(1 == choice)
    {
        system("cls");
        u=login();
        if(1 == exist(u))
        {
            printf("Choose an option: \n");
            printf("1. Balance\n");


            scanf("%s", ChoiceBank);

            if (strcmp(ChoiceBank, "Balance") == 0 || strcmp(ChoiceBank, "balance")) {
                           
                FILE *filePointer ; 

                char balance[50]; 
  
                filePointer = fopen("balance.txt", "r") ; 
      
                if ( filePointer == NULL ) 
                    { 
                    printf( "balance.txt file failed to open." ) ; 
                    } 
                else
                    { 
                    while( fgets ( balance, 50, filePointer ) != NULL ) 
                        { 
          
            
                            printf( "%s\n" , balance ) ; 
                            printf("%s\n", u.name);
            

                        } 
          
        
                    fclose(filePointer) ; 
          

    } 
    return 0;         
                }
        }
    }    
    else if(2 == choice)
    {
        system("cls");
        registerUser();
    }
    else
    {
        return 0;
    }
  
}
}
