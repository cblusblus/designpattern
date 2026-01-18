#include "lazy_singleton.hpp"

class MyConfig  : public LazySingletonOnce<MyConfig> {
    friend class LazySingletonOnce<MyConfig>;
private:
    MyConfig() = default;

public:
    int value{};

    int getValue() const {return value;}
    void setValue(int v) {value = v;}
};

int main() {
    MyConfig::instance().setValue(42);  
    const auto value = MyConfig::instance().getValue();
        //expected value = 42

    return 0;
}