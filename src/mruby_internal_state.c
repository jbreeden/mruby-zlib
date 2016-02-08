/*
 * struct internal_state
 * Defined in file zlib.h @ line 90
 */

#include "mruby_ZLib.h"

#if BIND_InternalState_TYPE

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState::initialize */
/* sha: 720d404a6ae5bf99f9205b028b449cde4ee555dfacbbee30271501ea9843932f */
#if BIND_InternalState_INITIALIZE
mrb_value
mrb_ZLib_InternalState_initialize(mrb_state* mrb, mrb_value self) {
  mrb_raise(mrb, E_NOMETHOD_ERROR, "No initializer defined");
/* 
  struct internal_state* native_object = (struct internal_state*)calloc(1, sizeof(struct internal_state));
  mruby_gift_internal_state_data_ptr(self, native_object);
  return self;
*/
}
#endif
/* MRUBY_BINDING_END */

/*
 * Fields
 */

/* MRUBY_BINDING: InternalState::dummy_reader */
/* sha: 93e9c8af8038dfe9628173cdef5215ebf210db7c89bb6f221a8426897875bb52 */
#if BIND_InternalState_dummy_FIELD_READER
mrb_value
mrb_ZLib_InternalState_get_dummy(mrb_state* mrb, mrb_value self) {
  struct internal_state * native_self = mruby_unbox_internal_state(self);

  int native_dummy = native_self->dummy;

  mrb_value dummy = mrb_fixnum_value(native_dummy);

  return dummy;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState::dummy_writer */
/* sha: 012c3f72951529ff6f02ef7897ec5ddbe3004c398f732e80ee345821096e5b88 */
#if BIND_InternalState_dummy_FIELD_WRITER
mrb_value
mrb_ZLib_InternalState_set_dummy(mrb_state* mrb, mrb_value self) {
  struct internal_state * native_self = mruby_unbox_internal_state(self);
  mrb_int native_dummy;

  mrb_get_args(mrb, "i", &native_dummy);

  native_self->dummy = native_dummy;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */


void mrb_ZLib_InternalState_init(mrb_state* mrb) {
  static int initialized = 0;
  if (initialized) return;
  else initialized = 1;

/* MRUBY_BINDING: pre_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState::class_definition */
/* sha: 0a591509a18d1466241840e37724e1c92104a16fd354322f3f3376f83d912747 */
  struct RClass* InternalState_class = mrb_define_class_under(mrb, ZLib_module(mrb), "InternalState", mrb->object_class);
  MRB_SET_INSTANCE_TT(InternalState_class, MRB_TT_DATA);
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState::pre_class_method_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState::class_method_definitions */
/* sha: 2eb5f11f15bf325f341f621c478949b164401f3a48e6b0835571fb5650457717 */
#if BIND_InternalState_INITIALIZE
  mrb_define_method(mrb, InternalState_class, "initialize", mrb_ZLib_InternalState_initialize, MRB_ARGS_NONE());
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState::pre_attr_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState::attr_definitions */
/* sha: e2d4653628dff092721fa41cff6535fa0c0112e23f3cb9e4e8ec76fe7bfced9e */
  /*
   * Fields
   */
#if BIND_InternalState_dummy_FIELD_READER
  mrb_define_method(mrb, InternalState_class, "dummy", mrb_ZLib_InternalState_get_dummy, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_InternalState_dummy_FIELD_WRITER
  mrb_define_method(mrb, InternalState_class, "dummy=", mrb_ZLib_InternalState_set_dummy, MRB_ARGS_ARG(1, 0));
#endif
/* MRUBY_BINDING_END */


/* MRUBY_BINDING: InternalState::post_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
#endif
