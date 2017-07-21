#include "unity.h"
#include "json_c.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_json_c_objConvToString(void)
{
    json_c_createObj_convToString();
    //TEST_ASSERT_EQUAL("{ "title": "testies", "body": "testies ... testies ... 1,2,3", "userId": 133 }", json_c_test());
    //TEST_IGNORE_MESSAGE("Need to Implement json_c");
}
