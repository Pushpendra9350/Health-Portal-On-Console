#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#define ENTER 13
COORD c= {0,0};
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
    
}
int next(int );
void enter();
void log_in();
void sign_up();
void searchinfo();
void search_all();
void welcome();
void heading();
int menu(int);
int again_menu(int);
char gender(char);
void age_group(int);
void goals();
int goal_select(int );
int get_active(int);
float bmi(float,float);
float calorie(float,float,float);
void fat_lose_meal_nonveg();
void fat_lose_meal_veg();
int fat_lose_workout(int);
int fat_lose(int);
int howto(int );
int home(int );
void gain_muscle_meal(int );
void muscle_gain_workout(int );
int muscle_gain(int i) ;
int  massup_workout(int );
int  massup_meal(int );
int massup(int);
struct members
{
    char name[20];
    char pass[20];
    int age;
    char first_date[20];
    char mobile[20];
    char address[20];
};
void main()
{
    int i;
    welcome();
}
int next(int i)
{
    system("COLOR 2F");
    struct  members s;
    int p,a;
    while(1)
    {
        heading();
        for(i=209; i>=0; i--)
        {
            gotoxy(i,26);
            printf("%c",196);
            delay(5);
        }
        printf("\n\n\n\n");
        gotoxy(90,17);
        printf("   CREATE NEW ACCOUNT");
        gotoxy(88,20);
        printf("    LOGIN TO YOUR ACCOUNT\n");
        gotoxy(88,23);
        printf("      Enter a choice:");
        gotoxy(90,28);
        printf("CREATE ACCOUNT : press 1");
        gotoxy(90,29);
        printf("LOGIN          : press 2");
        gotoxy(110,23);
        scanf("%d",&p);
        system("cls");
        switch(p)
        {
        case 1:
            heading();
            printf("\n\n\n");
            sign_up();
            break;
        case 2:
            heading();
            printf("\n\n\n");
            log_in();
            break;
        default:
            heading();
            printf("\n\t\t\t\t\t\t\t\t                                Wrong choice\n\n");
        }
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\n\t\t\t\t\t\t\t                                 To continue : press ANY key");
        printf("\n\t\t\t\t\t\t\t                                    For Exit : press 0\n");
        printf("\t\t\t\t\t\t\t                                 ");
        scanf("%d",&a);
        if(a==0)
            break;
        system("cls");
    }
}

void gotoxy(int x,int y)
{
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void log_in()
{
    char name[20];
    char pass[20];
    char ch;
    int i=0,c=0;
    struct  members s;
    FILE *fp;
    fp=fopen("prog.txt","r");
    //gotoxy(90,15);
    printf("\n\t\t\t\t\t\t\t                                   Username:\t");

    scanf("%s",&name);
    printf("\n\n\t\t\t\t\t\t\t                                   password:\t");

    while(1)
    {

        ch=getch();
        if(ch==13)
        {
            pass[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }

        }
        else if(ch==32||ch==9)
        {
            continue;
        }
        else
        {
            pass[i]=ch;
            i++;
            printf("*");
        }
    }

    while(fscanf(fp,"%s\t%s",s.name,s.pass)!=-1)
    {
        if(strcmp(name,s.name)==0)
        {
            if(strcmp(pass,s.pass)==0)
            {
                c=1;
                for(i=209; i>=0; i--)
                {
                    gotoxy(i,22);
                    printf("%c",196);
                    delay(5);
                }
                menu(i);
            }
            else
            {
                c=1;
                printf("\n\n\t\t\t\t\t\t\t                                 Your password is wrong");
                for(i=0; i<=209; i++)
                {
                    gotoxy(i,24);
                    printf("%c",196);
                }
            }
        }
    }


    if(c==0)
    {
        printf("\n\n\n\t\t\t\t\t\t\t                               You are NOT registered here!!");
        for(i=0; i<=209; i++)
        {
            gotoxy(i,24);
            printf("%c",196);
        }
    }
    fclose(fp);

}

void sign_up()
{
    int p;
    int i=0;
    struct  members s;
    char ch;
    FILE *fp;
    fp=fopen("prog.txt","a");
    printf("\n\t\t\t\t\t\t\t\t                              APPLICATION FORM");
    printf("\n\t\t\t\t\t\t\t\t                              ________________\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tEnter name(without space):\t\t");
    scanf("%s",s.name);
    printf("\n\n\t\t\t\t\t\t\t\t\tEnter password(less than 8 char.):\t\t");
    // gotoxy(112,3);
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            s.pass[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if(ch==32||ch==9)
        {
            continue;
        }
        else
        {
            s.pass[i]=ch;
            i++;
            printf("*");
        }
    }
    printf("\n\n\n\t\t\t\t\t\t\t\t\t   Enter your age(same as,age=20):\t\t");
    scanf("%d",&s.age);
    printf("\n\n\t\t\t\t\t\t\t\t\t   Enter today's date(dd/mm/yyyy):\t\t");
    scanf("%s",s.first_date);
    printf("\n\n\t\t\t\t\t\t\t\t        Enter your mobile no(without +91):\t\t");
    scanf("%s",s.mobile);
    printf("\n\n\t\t\t\t\t\t\t\t       Enter your address(only city name):\t\t");
    scanf("%s",s.address);
    fprintf(fp,"\n%s",s.name);
    fprintf(fp,"\t%s",s.pass);
    fprintf(fp,"\t%d",s.age);
    fprintf(fp,"\t%s",s.first_date);
    fprintf(fp,"\t%s",s.mobile);
    fprintf(fp,"\t%s",s.address);
    fclose(fp);

    system("cls");
    heading();
    printf("\n\n\t\t\t\t\t\t\t\t                           SUCCESSFULLY REGISTERED\n");
    printf("\n\n\t\t\t\t\t\t\t\t                            Username : %s",s.name);
    printf("\n\t\t\t\t\t\t\t\t                            Password : %s",s.pass);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t                 Please note down username and password for login\n");
    for(i=209; i>=0; i--)
    {
        gotoxy(i,24);
        printf("%c",196);
        delay(5);
    }
    menu(i);
}

void searchinfo()
{
    struct  members s;
    int i;
    char name[20];
    char pass[20];
    char ch;
    FILE *fp;
    fp=fopen("prog.txt","r");
    printf("\n\n\t\t\t\t\t\t\t                                Enter name:\t\t");
    scanf("%s",name);
    while(fscanf(fp,"%s\t%s\t%d\t%s\t%s\t%s\n",s.name,s.pass,&s.age,s.first_date,s.mobile,s.address)!=-1)
    {
        if(strcmp(name,s.name)==0)
        {
            printf("\n\n\t\t\t\t\t\t\t                               Your age is:\t\t%d",s.age);
            printf("\n\n\t\t\t\t\t\t\t                        Date of joining is:\t\t%s",s.first_date);
            printf("\n\n\t\t\t\t\t\t\t                             Mobile no. is:\t\t%s",s.mobile);
            printf("\n\n\t\t\t\t\t\t\t                                 Living in:\t\t%s",s.address);
        }
    }
    fclose(fp);
    printf("\n\n");
    again_menu(i);
}

void search_all()
{
    int i,r,q;
    system("cls");
    heading();
    gotoxy(25,15);
    printf("Loading.");
    gotoxy(25,16);
    for(r=1; r<=15; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",178);
    }
    system("cls");
    heading();
    system("COLOR 2F");
    printf("\n\n");
    char c;
    struct members s;
    FILE *fp;
    fp=fopen("prog.txt","r");
    c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);
}

void welcome()
{
    int i,r,q;
    char ch;
    system("cls");
     gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=20; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
    system("cls");
    system("COLOR F2");



    gotoxy(47,0);
    printf("%c",201);
    for(i=48; i<165; i++)
    {
        gotoxy(i,0);
        printf("%c",205);
        delay(15);
    }
    gotoxy(165,0);
    printf("%c",187);
    for(i=1; i<10; i++)
    {
        gotoxy(165,i);
        printf("%c",186);
        printf("\n");
        delay(15);
    }
    gotoxy(165,10);
    printf("%c",188);
    for(i=164; i>=48; i--)
    {
        gotoxy(i,10);
        printf("%c",205);
        delay(15);
    }
    gotoxy(47,10);
    printf("%c",200);
    for(i=9; i>=1; i--)
    {
        gotoxy(47,i);
        printf("%c",186);
        delay(15);
    }

    gotoxy(51,3);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(51,4);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(51,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(51,6);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(51,7);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(63,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(63,4);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(63,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(63,6);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(63,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(73,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(73,4);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(73,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(73,6);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(73,7);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(85,3);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(85,4);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(85,5);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(85,6);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(85,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(94,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(97,4);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(97,5);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(97,6);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(97,7);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(104,3);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(104,4);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(104,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(104,6);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(104,7);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(122,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(122,4);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(122,5);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(122,6);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(122,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(132,3);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(132,4);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(132,5);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(132,6);
    printf("\xDB\xDB\n");
    delay(20);
    gotoxy(132,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(141,3);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(141,4);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(141,5);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(141,6);
    printf("\xDB\xDB      \xDB\xDB\n");
    delay(20);
    gotoxy(141,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(153,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(153,4);
    printf("\xDB\xDB     \xDB\xDB\n");
    delay(20);
    gotoxy(153,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(153,6);
    printf("\xDB\xDB     \xDB\xDB\n");
    delay(20);
    gotoxy(153,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    delay(20);
    gotoxy(16,5);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(19,4);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(19,5);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(19,6);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(22,3);
    printf("\xDB\xDB         \xDB\xDB");
    delay(20);
    gotoxy(22,4);
    printf("\xDB\xDB         \xDB\xDB");
    delay(20);
    gotoxy(22,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    delay(20);
    gotoxy(22,6);
    printf("\xDB\xDB         \xDB\xDB");
    delay(20);
    gotoxy(22,7);
    printf("\xDB\xDB         \xDB\xDB");
    delay(20);
    gotoxy(36,4);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(36,5);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(36,6);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(39,5);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(172,5);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(175,4);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(175,5);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(175,6);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(178,3);
    printf("\xDB\xDB         \xDB\xDB");
    delay(20);
    gotoxy(178,4);
    printf("\xDB\xDB         \xDB\xDB");
    delay(20);
    gotoxy(178,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    delay(20);
    gotoxy(178,6);
    printf("\xDB\xDB         \xDB\xDB");
    delay(20);
    gotoxy(178,7);
    printf("\xDB\xDB         \xDB\xDB");
    delay(20);
    gotoxy(192,4);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(192,5);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(192,6);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(195,5);
    printf("\xDB\xDB");
    delay(20);
    gotoxy(95,11);
    printf("FITNESS HEALTH CLUB");
    for(i=209; i>=0; i--)
    {
        gotoxy(i,13);
        printf("%c",196);
        delay(12);
    }
    gotoxy(180,14);
    printf("designed by-PUSHPENDRA KUMAR");

    for(i=0; i<=209; i++)
    {
        gotoxy(i,45);
        printf("%c",196);
        delay(12);
    }
    gotoxy(20,16);
    printf("%c",254);
    printf("\tA Health club is a place that houses exercise equipment for the purpose of physical exercise.");
    delay(20);
    gotoxy(20,18);
    printf("%c",254);
    printf("\tFITNESS HEALTH CLUB is one of the newest health club in Ghaziabad");
    delay(20);
    gotoxy(20,20);
    printf("%c",254);
    printf("\tFACILITIES");
    delay(20);
    gotoxy(40,20);
    printf(". Free WIFI");
    delay(20);
    gotoxy(40,21);
    printf(". Free parking");
    delay(20);
    gotoxy(40,22);
    printf(". Personal trainers");
    delay(20);
    gotoxy(40,23);
    printf(". Lockers");
    delay(20);
    gotoxy(40,24);
    printf(". Changing room");
    delay(20);
    gotoxy(20,26);
    printf("%c",254);
    printf("\tRULES");
    delay(20);
    gotoxy(40,26);
    printf(". Don't drink too much water b/w exercises");
    delay(20);
    gotoxy(40,27);
    printf(". Do stay at home if you are sick");
    delay(20);
    gotoxy(40,28);
    printf(". sleep at least 7 hours");
    delay(20);
    gotoxy(40,29);
    printf(". Take proper food");
    delay(20);
    gotoxy(40,30);
    printf(". Do dress appropriately");
    delay(20);
    gotoxy(20,35);
    printf("%c",218);
    for(i=21; i<=26; i++)
    {
        gotoxy(i,35);
        printf("%c",196);
        delay(15);
    }
    gotoxy(27,35);
    printf("%c",191);
    gotoxy(27,36);
    printf("%c",179);
    gotoxy(27,37);
    printf("%c",217);
    for(i=26; i>=21; i--)
    {
        gotoxy(i,37);
        printf("%c",196);
        delay(50);

    }
    gotoxy(20,36);
    printf("%c",179);
    gotoxy(20,37);
    printf("%c",192);
    gotoxy(22,36);
    printf("NOTE");
    delay(20);
    gotoxy(32,36);
    printf("YOU ARE BORN WEAK AND DIE WEAK, WHAT YOU ARE IN BETWEEN THOSE TWO PERIODS OF TIME IS UP TO YOU");
    delay(20);


    gotoxy(20,40);
    printf("%c",218);
    for(i=21; i<=26; i++)
    {
        gotoxy(i,40);
        printf("%c",196);
        delay(15);
    }
    gotoxy(27,40);
    printf("%c",191);
    gotoxy(27,41);
    printf("%c",179);
    gotoxy(27,42);
    printf("%c",217);
    for(i=26; i>=21; i--)
    {
        gotoxy(i,42);
        printf("%c",196);
        delay(50);

    }
    gotoxy(20,41);
    printf("%c",179);
    gotoxy(20,42);
    printf("%c",192);
    gotoxy(22,41);
    delay(20);
    printf("HELP");
    delay(20);
    gotoxy(32,41);
    printf("if you want to do OK then press ENTER for INSTRUCTIONS see after bottom line");
    delay(20);
    gotoxy(90,47);
    printf("TO Continue : press ENTER");
    delay(20);
    system("COLOR 2F");
    ch=getch();
    if(ch==ENTER)
    {
        next(i);
    }
    else
    {
        gotoxy(93,49);
        printf("wrong choice\n\n");
        gotoxy(90,51);
        enter();

    }
}
void enter()
{
    int i;
    char ch;
     printf("TO Continue : press ENTER");
    delay(20);
    system("COLOR 2F");
    ch=getch();
    if(ch==ENTER)
    {
        next(i);
    }
    else
    {
        gotoxy(93,49);
        printf("wrong choice\n\n");
        gotoxy(90,51);
       enter();
    }
}
void heading()
{
    int i;
    system("cls");
    system("COLOR F2");
    gotoxy(47,0);
    printf("%c",201);
    for(i=48; i<165; i++)
    {
        gotoxy(i,0);
        printf("%c",205);

    }
    gotoxy(165,0);
    printf("%c",187);
    for(i=1; i<10; i++)
    {
        gotoxy(165,i);
        printf("%c",186);
        printf("\n");

    }
    gotoxy(165,10);
    printf("%c",188);
    for(i=164; i>=48; i--)
    {
        gotoxy(i,10);
        printf("%c",205);

    }
    gotoxy(47,10);
    printf("%c",200);
    for(i=9; i>=1; i--)
    {
        gotoxy(47,i);
        printf("%c",186);

    }

    gotoxy(51,3);
    printf("\xDB\xDB      \xDB\xDB\n");

    gotoxy(51,4);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(51,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(51,6);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(51,7);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(63,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(63,4);
    printf("\xDB\xDB");
    gotoxy(63,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(63,6);
    printf("\xDB\xDB");
    gotoxy(63,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(73,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(73,4);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(73,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(73,6);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(73,7);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(85,3);
    printf("\xDB\xDB\n");
    gotoxy(85,4);
    printf("\xDB\xDB\n");
    gotoxy(85,5);
    printf("\xDB\xDB\n");
    gotoxy(85,6);
    printf("\xDB\xDB\n");
    gotoxy(85,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(94,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(97,4);
    printf("\xDB\xDB\n");
    gotoxy(97,5);
    printf("\xDB\xDB\n");
    gotoxy(97,6);
    printf("\xDB\xDB\n");
    gotoxy(97,7);
    printf("\xDB\xDB\n");
    gotoxy(104,3);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(104,4);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(104,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(104,6);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(104,7);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(122,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(122,4);
    printf("\xDB\xDB\n");
    gotoxy(122,5);
    printf("\xDB\xDB\n");
    gotoxy(122,6);
    printf("\xDB\xDB\n");
    gotoxy(122,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(132,3);
    printf("\xDB\xDB\n");
    gotoxy(132,4);
    printf("\xDB\xDB\n");
    gotoxy(132,5);
    printf("\xDB\xDB\n");
    gotoxy(132,6);
    printf("\xDB\xDB\n");
    gotoxy(132,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(141,3);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(141,4);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(141,5);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(141,6);
    printf("\xDB\xDB      \xDB\xDB\n");
    gotoxy(141,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(153,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(153,4);
    printf("\xDB\xDB     \xDB\xDB\n");
    gotoxy(153,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(153,6);
    printf("\xDB\xDB     \xDB\xDB\n");
    gotoxy(153,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(16,5);
    printf("\xDB\xDB");
    gotoxy(19,4);
    printf("\xDB\xDB");
    gotoxy(19,5);
    printf("\xDB\xDB");
    gotoxy(19,6);
    printf("\xDB\xDB");
    gotoxy(22,3);
    printf("\xDB\xDB         \xDB\xDB");
    gotoxy(22,4);
    printf("\xDB\xDB         \xDB\xDB");
    gotoxy(22,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(22,6);
    printf("\xDB\xDB         \xDB\xDB");
    gotoxy(22,7);
    printf("\xDB\xDB         \xDB\xDB");
    gotoxy(36,4);
    printf("\xDB\xDB");
    gotoxy(36,5);
    printf("\xDB\xDB");
    gotoxy(36,6);
    printf("\xDB\xDB");
    gotoxy(39,5);
    printf("\xDB\xDB");
    gotoxy(172,5);
    printf("\xDB\xDB");
    gotoxy(175,4);
    printf("\xDB\xDB");
    gotoxy(175,5);
    printf("\xDB\xDB");
    gotoxy(175,6);
    printf("\xDB\xDB");
    gotoxy(178,3);
    printf("\xDB\xDB         \xDB\xDB");
    gotoxy(178,4);
    printf("\xDB\xDB         \xDB\xDB");
    gotoxy(178,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(178,6);
    printf("\xDB\xDB         \xDB\xDB");
    gotoxy(178,7);
    printf("\xDB\xDB         \xDB\xDB");
    gotoxy(192,4);
    printf("\xDB\xDB");
    gotoxy(192,5);
    printf("\xDB\xDB");
    gotoxy(192,6);
    printf("\xDB\xDB");
    gotoxy(195,5);
    printf("\xDB\xDB");
    gotoxy(93,11);
    printf("FITNESS HEALTH CLUB");
    for(i=209; i>=0; i--)
    {
        gotoxy(i,12);
        printf("_");
    }
}
//to making menu function
int menu(int i)
{
    char ch,p;
    printf("\n\t\t\t\t\t\t\t                                 To continue : press ENTER\t");

    p=getch();
    if(p==ENTER)
    {
        system("cls");
        heading();
    }
    else
    {
        system("cls");
        heading();
        printf("\n\n\t\t\t\t\t\t\t                                      wrong choice\n\n");
        menu(i);
    }
    printf("\n\n\t\t\t\t\t\t\t\tEnter your Gender(m/f or male/female):\t");
    scanf("%s",&ch);
    gender(ch);
}
//to making again menu

int again_menu(int i)
{
    char ch;
    int g;
    printf("\n\n");
    for(i=0; i<=209; i++)
    {
        printf("%c",196);
    }
    printf("\n\n\t\t\t\t\t\t\t\t                         \xDC  SELECT YOUR GOAL   : press 1");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t                         \xDC  START AGAIN        : press 2");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t                         \xDC  DETAIL OF A MEMBER : press 3");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t                         \xDC  SHOW ALL MEMBERS   : press 4");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t                         \xDC  EXIT               : press 5\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t                            Enter a choice     :\t");
    scanf("%d",&i);
    switch(i)
    {

    case 1:
        goals();
        goal_select(g);
        break;
    case 2:
        welcome();
        break;
    case 3:
        system("cls");
        heading();
        searchinfo();
        break;
    case 4:
        search_all();
        again_menu(i);
        break;
    case 5:
        printf("\n\t\t\t\t\t\t\t                                   THANKS FOR USING PROGRAMS\n\n");
        break;

    default:
        printf("\n\n\n\t\t\t\t\t\t\t\t                                  WRONG CHOICE\n\n");
        again_menu(i);
    }
}
// To making gender function
char gender(char ch)
{
    int a,g;
    if(ch=='m'||ch=='M')
    {
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\tyour AGE GROUP is:\t");
        age_group(a);

    }
    else if(ch=='f'||ch=='F')
    {
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\tyour AGE GROUP is:\t");
        age_group(a);

    }
    else
    {
        printf("\n\n\n\t\t\t\t\t\t\t                                    Wrong choice\n\n");
        printf("\n\n\t\t\t\t\t\t\t\tEnter your Gender(m/f or male/female):\t");
        scanf("%s",&ch);
        gender(ch);

    }
}
//To enter the age group
void age_group(int a)
{
    int g;
    printf("1-   Teenager\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t2-   Adult\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        goals();
        goal_select(g);
        break;
    case 2:
        goals();
        goal_select(g);
        break;
    default:
        printf("\n\n\n\t\t\t\t\t\t\t                               Unknown age group\n\n");
        printf("\n");
        printf("\t\t\t\t\t\t\t\t\tyour AGE GROUP is:\t");
        age_group(a);
    }
}
//to select th goals
int goal_select(int g)
{
    int i,m;
    float kilo,cm,age;
    scanf("%d",&g);
    if(g==1)
    {
        system("cls");
        get_active(i);
        again_menu(i);
    }
    else if(g==2)
    {
        home(i);
    }

    else if(g==3)
    {
        fat_lose(i);
    }

    else if(g==4)
    {
        muscle_gain(i) ;
    }

    else if(g==5)
    {
        massup(i);
    }
    else if(g==6)
    {
        system("cls");
        heading();
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t                                     CALORIE CALCULATOR\n\n");
        printf("\n\t\t\t\t\t\t\t                                      BMI CALLCULATOR\n\n\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\t\t\t\t\t\t\t\t                            CALORIE       : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t                            BMI           : press 2\n");
        printf("\n\t\t\t\t\t\t\t\t                            Enter a choice:\t");
        scanf("%d",&m);
        if(m==1)
        {
            system("cls");
            calorie(kilo,cm,age);
        }
        else if(m==2)
        {
            system("cls");
            bmi(kilo,cm);
        }
        else
        {
            system("Cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            printf("\n\n");
            again_menu(i);
        }
    }
    else
    {
        system("cls");
        printf("\n\t\t\t\t\t\t\t                                 Wrong choice\n\n");
        goals();
        goal_select(i);
    }
}

int fat_lose(int i)
{

    system("cls");
    heading();
    printf("\n\n\n\t\t\t\t\t\xDC WORKOUT PLANS\t\t");
    printf("        < this workout plan based on daily routine,follow it day by day at least 3 months >\n");
    delay(30);
    printf("\n\n\t\t\t\t\t\xDC DIET PLANS\t\t");
    printf("        < this diet plan based on full day routine,follow it day by day at least 3 months >\n");
    delay(30);
    printf("\n\n\t\t\t\t\t\xDc HOW TO EXERCISE\t\t");
    printf("< if you don't know how to exercise those mention in workout plan you can it >\n\n\n");
    delay(30);
    for(i=0; i<=209; i++)
    {
        printf("%c",196);
        delay(5);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  WORKOUT PLAN   : press 1");
    delay(30);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  DIET PLAN      : press 2");
    delay(30);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  HOW TO EXERCISE: press 3");
    delay(30);
    system("COLOR 2F");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  Enter a choice :\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        heading();
        printf("\n\n");
        fat_lose_workout(i);
        break;
    case 2:
        system("cls");
        heading();
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tVEGITARIAN\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t      NON VEGITATIAN\n\n\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tVEGITARIAN     : press 1");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tNON VEGITATIAN : press 2");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            heading();
            printf("\n\n");
            fat_lose_meal_veg(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            printf("\n\n");
            fat_lose_meal_nonveg(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t                                Wrong choice\n\n");
            again_menu(i);
        }
        break;
    case 3:
        howto(i);
        break;
    default:
        system("cls");
        heading();
        printf("\n\n\t\t\t\t\t\t\t\t                                Wrong choice\n\n");
        again_menu(i);
        break;


    }
}

void goals()
{
    int i;
    system("cls");
    heading();
    printf("\n\n\n\t\t\t\t\t\t\t\t\t                      Select your GOAL\n");
    printf("\t\t\t\t\t\t\t\t                              ________________");
    printf("\n\n\t\t\t\t\t\xDC   GET ACTIVE\t\t");
    printf("        < To get more active in whole day you can do all these exercises in 8-10 minutes >\n\n\n");
    delay(50);
    printf("\t\t\t\t\t\xDC   HOME WORKOUT\t\t");
    printf("< If you want to do exercises at your home than you can do any type of exercise >\n\n\n");
    delay(50);
    printf("\t\t\t\t\t\xDC   LOSE FAT/WEIGHT\t\t");
    printf("< If your weight is more according to YOU  can follow all these workout and diet plans >\n\n\n");
    delay(50);
    printf("\t\t\t\t\t\xDC   GAIN MUSCLE SIZE\t\t");
    printf("< If you want looking more muscular than you can follow all these workout and diet plan >\n\n\n");
    delay(50);
    printf("\t\t\t\t\t\xDC   GAIN SIZE/WEIGHT\t\t");
    printf("< If your weight is less than normal weight so you must follow these workout and diet plans >\n\n\n");
    delay(50);
    printf("\t\t\t\t\t\xDC   CALCULATORS\t\t");
    printf("        < To calculate your BMI(body mas index) or calories/day to maintain your weight >\n\n\n");
    delay(50);
    for(i=209; i>=0; i--)
    {
        gotoxy(i,37);
        printf("%c",196);
        delay(5);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t                    GET ACTIVE : press 1");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t                  HOME WORKOUT : press 2");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t               LOSE FAT/WEIGHT : press 3");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t              GAIN MUSCLE SIZE : press 4");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t              GAIN SIZE/WEIGHT : press 5");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t                    CALCULATOR : press 6");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t                Enter a choice :\t");
    system("COLOR 2F");
}

float bmi(float kilo,float cm)
{
    float bmi;
    int i;
    heading();
    printf("\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t Enter your WEIGHT (in kilograms)   :\t");
    scanf("%f",&kilo);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t Enter your HEIGHT (in centimeters) :\t");
    scanf("%f",&cm);
    bmi=(kilo/pow(cm,2))*10000;
    printf("\n\n\t\t\t\t\t\t\t\t\t\t YOUR BMI IS                        :\t%f",bmi);
    printf("\n");
    if(bmi<18.5)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t Weight status                      :\tUNDERWEIGHT");
        printf("\n\n");
        again_menu(i);
    }
    else if(bmi>=18.6&&bmi<=24.9)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t Weight status                      :\tNORMAL WEIGHT");
        printf("\n\n");
        again_menu(i);
    }
    else if(bmi>=25&&bmi<=29.9)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t Weight status                      :\tOVERWEGHT");
        printf("\n\n");
        again_menu(i);
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t Weight status                      :\tOBESITY");
        printf("\n\n");
        again_menu(i);
    }
}

float calorie(float kilo,float cm,float age)
{
    float cal;
    int i;
    heading();
    printf("\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t   Enter your weight in kilograms  :\t");
    scanf("%f",&kilo);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t   Enter your height in centimeters:\t");
    scanf("%f",&cm);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t   Enter your age                  :\t");
    scanf("%d",&age);
    printf("\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t   1-Male\n");
    printf("\t\t\t\t\t\t\t\t\t\t   2-Female\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t   your gender :\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        cal=66.47+(kilo*13.75)+(5*cm)-(6.75*age);
        printf("\n\t\t\t\t\t\t\t\t\t\t   To maintain your weight         : %f cal/day.",cal);
        printf("\n\n");
        again_menu(i);
        break;
    case 2:
        cal=665.09+(9.56*kilo)+(1.84*cm)-(4.67*age);
        printf("\n\t\t\t\t\t\t\t\t\t\t   To maintain your weight         : %f cal/day.",cal);
        printf("\n\n");
        again_menu(i);
    default:
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice");
        again_menu(i);
    }

}


int get_active(int i)
{
    /* printf("\t\t\tSearching");
     for(i=0; i<3; i++)
     {
         delay(1000);
         printf(".");
     }
     */
    heading();
    int r,q;
    gotoxy(25,15);
    printf("Loading.");
    gotoxy(25,16);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",178);
    }
    system("cls");
    heading();
    system("COLOR 2F");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t      YOUR EXERCISES ARE\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t      __________________");
    delay(20);
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  High Knees                |   45sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Rest                      |   15sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Left arm rotation         |   25sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Right arm rotation        |   25sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  both arm rotation         |   30sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Rest                      |   15sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Back extension v2         |   35sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Back lateral flexion      |   35sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Rest                      |   20sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Burpees                   |   40sec  |\n");
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  rest                      |   30sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Pushups on knees          |   40sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Rest                      |   25sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Triceps push down on chair|   40sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Rest                      |   30sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |  Back suryanamaskar stretch|   30sec  |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t   |      Thanks for using our plan        |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t   ");
    for(i=1; i<42; i++)
    {
        printf("%c",196);
    }
    delay(20);
}

int home(int i)
{
    int r,q;
    system("cls");
    heading();
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t    \xDC  CLASSIC 7 MINUTES WORKOUT ");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    \xDC  FULL BODY IN 3 MINUTES");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    \xDC  STRENGTHEN BODY PLAN ");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    \xDC  STRENGTHEN BODY PLAN ");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    \xDC  TONE ABS IN 5 MINUTES");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    \xDC  UPPER BODY IN 5 MINUTES");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t    \xDC  ATTRACTIVE ARMS IN 7 MINUTES");
    delay(20);
    printf("\n\n");
    for(i=209; i>=0; i--)
    {
        gotoxy(i,29);
        printf("%c",196);
        delay(3);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t CLASSIC 7 MINUTES WORKOUT  : press 1");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t FULL BODY IN 3 MINUTES     : press 2");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t STRENGTHEN BODY PLAN       : press 3");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t STRENGTHEN BODY PLAN       : press 4");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t TONE ABS IN 5 MINUTES      : press 5");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t UPPER BODY IN 5 MINUTES    : press 6");
    delay(20);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t ATTRACTIVE ARM IN 7 MINUTES: press 7");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t      Enter a choice        :\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t         THIS IS YOUR EXERCISE PLAN\n");
        printf("\t\t\t\t\t\t\t\t\t\t         __________________________");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  jumping jacks             |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  wall sit                  |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  push-ups                  |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  abdominal crunches        |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  step-up onto chair        |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  squats                    |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  triceps dips              |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  plank                     |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  high stepping             |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  altenating lunges         |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  push-ups & rotation       |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  side plank right          |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  side plank left           |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |      Thanks for using our plan        |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        system("COLOR 2F");
        again_menu(i);
        break;
    case 2:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t         THIS IS YOUR EXERCISE PLAN\n");
        printf("\t\t\t\t\t\t\t\t\t\t         __________________________");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  jumping jacks             |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  bicycle crunches          |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  push-ups                  |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  alternating lunges        |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        system("COLOR 2F");
        again_menu(i);
        break;
    case 3:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t         THIS IS YOUR EXERCISE PLAN\n");
        printf("\t\t\t\t\t\t\t\t\t\t         __________________________");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  squat kicks               |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  triceps dips              |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  high crunch               |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  decline push-ups          |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  chair                     |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  jumping squats            |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  side plank front kick left|   20sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   | side plank front kick right|   20sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  crab kicks                |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  mountain climber          |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        system("COLOR 2F");
        again_menu(i);

        break;
    case 4:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t         THIS IS YOUR EXERCISE PLAN\n");
        printf("\t\t\t\t\t\t\t\t\t\t         __________________________");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  burpees                   |   50sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  squats kick back          |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  v crunch                  |   25sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  up and down plank         |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  bicycle crunches          |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  staggered push-uos        |   20sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  bulgarian split squatsleft|   20sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   | bulgarian split squat right|   20sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  plank and reach           |   20sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  superman                  |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        system("COLOR 2F");
        again_menu(i);

        break;
    case 5:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t         THIS IS YOUR EXERCISE PLAN\n");
        printf("\t\t\t\t\t\t\t\t\t\t         __________________________");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  mountain climber          |   60sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  straight-arm plank        |   60sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  plank                     |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  side plank left           |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  right plank right         |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  plank leg up              |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  up and down plank         |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        system("COLOR 2F");
        again_menu(i);
        break;
    case 6:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t         THIS IS YOUR EXERCISE PLAN\n");
        printf("\t\t\t\t\t\t\t\t\t\t         __________________________");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  staggered push-upd        |   15sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  push-ups & rotation       |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  triceps dips              |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  russian twist             |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  wood chops                |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  bridge plank              |   60sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  incline push-ups          |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        system("COLOR 2F");
        again_menu(i);
        break;
    case 7:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t         THIS IS YOUR EXERCISE PLAN\n");
        printf("\t\t\t\t\t\t\t\t\t\t         __________________________");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  arm cicle clockwise       |   80sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  arm circle anti clockwise |   80sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  floor triceps dips        |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  chest press pulls         |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  clockwise arm swings      |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  up and down plank         |   30sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t\t\t   |  anticlockwise arm swings  |   40sec  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t\t\t   ");
        for(i=1; i<42; i++)
        {
            printf("%c",196);
        }
        delay(20);
        system("COLOR 2F");
        again_menu(i);
        break;
    default:
        system("cls");
        heading();
        printf("\n\n\t\t\t\t\t\t\t\t                                 Wrong choice\n\n");
        again_menu(i);
    }
}



void fat_lose_meal_nonveg()
{
    int i,r,q;
    gotoxy(25,15);
    printf("Loading.");
    gotoxy(25,16);
    for(r=1; r<=15; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",178);
    }
    system("cls");
    heading();
    system("COLOR 2F");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t                            ***| MEAL PLAN |***                           \n");
    printf("\t\t\t\t\t\t\t\t                                ___________                               \n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |      TIME       |      NUTRITION               |   MACRO BREAKDOWN   |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  1                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   BREAKFAST     | PROTRIN SMOOTHIE             | CALORIES=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   8-9AM         | 2/3sp whey                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup oats                 | carbs-50g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp peanut butter            | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml non fat milk           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2g cinnamon                  |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  2                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   SNACK         | SPINACH OMELETE              | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   11-12PM       | 1 whole egg                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5 egg white                  | carbs-50g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3 slice whole wheat bread    | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 handful spinach            | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 orange                     |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  3                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   LUNCH         | POTATO BEAN BOWL             | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   2-3PM         | 100g grilled chicken         |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup black kidney beans   | carbs-50g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup white chickpeas      | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 100g sweet potato            | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 green bell pepper        |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2sp olive oil              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp onion                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp tomato                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 lemon                    |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  4                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   SNACK         | MULTIGRAIN MEAL              | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   4-5PM         | 1/8cup oats                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/8cup quinoa                | carbs-50g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/8cup millet                | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/8cup amarathan             | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 whey                     |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp peanuts+1/2 apple        |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                         PRE WORKOUT MEAL                             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   PRE W/O       | WITH SUPPLEMENT                                    |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   6PM           | 1scoop c4/amino energy                             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 200ml cold water                                   |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | OR                                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | WITHOUT SUPPLEMENT                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2tsp coffee                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml hot water+1sp milk                           |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                         Post WORKOUT MEAL                            |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   POST W/O      | POST W/O SUPPLENET           | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   6PM           | 1-2scoop whey protein        |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5g BCAA                      | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml gatorade               | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     | fat-0g              |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp honey                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | OR                           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | POST W/o WITHOUT SUPPLEMENT  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 6 boiled egg white           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml non fat milk           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp honey                    |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  5                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   DINNER        | BOILED EGG SABJI             | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   8:30-9PM      | 2 whole egg(boiled)          |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3 egg white(boiled)          | carbs-50g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 green bell papper        | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 thin chapatti              | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2sp olive oil              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp onion                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp tomato                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp green onion              |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  6                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   BEFORE BED    | PROTEIN PAN CAKE             | calories=375        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   11PM          | 1 whole                      |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 banana                   | carbs-30g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp chia seeds or flaxseeds  | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | pinch cinnamon               | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp casein protien(or whey)  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp almond or peanut butter  |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |  calories=2825      protein=210g       carbs=350g       fat=65g      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    again_menu(i);
}
void fat_lose_meal_veg()
{
    int i,r,q;
    gotoxy(25,15);
    printf("Loading.");
    gotoxy(25,16);
    for(r=1; r<=15; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",178);
    }
    system("cls");
    heading();
    system("COLOR 2F");
    printf("\n\n");
    printf("\t\t\t\t\t\t                              ***| MEAL PLAN |***                           \n");
    printf("\t\t\t\t\t\t                                  ___________                               \n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |      TIME       |      NUTRITION               |   MACRO BREAKDOWN   |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  1                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   BREAKFAST     | PROTRIN SMOOTHIE             | CALORIES=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   8-9AM         | 2/3sp whey                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup oats                 | carbs-50g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp peanut butter            | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml non fat milk           |                     |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2g cinnamon                  |                     |\n");
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  2                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   SNACK         | MILK & BREAD                 | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   11-12PM       | 240ml non fat milk           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3 slices whole wheat bread   | carbs-52g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp peanut butter            | pro-28g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 almonds                    | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 orange                     |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  3                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   LUNCH         | POTATO BEAN BOWL             | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   2-3PM         | 50g soy chunks               |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup black kidney beans   | carbs-50g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup white chickpeas      | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 100g sweet potato            | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 green bell pepper        |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2sp olive oil              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp onion                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp tomato                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 lemon                    |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  4                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   SNACK         | MULTIGRAIN MEAL              | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   4-5PM         | 1/8cup oats                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/8cup quinoa                | carbs-50g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/8cup millet                | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/8cup amarathan             | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 whey                     |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp peanuts+1/2 apple        |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                         PRE WORKOUT MEAL                             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   PRE W/O       | WITH SUPPLEMENT                                    |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   6PM           | 1scoop c4/amino energy                             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 200ml cold water                                   |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | OR                                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | WITHOUT SUPPLEMENT                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2tsp coffee                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml hot water+1sp milk                           |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                         Post WORKOUT MEAL                            |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   POST W/O      | POST W/O SUPPLENET           | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   6PM           | 1-2scoop whey protein        |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5g BCAA                      | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml gatorade               | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     | fat-0g              |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp honey                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | OR                           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | POST W/o WITHOUT SUPPLEMENT  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml non fat milk           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp honey                    |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  5                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   DINNER        | PANEER SABJI                 | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   8:30-9PM      | 100g paneer                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 green peas               | carbs-55g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 green bell papper        | pro-25g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 thin chapatti              | fat-10g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2sp olive oil              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp onion                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp tomato                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp green onion              |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  6                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   BEFORE BED    | PROTEIN PAN CAKE             | calories=375        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   11PM          | 1/2 banana                   | carbs-30g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp chia seeds or flaxseeds  | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | pinch cinnamon               | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp casein protien(or whey)  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp almond or peanut butter  |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |  calories=2825      protein=210g       carbs=350g       fat=65g      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    again_menu(i);
}


int fat_lose_workout(int i)
{
    int r,q;
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  MONDAY    : press 1\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  TUESDAY   : press 2\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  WEDNESDAY : press 3\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  THURSDAY  : press 4\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  FRIDAY    : press 5\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  SATURDAY  : press 6\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  SUNDAY    : press 7\n\n");
    for(i=209; i>=0; i--)
    {
        printf("%c",196);
        delay(5);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t        Enter a day:\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  TODAY IS YOUR LEGS DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                            MONDAY- LEGS                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 1   | a) leg press                 |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB walking lunges         |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) leg extension             |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 2   | a) DB or barbell deadlift    |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) laying leg curl           |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) seated calf raise         |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 2:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t        TODAY IS YOUR SHOULDERS+ABS+CARDIO DAY                   \n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                   THURSDAY-SHOULDERS+ABS+CARDIO                       |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 1   | a) shoulder press behind neck|   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB side raise             |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) plate front raise         |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 2   | a) DB press                  |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB front raise            |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) cable rear delt fly       |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set     | a) sit-ups                   |   20     |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) hanging side raise        |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) reverse crunch            |   20     |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) wood chopper              |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   CARDIO        | 20 min running on treadmill  |speed 6mph|   20 min  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 3:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  TODAY IS YOUR ARMS DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                          WEDNESDAY-ARMS                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 1   | a) barbell curl              |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB hammer curl            |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) laying cable curl         |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 2   | a) barbell skull crusher     |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) rope overhead extension   |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) CG triceps pushdown       |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 4:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t           TODAY IS YOUR ABS+CARDIO DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                           THURDAY-ABS+CARDIO                          |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set     | a) sit-ups                   |   20     |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) hanging side raise        |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) reverse crunch            |   20     |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) wood chopper              |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   CARDIO        | 20 min running on treadmill  |speed 6mph|   20 min  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 5:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t  TODAY IS YOUR CHEST DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                           FRIDAY-CHEST                                |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 1   | a) barbell incline press     |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB press                  |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) decline vable fly         |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 2   | a) decline pushups           |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) incline pushups           |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) barbell press             |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 6:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t         TODAY IS YOUR BACK+ABS+CARDIO DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                        SATURDAY-BACK+ABS+CARDIO                       |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 1   | a) WG lat pull down          |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) machine rows              |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) standing lat pull down    |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set 2   | a) DB shrugs                 |   5      |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) rope upright rows         |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) hyper back extension      |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   Giant set     | a) sit-ups                   |   20     |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) hanging side raise        |   10     |    3-4    |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) reverse crunch            |   20     |           |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) wood chopper              |   20     |           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   CARDIO        | 20 min running on treadmill  |speed 6mph|   20 min  |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 7:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t\t                           TODAY IS YOUR REST DAY\n");
        again_menu(i);
        break;
    default:
        system("cls");
        heading();
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t\t                                Wrong choice\n\n");
        again_menu(i);
        break;
    }
}

// how to do exercise

int howto(int i)
{
    heading();
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   PULL UPS                    : press 1\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   PUSH UPS                    : press 2\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   BARBELL CURL                : press 3\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   HAMMER CURL                 : press 4\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   DELTOID RAISE               : press 5\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   ARNOLD DUMBBELL PRESS       : press 6\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   BARBELL SHOULDER PRESS      : press 7\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   CABLE PREACHER CURL         : press 8\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   BARBELL BENCH PRESS         : press 9\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   BUTTERFLY                   : press 10\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   BARBELL INCLINE BENCH PRESS : press 11\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   BENT OVER BARBELL ROW       : press 12\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   DEADLIFT                    : press 13\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   BARBELL SQUAT               : press 14\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t  \xDC   CABLE TRICEPS EXTENSION     : press 15\n\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t\t\t      Enter a choice              :\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC With a grip well outside shoulder width, hang freely from an overhead bar as you would doing a pull-up.\n");
        delay(30);
        printf("\t\t\t\xDC nstead of pulling yourself directly up to the bar, contract your lats to instead go in a counter-clockwise direction.\n");
        delay(30);
        printf("\t\t\t\xDC pulling yourself partway up to the right side and continue going upward as you move back toward the center of the bar.\n");
        delay(30);
        printf("\t\t\t\xDC Here your chin should meet the bar at the apex of the move.\n");
        delay(30);
        printf("\t\t\t\xDC Continue in a circular motion until you are back to the center, reaching full arm extension.\n");
        delay(30);
        printf("\t\t\t\xDC Complete forthe designated number of reps in the same counter-clockwise motion\n");
        delay(30);
        printf("\t\t\t\xDC repeat the move for the same number of reps going in a clockwise direction as well.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 2:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC When down on the ground, set your hands at a distance that is slightly wider than shoulder-width apart.\n");
        delay(30);
        printf("\t\t\t\xDC Your feet should be set up in a way that feels right and comfortable to you.\n");
        delay(30);
        printf("\t\t\t\xDC Think of your body as one giant straight line.\n");
        delay(30);
        printf("\t\t\t\xDC If you have a problem getting the proper form with your body, try this (yes Im serious).\n");
        delay(30);
        printf("\t\t\t\xDC Your head should be looking slightly ahead of you, not straight down.\n");
        delay(30);
        printf("\t\t\t\xDC At the top of your push up, your arms should be straight and supporting your weight.\n");
        delay(30);
        printf("\t\t\t\xDC With your arms straight, butt clenched, and abs braced.\n");
        delay(30);
        printf("\t\t\t\xDC Try not to let your elbows go flying way out with each repetition.\n");
        delay(30);
        printf("\t\t\t\xDC Once your chest touches the floor (or your arms go down to a 90 degree angle).\n");
        delay(30);
        printf("\t\t\t\xDC Congratulations, you just did a proper push up.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 3:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Stand up with your torso upright while holding a barbell at a shoulder-width grip.\n");
        delay(30);
        printf("\t\t\t\xDC The palm of your hands should be facing forward and the elbows should be close to the torso.\n");
        delay(30);
        printf("\t\t\t\xDC This will be your starting position.\n");
        delay(30);
        printf("\t\t\t\xDC While holding the upper arms stationary, curl the weights forward while contracting the biceps as you breathe out.\n");
        delay(30);
        printf("\t\t\t\xDC tips-Only the forearms should move\n");
        delay(30);
        printf("\t\t\t\xDC Continue the movement until your biceps are fully contracted and the bar is at shoulder level.\n");
        delay(30);
        printf("\t\t\t\xDC Hold the contracted position for a second and squeeze the biceps hard\n");
        delay(30);
        printf("\t\t\t\xDC Slowly begin to bring the bar back to starting position as your breathe in.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat for the recommended amount of repetitions\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }

        break;
    case 4:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Stand up with your torso upright and a dumbbell in each hand being held at arms length\n");
        delay(30);
        printf("\t\t\t\xDC The elbows should be close to the torso.\n");
        delay(30);
        printf("\t\t\t\xDC The palms of the hands should be facing your torso\n");
        delay(30);
        printf("\t\t\t\xDC This will be your starting position.\n");
        delay(30);
        printf("\t\t\t\xDC While holding the upper arm stationary, curl the right weight forward while contracting the biceps as you breathe out. \n");
        delay(30);
        printf("\t\t\t\xDC Continue the movement until your biceps is fully contracted and the dumbbells are at shoulder level. \n");
        delay(30);
        printf("\t\t\t\xDC Hold the contracted position for a second as you squeeze the biceps.\n");
        delay(30);
        printf("\t\t\t\xDC Slowly begin to bring the dumbbells back to starting position as your breathe in.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat the movement with the left hand. This equals one repetition\n");
        delay(30);
        printf("\t\t\t\xDC Continue alternating in this manner for the recommended amount of repetitions.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 5:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC In a standing position, hold a pair of dumbbells at your side.\n");
        delay(30);
        printf("\t\t\t\xDC Keeping your elbows slightly bent, raise the weights directly in front of you to shoulder height,\n");
        delay(30);
        printf("\t\t\t\xDC avoiding any swinging or cheating.\n");
        delay(30);
        printf("\t\t\t\xDC Return the weights to your side.\n");
        delay(30);
        printf("\t\t\t\xDC On the next repetition, raise the weights laterally,\n");
        delay(30);
        printf("\t\t\t\xDC raising them out to your side to about shoulder height.\n");
        delay(30);
        printf("\t\t\t\xDC Return the weights to the starting position and continue alternating to the front and side.\n");
        delay(30);
        printf("\n\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 6:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Sit on an exercise bench with back support and hold two dumbbells in front of you at about upper chest. \n");
        delay(30);
        printf("\t\t\t\xDC level with your palms facing your body and your elbows bent.\n");
        delay(30);
        printf("\t\t\t\xDC Now to perform the movement, raise the dumbbells as you rotate the palms of your hands until they are facing forward.\n");
        delay(30);
        printf("\t\t\t\xDC Continue lifting the dumbbells until your arms are extended above you in straight arm position.\n");
        delay(30);
        printf("\t\t\t\xDC Breathe out as you perform this portion of the movement.\n");
        delay(30);
        printf("\t\t\t\xDC After a second pause at the top, begin to lower the dumbbells to the original position by rotating the palms of your hands towards you.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat for the recommended amount of repetitions.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 7:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Sit on a bench with back support in a squat rack. Position a barbell at a height that is just above your head.\n");
        delay(30);
        printf("\t\t\t\xDC Grab the barbell with a pronated grip (palms facing forward).\n");
        delay(30);
        printf("\t\t\t\xDC Once you pick up the barbell with the correct grip width, lift the bar up over your head by locking your arms.\n");
        delay(30);
        printf("\t\t\t\xDC Hold at about shoulder level and slightly in front of your head. This is your starting position.\n");
        delay(30);
        printf("\t\t\t\xDC Lower the bar down to the shoulders slowly as you inhale.\n");
        delay(30);
        printf("\t\t\t\xDC Lift the bar back up to the starting position as you exhale.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat for the recommended amount of repetitions.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 8:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Place a preacher bench about 2 feet in front of a pulley machine.\n");
        delay(30);
        printf("\t\t\t\xDC Attach a straight bar to the low pulley.\n");
        delay(30);
        printf("\t\t\t\xDC Sit at the preacher bench with your elbow and upper arms firmly on top of the bench. \n");
        delay(30);
        printf("\t\t\t\xDC pad and have someone hand you the bar from the low pulley.\n");
        delay(30);
        printf("\t\t\t\xDC Grab the bar and fully extend your arms on top of the preacher bench pad. This will be your starting position.\n");
        delay(30);
        printf("\t\t\t\xDC Now start pilling the weight up towards your shoulders and squeeze the biceps hard at the top of the movement.\n");
        delay(30);
        printf("\t\t\t\xDC Exhale as you perform this motion. Also, hold for a second at the top.\n");
        delay(30);
        printf("\t\t\t\xDC Now slowly lower the weight to the starting position.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat for the recommended amount of repetitions.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 9:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Lie back on a flat bench. Using a medium width grip (a grip that creates a 90-degree angle in the middle of the movement .\n");
        delay(30);
        printf("\t\t\t\xDC between the forearms and the upper arms), lift the bar from the rack and hold it straight over you with your arms locked.\n");
        delay(30);
        printf("\t\t\t\xDC From the starting position, breathe in and begin coming down slowly until the bar touches your middle chest\n");
        delay(30);
        printf("\t\t\t\xDC After a brief pause, push the bar back to the starting position as you breathe out. Focus on pushing the bar using your chest muscles.\n");
        delay(30);
        printf("\t\t\t\xDC Lock your arms and squeeze your chest in the contracted position at the top of the motion.\n");
        delay(30);
        printf("\t\t\t\xDC hold for a second and then start coming down slowly again.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat the movement for the prescribed amount of repetitions.\n");
        delay(30);
        printf("\t\t\t\xDC When you are done, place the bar back in the rack.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 10:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Sit on the machine with your back flat on the pad.\n");
        delay(30);
        printf("\t\t\t\xDC Take hold of the handles. Tip: Your upper arms should be positioned parallel to the floor;\n");
        delay(30);
        printf("\t\t\t\xDC adjust the machine accordingly. This will be your starting position.\n");
        delay(30);
        printf("\t\t\t\xDC Push the handles together slowly as you squeeze your chest in the middle.\n");
        delay(30);
        printf("\t\t\t\xDC Breathe out during this part of the motion and hold the contraction for a second.\n");
        delay(30);
        printf("\t\t\t\xDC Return back to the starting position slowly as you inhale until your chest muscles are fully stretched.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat for the recommended amount of repetitions.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 11:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Load the bar to an appropriate weight for your training.\n");
        delay(30);
        printf("\t\t\t\xDC Lay on the bench with your feet flat on the ground, driving through to your hips.\n");
        delay(30);
        printf("\t\t\t\xDC Your back should be arched, and your shoulder blades retracted.\n");
        delay(30);
        printf("\t\t\t\xDC Take a medium, pronated grip covering the rings on the bar. Remove the bar from the rack.\n");
        delay(30);
        printf("\t\t\t\xDC holding the weight above your chest with your arms extended. This will be your starting position.\n");
        delay(30);
        printf("\t\t\t\xDC Lower the bar to the sternum by flexing the elbows. Maintain control and do not bounce the bar off of your chest.\n");
        delay(30);
        printf("\t\t\t\xDC Your lats should stay tight and elbows slightly drawn in.\n");
        delay(30);
        printf("\t\t\t\xDC After touching your torso with the bar, extend the elbows to return the bar to the starting position.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 12:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Holding a barbell with a pronated grip (palms facing down), bend your knees slightly and bring your torso forward.\n");
        delay(30);
        printf("\t\t\t\xDC by bending at the waist, while keeping the back straight until it is almost parallel to the floor.\n");
        delay(30);
        printf("\t\t\t\xDC Now, while keeping the torso stationary, breathe out and lift the barbell to you.\n");
        delay(30);
        printf("\t\t\t\xDC Keep the elbows close to the body and only use the forearms to hold the weight.\n");
        delay(30);
        printf("\t\t\t\xDC At the top contracted position, squeeze the back muscles and hold for a brief pause.\n");
        delay(30);
        printf("\t\t\t\xDC Then inhale and slowly lower the barbell back to the starting position.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat for the recommended amount of repetitions.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 13:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Approach the bar so that it is centered over your feet. You feet should be about hip width apart. Bend at the hip to grip the bar at shoulder width.\n");
        delay(30);
        printf("\t\t\t\xDC allowing your shoulder blades to protract. Typically, you would use an over/under grip.\n");
        delay(30);
        printf("\t\t\t\xDC With your feet and your grip set, take a big breath and then lower your hips and flex the knees until your shins contact the bar.\n");
        delay(30);
        printf("\t\t\t\xDC keep your chest up and your back arched, and begin driving through the heels to move the weight upward.\n");
        delay(30);
        printf("\t\t\t\xDC After the bar passes the knees, aggressively pull the bar back.\n");
        delay(30);
        printf("\t\t\t\xDC pulling your shoulder blades together as you drive your hips forward into the bar.\n");
        delay(30);
        printf("\t\t\t\xDC Lower the bar by bending at the hips and guiding it to the floor.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 14:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC This exercise is best performed inside a squat rack for safety purposes. To begin, first set the bar on a rack just above shoulder level.\n");
        delay(30);
        printf("\t\t\t\xDC Once the correct height is chosen and the bar is loaded.\n");
        delay(30);
        printf("\t\t\t\xDC step under the bar and place the back of your shoulders (slightly below the neck) across it.\n");
        delay(30);
        printf("\t\t\t\xDC Hold on to the bar using both arms at each side and lift it off the rack by first pushing with your legs and at the same time straightening your torso.\n");
        delay(30);
        printf("\t\t\t\xDC Step away from the rack and position your legs using a shoulder-width medium stance with the toes slightly pointed out. \n");
        delay(30);
        printf("\t\t\t\xDC Keep your head up at all times and maintain a straight back. This will be your starting position.\n");
        delay(30);
        printf("\t\t\t\xDC Begin to slowly lower the bar by bending the knees and sitting back with your hips as you maintain a straight posture with the head up.\n");
        delay(30);
        printf("\t\t\t\xDC Continue down until your hamstrings are on your calves. Inhale as you perform this portion of the movement.\n");
        delay(30);
        printf("\t\t\t\xDC Begin to raise the bar as you exhale by pushing the floor with the heel or middle of your foot .\n");
        delay(30);
        printf("\t\t\t\xDC you straighten the legs and extend the hips to go back to the starting position.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat for the recommended amount of repetitions.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    case 15:
        system("cls");
        heading();
        printf("\n\n");
        system("COLOR 2F");
        printf("\t\t\t\xDC Place a bench sideways in front of a high pulley machine.\n");
        delay(30);
        printf("\t\t\t\xDC Hold a straight bar attachment above your head with your hands about 6 inches apart with your palms facing down.\n");
        delay(30);
        printf("\t\t\t\xDC Face away from the machine and kneel.\n");
        delay(30);
        printf("\t\t\t\xDC Place your head and the back of your upper arms on the bench. Your elbows should be bent with the forearms pointing towards the high pulley. \n");
        delay(30);
        printf("\t\t\t\xDC While keeping your upper arms close to your head at all times with the elbows in, press the bar out in a semicircular motion .\n");
        delay(30);
        printf("\t\t\t\xDC until the elbows are locked and your arms are parallel to the floor. Contract the triceps hard and keep this position for a second. \n");
        delay(30);
        printf("\t\t\t\xDC Slowly return to the starting position as you breathe in.\n");
        delay(30);
        printf("\t\t\t\xDC Repeat for the recommended amount of repetitions.\n");
        delay(30);
        printf("\n");
        for(i=0; i<=209; i++)
        {
            printf("%c",196);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE EXERCISE AGAIN : press 1\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tIF YOU WANT TO SEE MENU BAR       : press 2\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter a choice                    :\t");
        scanf("%d",&i);
        if(i==1)
        {
            system("cls");
            howto(i);
        }
        else if(i==2)
        {
            system("cls");
            heading();
            again_menu(i);
        }
        else
        {
            system("cls");
            heading();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
            again_menu(i);
        }
        break;
    default:
        system("cls");
        heading();
        printf("\n");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong choice\n");
        again_menu(i);
    }
}

void gain_muscle_meal(int i)
{
    int r,q;
    gotoxy(25,15);
    printf("Loading.");
    gotoxy(25,16);
    for(r=1; r<=15; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",178);
    }
    system("cls");
    heading();
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t                              ***| MEAL PLAN |***                           \n");
    printf("\t\t\t\t\t\t\t\t                                  ___________                               \n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |      TIME       |      NUTRITION               |   MACRO BREAKDOWN   |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  1                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   BREAKFAST     | MUSCLE GAIN SHAKE            | CALORIES=555        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   8-9AM         | 4 egg white(or whey)         |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 cup oats powder            | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup low fat yogurt       | pro-35g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp peanut butter            | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 300ml water                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2g cinnamon                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5g BCAA(optional)            |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  2                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   SNACK         | FOOD                         | calories=555        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   10-11AM       | 1 whole egg                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5 egg white                  | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 cup black roasted channa   | pro-35g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 4-6 biscuits                 | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 cup ginger tea             |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  3                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   LUNCH         | LUNCH                        | calories=555        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   1-2PM         | 5 egg white                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 whole egg                  | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 orange or 1 pear           | pro-35g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 handful spinach            | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 green bell pepper        |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2sp olive oil              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2sp onion                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp tomato                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 chapati                    |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  4                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   SNACK         | MULTIGRAIN MEAL              | calories=555        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   4-5PM         | 200g low fat cottage cheese  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3 slice wheat bread          | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp peanut butter            | pro-35g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 cup coffee                 |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                         PRE WORKOUT MEAL                             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   PRE W/O       | WITH SUPPLEMENT              | calories=525        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   6PM           | 2 scoop whey                 |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 sp boost                   | pro=55g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 sp glucose-c               | carbs=65g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     | fat=5g              |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                         Post WORKOUT MEAL                            |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   POST W/O      | POST W/O SUPPLENET           | calories=410        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   6PM           | 1-2scoop whey protein        |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5g BCAA                      | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml gatorade               | pro-30g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     | fat-0g              |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp honey                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | OR                           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | POST W/o WITHOUT SUPPLEMENT  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 6 boiled egg white           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml non fat milk           |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp honey                    |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  5                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   DINNER        | BOILED EGG SABJI             | calories=555        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   9-10PM        | 1/2 cup kidney beans         |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3 egg white(boiled)          | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 green bell papper        | pro-35g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 thin chapatti              | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2sp olive oil              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp onion                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp tomato                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup black beans          |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |  calories=3300      protein=225g       carbs=420g       fat=80g      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    again_menu(i);

}
void muscle_gain_workout(int i)
{
    int r,q;
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  MONDAY    : press 1\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  TUESDAY   : press 2\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  WEDNESDAY : press 3\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  THURSDAY  : press 4\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  FRIDAY    : press 5\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  SATURDAY  : press 6\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  SUNDAY    : press 7\n\n");
    for(i=209; i>=0; i--)
    {
        printf("%c",196);
        delay(5);
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t        Enter a day:\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t\t                      TODAY IS YOUR CHEST DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                            MONDAY- CHEST                              |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) barbell incline press     |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB flat bench press       |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) decline dips              |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) cable fiy's               |   5      |    5      |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 2:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                    TODAY IS YOUR LATS/MID-BACK/LOWER-BACK DAY               \n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                   THURSDAY-LATS/MID-BACK/LOWER-BACK                   |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) V-grid lat pull-down      |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) close grip machine rows   |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) wide grip v-bar pull-down |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) hyper extension           |   5      |    5      |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 3:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                          TODAY IS YOUR ARMS/abs DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                          WEDNESDAY-ARMS/ABS                           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) barbell preacher curl     |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB hammer curl            |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) triceps skull crusher     |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) DB kick back              |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | e) DB overhead extension     |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | f) weighted inclined crusher |   2      |   15-20   |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | g) laying reverse crusher    |   2      |   15-20   |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | h) hanging knee raise        |   2      |   10-20   |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 4:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t\t                           TODAY IS YOUR REST DAY\n");
        again_menu(i);
        break;
    case 5:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                       TODAY IS YOUR SHOULDER/TRAPS DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                           FRIDAY-SHOULDER/TRAPS                       |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) barbell press behind neck |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB shoulder press         |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) DB side raise             |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) DB front raise            |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | e) barbell shrugs            |   5      |    5      |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 6:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                             TODAY IS YOUR LEGS DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                              SATURDAY-LEGS                            |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) leg press                 |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB walking lunges         |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) leg extension             |   5      |    5      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) calf raise on leg press   |   5      |    5      |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 7:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t\t                           TODAY IS YOUR REST DAY\n");
        again_menu(i);
        break;
    default:
        system("cls");
        heading();
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t\t                                Wrong choice\n\n");
        again_menu(i);
        break;
    }
}

int muscle_gain(int i)
{
    system("cls");
    heading();
    printf("\n\n\n\t\t\t\t\t\xDC WORKOUT PLANS\t\t");
    printf("        < this workout plan based on daily routine,follow it day by day at least 3 months >\n");
    delay(30);
    printf("\n\n\t\t\t\t\t\xDC DIET PLANS\t\t");
    printf("        < this diet plan based on full day routine,follow it day by day at least 3 months >\n");
    delay(30);
    printf("\n\n\t\t\t\t\t\xDc HOW TO EXERCISE\t\t");
    printf("< if you don't know how to exercise those mention in workout plan you can it >\n\n\n");
    delay(30);
    for(i=0; i<=209; i++)
    {
        printf("%c",196);
        delay(5);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  WORKOUT PLAN   : press 1");
    delay(30);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  DIET PLAN      : press 2");
    delay(30);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  HOW TO EXERCISE: press 3");
    delay(30);
    system("COLOR 2F");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  Enter a choice :\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        heading();
        printf("\n\n");
        muscle_gain_workout(i);
        break;
    case 2:
        system("cls");
        heading();
        printf("\n\n");
        gain_muscle_meal(i);
        break;
    case 3:
        howto(i);
        break;
    default:
        system("cls");
        heading();
        printf("\n\n\t\t\t\t\t\t\t                                      wrong choice\n\n");
        again_menu(i);
        break;


    }
}


int massup(int i)
{
    system("cls");
    heading();
    printf("\n\n\n\t\t\t\t\t\xDC WORKOUT PLANS\t\t");
    printf("        < this workout plan based on daily routine,follow it day by day at least 3 months >\n");
    delay(30);
    printf("\n\n\t\t\t\t\t\xDC DIET PLANS\t\t");
    printf("        < this diet plan based on full day routine,follow it day by day at least 3 months >\n");
    delay(30);
    printf("\n\n\t\t\t\t\t\xDc HOW TO EXERCISE\t\t");
    printf("< if you don't know how to exercise those mention in workout plan you can it >\n\n\n");
    delay(30);
    for(i=0; i<=209; i++)
    {
        printf("%c",196);
        delay(5);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  WORKOUT PLAN   : press 1");
    delay(30);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  DIET PLAN      : press 2");
    delay(30);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  HOW TO EXERCISE: press 3");
    delay(30);
    system("COLOR 2F");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  Enter a choice :\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        heading();
        printf("\n\n");
        massup_workout(i);
        break;
    case 2:
        system("cls");
        heading();
        printf("\n\n");
        massup_meal(i);
        break;
    case 3:
        howto(i);
        break;
    default:
        system("cls");
        heading();
        printf("\n\n\t\t\t\t\t\t\t                                      wrong choice\n\n");
        again_menu(i);
        break;


    }
}

int  massup_workout(int i)
{
    int r,q;
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  MONDAY    : press 1\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  TUESDAY   : press 2\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  WEDNESDAY : press 3\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  THURSDAY  : press 4\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  FRIDAY    : press 5\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  SATURDAY  : press 6\n\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t\t\t\t   \xDC  SUNDAY    : press 7\n\n");
    for(i=209; i>=0; i--)
    {
        printf("%c",196);
        delay(5);
    }
    printf("\t\t\t\t\t\t\t\t\t\t\t        Enter a day:\t");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                      TODAY IS YOUR CHEST/TRICEPS DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                          MONDAY- CHEST/TRICEPS                        |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) barbell incline press     |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB flat bench press       |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) barbell decline press     |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) close gp barbell press    |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | e) DB overhead ext.          |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | f) triceps press down        |   6-8    |    3      |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 2:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                     TODAY IS YOUR QUADS,HAMS&CALVES DAY               \n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                         THURSDAY-QUADS,HAMS&CALVES                   |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) barbell squats            |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) leg press                 |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) barbell deadlift          |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) gluteus kickback          |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | e) seated calf raise         |   6-8    |    3      |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 3:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t\t                           TODAY IS YOUR REST DAY\n");
        again_menu(i);
        break;

    case 4:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                           TODAY IS YOUR CARDIO/ABS DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                          WEDNESDAY-CARDIO/ABS                           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) incline crunches          |   15     |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) reverse crunch            |   15     |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) v-crunches                |   15     |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) side plank(RR)            |   15     |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | e) seated side twist(barbell)|   15     |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | f) 20 min cycling            |     LEVEL  10-12     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;

    case 5:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                         TODAY IS YOUR BACH & BICEPS DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                           FRIDAY-BACH & BICEPS                       |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) wide grip lat pull down   |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB row or barbell row     |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) rope row                  |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) barbell hyper ext.        |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | e) barbell curl              |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | f) reverse bar preacher curl |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | g) single hand DD side curl  |   6-8    |    3      |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 6:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        system("COLOR 2F");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t                      TODAY IS YOUR SHOULDERS & TRAPS DAY\n");
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                         SATURDAY-SHOULDERS & TRAPS                           |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | Exercise                     | reps/set |   set     |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   simple set    | a) barbell press             |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | b) DB side raise             |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | c) DB front raise(neutral)   |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | d) DB rear delt fiy          |   6-8    |    3      |\n");
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |                 | e) barbell shrugs            |   6-8    |    3      |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        printf("\n\t\t\t\t\t\t\t\t    |   NOTE-rest 1-2 minutes after every set                               |\n");
        delay(20);
        printf("\t\t\t\t\t\t\t\t    ");
        for(i=1; i<74; i++)
        {
            printf("%c",196);
        }
        delay(20);
        again_menu(i);
        break;
    case 7:
        system("cls");
        heading();
        gotoxy(25,15);
        printf("Loading.");
        gotoxy(25,16);
        for(r=1; r<=15; r++)
        {
            for(q=0; q<=100000000; q++);
            printf("%c",178);
        }
        system("cls");
        heading();
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t\t                           TODAY IS YOUR REST DAY\n");
        again_menu(i);
        break;
    default:
        system("cls");
        heading();
        printf("\n\n");
        printf("\n\t\t\t\t\t\t\t\t                                Wrong choice\n\n");
        again_menu(i);
        break;
    }
}

int massup_meal(int i)
{
    int r,q;
    gotoxy(25,15);
    printf("Loading.");
    gotoxy(25,16);
    for(r=1; r<=15; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",178);
    }
    system("cls");
    heading();
    system("COLOR 2F");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t                               ***| MEAL PLAN |***                           \n");
    printf("\t\t\t\t\t\t\t\t                                   ___________                               \n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |      TIME       |      NUTRITION               |   MACRO BREAKDOWN   |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  1                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   BREAKFAST     | MUSCLE OATS                  | CALORIES=500        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   8-9AM         | 4 egg white(or whey)         |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 cup oats                   | carbs-60g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 15g peanuts or almonds       | pro-40g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/4 cup raisins              | fat-11g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 300ml water                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2g cinnamon                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 apple or banana            |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  2                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   SNACK         | BANANA BREAD PEANUT BUTTER   | calories=500        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   11-12AM       | 3 slice whole wheat bread    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana                     | carbs-62g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1.5 to 2 sp peanuts butter   | pro-28g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp honey or cinnamon        | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 glass low fat milk         |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  3                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   LUNCH         | SUPER RICE                   | calories=500        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   1-2PM         | 1 cup brown rice             |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 whole egg                  | carbs-56g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5 eggs white                 | pro-32g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 20g peanuts                  | fat-16g             |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  4                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   SNACK         | HOME MADE MASS GAIN SHAKE    | calories=500        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   3-4PM         | 1/2 cup oats + 1sp whey      |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2sp yogurt                   | carbs-53g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1sp peanut butter            | pro-37g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3g cinnamon                  | fat-16g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 banana or strawberries     |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 cup coffee                 |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                         PRE WORKOUT MEAL                             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   PRE W/O       | WITH SUPPLEMENT              | calories=60         |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   6PM           | 5g creatine                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml gatorade               | pro=0g              |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5 g BCAA (optional)          | carbs=15g           |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                         Post WORKOUT MEAL                            |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   POST W/O      | POST W/O SUPPLENET           | calories=499        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   6PM           | 1-2scoop whey protein        |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 banana                     | carbs-78g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 240ml gatorade               | pro-40g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 5 g creatine                 | fat-3g              |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  5                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   DINNER        | DINNER                       | calories=494        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   9-10PM        | 1/2 cup kidney beans         |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3 egg white(boiled)          | carbs-70g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 green bell papper        | pro-35g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 2 thin chapatti              | fat-15g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2sp olive oil              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp onion                    |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 3sp tomato                   |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1/2 cup black beans          |                     |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                              MEAL  6                                 |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                                                                      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | RICE CAKE                    | calories=500        |\n");
    printf("\n\t\t\t\t\t\t\t\t  |                 |                              |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |   10-11PM       | 1 rice cake                  |                     |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 sp peanut butter           | carbs-36g           |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 1 cup milk                   | pro-36g             |\n");
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |                 | 4 boiled egg white           | fat-15g             |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    printf("\n\t\t\t\t\t\t\t\t  |  calories=3446      protein=245g       carbs=405g       fat=94g      |\n");
    delay(20);
    printf("\t\t\t\t\t\t\t\t  ");
    for(i=0; i<=71; i++)
    {
        printf("%c",196);
    }
    delay(20);
    again_menu(i);

}

