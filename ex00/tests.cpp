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