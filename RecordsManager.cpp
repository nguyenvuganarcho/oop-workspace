#include <iostream>  // For input/output operations
#include <fstream>   // For file operations
#include <vector>    // For storing records
#include <string>    // For string handling
#include <stdexcept> // For standard exceptions

using namespace std;  // This makes all std items available without the std:: prefix

class RecordsManager {
private:
    vector<int> records;  // Vector to store all the numbers

public:
    void read(const string& filename) {
        ifstream file(filename);  // Open the file
        
        try {
            if (!file.is_open()) {
                throw ios_base::failure("Failed to open file");
            }
            
            string line;
            while (getline(file, line)) {  // Read the file line by line
                records.push_back(stoi(line));  // Convert string to int and store
            }
        } 
        catch (const invalid_argument& e) {
            cout << "invalid_argument error" << endl;
            if (file.is_open()) {
                file.close();
            }
            throw;  // Pass the exception up to main()
        } 
        catch (const out_of_range& e) {
            cout << "out_of_range error" << endl;
            if (file.is_open()) {
                file.close();
            }
            throw;  // Pass the exception up to main()
        }
        catch (const ios_base::failure& e) {
            cout << "ios_base::failure error" << endl;
            if (file.is_open()) {
                file.close();
            }
            throw;  // Pass the exception up to main()
        }
        
        if (file.is_open()) {
            file.close();  // Close the file in the normal case too
        }
    }

    const vector<int>& getRecords() const {
        return records;  // Return the vector of records
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    
    RecordsManager records;
    try {
        records.read(argv[1]);  // Try to read the file
        
        // Calculate the sum of all numbers
        int sum = 0;
        for (int value : records.getRecords()) {
            sum += value;
        }
        cout << "Sum: " << sum << endl;
    } 
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;  // Return error code
    }
    
    return 0;  // Return success code
}