#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    int distance_x = 0, distance_y = 0;
    int thor_x = initial_tx, thor_y = initial_ty;
    string move_to = "";

    // game loop
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns; cin.ignore();

        move_to.clear();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        //Calculate Thor remaining distance from light :
        distance_x = light_x - thor_x;
        distance_y = light_y - thor_y;

        //Determine Thor next movement :
        if(distance_y < 0) {
            move_to = move_to + "N"; 
            thor_y--;
        }
        if(distance_y > 0) {
            move_to = move_to + "S";
            thor_y++;
        }

        if(distance_x < 0) {
            move_to = move_to + "W"; 
            thor_x--;
        }
        if(distance_x > 0) {
            move_to = move_to + "E";
            thor_x++;
        }

        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << move_to << endl;
    }
}