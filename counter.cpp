//Developed by Narendra Vardi
//equality operator should be overloading in order to make this function work for user defined data types
#include<vector>
#include<map>
#include<iostream>
#include<cstdio>
using namespace std;

template<class T>
map<T,int> counter(vector<T> a)
{
	map<T,int> b;
	pair< typename map<T,int>::iterator ,bool> pos;
	for(int i=0;i<a.size();++i)
	{
		pos=b.insert(make_pair(a[i],1));
		if(!(pos.second))
		{
			b[pos.first -> first]++;
		}
	}
	return b;
}

void test_for_int()
{
	vector<int> a;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	map<int,int> b = counter(a);
	map<int,int>::iterator pos;
	pos = b.begin();
	for(;pos!=b.end();++pos)
		cout<<pos->first<<" "<<pos->second<<"\n";
}

void test_for_string()
{
	vector<string> a;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		string temp;
		cin>>temp;
		a.push_back(temp);
	}
	map<string,int> b = counter(a);
	map<string,int>::iterator pos;
	pos = b.begin();
	for(;pos!=b.end();++pos)
		cout<<pos->first<<" "<<pos->second<<"\n";
}

void test_for_char()
{
	vector<char> a;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		char temp;
		cin>>temp;
		a.push_back(temp);
	}
	map<char,int> b = counter(a);
	map<char,int>::iterator pos;
	pos = b.begin();
	for(;pos!=b.end();++pos)
		cout<<pos->first<<" "<<pos->second<<"\n";
}

int main()
{
  test_for_string();
  test_for_int();
  test_for_char();

	return 0;
}
