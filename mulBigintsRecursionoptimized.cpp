//Developed by Narendra Vardi 
//optimised version of multiplying two Bigintegers in c++

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
string to_string(int num)
{
	string result;
	while(num > 0)
	{
		int remainder = num %10;
		result.push_back(remainder+'0');
		num/=10;
	}
	reverse(result.begin(),result.end());
	return result;
}
string addBigint(string a,string b)
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
	//printdeque(first);
	//printdeque(second);
	int carry=0;
	int temp;
	int digit;
	deque<char> result;
	for(int i=second.size()-1;i>=0;--i)
	{

		 temp = first[i]-'0' + second[i]-'0' + carry;
		 digit = temp%10;
		 carry = temp/10;
		char c = digit+'0';
		result.push_front(c);
	}
	while(carry > 0)
	{
		int temp = carry%10;
		result.push_front(temp+'0');
		carry/=10;
	}
	string res;
	for(int i=0;i<result.size();++i)
		res.push_back(result[i]);

	return res;
}


string mulBigint(string num1,string num2)
{
	int size1 = num1.size();
	int size2 = num2.size();
	int diff = abs(size1-size2);
	if(size1==1 && size2==1)
	{
		return to_string((num1[0]-'0')*(num2[0]-'0'));
	}
	else if(size1 < size2)
	{
		for(int i=0;i<diff;++i)
			num1.push_back('0');
	}
	else if(size2 < size1)
	{
		for(int i=0;i<diff;++i)
			num2.push_back('0');
	}
	int n = num1.size();
	if(n%2==1)
	{
		num1.push_back('0');
		num2.push_back('0');
		diff+=2;
		n++;
	}
	
		int mid = n/2;
		string a,b,c,d;
		for(int i=0;i<mid;++i)
			a.push_back(num1[i]);
		for(int i=mid;i<n;++i)
			b.push_back(num1[i]);
		for(int i=0;i<mid;++i)
			c.push_back(num2[i]);
		for(int i=mid;i<n;++i)
			d.push_back(num2[i]);
		string coeff1,coeff2;
		for(int i=0;i<n;++i)
			coeff1.push_back('0');
		for(int i=0;i<n/2;++i)
			coeff2.push_back('0');
		string first = mulBigint(a,c)+coeff1;
		string third = mulBigint(b,d);
		string extra1 = mulBigint(a,d);
		string extra2 = mulBigint(b,c); 
		string second = addBigint(extra1,extra2)+coeff2;
		string res="0";
		res = addBigint(res,first);
		res = addBigint(res,second);
		res = addBigint(res,third);
		string result;
		for(int i=0;i<res.size()-diff;++i)
			result.push_back(res[i]);
		return result;

}
int main()
{
	cout<<mulBigint("1232421","234324")<<"\n";
	return 0;
}
