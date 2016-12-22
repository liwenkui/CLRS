#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void Force(vector<int> const& ivec,int &ii,int &jj,int&sum){
	sum=-1000000;
	int sum2;
	for(int i=0;i<ivec.size();i++){	
		sum2=ivec[i];
		if(sum2>sum){
			sum=sum2;
			ii=i;
			jj=0;
		}
		for(int j=i+1;j<ivec.size();j++){
			sum2+=ivec[j];
			if(sum2>sum){
				sum=sum2;
				ii=i;
				jj=j;
			}
		}
	}
}
struct res{
	res(int l,int h,int s):low(l),high(h),sum(s){}
	int low;
	int high;
	int sum;
};
res Cross(vector<int> const& ivec,int low,int mid,int high){
	int LS=-10000;		
	int MAX_L,MAX_R;
	int RS=-10000;
	int sum=0;
	for(int i=mid;i>=low;i--){
		sum+=ivec[i];	
		if(sum>LS){
			LS=sum;
			MAX_L=i;
		}
	}
	sum=0;
	for(int i=mid+1;i<high;i++){
		sum+=ivec[i];	
		if(sum>RS){
			RS=sum;
			MAX_R=i;
		}
	}
	return res(MAX_L,MAX_R,LS+RS);
}
res Devide(vector<int> const&ivec,int low,int high){
	if(high-low<2)
		return res(low,high,ivec[low]);
	int mid=(high+low)>>1;
	res left=Devide(ivec,low,mid+1);
	res right=Devide(ivec,mid+1,high);
	res cross=Cross(ivec,low,mid,high);
	if(left.sum>=right.sum&&left.sum>=cross.sum)
		return left;
	else if(right.sum>=left.sum&&right.sum>=cross.sum)
		return right;
	else return cross;
}
int main(){
	vector<int> ivec;
	ifstream in("input");	
	int input;
	while(in>>input){
		ivec.push_back(input);
	}
	int i=0,j=ivec.size(),sum;
	Force(ivec,i,j,sum);
	cout<<i<<' '<<j<<' '<<sum<<endl;
	res r=Devide(ivec,0,ivec.size());
	cout<<r.low<<' '<<r.high<<' '<<r.sum<<endl;
	return 0;
}
