#pragma once

#include <limits>

class Statistic
{
public:
    virtual ~Statistic(){}
    virtual void process(double) = 0;
    virtual double eval() const = 0;
};

class MinStatistics:public Statistic
{
public:
    void process(double val);
    double eval() const;
private:
    double min = std::numeric_limits<double>::max();
};

class MaxStatistics:public Statistic
{
public:
    void process(double val);
    double eval() const;
private:
    double max = std::numeric_limits<double>::min();
};

class MeanStatistics:public Statistic
{
public:
    void process(double val);
    double eval() const;
private:
    double sum = 0;
    int count = 0;
};
