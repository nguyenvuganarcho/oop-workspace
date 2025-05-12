#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class RecordsManager {
private:
    vector<int> records;
    string filename;

public:
    // Constructor
    RecordsManager(const string& file) : filename(file) {}
    
    void read() {
        ifstream file;  // Create file stream but don't open yet
        
        try {
            file.open(filename);  // Try to open the file
            
            if (!file.is_open()) {
                throw ios_base::failure("Failed to open file");
            }
            
            string line;
            while (getline(file, line)) {
                try {
                    records.push_back(stoi(line));
                }
                catch (const invalid_argument& e) {
                    cout << "invalid_argument error" << endl;
                    // Close file before re-throwing
                    file.close();
                    throw;  // Re-throw to main
                }
                catch (const out_of_range& e) {
                    cout << "out_of_range error" << endl;
                    // Close file before re-throwing
                    file.close();
                    throw;  // Re-throw to main
                }
            }
        }
        catch (const ios_base::failure& e) {
            cout << "ios_base::failure error" << endl;
            // Only try to close if it was successfully opened
            if (file.is_open()) {
                file.close();
            }
            throw;  // Re-throw to main
        }
        
        // Make sure to close the file if we get here
        if (file.is_open()) {
            file.close();
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
    
    try {
        // Create RecordsManager with filename from command line
        RecordsManager records(argv[1]);
        
        // Try to read the file
        records.read();
        
        // Calculate sum if read was successful
        int sum = 0;
        for (int value : records.getRecords()) {
            sum += value;
        }
        cout << sum << endl;
    }
    catch (const exception& e) {
        // Catch all standard exceptions
        cerr << "Error: " << e.what() << endl;
        return 1;  // Use a positive error code (1) instead of -1
    }
    catch (...) {
        // Catch any other unexpected exceptions
        cerr << "Unknown error occurred" << endl;
        return 2;  // Different error code for unknown exceptions
    }
    
    return 0;  // Successful execution
}