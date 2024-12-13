#include <iostream>
#include <memory>

class ShippingStrategy {
public:
    virtual ~ShippingStrategy() = default;
    virtual int calculate(int weight) const = 0;
};

class CourierStrategy : public ShippingStrategy {
public:
    int calculate(int weight) const override { return 10 + 5 * weight; }
};

class PostStrategy : public ShippingStrategy {
public:
    int calculate(int weight) const override { return 5 + 2 * weight; }
};

class DeliveryService {
private:
    std::unique_ptr<ShippingStrategy> strategy_;

public:
    DeliveryService(std::unique_ptr<ShippingStrategy>&& strategy)
        : strategy_(std::move(strategy)) {}

    void set_strategy(std::unique_ptr<ShippingStrategy>&& strategy) {
        strategy_ = std::move(strategy);
    }

    int calculate(int weight) { return strategy_->calculate(weight); }
};

int main() {
    int weight = 10;
    DeliveryService ds(std::make_unique<CourierStrategy>());
    std::cout << ds.calculate(weight);
    ds.set_strategy(std::make_unique<PostStrategy>());
    std::cout << ds.calculate(weight);
    return 0;
}