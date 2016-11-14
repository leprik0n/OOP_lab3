#include "stat.h"

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

typedef unique_ptr<Statistic> ptr_stat;

int main(int avgc,char**argv)
{
vector<ptr_stat> buf;
buf.push_back(ptr_stat(new MinStatistics));
buf.push_back(ptr_stat(new MaxStatistics));
buf.push_back(ptr_stat(new MeanStatistics));

for(double val;cin>>val;){
   for(auto &st:buf)
     st->process(val);
}
cout<<endl;
for(auto &s:buf)
    cout<<s->eval()<<endl;

return 0;
}
