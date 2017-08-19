#include <bits/stdc++.h>

using namespace std;

class nodo{
	nodo* prev,*next;
	bool v;
public:
	nodo(){}
	void value(nodo* p,nodo* n,bool r=0){
		prev=p;
		next=n;
		v=r;
	}
	bool read(){ return v;}
	void write(bool r){v=r;}
	void p(nodo* n){
		prev=n;
	}
	void n(nodo* n){
		next=n;
	}
	nodo* N(){
		return next;
	}
	void print(){
		printf("prev: %p\nvalor: %d\nnext: %p\n",prev,v,next);
	}
};

class strip{
	nodo* start,*finish;
	int number;
public:
	strip(){
		start=NULL;
		finish=NULL;
		number=0;
	}
	int size(){return number;}
	void add_begin(bool val){
		nodo* n;
		n=(nodo*)malloc(sizeof(nodo));
		n->value(NULL,start,val);
		if(start) {
			start->p(n);
		}
		start=n;
		if(finish==NULL) finish=n;
		number++;
	}
	void add_end(bool val){
		nodo* n;
		n=(nodo*) malloc(sizeof(nodo));
		n->value(finish,NULL,val);
		if(finish) finish->n(n);
		finish=n;
		if(start==NULL) start=n;
		number++;
	}
	void read(){
		char c;
		scanf("%c",&c);
		while(c!='\n'){
			if(c=='0') add_end(false);
			else if(c=='1') add_end(true);
			scanf("%c",&c);
		}
		print();
	}
	nodo* operator [](int p){
		int i=0;
		nodo* n=start;
		while(i<p){
			n=n->N();
			i++;
		}
		return n;
	}
	void print(){
		nodo* n=start;
		while(n->N()){
			printf("%d",n->read());
			n=n->N();
		}
		printf("%d\n",n->read());
	}
};
