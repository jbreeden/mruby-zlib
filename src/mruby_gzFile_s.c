/* - MRUBY_BINDINGS_NO_CLOBBER -
 *
 * struct gzFile_s
 * Defined in file zlib.h @ line 1220
 */

#include "mruby_ZLib.h"

#if BIND_GZFile_TYPE

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZFile::initialize */
/* sha: cf8f931114848506ff40be8babe93afdf8eebeaae7e7b2a9fa8d14c85a0a5ffa */
#if BIND_GZFile_INITIALIZE
mrb_value
mrb_ZLib_GZFile_initialize(mrb_state* mrb, mrb_value self) {
  mrb_raise(mrb, E_NOMETHOD_ERROR, "No initializer defined");
/* 
  struct gzFile_s* native_object = (struct gzFile_s*)calloc(1, sizeof(struct gzFile_s));
  mruby_gift_gzFile_s_data_ptr(self, native_object);
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
/* sha: e03f02e65c89166e4270e007a36d6124bfa9491cada6a19bc4cc994e0bf5b64f */
  struct RClass* GZFile_class = mrb_define_class_under(mrb, ZLib_module(mrb), "GZFile", mrb->object_class);
  MRB_SET_INSTANCE_TT(GZFile_class, MRB_TT_DATA);
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZFile::pre_class_method_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZFile::class_method_definitions */
/* sha: 3528b1e24c76ac3fb0c405e25cba046eb57e7e3aaab9f16eb5a0d38df3e92e55 */
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
