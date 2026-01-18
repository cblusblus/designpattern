#include <shared_mutex>

class ReadWriteLock {
public:
    int get() const {
        std::shared_lock lock(m);
        return value;
    }

    void set(int v) {
        std::unique_lock lock(m);
        value = v;
    }

private:
    mutable std::shared_mutex m;
    int value{};
};