#include "src/ecma402/calendar.h"
#include "src/ecma402/category.h"
#include "src/ecma402/collation.h"
#include "src/ecma402/currency.h"
#include "tests/criterion/test.h"

#define TEST_SUITE ecma402Category

#define CATEGORY_VALUES_TEST(name, category, capacity)                         \
  Test(TEST_SUITE, supportedValuesFor##name##Category) {                       \
    const char **values;                                                       \
    int count;                                                                 \
    values = (const char **)malloc(sizeof(const char *) * capacity);           \
    count = ecma402_supportedValuesForCategory(category, values);              \
    cr_expect(values != NULL);                                                 \
    cr_expect(gt(int, count, 0));                                              \
    free(values);                                                              \
  }

#define CATEGORY_CAPACITY_TEST(name, category, expectedCapacity)               \
  Test(TEST_SUITE, capacityFor##name##Category) {                              \
    int actualCapacity = ecma402_capacityForCategory(category);                \
    cr_assert(eq(int, actualCapacity, expectedCapacity));                      \
  }

CATEGORY_VALUES_TEST(Collation, ECMA402_CATEGORY_COLLATION,
                     ECMA402_COLLATION_CAPACITY)

CATEGORY_CAPACITY_TEST(Calendar, ECMA402_CATEGORY_CALENDAR,
                       ECMA402_CALENDAR_CAPACITY)
CATEGORY_CAPACITY_TEST(Collation, ECMA402_CATEGORY_COLLATION,
                       ECMA402_COLLATION_CAPACITY)
CATEGORY_CAPACITY_TEST(Currency, ECMA402_CATEGORY_CURRENCY,
                       ECMA402_CURRENCY_CAPACITY)
CATEGORY_CAPACITY_TEST(NumberingSystem, ECMA402_CATEGORY_NUMBERING_SYSTEM,
                       CATEGORY_NUMBERING_SYSTEM_CAPACITY)
CATEGORY_CAPACITY_TEST(TimeZone, ECMA402_CATEGORY_TIME_ZONE,
                       CATEGORY_TIME_ZONE_CAPACITY)
CATEGORY_CAPACITY_TEST(Unit, ECMA402_CATEGORY_UNIT, CATEGORY_UNIT_CAPACITY)

Test(TEST_SUITE, getsSupportedValuesForInvalidCategory) {
  const char **values;
  int count;

  values = (const char **)malloc(sizeof(const char *) * 1);
  count = ecma402_supportedValuesForCategory("foo", values);

  cr_expect(eq(int, count, 0));

  free(values);
}
