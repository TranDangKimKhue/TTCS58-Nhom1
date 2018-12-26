#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
ofstream g ("output3.txt");
struct nhanvien
{
	int manv, tienluong;
	char holot[30],ten[10];
};
void nhap(nhanvien a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhan vien "<<i+1<<endl;
		cout<<"Ma so nhan vien : ";	cin>>a[i].manv;
		cin.ignore();
		cout<<"Ho lot : ";	cin.getline(a[i].holot,30);
		cout<<"Ten : ";	cin.getline(a[i].ten,10);
		cout<<"Tien luong : ";	cin>>a[i].tienluong;
	}
	ofstream f;
	f.open("input3.txt");
	for(int i=0;i<n;i++)
	{
		f<<"Ma nhan vien : "<<a[i].manv<<endl;
		f<<"Ho lot : "<<a[i].holot<<endl;
		f<<"Ten : "<<a[i].ten<<endl;
		f<<"Tien luong : "<<a[i].tienluong<<endl;
	}
	f.close();
}
void timkiemmanv(nhanvien a[],int n)
{
	int x;
	cout<<"Nhap ma nhan vien can tim : ";	cin>>x;
	g<<x;
	for(int i=0;i<n;i++)
	{
		if(x==a[i].manv)
		{
			cout<<"Ma nhan vien : "<<a[i].manv<<endl<<"Ho lot : "<<a[i].holot<<endl<<"Ten : "<<a[i].ten<<endl<<"Tien luong : "<<a[i].tienluong<<endl;
			g<<"Ma nhan vien : "<<a[i].manv<<endl<<"Ho lot : "<<a[i].holot<<endl<<"Ten : "<<a[i].ten<<endl<<"Tien luong : "<<a[i].tienluong<<endl;
		}
		
	}
}
void maxmin(nhanvien a[],int n)
{
	int max=a[0].tienluong,index;
	for(int i=0;i<n;i++)
	{
		if(max<a[i].tienluong)
		{
			max=a[i].tienluong;
			index=i;
		}
	}
	int min=a[0].tienluong,index1;
	for(int j=0;j<n;j++)
	{
		if(min>a[j].tienluong)
		{
			min=a[j].tienluong;
			index1=j;
		}
	}
	cout<<"MAX : "<<max<<"\t"<<a[index].manv<<"\t"<<a[index].holot<<"\t"<<a[index].ten<<endl;
	g<<"MAX : "<<max<<"\t"<<a[index].manv<<"\t"<<a[index].holot<<"\t"<<a[index].ten<<endl;
	cout<<"MIN : "<<min<<"\t"<<a[index1].manv<<"\t"<<a[index1].holot<<"\t"<<a[index1].ten<<endl;
	g<<"MIN : "<<min<<"\t"<<a[index1].manv<<"\t"<<a[index1].holot<<"\t"<<a[index1].ten<<endl;
}
void sapxep(nhanvien a[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(strcmp(a[i].ten,a[j].ten)>0)
				swap(a[i],a[j]);
			else
			{
				if(strcmp(a[i].ten,a[j].ten)==0)
				{
					if(strcmp(a[i].holot,a[j].holot)>0)
						swap(a[i],a[j]);
				}
			}
}
void xuat(nhanvien a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i].manv<<"\t"<<a[i].holot<<"\t"<<a[i].ten<<"\t"<<a[i].tienluong<<endl;
		g<<a[i].manv<<"\t"<<a[i].holot<<"\t"<<a[i].ten<<"\t"<<a[i].tienluong<<endl;
	}
}
void menu(nhanvien a[],int n)
{
	int chon;
	do
	{
		cout<<"1.Nhap thong tin nhan vien vao danh sach"<<endl;
		cout<<"2.Tim kiem thong tin nhan vien qua MA NHAN VIEN"<<endl;
		cout<<"3.Thong tin nhan vien co luong cao nhat va nhan vien co luong thap nhat"<<endl;
		cout<<"4.Sap xep ten nhan vien theo thu tu tang dan theo ten (theo ho)"<<endl;
		cout<<"5.Thoat"<<endl;
		cout<<"------------------------------------------------------------------------"<<endl;
		cout<<"Chon muc tu menu: ";	cin>>chon;
		switch(chon)
		{
			case 1:
				nhap(a,n);
				cout<<"Du lieu da ghi vao file input3.txt"<<endl;
				break;
			case 2:
				timkiemmanv(a,n);
				break;
			case 3:
				maxmin(a,n);
				break;
			case 4:
				sapxep(a,n);
				xuat(a,n);
			case 5:
				cout<<"Ket thuc"<<endl;
				break;
			default:
				cout<<"Muc ban lua chua khong ton tai! Xin lua chon lai memu :"<<endl;
				break;
		}
	}while(chon!=5);
	g.close();
}
int main()
{
	int n,x;
	do
	{
		cout<<"So luong nhan vien : ";
		cin>>n;
	}while(n>50);
	nhanvien a[n];
	menu(a,n);
	getch();
	return 0;
}
