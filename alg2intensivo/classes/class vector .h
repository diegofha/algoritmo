#include <iostream>
#include <iostream>
#include <conio.h>
#include <string>

typedef int tipovar;
const int MAX=50;
using namespace std;
class vector{
private:
	int v[MAX];
	int n;
public:
	vector(){
	v[0]=0;
	n=0;
	}
	void setdim(int d){
    n=d;
	}
	int getdim(){
	return n;
	}
	void setelem(int e,int pos){
	v[pos]=e;
	}
	int getelem(int i){
		return v[i];
	}
	void leer(){
	int x;
		for(int i=0;i<getdim();i++){
		cout<<"elemento:";
		cin>>x;
		setelem(x,i);
	  }
	}
	void mostrar(){
	int x;
	cout<<endl;
		for(int i=0;i<getdim();i++){
		cout<<getelem(i)<<" ";
	  }
	}
	bool lleno(){
	return n==MAX;
	}
	bool vacio(){
	return n==0;
	}
	void insertar(int x,int p);
	void insertarprimero(int x);
	void insertarult(int x);
	void eliminar(int p);
	void eliminarpri();
	void eliminarult();
	void eliminarduplicado();
	void eliminarnoduplicado();

};
void vector::insertar(int x,int p){
	if(p<0 || p>n){
		cout<<"posicion invalida!!";
		return;
	}
	if(lleno()){
		cout<<"vector lleno";
		return;
	}
	int k=n-1;
	while(k>=p){
		v[k+1]=v[k];
		k--;
	}
	v[p]=x;
	n=n+1;
}
void vector::insertarprimero(int x){
	insertar(x,0);
}
void vector::insertarult(int x){
	insertar(x,n);
}
void vector::eliminar(int p){
	int k=p;
	while(k<n){
		v[k]=v[k+1];
         k++;
    }n--;
}
void vector::eliminarpri(){
eliminar(0);
}
void vector::eliminarult(){
eliminar(n-1);
}
void vector::eliminarduplicado(){

	for(int i=0;i<getdim();i++){
		for(int j=i+1;j<getdim();j++){
			if(v[i]==v[j]){
				eliminar(i);
				eliminar(j-1);
				j=i+1;
			}
		}
	}
}
void vector::eliminarnoduplicado(){
	int band,j,i=0;
	while(i<n){
		band=0;
		j=0;
		while(j<n){
			if(j!=i && v[i]==v[j])
				band=1;
			j++;
		}
		if(band==0)
			eliminar(i);
		else
			i++;
	}
}
void main(){
vector v;
int n;
cout<<"ingrese dimension :";
cin>>n;
v.setdim(n);
v.leer();
v.mostrar();
v.eliminarnoduplicado();
v.mostrar();
getch();
}
