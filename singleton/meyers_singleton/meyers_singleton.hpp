#pragma once

class meyers_singleton{

private:
    meyers_singleton() = default;
    meyers_singleton(const meyers_singleton&) = delete;
    meyers_singleton& operator=(const meyers_singleton&) = delete;
    meyers_singleton(meyers_singleton&&) = delete;
    meyers_singleton& operator=(meyers_singleton&&) = delete;
    // ~meyers_singleton() = default;

    /* Singleton */
public:
    static meyers_singleton &getInstance(){
        static meyers_singleton inst;
        return inst;
    }


    /* Date Fields */
private:
    int i;
    double d;

public:
    int getI() const { return i; }
    void setI(int val) { i = val; }
    double getD() const { return d; }
    void setD(double val) { d = val; }
};