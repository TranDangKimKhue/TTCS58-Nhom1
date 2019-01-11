#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
void LRS(char X[],int n);
void inKetQua(char X[],int a[][255],int n);
void LRS(char X[],int n)
{
	int TS[n+1][n+1],LV[n+1][n+1];
	//khoi tai mang TRONG SO va LUU VET
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			TS[i][j]=0;
			LV[i][j]=0;
		}
	}
	//LRS
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(X[i-1]==X[j-1]&&i==j)
			{
				TS[i][j]=TS[i][j-1];
				LV[i][j]=2;
			}
			else if(X[i-1]==X[j-1]&&i!=j)
			{
				TS[i][j]=TS[i-1][j-1]+1;
				LV[i][j]=1;
			}
			else
			{
				if(TS[i][j-1]>TS[i-1][j])
				{
					TS[i][j]=TS[i][j-1];
					LV[i][j]=2;
				}
				else
				{
					TS[i][j]=TS[i-1][j];
					LV[i][j]=3;
				}
			}
		}
	}
	cout<<"Ma tran trong so"<<endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			cout<<" "<<TS[i][j];
		cout<<endl;
	}
	cout<<"Ma tran luu vet"<<endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			cout<<" "<<LV[i][j];
		cout<<endl;
	}
	//truy vet
	int a[255][255];
	int i=n,j=n;
	int itam=0;
	char tam[255];
	while(i>0&&j>0)
	{
		if(LV[i][j]==1)
		{
			cout<<X[i-1];
			i--;
			j--;
		}
		else if(LV[i][j]==2)
		{
			j--;
		}
		else
		{
			i--;
		}
	}
}
int main()
{
	char X[255];
	cout<<"X : ";	cin.getline(X,255);
	int n=strlen(X);
	LRS(X,n);
	return 0;
}
