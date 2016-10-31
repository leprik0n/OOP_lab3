#ifndef STAT_H_
#define STAT_H_
#include <vector>

using namespace std;
class statistic
{
public:
      virtual void process(double)=0;
      virtual void result()=0;  //return res;
};

class mini:public statistic
{
public:
      void process(double);
      void result();
private:
       std::vector<double> vec2;
};

class maxi:public statistic
{
public:
      void process(double);
      void result();
private:
      std::vector<double> vec1;
};

class ang:public statistic
{
public:
      void process(double); 
      void result();
private:
      std::vector<double> vec3;
};

#endif
