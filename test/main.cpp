#include "stat.h"

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <exception>
using namespace std;


unique_ptr<Statistic> func(string name)
{
    if(name == "min"){
        return unique_ptr<Statistic>(new MinStatistics);
    }
    if(name == "max"){
        return unique_ptr<Statistic>(new MaxStatistics);
    }
    if(name == "avg"){
        return unique_ptr<Statistic>(new MeanStatistics);
    }
    else{
        throw std::invalid_argument("name is != (min or max or avg)");
    }
}


int main(int argc,char**argv)
{
try{

vector<unique_ptr<Statistic> > buf;
for(int i = 1; i < argc; ++i){
   buf.push_back(func(argv[i]));
}
if(buf.size() == 0)
   throw invalid_argument("argc == 0");

for(double val;cin>>val;){
   for(auto &st:buf)
     st->process(val);
}

 for(auto &s:buf){
     cout<<s->eval()<<' '<<endl;
 }
}

catch(std::invalid_argument &oop){
     cout<<"exception:"<<oop.what()<<endl;
}

return 0;
}
