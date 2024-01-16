#include <stdio.h>

int main(){
    int date1, month1, year1, date2, month2, year2;
    int date_diff, month_diff, year_diff;
    scanf("%d/%d/%d\n%d/%d/%d",&date1, &month1, &year1, &date2, &month2, &year2);
    
    year_diff = year2 - year1;
    
    if(month1 > month2){
        year_diff--;
        month_diff = 12-month1+month2;
    }
    else if(month1 <= month2){
        month_diff = month2 - month1;
    }
    
    if(date1 > date2){
        month_diff--;
        if(month1 == 2 && (year1%400==0 || (year1%4==0 && year1%100 != 0))){
            date_diff = 29%date1 + date2;
        }
        else if(month1 == 2){
            date_diff = 28%date1 + date2;
        }
        else if((month1 <= 7 && month1%2 != 0)||(month1 > 7 && month1%2 == 0)){
            date_diff = 31%date1 + date2;
        }
        else{
            date_diff = 30%date1 + date2;
        }
    }
    else{
        date_diff = date2 - date1;
    }
    
    printf("%d years %d months and %d days.", year_diff, month_diff, date_diff);
    
    return 0;
}