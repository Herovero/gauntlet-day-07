#include "catch_amalgamated.hpp"
#include "Inventory.hpp"

TEST_CASE("adding an item raises the count") {
    Inventory inv;
    inv.add("potion");
    CHECK(inv.count() == 1);
}

TEST_CASE("has() finds an added item and rejects a missing one") {
    Inventory inv;
    inv.add("potion");
    CHECK(inv.has("potion") == true);
    CHECK(inv.has("sword") == false);
}

TEST_CASE("removing an item drops the count and has() stops finding it") {
    Inventory inv;
    inv.add("potion");
    inv.remove("potion");
    CHECK(inv.count() == 0);
    CHECK(inv.has("potion") == false);
}

TEST_CASE("removing a missing item is a no-op") {
    Inventory inv;
    inv.add("potion");
    inv.remove("sword");
    CHECK(inv.count() == 1);
    CHECK(inv.has("potion") == true);
}