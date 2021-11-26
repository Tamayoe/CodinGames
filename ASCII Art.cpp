#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int letter_width;
    cin >> letter_width; cin.ignore();
    int letter_height;
    cin >> letter_height; cin.ignore();
    string text;
    getline(cin, text);
    int n = text.size();

    //Text to uppercase
    transform(text.begin(), text.end(), text.begin(), ::toupper);


    for(int i = 0; i < letter_height; i++) { 
        string row;
        getline(cin, row);   

        for (int j = 0; j < n; j++) {
            char c = text[j];
            int p = c - 65;

            if(p >= 0 && p < 26) {
                cout << row.substr(p*letter_width,letter_width);
            } else {
                cout << row.substr(26*letter_width,letter_width);
            }
            
        }

        cout << "\n";
    }

    cout << endl;
}