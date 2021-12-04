#include <stdio.h>
#include <stdlib.h>
int get_first_weekDay(int year)
{
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}
int main()
{
    system("color 3F");
    int year,day=0,dayInMonth,weekDay=0,startingDay,month;
    printf("Enter your desired year: ");
    scanf("%d",&year);
    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        monthDays[1]=29;
    }
    startingDay=get_first_weekDay(year);
    for(month=0;month<12;month++)
    {
        dayInMonth=monthDays[month]+1;
        printf("\n\n------------------%s----------------",months[month]);
        printf("\n  Sun   Mon  Tue  Wed  Thurs Fri  Sat\n");
        for(weekDay=0;weekDay<startingDay;weekDay++)
        {
           printf("     ");
        }
        for(day=1;day<dayInMonth;day++)
        {
            printf("%5d",day);
            if(++weekDay>6)
            {
                printf("\n");
                weekDay=0;
            }
            startingDay=weekDay;
        }
    }

}