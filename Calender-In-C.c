#include<stdio.h>
#include<string.h>
struct Event {
	int date;
	int month;
	int year;
	char description[50];
};
struct Event events[100];
int event_count=0;
int dayNumber(int day,int month,int year)
{

	int arr[12]= {0,3,2,5,0,3,5,1,4,6,2,4};
	if(month<3) {
		year=year-1;
	}
	return (year+year/4 -year/100 +year/400+ arr[month-1] +day)%7;

}
int numberofdays(int month,int year)
{

	if(month==1)
	{

		return 31;
	}
	else if(month==2)
	{
		if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	else if(month==3)
	{
		return 31;
	}
	else if(month==4)
	{
		return 30;
	}
	else if(month==5)
	{
		return 31;
	}
	else if(month==6)
	{
		return 30;
	}
	else if(month==7)
	{
		return 31;
	}
	else if(month==8)
	{
		return 31;
	}
	else if(month==9)
	{
		return 30;
	}
	else if(month==10)
	{
		return 31;
	}
	else if(month==11)
	{
		return 30;
	}
	else if(month==12)
	{
		return 31;
	}
	return 0;

}
void displaymonthname(int month)
{
	int i=month;
	if(i==1)
	{
		printf("---------------- January ----------------\n");
	}
	else if(i==2)
	{
		printf("---------------- February ----------------\n");
	}
	else if(i==3)
	{
		printf("---------------- March ----------------\n");
	}
	else if(i==4)
	{
		printf("---------------- April ----------------\n");
	}
	else if(i==5)
	{
		printf("---------------- May ----------------\n");
	}
	else if(i==6)
	{
		printf("---------------- June ----------------\n");
	}
	else if(i==7)
	{
		printf("---------------- July ----------------\n");
	}
	else if(i==8)
	{
		printf("---------------- August ----------------\n");
	}
	else if(i==9)
	{
		printf("---------------- September ----------------\n");
	}
	else if(i==10)
	{
		printf("---------------- October ----------------\n");
	}
	else if(i==11)
	{
		printf("---------------- November ----------------\n");
	}
	else if(i==12)
	{
		printf("---------------- December ----------------\n");
	}
}

void displayspecificmonth(int month,int year)
{	
    
	int days= numberofdays(month,year);
	int current = dayNumber(1,month,year);
	displaymonthname(month);
    printf("%5s%5s%5s%5s%5s%5s%5s\n",
           "Sun","Mon","Tue","Wed","Thu","Fri","Sat");
	int k;
		for(k=0;k<current;k++)
		{
			printf("%5s"," ");
		}
		for(int j=1;j<=days;j++){
		printf("%5d",j);
		
		if((current + j) % 7 == 0)
        {
              printf("\n");
        }}
		printf("\n\n");
		
}
void displayyearcalender()
{
	int year;
	printf("Enter year:\n");
	scanf("%d",&year);
	int days;
	for(int i=0; i<12; i++)
	{
		displayspecificmonth(i+1, year);
	}
}


void  checkleapyear()
{
	int year;
	printf("Enter the year :\n");
	scanf("%d",&year);
	if(year % 400 == 0  || (year % 4 == 0  && year % 100 != 0))
		printf("Yes! It is a leap year.\n");
	else
		printf("No It's not a leap year\n");
}
void finddayusingdate()
{
	int day;
	int month, year;
	printf("Enter the day,month,year to find the day:\n");
	scanf("%d%d%d",&day,&month,&year);
	int currentday=dayNumber(day,month,year);
	if(currentday==0)
	{
		printf("%d/%d/%d is on Sunday\n",day,month,year);
	}
	else if(currentday==1)
	{
		printf("%d/%d/%d is on Monday\n",day,month,year);
	}
	else if(currentday==2)
	{
		printf("%d/%d/%d is on Tuesday\n",day,month,year);
	}
	else if(currentday==3)
	{
		printf("%d/%d/%d is on Wednesday\n",day,month,year);
	}
	else if(currentday==4)
	{
		printf("%d/%d/%d is on Thursday\n",day,month,year);
	}
	else if(currentday==5)
	{
		printf("%d/%d/%d is on Friday\n",day,month,year);
	}
	else if(currentday==6)
	{
		printf("%d/%d/%d is on Saturday\n",day,month,year);
	}
	else
		printf("Invalid\n");
}

void addevent()
{
	if (event_count >= 100) {
		printf("Event list full!\n");
		return;
	}

	printf("--------Enter event details---------\n");
	printf("Enter the date of the event:\n");
	scanf("%d",&events[event_count].date);
	printf("Enter the month of the events:\n");
	scanf("%d",&events[event_count].month);
	printf("Enter the year of event:\n");
	scanf("%d",&events[event_count].year);
	printf("Enter the events description:\n");
	scanf(" %[^\n]",events[event_count].description);
	event_count++;
	printf("Event added successfully\n");
}

void displayevent()
{	if (event_count == 0) printf("No events found.\n");
	for(int i=0; i<event_count; i++)
	{
		printf("-------------------EVENT DETAILS-------------------\n");
		printf("DATE =%d/",events[i].date);
		printf("%d/",events[i].month);
		printf("%d\n",events[i].year);
		printf("DESCRIPTION:%s\n",events[i].description);
	}
}

int main()
{
	int choice;
	printf("====================================\n");
	printf("--------- Calender System ----------\n");
	printf("====================================\n");
	do {
		printf("1.Display Full Year Calender\n2.Display Specific Month\n3.Check Leap Year\n4.Find Day using Date\n5.Add event\n6.Display all events \n7.Exit\n");
		printf("Enter a choice\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			displayyearcalender();
		}
		else if(choice==2)
		{
			int m, y;
			printf("Enter month and year:\n");
			scanf("%d %d", &m, &y);
			displayspecificmonth(m, y);

		}
		else if(choice==3)
		{
			checkleapyear();
		}
		else if(choice==4)
		{
			finddayusingdate();
		}
		else if(choice==5)
		{
			addevent();
		}
		else if(choice==6)
		{
			displayevent();
		}
		else if(choice==7)
		{
			printf("Returning to console......\n");
			break;
		}
		else
			printf("Invalid input\n");
	} while(choice!=7);
	return 0;
}

