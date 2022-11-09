#include <iostream>
using namespace std;

class MHS {
	//Acces Specifier
	public:
	string MHSname; // data member
	
	//member function()
	void printname() {
		cout << "MHS name is : "<< MHSname; 
	}
};

int main() {\
	//declare an object of class geeks
	MHS mhs1;
	
	//accesing data member 
	mhs1.MHSname = "Arfan";
	
	//accesing member function
	mhs1.printname();
	
	return 0;
}