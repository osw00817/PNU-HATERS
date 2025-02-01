#include <iostream>
#include <string>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++){
        int p;
        cin >> p;
        
        int maxPrice = 0;
        string maxName;
        
        for(int j = 0; j < p; j++){
            int price;
            string name;
            cin >> price >> name;
            
            
            if(price > maxPrice) {
                maxPrice = price;
                maxName = name;
            }
        }
        
        
        cout << maxName << endl;
    }

    return 0;
}
