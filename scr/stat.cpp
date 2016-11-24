#include "stat.h"

#include <vector>

const double& Min(const double &a,const double &b)
{
    return ((a > b) ? b : a);
}

const double& Max(const double &a,const double &b)
{
    return ((a > b) ? a : b);
}

void MinStatistics::process(double val)
{
    static std::vector<double> mas;
    if(mas.size() == 0){
        mas.push_back(val);
        return;
    }
    if(mas.size() == 1){
        mas.push_back(val);
        min = Min(mas[0],mas[1]);
        return;
    }
    mas[1] = val;
    double m = Min(mas[0],mas[1]);
    if(min > m){
        min = m;
    }
}

double MinStatistics::eval()const
{
    return min;
}

void MaxStatistics::process(double val)
{
       static std::vector<double> mas;
    if(mas.size() == 0){
        mas.push_back(val);
        return;
    }
    if(mas.size() == 1){
        mas.push_back(val);
        max = Max(mas[0],mas[1]);
        return;
    }
    mas[1] = val;
    double m = Max(mas[0],mas[1]);
    if(max < m){
        max = m;
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

