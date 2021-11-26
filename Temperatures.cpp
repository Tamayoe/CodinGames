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
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();

    int display_t = 5526, abs_display_t = 5526;

    if(n>0) {
        for (int i = 0; i < n; i++) {
            int t; // a temperature expressed as an integer ranging from -273 to 5526
            cin >> t; cin.ignore();

            //Calculating the absolute value of t
            int abs_t = abs(t);

            if(abs_t < abs_display_t) {
                display_t = t;
                abs_display_t = abs_t;
            } else if (abs_t == abs_display_t && t > 0) {
                display_t = t;
            }
        }
    } else {
    //If 0 temperatures are given
     display_t = 0;
    }
    

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << display_t << endl;
}