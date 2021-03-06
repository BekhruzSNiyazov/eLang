#include "../src/helpers/re.h"
#include "Unity/src/unity.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void re_test(void)
{
	char *string1 = (char *) "hello";
	char *pattern1 = (char *) "[\\w]*";
	TEST_ASSERT(match(string1, pattern1) == true);
	char *string2 = (char *) "123hello456";
	char *pattern2 = (char *) "([A-Za-z]+)";
	char *result = (char *) "hello";
	TEST_ASSERT_EQUAL_STRING(result, get(string2, pattern2));
}

int main(void)
{
	printf("\n\n");
	UNITY_BEGIN();
	RUN_TEST(re_test);
	return UNITY_END();
}
