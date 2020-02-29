#include<iostream>
using namespace std;
class Distance{
	private: 
		int metre;
	public:
		Distance(){
			metre = 0;
		}
		void displayData(){
			cout<<"Metre value is :"<< metre<<endl;
		}
		//prototype / Signature
		friend void addValue(Distance &d);
};

void addValue(Distance &d){
	d.metre = d.metre + 5 ; 
}
int main(){
	Distance d1;
	d1.displayData();
	
	addValue(d1);
	d1.displayData();
	return 0;
} 
