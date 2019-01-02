#include<iostream>
using namespace std;
#include<fstream>
struct nhanVien
{
	int maNv;
	char hoTen[30];
	int tuoi;
	int luongCb;
};
ofstream k ("output2.txt");
void nhap(nhanVien a[],int &n);
void themNv(nhanVien a[],int &n);
void xoaNv(nhanVien a[],int &n);
void capNhatNv(nhanVien a[],int n);
void timKiemNv(nhanVien a[],int n);
void ghifile(char *file,nhanVien a[],int n);
void ghifile1(char *file,nhanVien a[],int n,char *s);
void nhap(nhanVien a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Ma nhan vien : ";	cin>>a[i].maNv;
		fflush(stdin);
		cout<<"Ho ten nhan vien : ";	cin.getline(a[i].hoTen,30);
		cout<<"Tuoi : ";	cin>>a[i].tuoi;
		cout<<"Luong : ";	cin>>a[i].luongCb;
	}
}
void inDanhSachNv(nhanVien a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<a[i].maNv<<"\t"<<" "<<a[i].hoTen<<"\t\t    "<<a[i].tuoi<<"\t"<<a[i].luongCb<<endl;
	}
	cout<<endl;
}
void themNv(nhanVien a[],int &n)
{
	int x;
	cout<<"Vi tri can them : ";	cin>>x;
	if(x>=0&&x<=n)
	{
		for(int i=x;i<n;i++)
			a[i+1]=a[i];
		cout<<"Ma nhan vien : ";	cin>>a[x].maNv;
		fflush(stdin);
		cout<<"Ho ten nhan vien : ";	cin.getline(a[x].hoTen,30);
		cout<<"Tuoi : ";	cin>>a[x].tuoi;
		cout<<"Luong : ";	cin>>a[x].luongCb;
		n++;
		cout<<"Danh sach nhan vien sau khi them"<<endl;
		k<<"Sau khi them mot nhan vien vao danh sach : "<<endl;
		k<<"---------------------------------------------"<<endl;
		k<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
		for(int j=0;j<n;j++)
			k<<a[j].maNv<<"\t"<<" "<<a[j].hoTen<<"\t\t    "<<a[j].tuoi<<"\t"<<a[j].luongCb<<endl;
		inDanhSachNv(a,n);
	}
	else
		cout<<"Vi tri nay khong the them!"<<endl;
}
void xoaNv(nhanVien a[],int &n)
{
	int x,index;
	cout<<"Ma nhan vien can xoa : ";
	cin>>x;
	for(int i=0;i<n;i++)
		if(a[i].maNv==x)
			a[i]=a[i+1];
	n--;
	cout<<"Danh sach nhan vien sau khi xoa"<<endl;
	k<<"Sau khi xoa mot nhan vien vao danh sach : "<<endl;
	k<<"---------------------------------------------"<<endl;
	k<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
	for(int j=0;j<n;j++)
		k<<a[j].maNv<<"\t"<<" "<<a[j].hoTen<<"\t\t    "<<a[j].tuoi<<"\t"<<a[j].luongCb<<endl;
	inDanhSachNv(a,n);
}
void capNhatNv(nhanVien a[],int n)
{
	int x,index;
	cout<<"Ma nhan vien can sua : ";
	cin>>x;
	for(int i=0;i<n;i++)
	{
		if(a[i].maNv==x)
		{
			index=i;
			fflush(stdin);
			cout<<"Ho ten nhan vien : ";	cin.getline(a[index].hoTen,30);
			cout<<"Tuoi : ";	cin>>a[index].tuoi;
			cout<<"Luong : ";	cin>>a[i].luongCb;
		}
	}
	cout<<"Danh sach nhan vien sau khi cat nhap"<<endl;
	k<<"---------------------------------------------"<<endl;
	k<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
	k<<"Danh sach sau khi cap nhat : "<<endl;
	for(int j=0;j<n;j++)
		k<<a[j].maNv<<"\t"<<" "<<a[j].hoTen<<"\t\t    "<<a[j].tuoi<<"\t"<<a[j].luongCb<<endl;
	inDanhSachNv(a,n);
}
void timKiemNv(nhanVien a[],int n)
{
	int x,index;
	cout<<"Ma nhan vien can tim : ";
	cin>>x;
	for(int i=0;i<n;i++)
	{
		if(a[i].maNv==x)
		{
			index=i;
			cout<<a[i].maNv<<"\t"<<a[i].hoTen<<"\t"<<a[i].tuoi<<"\t"<<a[i].luongCb<<endl;
			k<<"---------------------------------------------"<<endl;
			k<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
			k<<"Ket qua sau khi tim kiem : "<<endl;
			k<<a[i].maNv<<"\t"<<a[i].hoTen<<"\t"<<a[i].tuoi<<"\t"<<a[i].luongCb<<endl;
		}
	}
}
void ghifile(char *file,nhanVien a[],int n)
{
	ofstream f;
	f.open(file);
	f<<n<<endl;
	for(int i=0;i<n;i++)
		f<<a[i].maNv<<" "<<a[i].hoTen<<" "<<a[i].tuoi<<" "<<a[i].luongCb<<endl;
	f.close();
}
/*void filenhiphan(char *file,nhanVien a[])
{
	ofstream f;
	f.open(file,ios::binary);
	f.write((char *)a,sizeof(a));
	f.close();
}*/
int main()
{
	nhanVien a[50];
	int n,chon;
	ifstream g;
	g.open("input2.txt");
	if(g!=NULL)
	{
		g>>n;
		cout<<"Du lieu trong file : "<<endl;
		cout<<"So luong nhan vien : "<<n<<endl;
		cout<<"---------------------------------------------"<<endl;
		cout<<"STT"<<"|"<<"Ma nhan vien"<<"|"<<"Ho ten nhan vien"<<"|"<<"Tuoi"<<"|"<<"Luong"<<endl;
		for(int i=0;i<n;i++)
		{
			g>>a[i].maNv;
			g>>a[i].hoTen;
			g>>a[i].tuoi;
			g>>a[i].luongCb;
			cout<<i+1<<"\t"<<a[i].maNv<<"\t"<<" "<<a[i].hoTen<<"\t\t    "<<a[i].tuoi<<"\t"<<a[i].luongCb<<endl;
		}
		system("pause");
		do
		{
			system("cls");
			cout<<"1.Tao lai danh sach nhan vien"<<endl;
			cout<<"2.Them mot nhan vien"<<endl;
			cout<<"3.Sua doi thong tin nhan vien"<<endl;
			cout<<"4.Xoa mot nhan vien"<<endl;
			cout<<"5.Tim kiem nhan vien"<<endl;
			cout<<"6.In danh sach nhan vien"<<endl;
			cout<<"7.Thoat"<<endl;
			cout<<"------------------------------"<<endl;
			cout<<"Chon menu (1->5)"<<endl;
			cin>>chon;
			switch(chon)
			{
				case 1:
					cout<<"So luong nhan vien : ";
					cin>>n;
					nhap(a,n);
					ghifile("input2.txt",a,n);
					//filenhiphan("input2.dat",a);
					system("pause");
					break;
				case 2:
					themNv(a,n);
					system("pause");
					break;
				case 3:
					capNhatNv(a,n);
					system("pause");
					break;
				case 4:
					xoaNv(a,n);
					system("pause");
					break;
				case 5:
					timKiemNv(a,n);
					system("pause");
					break;
				case 6:
					inDanhSachNv(a,n);
					system("pause");
					break;
				case 7:
					break;
				default:
					cout<<"Muc lua chon khong ton tai!"<<endl;
			}
		}while(chon!=7);
	}
	else
	{
		do
		{
			system("cls");
			cout<<"1.Nhap danh sach nhan vien"<<endl;
			cout<<"2.Them mot nhan vien"<<endl;
			cout<<"3.Sua doi thong tin nhan vien"<<endl;
			cout<<"4.Xoa mot nhan vien"<<endl;
			cout<<"5.Tim kiem nhan vien"<<endl;
			cout<<"6.In danh sach nhan vien"<<endl;
			cout<<"7.Thoat"<<endl;
			cout<<"------------------------------"<<endl;
			cout<<"Chon menu (1->5)"<<endl;
			cin>>chon;
			switch(chon)
			{
				case 1:
					cout<<"So luong nhan vien : ";
					cin>>n;
					nhap(a,n);
					ghifile("input2.txt",a,n);
					system("pause");
					do
					{
						system("cls");
						cout<<"1.Tao lai danh sach nhan vien"<<endl;
						cout<<"2.Them mot nhan vien"<<endl;
						cout<<"3.Sua doi thong tin nhan vien"<<endl;
						cout<<"4.Xoa mot nhan vien"<<endl;
						cout<<"5.Tim kiem nhan vien"<<endl;
						cout<<"6.In danh sach nhan vien"<<endl;
						cout<<"7.Thoat"<<endl;
						cout<<"------------------------------"<<endl;
						cout<<"Chon menu (1->5)"<<endl;
						cin>>chon;
						switch(chon)
						{
							case 1:
								cout<<"So luong nhan vien : ";
								cin>>n;
								nhap(a,n);
								ghifile("input2.txt",a,n);
								system("pause");
								break;
							case 2:
								themNv(a,n);
								system("pause");
								break;
							case 3:
								capNhatNv(a,n);
								system("pause");
								break;
							case 4:
								xoaNv(a,n);
								system("pause");
								break;
							case 5:
								timKiemNv(a,n);
								system("pause");
								break;
							case 6:
								inDanhSachNv(a,n);
								system("pause");
								break;
							case 7:
								break;
							default:
								cout<<"Muc lua chon khong ton tai!"<<endl;
						}
					}while(chon!=7);
					break;
				case 7:
					break;
				default:
					cout<<"Du lieu trong file khong ton tai!"<<endl;
					system("pause");
			}
		}while(chon!=7);
	}
	g.close();
	return 0;
}
