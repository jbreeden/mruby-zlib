/*
 * gzFile
 * Defined in file zlib.h @ line 1224
 */

#include "mruby_ZLib.h"

#if BIND_GzFile_TYPE

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFile::initialize */
/* sha: 7a2a7edcc0d1650821b7eb2e8e0730991962d17d2874216ecf55d8f59070dcf3 */
#if BIND_GzFile_INITIALIZE
mrb_value
mrb_ZLib_GzFile_initialize(mrb_state* mrb, mrb_value self) {
  mrb_raise(mrb, E_NOMETHOD_ERROR, "No initializer defined");
/* 
  gzFile* native_object = (gzFile*)calloc(1, sizeof(gzFile));
  mruby_gift_gzFile_data_ptr(self, native_object);
  return self;
*/
}
#endif
/* MRUBY_BINDING_END */


void mrb_ZLib_GzFile_init(mrb_state* mrb) {
  static int initialized = 0;
  if (initialized) return;
  else initialized = 1;

/* MRUBY_BINDING: pre_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFile::class_definition */
/* sha: 8fcfe867faf09074ebec92663a962a0cec32beacc8531e26f644cf81299f92bd */
  struct RClass* GzFile_class = mrb_define_class_under(mrb, ZLib_module(mrb), "GzFile", mrb->object_class);
  MRB_SET_INSTANCE_TT(GzFile_class, MRB_TT_DATA);
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFile::pre_class_method_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFile::class_method_definitions */
/* sha: 3218ea9598b11be00ef1f2fa75723be2bc96504171ccec4e87ec5c828a25573d */
#if BIND_GzFile_INITIALIZE
  mrb_define_method(mrb, GzFile_class, "initialize", mrb_ZLib_GzFile_initialize, MRB_ARGS_NONE());
#endif
/* MRUBY_BINDING_END */



/* MRUBY_BINDING: GzFile::post_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
#endif
