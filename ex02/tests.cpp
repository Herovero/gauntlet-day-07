#include "catch_amalgamated.hpp"
#include "Dice.hpp"
#include "RandomSource.hpp"

class FakeRandom : public RandomSource {
public:
    explicit FakeRandom(int fixedValue) : m_fixedValue(fixedValue) {}
    
    // Unnamed parameter ignores the max limit and avoids the compiler warning
    int next(int) override {
        return m_fixedValue;
    }
    
private:
    int m_fixedValue;
};

TEST_CASE("rng value 0 must give face 1") {
    FakeRandom fakeRng(0);
    Dice dice(fakeRng);
    
    CHECK(dice.roll() == 1);
}

TEST_CASE("rng value 5 must give face 6") {
    FakeRandom fakeRng(5);
    Dice dice(fakeRng);
    
    CHECK(dice.roll() == 6);
}