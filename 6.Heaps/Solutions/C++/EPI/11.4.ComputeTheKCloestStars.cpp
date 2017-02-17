#include "../Debug.h"
using namespace std;
 
struct Star {
    bool operator<(const Star& that) const {
        return Distance() < that.Distance();
    }

    double Distance() const {
        double dist = 0;
        for (auto x : coordinate ) {
            dist += x*x;
        }

        return dist;
    }

    vector<double> coordinate;
}

vector<Star> FindClosestKStars(int k, istringstream* stars) {
    priority_queue<Star, vector<Star>> max_heap;



}
