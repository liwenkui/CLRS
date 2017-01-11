#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
using namespace std;
int CUT_ROD(vector<int> p,int n){
	if(n==0)
		return 0;
	int q=INT_MIN;
	for(int i=1;i<=n;i++)
		q=max(q,p[i]+CUT_ROD(p,n-i));
	return q;
}
int MEMOIZED_CUT_ROD_AUX(const vector<int> &p,int n,vector<int> &r){
	int q;
	if(r[n]>0)
		return r[n];
	if(n==0)
		q=0;
	else{
		q=INT_MIN;
		for(int i=1;i<n+1;i++)
			q=max(q,p[i]+MEMOIZED_CUT_ROD_AUX(p,n-i,r));
	}
	r[n]=q;
	return q;
}
int MEMOIZED_CUT_ROD(const vector<int> &p,int n){
	vector<int> r(n+1);
	for(int i=0;i<n+1;i++)
		r[i]=INT_MIN;
	return MEMOIZED_CUT_ROD_AUX(p,n,r);
}
int BOTTOM_UP_CUT_ROD(const vector<int> &p,int n){
	vector<int> r(n+1);
	r[0]=0;
	for(int j=1;j<=n;j++){
		int q=INT_MIN;
		for(int i=1;i<=j;i++)
			q=max(q,p[i]+r[j-i]);
		r[j]=q;
	}
	return r[n];
}

pair<vector<int>,vector<int>> EXTENDED_BOTTOM_UP_CUT_ROD(const vector<int> &p,int n){
	pair<vector<int>,vector<int>> rs{vector<int>(n+1),vector<int>(n+1)};
	rs.first[0]=0;
	for(int j=1;j<=n;j++){
		int q=INT_MIN;
		for(int i=1;i<=j;i++){
			if(q<(p[i]+rs.first[j-i])){
				q=p[i]+rs.first[j-i];
				rs.second[j]=i;
			}
		}
		rs.first[j]=q;
	}
	return rs;
}

void PRINT_CUT_ROD_SOLUTION(const vector<int> &p,int n){
	auto rs=EXTENDED_BOTTOM_UP_CUT_ROD(p,n);
	while(n>0){
		cout<<rs.second[n]<<' ';
		n=n-rs.second[n];
	}
	cout<<endl;
}
int main(){
	vector<int> p={0,1,5,8,9,10,17,17,20,24,30};
	for(int i=0;i<p.size();i++)
		cout<<CUT_ROD(p,i)<<' ';
	cout<<endl;
	for(int i=0;i<p.size();i++)
		cout<<MEMOIZED_CUT_ROD(p,i)<<' ';
	cout<<endl;
	for(int i=0;i<p.size();i++)
		cout<<BOTTOM_UP_CUT_ROD(p,i)<<' ';
	cout<<endl;
	for(int i=0;i<p.size();i++)
		PRINT_CUT_ROD_SOLUTION(p,i);
	return 0;
}
