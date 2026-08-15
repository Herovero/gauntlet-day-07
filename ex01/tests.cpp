#include "catch_amalgamated.hpp"
#include "Inventory.hpp"

struct InventoryFixture {
    Inventory inv;
    
    InventoryFixture() { 
        inv.add("potion"); 
        inv.add("sword"); 
    }
};

TEST_CASE_METHOD(InventoryFixture, "adding an item raises the count") {
    inv.add("shield");
    CHECK(inv.count() == 3);
}

TEST_CASE_METHOD(InventoryFixture, "has() finds an added item and rejects a missing one") {
    CHECK(inv.has("potion") == true);
    CHECK(inv.has("elixir") == false);
}

TEST_CASE_METHOD(InventoryFixture, "removing an item drops the count and has() stops finding it") {
    inv.remove("potion");
    CHECK(inv.count() == 1);
    CHECK(inv.has("potion") == false);
}

TEST_CASE_METHOD(InventoryFixture, "removing a missing item is a no-op") {
    inv.remove("elixir");
    // Item count remains 2, and the default items are unaffected
    CHECK(inv.count() == 2);
    CHECK(inv.has("potion") == true);
    CHECK(inv.has("sword") == true);
}