#include "../Debug.h"
using namespace std;

/* copied from the book */
void SampleOfflineData(vector<int>& data, int k) {
     default_random_engine seed((random_device())());
     for (int i = 0; i < k; i++) {
         int randindex = uniform_int_distribution<int>(i, static_cast<int>(data.size() - 1))(seed);
         swap(data[i], data[randindex]);
     }
}
