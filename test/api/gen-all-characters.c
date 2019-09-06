/* ensure that we generate all characters correctly escaped */

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
  const unsigned char allcharacters[] = "\x01 \x02 \x03 \x04 \x05 \x06 \x07 \x08 \x09 \x0A \x0B \x0C \x0D \x0E \x0F \x10 "
    "\x11 \x12 \x13 \x14 \x15 \x16 \x17 \x18 \x19 \x1A \x1B \x1C \x1D \x1E \x1F \x20 \x21 \x22 \x23 \x24 \x25 \x26 \x27 "
    "\x28 \x29 \x2A \x2B \x2C \x2D \x2E \x2F \x30 \x31 \x32 \x33 \x34 \x35 \x36 \x37 \x38 \x39 \x3A \x3B \x3C \x3D \x3E "
    "\x3F \x40 \x41 \x42 \x43 \x44 \x45 \x46 \x47 \x48 \x49 \x4A \x4B \x4C \x4D \x4E \x4F \x50 \x51 \x52 \x53 \x54 \x55 "
    "\x56 \x57 \x58 \x59 \x5A \x5B \x5C \x5D \x5E \x5F \x60 \x61 \x62 \x63 \x64 \x65 \x66 \x67 \x68 \x69 \x6A \x6B \x6C "
    "\x6D \x6E \x6F \x70 \x71 \x72 \x73 \x74 \x75 \x76 \x77 \x78 \x79 \x7A \x7B \x7C \x7D \x7E \x7F \x80 \x81 \x82 \x83 "
    "\x84 \x85 \x86 \x87 \x88 \x89 \x8A \x8B \x8C \x8D \x8E \x8F \x90 \x91 \x92 \x93 \x94 \x95 \x96 \x97 \x98 \x99 \x9A "
    "\x9B \x9C \x9D \x9E \x9F \xA0 \xA1 \xA2 \xA3 \xA4 \xA5 \xA6 \xA7 \xA8 \xA9 \xAA \xAB \xAC \xAD \xAE \xAF \xB0 \xB1 "
    "\xB2 \xB3 \xB4 \xB5 \xB6 \xB7 \xB8 \xB9 \xBA \xBB \xBC \xBD \xBE \xBF \xC0 \xC1 \xC2 \xC3 \xC4 \xC5 \xC6 \xC7 \xC8 "
    "\xC9 \xCA \xCB \xCC \xCD \xCE \xCF \xD0 \xD1 \xD2 \xD3 \xD4 \xD5 \xD6 \xD7 \xD8 \xD9 \xDA \xDB \xDC \xDD \xDE \xDF "
    "\xE0 \xE1 \xE2 \xE3 \xE4 \xE5 \xE6 \xE7 \xE8 \xE9 \xEA \xEB \xEC \xED \xEE \xEF \xF0 \xF1 \xF2 \xF3 \xF4 \xF5 \xF6 "
    "\xF7 \xF8 \xF9 \xFA \xFB \xFC \xFD \xFE \xFF";
  const char gold[] = "{\"payload\":\""
    "\\u0001 \\u0002 \\u0003 \\u0004 \\u0005 \\u0006 \\u0007 \\b \\t \\n \\u000B \\f \\r \\u000E \\u000F \\u0010 \\u0011 "
    "\\u0012 \\u0013 \\u0014 \\u0015 \\u0016 \\u0017 \\u0018 \\u0019 \\u001A \\u001B \\u001C \\u001D \\u001E \\u001F "
    "  ! \\\" # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z "
    "[ \\\\ ] ^ _ ` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~ \x7f "
    "\\u0080 \\u0081 \\u0082 \\u0083 \\u0084 \\u0085 \\u0086 \\u0087 \\u0088 \\u0089 \\u008A \\u008B \\u008C \\u008D "
    "\\u008E \\u008F \\u0090 \\u0091 \\u0092 \\u0093 \\u0094 \\u0095 \\u0096 \\u0097 \\u0098 \\u0099 \\u009A \\u009B "
    "\\u009C \\u009D \\u009E \\u009F \\u00A0 \\u00A1 \\u00A2 \\u00A3 \\u00A4 \\u00A5 \\u00A6 \\u00A7 \\u00A8 \\u00A9 "
    "\\u00AA \\u00AB \\u00AC \\u00AD \\u00AE \\u00AF \\u00B0 \\u00B1 \\u00B2 \\u00B3 \\u00B4 \\u00B5 \\u00B6 \\u00B7 "
    "\\u00B8 \\u00B9 \\u00BA \\u00BB \\u00BC \\u00BD \\u00BE \\u00BF \\u00C0 \\u00C1 \\u00C2 \\u00C3 \\u00C4 \\u00C5 "
    "\\u00C6 \\u00C7 \\u00C8 \\u00C9 \\u00CA \\u00CB \\u00CC \\u00CD \\u00CE \\u00CF \\u00D0 \\u00D1 \\u00D2 \\u00D3 "
    "\\u00D4 \\u00D5 \\u00D6 \\u00D7 \\u00D8 \\u00D9 \\u00DA \\u00DB \\u00DC \\u00DD \\u00DE \\u00DF \\u00E0 \\u00E1 "
    "\\u00E2 \\u00E3 \\u00E4 \\u00E5 \\u00E6 \\u00E7 \\u00E8 \\u00E9 \\u00EA \\u00EB \\u00EC \\u00ED \\u00EE \\u00EF "
    "\\u00F0 \\u00F1 \\u00F2 \\u00F3 \\u00F4 \\u00F5 \\u00F6 \\u00F7 \\u00F8 \\u00F9 \\u00FA \\u00FB \\u00FC \\u00FD "
    "\\u00FE \\u00FF\"}";

  CHK(yajl_gen_string(yg, payload, strlen((const char*)payload)));
  CHK(yajl_gen_string(yg, allcharacters, strlen((const char*)allcharacters)));
  CHK(yajl_gen_map_close(yg));

  const unsigned char *buf;
  size_t len;
  CHK(yajl_gen_get_buf(yg, &buf, &len));

  int ret;
  if ((ret = strcmp((const char*)buf, gold))) {
    printf("DIFF %d: \n%s\n%s\n", ret, buf, gold);
  }

  return ret;
}
