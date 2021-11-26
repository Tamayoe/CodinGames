#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int main()
{
    const int MAX_DIST = 499;

    std::vector< vector< int > > neighbors;
    std::vector< bool > gateways;
    std::vector< int > dist; // Distance vector to find the shortest path from bobnet to the closest gateway
    std::queue< int > q; // Queue for the BFS
    std::vector< bool > visited; // Visited nodes list for the BFS

    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();

    neighbors.resize(n);
    for(vector< int > c : neighbors) c.reserve(16);
    gateways.resize(n, false);
    dist.resize(n, MAX_DIST + 1);
    visited.resize(n, false);

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();

        cerr << neighbors.size() << endl;

        neighbors[n1].push_back(n2);
        neighbors[n2].push_back(n1);

        cerr << "Link between node " << n1 << " and node " << n2 << endl;
    }
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();

        gateways[ei] = true;
    }

    // game loop
    while (1) {

        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        bool noGatewayHasBeenFound = true;
        int closestGateway = MAX_DIST + 1;

        //Starting node is Bobnet Agent
        q.push(si);
        visited[si] = true;
        dist[si] = 0;

        // Search algorithm is gonna calculate the distance of every nodes starting from bobnet 
        // until it find the closest gateway and then terminate
        while(noGatewayHasBeenFound) {
            int node = q.front();
            q.pop();

            for(int neighbor : neighbors[node]) {
                if( !visited[neighbor] ) {
                    q.push(neighbor);
                    visited[neighbor] = true;

                    dist[neighbor] = dist[node] + 1;

                    if( gateways[neighbor] == true ) {
                        noGatewayHasBeenFound = false;
                        closestGateway = neighbor;

                        //BFS is gonna stop, clearing the queue and the visited node list...
                        std::queue<int> empty;
                        std::swap( q, empty );
                        std::fill(visited.begin(), visited.end(), false);

                        break;
                    }
                }
            }
        }

        //Closest gateway has been found -> looking for the shortest path using the dist array
        cerr << "Closest gateway is node " << closestGateway << " at distance " << dist[closestGateway] << endl;

        std::vector< int > shortestPath;
        shortestPath.push_back(closestGateway);

        int next_node = closestGateway;
        int shortestDistance = 999;

        while(next_node != si) {

            for(int neighbor : neighbors[next_node]) {
                if(dist[neighbor] < shortestDistance) {
                    next_node = neighbor;
                    shortestDistance = dist[neighbor];
                }
            }

            shortestPath.push_back(next_node);
        }

        cerr << "Shortest path from Bobnet to a gateway is the following :\n(Gateway) ";
        for(int node : shortestPath) cerr << node << " ";
        cerr << "(Bobnet)" << endl;

        int first_node_cut = shortestPath[shortestPath.size() - 1];
        int second_node_cut = shortestPath[shortestPath.size() - 2];


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << first_node_cut << " " << second_node_cut << endl;

        //Update the data in the neighbors vector after severing the link between the 2 nodes
        l = l-1;
        neighbors[first_node_cut].erase(std::remove(neighbors[first_node_cut].begin(), neighbors[first_node_cut].end(), second_node_cut), neighbors[first_node_cut].end());
        neighbors[second_node_cut].erase(std::remove(neighbors[second_node_cut].begin(), neighbors[second_node_cut].end(), first_node_cut), neighbors[second_node_cut].end());



        //Reset the parameters for the algorithm
        shortestPath.clear();
        std::fill(dist.begin(), dist.end(), MAX_DIST + 1);
        std::fill(visited.begin(), visited.end(), false);

    }
}