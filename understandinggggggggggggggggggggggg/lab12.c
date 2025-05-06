#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int day_of_week(int year, int month, int day) { // Алгоритм Зеллера
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + 13*(month + 1)/5 + K + K/4 + 5*J + J/4) % 7;
    return (h + 5) % 7;
}

const char *weekday_name(int wday){
	const char *names[] = {"Monday", "Tuesday", 
						"Wednesday", "Thursday",
						"Friday", "Saturday", "Sunday"};
	return names[wday];
}

const char *month_name(int month){
	const char *names[] = {"January", "February", 
						"March", "April",
						"May", "June", "July", 
						"September", "October", "November", "December"};
	return names[month-1];
}

int days_in_month(int year, int month) {
	if (month == 2)
		return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
}

void print_month_calendar(int year, int month) {
	printf("\n      %s %d\n", month_name(month), year);
	printf("Mon Tue Wed Thu Fri Sat Sun \n");
	
	int first_day = day_of_week(year, month, 1);
	int num_days = days_in_month(year, month);
	
	for (int i = 0; i < first_day; i++){
		printf("    ");
	}
	
	for (int day = 1; day <= num_days; day++){
		printf("%2d  ", day);
		if((first_day + day) % 7 == 0 || day == num_days) {
			printf("\n");
		}
	}
}

void print_year_calendar(int year){
	for (int m = 1; m <= 12; m++){
		print_month_calendar(year, m);
		printf("\n");
	}
}

void get_current_date(int *year, int *month, int *day){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	*year = tm.tm_year + 1900;
	*month = tm.tm_mon + 1;
	*day = tm.tm_mday;
}

int main(){
	char input[32];
	
	printf("Input date in format:\n");
	printf(" yyyy.mm.dd		- day of week\n");
	printf(" yyyy.mm		- calendar of month\n");
	printf(" yyyy			- calendar of year\n");
	printf(" now			- today date\n");
	scanf("%s", input);

//	NOW
	if(strlen(input) == 3){
		int year, month, day;
		get_current_date(&year, &month, &day);
		printf("Current date: %04d.%02d.%02d\n", year, month, day);
		print_month_calendar(year, month);

//	YYYY
	} else if (strlen(input) == 4) {
		int year =  atoi (input);
		if (year >= 1 && year <= 9999)
			print_year_calendar(year);
		else
			printf("Incorrect year\n");
		
//	YYYY.MM
	} else if (strlen(input) == 7) { 
        int year = atoi(input);
        int month = atoi(input + 5);
        if (year >= 1 && year <= 9999 && month >= 1 && month <= 12)
            print_month_calendar(year, month);
        else
            printf("Incorrent date.\n");
		
//	YYYY.MM.DD
	} else if (strlen(input) == 10) {
        int year = atoi(input);
        int month = atoi(input + 5);
        int day = atoi(input + 8);
        if (year >= 1 && year <= 9999 && month >= 1 && month <= 12 &&
            day >= 1 && day <= days_in_month(year, month)) {
            int wday = day_of_week(year, month, day);
            printf("Date: %04d.%02d.%02d - %s\n", year, month, day, weekday_name(wday));
        } else {
            printf("Incorrent date.\n");
        }
    } else {
        printf("Error.\n");
    }

    return 0;
}

