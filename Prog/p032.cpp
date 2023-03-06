#include "interval.h"
#include <iostream>
using namespace std;

bool earlier(time_of_day t1, time_of_day t2){
    if (t1.h==t2.h && t1.m>t2.m) {
        return false; 
    }
    else if (t1.h>t2.h) {
        return false;  
    }

    return true;    
}

interval intersection(interval a, interval b){
    interval intt={{00,00}, {00,00}};
    if (earlier(a.start, b.start)){
        intt.start=b.start;

        if (earlier(a.end, b.end)) intt.end=a.end;
        else intt.end=b.end;
        
        if (earlier(a.end, b.start)) intt={{00,00}, {00,00}};

    }

    else if (earlier(b.start, a.start)){
        intt.start=a.start;

        if (earlier(b.end, a.end)) {
            intt.end=b.end;
        }
        else {
            intt.end=a.end;
        } 
        
        if (earlier(b.end, a.start)) {
            intt={{00,00}, {00,00}};
        }

    }

    return intt;
}

int main(){
    return 0;
}