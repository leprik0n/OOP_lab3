#include "stat.h"

#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include <random>
#include <algorithm>
using namespace std;

typedef unique_ptr<Statistic> ptr_stat;

int main()
{
vector<ptr_stat> buf;

buf.push_back(ptr_stat(new MinStatistics));
buf.push_back(ptr_stat(new MaxStatistics));
buf.push_back(ptr_stat(new MeanStatistics));

vector<double> rval(30);
for_each(rval.begin(),rval.end(),[](double&i){return i = 5.16+rand()%32-20.25;});
for_each(rval.begin(),rval.end(),[](const double&i){cout<<i<<endl;});
cout<<endl;
int s = rval.size();
for(int i = 0; i < s; ++i){
   for(auto &st:buf)
     st->process(rval[i]);
}
cout<<endl;
for(auto &st:buf){
    cout<<st->eval()<<' ';
}
return 0;
}
