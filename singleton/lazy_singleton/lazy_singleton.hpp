#include <mutex>
#include <memory>

template <typename T>
class lazy_singleton {
public:
    static T& instance() {
        std::lock_guard<std::mutex> lock(_mtx);
        if (!ptr) {
            ptr.reset(new T());
        }
        return *ptr;
    }

    static void destroy() {
        std::lock_guard<std::mutex> lock(_mtx);
        ptr.reset();
    }

    lazy_singleton(const lazy_singleton&) = delete;
    lazy_singleton& operator=(const lazy_singleton&) = delete;
    lazy_singleton(lazy_singleton&&) = delete;
    lazy_singleton& operator=(lazy_singleton&&) = delete;

protected:
    lazy_singleton() = default;
    ~lazy_singleton() = default;

private:
    inline static std::unique_ptr<T> ptr{};
    inline static std::mutex _mtx{};
};