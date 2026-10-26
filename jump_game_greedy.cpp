#include <iostream>
#include <vector>
using namespace std;

int jumpGame (vector<int> &busStops) {
    
    if (busStops[0] == 0) {
        return -1;
    }
    
    int maxStop = 0;
    int curStop = 0;
    int trips = 0;

    for (int i = 0; i < busStops.size() - 1; i ++) {
        maxStop = max(maxStop, i + busStops[i]);
        
        if (i == curStop) {
            if(maxStop == curStop) {
                cout << "No Possible Route" << endl;
                return -1;
            }
            else {
                trips++;
                curStop = maxStop;
            }
        }
    }

    return trips;
}

int main() {
    vector<int> bus = {3,1,1,4,2};
    cout << "Total Trips needed: " << jumpGame(bus) << endl;
}