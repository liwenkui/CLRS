//CLRS QuickSort p.95(C),p.170(E)
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
template<typename T>
T Partition(T begin,T end){
	auto pivot=*begin;
	auto i=end;
	for(auto j=end-1;j!=begin;--j){
		if(*j>pivot){
			--i;
			std::swap(*j,*i);
		}
	}
	std::swap(*begin,*(--i));
	return i;
}

template<typename T>
void QuickSort(T begin,T end){
	if(end-begin<2) return;
	auto q=Partition(begin,end);
	QuickSort(begin,q);
	QuickSort(++q,end);
}
int main(){
	std::vector<int> ivec{2,8,7,1,3,5,6,4};
	int arry[]={2,8,7,1,3,5,6,4};
	QuickSort(ivec.begin(),ivec.end());
	QuickSort(std::begin(arry),std::end(arry));
	for(auto c:ivec)
		std::cout<<c<<' ';
	std::cout<<std::endl;
	for(auto c:arry)
		std::cout<<c<<' ';
	std::cout<<std::endl;
}

