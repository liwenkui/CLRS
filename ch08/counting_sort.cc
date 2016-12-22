#include <iostream>
#include <vector>
using namespace std;
void Counting_Sort(const vector<int>&a,vector<int>&b,int k){
	vector<int> c(k);
	for(auto i:a)
		c[i]=c[i]+1;
	for(auto i=c.begin()+1;i!=c.end();++i)
		*i=*i+*(i-1);
	for(auto i=a.rbegin();i!=a.rend();++i){
		b[c[*i]]=*i;
		c[*i]=c[*i]-1;
	}
}
int main(){
	vector<int> A={6,0,2,0,1,3,4,6,1,3,2},B(A.size());
	Counting_Sort(A,B,7);
	for(auto c:B)
		cout<<c<<' ';
	cout<<endl;
	return 0;
}
