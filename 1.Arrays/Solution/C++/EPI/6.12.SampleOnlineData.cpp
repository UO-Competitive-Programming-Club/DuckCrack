#include "../Debug.h"

using namespace std;

/* coppied solution from he book */
std::vector<int> OnlineRandomSample(std::istringstream * sin, int k) {
    int x;
    std::vector<int> running_sample;

    for (int i = 0; i < k && *sin >> x; i++) {
        running_sample.emplace_back(x);
    }     

    std::default_random_engine seed((std::random_device())());

    int num_seen_so_far = k;

    while (*sin >> x) {
        ++num_seen_so_far;
        int idx_to_replace = std::uniform_int_distribution<int>{0, num_seen_so_far - 1}(seed);
        if (idx_to_replace < k) {

            running_sample[idx_to_replace] = x;
        }
    }

    return running_sample;
}
