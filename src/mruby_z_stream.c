/*
 * z_stream
 * Defined in file zlib.h @ line 92
 */

#include "mruby_ZLib.h"

#if BIND_ZStream_TYPE

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::initialize */
/* sha: 9d7a6a6f27ef8f216bc8f14d80bbc19a9009a9dd7d29c76ed91c617b7e6e31d8 */
#if BIND_ZStream_INITIALIZE
mrb_value
mrb_ZLib_ZStream_initialize(mrb_state* mrb, mrb_value self) {
  mrb_int buffer_size = BUFFER_SIZE;
  
  mrb_get_args(mrb, "|i", &buffer_size);
  
  mruby_z_stream * native_object = (mruby_z_stream*)calloc(1, sizeof(mruby_z_stream));
  native_object->stream.next_out = (char *)calloc(buffer_size, sizeof(char));
  native_object->stream.avail_out = buffer_size;
  native_object->buffer_size = buffer_size;
  native_object->buffer_start = native_object->stream.next_out;
  native_object->type = UNINITIALIZED_STREAM;
  
  mruby_gift_z_stream_data_ptr(self, (z_stream*)native_object);
  return self;
}
#endif
/* MRUBY_BINDING_END */

/*
 * Fields
 */

/* MRUBY_BINDING: ZStream::next_in_reader */
/* sha: 21573781c70e10a71b50fcc5379ec701276738d31eac7d84ce819ef5db95c1a1 */
#if BIND_ZStream_next_in_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_next_in(mrb_state* mrb, mrb_value self) {
  return mrb_iv_get(mrb, self, mrb_intern_cstr(mrb, "@next_in"));
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::next_in_writer */
/* sha: eaef4282936b33b97c1473cf3d32430f78609b59c16fe104135af555ddd5f359 */
#if BIND_ZStream_next_in_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_next_in(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value next_in = mrb_nil_value();

  mrb_get_args(mrb, "S!", &next_in);
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, "@next_in"), next_in);
  
  return next_in;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::avail_in_reader */
/* sha: 6e5e110241904eadfb091bd740d1bd405577b8e2241136e24da3ccd2383797cb */
#if BIND_ZStream_avail_in_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_avail_in(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  uInt native_avail_in = native_self->avail_in;

  mrb_value avail_in = TODO_mruby_box_uInt(mrb, native_avail_in);

  return avail_in;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::avail_in_writer */
/* sha: 7d9854c937fbab6c75342acbf68e6f3864177d2bf82300e4dc0803d9a3530113 */
#if BIND_ZStream_avail_in_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_avail_in(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value avail_in;

  mrb_get_args(mrb, "o", &avail_in);

  /* type checking */
  TODO_type_check_uInt(avail_in);

  uInt native_avail_in = TODO_mruby_unbox_uInt(avail_in);

  native_self->avail_in = native_avail_in;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::total_in_reader */
/* sha: ebdddd50062a73ce6295a0f3b5b2c1b2ade65cdccf3488d7ff0f1b6b648d5d8e */
#if BIND_ZStream_total_in_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_total_in(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  uLong native_total_in = native_self->total_in;

  mrb_value total_in = mrb_fixnum_value(native_total_in);

  return total_in;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::total_in_writer */
/* sha: 752fd5af6a8900b6d5bd58851d5f6997410ed9584c0878c22f5d4330ff044604 */
#if BIND_ZStream_total_in_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_total_in(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_int native_total_in;

  mrb_get_args(mrb, "i", &native_total_in);

  native_self->total_in = native_total_in;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::next_out_reader */
/* sha: 910afa79c808cd67e3c16fd4ed9b4b22d76b8b2dfeb2ff2f2559262409465bb3 */
#if BIND_ZStream_next_out_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_next_out(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  Bytef * native_next_out = native_self->next_out;

  mrb_value next_out = TODO_mruby_box_Bytef_PTR(mrb, native_next_out);

  return next_out;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::next_out_writer */
/* sha: 49f9f57c803967aa4e77e0c2d29c5981fa591d903b60d9ce07d9650d9c513c0c */
#if BIND_ZStream_next_out_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_next_out(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value next_out;

  mrb_get_args(mrb, "o", &next_out);

  /* type checking */
  TODO_type_check_Bytef_PTR(next_out);

  Bytef * native_next_out = TODO_mruby_unbox_Bytef_PTR(next_out);

  native_self->next_out = native_next_out;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::avail_out_reader */
/* sha: d2883dcd8c5c1242e7ae477f7f227a417d9bd23b293f67ac4196bc0c88a65a13 */
#if BIND_ZStream_avail_out_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_avail_out(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  uInt native_avail_out = native_self->avail_out;

  mrb_value avail_out = TODO_mruby_box_uInt(mrb, native_avail_out);

  return avail_out;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::avail_out_writer */
/* sha: 1c87af7e06c33d8495ba41ff1fe4b79993f0f3ecd9b3f35b0ca1b934fc7353d8 */
#if BIND_ZStream_avail_out_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_avail_out(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value avail_out;

  mrb_get_args(mrb, "o", &avail_out);

  /* type checking */
  TODO_type_check_uInt(avail_out);

  uInt native_avail_out = TODO_mruby_unbox_uInt(avail_out);

  native_self->avail_out = native_avail_out;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::total_out_reader */
/* sha: 567ad6565d9afe6fb84ba329e9f773f2c2679d2a151770624cc75a39855b4f0c */
#if BIND_ZStream_total_out_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_total_out(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  uLong native_total_out = native_self->total_out;

  mrb_value total_out = mrb_fixnum_value(native_total_out);

  return total_out;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::total_out_writer */
/* sha: aae59d2f3423a01c05fdf56a6cd1796bded105472af98f14cd3aa5ab1a80a9ea */
#if BIND_ZStream_total_out_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_total_out(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_int native_total_out;

  mrb_get_args(mrb, "i", &native_total_out);

  native_self->total_out = native_total_out;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::msg_reader */
/* sha: 825d6ca3ecc4fd1205ddc3fb1cee2ec744017c8179b1164f9f193fce1d484a24 */
#if BIND_ZStream_msg_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_msg(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  char * native_msg = native_self->msg;

  mrb_value msg = TODO_mruby_box_char_PTR(mrb, native_msg);

  return msg;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::msg_writer */
/* sha: 73dc3f3e191cddba7e270c4daa3572d9b2c0a2d4728b992fd61c42eb606d9a51 */
#if BIND_ZStream_msg_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_msg(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value msg;

  mrb_get_args(mrb, "o", &msg);

  /* type checking */
  TODO_type_check_char_PTR(msg);

  char * native_msg = TODO_mruby_unbox_char_PTR(msg);

  native_self->msg = native_msg;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::state_reader */
/* sha: 275bf04adf925f4ebb4acd42e8e0d5628fa4b25fa8226e5856d9938f1c72f422 */
#if BIND_ZStream_state_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_state(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  struct internal_state * native_state = native_self->state;

  mrb_value state = (native_state == NULL ? mrb_nil_value() : mruby_box_internal_state(mrb, native_state));

  return state;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::state_writer */
/* sha: 0e4253cecbf40dd59ba05b65b52f4910777567caa5f7c209c7ce0c55339ffe54 */
#if BIND_ZStream_state_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_state(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value state;

  mrb_get_args(mrb, "o", &state);

  /* type checking */
  if (!mrb_obj_is_kind_of(mrb, state, InternalState_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "InternalState expected");
    return mrb_nil_value();
  }

  struct internal_state * native_state = (mrb_nil_p(state) ? NULL : mruby_unbox_internal_state(state));

  native_self->state = native_state;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::zalloc_reader */
/* sha: dfb5e9da6e35b49930acc4509d648f5dc552471f484a9307689bbcbc0e52fc8c */
#if BIND_ZStream_zalloc_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_zalloc(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  alloc_func native_zalloc = native_self->zalloc;

  mrb_value zalloc = TODO_mruby_box_alloc_func(mrb, native_zalloc);

  return zalloc;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::zalloc_writer */
/* sha: b9dd1c12688c4c8006bbbdd3fe16d3f74f7c1eb56898a49acf9d52e0196e1072 */
#if BIND_ZStream_zalloc_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_zalloc(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value zalloc;

  mrb_get_args(mrb, "o", &zalloc);

  /* type checking */
  TODO_type_check_alloc_func(zalloc);

  alloc_func native_zalloc = TODO_mruby_unbox_alloc_func(zalloc);

  native_self->zalloc = native_zalloc;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::zfree_reader */
/* sha: d3a65a533e647bc47ab48c1f304c093618e8e992b6a437c01c72c49f8ce4358b */
#if BIND_ZStream_zfree_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_zfree(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  free_func native_zfree = native_self->zfree;

  mrb_value zfree = TODO_mruby_box_free_func(mrb, native_zfree);

  return zfree;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::zfree_writer */
/* sha: 99ea23a21d60081012f1f7aca6201100c376c614b31ff0f2a43246ea4561d0a1 */
#if BIND_ZStream_zfree_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_zfree(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value zfree;

  mrb_get_args(mrb, "o", &zfree);

  /* type checking */
  TODO_type_check_free_func(zfree);

  free_func native_zfree = TODO_mruby_unbox_free_func(zfree);

  native_self->zfree = native_zfree;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::opaque_reader */
/* sha: e8e69657de3307647f91dd4a3f8d6c71ef62017e0841a63b2f88d4d5ad41ef34 */
#if BIND_ZStream_opaque_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_opaque(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  voidpf native_opaque = native_self->opaque;

  mrb_value opaque = TODO_mruby_box_voidpf(mrb, native_opaque);

  return opaque;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::opaque_writer */
/* sha: bdd31c2d0f01c83ca8550bdcccb125f031d1901f3ba26bc79219829fbc14a3a5 */
#if BIND_ZStream_opaque_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_opaque(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_value opaque;

  mrb_get_args(mrb, "o", &opaque);

  /* type checking */
  TODO_type_check_voidpf(opaque);

  voidpf native_opaque = TODO_mruby_unbox_voidpf(opaque);

  native_self->opaque = native_opaque;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::data_type_reader */
/* sha: a36a1a451140c0e7ad624d4ecb59abece475f347e0ab3a24fec5d3f678a482f5 */
#if BIND_ZStream_data_type_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_data_type(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  int native_data_type = native_self->data_type;

  mrb_value data_type = mrb_fixnum_value(native_data_type);

  return data_type;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::data_type_writer */
/* sha: 76e42e495762901e01fbebe6604edc367f52c1b0cacda7b7a904fdc4fb4cae97 */
#if BIND_ZStream_data_type_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_data_type(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_int native_data_type;

  mrb_get_args(mrb, "i", &native_data_type);

  native_self->data_type = native_data_type;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::adler_reader */
/* sha: b726660f0d2a8da57bc51ff2984faffdbb6338325dcef90c1dd3e4a92d79fe49 */
#if BIND_ZStream_adler_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_adler(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  uLong native_adler = native_self->adler;

  mrb_value adler = mrb_fixnum_value(native_adler);

  return adler;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::adler_writer */
/* sha: 40da05ddda8b309aff46ac9a398fff41ac905435cce30b803b316036be89725d */
#if BIND_ZStream_adler_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_adler(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_int native_adler;

  mrb_get_args(mrb, "i", &native_adler);

  native_self->adler = native_adler;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::reserved_reader */
/* sha: e169c8ef854e26c50c8c2c75e321da489ac9ba2041474290becd4b72eff0dfb6 */
#if BIND_ZStream_reserved_FIELD_READER
mrb_value
mrb_ZLib_ZStream_get_reserved(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);

  uLong native_reserved = native_self->reserved;

  mrb_value reserved = mrb_fixnum_value(native_reserved);

  return reserved;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::reserved_writer */
/* sha: 211ff210415a94d11377892a1c75907d906061b8e198eda8ec2bb19837b31009 */
#if BIND_ZStream_reserved_FIELD_WRITER
mrb_value
mrb_ZLib_ZStream_set_reserved(mrb_state* mrb, mrb_value self) {
  z_stream * native_self = mruby_unbox_z_stream(self);
  mrb_int native_reserved;

  mrb_get_args(mrb, "i", &native_reserved);

  native_self->reserved = native_reserved;
  
  mrb_value value_as_mrb_value;
  mrb_get_args(mrb, "o", &value_as_mrb_value);
  return value_as_mrb_value;
}
#endif
/* MRUBY_BINDING_END */


void mrb_ZLib_ZStream_init(mrb_state* mrb) {
  static int initialized = 0;
  if (initialized) return;
  else initialized = 1;

/* MRUBY_BINDING: pre_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::class_definition */
/* sha: e72d49cfc8e1a233892788961c81fecc8c285b717c5ffe29a84d983dc115e946 */
  struct RClass* ZStream_class = mrb_define_class_under(mrb, ZLib_module(mrb), "ZStream", mrb->object_class);
  MRB_SET_INSTANCE_TT(ZStream_class, MRB_TT_DATA);
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::pre_class_method_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::class_method_definitions */
/* sha: 9cb6a2670fc2849041d6a4f4861085733500639f7032a0fe5fdf5f187aa621a9 */
#if BIND_ZStream_INITIALIZE
  mrb_define_method(mrb, ZStream_class, "initialize", mrb_ZLib_ZStream_initialize, MRB_ARGS_ARG(0, 1));
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::pre_attr_definitions */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::attr_definitions */
/* sha: af42de7f411c16afc9373f641a8ce3393d8825136dd23dda562aca0f72fb9beb */
  /*
   * Fields
   */
#if BIND_ZStream_next_in_FIELD_READER
  mrb_define_method(mrb, ZStream_class, "next_in", mrb_ZLib_ZStream_get_next_in, MRB_ARGS_ARG(0, 0));
#endif
#if BIND_ZStream_next_in_FIELD_WRITER
  mrb_define_method(mrb, ZStream_class, "next_in=", mrb_ZLib_ZStream_set_next_in, MRB_ARGS_ARG(1, 0));
#endif
// #if BIND_ZStream_avail_in_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "avail_in", mrb_ZLib_ZStream_get_avail_in, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_avail_in_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "avail_in=", mrb_ZLib_ZStream_set_avail_in, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_total_in_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "total_in", mrb_ZLib_ZStream_get_total_in, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_total_in_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "total_in=", mrb_ZLib_ZStream_set_total_in, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_next_out_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "next_out", mrb_ZLib_ZStream_get_next_out, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_next_out_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "next_out=", mrb_ZLib_ZStream_set_next_out, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_avail_out_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "avail_out", mrb_ZLib_ZStream_get_avail_out, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_avail_out_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "avail_out=", mrb_ZLib_ZStream_set_avail_out, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_total_out_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "total_out", mrb_ZLib_ZStream_get_total_out, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_total_out_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "total_out=", mrb_ZLib_ZStream_set_total_out, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_msg_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "msg", mrb_ZLib_ZStream_get_msg, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_msg_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "msg=", mrb_ZLib_ZStream_set_msg, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_state_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "state", mrb_ZLib_ZStream_get_state, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_state_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "state=", mrb_ZLib_ZStream_set_state, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_zalloc_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "zalloc", mrb_ZLib_ZStream_get_zalloc, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_zalloc_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "zalloc=", mrb_ZLib_ZStream_set_zalloc, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_zfree_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "zfree", mrb_ZLib_ZStream_get_zfree, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_zfree_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "zfree=", mrb_ZLib_ZStream_set_zfree, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_opaque_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "opaque", mrb_ZLib_ZStream_get_opaque, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_opaque_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "opaque=", mrb_ZLib_ZStream_set_opaque, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_data_type_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "data_type", mrb_ZLib_ZStream_get_data_type, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_data_type_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "data_type=", mrb_ZLib_ZStream_set_data_type, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_adler_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "adler", mrb_ZLib_ZStream_get_adler, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_adler_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "adler=", mrb_ZLib_ZStream_set_adler, MRB_ARGS_ARG(1, 0));
// #endif
// #if BIND_ZStream_reserved_FIELD_READER
//   mrb_define_method(mrb, ZStream_class, "reserved", mrb_ZLib_ZStream_get_reserved, MRB_ARGS_ARG(0, 0));
// #endif
// #if BIND_ZStream_reserved_FIELD_WRITER
//   mrb_define_method(mrb, ZStream_class, "reserved=", mrb_ZLib_ZStream_set_reserved, MRB_ARGS_ARG(1, 0));
// #endif
/* MRUBY_BINDING_END */


/* MRUBY_BINDING: ZStream::post_class_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
#endif
