#include<iostream>
#include<queue>

using namespace std;

struct Animal{
	int order;
	int index;
};

int main(){
	int n;
	while(cin>>n){
		queue<Animal> cat;
		queue<Animal> dog;
		for(int i=0;i<n;i++){
			int oper;
			cin>>oper;
			if(oper == 1){
				Animal animal;
				cin>>animal.index;
				animal.order = i;
				if(animal.index > 0 ){
					dog.push(animal);
				}else{
					cat.push(animal);
				}
			}else if(oper == 2){
				int method;
				cin>>method;
				if(method == 0){
					Animal tmp1 = cat.front();
					Animal tmp2 = dog.front();
					if(tmp1.order < tmp2.order){
						cout<<tmp1.index<<" ";
						cat.pop();
					}else{
						cout<<tmp2.index<<" ";
						dog.pop();
					}
				}else if(method == 1){
					cout<<dog.front().index<<" ";
					dog.pop();
				}else{
					cout<<cat.front().index<<" ";
					cat.pop();
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
