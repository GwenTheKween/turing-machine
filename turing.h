#include "tuplas.h"
#include "strip.h"

void wait();

class turing{
	strip s;
	tuples t;
	int state,pos;
public:
	turing(){
		pos=0;
		state=0;
		s.read();
		t.read();
	}
	void print(){
		for (int i=0;i<pos;i++) printf(" ");
		printf("^\n");
		for (int i=0;i<pos;i++) printf(" ");
		printf("|\n");
		for(int i=0;i<pos;i++)
			if(state>10 && i==pos-1) break;
			else printf(" ");
		printf("%d\n",state);
	}
	void run(){
		out O;
		in I;
		I.value(state,s[0]->read());
		O=t[I];
		while(O.m()!='s'){
			system("clear");
			s.print();
			this->print();
			t[I].print();
			s[pos]->write(O.w());
			if(O.m()=='d'){
				pos++;
				if(pos==s.size())s.add_end(0);
			}else{
				pos--;
				if(pos<0){
					pos=0;
					s.add_begin(0);
				}
			}
			state=O.ns();
			I.value(state,s[pos]->read());
			O=t[I];
			wait();
		}
		system("clear");
		s.print();
		this->print();
	}
};

void wait(){
	long double now,fin;
	now=time(NULL);
	fin=now+1;
	while(now!=fin) now=time(NULL);
}
