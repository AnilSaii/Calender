#include <stdio.h>

int main(void)
{
    // Bring the user input
    int year = 0;
    printf("Enter a year of your choice : ");
    scanf("%d", &year);

    // Initialize Months array
    char * months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Initialize a array for storing number of days in a specific month for all months
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check wheather the year is a leap year. If so, update february in monthDays
    if (year % 4 == 0)
    {
        monthDays[1] = 29;
    }

    // Got this from internet. I don't know anything about this condition. But i am guessing this one works for every year.
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        monthDays[1]=29;
    }

    // Calculate starting day of the year
    int startingDay = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;

    // Define a variable to keep track the day
    int track = -1;

    // Print Everything
    for (int i = 0; i < 12; i++)
    {
        printf("\n\n________________________%s______________________________\n\n", months[i]);
        printf("\n      Sun     Mon     Tue     Wed    Thurs     Fri     Sat\n\n");

        // Print the spaces if required
        for (int k = 0; k < startingDay; k++)
        {
            printf("        ");
            track = track + 1;
        }
        
        // Print all the dates under every month
        for (int j = 1; j <= monthDays[i]; j++)
        {
            track = track + 1;
            printf("%8d", j);
            if (track > 5)
            {
                printf("\n\n");
                track = -1;
            }
        }
        // Set the starting day to the previous month last day
        startingDay = track + 1;

        // Reset the tracker to its intial value
        track = -1;
    }
    printf("\n\n\n\n");
    printf("____________________This is the End of the Calender____________________");
    printf("\n\n\n\n");
    return 0;
}
