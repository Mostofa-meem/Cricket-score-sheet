void run(int Run)
{
      if(Run!=0){
    run_counter++;
     }
    Bowler[current_bowler_no].given_run+=Run ;
    Batsman[pl[0]].run+=Run;
    total_run+=Run;
    if(Run==4)
        Batsman[pl[0]].four++;
    if(Run==6)
        Batsman[pl[0]].six++;
    freehit=0;

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

    if(freehit==0)
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
            printf("Enter Batsman Name : ");
            gets(current_batsman);
            current_batsman_no=checkbatsman(pl[1]);
            if(current_batsman_no==-1)
            {
                printf("Invalid Name.\n");
            }
            else
            {
                break;
            }
        }
        pl[0]=current_batsman_no;
        Batsman[pl[0]].out=1;
    }
    freehit=0;
}

void Wide(int run)
{
    wide++;
    Ball--;
    run_counter++;
    Batsman[pl[0]].ball--;
    Bowler[current_bowler_no].totalball--;
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
    Bowler[current_bowler_no].totalball--;
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

    freehit=1;

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
    freehit=0;
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
    freehit=0;
}
