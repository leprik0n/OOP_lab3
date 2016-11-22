#include "stat.h"

void MinStatistics::process(double val)
{
    static double first = val;
    if(first == val){
        if(min < first){
            goto mark;
        }
        else{
            min = first;
        }
    }
    mark:
    if(min > val){
        min = val;
    }
}

double MinStatistics::eval()const
{
    return min;
}

/*void MaxStatistics::process(double val)
{
    static double first = val;
    if(val == first){
        if(max > first){
            goto mark;
        }
        else{
            max = first;
        }
    }
    mark:
    if(max < val){
        max = val;
    }
}

double MaxStatistics::eval()const
{
    return max;
}

void MeanStatistics::process(double val)
{
    sum += val;
    ++count;
}

double MeanStatistics::eval()const
{
    return sum/count;
}
*/
