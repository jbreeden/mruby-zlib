#include "mruby_ZLib.h"

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

void
mruby_ZLib_define_macro_constants(mrb_state* mrb) {
/* MRUBY_BINDING: pre_macro_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

#ifdef Z_ASCII
  do {
    mrb_value macro = mrb_fixnum_value(Z_ASCII);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_ASCII", macro);
  } while (0);
#endif
#ifdef Z_BEST_COMPRESSION
  do {
    mrb_value macro = mrb_fixnum_value(Z_BEST_COMPRESSION);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_BEST_COMPRESSION", macro);
  } while (0);
#endif
#ifdef Z_BEST_SPEED
  do {
    mrb_value macro = mrb_fixnum_value(Z_BEST_SPEED);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_BEST_SPEED", macro);
  } while (0);
#endif
#ifdef Z_BINARY
  do {
    mrb_value macro = mrb_fixnum_value(Z_BINARY);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_BINARY", macro);
  } while (0);
#endif
#ifdef Z_BLOCK
  do {
    mrb_value macro = mrb_fixnum_value(Z_BLOCK);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_BLOCK", macro);
  } while (0);
#endif
#ifdef Z_BUF_ERROR
  do {
    mrb_value macro = mrb_fixnum_value(Z_BUF_ERROR);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_BUF_ERROR", macro);
  } while (0);
#endif
#ifdef Z_DATA_ERROR
  do {
    mrb_value macro = mrb_fixnum_value(Z_DATA_ERROR);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_DATA_ERROR", macro);
  } while (0);
#endif
#ifdef Z_DEFAULT_COMPRESSION
  do {
    mrb_value macro = mrb_fixnum_value(Z_DEFAULT_COMPRESSION);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_DEFAULT_COMPRESSION", macro);
  } while (0);
#endif
#ifdef Z_DEFAULT_STRATEGY
  do {
    mrb_value macro = mrb_fixnum_value(Z_DEFAULT_STRATEGY);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_DEFAULT_STRATEGY", macro);
  } while (0);
#endif
#ifdef Z_DEFLATED
  do {
    mrb_value macro = mrb_fixnum_value(Z_DEFLATED);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_DEFLATED", macro);
  } while (0);
#endif
#ifdef Z_ERRNO
  do {
    mrb_value macro = mrb_fixnum_value(Z_ERRNO);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_ERRNO", macro);
  } while (0);
#endif
#ifdef Z_FILTERED
  do {
    mrb_value macro = mrb_fixnum_value(Z_FILTERED);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_FILTERED", macro);
  } while (0);
#endif
#ifdef Z_FINISH
  do {
    mrb_value macro = mrb_fixnum_value(Z_FINISH);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_FINISH", macro);
  } while (0);
#endif
#ifdef Z_FIXED
  do {
    mrb_value macro = mrb_fixnum_value(Z_FIXED);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_FIXED", macro);
  } while (0);
#endif
#ifdef Z_FULL_FLUSH
  do {
    mrb_value macro = mrb_fixnum_value(Z_FULL_FLUSH);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_FULL_FLUSH", macro);
  } while (0);
#endif
#ifdef Z_HUFFMAN_ONLY
  do {
    mrb_value macro = mrb_fixnum_value(Z_HUFFMAN_ONLY);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_HUFFMAN_ONLY", macro);
  } while (0);
#endif
#ifdef Z_MEM_ERROR
  do {
    mrb_value macro = mrb_fixnum_value(Z_MEM_ERROR);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_MEM_ERROR", macro);
  } while (0);
#endif
#ifdef Z_NEED_DICT
  do {
    mrb_value macro = mrb_fixnum_value(Z_NEED_DICT);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_NEED_DICT", macro);
  } while (0);
#endif
#ifdef Z_NO_COMPRESSION
  do {
    mrb_value macro = mrb_fixnum_value(Z_NO_COMPRESSION);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_NO_COMPRESSION", macro);
  } while (0);
#endif
#ifdef Z_NO_FLUSH
  do {
    mrb_value macro = mrb_fixnum_value(Z_NO_FLUSH);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_NO_FLUSH", macro);
  } while (0);
#endif
#ifdef Z_NULL
  do {
    mrb_value macro = mrb_fixnum_value(Z_NULL);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_NULL", macro);
  } while (0);
#endif
#ifdef Z_OK
  do {
    mrb_value macro = mrb_fixnum_value(Z_OK);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_OK", macro);
  } while (0);
#endif
#ifdef Z_PARTIAL_FLUSH
  do {
    mrb_value macro = mrb_fixnum_value(Z_PARTIAL_FLUSH);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_PARTIAL_FLUSH", macro);
  } while (0);
#endif
#ifdef Z_RLE
  do {
    mrb_value macro = mrb_fixnum_value(Z_RLE);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_RLE", macro);
  } while (0);
#endif
#ifdef Z_STREAM_END
  do {
    mrb_value macro = mrb_fixnum_value(Z_STREAM_END);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_STREAM_END", macro);
  } while (0);
#endif
#ifdef Z_STREAM_ERROR
  do {
    mrb_value macro = mrb_fixnum_value(Z_STREAM_ERROR);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_STREAM_ERROR", macro);
  } while (0);
#endif
#ifdef Z_SYNC_FLUSH
  do {
    mrb_value macro = mrb_fixnum_value(Z_SYNC_FLUSH);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_SYNC_FLUSH", macro);
  } while (0);
#endif
#ifdef Z_TEXT
  do {
    mrb_value macro = mrb_fixnum_value(Z_TEXT);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_TEXT", macro);
  } while (0);
#endif
#ifdef Z_TREES
  do {
    mrb_value macro = mrb_fixnum_value(Z_TREES);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_TREES", macro);
  } while (0);
#endif
#ifdef Z_UNKNOWN
  do {
    mrb_value macro = mrb_fixnum_value(Z_UNKNOWN);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_UNKNOWN", macro);
  } while (0);
#endif
#ifdef Z_VERSION_ERROR
  do {
    mrb_value macro = mrb_fixnum_value(Z_VERSION_ERROR);
    mrb_define_const(mrb, ZLib_module(mrb), "Z_VERSION_ERROR", macro);
  } while (0);
#endif

/* MRUBY_BINDING: post_macro_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
