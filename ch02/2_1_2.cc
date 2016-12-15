#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void rInsertionSort(vector<T> & ivec){
	for(int i=1;i!=ivec.size();++i){
		T key=ivec[i];		
		int j=i-1;
		while(j>-1&&ivec[j]<key){
			ivec[j+1]=ivec[j];
			--j;
		}
		ivec[j+1]=key;
	}
}
int main(){
	vector<int> ivec={5,3,6,7,3,2,5,8,3,2};
	rInsertionSort(ivec);
	for(auto i:ivec)
		cout<<i<<' ';
	cout<<endl;
	return 0;
}
