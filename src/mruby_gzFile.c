/*
 * gzFile
 * Defined in file zlib.h @ line 1227
 */

#include "mruby_ZLib.h"

#if BIND_GZFile_TYPE

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZFile::initialize */
/* sha: 37b92c9abf75cacd420cb28df7753bc8d23372e6937ce24b5a94d96db7467244 */
#if BIND_GZFile_INITIALIZE
mrb_value
mrb_ZLib_GZFile_initialize(mrb_state* mrb, mrb_value self) {
  mrb_raise(mrb, E_NOMETHOD_ERROR, "No initializer defined");
/* 
  gzFile* native_object = (gzFile*)calloc(1, sizeof(gzFile));
  mruby_gift_gzFile_data_ptr(self, native_object);
  return self;
*/
}
#endif
/* MRUBY_BINDING_END */


void mrb_ZLib_GZFile_init(mrb_state* mrb) {
  static int initialized = 0;
  if (initialized) return;
  else initialized = 1;

/* MRUBY_BINDING: pre_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZFile::class_definition */
/* sha: fe65399a1b14b32ec24193af1385d7b96d0ee65d288d0552b4934f16b4b9b35c */
  struct RClass* GZFile_class = mrb_define_class_under(mrb, ZLib_module(mrb), "GZFile", mrb->object_class);
  MRB_SET_INSTANCE_TT(GZFile_class, MRB_TT_DATA);
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZFile::pre_class_method_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZFile::class_method_definitions */
/* sha: 64e0709138a52bfa2b72ce6902c3b77f7ddaa905433faff5c5c3f673783c711a */
#if BIND_GZFile_INITIALIZE
  mrb_define_method(mrb, GZFile_class, "initialize", mrb_ZLib_GZFile_initialize, MRB_ARGS_NONE());
#endif
/* MRUBY_BINDING_END */



/* MRUBY_BINDING: GZFile::post_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
#endif
