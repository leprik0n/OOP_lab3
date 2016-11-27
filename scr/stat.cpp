#include "stat.h"

#include <algorithm>

void MinStatistics::process(double val)
{
    min = std::min(min,val);
}

double MinStatistics::eval() const
{
    return min;
}

void MaxStatistics::process(double val)
{
    max = std::max(max,val);
}

double MaxStatistics::eval() const
{
    return max;
}

void MeanStatistics::process(double val)
{
    sum += val;
    ++count;
}

double MeanStatistics::eval() const
{
    return sum/count;
}
