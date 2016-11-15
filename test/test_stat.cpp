#include "stat.h"

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

typedef unique_ptr<Statistic> ptr_stat;

int main()
{
vector<ptr_stat> buf;

buf.push_back(ptr_stat(new MinStatistics));
buf.push_back(ptr_stat(new MaxStatistics));
buf.push_back(ptr_stat(new MeanStatistics));

vector<double> test;
ifstream is("test1.txt");

for(double val;is>>val;){
   for(auto &st:buf)
     st->process(val);
   test.push_back(val);
}
sort(test.begin(),test.end());
for_each(test.begin(),test.end(),[](const double&i){cout<<i<<endl;});
cout<<endl;
for(auto &st:buf){
    cout<<st->eval()<<' ';
}
cout<<'\n'<<endl;;
assert(buf[0]->eval() == test[0]);
cout<<"TEST_1_OK"<<endl;
assert(buf[1]->eval() == test[test.size()-1]);
cout<<"TEST_2_OK"<<endl;
double sum = 0;
int s = test.size();
for(int i = 0; i < s; ++i){
    sum += test[i];
}
assert(buf[2]->eval() == sum/s);
cout<<"TEST_3_OK"<<endl;

return 0;
}
