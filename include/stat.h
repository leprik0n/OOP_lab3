#pragma once
class Statistic
{
public:
    virtual ~Statistic(){}
    virtual void process(double)=0;
    virtual double eval()const=0;
};

class MinStatistics:public Statistic
{
public:
    void process(double val);
   	double eval()const;
private:
    double min;
};

class MaxStatistics:public Statistic
{
public:
	void process(double val);
	double eval()const;
private:
    double max;
};

class MeanStatistics:public Statistic
{
public:
    void process(double val);
    double eval()const;
private:
    double sum = 0;
    int count = 0;
};
