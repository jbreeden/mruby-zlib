/*
 * gz_header
 * Defined in file zlib.h @ line 119
 */

#include "mruby_ZLib.h"

#if BIND_GZHeader_TYPE

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::initialize */
/* sha: 281d8c056ac87061e546de6c34c0a9cff2e1f4ccc6b37bd395d99a8cc5c7512f */
#if BIND_GZHeader_INITIALIZE
mrb_value
mrb_ZLib_GZHeader_initialize(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::text_reader */
/* sha: d968a8eacb82e8b79e4bd3dda9fc5cea5bdeea0af06461e69efe09b6356fa9e1 */
#if BIND_GZHeader_text_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_text(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_text = native_self->text;

  mrb_value text = mrb_fixnum_value(native_text);

  return text;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::text_writer */
/* sha: 3f30b5d39277067e6a1e4da3eb05de48439e5cbf826a96fa676877e379a53d81 */
#if BIND_GZHeader_text_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_text(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::time_reader */
/* sha: 8427514d3bf81fe5595541e0dfbc2ad99ee389b6f094a2c955cb5775d7716a89 */
#if BIND_GZHeader_time_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_time(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uLong native_time = native_self->time;

  mrb_value time = mrb_fixnum_value(native_time);

  return time;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::time_writer */
/* sha: b5103bcf3c81c06d8f3892c8c50e594718f1e6f9e202ee8d301b177f8380bbcb */
#if BIND_GZHeader_time_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_time(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::xflags_reader */
/* sha: 1b08ac1a834d7f540ca1be4c8bd4b60d6f10a80c0cf29cb034e057cf753e1e05 */
#if BIND_GZHeader_xflags_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_xflags(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_xflags = native_self->xflags;

  mrb_value xflags = mrb_fixnum_value(native_xflags);

  return xflags;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::xflags_writer */
/* sha: 5557c2a93177916932efebedb864883081e90ed8f9d1ab1ee8e9ee65df1901ee */
#if BIND_GZHeader_xflags_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_xflags(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::os_reader */
/* sha: 77b6f5c06a33dc748eb80c42d61d4f3a3707354ad684220d14888dabb80b3caa */
#if BIND_GZHeader_os_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_os(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_os = native_self->os;

  mrb_value os = mrb_fixnum_value(native_os);

  return os;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::os_writer */
/* sha: 599a18fc818f9870ebf2317a00cfaa317d19b0164a20795df83c367d9f4d7d76 */
#if BIND_GZHeader_os_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_os(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::extra_reader */
/* sha: 8187a0d88baa00f56fa290a42038a66f61c73bfbb4075c25478f16436df4485a */
#if BIND_GZHeader_extra_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_extra(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  Bytef * native_extra = native_self->extra;

  mrb_value extra = TODO_mruby_box_Bytef_PTR(mrb, native_extra);

  return extra;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::extra_writer */
/* sha: f6232165c8ce35b75dfc73cd575c4761e3004cc508be2f642c68dc24a4321d49 */
#if BIND_GZHeader_extra_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_extra(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::extra_len_reader */
/* sha: 489545a339dedc3730a88f74c97a521967b1d1a56e094379a29cec581d014e3e */
#if BIND_GZHeader_extra_len_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_extra_len(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uInt native_extra_len = native_self->extra_len;

  mrb_value extra_len = TODO_mruby_box_uInt(mrb, native_extra_len);

  return extra_len;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::extra_len_writer */
/* sha: b334e6ffb3014cc46868abf92cd3abc67a253719635c18635415c5ccf159ea01 */
#if BIND_GZHeader_extra_len_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_extra_len(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::extra_max_reader */
/* sha: 85701d403502665b76d54dea6753ae7e120c84a266f5547dd6fa81bf2702a121 */
#if BIND_GZHeader_extra_max_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_extra_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uInt native_extra_max = native_self->extra_max;

  mrb_value extra_max = TODO_mruby_box_uInt(mrb, native_extra_max);

  return extra_max;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::extra_max_writer */
/* sha: f2469f2bb1cacde8ec9421971527c340324c240e1b70f55328e062fabd0baf1b */
#if BIND_GZHeader_extra_max_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_extra_max(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::name_reader */
/* sha: bf321c623ad453d6a3566d5fcbfc88d36ee688bc8fcabe2c53bc7b865caba66a */
#if BIND_GZHeader_name_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_name(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  Bytef * native_name = native_self->name;

  mrb_value name = TODO_mruby_box_Bytef_PTR(mrb, native_name);

  return name;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::name_writer */
/* sha: 77c0d6c23acbda19c737467b12ebc35402fa030ec847055805ee7d99d5b50434 */
#if BIND_GZHeader_name_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_name(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::name_max_reader */
/* sha: 57fdae2b15fcd947c9eec206041784a1c31c76398bc14ddea490fc5b52f24d57 */
#if BIND_GZHeader_name_max_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_name_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uInt native_name_max = native_self->name_max;

  mrb_value name_max = TODO_mruby_box_uInt(mrb, native_name_max);

  return name_max;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::name_max_writer */
/* sha: 68b64aafb1b20b9c560707ae910e65606ebd14e2be759760a0821071aae82f04 */
#if BIND_GZHeader_name_max_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_name_max(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::comment_reader */
/* sha: 91124d05c556e875e8006e66fd43eb1e684497497609a2bd0d016a0b81abf6f1 */
#if BIND_GZHeader_comment_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_comment(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  Bytef * native_comment = native_self->comment;

  mrb_value comment = TODO_mruby_box_Bytef_PTR(mrb, native_comment);

  return comment;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::comment_writer */
/* sha: 1f0e75018c4ab93a9a9d9ef1f6148414c8ca5822f67aca9040c7f0067666caca */
#if BIND_GZHeader_comment_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_comment(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::comm_max_reader */
/* sha: e6852104f607b25d754c61be4016c66529db63fc958bc340077f7fbbb056d4ec */
#if BIND_GZHeader_comm_max_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_comm_max(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  uInt native_comm_max = native_self->comm_max;

  mrb_value comm_max = TODO_mruby_box_uInt(mrb, native_comm_max);

  return comm_max;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::comm_max_writer */
/* sha: ef41d19a3330ac2c3c8b50d75434a6bf352dfdef967a91c94e5ebab200b1bd59 */
#if BIND_GZHeader_comm_max_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_comm_max(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::hcrc_reader */
/* sha: f8bfb5b589600eaaad9d55a82478434c45e403815f513fa269bdca79252364c3 */
#if BIND_GZHeader_hcrc_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_hcrc(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_hcrc = native_self->hcrc;

  mrb_value hcrc = mrb_fixnum_value(native_hcrc);

  return hcrc;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::hcrc_writer */
/* sha: 563ad064a4dc4729ba5501c1175a723ef33e80b0891c42e62d23afa1334da005 */
#if BIND_GZHeader_hcrc_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_hcrc(mrb_state* mrb, mrb_value self) {
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

/* MRUBY_BINDING: GZHeader::done_reader */
/* sha: d4ddfabd957ca693d29f1222dd13b19ed7250751b69891be17a2e9a62b50f17d */
#if BIND_GZHeader_done_FIELD_READER
mrb_value
mrb_ZLib_GZHeader_get_done(mrb_state* mrb, mrb_value self) {
  gz_header * native_self = mruby_unbox_gz_header(self);

  int native_done = native_self->done;

  mrb_value done = mrb_fixnum_value(native_done);

  return done;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::done_writer */
/* sha: 28b71512df84acaf87924adbf2ab3b61355974ad7ef0a27ccfbf98a90cbd487c */
#if BIND_GZHeader_done_FIELD_WRITER
mrb_value
mrb_ZLib_GZHeader_set_done(mrb_state* mrb, mrb_value self) {
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


void mrb_ZLib_GZHeader_init(mrb_state* mrb) {
  static int initialized = 0;
  if (initialized) return;
  else initialized = 1;

/* MRUBY_BINDING: pre_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::class_definition */
/* sha: 51812cfccf733737112702dff03c39eb0d5521ee65f48562f18434a1477a8717 */
  struct RClass* GZHeader_class = mrb_define_class_under(mrb, ZLib_module(mrb), "GZHeader", mrb->object_class);
  MRB_SET_INSTANCE_TT(GZHeader_class, MRB_TT_DATA);
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::pre_class_method_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::class_method_definitions */
/* sha: 6861efaedac6b0825147c2a384b2255035fa8c66422e3123e417c762ddaa8e3e */
#if BIND_GZHeader_INITIALIZE
  mrb_define_method(mrb, GZHeader_class, "initialize", mrb_ZLib_GZHeader_initialize, MRB_ARGS_NONE());
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::pre_attr_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::attr_definitions */
/* sha: 429110a0410038b7e74ba0be3ee49e00b861a0052a69d2545d03dcfc21027e70 */
  /*
   * Fields
   */
#if BIND_GZHeader_text_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "text", mrb_ZLib_GZHeader_get_text, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_text_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "text=", mrb_ZLib_GZHeader_set_text, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_time_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "time", mrb_ZLib_GZHeader_get_time, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_time_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "time=", mrb_ZLib_GZHeader_set_time, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_xflags_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "xflags", mrb_ZLib_GZHeader_get_xflags, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_xflags_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "xflags=", mrb_ZLib_GZHeader_set_xflags, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_os_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "os", mrb_ZLib_GZHeader_get_os, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_os_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "os=", mrb_ZLib_GZHeader_set_os, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_extra_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "extra", mrb_ZLib_GZHeader_get_extra, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_extra_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "extra=", mrb_ZLib_GZHeader_set_extra, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_extra_len_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "extra_len", mrb_ZLib_GZHeader_get_extra_len, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_extra_len_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "extra_len=", mrb_ZLib_GZHeader_set_extra_len, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_extra_max_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "extra_max", mrb_ZLib_GZHeader_get_extra_max, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_extra_max_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "extra_max=", mrb_ZLib_GZHeader_set_extra_max, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_name_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "name", mrb_ZLib_GZHeader_get_name, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_name_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "name=", mrb_ZLib_GZHeader_set_name, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_name_max_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "name_max", mrb_ZLib_GZHeader_get_name_max, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_name_max_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "name_max=", mrb_ZLib_GZHeader_set_name_max, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_comment_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "comment", mrb_ZLib_GZHeader_get_comment, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_comment_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "comment=", mrb_ZLib_GZHeader_set_comment, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_comm_max_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "comm_max", mrb_ZLib_GZHeader_get_comm_max, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_comm_max_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "comm_max=", mrb_ZLib_GZHeader_set_comm_max, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_hcrc_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "hcrc", mrb_ZLib_GZHeader_get_hcrc, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_hcrc_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "hcrc=", mrb_ZLib_GZHeader_set_hcrc, MRB_ARGS_ARG(1, 0));
#endif
#if BIND_GZHeader_done_FIELD_READER
  mrb_define_method(mrb, GZHeader_class, "done", mrb_ZLib_GZHeader_get_done, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_GZHeader_done_FIELD_WRITER
  mrb_define_method(mrb, GZHeader_class, "done=", mrb_ZLib_GZHeader_set_done, MRB_ARGS_ARG(1, 0));
#endif
/* MRUBY_BINDING_END */


/* MRUBY_BINDING: GZHeader::post_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
#endif
