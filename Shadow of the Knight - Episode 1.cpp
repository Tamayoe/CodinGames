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


    int width; // width of the building.
    int height; // height of the building.
    cin >> width >> height; cin.ignore();

    int search_min_y = 0, search_max_y = height-1, search_min_x = 0, search_max_x = width-1;

    int remaining_turns; // maximum number of turns before game over.
    cin >> remaining_turns; cin.ignore();

    int x, y;
    cin >> x >> y; cin.ignore();

    int move_x = 0, move_y = 0;

    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // Reducing the search area according to the given bomb direction
        cerr << "direction = " << bomb_dir << endl;


        if(bomb_dir == "U") {
            search_max_y = y - 1; 
            search_min_x = x; 
            search_max_x = x;
        } else if(bomb_dir == "D") {
            search_min_y = y + 1; 
            search_min_x = x; 
            search_max_x = x;
        } else if(bomb_dir == "R") {
            search_min_x = x + 1; 
            search_min_y = y; 
            search_max_y = y;
        } else if(bomb_dir == "L") {
            search_max_x = x - 1; 
            search_min_y = y; 
            search_max_y = y;
        } else if(bomb_dir == "UR") { 
            search_max_y = y - 1; 
            search_min_x = x + 1;
        } else if(bomb_dir == "UL") { 
            search_max_y = y - 1; 
            search_max_x = x - 1;
        } else if(bomb_dir == "DR") {
            search_min_y = y + 1; 
            search_min_x = x + 1;
        } else if(bomb_dir == "DL") {
            search_min_y = y + 1; 
            search_max_x = x - 1;
        }

        //Calculating the search zone height and width
        int search_width = search_max_x - search_min_x + 1;
        int search_height = search_max_y - search_min_y + 1;

        //Going to the center of the search area
        move_x = search_min_x + search_width / 2;
        move_y = search_min_y + search_height / 2;

        // the location of the next window Batman should jump to.
        cout << move_x << " " << move_y << endl;

        //Updating Batman's location
        x = move_x; y = move_y;
    }
}