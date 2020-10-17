#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <unistd.h>

void choich(int innings);
void scorebord();
void start();

int i,t,cunt,X,Ball,ball,Over,pl[2];
int temp = 0 ;
int total_run=0;
int flag = 0 ;
int run_counter            = 0 ;
int out_every_over         = 0 ;
int wide     = 0 ;
int noball     = 0 ;
int lb=0;
int wide_flag         = 0 ;
int target=0;
int freehit=0;
int d=0;
char current_bowler[20];
int current_bowler_no=-1;
int current_batsman_no;
char current_batsman[20];
int wicket=0;
int extra;
int bowler_used_no[10];
int bowler_used_total=0;



struct gamedetails//for the records of game details//
{
    char competition[20];
    char playedAt[50];
    char venue[30];
    char matchbetween[30];
    char versus[30];
    char tosswonby[30];
    char electedto[20];
    int inningsof;
    char date[30];
    char input;
    int overs;
    char Batting_team_Name[20];
    char Bowling_team_Name[20];
    int over;
    int Bowler_max_over;

} game;

struct player_details//making data type
{
    char name[50];
    int run;
    int ball;
    double strick_rate;
    int out;
    int four;
    int six;

    int maiden_over;
    int totalball;
    int given_run;
    int wicket;
    int maiden;
    int NB;
    int WD;
    float ECO;
    char skill[20];
} Batsman[12],Bowler[12],cng;


void details(int cunter)
{
    cunter++;
    printf(" -------------------------------------------------------------\n");
    printf("|| Competition : %15s  ",game.competition);

    printf("| Vanue  : %15s ||\n",game.venue);
    printf("|| Match between : %13s  ",game.matchbetween);
    printf("| Versus : %16s||\n",game.versus);
    printf("|| Toss won by : %15s  ",game.tosswonby);
    printf("| Total Over : %12d||\n",game.over);
    printf(" -------------------------------------------------------------\n");

    if(cunter==2)
    {
        printf(" Competition : ");
        gets(game.competition);
        system("cls");
        details(cunter);
        d=0;
    }
    else if(cunter==3)
    {
        printf(" Vanue  : ");
        gets(game.venue);
        system("cls");
        details(cunter);
        d=0;
    }
    else if(cunter==4)
    {
        system("cls");
        if(d==-1)
            printf(" Invalid Name\n");
        for(int i=0; i<25; i++)
            printf("_");
        printf("\n");
        printf("|\tMatch between   |\n");
        for(int i=0; i<25; i++)
            printf("_");
        printf("\n");
        int ck=-1;
        printf("| 1.   |  Bangladesh    |\n");
        printf("| 2.   |  India         |\n");
        printf("| 3.   |  Australia     |\n");
        printf("| 4.   |  England       |\n");
        printf("| 5.   |  Ireland       |\n");
        printf("| 6.   |  New Zealand   |\n");
        printf("| 7.   |  Pakistan      |\n");
        printf("| 8.   |  South Africa  |\n");
        printf("| 9.   |  Sri Lanka     |\n");
        printf("|10.   |  West Indies   |\n");
        printf("|11.   |  Zimbabwe      |\n");
        for(int i=0; i<25; i++)
            printf("_");
        printf("\n Enter Number :");
        scanf("%d",&ck);
        if(ck>11&&ck<0)
            d=-1,cunter--,game.matchbetween[0]='\0';
        else
        {
            d=0;
            if(ck==1)
                strcpy(game.matchbetween,"Bangladesh");
            if(ck==2)
                strcpy(game.matchbetween,"India");
            if(ck==3)
                strcpy(game.matchbetween,"Australia");
            if(ck==4)
                strcpy(game.matchbetween,"England");
            if(ck==5)
                strcpy(game.matchbetween,"Ireland");
            if(ck==6)
                strcpy(game.matchbetween,"New Zealand");
            if(ck==7)
                strcpy(game.matchbetween,"Pakistan");
            if(ck==8)
                strcpy(game.matchbetween,"South Africa");
            if(ck==9)
                strcpy(game.matchbetween,"Sri Lanka");
            if(ck==10)
                strcpy(game.matchbetween,"West Indies");
            if(ck==11)
                strcpy(game.matchbetween,"Zimbabwe");
        }
        system("cls");
        details(cunter);
    }
    else if(cunter==5)
    {
        system("cls");
        if(d==-1)
            printf(" Invalid Name\n");
        for(int i=0; i<25; i++)
            printf("_");
        printf("\n");
        printf("\tVersus          | \n");
        for(int i=0; i<25; i++)
            printf("_");
        printf("\n");
        int ck=-1;
        printf("| 1.   |  Bangladesh    |\n");
        printf("| 2.   |  India         |\n");
        printf("| 3.   |  Australia     |\n");
        printf("| 4.   |  England       |\n");
        printf("| 5.   |  Ireland       |\n");
        printf("| 6.   |  New Zealand   |\n");
        printf("| 7.   |  Pakistan      |\n");
        printf("| 8.   |  South Africa  |\n");
        printf("| 9.   |  Sri Lanka     |\n");
        printf("|10.   |  West Indies   |\n");
        printf("|11.   |  Zimbabwe      |\n");
        for(int i=0; i<25; i++)
            printf("_");
        printf("\n Enter Number :");
        scanf("%d",&ck);
        if(ck<=11&&ck>0)
        {
            d=0;

            if(ck==1)
                strcpy(game.versus,"Bangladesh");
            if(ck==2)
                strcpy(game.versus,"India");
            if(ck==3)
                strcpy(game.versus,"Australia");
            if(ck==4)
                strcpy(game.versus,"England");
            if(ck==5)
                strcpy(game.versus,"Ireland");
            if(ck==6)
                strcpy(game.versus,"New Zealand");
            if(ck==7)
                strcpy(game.versus,"Pakistan");
            if(ck==8)
                strcpy(game.versus,"South Africa");
            if(ck==9)
                strcpy(game.versus,"Sri Lanka");
            if(ck==10)
                strcpy(game.versus,"West Indies");
            if(ck==11)
                strcpy(game.versus,"Zimbabwe");
        }
        else
            d=-1,cunter--,game.versus[0]='\0';

        if(strcmp(game.matchbetween,game.versus)==0)
            d=-1,cunter--,game.versus[0]='\0';
        system("cls");
        details(cunter);
    }
    else if(cunter==6)
    {
        printf(" Toss won by : ");
        gets(game.tosswonby);
        d=0;
        if(strcmp(game.tosswonby,game.matchbetween)==0 )
        {
            strcpy(game.Batting_team_Name,game.tosswonby);
            strcpy(game.Bowling_team_Name,game.versus);
        }
        else if(strcmp(game.tosswonby,game.versus)==0)
        {
            strcpy(game.Batting_team_Name,game.versus);
            strcpy(game.Bowling_team_Name,game.matchbetween);
        }
        else
            d=-1,cunter--,game.tosswonby[0]='\0';
        system("cls");
        details(cunter);
    }
    else if(cunter==7)
    {
        printf("Total Over : ");
        scanf("%d",&game.over);
        details(cunter);
        d=0;
    }

}



void takedata_batsman()//save batsman
{
    char name[50];
    FILE *file,*f;//=fopen("bd.txt","r");

    if(strcmp(game.Batting_team_Name,"Bangladesh")==0)
    {
        file =fopen("bd.txt","r");
        f=fopen("bdskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"India")==0)
    {
        file =fopen("ind.txt","r");
        f=fopen("indskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Australia")==0)
    {
        file =fopen("australianame.txt","r");
        f=fopen("australiaskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"England")==0)
    {
        file =fopen("englandname.txt","r");
        f=fopen("englandskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Ireland")==0)
    {
        file =fopen("irelandname.txt","r");
        f=fopen("irelandskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"New Zealand")==0)
    {
        file =fopen("newzlandname.txt","r");
        f=fopen("newzlandskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Pakistan")==0)
    {
        file =fopen("pakistanname.txt","r");
        f=fopen("pakistanskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"South Africa")==0)
    {
        file =fopen("southafricaname.txt","r");
        f=fopen("southafricaskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Sri Lanka")==0)
    {
        file =fopen("srilankaname.txt","r");
        f=fopen("srilankaskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"West Indies")==0)
    {
        file =fopen("westindiesname.txt","r");
        f=fopen("westindiesskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Zimbabwe")==0)
    {
        file =fopen("zimbabuwename.txt","r");
        f=fopen("zimbabuweskill.txt","r");
    }

    int line=1;

    while(fgets(name,50,file))
    {
        for(int i=0; i<strlen(name); i++)
        {
            if((name[i]>='a'&&name[i]<='z')||name[i]==' '||(name[i]>='A'&&name[i]<='Z'))
                Batsman[line].name[i]=name[i];
        }
        line++;
        if(line==12)
            break;
    }

    char skill[50];
    line=1;
    while(fgets(skill,50,f))
    {
        for(int i=0; i<strlen(skill); i++)
        {
            if((skill[i]>='a'&&skill[i]<='z')||skill[i]==' '||(skill[i]>='A'&&skill[i]<='Z'))
                Batsman[line].skill[i]=skill[i];
        }
        Batsman[line].run=0;
        Batsman[line].ball=0;
        Batsman[line].out=0;
        Batsman[line].four=0;
        Batsman[line].six=0;
        Batsman[line].totalball=0;
        Batsman[line].given_run=0;
        Batsman[line].wicket;
        Batsman[line].NB=0;
        Batsman[line].WD=0;
        Batsman[line].ECO=0;
        Batsman[line].maiden_over=0;
        line++;
        if(line==12)
            break;
    }

    fclose(file);
    fclose(f);
}

void takedata_bowler()// save bowlers
{
    char name[50];
    FILE *file,*f;

    if(strcmp(game.Bowling_team_Name,"Bangladesh")==0)
    {
        file =fopen("bd.txt","r");
        f=fopen("bdskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"India")==0)
    {
        file =fopen("ind.txt","r");
        f=fopen("indskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Australia")==0)
    {
        file =fopen("australianame.txt","r");
        f=fopen("australiaskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"England")==0)
    {
        file =fopen("englandname.txt","r");
        f=fopen("englandskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Ireland")==0)
    {
        file =fopen("irelandname.txt","r");
        f=fopen("irelandskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"New Zealand")==0)
    {
        file =fopen("newzlandname.txt","r");
        f=fopen("newzlandskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Pakistan")==0)
    {
        file =fopen("pakistanname.txt","r");
        f=fopen("pakistanskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"South Africa")==0)
    {
        file =fopen("southafricaname.txt","r");
        f=fopen("southafricaskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Sri Lanka")==0)
    {
        file =fopen("srilankaname.txt","r");
        f=fopen("srilankaskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"West Indies")==0)
    {
        file =fopen("westindiesname.txt","r");
        f=fopen("westindiesskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Zimbabwe")==0)
    {
        file =fopen("zimbabuwename.txt","r");
        f=fopen("zimbabuweskill.txt","r");
    }





    int line=1;
    while(fgets(name,50,file))
    {
        for(int i=0; i<strlen(name); i++)
        {
            if((name[i]>='a'&&name[i]<='z')||name[i]==' '||(name[i]>='A'&&name[i]<='Z'))
                Bowler[line].name[i]=name[i];
        }
        line++;
        if(line==12)
            break;
    }

    char skill[50];

    line=1;
    while(fgets(skill,50,f))
    {
        for(int i=0; i<strlen(skill); i++)
        {
            if((skill[i]>='a'&&skill[i]<='z')||skill[i]==' '||(skill[i]>='A'&&skill[i]<='Z'))
                Bowler[line].skill[i]=skill[i];
        }
        Bowler[line].run=0;
        Bowler[line].ball=0;
        Bowler[line].out=0;
        Bowler[line].four=0;
        Bowler[line].six=0;
        Bowler[line].totalball=0;
        Bowler[line].given_run=0;
        Bowler[line].wicket;
        Bowler[line].NB=0;
        Bowler[line].WD=0;
        Bowler[line].ECO=0;
        Bowler[line].maiden_over=0;
        line++;
        if(line==12)
            break;
    }
    fclose(file);
    fclose(f);
}


void showdata()//for output
{
    printf("\t\t\t\t\t -----------------------------------------------------------------\n");
    printf("\t\t\t\t\t||      Batsman Name         |   R   |   B  |  4  |  6  |   SR  ||\n");
    printf("\t\t\t\t\t -----------------------------------------------------------------\n");
    for( int i=1; i<=11; i++)
    {
        printf("\t\t\t\t\t|| ");
        if(Batsman[i].out==0)
            printf("*%2d .",i);
        else if(Batsman[i].out==1)
            printf("#%2d .",i);
        else
            printf("%3d .",i);
        printf("%20s",Batsman[i].name);

        printf(" |  %.3d  | %.3d  |",Batsman[i].run,Batsman[i].ball);
        if(Batsman[i].ball==0)
            Batsman[i].strick_rate=0;
        else
            Batsman[i].strick_rate=Batsman[i].run*10000/Batsman[i].ball;

        int tem= Batsman[i].strick_rate;
        printf(" %2d  | %2d  |",Batsman[i].four,Batsman[i].six);
        printf("%3d.%2d || \n", tem/100, tem%100);
    }
    printf("\t\t\t\t\t -----------------------------------------------------------------\n");
    printf("\t\t\t\t --------------------------------------------------------------------------\n");
    printf("\t\t\t\t||     Bowlers Name        |  O  |   R  |  W  |  M  |  NB |  WD  |   ECO  ||\n");
    printf("\t\t\t\t --------------------------------------------------------------------------\n");

    for(int i=0; i<bowler_used_total; i++)
    {
        printf("\t\t\t\t|| %d .",i+1);
        printf("%20s",Bowler[bowler_used_no[i]].name);
        printf(" | %d.%d | %3d  | %2d  |  %d  | %2d  |  %3d | ",Bowler[bowler_used_no[i]].totalball/6,Bowler[bowler_used_no[i]].totalball%6,Bowler[bowler_used_no[i]].given_run,Bowler[bowler_used_no[i]].wicket,Bowler[bowler_used_no[i]].maiden_over,Bowler[bowler_used_no[i]].NB,Bowler[bowler_used_no[i]].WD);
        if(Bowler[bowler_used_no[i]].totalball==0)
        {
            Bowler[bowler_used_no[i]].ECO=0;
        }
        else
        {
            Bowler[bowler_used_no[i]].ECO=Bowler[bowler_used_no[i]].given_run*600/Bowler[bowler_used_no[i]].totalball;
        }
        int tem=Bowler[bowler_used_no[i]].ECO;
        printf("%2d.%2d  ||\n",tem/100,tem%100);
    }
    printf("\t\t\t\t --------------------------------------------------------------------------\n");
}

int checkbowler(int prev_bowler,int current_Bowler)
{
    if(prev_bowler!=current_Bowler)
    {
        if(Bowler[current_Bowler].totalball<game.Bowler_max_over)
            return i;
        else
            return -2;
    }
    return -1;
}

int checkbatsman(int non,int strick)
{
    if(Batsman[strick].out==0)
        return strick;
    else if(Batsman[strick].out==2)
        return -2;
    return -1;
}

void change()
{
    char tempp[20];
    strcpy(tempp,game.Bowling_team_Name);
    strcpy(game.Bowling_team_Name,game.Batting_team_Name);
    strcpy(game.Batting_team_Name,tempp);

    for(i=1; i<=11; i++)
    {
        cng=Batsman[i];
        Batsman[i]=Bowler[i];
        Bowler[i]=cng;
    }
}



int main()
{
    while(1)
    {
        start();
    }
}

void start()
{
    int i,choice;

    system("color f1");

    const char rocket[] ="           _\n\
          /^\\\n\
          |-|\n\
          |W|\n\
          |E|\n\
          |L|\n\
          |C|\n\
         /|O|\\\n\
        / |M| \\\n\
       /  |E|  \\\n\
      /___\"\"\"___\\\n\     TO OUR PROJECT"
                         ;
    ;
    for ( i = 0; i < 50; i ++)
        printf("\n"); // jump to bottom of console
    printf("%s", rocket);
    int j = 300000;
    for ( i = 0; i < 50; i ++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * .8); // so sleep less each time
        printf("\n"); // move rocket a line upward
        if(i==49)
        {
            printf("                                                                                              ||Made by Cse-16 Mbstu||\n");
        }
    }

    system("color f1");
    printf("PLEASE ENTER ANY KEY TO START PROCESS:\n\n");
    getchar();
    system("cls");
    printf("\t_________________________________\n");
    printf("\t---------------------------------\n");
    printf("\t    ***ENTER YOUR CHOICE***    \n");
    printf("\t_________________________________\n");
    printf("\t---------------------------------\n");

    printf("\t|\t\t\t\t|\n");
    printf("\t|\tStart The Game  [1]\t|\n");
    printf("\t|\tExit            [2]\t|\n");
    printf("\t|\t\t\t\t|\n");
    printf("\t_________________________________\n");
    printf("\t---------------------------------\n");

    scanf("%d",&choice);
    getchar();
    switch(choice)
    {
    case 1:
        system("cls");
        details(1);
        system("cls");
        choich(1);
        break;
    case 2:
        printf("Thank you!!\n");
        exit(0);

    default:
        printf("YOU ENTER WRONG CHICE!!!\n\nPlease enter any key to continue\n\n");

        getchar();
        break;
    }
}
void run(int Run)
{
    if(Run!=0)
    {
        run_counter++;
    }


    Bowler[current_bowler_no].given_run+=Run ;
    Batsman[pl[0]].run+=Run;
    total_run+=Run;
    if(Run==4)
        Batsman[pl[0]].four++;
    if(Run==6)
        Batsman[pl[0]].six++;
    //freehit=0;

    if(Run==1||Run==3||Run==5)//change batsman
    {
        flag = 0 ;
        X=pl[0];
        pl[0]=pl[1];
        pl[1]=X;

    }
}
void out(int innings)
{
    wicket++;
    Batsman[pl[0]].out=2;
    Bowler[current_bowler_no].wicket++ ;
    cunt++;
    system("cls");
    showdata();
    if(cunt>=10)
    {
        printf("\n\nAll players out!!\n\n");
        if(innings==2)
        {
            if(total_run<target)
            {
                printf("%15s team Won By %d Run .....\n",game.Bowling_team_Name,target-total_run);
                system("pause");
            }
        }
    }
    while(1)
    {
        printf("Enter Batsman Number : ");
        scanf("%d",&pl[0]);
        if( checkbatsman(pl[1],pl[0])==-1)
        {
            printf("Invalid Name.\n");
        }
        else if( checkbatsman(pl[1],pl[0])==-2)
            printf("Already Out !!! \n");
        else
        {
            break;
        }
    }
    Batsman[pl[0]].out=1;
    getchar();
}

void Wide(int run)
{
    wide++;
    Ball--;
    run_counter++;
    Bowler[current_bowler_no].WD++;


    extra+=run+1;
    total_run+=run+1;
    Bowler[current_bowler_no].given_run+=run+1;
    Bowler[current_bowler_no].WD+=run;
    if(run==1||run==3)
    {
        int temporary=pl[0];
        pl[0]=pl[1];
        pl[1]=temporary;
    }

}
void Noball(int run)
{
    run_counter++;
    noball++;
    Ball--;
    Bowler[current_bowler_no].NB++;
    Bowler[current_bowler_no].given_run+=run+1;

    extra+=run+1;
    total_run+=run+1;
    Batsman[pl[0]].run+=run;
    if(run==1||run==3)
    {
        int temporary=pl[0];
        pl[0]=pl[1];
        pl[1]=temporary;
    }

}
void leg_bye(int Run)
{
    run_counter++;
    lb+=Run;
    extra+=Run;
    total_run+=Run;
    Bowler[current_bowler_no].given_run+=Run;


    if(Run==1||Run==3)
    {
        int temporary=pl[0];
        pl[0]=pl[1];
        pl[1]=temporary;
    }
    // freehit=0;
}

void bye(int Run)
{
    extra+=Run;
    total_run+=Run;
    Bowler[current_bowler_no].given_run+=Run;

    if(Run==1||Run==3)
    {
        int temporary=pl[0];
        pl[0]=pl[1];
        pl[1]=temporary;
    }
    //freehit=0;
}


void choich( int innings)
{
    game.Bowler_max_over=game.over*6/5;
    temp = 0 ;
    total_run=0;
    flag = 0 ;
    run_counter   = 0 ;
    wide     = 0 ;
    noball     = 0 ;
    lb=0;
    wide_flag         = 0 ;
    current_bowler_no=-1;
    current_batsman_no=-1;
    wicket=0;
    extra=0;
    bowler_used_total=0;
    freehit=0;

    system("color f1");
    cunt=0;
    if(innings==1)
    {
        takedata_batsman();
        takedata_bowler();

        system("cls");
        printf(" -------------------------------------------------------------------------------------\n");
        printf("||         %15s                 ||          %15s                ||\n",game.Batting_team_Name,game.Bowling_team_Name);
        printf(" -------------------------------------------------------------------------------------\n");
        printf("||          Name         |    skill        ||          Name         |       skill     ||\n");
        printf(" -------------------------------------------------------------------------------------\n");
        for(i=1; i<=11; i++)
        {
            printf("||  %20s |  %14s || %20s  |  %14s ||\n",Batsman[i].name,Batsman[i].skill,Bowler[i].name,Bowler[i].skill);
        }
        printf(" --------------------------------------------------------------------------------------\n");
        system("pause");
        system("cls");
    }

    getchar();
    pl[0]=-1;
    pl[1]=-1;
    while(1)
    {
        system("cls");
    showdata();
        printf("Enter Batsman Number : ");
        scanf("%d",&pl[0]);
        if( checkbatsman(0,pl[0])==-1)
        {
            printf("Invalid Name.\n");
        }
        else if( checkbatsman(0,pl[0])==-2)
            printf("Already Out !!! \n");
        else
        {
            break;
        }
    }
    Batsman[pl[0]].out=1;
    while(1)
    {
        system("cls");
        showdata();
        printf("Enter Batsman Number : ");
        scanf("%d",&pl[1]);
        if( checkbatsman(pl[0],pl[1])==-1)
        {
            printf("Invalid Player.\n");
        }
        else if( checkbatsman(pl[0],pl[1])==-2)
            printf("Already Out !!! \n");
        else
        {
            break;
        }
    }
    Batsman[pl[1]].out=1;
    current_batsman_no=pl[0];

    while(1)
    {
        int tem[10],j,bowlerr;
        printf("-------------------------\n");
        printf("|      Bowler list        |\n");
        printf("-------------------------\n");
        for(i=1, j=1; i<=11; i++)
        {
            if(i==current_bowler_no)
                continue;
            if(strcmp(Bowler[i].skill,"Bowler")==0||strcmp(Bowler[i].skill,"All Rounder")==0)
            {
                tem[j]=i;
                printf("|%d . %20s  |\n",j,Bowler[i].name);
                j++;
            }
        }
        printf("-------------------------\n");
        printf("Enter Bowlers Number : ");
        int prev_bowler=current_bowler_no;
        scanf("%d",&bowlerr);
        if(checkbowler(prev_bowler,tem[bowlerr])==-1)
        {
            printf("Invalid Name.\n");
        }
        else
        {
            current_bowler_no=tem[bowlerr];
            break;
        }

    }
    bowler_used_no[bowler_used_total]=current_bowler_no;
    bowler_used_total++;
    getchar();
    for(Ball=0, i = 0 ; Ball<game.over*6; Ball++)
    {
        if(Ball%6==0 && Ball!=0 && wide_flag==0)
        {
            X=pl[0];
            pl[0]=pl[1];
            pl[1]=X;
            if(run_counter   == 0 )
                Bowler[current_bowler_no].maiden_over++;

            run_counter         = 0 ;
            i++;
            system("cls");
            showdata();
            printf("\t\t\t-------------------------------------------------------------------------------------------\n");
            printf("\t\t\t|| %c%c%c %d/%d | %d.%d | Extra - %d | *%8s %2d (%2d) | %7s %2d (%2d)  | ",game.Batting_team_Name[0],game.Batting_team_Name[1],game.Batting_team_Name[2],total_run,cunt,Ball/6,Ball%6,extra,Batsman[pl[0]].name,Batsman[pl[0]].run,Batsman[pl[0]].ball,Batsman[pl[1]].name,Batsman[pl[1]].run,Batsman[pl[1]].ball);
            if(innings==1)
            {
                int run_rate=0;
                if(Ball!=0)
                {
                    run_rate=total_run*600/Ball;
                }
                printf(" RR  %d.%d ||\n",run_rate/100,run_rate%100);

            }
            else
                printf("Target  %d ||\n ",target);
            printf("\t\t\t-------------------------------------------------------------------------------------------\n");
            if(innings==2)
                printf("\t\t\t Need %d Run from %d Ball \n",target-total_run,game.over*6-Ball);
            while(1)
            {
                int tem[10],j,bowlerr;
                printf("-------------------------\n");
                printf("|    Bowler list        |\n");
                printf("-------------------------\n");
                for(i=1, j=1; i<=11; i++)
                {
                    if(i==current_bowler_no)
                        continue;
                    if(strcmp(Bowler[i].skill,"Bowler")==0||strcmp(Bowler[i].skill,"All Rounder")==0)
                    {
                        tem[j]=i;
                        printf("|%d . %20s  |\n",j,Bowler[i].name);
                        j++;
                    }
                }
                printf("-------------------------\n");
                printf("Enter Bowlers Number : ");
                int prev_bowler=current_bowler_no;
                scanf("%d",&bowlerr);
                int check=checkbowler(prev_bowler,tem[bowlerr]);
                if(check==-1)
                {
                    printf("Invalid Name.\n");
                }
                else if(check==-2)
                {
                    printf("Over Finished Already\n");
                }
                else
                {
                    current_bowler_no=tem[bowlerr];
                    break;
                }

            }
            if(Bowler[current_bowler_no].totalball==0)
            {
                bowler_used_no[bowler_used_total]=current_bowler_no;
                bowler_used_total++;
            }
            getchar();
        }
        system("cls");
        // showdata();
        printf("-------------------------------------------------------------------------------------------\n");
        printf("|| %c%c%c %d/%d | %d.%d | Extra - %d | *%8s %2d (%2d) | %7s %2d (%2d)  | ",game.Batting_team_Name[0],game.Batting_team_Name[1],game.Batting_team_Name[2],total_run,cunt,Ball/6,Ball%6,extra,Batsman[pl[0]].name,Batsman[pl[0]].run,Batsman[pl[0]].ball,Batsman[pl[1]].name,Batsman[pl[1]].run,Batsman[pl[1]].ball);
        if(innings==1)
        {
            int run_rate=0;
            if(Ball!=0)
            {
                run_rate=total_run*600/Ball;
            }
            printf(" RR - %d.%d ||\n",run_rate/100,run_rate%100);
        }
        else
            printf("Target - %d ||\n ",target);
        printf("-------------------------------------------------------------------------------------------\n");
        if(innings==2)
            printf("  Need %d Run from %d Ball \n",target-total_run,game.over*6 -Ball);
        printf("------------------------------------------------------------------\n");
        printf("|| Bowlers Name       |  O  |   R  |  W  | NB  |  WD  |   ECO   ||\n");
        printf("------------------------------------------------------------------\n");
        printf("||%17s  ",Bowler[current_bowler_no].name);
        printf(" | %d.%d | %3d  | %2d  | %2d  |  %3d |  ",Bowler[current_bowler_no].totalball/6,Bowler[current_bowler_no].totalball%6,Bowler[current_bowler_no].given_run,Bowler[current_bowler_no].wicket,Bowler[current_bowler_no].NB,Bowler[current_bowler_no].WD);
        if(Bowler[current_bowler_no].totalball==0)
        {
            Bowler[current_bowler_no].ECO=0;
        }
        else
        {
            Bowler[current_bowler_no].ECO=Bowler[current_bowler_no].given_run*600/Bowler[current_bowler_no].totalball;
        }
        int tem=Bowler[current_bowler_no].ECO;
        printf("%2d.%2d  ||\n",tem/100,tem%100);
        printf("-----------------------------------------------------------------\n");
        if(innings==2)
        {
            if(total_run>target)
            {
                printf("%15s Won by %d Wicket .....\n",game.Batting_team_Name,10-cunt);
                system("pause");
                break;
            }
        }
        wide_flag=1;
        char ran[10];
        int Run=-1;
        while(1)
        {
            if(freehit==1)
                printf("Free Hit\n");

            printf("Enter the Run:\n");
            gets(ran);

            if(ran[0]>='0'&&ran[0]<'7'&&strlen(ran)==1)//Run
            {
                Batsman[pl[0]].ball++;
                Bowler[current_bowler_no].totalball++;
                freehit=0;
                wide_flag=0;
                Run=ran[0]-48;
                run(Run);
            }
            else if(ran[0]=='w'&&strlen(ran)==1)//wicket
            {
                Batsman[pl[0]].ball++;
                Bowler[current_bowler_no].totalball++;
                if(freehit==0)
                {
                    out(innings);
                    wide_flag=0;
                }
                Run=0;
                freehit=0;
            }
            else if(ran[0]=='w'&&ran[1]=='d')//wide
            {
                if(strlen(ran)==2)
                {
                    Wide(0);
                    Run=0;
                }
                else if(strlen(ran)==3)
                {
                    if(ran[2]>'0'&&ran[2]<'5')
                    {
                        Run=ran[2]-48;
                        Wide(Run);
                    }
                }
                else if(ran[2]=='r'&&ran[3]=='o')//runout
                {
                    if(strlen(ran)==5&&ran[4]>'0'&&ran[4]<'4')
                    {
                        Run=ran[4]-48;
                        Wide(Run);
                        out(innings);
                    }
                }
            }

            else if(ran[0]=='n'&&ran[1]=='b')//noball
            {
                if(strlen(ran)==2)
                {
                    Run=0,Noball(0);
                    Batsman[pl[0]].ball++;
                    freehit=1;
                }
                else if(strlen(ran)==3&&ran[2]=='w')
                {
                    Run=0,Noball(0);
                    Batsman[pl[0]].ball++;
                    freehit=1;
                }
                else if(strlen(ran)==3&&ran[2]>'0'&&ran[2]<'7')
                {
                    Batsman[pl[0]].ball++;
                    Run=ran[2]-48;
                    Noball(Run);
                    freehit=1;
                }
                else if(ran[2]=='r'&&ran[3]=='o')
                {
                    if(strlen(ran)==5&&ran[4]>='0'&&ran[4]<'4')
                    {
                        Batsman[pl[0]].ball++;
                        Run=ran[4]-48;
                        Noball(Run);
                        out(innings);
                        freehit=1;
                    }
                }
                else if(ran[2]=='l'&&ran[3]=='b')
                {
                    if(strlen(ran)==5&&ran[4]>'0'&&ran[4]<'4')
                    {
                        Batsman[pl[0]].ball++;
                        Run=ran[4]-48;
                        Noball(0);
                        leg_bye(Run);
                        freehit=1;
                    }
                }
                else if(ran[2]=='b')
                {
                    if(strlen(ran)==4&&ran[3]>'0'&&ran[3]<'4')
                    {
                        Batsman[pl[0]].ball++;
                        Run=ran[3]-48;
                        Noball(0);
                        bye(Run);
                        freehit=1;
                    }
                }
            }
            else if(ran[0]=='l'&&ran[1]=='b')
            {
                if(ran[2]>'0'&&ran[2]<'5')
                {
                    Batsman[pl[0]].ball++;
                    Bowler[current_bowler_no].totalball++;
                    freehit=0;
                    Run=ran[2]-48;
                    leg_bye(Run);
                    wide_flag=0;
                }
            }
            else if(ran[0]=='b'&&strlen(ran)==2)
            {
                if(ran[1]>'0'&&ran[1]<'5')
                {
                    Batsman[pl[0]].ball++;
                    Bowler[current_bowler_no].totalball++;
                    freehit=0;
                    wide_flag=0;
                    Run=ran[1]-48;
                    bye(Run);
                }
            }
            else if(ran[0]=='r'&&ran[1]=='o')
            {
                if(strlen(ran)==3 && ran[2]>'0'&&ran[2]<'4')
                {
                    Batsman[pl[0]].ball++;
                    Bowler[current_bowler_no].totalball++;
                    freehit=0;
                    Run=ran[2]-48;
                    run(Run);
                    out(innings);
                    wide_flag=0;
                }
            }


            if(Run==-1)
            {
                printf("Invalid Run !!!\n");
            }
            else
                break;
        }



        if(wicket>=10)
            break;
    }
    if(run_counter   == 0 )
        Bowler[current_bowler_no].maiden_over++;

    system("cls");
    showdata();
    printf("\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t|| %c%c%c %d/%d | %d.%d | Extra - %d | *%8s %2d (%2d) | %7s %2d (%2d)  | ",game.Batting_team_Name[0],game.Batting_team_Name[1],game.Batting_team_Name[2],total_run,cunt,Ball/6,Ball%6,extra,Batsman[pl[0]].name,Batsman[pl[0]].run,Batsman[pl[0]].ball,Batsman[pl[1]].name,Batsman[pl[1]].run,Batsman[pl[1]].ball);

        int run_rate=0;
        if(Ball!=0)
        {
            run_rate=total_run*600/Ball;
        }
        printf(" RR - %d.%d ||\n",run_rate/100,run_rate%100);

    printf("\t\t\t-------------------------------------------------------------------------------------------\n");
    if(innings==1)
    {
        target=total_run+1;
        printf("\t\t\t\t\t\t\t\t\t Target : %d\n",target);
        system("pause");
        system("cls");
        change();
        innings++;
        choich(innings);
    }
    else
    {
        if(total_run<target)
            printf("%15s team Won By %d Run .....\n",game.Bowling_team_Name,target-total_run);
            system("pause");
    }
}
