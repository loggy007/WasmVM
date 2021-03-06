#include <skypat/skypat.h>

#define _Bool bool
extern "C" {
#include <instance/ModuleInst.h>
#include <string.h>
}
#undef _Bool

SKYPAT_F(ModuleInst, create_delete)
{
    // Prepare
    char* name = (char*) malloc(sizeof(char) * 5);
    strcpy(name, "test");
    ModuleInst* moduleInst = new_ModuleInst(name);

    // Check
    EXPECT_EQ(strcmp(moduleInst->name, "test"), 0);
    EXPECT_EQ(moduleInst->types->length, 0);
    EXPECT_EQ(moduleInst->types->data, NULL);
    EXPECT_EQ(moduleInst->funcaddrs->length, 0);
    EXPECT_EQ(moduleInst->funcaddrs->data, NULL);
    EXPECT_EQ(moduleInst->memaddrs->length, 0);
    EXPECT_EQ(moduleInst->memaddrs->data, NULL);
    EXPECT_EQ(moduleInst->tableaddrs->length, 0);
    EXPECT_EQ(moduleInst->tableaddrs->data, NULL);
    EXPECT_EQ(moduleInst->globaladdrs->length, 0);
    EXPECT_EQ(moduleInst->globaladdrs->data, NULL);
    EXPECT_EQ(moduleInst->exports->length, 0);
    EXPECT_EQ(moduleInst->exports->data, NULL);

    free_ModuleInst(moduleInst);
}
