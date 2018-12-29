#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int n,m;
struct matran
{
	int giatri;
	matran *tiep;
};
void khoitao(matran *&dau)
{
	dau=NULL;
}
void nhap(matran *&dau,int _dau)
{
	matran *p,*q;
	int giatri;
	printf("a[] : ",_dau);
	scanf("%d",&giatri);
	p=new matran;
	p->giatri=giatri;
	p->tiep=NULL;
	if(dau==NULL)
		dau=p;
	else
		q->tiep=p;
	q=p;
}
int dem(matran *dau)
{
	if(dau!=NULL)
	{
		if(dau->giatri!=0)
			return dem(dau->tiep);
		return 1+dem(dau->tiep);
	}
}
int kt(matran *dau,int i)
{
	if(i>=4)
	{
		float h=(float)i/2;
		if(h<=dem(dau))
			return 1;
		return 0;
	}
	else
		return 0;
}
void duyet(matran *dau)
{
	if(dau!=NULL)
	{	
		printf(" %3d",dau->giatri);
		duyet(dau->tiep);
	}
}
void nhan1(matran *dau,int k)
{
	matran *p;
	do
	{
		printf("Nhap mot so khac 0 :",k);
		scanf("%d",&k);
	}while(k==0);
	while(dau!=NULL)
	{
		if(dau->giatri!=0)
			dau->giatri=dau->giatri*k;
		p=dau;
		dau=dau->tiep;
	}
}
void nhapmatran(int a[][50],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void mang1(matran *dau,int a[50],int n)
{
	int i=0;
	while(dau!=NULL)
	{
		a[i]=dau->giatri;
		i++;
		dau=dau->tiep;
	}
}
void xuatmang2(int a[][50],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("% d",a[i][j]);
		printf("\n");
	}
}
void xuatmang3(int a[][50],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("% d",a[i][j]);
		printf("\n");
	}
}
void chuyenmang(int a[],int b[][50],int n)
{
	int k=sqrt(n);
	int l=k*k;
	if(n==l)
	{
		int index=0;
		if(index<n)
		{
			for(int i=0;i<k;i++)
				for(int j=0;j<k;j++)
					b[i][j]=a[index++];
		}
		xuatmang2(b,k);
	}
	else
	{
		if(n%2==0)
		{
			int m=n/2;
			int index=0;
			if(index<n)
			{
				for(int i=0;i<2;i++)
					for(int j=0;j<m;j++)
						b[i][j]=a[index++];
			}
			xuatmang3(b,2,m);
		}
	}
}
void nhanmatran(int a[][50],int b[][50],int c[][50],int n)
{
	
	int sum;
	int k=sqrt(n);
	int l=k*k;
	if(n==l)
	{
		nhapmatran(b,k);
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				sum=0;
				for(int h=0;h<k;k++)
				{
					sum=sum+a[i][h]*b[h][j];
				}
				c[i][j]=sum;
			}
		}
	}
	else
	{
		if(n%2==0)
		{
			int m=n/2;
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<m;j++)
				{
					sum=0;
					for(int h=0;h<m;k++)
					{
						sum=sum+a[i][h]*b[h][j];
					}
					c[i][j]=sum;
				}
			}
		}
	}
}
int main()
{
	matran *a;
	int k,i=0,j,l,q;
	int b[50][50],d[50][50],e[50][50];
	int c[50];
	khoitao(a);
	int chon;
	do
	{
		printf("1.Tao ma tran thua\n");
		printf("2.Hien thi ma tran thua\n");
		printf("3.Nhan ma tran voi mot so khac 0\n");
		printf("4.Nhan ma tran thua voi mot ma tran khac\n");
		printf("5.Thoat\n");
		printf("----------------------------------------\n");
		printf("Chon menu (1-5) : ",chon);
		scanf("%d",&chon);
		switch(chon)
		{
			case 1:
				a=NULL;
				printf("Nhap cac phan tu cua ma tran\n");
				do
				{
					nhap(a,i);
					i++;
				}while(kt(a,i)!=1);
				j=sqrt(i);
				if(i%2==0||i%j==0)
					printf("Da luu ket qua!\n");
				else
					printf("Day khong phai ma tran!\n");
				do
				{
					printf("1.Tao lai ma tran thua\n");
					printf("2.Hien thi ma tran thua\n");
					printf("3.Nhan ma tran voi mot so khac 0\n");
					printf("4.Nhan ma tran thua voi mot ma tran khac\n");
					printf("5.Thoat\n");
					printf("----------------------------------------\n");
					printf("Chon menu (1-5) : ",chon);
					scanf("%d",&chon);
					switch(chon)
					{
						case 1:
							a=NULL;
							printf("Nhap cac phan tu cua ma tran : \n");
							do
							{
								nhap(a,i);
								i++;
							}while(kt(a,i)!=1);
							j=sqrt(i);
							if(i%2==0||i%j==0)
								printf("Da luu ket qua!\n");
							else
								printf("Day khong phai ma tran!\n");
						case 2:
							if(a!=NULL)
							{
								mang1(a,c,i);
								printf("\n");
								chuyenmang(c,b,i);
							}
							break;
						case 3:
							nhan1(a,q);
							duyet(a);
							printf("\n");
							break;
						case 4:
							nhanmatran(b,d,e,i);
							break;
						case 5:
							break;
						default:
							printf("Muc lua chon khong ton tai, xin lua chon lai menu!\n");
					}
				}while(chon!=5);
			case 5:
				break;
			default:
				printf("Chua co du lieu!\n");
				break;
		}
	}while(chon!=5);
	return 0;
};
