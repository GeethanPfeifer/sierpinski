#include <bits/stdc++.h>
using namespace std;

enum CELL {
	FREE,
	CENTER,
	PARENT,
	EMPTY,
	N1,
	N2
};

//c,n,ne,e,se,s,sw,w,nw : c'
const CELL rts[6][9] =
	{
		{CENTER, PARENT, FREE, FREE, N1, N2, FREE, FREE, EMPTY},
		{CENTER, EMPTY, FREE, FREE, N1, N2, FREE, FREE, PARENT},
		{CENTER, N1, FREE, N2, FREE, PARENT, FREE, EMPTY, FREE},
		{CENTER, N1, FREE, N2, FREE, EMPTY, FREE, PARENT, FREE},
		{CENTER, FREE, FREE, PARENT, EMPTY, FREE, FREE, N1, N2},
		{CENTER, FREE, FREE, EMPTY, PARENT, FREE, FREE, N1, N2}
	};
	
string cellRule(const CELL (&rt)[9], int center, int parent, int n1, int n2, int r){
	string ret;
	int i, f(0);
	for(i=0; i<9; i++){
		switch(rt[i]){
			case FREE:
				f++;
				ret += "f";
				ret += to_string(f);
				ret += ",";
				break;
			case CENTER:
				ret += to_string(center + 1);
				ret += ",";
				break;
			case PARENT:
				ret += to_string(parent + 1);
				ret += ",";
				break;
			case EMPTY:
				ret += "0,";
				break;
			case N1:
				ret += to_string(n1 + 1);
				ret += ",";
				break;
			case N2:
				ret += to_string(n2 + 1);
				ret += ",";
				break;
			default:
				assert(false);
		}
	}
	ret += to_string(r+1);
	ret += '\n';
	return ret;
}

int main(int argc, char** argv){
	int r;
	//cin >> r;
	if(argc != 2){
		cout << "Usage: [PROGRAM] INT";
		return -1;
	}
	r = atoi(argv[1]);
	if(r<0 || r>65535){
		cerr << "Error: rule must be 16-bit integer.";
		return -1;
	}
	string rs = to_string(r);
	
	
	ofstream of;
	of.open("Sierpinski" + rs+".rule");
	
	

	of << "@RULE " << "Sierpinski" + rs << "\n\n";
	of << "This file was generated automatically by sierpinskirulegen\n\n";
	of << "@TABLE\nn_states:3\nneighborhood:Moore\nsymmetries:none\n";
	
	of << "var f1 = {0,1,2}\n";
	of << "var f2 = {0,1,2}\n";
	of << "var f3 = {0,1,2}\n";
	of << "var f4 = {0,1,2}\n";
	
	int i, j;
	for(i=0; i<6; i++){
		for(j=0; j<16; j++){
			of << cellRule(rts[i], j&1, (j>>1)&1, (j>>2)&1, (j>>3)&1, (r>>j)&1);
		}
	}
	return 0;
}




















