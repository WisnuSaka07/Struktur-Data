#include <iostream>
using namespace std;

class MHS {
    private:
    string MHSName;
    string MHSNRP;

    public:
    void printname()
    {
        cout << " MY name is " << MHSName <<" MY NRP "<< MHSNRP;
    }

    string getName()
    {
        return MHSName;
    }
    
    MHS(string Name, string NRP) 
    {
        MHSName = Name;
        MHSNRP = NRP;
    }

};

int main() {
   MHS mhs1("Wisnu", "051");
   mhs1.printname();
   //cout << mhs1.getName();
    
   return 0;
}