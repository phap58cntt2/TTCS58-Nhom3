#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
struct BoDe{
	string cauhoi;
	string A, B, C;
	string DA;
};
struct Nguoichoi{
	string ten;
	int diem;
};
vector <BoDe> bd;
vector <Nguoichoi> NC;
int Xuat(BoDe bd){	
	int diem=0;
	string DapAn;
	cout<<bd.cauhoi<<endl;
	cout<<bd.A<<endl;
	cout<<bd.B<<endl;
	cout<<bd.C<<endl;
	cout<<"Nhap dap an tra loi: "; cin>>DapAn;
	if(DapAn==bd.DA){
		cout<<"Tra loi dung"<<endl;
		diem=1;
	}
	else{
		cout<<"Tra loi sai"<<endl;
		diem=0;
	}
	return diem;	
}
void Nhaptennguoichoi(int d){
	Nguoichoi nc;
	cout<<"Nhap ten:";
	cin>>nc.ten;
	nc.diem=d;
	NC.push_back(nc);
}
void DocDe(){	
	int de;
	cout<<"Chon de ";
	cin>>de;
	switch (de){
		case 1:{
			ifstream f("de1.txt");//mo ra de doc
			string s;
			BoDe de1; 
			int SL;
			getline(f,s);
			SL=atoi(s.c_str());// doi tu kieu string sang kieu int
			for (int i=0;i<SL;i++){
				getline(f,s);  de1.cauhoi=s;
				getline(f,s);  de1.A=s;
				getline(f,s);  de1.B=s;
				getline(f,s);  de1.C=s;
				getline(f,s);	de1.DA =s;
				bd.push_back(de1);
			}
			break;
		}
		case 2:{
			ifstream f("de2.txt");//mo ra de doc
			string s; BoDe de2; 
			int SL;
			getline(f,s);
			SL=atoi(s.c_str());// doi tu kieu string sang kieu int
			for (int i=0;i<SL;i++)	{
				getline(f,s);
				de2.cauhoi =s;
				getline(f,s);
				de2.A=s;
				getline(f,s);
				de2.B=s;	
				getline(f,s);
				de2.C=s;
				getline(f,s);
				de2.DA =s;
				bd.push_back(de2);
			}
			break;	
		}
	}
}
void Xuatdiem(){
	for(int i=0;i<NC.size();i++){
		cout<<"Ten:";
		cout<<NC[i].ten<<endl;
		cout<<"Diem:";
		cout<<NC[i].diem<<endl;
	}
}
int main(){	
	int check;
	do{
		DocDe();
		int d=0;
		for(int i=0;i<bd.size();i++)
			d+=Xuat(bd[i]);
		cout<<"So diem dat duoc: "<<d<<endl;
		Nhaptennguoichoi(d);
		cout<<"Ban co muon choi tiep khong?"<<endl;
		cout<<"0: Ngung choi"<<endl;
		cin>>check;
		bd.clear();
	} while (check!=0);
	Xuatdiem();	
}
