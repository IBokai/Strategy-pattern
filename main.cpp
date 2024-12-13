#include <iostream>
#include <string>
using std::string;

class DeliveryService {
private:
    int calculate_courier(int weight) { return 10 + 5 * weight; }

    int calculate_post(int weight) { return 5 + 2 * weight; }

    int calculate_express(int weight) { return 20 + 3 * weight; }

public:
    int calculate(int weight, string type) {
        // Может быть заменено на switch-case, но дело это не спасает
        if (type == "courier") {
            return calculate_courier(weight);
        } else if (type == "post") {
            return calculate_post(weight);
        } else if (type == "express") {
            return calculate_express(weight);
        }
        return -1;
    }
};

int main() {
    DeliveryService ds = DeliveryService();
    std::cout << ds.calculate(10, "courier") << '\n';
    std::cout << ds.calculate(10, "post") << '\n';
    return 0;
}