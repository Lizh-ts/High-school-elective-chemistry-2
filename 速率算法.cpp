#include<iostream>
#include<cmath>
using namespace std;
int x,y;
int whbrk=0;
float a[10][10];
int chk(int r){
	int zero=0;
		for(int k=0;k<x;k++){
			if(a[r][k]==0){
				zero+=1;
			}
		}
		if(zero==x+1){
			r-=1;
			whbrk=0;
		}else{
			whbrk=1;
		}
		return r;
	}
void Ans(){
	float b[x];
	int h=x-1,err=0;;
	for(int i=y-1;i>=0;i--){
		while(a[i][h]==0){
			i=chk(i);
			if(a[i][x]!=0 or whbrk==1){
				break;
			}
		}
		if(a[i][h]==0 and a[i][x]!=0){
			cout<<x-i+1<<"無解"<<endl;
			err=1;
		}else if(a[i][x]==0 and a[i][h]==0){
			cout<<x-i+1<<"有無限解"<<endl;
			err=1;
		}else if(a[i][h-1]!=0 and a[i][h]!=0){
			cout<<x-i+1<<"有無限解"<<endl;
			err=1;;
		}else{
			err=0;
		}
		if(a[i][h]!=0 and err==0){
			b[h]=a[i][x]/a[i][h];
			for(int j=i;j>0;j--){
				a[j-1][h]*=b[h];
				a[j-1][x]-=a[j-1][h];
				a[j-1][h]=0;
			}
			h--;
		}
	}
	cout<<"ANS=";
	cout<<pow(10,b[0])<<" ";
	for(int i=1;i<x;i++){
		cout<<b[i]<<" ";
	}
}
int main(){
	cout<<"使用方式"<<endl;
	cout<<"先輸入\"項數\"和\"變數個數\""<<endl;
	cout<<"常數k值帶10放進首位"<<endl;
	cout<<"剩下以\"元素1 元素2 元素3... 速率\"按行輸入"<<endl;
	cin>>x>>y;
	for(int i=0;i<y;i++){
		for (int j=0;j<x+1;j++){
			cin>>a[i][j];
			a[i][j]=log10(a[i][j])*-1;
		}
	}
	int d=0;
	for(int c=0;c<y;c++){
		for(int i=c+1;i<y;i++){
			if(d>=x){
				break;
			}
			if(a[c][d]==0){
				d++;
			}
			float k=a[i][d]/a[c][d];
			for(int j=0;j<x+2;j++){
				a[i][j]-=a[c][j]*k;
			}
		}
		d++;
	}
	Ans();
	
	return 0;
}
