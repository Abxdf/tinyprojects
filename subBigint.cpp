//Developed by Narendra Vardi
//Bigint Substration in c++

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
void swap1(string &a,string &b)
{
string temp =a;
a=b;
b=temp;
return;
}
string subBigint(string a,string b)
{
bool minus = false;
int i=0,j=0;
while(a[i++]=='0');
i--;
while(b[j++]=='0');
j--;
string num1,num2;
for(int k=i;k<a.size();++k)
{
num1.push_back(a[k]);
}
for(int k=j;k<b.size();++k)
{
num2.push_back(b[k]);
}



if( (num1 < num2 && num1.size()==num2.size()) || num1.size() < num2.size())
{
minus=true;
swap1(num1,num2);
}
reverse(num1.begin(),num1.end());
reverse(num2.begin(),num2.end());
a=num1;
b=num2;
string c;
for(int i=0;i<num2.size();++i)
{
if(a[i] < b[i])
{
a[i+1]--;
a[i]+=10;
c.push_back(a[i]-b[i]+'0');
}
else
{
c.push_back(a[i]-b[i]+'0');
}
}
for(int i=num2.size();i<num1.size();++i)
{
if(a[i] < '0')
{
a[i+1]--;
a[i]+=10;
c.push_back(a[i]);
}
else
{
c.push_back(a[i]);
}
}
reverse(c.begin(),c.end());
 i=0;
while(c[i]=='0')
i++;
string res;
if(minus)
res.push_back('-');

for(int k=i;k<c.size();k++)
res.push_back(c[k]);

return res;
}


int main()
{
cout<<subBigint("122","111111111111");
return 0;
}
