#include "mruby_ZLib.h"

/* MRUBY_BINDING: header */
/* sha: user_defined */
#include <errno.h>
#include <stdio.h>
#include <string.h>

void
raise_zlib_errno(mrb_state * mrb, int err) {
  switch (err) {
  case Z_ERRNO:
    mrb_raise(mrb, ZSystemCallError_class(mrb), strerror(err));
    break;
  case Z_STREAM_ERROR:
    mrb_raise(mrb, ZStreamError_class(mrb), zError(err));
    break;
  case Z_DATA_ERROR:
    mrb_raise(mrb, ZDataError_class(mrb), zError(err));
    break;
  case Z_MEM_ERROR:
    mrb_raise(mrb, ZMemoryError_class(mrb), zError(err));
    break;
  case Z_BUF_ERROR:
    mrb_raise(mrb, ZBufferError_class(mrb), zError(err));
    break;
  case Z_VERSION_ERROR:
    mrb_raise(mrb, ZVersionError_class(mrb), zError(err));
    break;
  default:
    return; /* No problem */
  }
}

#define ASSERT_GZFILE_OPEN(mrb, file) \
  if ( ((mruby_to_native_ref *)DATA_PTR(file))->obj == NULL ) { \
    mrb_raise(mrb, ZIOError_class(mrb), "File not open"); \
    return mrb_nil_value(); \
  }

/* MRUBY_BINDING_END */

#ifdef __cplusplus
extern "C" {
#endif

/* MRUBY_BINDING: adler32 */
/* sha: 57d5b9025c06fb023e31ad7a3c9dc027d7f0520842501c25c8af9667964c23fc */
#if BIND_adler32_FUNCTION
#define adler32_REQUIRED_ARGC 3
#define adler32_OPTIONAL_ARGC 0
/* uLong adler32(uLong adler, const Bytef * buf, uInt len) */
mrb_value
mrb_ZLib_adler32(mrb_state* mrb, mrb_value self) {
  mrb_int native_adler;
  Bytef * native_buf = NULL;
  mrb_int len = 0;

  /* Fetch the args */
  mrb_get_args(mrb, "is", &native_adler, &native_buf, &len);

  /* Invocation */
  uLong native_return_value = adler32(native_adler, native_buf, len);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: adler32_combine */
/* sha: e8fd224c35ab1d66861a74f058cf521cad3d7afe6b611be8b082e64f108bb72d */
#if BIND_adler32_combine_FUNCTION
#define adler32_combine_REQUIRED_ARGC 3
#define adler32_combine_OPTIONAL_ARGC 0
/* uLong adler32_combine(uLong arg1, uLong arg2, long arg3) */
mrb_value
mrb_ZLib_adler32_combine(mrb_state* mrb, mrb_value self) {
  mrb_int native_arg1;
  mrb_int native_arg2;
  mrb_int native_arg3;

  /* Fetch the args */
  mrb_get_args(mrb, "iii", &native_arg1, &native_arg2, &native_arg3);

  /* Invocation */
  uLong native_return_value = adler32_combine(native_arg1, native_arg2, native_arg3);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: compress */
/* sha: 2009607471190fda39f22cf718d92bd532099f019dc2654dcb8774df64c82309 */
#if BIND_compress_FUNCTION
#define compress_REQUIRED_ARGC 1
#define compress_OPTIONAL_ARGC 0
/* int compress(Bytef * dest, uLongf * destLen, const Bytef * source, uLong sourceLen) */
mrb_value
mrb_ZLib_compress(mrb_state* mrb, mrb_value self) {
  char * native_source = NULL;
  mrb_int native_sourceLen;

  /* Fetch the args */
  mrb_get_args(mrb, "s", &native_source, &native_sourceLen);

  /* Invocation */
  uLongf native_destLen = compressBound(native_sourceLen);
  Bytef * native_dest = (Bytef*)calloc(native_destLen, sizeof(Bytef));
  int native_return_value = compress(native_dest, &native_destLen, (Bytef *)native_source, native_sourceLen);

  mrb_value result = mrb_nil_value();
  if (native_return_value == Z_OK) {
    result = mrb_str_new(mrb, (char *)native_dest, native_destLen);
  }
  
  free(native_dest);
  
  raise_zlib_errno(mrb, native_return_value);
  
  return result;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: compress2 */
/* sha: c7b3f38eed72594a922980c191dc4e3165214d2072296e2e033a11a24812c7ee */
#if BIND_compress2_FUNCTION
#define compress2_REQUIRED_ARGC 2
#define compress2_OPTIONAL_ARGC 0
/* int compress2(Bytef * dest, uLongf * destLen, const Bytef * source, uLong sourceLen, int level) */
mrb_value
mrb_ZLib_compress2(mrb_state* mrb, mrb_value self) {
  char * native_source = NULL;
  mrb_int native_sourceLen = 0;
  mrb_int native_level = 0;

  /* Fetch the args */
  mrb_get_args(mrb, "si", &native_source, &native_sourceLen, &native_level);

  uLongf native_destLen = compressBound(native_sourceLen);
  Bytef * native_dest = (Bytef*)calloc(native_destLen, sizeof(Bytef));
  int native_return_value = compress2(native_dest, &native_destLen, (Bytef *)native_source, native_sourceLen, native_level);

  mrb_value result = mrb_nil_value();
  if (native_return_value == Z_OK) {
    result = mrb_str_new(mrb, (char*)native_dest, native_destLen);
  }

  free(native_dest);

  raise_zlib_errno(mrb, native_return_value);

  return result;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: compressBound */
/* sha: 5a04f559bda8bc3c17fb998403b416058111ae292064495fdf997d4517612064 */
#if BIND_compressBound_FUNCTION
#define compressBound_REQUIRED_ARGC 1
#define compressBound_OPTIONAL_ARGC 0
/* uLong compressBound(uLong sourceLen) */
mrb_value
mrb_ZLib_compressBound(mrb_state* mrb, mrb_value self) {
  mrb_int native_sourceLen;

  /* Fetch the args */
  mrb_get_args(mrb, "i", &native_sourceLen);

  /* Invocation */
  uLong native_return_value = compressBound(native_sourceLen);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: crc32 */
/* sha: ba7ef624b1a80f8e251b9daea5e400e0d392edc655253d9ad6cf402232b55894 */
#if BIND_crc32_FUNCTION
#define crc32_REQUIRED_ARGC 3
#define crc32_OPTIONAL_ARGC 0
/* uLong crc32(uLong crc, const Bytef * buf, uInt len) */
mrb_value
mrb_ZLib_crc32(mrb_state* mrb, mrb_value self) {
  mrb_int native_crc;
  Bytef * native_buf = NULL;
  mrb_int len = 0;

  /* Fetch the args */
  mrb_get_args(mrb, "is", &native_crc, &native_buf, &len);

  /* Invocation */
  uLong native_return_value = crc32(native_crc, native_buf, len);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: crc32_combine */
/* sha: 81ab4067b714cba68af0814c1a206f83185dc569f6e0876df43f5cea07c93015 */
#if BIND_crc32_combine_FUNCTION
#define crc32_combine_REQUIRED_ARGC 3
#define crc32_combine_OPTIONAL_ARGC 0
/* uLong crc32_combine(uLong arg1, uLong arg2, long arg3) */
mrb_value
mrb_ZLib_crc32_combine(mrb_state* mrb, mrb_value self) {
  mrb_int native_arg1;
  mrb_int native_arg2;
  mrb_int native_arg3;

  /* Fetch the args */
  mrb_get_args(mrb, "iii", &native_arg1, &native_arg2, &native_arg3);

  /* Invocation */
  uLong native_return_value = crc32_combine(native_arg1, native_arg2, native_arg3);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflate */
/* sha: 32f8e74147ddee779d138f1cc444b650884ff21d54d4a72ac9f2524a093169e6 */
#if BIND_deflate_FUNCTION
#define deflate_REQUIRED_ARGC 1
#define deflate_OPTIONAL_ARGC 1
/* int deflate(z_stream * strm, int flush) */
mrb_value
mrb_ZLib_deflate(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_flush = Z_NO_FLUSH;

  /* Fetch the args */
  mrb_get_args(mrb, "o|i", &strm, &native_flush);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  
  /** Get buffer size */
  mrb_int buffer_size = ((mruby_z_stream*)native_strm)->buffer_size;
  
  /** Setup next_in */
  mrb_value next_in = mrb_iv_get(mrb, strm, mrb_intern_cstr(mrb, "@next_in"));
  
  /*** We're going to pump through the entire input, so go ahead and set next_in to nil */
  mrb_iv_set(mrb, strm, mrb_intern_cstr(mrb, "@next_in"), mrb_nil_value());
  
  if (mrb_nil_p(next_in)) {
    native_strm->next_in = NULL;
    native_strm->avail_in = 0;
  } else {
    mrb_value next_in_as_str = mrb_str_to_str(mrb, next_in);
    native_strm->next_in = (Bytef *)RSTRING_PTR(next_in_as_str);
    native_strm->avail_in = RSTRING_LEN(next_in_as_str);
  }
    
  /** Run until no more output is generated */
  mrb_value result = mrb_str_new(mrb, "", 0);
  int ready_out = buffer_size - native_strm->avail_out;
  do {
    /* Grab any pending output from previous iteration & reset output buffer */
    char * buffer_start = ((mruby_z_stream *)native_strm)->buffer_start;
    if (ready_out > 0) {
      mrb_str_cat(mrb, result, buffer_start, ready_out);
    }
    native_strm->next_out = (Byte *)buffer_start;
    native_strm->avail_out = buffer_size;
    
    /* Normally (when not flushing) we only invoke if there is input available.
       This prevents Z_BUF_ERROR from lack of input data.
       
       When flushing, invoke every time. The loop will exit
       when no new output is generated.
     */
    int result = Z_OK;
    if (native_strm->avail_in > 0 || native_flush != Z_NO_FLUSH) {
      result = deflate(native_strm, native_flush);
    }
    if (result != Z_OK) {
      raise_zlib_errno(mrb, result);
    }
    ready_out = buffer_size - native_strm->avail_out;
  } while (ready_out > 0 || native_strm->avail_in > 0);
  
  return result;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateBound */
/* sha: 5793d69e59ce63f222db00e2a07b7d19d2c1c370d3f126c25a08a886fb54f65f */
#if BIND_deflateBound_FUNCTION
#define deflateBound_REQUIRED_ARGC 2
#define deflateBound_OPTIONAL_ARGC 0
/* uLong deflateBound(z_stream * strm, uLong sourceLen) */
mrb_value
mrb_ZLib_deflateBound(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_sourceLen;

  /* Fetch the args */
  mrb_get_args(mrb, "oi", &strm, &native_sourceLen);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  uLong native_return_value = deflateBound(native_strm, native_sourceLen);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateCopy */
/* sha: c4ee3d981ad1d42301d943c2ac3cfa348afd40ef887d8ecf2921ed6d1452bb46 */
#if BIND_deflateCopy_FUNCTION
#define deflateCopy_REQUIRED_ARGC 2
#define deflateCopy_OPTIONAL_ARGC 0
/* int deflateCopy(z_stream * dest, z_stream * source) */
mrb_value
mrb_ZLib_deflateCopy(mrb_state* mrb, mrb_value self) {
  mrb_value dest;
  mrb_value source;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dest, &source);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dest, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, source, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: dest */
  z_stream * native_dest = (mrb_nil_p(dest) ? NULL : mruby_unbox_z_stream(dest));

  /* Unbox param: source */
  z_stream * native_source = (mrb_nil_p(source) ? NULL : mruby_unbox_z_stream(source));

  /* Invocation */
  int native_return_value = deflateCopy(native_dest, native_source);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateEnd */
/* sha: 358175875c93bc323663dde9526fc48419d22502c5a1cd325a4a4c6aaa6a53d0 */
#if BIND_deflateEnd_FUNCTION
#define deflateEnd_REQUIRED_ARGC 1
#define deflateEnd_OPTIONAL_ARGC 0
/* int deflateEnd(z_stream * strm) */
mrb_value
mrb_ZLib_deflateEnd(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  int native_return_value = Z_STREAM_ERROR; /* In case of wrong stream type */
  if (((mruby_z_stream*)native_strm)->type == DEFLATE_STREAM) {
     native_return_value = deflateEnd(native_strm);
     ((mruby_z_stream*)native_strm)->type = UNINITIALIZED_STREAM;
  }
  
  raise_zlib_errno(mrb, native_return_value);
  
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateInit */
/* sha: 9e07f0ba7ca24df99e3da37423fcd482bae5f5ca6c653d81b2a400e0d0ccb962 */
#if BIND_deflateInit_FUNCTION
#define deflateInit_REQUIRED_ARGC 1
#define deflateInit_OPTIONAL_ARGC 1
/* int deflateInit(z_stream * strm, int level) */
mrb_value
mrb_ZLib_deflateInit(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_level = Z_DEFAULT_COMPRESSION;

  /* Fetch the args */
  mrb_get_args(mrb, "o|i", &strm, &native_level);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));
  if (((mruby_z_stream *)native_strm)->type != UNINITIALIZED_STREAM) {
    mrb_raise(mrb, ZStreamError_class(mrb), "Stream already initialized");
    return mrb_nil_value();
  } else {
    ((mruby_z_stream *)native_strm)->type = DEFLATE_STREAM;
  }
  
  /* Invocation */
  int native_return_value = deflateInit(native_strm, native_level);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateInit2 */
/* sha: 154d9fcd7619e9d4ee1e48f024239d6f586df289eed6135556970b74c9650478 */
#if BIND_deflateInit2_FUNCTION
#define deflateInit2_REQUIRED_ARGC 6
#define deflateInit2_OPTIONAL_ARGC 0
/* int deflateInit2(z_stream * strm, int level, int method, int windowBits, int memLevel, int strategy) */
mrb_value
mrb_ZLib_deflateInit2(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_level;
  mrb_int native_method;
  mrb_int native_windowBits;
  mrb_int native_memLevel;
  mrb_int native_strategy;

  /* Fetch the args */
  mrb_get_args(mrb, "oiiiii", &strm, &native_level, &native_method, &native_windowBits, &native_memLevel, &native_strategy);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));
  if (((mruby_z_stream *)native_strm)->type != UNINITIALIZED_STREAM) {
    mrb_raise(mrb, ZStreamError_class(mrb), "Stream already initialized");
    return mrb_nil_value();
  } else {
    ((mruby_z_stream *)native_strm)->type = DEFLATE_STREAM;
  }
  
  /* Invocation */
  int native_return_value = deflateInit2(native_strm, native_level, native_method, native_windowBits, native_memLevel, native_strategy);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateParams */
/* sha: 8e9806961cb34bf7fea73a649d85144d3ed445e5a1e100a7df2e7d37e4d3cbe0 */
#if BIND_deflateParams_FUNCTION
#define deflateParams_REQUIRED_ARGC 3
#define deflateParams_OPTIONAL_ARGC 0
/* int deflateParams(z_stream * strm, int level, int strategy) */
mrb_value
mrb_ZLib_deflateParams(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_level;
  mrb_int native_strategy;

  /* Fetch the args */
  mrb_get_args(mrb, "oii", &strm, &native_level, &native_strategy);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = deflateParams(native_strm, native_level, native_strategy);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflatePending */
/* sha: e1f2c4c51562b01390d49a170c8e21d6021c3257b35189056fb76314e818c433 */
// TODO: This isn't defined in the headers I'm building against.
#if BIND_deflatePending_FUNCTION
#define deflatePending_REQUIRED_ARGC 1
#define deflatePending_OPTIONAL_ARGC 0
/* int deflatePending(z_stream * strm, unsigned int * pending, int * bits) */
mrb_value
mrb_ZLib_deflatePending(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_pending = 0;
  int native_bits = 0;
  int native_return_value = deflatePending(native_strm, &native_pending, &native_bits);

  if (native_return_value == Z_OK) {
    mrb_value result = mrb_ary_new(mrb);
    mrb_ary_push(mrb, result, mrb_fixnum_value(native_pending));
    mrb_ary_push(mrb, result, mrb_fixnum_value(native_bits));
    return result;
  } else {
    mrb_raise(mrb, ZError_class(mrb), zError(native_return_value));
    return mrb_nil_value();
  }
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflatePrime */
/* sha: 6c710244b04eb04b0d7a9930cb1a68f134c7168ffff0eb3a3887336bcf708c5c */
#if BIND_deflatePrime_FUNCTION
#define deflatePrime_REQUIRED_ARGC 3
#define deflatePrime_OPTIONAL_ARGC 0
/* int deflatePrime(z_stream * strm, int bits, int value) */
mrb_value
mrb_ZLib_deflatePrime(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_bits;
  mrb_int native_value;

  /* Fetch the args */
  mrb_get_args(mrb, "oii", &strm, &native_bits, &native_value);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = deflatePrime(native_strm, native_bits, native_value);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateReset */
/* sha: 04f365e4534b114c1e214a6b87c855ba12fa260cc862133a0f3611c856bce936 */
#if BIND_deflateReset_FUNCTION
#define deflateReset_REQUIRED_ARGC 1
#define deflateReset_OPTIONAL_ARGC 0
/* int deflateReset(z_stream * strm) */
mrb_value
mrb_ZLib_deflateReset(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = deflateReset(native_strm);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateResetKeep */
/* sha: 91ef42fc442f5e336c475e3646333f60c4d1e207ba4ec94d1e1e2e58f9ed8b49 */
#if BIND_deflateResetKeep_FUNCTION
#define deflateResetKeep_REQUIRED_ARGC 1
#define deflateResetKeep_OPTIONAL_ARGC 0
/* int deflateResetKeep(z_stream * arg1) */
mrb_value
mrb_ZLib_deflateResetKeep(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arg1, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: arg1 */
  z_stream * native_arg1 = (mrb_nil_p(arg1) ? NULL : mruby_unbox_z_stream(arg1));

  /* Invocation */
  int native_return_value = deflateResetKeep(native_arg1);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateSetDictionary */
/* sha: 8009d61607b6697d09f65922725c38268696bc5840c0f376160ad1fa0cd1dc15 */
#if BIND_deflateSetDictionary_FUNCTION
#define deflateSetDictionary_REQUIRED_ARGC 3
#define deflateSetDictionary_OPTIONAL_ARGC 0
/* int deflateSetDictionary(z_stream * strm, const Bytef * dictionary, uInt dictLength) */
mrb_value
mrb_ZLib_deflateSetDictionary(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  char * native_dictionary = NULL;
  mrb_value dictLength;

  /* Fetch the args */
  mrb_get_args(mrb, "ozo", &strm, &native_dictionary, &dictLength);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }
  TODO_type_check_uInt(dictLength);

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Unbox param: dictLength */
  uInt native_dictLength = TODO_mruby_unbox_uInt(dictLength);

  /* Invocation */
  int native_return_value = deflateSetDictionary(native_strm, native_dictionary, native_dictLength);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateSetHeader */
/* sha: 2481795f5f669acfa70d7be2e501fdc9d6231e4f67d5ca69ecc155dbbf86a4a9 */
#if BIND_deflateSetHeader_FUNCTION
#define deflateSetHeader_REQUIRED_ARGC 2
#define deflateSetHeader_OPTIONAL_ARGC 0
/* int deflateSetHeader(z_stream * strm, gz_header * head) */
mrb_value
mrb_ZLib_deflateSetHeader(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_value head;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &strm, &head);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, head, GZHeader_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZHeader expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Unbox param: head */
  gz_header * native_head = (mrb_nil_p(head) ? NULL : mruby_unbox_gz_header(head));

  /* Invocation */
  int native_return_value = deflateSetHeader(native_strm, native_head);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: deflateTune */
/* sha: ea201a3c04f5d16e91114409694634a09cc0ae7c7897913b72ed0f78ed4736ba */
#if BIND_deflateTune_FUNCTION
#define deflateTune_REQUIRED_ARGC 5
#define deflateTune_OPTIONAL_ARGC 0
/* int deflateTune(z_stream * strm, int good_length, int max_lazy, int nice_length, int max_chain) */
mrb_value
mrb_ZLib_deflateTune(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_good_length;
  mrb_int native_max_lazy;
  mrb_int native_nice_length;
  mrb_int native_max_chain;

  /* Fetch the args */
  mrb_get_args(mrb, "oiiii", &strm, &native_good_length, &native_max_lazy, &native_nice_length, &native_max_chain);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = deflateTune(native_strm, native_good_length, native_max_lazy, native_nice_length, native_max_chain);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: get_crc_table */
/* sha: 03f663ad95f78d178106b6aea2fc767b89469276c43e90022f8c6edf27dbc823 */
#if BIND_get_crc_table_FUNCTION
#define get_crc_table_REQUIRED_ARGC 0
#define get_crc_table_OPTIONAL_ARGC 0
/* const int * get_crc_table() */
mrb_value
mrb_ZLib_get_crc_table(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  const int * native_return_value = get_crc_table();

  /* Box the return value */
  mrb_value return_value = TODO_mruby_box_int_PTR(mrb, native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzbuffer */
/* sha: 5d3e928b85962b61b06540a67a64ad0bb620a12ed48cda4a4940085a254d16b7 */
#if BIND_gzbuffer_FUNCTION
#define gzbuffer_REQUIRED_ARGC 2
#define gzbuffer_OPTIONAL_ARGC 0
/* int gzbuffer(gzFile file, unsigned int size) */
mrb_value
mrb_ZLib_gzbuffer(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_int native_size;

  /* Fetch the args */
  mrb_get_args(mrb, "oi", &file, &native_size);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzbuffer(native_file, native_size);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzclearerr */
/* sha: ba3ab07765c6a5b174240a0eb00d797d3889b0d1ba025c29401f9cba387243df */
#if BIND_gzclearerr_FUNCTION
#define gzclearerr_REQUIRED_ARGC 1
#define gzclearerr_OPTIONAL_ARGC 0
/* void gzclearerr(gzFile file) */
mrb_value
mrb_ZLib_gzclearerr(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  gzclearerr(native_file);

  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzclose */
/* sha: 58a3f9cbbedaa2dfca201e5d228a6ef472751accfab8091b28efd1341a6e8808 */
#if BIND_gzclose_FUNCTION
#define gzclose_REQUIRED_ARGC 1
#define gzclose_OPTIONAL_ARGC 0
/* int gzclose(gzFile file) */
mrb_value
mrb_ZLib_gzclose(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzclose(native_file);
  ((mruby_to_native_ref *)DATA_PTR(file))->obj = NULL;

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzdirect */
/* sha: 14efac1da8db79cc819dfdc33cb0e14cc15a0434d43874f4b6d340e94bb27555 */
#if BIND_gzdirect_FUNCTION
#define gzdirect_REQUIRED_ARGC 1
#define gzdirect_OPTIONAL_ARGC 0
/* int gzdirect(gzFile file) */
mrb_value
mrb_ZLib_gzdirect(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzdirect(native_file);

  return native_return_value == 1 ? mrb_true_value() : mrb_false_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzdopen */
/* sha: b206512e75eb4279aac62a9329e4a252cd29145c6338eb42a34eca142cf0daa6 */
#if BIND_gzdopen_FUNCTION
#define gzdopen_REQUIRED_ARGC 2
#define gzdopen_OPTIONAL_ARGC 0
/* gzFile gzdopen(int fd, const char * mode) */
mrb_value
mrb_ZLib_gzdopen(mrb_state* mrb, mrb_value self) {
  mrb_int native_fd;
  char * native_mode = NULL;

  /* Fetch the args */
  mrb_get_args(mrb, "iz", &native_fd, &native_mode);

  /* Invocation */
  gzFile native_return_value = gzdopen(native_fd, native_mode);

  /* Box the return value */
  mrb_value return_value = (native_return_value == NULL ? mrb_nil_value() : mruby_box_gzFile(mrb, native_return_value));
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzeof */
/* sha: 242aa8eadb58a427219b35ffc0e8f7f381539e066c27dfc45006fcb8227f3004 */
#if BIND_gzeof_FUNCTION
#define gzeof_REQUIRED_ARGC 1
#define gzeof_OPTIONAL_ARGC 0
/* int gzeof(gzFile file) */
mrb_value
mrb_ZLib_gzeof(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzeof(native_file);

  /* Box the return value */
  return native_return_value == 1 ? mrb_true_value() : mrb_false_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzerror */
/* sha: 343f4032cbbccc9a51a691cb8bbb17d8c477a1d30d613c12ae644248904d682e */
#if BIND_gzerror_FUNCTION
#define gzerror_REQUIRED_ARGC 2
#define gzerror_OPTIONAL_ARGC 0
/* const char * gzerror(gzFile file, int * errnum) */
mrb_value
mrb_ZLib_gzerror(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int err = 0;
  const char * native_return_value = gzerror(native_file, &err);

  return mrb_str_new_cstr(mrb, native_return_value);
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzflush */
/* sha: 25bf7da855935ef0db846420fdce02a1176e070fcb5d3a455d8b44dce0a1bd8f */
#if BIND_gzflush_FUNCTION
#define gzflush_REQUIRED_ARGC 2
#define gzflush_OPTIONAL_ARGC 0
/* int gzflush(gzFile file, int flush) */
mrb_value
mrb_ZLib_gzflush(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_int native_flush;

  /* Fetch the args */
  mrb_get_args(mrb, "oi", &file, &native_flush);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzflush(native_file, native_flush);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzgetc */
/* sha: 3d208ff018783e25ebe9ad08e9c355f27d7b479d60acfa5c914e0e20f5c7f8c4 */
#if BIND_gzgetc_FUNCTION
#define gzgetc_REQUIRED_ARGC 1
#define gzgetc_OPTIONAL_ARGC 0
/* int gzgetc(gzFile file) */
mrb_value
mrb_ZLib_gzgetc(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzgetc(native_file);
  if (native_return_value == -1) {
    int err = 0;
    gzerror(native_file, &err);
    raise_zlib_errno(mrb, err);
  }

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzgets */
/* sha: 7c923d80ff6cf31a97480f9f1ba469bd1d435dab94830f627735a0c06bacbfbd */
#if BIND_gzgets_FUNCTION
#define gzgets_REQUIRED_ARGC 1
#define gzgets_OPTIONAL_ARGC 1
/* char * gzgets(gzFile file, char * buf, int len) */
mrb_value
mrb_ZLib_gzgets(mrb_state* mrb, mrb_value self) {
  mrb_value file = mrb_nil_value();
  mrb_int native_len = 1024;

  /* Fetch the args */
  mrb_get_args(mrb, "o|i", &file, &native_len);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Unbox param: buf */
  char * native_buf = (char *)calloc(native_len, sizeof(char));

  /* Invocation */
  char * native_return_value = gzgets(native_file, native_buf, native_len);

  mrb_value result = mrb_nil_value();
  if (native_return_value != NULL) {
    result = mrb_str_new_cstr(mrb, native_return_value);
  }
  
  free(native_buf);
  
  if (native_return_value == NULL && !gzeof(native_file)) {
    int err = 0;
    gzerror(native_file, &err);
    raise_zlib_errno(mrb, err);
  }

  return result;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzoffset */
/* sha: 4427224f010553d21df9e4dfa16905c8f429a5ff6e546febff5394e1440aef5f */
#if BIND_gzoffset_FUNCTION
#define gzoffset_REQUIRED_ARGC 1
#define gzoffset_OPTIONAL_ARGC 0
/* long gzoffset(gzFile file) */
mrb_value
mrb_ZLib_gzoffset(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  long native_return_value = gzoffset(native_file);
  if (native_return_value == -1) {
    int err = 0;
    gzerror(native_file, &err);
    raise_zlib_errno(mrb, err);
  }
  
  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzopen */
/* sha: 51037ae0566520f71b11449343e1489b3f119f4071d8b1e25f86f844a883249e */
#if BIND_gzopen_FUNCTION
#define gzopen_REQUIRED_ARGC 2
#define gzopen_OPTIONAL_ARGC 0
/* gzFile gzopen(const char * path, const char * mode) */
mrb_value
mrb_ZLib_gzopen(mrb_state* mrb, mrb_value self) {
  char * native_path = NULL;
  char * native_mode = NULL;

  /* Fetch the args */
  mrb_get_args(mrb, "zz", &native_path, &native_mode);

  /* Invocation */
  gzFile native_return_value = gzopen(native_path, native_mode);

  /* Box the return value */
  mrb_value return_value = (native_return_value == NULL ? mrb_nil_value() : mruby_giftwrap_gzFile(mrb, native_return_value));
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzputc */
/* sha: f88f7cc76bd5819d20dbbc340b17665ccda0872f95e104cdad75dcb3e6967eff */
#if BIND_gzputc_FUNCTION
#define gzputc_REQUIRED_ARGC 2
#define gzputc_OPTIONAL_ARGC 0
/* int gzputc(gzFile file, int c) */
mrb_value
mrb_ZLib_gzputc(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_int native_c;

  /* Fetch the args */
  mrb_get_args(mrb, "oi", &file, &native_c);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzputc(native_file, native_c);
  if (native_return_value == -1) {
    int err = 0;
    gzerror(native_file, &err);
    raise_zlib_errno(mrb, err);
  }

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzputs */
/* sha: 2cb7f3c93b1535c110fb76372ef3cc4627cc73a6851d71282b92b005fbcbeb6d */
#if BIND_gzputs_FUNCTION
#define gzputs_REQUIRED_ARGC 2
#define gzputs_OPTIONAL_ARGC 0
/* int gzputs(gzFile file, const char * s) */
mrb_value
mrb_ZLib_gzputs(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  char * native_s = NULL;

  /* Fetch the args */
  mrb_get_args(mrb, "oz", &file, &native_s);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzputs(native_file, native_s);
  if (native_return_value == -1) {
    int err = 0;
    gzerror(native_file, &err);
    raise_zlib_errno(mrb, err);
  }

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzread */
/* sha: eb817f672d862c192a1ecbfdb928195fdc0821b05ab76a648fd449825310ac01 */
#if BIND_gzread_FUNCTION
#define gzread_REQUIRED_ARGC 2
#define gzread_OPTIONAL_ARGC 0
/* int gzread(gzFile file, voidp buf, unsigned int len) */
mrb_value
mrb_ZLib_gzread(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_int native_len;

  /* Fetch the args */
  mrb_get_args(mrb, "oi", &file, &native_len);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Unbox param: buf */
  voidp native_buf = (char*)calloc(native_len, sizeof(char));

  /* Invocation */
  int native_return_value = gzread(native_file, native_buf, native_len);

  /* Box the return value */
  mrb_value result = mrb_nil_value();
  if (native_return_value >= 0) {
    result = mrb_str_new(mrb, native_buf, native_return_value);
  } else {
    int err = 0;
    gzerror(native_file, &err);
    if (err == Z_OK) {
      /* Not actually an error, just the end of one gzip stream
       * Signifty this to the caller by returning nil instead of the empty string.
       * (XXX: Something less subtle would be preferable)
       */
      gzclearerr(native_file);
      result = mrb_nil_value(); /* redundant but explicit */
    }
  }
  
  free(native_buf);
  
  raise_zlib_errno(mrb, native_return_value);
  return result;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzrewind */
/* sha: df6ec2f40ef4c017db8b1e1a3f27c4bd2c2732a8dfde6449293746520d296dd0 */
#if BIND_gzrewind_FUNCTION
#define gzrewind_REQUIRED_ARGC 1
#define gzrewind_OPTIONAL_ARGC 0
/* int gzrewind(gzFile file) */
mrb_value
mrb_ZLib_gzrewind(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzrewind(native_file);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzseek */
/* sha: 57902a060c21416bbce553c59d4310eb60dcdcd9518e56a7a28f153ab90a8d5e */
#if BIND_gzseek_FUNCTION
#define gzseek_REQUIRED_ARGC 3
#define gzseek_OPTIONAL_ARGC 0
/* long gzseek(gzFile file, long offset, int whence) */
mrb_value
mrb_ZLib_gzseek(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_int native_offset;
  mrb_int native_whence;

  /* Fetch the args */
  mrb_get_args(mrb, "oii", &file, &native_offset, &native_whence);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  long native_return_value = gzseek(native_file, native_offset, native_whence);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzsetparams */
/* sha: 4a3700b85bfc00441baab77169a41dfe835b0830bb5c4f0c9296d715011292ec */
#if BIND_gzsetparams_FUNCTION
#define gzsetparams_REQUIRED_ARGC 3
#define gzsetparams_OPTIONAL_ARGC 0
/* int gzsetparams(gzFile file, int level, int strategy) */
mrb_value
mrb_ZLib_gzsetparams(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  mrb_int native_level;
  mrb_int native_strategy;

  /* Fetch the args */
  mrb_get_args(mrb, "oii", &file, &native_level, &native_strategy);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzsetparams(native_file, native_level, native_strategy);
  if (native_return_value == Z_OK) {
    raise_zlib_errno(mrb, native_return_value);
  }

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gztell */
/* sha: d8000728fec4986c0d2c29ac5622b47133287f60057a412438b520e400b6c41b */
#if BIND_gztell_FUNCTION
#define gztell_REQUIRED_ARGC 1
#define gztell_OPTIONAL_ARGC 0
/* long gztell(gzFile file) */
mrb_value
mrb_ZLib_gztell(mrb_state* mrb, mrb_value self) {
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  long native_return_value = gztell(native_file);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzungetc */
/* sha: 870d13894de82f058d2a58c40fb6b1d9c615ab4071ff3b16b12cdb46a87a981a */
#if BIND_gzungetc_FUNCTION
#define gzungetc_REQUIRED_ARGC 2
#define gzungetc_OPTIONAL_ARGC 0
/* int gzungetc(int c, gzFile file) */
mrb_value
mrb_ZLib_gzungetc(mrb_state* mrb, mrb_value self) {
  mrb_int native_c;
  mrb_value file;

  /* Fetch the args */
  mrb_get_args(mrb, "io", &native_c, &file);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzungetc(native_c, native_file);
  if (native_return_value == -1) {
    int err = 0;
    gzerror(native_file, &err);
    raise_zlib_errno(mrb, err);
  }

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: gzwrite */
/* sha: 0ae199c978ab4c99466492126bbddb4a412f5b735d34d9c044bd0a8b28d85dd5 */
#if BIND_gzwrite_FUNCTION
#define gzwrite_REQUIRED_ARGC 2
#define gzwrite_OPTIONAL_ARGC 0
/* int gzwrite(gzFile file, voidpc buf, unsigned int len) */
mrb_value
mrb_ZLib_gzwrite(mrb_state* mrb, mrb_value self) {
  mrb_value file;
  char * native_buf = NULL;
  mrb_int native_len = 0;

  /* Fetch the args */
  mrb_get_args(mrb, "os", &file, &native_buf, &native_len);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, file, GZFile_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZFile expected");
    return mrb_nil_value();
  }
  ASSERT_GZFILE_OPEN(mrb, file);

  /* Unbox param: file */
  gzFile native_file = (mrb_nil_p(file) ? NULL : mruby_unbox_gzFile(file));

  /* Invocation */
  int native_return_value = gzwrite(native_file, native_buf, native_len);
  if (native_return_value != 0) {
    int err = 0;
    gzerror(native_file, &err);
    raise_zlib_errno(mrb, err);
  }

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflate */
/* sha: 269d493f05417aba19927bcf7eeb98f2b3f75702906ecb44823c0ed9482f1e48 */
#if BIND_inflate_FUNCTION
#define inflate_REQUIRED_ARGC 2
#define inflate_OPTIONAL_ARGC 0
/* int inflate(z_stream * strm, int flush) */
mrb_value
mrb_ZLib_inflate(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_flush = Z_NO_FLUSH;

  /* Fetch the args */
  mrb_get_args(mrb, "o|i", &strm, &native_flush);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  
  /** Get buffer size */
  mrb_int buffer_size = ((mruby_z_stream*)native_strm)->buffer_size;
  
  /** Setup next_in */
  mrb_value next_in = mrb_iv_get(mrb, strm, mrb_intern_cstr(mrb, "@next_in"));
  
  /*** We're going to pump through the entire input, so go ahead and set next_in to nil */
  mrb_iv_set(mrb, strm, mrb_intern_cstr(mrb, "@next_in"), mrb_nil_value());
  
  if (mrb_nil_p(next_in)) {
    native_strm->next_in = NULL;
    native_strm->avail_in = 0;
  } else {
    mrb_value next_in_as_str = mrb_str_to_str(mrb, next_in);
    native_strm->next_in = (Bytef *)RSTRING_PTR(next_in_as_str);
    native_strm->avail_in = RSTRING_LEN(next_in_as_str);
  }
    
  /** Run until no more output is generated */
  mrb_value result = mrb_str_new(mrb, "", 0);
  int ready_out = buffer_size - native_strm->avail_out;
  do {
    /* Grab any pending output from previous iteration & reset output buffer */
    char * buffer_start = ((mruby_z_stream *)native_strm)->buffer_start;
    if (ready_out > 0) {
      mrb_str_cat(mrb, result, buffer_start, ready_out);
    }
    native_strm->next_out = (Byte *)buffer_start;
    native_strm->avail_out = buffer_size;
    
    /* Normally (when not flushing) we only invoke if there is input available.
       This prevents Z_BUF_ERROR from lack of input data.
       
       When flushing, invoke every time. The loop will exit
       when no new output is generated.
     */
    int result = Z_OK;
    if (native_strm->avail_in > 0 || native_flush != Z_NO_FLUSH) {
      result = inflate(native_strm, native_flush);
    }
    if (result != Z_OK) {
      raise_zlib_errno(mrb, result);
    }
    ready_out = buffer_size - native_strm->avail_out;
  } while (ready_out > 0 || native_strm->avail_in > 0);

  return result;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateBack */
/* sha: d51d76bad433b973b9953105546f44a2c0fc3b388c9e9c020c780961c0ae53d0 */
#if BIND_inflateBack_FUNCTION
#define inflateBack_REQUIRED_ARGC 5
#define inflateBack_OPTIONAL_ARGC 0
/* int inflateBack(z_stream * strm, in_func in, void * in_desc, out_func out, void * out_desc) */
mrb_value
mrb_ZLib_inflateBack(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_value in;
  mrb_value in_desc;
  mrb_value out;
  mrb_value out_desc;

  /* Fetch the args */
  mrb_get_args(mrb, "ooooo", &strm, &in, &in_desc, &out, &out_desc);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }
  TODO_type_check_in_func(in);
  TODO_type_check_void_PTR(in_desc);
  TODO_type_check_out_func(out);
  TODO_type_check_void_PTR(out_desc);

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Unbox param: in */
  in_func native_in = TODO_mruby_unbox_in_func(in);

  /* Unbox param: in_desc */
  void * native_in_desc = TODO_mruby_unbox_void_PTR(in_desc);

  /* Unbox param: out */
  out_func native_out = TODO_mruby_unbox_out_func(out);

  /* Unbox param: out_desc */
  void * native_out_desc = TODO_mruby_unbox_void_PTR(out_desc);

  /* Invocation */
  int native_return_value = inflateBack(native_strm, native_in, native_in_desc, native_out, native_out_desc);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateBackEnd */
/* sha: fc564d6ad161321710c379b9fbb63e3d8da85eeee10b2cdae7b3a4b64b468a0e */
#if BIND_inflateBackEnd_FUNCTION
#define inflateBackEnd_REQUIRED_ARGC 1
#define inflateBackEnd_OPTIONAL_ARGC 0
/* int inflateBackEnd(z_stream * strm) */
mrb_value
mrb_ZLib_inflateBackEnd(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = inflateBackEnd(native_strm);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateCopy */
/* sha: 99da49a8dda0c6810a8f2eb2662eca73a2be05d94f8d8cfd861d6821065179a1 */
#if BIND_inflateCopy_FUNCTION
#define inflateCopy_REQUIRED_ARGC 2
#define inflateCopy_OPTIONAL_ARGC 0
/* int inflateCopy(z_stream * dest, z_stream * source) */
mrb_value
mrb_ZLib_inflateCopy(mrb_state* mrb, mrb_value self) {
  mrb_value dest;
  mrb_value source;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &dest, &source);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, dest, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, source, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: dest */
  z_stream * native_dest = (mrb_nil_p(dest) ? NULL : mruby_unbox_z_stream(dest));

  /* Unbox param: source */
  z_stream * native_source = (mrb_nil_p(source) ? NULL : mruby_unbox_z_stream(source));

  /* Invocation */
  int native_return_value = inflateCopy(native_dest, native_source);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateEnd */
/* sha: 30d41d8198b435ab4e4d055dbf2fc3e130d61e0024143d2103a634a0d8a2e6ee */
#if BIND_inflateEnd_FUNCTION
#define inflateEnd_REQUIRED_ARGC 1
#define inflateEnd_OPTIONAL_ARGC 0
/* int inflateEnd(z_stream * strm) */
mrb_value
mrb_ZLib_inflateEnd(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = Z_STREAM_ERROR; /* In case of wrong stream type */
  if (((mruby_z_stream*)native_strm)->type == INFLATE_STREAM) {
     native_return_value = inflateEnd(native_strm);
     ((mruby_z_stream*)native_strm)->type = UNINITIALIZED_STREAM;
  }
  
  raise_zlib_errno(mrb, native_return_value);
  
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateGetDictionary */
/* sha: 6dfd1d3d4d7aadc2dd1a02aa3acde110643010c0f07cd4bc8c42973051553774 */
#if BIND_inflateGetDictionary_FUNCTION
#define inflateGetDictionary_REQUIRED_ARGC 3
#define inflateGetDictionary_OPTIONAL_ARGC 0
/* int inflateGetDictionary(z_stream * strm, Bytef * dictionary, uInt * dictLength) */
mrb_value
mrb_ZLib_inflateGetDictionary(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_value dictionary;
  mrb_value dictLength;

  /* Fetch the args */
  mrb_get_args(mrb, "ooo", &strm, &dictionary, &dictLength);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }
  TODO_type_check_Bytef_PTR(dictionary);
  TODO_type_check_uInt_PTR(dictLength);

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Unbox param: dictionary */
  Bytef * native_dictionary = TODO_mruby_unbox_Bytef_PTR(dictionary);

  /* Unbox param: dictLength */
  uInt * native_dictLength = TODO_mruby_unbox_uInt_PTR(dictLength);

  /* Invocation */
  int native_return_value = inflateGetDictionary(native_strm, native_dictionary, native_dictLength);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateGetHeader */
/* sha: 34145f1c2563d907cc504cf2cf0cd45fc65a2765f4c7f18322eb017f6403687e */
#if BIND_inflateGetHeader_FUNCTION
#define inflateGetHeader_REQUIRED_ARGC 2
#define inflateGetHeader_OPTIONAL_ARGC 0
/* int inflateGetHeader(z_stream * strm, gz_header * head) */
mrb_value
mrb_ZLib_inflateGetHeader(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_value head;

  /* Fetch the args */
  mrb_get_args(mrb, "oo", &strm, &head);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }
  if (!mrb_obj_is_kind_of(mrb, head, GZHeader_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "GZHeader expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Unbox param: head */
  gz_header * native_head = (mrb_nil_p(head) ? NULL : mruby_unbox_gz_header(head));

  /* Invocation */
  int native_return_value = inflateGetHeader(native_strm, native_head);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateInit */
/* sha: 305efeca2d8a33fe03badc9e89653e2da68aec245c149bd87f2146d2d6a6a3e8 */
#if BIND_inflateInit_FUNCTION
#define inflateInit_REQUIRED_ARGC 1
#define inflateInit_OPTIONAL_ARGC 0
/* int inflateInit(z_stream * strm) */
mrb_value
mrb_ZLib_inflateInit(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = inflateInit(native_strm);
  if (((mruby_z_stream *)native_strm)->type != UNINITIALIZED_STREAM) {
    mrb_raise(mrb, ZStreamError_class(mrb), "Stream already initialized");
    return mrb_nil_value();
  } else {
    ((mruby_z_stream *)native_strm)->type = INFLATE_STREAM;
  }

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateInit2 */
/* sha: 67fa46fee1d20b0b6f3ef81fca24fc6116d83fd59a131d462dc260d675aa77bb */
#if BIND_inflateInit2_FUNCTION
#define inflateInit2_REQUIRED_ARGC 2
#define inflateInit2_OPTIONAL_ARGC 0
/* int inflateInit2(z_stream * strm, int windowBits) */
mrb_value
mrb_ZLib_inflateInit2(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_windowBits;

  /* Fetch the args */
  mrb_get_args(mrb, "oi", &strm, &native_windowBits);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));
  if (((mruby_z_stream *)native_strm)->type != UNINITIALIZED_STREAM) {
    mrb_raise(mrb, ZStreamError_class(mrb), "Stream already initialized");
    return mrb_nil_value();
  } else {
    ((mruby_z_stream *)native_strm)->type = INFLATE_STREAM;
  }

  /* Invocation */
  int native_return_value = inflateInit2(native_strm, native_windowBits);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateMark */
/* sha: fb14d2d9175a053a15e988a33fea22b2beaf79f520ee99cd2bd5c74315703b61 */
#if BIND_inflateMark_FUNCTION
#define inflateMark_REQUIRED_ARGC 1
#define inflateMark_OPTIONAL_ARGC 0
/* long inflateMark(z_stream * strm) */
mrb_value
mrb_ZLib_inflateMark(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  long native_return_value = inflateMark(native_strm);

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflatePrime */
/* sha: 190ca1624007fecd2472cf01a8505241f03c03e6b250f163a251c569ce380e73 */
#if BIND_inflatePrime_FUNCTION
#define inflatePrime_REQUIRED_ARGC 3
#define inflatePrime_OPTIONAL_ARGC 0
/* int inflatePrime(z_stream * strm, int bits, int value) */
mrb_value
mrb_ZLib_inflatePrime(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_bits;
  mrb_int native_value;

  /* Fetch the args */
  mrb_get_args(mrb, "oii", &strm, &native_bits, &native_value);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = inflatePrime(native_strm, native_bits, native_value);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateReset */
/* sha: 1735947fe5d7903b735230849c69720b2b65b303130353045410bf152dbe1081 */
#if BIND_inflateReset_FUNCTION
#define inflateReset_REQUIRED_ARGC 1
#define inflateReset_OPTIONAL_ARGC 0
/* int inflateReset(z_stream * strm) */
mrb_value
mrb_ZLib_inflateReset(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = inflateReset(native_strm);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateReset2 */
/* sha: 4be731970ec396464b1b6a563809e0d66ebb1e31c8e2f5a60d320afa399f86cf */
#if BIND_inflateReset2_FUNCTION
#define inflateReset2_REQUIRED_ARGC 2
#define inflateReset2_OPTIONAL_ARGC 0
/* int inflateReset2(z_stream * strm, int windowBits) */
mrb_value
mrb_ZLib_inflateReset2(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  mrb_int native_windowBits;

  /* Fetch the args */
  mrb_get_args(mrb, "oi", &strm, &native_windowBits);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = inflateReset2(native_strm, native_windowBits);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateResetKeep */
/* sha: fbb4574f8e12841116d50e1b2362b7da78cf85ca7ef5453e5bdab064f2fb20d0 */
#if BIND_inflateResetKeep_FUNCTION
#define inflateResetKeep_REQUIRED_ARGC 1
#define inflateResetKeep_OPTIONAL_ARGC 0
/* int inflateResetKeep(z_stream * arg1) */
mrb_value
mrb_ZLib_inflateResetKeep(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arg1, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: arg1 */
  z_stream * native_arg1 = (mrb_nil_p(arg1) ? NULL : mruby_unbox_z_stream(arg1));

  /* Invocation */
  int native_return_value = inflateResetKeep(native_arg1);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateSetDictionary */
/* sha: 4a9c5351d6376548cdf112014b23b82725dd2a6b6b71cb0c9cb0b403ac178e7f */
#if BIND_inflateSetDictionary_FUNCTION
#define inflateSetDictionary_REQUIRED_ARGC 3
#define inflateSetDictionary_OPTIONAL_ARGC 0
/* int inflateSetDictionary(z_stream * strm, const Bytef * dictionary, uInt dictLength) */
mrb_value
mrb_ZLib_inflateSetDictionary(mrb_state* mrb, mrb_value self) {
  mrb_value strm;
  char * native_dictionary = NULL;
  mrb_value dictLength;

  /* Fetch the args */
  mrb_get_args(mrb, "ozo", &strm, &native_dictionary, &dictLength);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }
  TODO_type_check_uInt(dictLength);

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Unbox param: dictLength */
  uInt native_dictLength = TODO_mruby_unbox_uInt(dictLength);

  /* Invocation */
  int native_return_value = inflateSetDictionary(native_strm, native_dictionary, native_dictLength);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateSync */
/* sha: 8553d7a328dfdc623cec17cac3ec596195a6da98b4335b25245556c8c58f0a69 */
#if BIND_inflateSync_FUNCTION
#define inflateSync_REQUIRED_ARGC 1
#define inflateSync_OPTIONAL_ARGC 0
/* int inflateSync(z_stream * strm) */
mrb_value
mrb_ZLib_inflateSync(mrb_state* mrb, mrb_value self) {
  mrb_value strm;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &strm);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, strm, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: strm */
  z_stream * native_strm = (mrb_nil_p(strm) ? NULL : mruby_unbox_z_stream(strm));

  /* Invocation */
  int native_return_value = inflateSync(native_strm);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateSyncPoint */
/* sha: d2dad649bacedbedb6fd7750561dca3c4246bd2112fb1691e09064d4285081f9 */
#if BIND_inflateSyncPoint_FUNCTION
#define inflateSyncPoint_REQUIRED_ARGC 1
#define inflateSyncPoint_OPTIONAL_ARGC 0
/* int inflateSyncPoint(z_stream * arg1) */
mrb_value
mrb_ZLib_inflateSyncPoint(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "o", &arg1);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arg1, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: arg1 */
  z_stream * native_arg1 = (mrb_nil_p(arg1) ? NULL : mruby_unbox_z_stream(arg1));

  /* Invocation */
  int native_return_value = inflateSyncPoint(native_arg1);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: inflateUndermine */
/* sha: 60cc6e53023e324ceec4bc9825af05bfebd2759101be6066089f5762af4f176e */
#if BIND_inflateUndermine_FUNCTION
#define inflateUndermine_REQUIRED_ARGC 2
#define inflateUndermine_OPTIONAL_ARGC 0
/* int inflateUndermine(z_stream * arg1, int arg2) */
mrb_value
mrb_ZLib_inflateUndermine(mrb_state* mrb, mrb_value self) {
  mrb_value arg1;
  mrb_int native_arg2;

  /* Fetch the args */
  mrb_get_args(mrb, "oi", &arg1, &native_arg2);

  /* Type checking */
  if (!mrb_obj_is_kind_of(mrb, arg1, ZStream_class(mrb))) {
    mrb_raise(mrb, E_TYPE_ERROR, "ZStream expected");
    return mrb_nil_value();
  }

  /* Unbox param: arg1 */
  z_stream * native_arg1 = (mrb_nil_p(arg1) ? NULL : mruby_unbox_z_stream(arg1));

  /* Invocation */
  int native_return_value = inflateUndermine(native_arg1, native_arg2);

  /* Box the return value */
  raise_zlib_errno(mrb, native_return_value);
  return mrb_nil_value();
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: uncompress */
/* sha: dbd62d596e2a47b46642afcb4c4af9ed744b8ec0fa3c02501e630753b0c0bfcd */
#if BIND_uncompress_FUNCTION
#define uncompress_REQUIRED_ARGC 2
#define uncompress_OPTIONAL_ARGC 0
/* int uncompress(Bytef * dest, uLongf * destLen, const Bytef * source, uLong sourceLen) */
mrb_value
mrb_ZLib_uncompress(mrb_state* mrb, mrb_value self) {
  mrb_int destLen = 0;
  char * native_source = NULL;
  mrb_int native_sourceLen;

  /* Fetch the args */
  mrb_get_args(mrb, "is", &destLen, &native_source, &native_sourceLen);

  /* Invocation */
  uLongf native_destLen = destLen;
  Bytef * native_dest = (Bytef *)calloc(native_destLen, sizeof(Bytef));
  int native_return_value = uncompress(native_dest, &native_destLen, (Bytef *)native_source, native_sourceLen);

  mrb_value result = mrb_nil_value();
  if (native_return_value == Z_OK) {
    result = mrb_str_new(mrb, (char*)native_dest, native_destLen);
  }
  
  free(native_dest);
  
  raise_zlib_errno(mrb, native_return_value);
  
  return result;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: zError */
/* sha: d60b747cc676734c2ff4d80ddb465bc951a7a2834a60cb8810348bc4a12bc43b */
#if BIND_zError_FUNCTION
#define zError_REQUIRED_ARGC 1
#define zError_OPTIONAL_ARGC 0
/* const char * zError(int arg1) */
mrb_value
mrb_ZLib_zError(mrb_state* mrb, mrb_value self) {
  mrb_int native_arg1;

  /* Fetch the args */
  mrb_get_args(mrb, "i", &native_arg1);

  /* Invocation */
  const char * native_return_value = zError(native_arg1);

  /* Box the return value */
  mrb_value return_value = native_return_value == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: zlibCompileFlags */
/* sha: ccc41c127137649b5989e1e5598611af483026e966d6f094e98bd4a9f306383a */
#if BIND_zlibCompileFlags_FUNCTION
#define zlibCompileFlags_REQUIRED_ARGC 0
#define zlibCompileFlags_OPTIONAL_ARGC 0
/* uLong zlibCompileFlags() */
mrb_value
mrb_ZLib_zlibCompileFlags(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  uLong native_return_value = zlibCompileFlags();

  /* Box the return value */
  mrb_value return_value = mrb_fixnum_value(native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: zlibVersion */
/* sha: f0bb77bbe4a2c36dfce24adc6c42e1078b77d5d913be85270c3efbfbc5e57e08 */
#if BIND_zlibVersion_FUNCTION
#define zlibVersion_REQUIRED_ARGC 0
#define zlibVersion_OPTIONAL_ARGC 0
/* const char * zlibVersion() */
mrb_value
mrb_ZLib_zlibVersion(mrb_state* mrb, mrb_value self) {
  /* Invocation */
  const char * native_return_value = zlibVersion();

  /* Box the return value */
  mrb_value return_value = native_return_value == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, native_return_value);
  
  return return_value;
}
#endif
/* MRUBY_BINDING_END */


void mrb_mruby_zlib_gem_init(mrb_state* mrb) {
/* MRUBY_BINDING: pre_module_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
  
  struct RClass* ZLib_module = mrb_define_module(mrb, "ZLib");
  mruby_ZLib_define_macro_constants(mrb);
  mruby_ZLib_define_enum_constants(mrb);

/* MRUBY_BINDING: pre_class_initializations */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: class_initializations */
/* sha: c542a6f583afbd418ea324e66ac7f5e1f34d083f35eb72bbdb8808b458689f1d */
#if BIND_GZFile_TYPE
  mrb_ZLib_GZFile_init(mrb);
#endif
#if BIND_GZHeader_TYPE
  mrb_ZLib_GZHeader_init(mrb);
#endif
#if BIND_ZStream_TYPE
  mrb_ZLib_ZStream_init(mrb);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: pre_global_function_initializations */
/* sha: user_defined */
  mrb_define_class_under(mrb, ZLib_module, "ZError", mrb->eStandardError_class);
  mrb_define_class_under(mrb, ZLib_module, "ZIOError", mrb->eStandardError_class);
  mrb_define_class_under(mrb, ZLib_module, "ZSystemCallError", ZError_class(mrb));
  mrb_define_class_under(mrb, ZLib_module, "ZStreamError", ZError_class(mrb));
  mrb_define_class_under(mrb, ZLib_module, "ZBufferError", ZError_class(mrb));
  mrb_define_class_under(mrb, ZLib_module, "ZDataError", ZError_class(mrb));
  mrb_define_class_under(mrb, ZLib_module, "ZMemoryError", ZError_class(mrb));
  mrb_define_class_under(mrb, ZLib_module, "ZVersionError", ZError_class(mrb));
   
#undef BIND_gzgetc__FUNCTION
#define BIND_gzgetc__FUNCTION FALSE
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: global_function_definitions */
/* sha: 1553d18e83530ab6eec54a328074978978ce9ab9cc1ef1e103b5e225f97ff2b0 */
  /*
   * Global Functions
   */
#if BIND_adler32_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "adler32", mrb_ZLib_adler32, MRB_ARGS_ARG(adler32_REQUIRED_ARGC, adler32_OPTIONAL_ARGC));
#endif
#if BIND_adler32_combine_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "adler32_combine", mrb_ZLib_adler32_combine, MRB_ARGS_ARG(adler32_combine_REQUIRED_ARGC, adler32_combine_OPTIONAL_ARGC));
#endif
#if BIND_compress_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "compress", mrb_ZLib_compress, MRB_ARGS_ARG(compress_REQUIRED_ARGC, compress_OPTIONAL_ARGC));
#endif
#if BIND_compress2_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "compress2", mrb_ZLib_compress2, MRB_ARGS_ARG(compress2_REQUIRED_ARGC, compress2_OPTIONAL_ARGC));
#endif
#if BIND_compressBound_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "compressBound", mrb_ZLib_compressBound, MRB_ARGS_ARG(compressBound_REQUIRED_ARGC, compressBound_OPTIONAL_ARGC));
#endif
#if BIND_crc32_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "crc32", mrb_ZLib_crc32, MRB_ARGS_ARG(crc32_REQUIRED_ARGC, crc32_OPTIONAL_ARGC));
#endif
#if BIND_crc32_combine_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "crc32_combine", mrb_ZLib_crc32_combine, MRB_ARGS_ARG(crc32_combine_REQUIRED_ARGC, crc32_combine_OPTIONAL_ARGC));
#endif
#if BIND_deflate_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflate", mrb_ZLib_deflate, MRB_ARGS_ARG(deflate_REQUIRED_ARGC, deflate_OPTIONAL_ARGC));
#endif
#if BIND_deflateBound_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateBound", mrb_ZLib_deflateBound, MRB_ARGS_ARG(deflateBound_REQUIRED_ARGC, deflateBound_OPTIONAL_ARGC));
#endif
#if BIND_deflateCopy_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateCopy", mrb_ZLib_deflateCopy, MRB_ARGS_ARG(deflateCopy_REQUIRED_ARGC, deflateCopy_OPTIONAL_ARGC));
#endif
#if BIND_deflateEnd_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateEnd", mrb_ZLib_deflateEnd, MRB_ARGS_ARG(deflateEnd_REQUIRED_ARGC, deflateEnd_OPTIONAL_ARGC));
#endif
#if BIND_deflateInit_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateInit", mrb_ZLib_deflateInit, MRB_ARGS_ARG(deflateInit_REQUIRED_ARGC, deflateInit_OPTIONAL_ARGC));
#endif
#if BIND_deflateInit2_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateInit2", mrb_ZLib_deflateInit2, MRB_ARGS_ARG(deflateInit2_REQUIRED_ARGC, deflateInit2_OPTIONAL_ARGC));
#endif
#if BIND_deflateParams_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateParams", mrb_ZLib_deflateParams, MRB_ARGS_ARG(deflateParams_REQUIRED_ARGC, deflateParams_OPTIONAL_ARGC));
#endif
#if BIND_deflatePending_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflatePending", mrb_ZLib_deflatePending, MRB_ARGS_ARG(deflatePending_REQUIRED_ARGC, deflatePending_OPTIONAL_ARGC));
#endif
#if BIND_deflatePrime_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflatePrime", mrb_ZLib_deflatePrime, MRB_ARGS_ARG(deflatePrime_REQUIRED_ARGC, deflatePrime_OPTIONAL_ARGC));
#endif
#if BIND_deflateReset_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateReset", mrb_ZLib_deflateReset, MRB_ARGS_ARG(deflateReset_REQUIRED_ARGC, deflateReset_OPTIONAL_ARGC));
#endif
#if BIND_deflateResetKeep_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateResetKeep", mrb_ZLib_deflateResetKeep, MRB_ARGS_ARG(deflateResetKeep_REQUIRED_ARGC, deflateResetKeep_OPTIONAL_ARGC));
#endif
#if BIND_deflateSetDictionary_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateSetDictionary", mrb_ZLib_deflateSetDictionary, MRB_ARGS_ARG(deflateSetDictionary_REQUIRED_ARGC, deflateSetDictionary_OPTIONAL_ARGC));
#endif
#if BIND_deflateSetHeader_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateSetHeader", mrb_ZLib_deflateSetHeader, MRB_ARGS_ARG(deflateSetHeader_REQUIRED_ARGC, deflateSetHeader_OPTIONAL_ARGC));
#endif
#if BIND_deflateTune_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "deflateTune", mrb_ZLib_deflateTune, MRB_ARGS_ARG(deflateTune_REQUIRED_ARGC, deflateTune_OPTIONAL_ARGC));
#endif
#if BIND_get_crc_table_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "get_crc_table", mrb_ZLib_get_crc_table, MRB_ARGS_ARG(get_crc_table_REQUIRED_ARGC, get_crc_table_OPTIONAL_ARGC));
#endif
#if BIND_gzbuffer_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzbuffer", mrb_ZLib_gzbuffer, MRB_ARGS_ARG(gzbuffer_REQUIRED_ARGC, gzbuffer_OPTIONAL_ARGC));
#endif
#if BIND_gzclearerr_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzclearerr", mrb_ZLib_gzclearerr, MRB_ARGS_ARG(gzclearerr_REQUIRED_ARGC, gzclearerr_OPTIONAL_ARGC));
#endif
#if BIND_gzclose_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzclose", mrb_ZLib_gzclose, MRB_ARGS_ARG(gzclose_REQUIRED_ARGC, gzclose_OPTIONAL_ARGC));
#endif
#if BIND_gzdirect_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzdirect", mrb_ZLib_gzdirect, MRB_ARGS_ARG(gzdirect_REQUIRED_ARGC, gzdirect_OPTIONAL_ARGC));
#endif
#if BIND_gzdopen_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzdopen", mrb_ZLib_gzdopen, MRB_ARGS_ARG(gzdopen_REQUIRED_ARGC, gzdopen_OPTIONAL_ARGC));
#endif
#if BIND_gzeof_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzeof", mrb_ZLib_gzeof, MRB_ARGS_ARG(gzeof_REQUIRED_ARGC, gzeof_OPTIONAL_ARGC));
#endif
#if BIND_gzerror_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzerror", mrb_ZLib_gzerror, MRB_ARGS_ARG(gzerror_REQUIRED_ARGC, gzerror_OPTIONAL_ARGC));
#endif
#if BIND_gzflush_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzflush", mrb_ZLib_gzflush, MRB_ARGS_ARG(gzflush_REQUIRED_ARGC, gzflush_OPTIONAL_ARGC));
#endif
#if BIND_gzgetc_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzgetc", mrb_ZLib_gzgetc, MRB_ARGS_ARG(gzgetc_REQUIRED_ARGC, gzgetc_OPTIONAL_ARGC));
#endif
#if BIND_gzgets_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzgets", mrb_ZLib_gzgets, MRB_ARGS_ARG(gzgets_REQUIRED_ARGC, gzgets_OPTIONAL_ARGC));
#endif
#if BIND_gzoffset_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzoffset", mrb_ZLib_gzoffset, MRB_ARGS_ARG(gzoffset_REQUIRED_ARGC, gzoffset_OPTIONAL_ARGC));
#endif
#if BIND_gzopen_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzopen", mrb_ZLib_gzopen, MRB_ARGS_ARG(gzopen_REQUIRED_ARGC, gzopen_OPTIONAL_ARGC));
#endif
#if BIND_gzputc_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzputc", mrb_ZLib_gzputc, MRB_ARGS_ARG(gzputc_REQUIRED_ARGC, gzputc_OPTIONAL_ARGC));
#endif
#if BIND_gzputs_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzputs", mrb_ZLib_gzputs, MRB_ARGS_ARG(gzputs_REQUIRED_ARGC, gzputs_OPTIONAL_ARGC));
#endif
#if BIND_gzread_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzread", mrb_ZLib_gzread, MRB_ARGS_ARG(gzread_REQUIRED_ARGC, gzread_OPTIONAL_ARGC));
#endif
#if BIND_gzrewind_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzrewind", mrb_ZLib_gzrewind, MRB_ARGS_ARG(gzrewind_REQUIRED_ARGC, gzrewind_OPTIONAL_ARGC));
#endif
#if BIND_gzseek_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzseek", mrb_ZLib_gzseek, MRB_ARGS_ARG(gzseek_REQUIRED_ARGC, gzseek_OPTIONAL_ARGC));
#endif
#if BIND_gzsetparams_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzsetparams", mrb_ZLib_gzsetparams, MRB_ARGS_ARG(gzsetparams_REQUIRED_ARGC, gzsetparams_OPTIONAL_ARGC));
#endif
#if BIND_gztell_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gztell", mrb_ZLib_gztell, MRB_ARGS_ARG(gztell_REQUIRED_ARGC, gztell_OPTIONAL_ARGC));
#endif
#if BIND_gzungetc_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzungetc", mrb_ZLib_gzungetc, MRB_ARGS_ARG(gzungetc_REQUIRED_ARGC, gzungetc_OPTIONAL_ARGC));
#endif
#if BIND_gzwrite_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "gzwrite", mrb_ZLib_gzwrite, MRB_ARGS_ARG(gzwrite_REQUIRED_ARGC, gzwrite_OPTIONAL_ARGC));
#endif
#if BIND_inflate_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflate", mrb_ZLib_inflate, MRB_ARGS_ARG(inflate_REQUIRED_ARGC, inflate_OPTIONAL_ARGC));
#endif
#if BIND_inflateBack_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateBack", mrb_ZLib_inflateBack, MRB_ARGS_ARG(inflateBack_REQUIRED_ARGC, inflateBack_OPTIONAL_ARGC));
#endif
#if BIND_inflateBackEnd_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateBackEnd", mrb_ZLib_inflateBackEnd, MRB_ARGS_ARG(inflateBackEnd_REQUIRED_ARGC, inflateBackEnd_OPTIONAL_ARGC));
#endif
#if BIND_inflateCopy_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateCopy", mrb_ZLib_inflateCopy, MRB_ARGS_ARG(inflateCopy_REQUIRED_ARGC, inflateCopy_OPTIONAL_ARGC));
#endif
#if BIND_inflateEnd_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateEnd", mrb_ZLib_inflateEnd, MRB_ARGS_ARG(inflateEnd_REQUIRED_ARGC, inflateEnd_OPTIONAL_ARGC));
#endif
#if BIND_inflateGetDictionary_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateGetDictionary", mrb_ZLib_inflateGetDictionary, MRB_ARGS_ARG(inflateGetDictionary_REQUIRED_ARGC, inflateGetDictionary_OPTIONAL_ARGC));
#endif
#if BIND_inflateGetHeader_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateGetHeader", mrb_ZLib_inflateGetHeader, MRB_ARGS_ARG(inflateGetHeader_REQUIRED_ARGC, inflateGetHeader_OPTIONAL_ARGC));
#endif
#if BIND_inflateInit_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateInit", mrb_ZLib_inflateInit, MRB_ARGS_ARG(inflateInit_REQUIRED_ARGC, inflateInit_OPTIONAL_ARGC));
#endif
#if BIND_inflateInit2_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateInit2", mrb_ZLib_inflateInit2, MRB_ARGS_ARG(inflateInit2_REQUIRED_ARGC, inflateInit2_OPTIONAL_ARGC));
#endif
#if BIND_inflateMark_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateMark", mrb_ZLib_inflateMark, MRB_ARGS_ARG(inflateMark_REQUIRED_ARGC, inflateMark_OPTIONAL_ARGC));
#endif
#if BIND_inflatePrime_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflatePrime", mrb_ZLib_inflatePrime, MRB_ARGS_ARG(inflatePrime_REQUIRED_ARGC, inflatePrime_OPTIONAL_ARGC));
#endif
#if BIND_inflateReset_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateReset", mrb_ZLib_inflateReset, MRB_ARGS_ARG(inflateReset_REQUIRED_ARGC, inflateReset_OPTIONAL_ARGC));
#endif
#if BIND_inflateReset2_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateReset2", mrb_ZLib_inflateReset2, MRB_ARGS_ARG(inflateReset2_REQUIRED_ARGC, inflateReset2_OPTIONAL_ARGC));
#endif
#if BIND_inflateResetKeep_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateResetKeep", mrb_ZLib_inflateResetKeep, MRB_ARGS_ARG(inflateResetKeep_REQUIRED_ARGC, inflateResetKeep_OPTIONAL_ARGC));
#endif
#if BIND_inflateSetDictionary_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateSetDictionary", mrb_ZLib_inflateSetDictionary, MRB_ARGS_ARG(inflateSetDictionary_REQUIRED_ARGC, inflateSetDictionary_OPTIONAL_ARGC));
#endif
#if BIND_inflateSync_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateSync", mrb_ZLib_inflateSync, MRB_ARGS_ARG(inflateSync_REQUIRED_ARGC, inflateSync_OPTIONAL_ARGC));
#endif
#if BIND_inflateSyncPoint_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateSyncPoint", mrb_ZLib_inflateSyncPoint, MRB_ARGS_ARG(inflateSyncPoint_REQUIRED_ARGC, inflateSyncPoint_OPTIONAL_ARGC));
#endif
#if BIND_inflateUndermine_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "inflateUndermine", mrb_ZLib_inflateUndermine, MRB_ARGS_ARG(inflateUndermine_REQUIRED_ARGC, inflateUndermine_OPTIONAL_ARGC));
#endif
#if BIND_uncompress_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "uncompress", mrb_ZLib_uncompress, MRB_ARGS_ARG(uncompress_REQUIRED_ARGC, uncompress_OPTIONAL_ARGC));
#endif
#if BIND_zError_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "zError", mrb_ZLib_zError, MRB_ARGS_ARG(zError_REQUIRED_ARGC, zError_OPTIONAL_ARGC));
#endif
#if BIND_zlibCompileFlags_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "zlibCompileFlags", mrb_ZLib_zlibCompileFlags, MRB_ARGS_ARG(zlibCompileFlags_REQUIRED_ARGC, zlibCompileFlags_OPTIONAL_ARGC));
#endif
#if BIND_zlibVersion_FUNCTION
  mrb_define_class_method(mrb, ZLib_module, "zlibVersion", mrb_ZLib_zlibVersion, MRB_ARGS_ARG(zlibVersion_REQUIRED_ARGC, zlibVersion_OPTIONAL_ARGC));
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: post_module_definition */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

void mrb_mruby_zlib_gem_final(mrb_state* mrb){
/* MRUBY_BINDING: module_final */
/* sha: user_defined */

/* MRUBY_BINDING_END */
}

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */

#ifdef __cplusplus
}
#endif
