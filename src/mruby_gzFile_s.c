/*
 * struct gzFile_s
 * Defined in file zlib.h @ line 1224
 */

#include "mruby_ZLib.h"

#if BIND_GzFileS_TYPE

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFileS::initialize */
/* sha: 676076331d163890a420b304ed75fdd03af19733830e6994c3b61b5b1264cf7f */
#if BIND_GzFileS_INITIALIZE
mrb_value
mrb_ZLib_GzFileS_initialize(mrb_state* mrb, mrb_value self) {
  mrb_raise(mrb, E_NOMETHOD_ERROR, "No initializer defined");
/* 
  struct gzFile_s* native_object = (struct gzFile_s*)calloc(1, sizeof(struct gzFile_s));
  mruby_gift_gzFile_s_data_ptr(self, native_object);
  return self;
*/
}
#endif
/* MRUBY_BINDING_END */


void mrb_ZLib_GzFileS_init(mrb_state* mrb) {
  static int initialized = 0;
  if (initialized) return;
  else initialized = 1;

/* MRUBY_BINDING: pre_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFileS::class_definition */
/* sha: d7df6c2587fd3cf63e2aa992f4d22d180f7a6dcd48b2c453b35a32413a8b9a2f */
  struct RClass* GzFileS_class = mrb_define_class_under(mrb, ZLib_module(mrb), "GzFileS", mrb->object_class);
  MRB_SET_INSTANCE_TT(GzFileS_class, MRB_TT_DATA);
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFileS::pre_class_method_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFileS::class_method_definitions */
/* sha: 2546d922ce276996c5bfeb1b5ce351c9771af533f5bddddb96775f01044ba886 */
#if BIND_GzFileS_INITIALIZE
  mrb_define_method(mrb, GzFileS_class, "initialize", mrb_ZLib_GzFileS_initialize, MRB_ARGS_NONE());
#endif
/* MRUBY_BINDING_END */



/* MRUBY_BINDING: GzFileS::post_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
#endif
