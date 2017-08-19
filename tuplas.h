#include <bits/stdc++.h>
using namespace std;
class in{
	int S;//state
	bool R;//read
public:
	in(int a=0, bool b=0){
		S=a;
		R=b;
	}
	int s(){return S;}
	bool r(){return R;}
	void value(int a,bool b){
		S=a;
		R=b;
	}
	bool operator <(const in i) const{
		if(S==i.S) return R && (R!=i.R);
		return S<i.S;
	}
	void print(){
		printf("state:%d\nread:%d\n",S,R);
	}
};

class out{
	bool W;//write
	char M;//move
	int NS;//new state
public:
	out(bool a=0,char b=0,int c=0){
		W=a;
		M=b;
		NS=c;
	}
	int ns(){return NS;}
	bool w(){return W;}
	char m(){return M;}
	void value(bool a,char b,int c){
		W=a;
		M=b;
		NS=c;
	}
	void print(){
		printf("write:%d\nmove:%c\nnew state:%d\n",W,M,NS);
	}
};

class tuples{
	map<in,out> t;
public:
	tuples(){}
	bool add(int a,bool b,bool c,char d,int e){
		in i(a,b);
			printf("%d\n",b);
		out o(c,d,e);
		if(t.count(i)) return false;//could not add tuple
		t[i]=o;
	}
	void add(in i,out o){
		if(t.count(i)) printf("tupla com essa leitura e estado ja existem\n");
		else t[i]=o;
	}
	out operator [](in i){
		return t[i];
	}
	out at(int a,bool b){
		in i(a,b);
		return t[i];
	}
	void read(){
		int i=0,a,b=-1;
		char c;
		in I;
		out O;
		while (1){
			if(i==0) printf("entre com estado, leitura, escrita, movimento e novo estado da tupla;\nPara o estado de parada diga que a leitura é 2\n");
			scanf(" %d %d",&a,&b);
			if(b==2) break;
			I.value(a,b==1);
			scanf(" %d %c %d",&b,&c,&a);
			O.value(b,c,a);
			this->add(I,O);
			i=(i+1)%10;
		}
		I.value(a,0);
		O.value(0,'s',a);
		this->add(I,O);
		I.value(a,1);
		this->add(I,O);
	}
	void print(){
		in I;
		out O;
		for(map<in,out>::iterator it=t.begin();it!=t.end();it++){
			I=it->first;
			O=it->second;
			I.print();
			O.print();
		}
	}
};
