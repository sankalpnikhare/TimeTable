#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    // Get current time
    time_t current_time = time(NULL);
    if (current_time == ((time_t)-1)) {
        printf("Error: Unable to get the current time.\n");
        return 1;
    }

    struct tm *local_time = localtime(&current_time);
    if (local_time == NULL) {
        printf("Error: Unable to convert time to local time.\n");
        return 1;
    }

    printf("Current Time: %02d:%02d\n", local_time->tm_hour, local_time->tm_min);

    // Get the current day of the week
    const char *weekDays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int currentDay = local_time->tm_wday;
    printf("Today is: %s\n", weekDays[currentDay]);

    // Define the timetable
    char timetable[5][8][10] = {
        {"Period 1", "Period 2", "Period 3", "Lunch", "Period 4", "Period 5", "Period 6", "Period 7"},
        {"Period 1", "Period 2", "Period 3", "Lunch", "Period 4", "Period 5", "Period 6", "Period 7"},
        {"Period 1", "Period 2", "Period 3", "Lunch", "Period 4", "Period 5", "Period 6", "Period 7"},
        {"Period 1", "Period 2", "Period 3", "Lunch", "Period 4", "Period 5", "Period 6", "Period 7"},
        {"Period 1", "Period 2", "Period 3", "Lunch", "Period 4", "Period 5", "Period 6", "Period 7"}
    };

    // Only check for weekdays (Monday to Friday)
    if (currentDay >= 1 && currentDay <= 5) {
        int period = -1;

        // Determine the current period based on time
        if (local_time->tm_hour == 9) period = 0;
        else if (local_time->tm_hour == 10) period = 1;
        else if (local_time->tm_hour == 11) period = 2;
        else if (local_time->tm_hour == 12) period = 3; // Lunch
        else if (local_time->tm_hour == 13) period = 4;
        else if (local_time->tm_hour == 14) period = 5;
        else if (local_time->tm_hour == 15) period = 6;
        else if (local_time->tm_hour == 16) period = 7;

        if (period == -1) {
            printf("No scheduled classes at this time.\n");
        } else {
            printf("Your current period is: %s\n", timetable[currentDay - 1][period]);
        }
    } else {
        printf("Enjoy your holiday!\n");
    }

    return 0;
}
