#include<iostream>
using namespace std;
// Class that handles number system conversions
class Convert {
public:
    // Function to convert any base number to Decimal
    int toDecimal(string num, int base) {
        int value = 0;  // stores final decimal value
        // Loop through each digit of the input number
        for(int i = 0; i < num.length(); i++) {
            int digit;

            // If character is between 0–9
            if(num[i] >= '0' && num[i] <= '9')
                digit = num[i] - '0';   // convert char to integer
            else
                // For hexadecimal characters A–F
                digit = num[i] - 'A' + 10;

            // Decimal conversion formula
            value = value * base + digit;
        }

        return value; // return converted decimal number
    }

    // Function to convert Decimal number to another base
    void fromDecimal(int num, int base) {
        int arr[32], i = 0;  // array to store remainders

        // Special case when number is 0
        if(num == 0) {
            cout << 0;
            return;
        }

        // Divide number by base and store remainder
        while(num > 0) {
            arr[i++] = num % base;
            num /= base;
        }

        // Print digits in reverse order
        for(int j = i - 1; j >= 0; j--) {
            if(arr[j] >= 10)
                // Convert values 10–15 to A–F for Hexadecimal
                cout << char(arr[j] + 55);
            else
                cout << arr[j];
        }
    }

};

int main() {

    int fromType, toType, baseFrom, baseTo;
    string num;

    Convert obj; // object of Convert class

    // UI for the converter
    cout << "====================================\n";
    cout << "           NUMBER CONVERTER\n";
    cout << "====================================\n\n";

    // Menu of number systems
    cout << "1.Binary \n2.Decimal  \n3.Octal  \n4.Hex\n";

    // Take source type
    cout << "Enter source type: ";
    cin >> fromType;

    // Take target type
    cout << "Enter target type: ";
    cin >> toType;

    // Input number
    cout << "Enter number: ";
    cin >> num;

    // Base mapping array
    // Index: 1=Binary, 2=Decimal, 3=Octal, 4=Hex
    int base[5] = {0, 2, 10, 8, 16};

    baseFrom = base[fromType];
    baseTo   = base[toType];
    // Convert source number to decimal first
    int dec = obj.toDecimal(num, baseFrom);
    // If target base is decimal
    if(baseTo == 10) {
        cout << dec;
    }
    else {
        // Convert decimal to target base
        obj.fromDecimal(dec, baseTo);
    }

    return 0;
}