#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class Flip {
    int* arr;
    int size;

public:
    void inputArray() {
        cout << "Enter the size of the binary array: ";
        cin >> size;

        arr = new int[size];

        for (int i = 0; i < size; i++) {
            while (true) {
                cout << "Enter element " << i + 1 << " (must be 0 or 1): ";
                cin >> arr[i];

                if (arr[i] == 0 || arr[i] == 1) {
                    break;
                } else {
                    cout << RED << "Invalid input! " << RESET << endl;
                }
            }
        }
    }

    int Flips(int k) {
        int flips = 0;

        for (int i = 0; i <= size - k; i++) {
            if (arr[i] == 0) {
                
                for (int j = 0; j < k; j++) {
                    arr[i + j] = 1 - arr[i + j]; 
                }
                flips++;
            }
        }

        
        for (int i = 0; i < size; i++) {
            if (arr[i] == 0) {
                return -1; 
            }
        }

        return flips;
    }

    void run() {
        int k;
        inputArray();
        cout << "Enter the value of k : ";
        cin >> k;

        int result = Flips(k);
        if (result == -1) {
            cout << RED << "It is not possible to make all elements 1." << RESET << endl;
        } else {
            cout << GREEN << "Minimum number of flips required: " << result << RESET << endl;
        }
    }
    
};

int main() {
    Flip flips;
    flips.run();
    return 0;
}


       
        
        
        



    








