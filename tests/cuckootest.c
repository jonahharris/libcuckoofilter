#include "cuckoo_filter.h"

int
main (int argc, char ** argv) {
  cuckoo_filter_t  *filter;
  bool              rc;

  rc = cuckoo_filter_new(&filter, 500000, 100,
    (uint32_t) (time(NULL) & 0xffffffff));
  if (CUCKOO_FILTER_OK != rc) {
    printf("%s/%d: %d\n", __func__, __LINE__, rc);
  }
  rc = cuckoo_filter_contains(filter, "test", 4);
  if (CUCKOO_FILTER_OK == rc) {
    printf("%s/%d: %d\n", __func__, __LINE__, rc);
  }

  rc = cuckoo_filter_add(filter, "test", 4);
  if (CUCKOO_FILTER_OK != rc) {
    printf("%s/%d: %d\n", __func__, __LINE__, rc);
  }
  rc = cuckoo_filter_contains(filter, "test", 4);
  if (CUCKOO_FILTER_OK != rc) {
    printf("%s/%d: %d\n", __func__, __LINE__, rc);
  }

  rc = cuckoo_filter_remove(filter, "test", 4);
  if (CUCKOO_FILTER_OK != rc) {
    printf("%s/%d: %d\n", __func__, __LINE__, rc);
  }
  rc = cuckoo_filter_contains(filter, "test", 4);
  if (CUCKOO_FILTER_OK == rc) {
    printf("%s/%d: %d\n", __func__, __LINE__, rc);
  }

  int i;
  for (i = 0; i < 460000; i++) {
    rc = cuckoo_filter_add(filter, &i, sizeof(i));
    if (CUCKOO_FILTER_OK != rc) {
      printf("%s/%d: %d\n", __func__, __LINE__, rc);
    }
  }

  for (i = 0; i < 460000; i++) {
    rc = cuckoo_filter_contains(filter, &i, sizeof(i));
    if (CUCKOO_FILTER_OK != rc) {
      printf("%s/%d: %d %d\n", __func__, __LINE__, rc, i);
    }
  }
  
  rc = cuckoo_filter_free(&filter);
  if (CUCKOO_FILTER_OK != rc) {
    printf("%s/%d: %d\n", __func__, __LINE__, rc);
  }

  return 0;

} /* main() */

