/* ensure that we generate a high byte character correctly escaped */

#include <yajl/yajl_gen.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

#define CHK(x) if (x != yajl_gen_status_ok) return 1;

int main(void) {
  yajl_gen yg;

  yg = yajl_gen_alloc(NULL);
  CHK(yajl_gen_map_open(yg));

  const unsigned char payload[] = "payload";
  const unsigned char hibyte[] = "\xc3";
  const char gold[] = "{\"payload\":\"\\u00C3\"}";

  CHK(yajl_gen_string(yg, payload, strlen((const char*)payload)));
  CHK(yajl_gen_string(yg, hibyte, strlen((const char*)hibyte)));
  CHK(yajl_gen_map_close(yg));

  const unsigned char *buf;
  size_t len;
  CHK(yajl_gen_get_buf(yg, &buf, &len));

  int ret;
  if ((ret = strcmp((const char*)buf, gold))) {
    printf("DIFF: %s\n%s\n", buf, gold);
  }

  return ret;
}
