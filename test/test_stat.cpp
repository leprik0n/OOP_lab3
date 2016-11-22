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
ifstream is("mas.txt");
   
for(double val;is>>val;){
   for(auto &st:buf)
     st->process(val);
   test.push_back(val);
}
sort(test.begin(),test.end());
/*assert(buf[0]->eval() == test[0]);
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
*/
cout<<"buf[0]->eval min==>"<<buf[0]->eval()<<endl;   
cout<<"buf[1]->eval max==>"<<buf[1]->eval()<<endl;  
cout<<"buf[2]->eval avg==>"<<buf[2]->eval()<<endl;     
return 0;
}
