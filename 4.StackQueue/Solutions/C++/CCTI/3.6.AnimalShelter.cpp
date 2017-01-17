#include "../Debug.h"
using namespace std;
    
#define CAT 0
#define DOG 1

struct Animal {
    int type;
};

class AnimalShelter {
public:
    void Enque(Animal animal) {
        if (animal.type == CAT) {
            cat_list.push_back({animal, order_++});
        } else if (animal.type == DOG) {
            dog_list.push_back({animal, order_++});
        }
    }

    Animal DequeAny() {
        AnimalNode popped;
        if (cat_list.front().order < dog_list.front().order) {
            popped = cat_list.front();
            cat_list.pop_front();
        } else {
            popped = dog_list.front();
            dog_list.pop_front();
        } 

        return popped.animal;
    }

    Animal DequeueCat() {
        AnimalNode popped = cat_list.front();
        cat_list.pop_front();
        return popped.animal;
    }

    Animal DequeueDog() {
        AnimalNode popped = dog_list.front();
        dog_list.pop_front();
        return popped.animal;
    }

private:
    struct AnimalNode {
        Animal animal;
        int order;
    };

    list<AnimalNode> cat_list,
                     dog_list;

    int order_ = INT_MIN;
};
