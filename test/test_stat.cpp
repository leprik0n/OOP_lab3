#include "stat.h"

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

void test_min_min(vector<double> test)
{
    vector<unique_ptr<Statistic> > buf;
    buf.push_back(unique_ptr<Statistic>(new MinStatistics));
    buf.push_back(unique_ptr<Statistic>(new MinStatistics));
    int sk = test.size();
    for(int i = 0; i < sk; i++){
        for(auto &st:buf){
            st->process(test[i]);
        }
    }
    assert(buf[0]->eval() == test[0]);
    assert(buf[1]->eval() == test[0]);
    cout<<"TEST_1_OK"<<endl;
}

void test_max_max(vector<double> test)
{
    vector<unique_ptr<Statistic> > buf;
    buf.push_back(unique_ptr<Statistic>(new MaxStatistics));
    buf.push_back(unique_ptr<Statistic>(new MaxStatistics));
    int sk = test.size();
    for(int i = 0; i < sk; i++){
        for(auto &st:buf){
            st->process(test[i]);
        }
    }
    assert(buf[0]->eval() == test[test.size()-1]);
    assert(buf[1]->eval() == test[test.size()-1]);
    cout<<"TEST_2_OK"<<endl;
}

void test_avg_avg(vector<double> test)
{
    vector<unique_ptr<Statistic> > buf;
    buf.push_back(unique_ptr<Statistic>(new MeanStatistics));
    buf.push_back(unique_ptr<Statistic>(new MeanStatistics));
    int sk = test.size();
    double sum = 0;
    int c = test.size();
    for(int i = 0; i < sk; i++){
        for(auto &st:buf){
            st->process(test[i]);
        }
        sum += test[i];
    }
    assert(buf[0]->eval() == sum/c);
    assert(buf[1]->eval() == sum/c);
    cout<<"TEST_3_OK"<<endl;
}

void test_min_max(vector<double> test)
{
    vector<unique_ptr<Statistic> > buf;
    buf.push_back(unique_ptr<Statistic>(new MinStatistics));
    buf.push_back(unique_ptr<Statistic>(new MaxStatistics));
    int sk = test.size();
    for(int i = 0; i < sk; i++){
        for(auto &st:buf){
            st->process(test[i]);
        }
    }
    assert(buf[0]->eval() == test[0]);
    assert(buf[1]->eval() == test[test.size()-1]);
    cout<<"TEST_4_OK"<<endl;
}

void test_min_avg(vector<double> test)
{
    vector<unique_ptr<Statistic> > buf;
    buf.push_back(unique_ptr<Statistic>(new MinStatistics));
    buf.push_back(unique_ptr<Statistic>(new MeanStatistics));
    int sk = test.size();
    double sum = 0;
    int c = test.size();
    for(int i = 0; i < sk; i++){
        for(auto &st:buf){
            st->process(test[i]);
        }
        sum += test[i];
    }
    assert(buf[0]->eval() == test[0]);
    assert(buf[1]->eval() == sum/c);
    cout<<"TEST_5_OK"<<endl;
}

void test_max_avg(vector<double> test)
{
    vector<unique_ptr<Statistic> > buf;
    buf.push_back(unique_ptr<Statistic>(new MaxStatistics));
    buf.push_back(unique_ptr<Statistic>(new MeanStatistics));
    int sk = test.size();
    double sum = 0;
    int c = test.size();
    for(int i = 0; i < sk; i++){
        for(auto &st:buf){
            st->process(test[i]);
        }
        sum += test[i];
    }
    assert(buf[0]->eval() == test[test.size()-1]);
    assert(buf[1]->eval() == sum/c);
    cout<<"TEST_6_OK"<<endl;
}

void test_max_min_avg(vector<double> test)
{
    vector<unique_ptr<Statistic> > buf;
    buf.push_back(unique_ptr<Statistic>(new MaxStatistics));
    buf.push_back(unique_ptr<Statistic>(new MinStatistics));
    buf.push_back(unique_ptr<Statistic>(new MeanStatistics));
    int sk = test.size();
    double sum = 0;
    int c = test.size();
    for(int i = 0; i < sk; i++){
        for(auto &st:buf){
            st->process(test[i]);
        }
        sum += test[i];
    }
    assert(buf[0]->eval() == test[test.size()-1]);
    assert(buf[1]->eval() == test[0]);
    assert(buf[2]->eval() == sum/c);
    cout<<"TEST_7_OK"<<endl;
}

int main()
{

vector<double> vec(15);

vec[0] = 0.0;    vec[4] = -23.34;
vec[1] = 42.2;   vec[5] = -12.286;
vec[2] = 6.6;    vec[6] = 89.9;
vec[3] = 0.00;   vec[7] = 8.0001;
vec[8] = 0.012;  vec[9] = 10;
vec[10] = 3.21;  vec[11] = 7.89;
vec[12] = .0213; vec[13] = 0.123;
vec[14] = .76;

sort(vec.begin(),vec.end());

test_min_min(vec);
test_max_max(vec);
test_avg_avg(vec);
test_min_max(vec);
test_min_avg(vec);
test_max_avg(vec);
test_max_min_avg(vec);

return 0;
}
