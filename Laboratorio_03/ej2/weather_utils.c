#include <stdio.h>
#include <stdbool.h>

#include "array_helpers.h"
#include "weather_utils.h"



int min_temp_hist(WeatherTable weather){
    int tempMinHist = weather[0][0][0]._min_temp;
    for(unsigned int year = 0; year < YEARS; ++year){
        for(unsigned int month = 0; month < MONTHS; ++month){
            for(unsigned int day = 0; day < DAYS; ++day){

                int tempNow = weather[year][month][day]._min_temp;
                if(tempNow < tempMinHist){
                    tempMinHist = tempNow;
                }
            }
        }   
    }
    return tempMinHist;
}

void proc_max_anual(WeatherTable a, int output[YEARS]) {
    for (unsigned int year = 0; year < YEARS; ++year) {
        int max_t = 0;
        for(unsigned int month = 0; month < MONTHS; ++month){
            for(unsigned int day = 0; day < DAYS; ++day){
                
                int tempNow = a[year][month][day]._max_temp;
                if(tempNow > max_t){
                    max_t = tempNow;
                }
            }
        }
        output[year] = max_t;
    }
}

void proc_max_pres_m(WeatherTable a, int output[YEARS]){
    for (unsigned int year = 0; year < YEARS; ++year) {
        unsigned int maxpermonth = 0;
         for(unsigned int month = 0; month < MONTHS; ++month){
            unsigned int maxperday = 0; 
            for(unsigned int day = 0; day < DAYS; ++day){
                maxperday += a[year][month][day]._rainfall;
            }
            if(maxperday > maxpermonth){
                output[year] = month+1;
                maxpermonth = maxperday;
            }
            
        }
    }
}