/*
 * gz_header
 * Defined in file zlib.h @ line 112
 */

#include "mruby_ZLib.h"

#if BIND_GzHeader_TYPE

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::initialize */
/* sha: 73c9295cde16c4168481aed4e9f072ca638aadbeace18572e584dd848253b5ee */
#if BIND_GzHeader_INITIALIZE
mrb_value
mrb_ZLib_GzHeader_initialize(mrb_state* mrb, mrb_value self) {
  mrb_raise(mrb, E_NOMETHOD_ERROR, "No initializer defined");
/* 
  gz_header* native_object = (gz_header*)calloc(1, sizeof(gz_header));
  mruby_gift_gz_header_data_ptr(self, native_object);
  return self;
*/
}
#endif
/* MRUBY_BINDING_END */

/*
 * Fields
 */

/* MRUBY_BINDING: GzHeader::text_reader */
/* sha: a79607b69b7154a5b32560c7b064601838fcfbd19c658b36a7adbf23e5f3d686 */
#if BIND_GzHeader_text_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_text(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_text = native_self->text;

  mrb_value text = mrb_fixnum_value(native_text);

  return text;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::text_writer */
/* sha: e76d80a2fdf4143c3255482788ef672d19d32cf33489133afcf902522aba458f */
#if BIND_GzHeader_text_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_text(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_int native_text;

  mrb_get_args(mrb, "i", &native_text);

  native_self->text = native_text;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::time_reader */
/* sha: c18399709dabfcc7dc9b8283eecd46aa6423d345bb1cbb5436f69f171b94b7d1 */
#if BIND_GzHeader_time_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_time(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uLong native_time = native_self->time;

  mrb_value time = mrb_fixnum_value(native_time);

  return time;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::time_writer */
/* sha: 1c22ff8ef343d5e33d5950ae31e6eae761c34cecd52c36621ecbf63e14b4bd36 */
#if BIND_GzHeader_time_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_time(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_int native_time;

  mrb_get_args(mrb, "i", &native_time);

  native_self->time = native_time;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::xflags_reader */
/* sha: 30a89ee4cffba890e9a7e27ee3ec6dadd4889601b481c2dbf0d657d86c9b604e */
#if BIND_GzHeader_xflags_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_xflags(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_xflags = native_self->xflags;

  mrb_value xflags = mrb_fixnum_value(native_xflags);

  return xflags;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::xflags_writer */
/* sha: 98ef724f5bfdc8d75d5dc02206abfee327d15466ff60e7d2baf5302627a8352e */
#if BIND_GzHeader_xflags_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_xflags(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_int native_xflags;

  mrb_get_args(mrb, "i", &native_xflags);

  native_self->xflags = native_xflags;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::os_reader */
/* sha: a921a99680c97c9c0c8cbc3187b5fe643bc500a59eddeb9d5ad10e06a43dedbb */
#if BIND_GzHeader_os_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_os(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_os = native_self->os;

  mrb_value os = mrb_fixnum_value(native_os);

  return os;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::os_writer */
/* sha: 8284e69502cbecf739fe1d20281f12474fbf6824e0e60d1f1299a3d952beac85 */
#if BIND_GzHeader_os_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_os(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_int native_os;

  mrb_get_args(mrb, "i", &native_os);

  native_self->os = native_os;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::extra_reader */
/* sha: 17f71128f99dc5e848f043f398a9326158a79d01f41794eb5b8363624c56770c */
#if BIND_GzHeader_extra_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_extra(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  Bytef * native_extra = native_self->extra;

  mrb_value extra = TODO_mruby_box_Bytef_PTR(mrb, native_extra);

  return extra;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::extra_writer */
/* sha: 85ac951d74d182315c1905123619ae9895d03687587b3e29d5f313e3e89013bc */
#if BIND_GzHeader_extra_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_extra(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_value extra;

  mrb_get_args(mrb, "o", &extra);

  /* type checking */
  TODO_type_check_Bytef_PTR(extra);

  Bytef * native_extra = TODO_mruby_unbox_Bytef_PTR(extra);

  native_self->extra = native_extra;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::extra_len_reader */
/* sha: 9e8766ac0e0dae662c0208e1d1bb013a028a2661d21cec2022237f7076989572 */
#if BIND_GzHeader_extra_len_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_extra_len(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uInt native_extra_len = native_self->extra_len;

  mrb_value extra_len = TODO_mruby_box_uInt(mrb, native_extra_len);

  return extra_len;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::extra_len_writer */
/* sha: 76f716d068835c37bd89482c5f57ba8d99df3944fde0bcd3a342a121e5ff023b */
#if BIND_GzHeader_extra_len_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_extra_len(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_value extra_len;

  mrb_get_args(mrb, "o", &extra_len);

  /* type checking */
  TODO_type_check_uInt(extra_len);

  uInt native_extra_len = TODO_mruby_unbox_uInt(extra_len);

  native_self->extra_len = native_extra_len;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::extra_max_reader */
/* sha: 8cba294584e201bca7edde3518b2cd34d55e03eb288388df57437eb3da0b927e */
#if BIND_GzHeader_extra_max_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_extra_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uInt native_extra_max = native_self->extra_max;

  mrb_value extra_max = TODO_mruby_box_uInt(mrb, native_extra_max);

  return extra_max;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::extra_max_writer */
/* sha: 403f35dec85a9dd6df4691d920ede483a8bbd96909f98280324eb54d1d161602 */
#if BIND_GzHeader_extra_max_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_extra_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_value extra_max;

  mrb_get_args(mrb, "o", &extra_max);

  /* type checking */
  TODO_type_check_uInt(extra_max);

  uInt native_extra_max = TODO_mruby_unbox_uInt(extra_max);

  native_self->extra_max = native_extra_max;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::name_reader */
/* sha: 6256fe4a12fd10088ba41242d7df8d8ac59b8100bee1bb82e00ec9492517ff83 */
#if BIND_GzHeader_name_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_name(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  Bytef * native_name = native_self->name;

  mrb_value name = TODO_mruby_box_Bytef_PTR(mrb, native_name);

  return name;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::name_writer */
/* sha: bdf8d01c6c6342f2d23a81048eadbd7209f2068d9b74aba8803fd38fb359fb5b */
#if BIND_GzHeader_name_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_name(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_value name;

  mrb_get_args(mrb, "o", &name);

  /* type checking */
  TODO_type_check_Bytef_PTR(name);

  Bytef * native_name = TODO_mruby_unbox_Bytef_PTR(name);

  native_self->name = native_name;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::name_max_reader */
/* sha: 42f7c1de8d4ea4c57bfd18434bf45e7fac4ee5ae530f4fb6ac879305d9c239e7 */
#if BIND_GzHeader_name_max_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_name_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uInt native_name_max = native_self->name_max;

  mrb_value name_max = TODO_mruby_box_uInt(mrb, native_name_max);

  return name_max;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::name_max_writer */
/* sha: c6ebb21b0ec22cd7ebb4cce272423e4b4839f9e73961445b557744cf00c5bc45 */
#if BIND_GzHeader_name_max_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_name_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_value name_max;

  mrb_get_args(mrb, "o", &name_max);

  /* type checking */
  TODO_type_check_uInt(name_max);

  uInt native_name_max = TODO_mruby_unbox_uInt(name_max);

  native_self->name_max = native_name_max;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::comment_reader */
/* sha: 7281a0e18c29f10ae76194e0c5824404c5615c2110634fb1c33e9c86fc81016c */
#if BIND_GzHeader_comment_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_comment(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  Bytef * native_comment = native_self->comment;

  mrb_value comment = TODO_mruby_box_Bytef_PTR(mrb, native_comment);

  return comment;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::comment_writer */
/* sha: d3fb67a4cd1b80874d1320a3fa8a04952f49dc751b81c59c2969fb1f0844a7f3 */
#if BIND_GzHeader_comment_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_comment(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_value comment;

  mrb_get_args(mrb, "o", &comment);

  /* type checking */
  TODO_type_check_Bytef_PTR(comment);

  Bytef * native_comment = TODO_mruby_unbox_Bytef_PTR(comment);

  native_self->comment = native_comment;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::comm_max_reader */
/* sha: 7072b1c98aad4d72a3acb58ca440d50c1123484d300c3b881cdbe34458a99f6f */
#if BIND_GzHeader_comm_max_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_comm_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uInt native_comm_max = native_self->comm_max;

  mrb_value comm_max = TODO_mruby_box_uInt(mrb, native_comm_max);

  return comm_max;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::comm_max_writer */
/* sha: 101dd578302dc4d1c2923dfadf34ccc29e631691774384641d754dfd21a220de */
#if BIND_GzHeader_comm_max_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_comm_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_value comm_max;

  mrb_get_args(mrb, "o", &comm_max);

  /* type checking */
  TODO_type_check_uInt(comm_max);

  uInt native_comm_max = TODO_mruby_unbox_uInt(comm_max);

  native_self->comm_max = native_comm_max;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::hcrc_reader */
/* sha: 13e950a65c48879701e999941c1262aff428046810a4f7afe2853b12c1c137c9 */
#if BIND_GzHeader_hcrc_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_hcrc(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_hcrc = native_self->hcrc;

  mrb_value hcrc = mrb_fixnum_value(native_hcrc);

  return hcrc;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::hcrc_writer */
/* sha: fdcf249600c77bdaf3e0432f5ccec98aed6335a004f037a7d4b8bc0fb021fc67 */
#if BIND_GzHeader_hcrc_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_hcrc(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_int native_hcrc;

  mrb_get_args(mrb, "i", &native_hcrc);

  native_self->hcrc = native_hcrc;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::done_reader */
/* sha: d69ccd6c986ddfa24d84c503b0fc935d8227489dd7e400572b088fd7c0c9005e */
#if BIND_GzHeader_done_FIELD_READER
mrb_value
mrb_ZLib_GzHeader_get_done(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_done = native_self->done;

  mrb_value done = mrb_fixnum_value(native_done);

  return done;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::done_writer */
/* sha: d22e7e409dbf1918cd67d3ed66429dfae318b695d4b910c69a41d7c4421eb097 */
#if BIND_GzHeader_done_FIELD_WRITER
mrb_value
mrb_ZLib_GzHeader_set_done(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);
  mrb_int native_done;

  mrb_get_args(mrb, "i", &native_done);

  native_self->done = native_done;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */


void mrb_ZLib_GzHeader_init(mrb_state* mrb) {
  static int initialized = 0;
  if (initialized) return;
  else initialized = 1;

/* MRUBY_BINDING: pre_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::class_definition */
/* sha: fbac9b024bad6e6793438513471f4aa4d46e0387b061915f23c250d0da99e68d */
  struct RClass* GzHeader_class = mrb_define_class_under(mrb, ZLib_module(mrb), "GzHeader", mrb->object_class);
  MRB_SET_INSTANCE_TT(GzHeader_class, MRB_TT_DATA);
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::pre_class_method_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::class_method_definitions */
/* sha: 332a63cd80704d3bc7b317cb7b87e91936f888be79b8948787218e37e3ee9441 */
#if BIND_GzHeader_INITIALIZE
  mrb_define_method(mrb, GzHeader_class, "initialize", mrb_ZLib_GzHeader_initialize, MRB_ARGS_NONE());
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::pre_attr_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::attr_definitions */
/* sha: d9954c55ce2f5c97be2cce791fce0a079c09b2a23967fdca156d1aae8707aa08 */
  /*
   * Fields
   */
#if BIND_GzHeader_text_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "text", mrb_ZLib_GzHeader_get_text, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_text_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "text=", mrb_ZLib_GzHeader_set_text, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_time_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "time", mrb_ZLib_GzHeader_get_time, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_time_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "time=", mrb_ZLib_GzHeader_set_time, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_xflags_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "xflags", mrb_ZLib_GzHeader_get_xflags, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_xflags_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "xflags=", mrb_ZLib_GzHeader_set_xflags, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_os_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "os", mrb_ZLib_GzHeader_get_os, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_os_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "os=", mrb_ZLib_GzHeader_set_os, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_extra_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "extra", mrb_ZLib_GzHeader_get_extra, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_extra_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "extra=", mrb_ZLib_GzHeader_set_extra, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_extra_len_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "extra_len", mrb_ZLib_GzHeader_get_extra_len, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_extra_len_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "extra_len=", mrb_ZLib_GzHeader_set_extra_len, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_extra_max_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "extra_max", mrb_ZLib_GzHeader_get_extra_max, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_extra_max_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "extra_max=", mrb_ZLib_GzHeader_set_extra_max, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_name_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "name", mrb_ZLib_GzHeader_get_name, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_name_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "name=", mrb_ZLib_GzHeader_set_name, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_name_max_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "name_max", mrb_ZLib_GzHeader_get_name_max, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_name_max_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "name_max=", mrb_ZLib_GzHeader_set_name_max, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_comment_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "comment", mrb_ZLib_GzHeader_get_comment, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_comment_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "comment=", mrb_ZLib_GzHeader_set_comment, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_comm_max_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "comm_max", mrb_ZLib_GzHeader_get_comm_max, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_comm_max_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "comm_max=", mrb_ZLib_GzHeader_set_comm_max, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_hcrc_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "hcrc", mrb_ZLib_GzHeader_get_hcrc, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_hcrc_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "hcrc=", mrb_ZLib_GzHeader_set_hcrc, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GzHeader_done_FIELD_READER
  mrb_define_method(mrb, GzHeader_class, "done", mrb_ZLib_GzHeader_get_done, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GzHeader_done_FIELD_WRITER
  mrb_define_method(mrb, GzHeader_class, "done=", mrb_ZLib_GzHeader_set_done, MRB_ARGS_ARG(1, 0));
#endif
/* MRUBY_BINDING_END */


/* MRUBY_BINDING: GzHeader::post_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
#endif
