#include "BMP.h"
#include "unity.h"

#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void test_parseHeaders_NULL() {
    char* data = NULL;
    FileHeader* fh = NULL;
    ImageHeader* ih = NULL;

    char* dataNull = NULL;
    FileHeader* fhNull = NULL;
    ImageHeader* ihNull = NULL;

    TEST_ASSERT_EQUAL(-1, parseHeaders(dataNull, 54, fh, ih));
    TEST_ASSERT_EQUAL(-1, parseHeaders(data, 54, fhNull, ih));
    TEST_ASSERT_EQUAL(-1, parseHeaders(data, 54, fh, ihNull));
}

void test_parseHeaders_NotEnoughData() {
    char data;
    FileHeader fh;
    ImageHeader ih;

    TEST_ASSERT_EQUAL(-1, parseHeaders(&data, 53, &fh, &ih));
}





int main () {
    UnityBegin("a");

    MY_RUN_TEST(test_parseHeaders_NULL);
    MY_RUN_TEST(test_parseHeaders_NotEnoughData);
	
    return UnityEnd();
}
