#include <vector>
#include <iostream>
using namespace std;
vector<int> bin_add(vector<int> lhs,vector<int>rhs){
	if(lhs.size()!=rhs.size()) return vector<int>();
	int size=lhs.size();
	int carry=0;	
	vector<int> res(size+1);
	for(int i=size-1;i>-1;--i){
		res[i+1]=(carry+rhs[i]+lhs[i])%2;	
		carry=(carry+rhs[i]+lhs[i])/2;
	}
	res[0]=carry;
	return res;
}
int main(){
	vector<int> A={1,0,1,0,0,1,0};
	vector<int> B={1,1,0,1,1,1,1};
	vector<int> C=bin_add(A,B);
	for(auto c:C)
		cout<<c<<' ';
	cout<<endl;
	return 0;
}
