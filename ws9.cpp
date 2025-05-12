#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class RecordsManager {
private:
    vector<int> records;
    string filename;  // Store the filename as a class member

public:
    // Constructor now takes the filename
    RecordsManager(const string& file) : filename(file) {}
    
    // read() function with no parameters
    void read() {
        ifstream file(filename);  // Open the file using the stored filename
        
        try {
            if (!file.is_open()) {
                throw ios_base::failure("Failed to open file");
            }
            
            string line;
            while (getline(file, line)) {
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
        return records;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    
    // Create RecordsManager with the filename from command line
    RecordsManager records(argv[1]);
    
    try {
        records.read();  // Call read() with no parameters
        
        // Calculate the sum
        int sum = 0;
        for (int value : records.getRecords()) {
            sum += value;
        }
        cout << sum << endl;
    } 
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;  // Return error code
    }
    
    return 0;
}