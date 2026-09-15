/*
 * Activity Selection Problem
 * ---------------------------
 * Given N activities, each with a start time and a finish time, select the
 * maximum number of activities that can be performed by a single person,
 * assuming a person can only work on one activity at a time.
 *
 * Greedy strategy: EARLIEST FINISH TIME FIRST
 *   1. Sort activities by finish time in increasing order.
 *   2. Always pick the next activity whose start time is >= the finish
 *      time of the last selected activity.
 *
 * YOUR TASK:
 *   Complete the TODO sections below. Do not change the function
 *   signatures or the overall structure of main().
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

// TODO 1:
// Write a comparator function (or lambda) that sorts activities by
// finish time in ascending order. This will be used with std::sort.
bool compareByFinishTime(const Activity &a, const Activity &b) {
    // TODO: return true if activity 'a' should come before activity 'b'
    return false; // placeholder — replace this
}

// TODO 2:
// Implement the greedy activity selection algorithm.
// Input: a vector of activities (NOT necessarily sorted).
// Output: a vector containing the selected (compatible) activities,
//         in the order they were chosen.
vector<Activity> selectActivities(vector<Activity> activities) {
    vector<Activity> selected;

    // Step A: Sort the activities by finish time.
    // TODO: call std::sort using compareByFinishTime

    // Step B: Greedily pick activities.
    // Hint: keep track of the finish time of the last selected activity.
    // TODO: implement the selection loop

    return selected;
}

void printActivities(const vector<Activity> &activities) {
    cout << "Activity\tStart\tFinish\n";
    for (const auto &act : activities) {
        cout << act.id << "\t\t" << act.start << "\t" << act.finish << "\n";
    }
}

int main() {
    // Sample input: (id, start, finish)
    vector<Activity> activities = {
        {1, 1, 4},
        {2, 3, 5},
        {3, 0, 6},
        {4, 5, 7},
        {5, 3, 9},
        {6, 5, 9},
        {7, 6, 10},
        {8, 8, 11},
        {9, 8, 12},
        {10, 2, 14},
        {11, 12, 16}
    };

    cout << "All activities:\n";
    printActivities(activities);

    vector<Activity> result = selectActivities(activities);

    cout << "\nSelected activities (maximum non-overlapping set):\n";
    printActivities(result);

    cout << "\nTotal activities selected: " << result.size() << endl;

    // Expected output for the sample input above:
    // Activities 1, 4, 8, 11 (in some equivalent optimal ordering)
    // Total = 4

    return 0;
}
