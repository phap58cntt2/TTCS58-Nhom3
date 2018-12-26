#include <iostream>
#include <fstream>
#include <vector>
#include <string.>
#include <stdlib.h>
using namespace std;
fstream fi("input.txt");
fstream fo("output.txt");
class DANHBA{
	private:
		string gt,sdt[5],email,diachi;
	public:
		string ten;
		xuat(){
			cout<<"Ten: "<<ten<<endl;
			cout<<"Gioi tinh: "<<gt<<endl;
			cout<<"SDT: "<<sdt<<endl;
			cout<<"Email: "<<email<<endl;
			cout<<"Dia chi: "<<diachi;
		}
		nhapF(){

			getline( fi, ten);
			getline( fi, gt);
			getline( fi, sdt);
			getline( fi, email);
			getline( fi, diachi);
		}
		nhap(){
			cout<<"Nhap ten: ";
			cin.sync();
			getline( cin, ten);
			cout<<"Nhap gioi tinh: ";
			cin.sync();
			getline( cin, gt);
			cout<<"Nhap sdt: ";
			cin.sync();
			getline( cin, sdt);
			cout<<"Nhap email: ";
			cin.sync();
			getline( cin, email);
			cout<<"Nhap dia chi: ";
			cin.sync();
			getline( cin, diachi);		
		}
		xuatF()
		{
			fo<<ten<<endl;
			fo<<gt<<endl;
			fo<<sdt<<endl;
			fo<<email<<endl;
			fo<<diachi<<endl;
		}
		xuatFC()
		{
			fi<<ten<<endl;
			fi<<gt<<endl;
			fi<<sdt<<endl;
			fi<<email<<endl;
			fi<<diachi<<endl;
		}
};
class DSDB{
	vector <DANHBA> S;
	vector <DANHBA> P;
	public:
		void nhaptufile(){
			int n;
			string h;	
			getline( fi, h);
			n=atoi(h.c_str());
			S.resize(n);
			for(int i=0;i<S.size();i++)
				S[i].nhapF();
		}
		void xuatmh(){
			for(int i=0;i<P.size();i++){
				P[i].xuat();
				cout<<endl;
				cout<<"------------------------------"<<endl;
			}
		}
		void xuatmhfile(){
			for(int i=0;i<S.size();i++){
				S[i].xuat();
				cout<<endl;
				cout<<"------------------------------"<<endl;
			}
		}
		void xuatfile(){
			for(int i=0;i<P.size();i++)
				P[i].xuatF();
		}
		void xuatfileC(){
			for(int i=0;i<S.size();i++)
				S[i].xuatF();
		}
		void them(){
			DANHBA moi;
			moi.nhap();
			P.insert(P.end(), 1, moi);
			S.insert(S.end(), 1, moi);
		}
		void xoa(){
			int vt;
			cout<<"Nhap vi tri xoa:";
			cin>>vt;	
			S.erase(S.begin()+vt);
		}
		void chinhsua(){
			int vt;
			DANHBA moi;
			cout<<"Nhap vi tri sua:";
			cin>>vt;
			cout<<"Nhap thong tin chinh sua:"<<endl;
			moi.nhap();
			S.erase(S.begin()+vt);
			S.insert(S.begin()+vt,moi);
		}
		void Timkiem(){
			string k;
			cout<<"Nhap ten: ";
			cin>>k;
			for(int i = 0; i < S.size(); i++)
			if(k.compare(S[i].ten)== 0){
				S[i].xuat();
				cout<<endl;
			}
				
		}
};
int main(){
	int x;
	DSDB A;
	A.nhaptufile();
	cout<<"Danh sanh danh ba: "<<endl;
	cout<<"------------------------------"<<endl;
	A.xuatmhfile();
	cout<<"------------------------------"<<endl;
	do {
		cout<<"Nhap yeu cau:"<<endl<<"1: Them"<<endl<<"2: Liet ke cac ban ghi them vao"<<endl<<"3: Chinh sua ban ghi"<<endl<<"4: Xoa ban ghi"<<endl<<"5: Tim kiem"<<endl<<"0: Ket thuc"<<endl;
		cin>>x;
		if(x==1)
			A.them();
		if(x==2)
			A.xuatmh();
		if(x==3)
			A.chinhsua();
		if(x==4)
			A.xoa();
		if(x==5)
			A.Timkiem();
		cout<<"------------------------------"<<endl;
	}
	while (x!=0);
	cout<<"Danh sanh danh ba: "<<endl;
	cout<<"------------------------------"<<endl;
	A.xuatmhfile();
	A.xuatfile();
	A.xuatfileC();
	fi.close();
	fo.close();	
	
}
