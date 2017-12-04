/*Exponentiation
description 
Problems involving the computation of exact values of very large magnitude and precision are common. For example, the computation of the national debt is a taxing experience for many computer systems. 

This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i,lend,digit,j,u,x,lenc,n,lenb;
	bool flag;
	string d;
	int c[1000],a[1000],b[1000];
	while(cin>>d>>n)
	{
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		flag=0;
		lend=d.length()-1;
		for(i=0;i<=lend;i++)
		{
			if(d[i]=='.')break;
		}
		digit=lend-i;
		for(;i<=lend;i++)
		{
			d[i]=d[i+1];
		}
		lend--;
		for(i=lend;i>=0;i--)
		{
			a[i]=d[lend-i]-48;
			b[i]=a[i];
		}
		lenb=lend;
		/*for(i=0;i<lend;i++)cout<<a[i];
		cout<<endl;*/
		for(i=1;i<=n-1;i++)
		{
			for(j=0;j<=lenb;j++)
			{
				for(u=0;u<=lend;u++)
				{
					c[j+u]+=a[u]*b[j];
					c[j+u+1]+=c[j+u]/10;
					c[j+u]%=10;
				}
			}
		j--;u--;
		if(c[u+j+1]!=0)lenc=j+u+1;
		else lenc=j+u;
		for(j=0;j<=lenc;j++)b[j]=c[j]; 
		lenb=lenc;
		memset(c,0,sizeof(c));
		}
		digit=n*digit;
		int len=lenc+1-digit;
		for(i=lenc-len;i>=0;i--)
			if(b[i]!=0)
			{
				flag=1;break; 
			}
		if(flag==0)
		{	
			for(i=lenc;i>=lenc-len+1;i--)
			cout<<b[i];
			cout<<endl;
			continue;
		}
		if(len==1&&b[lenc]==0)cout<<".";
		else
		{
			for(i=lenc;i>=lenc-len+1;i--)cout<<b[i];
			cout<<".";
		}
		for(i=0;i<=lenc-len;i++)
		{
			if(b[i])
			{
				j=i;
				break;
			}
		}
		for(i=lenc-len;i>=j;i--)
		{
			cout<<b[i];
		}
		cout<<endl;
	}
}
