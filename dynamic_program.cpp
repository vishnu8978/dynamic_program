#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Here below is the function used to find the longest common substring
string findLongestSubstring(const string& textA, const string& textB) {
    int size1 = textA.length();  // Length of first string
    int size2 = textB.length();  // Length of second string
    
    // Step 1: Created a 2D vector for lookup table
    // The size of the table is (len1 + 1) x (len2 + 1) to accommodate empty string case
    vector<vector<int>> dpTable(size1 + 1, vector<int>(size2 + 1, 0));
    
    int bestLength = 0;   // Current length of the longest common substring so far
    int lastIndex = 0;    // This is the ending index of the longest common substring in str1
    
    // Step 2: Here table is filled using dynamic programming
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            // If characters match, extend the substring
            if (textA[i - 1] == textB[j - 1]) {
                dpTable[i][j] = dpTable[i - 1][j - 1] + 1;
                
                // If longest substring is found we need to update maxLength and endIndex
                if (dpTable[i][j] > bestLength) {
                    bestLength = dpTable[i][j];
                    lastIndex = i - 1;
                }
            }
            // If no characters match happened, lcsTable[i][j] remains 0
        }
    }
    
    // Step 3: need to print the table for visualization
    cout << "    ";
    for (char c : textB) cout << c << "   ";
    cout << "\n";
    
    for (int i = 0; i <= size1; i++) {
        if (i == 0) cout << "  ";
        else cout << textA[i - 1] << " ";
        for (int j = 0; j <= size2; j++) {
            cout << setw(3) << dpTable[i][j] << " ";
        }
        cout << "\n";
    }
    
    // Step 4: Here we need to extract and return the longest common substring
    return textA.substr(lastIndex - bestLength + 1, bestLength);
}

int main() {
    string textA, textB;
    
    // To get input from user
    cout << "Enter the first string: ";
    cin >> textA;
    cout << "Enter the second string: ";
    cin >> textB;
    
    // Comparing strings length to know whether they are same or not 
    if (textA.length() != textB.length()) {
        cout << "Error: The strings must have the same length." << endl;
        return 1;
    }
    
    // To find and print the longest common substring
    string result = findLongestSubstring(textA, textB);
    
    // Output results
    cout << "\nLongest Common Substring: " << result << endl;
    cout << "Length: " << result.length() << endl;
    
    return 0;
}
