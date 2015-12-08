//Developed by narendravardi
//Since, c++ library does not support addition of two big integers, I have developed this function
//Takes two strings as arguments and returns the addition of those strings as a string.
//Time Complexity of the function is O(max(num_of_digits_in_string1,num_of_digits_in_string2))
#include<string>
#include<cmath>
#include<iostream>
#include<deque>
using namespace std;
//takes two strings and returns a string.
//deque is used. hence, dont forget to include it.
//deque is a datastructure that can be used to insert and delete at both the ends in constant time, which is available in c++ STL
string addBigints(string a,string b)
{

	deque<char> first,second;
	for(int i=0;i<a.size();++i)
	{
		first.push_back(a[i]);
	}
	for(int i=0;i<b.size();++i)
	{
		second.push_back(b[i]);
	}
	int n1=a.size();
	int n2=b.size();
	int diff=abs(n1-n2);
	//append zeros to string which has less number of digits to get two equal sized strings
	if(n1<n2)
	{
		for(int i=0;i<diff;++i)
			first.push_front('0');
	}
	else
	{
		for(int i=0;i<diff;++i)
			second.push_front('0');
	}

	int carry=0;
	int number;
	int digit;
	deque<char> result;
	for(int i=second.size()-1;i>=0;--i)
	{

		 number = first[i]-'0' + second[i]-'0' + carry;
		 digit = number%10;
		 carry = number/10;
		char c = digit+'0';
		result.push_front(c);
	}
	while(carry > 0)
	{
		int number = carry%10;
		result.push_front(number+'0');
		carry/=10;
	}
	string res;
	for(int i=0;i<result.size();++i)
		res.push_back(result[i]);

	return res;
}



int main()
{
	cout<<addBigints("123","23");
}
