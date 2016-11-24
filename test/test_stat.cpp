#include "stat.h"

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

int main()
{
vector<unique_ptr<Statistic> > buf;
buf.push_back(unique_ptr<Statistic>(new MinStatistics));
buf.push_back(unique_ptr<Statistic>(new MaxStatistics));
buf.push_back(unique_ptr<Statistic>(new MeanStatistics));

vector<double> test;
vector<double> vec(10);
vec[0] = 0.0; vec[4] = -23.34;
vec[1] = 42.2; vec[5] = -12.286;
vec[2] = 6.6;  vec[6] = 89.9;
vec[3] = 0.00; vec[7] = 8.0001;
vec[8] = 0.012; vec[9] = 10;
int sk = vec.size();
   
for(int i = 0; i < sk; i++){
   for(auto &st:buf)
     st->process(vec[i]);
   test.push_back(vec[i]);
}
sort(test.begin(),test.end());
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

   
   //cout<<"buf[0]->eval()==>"<<' '<<buf[0]->eval()<<endl;
return 0;
}
