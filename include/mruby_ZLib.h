#ifndef ZLib_HEADER
#define ZLib_HEADER

/*
 * Header Files
 * ------------
 *
 * These are the header files that defined the
 * classes and functions for which bindings have
 * been generated. If any of these are not needed
 * they should be commented out.
 *
 * TODO: ONLY the filename is inserted here automatically.
 *       If the file is not directly on the include path,
 *       you will need to prepend the relative path.
 */

/* MRUBY_BINDING: pre_includes */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: includes */
/* sha: 9e6861fe8b2b2a9a28cd5300d432b3425f1769d505440a91fed6ff1340b48d49 */
#include <stdlib.h>
#include "mruby.h"
#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/compile.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "mruby/value.h"
#include "mruby/variable.h"

#include "zlib.h"

#include "mruby_ZLib_functions.h"
#include "mruby_ZLib_classes.h"
#include "mruby_ZLib_boxing.h"
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: post_includes */
/* sha: user_defined */
#undef BIND_GZFile_INITIALIZE
#define BIND_GZFile_INITIALIZE TRUE

#define BUFFER_SIZE (64 * 1024)

typedef enum {
  UNINITIALIZED_STREAM,
  INFLATE_STREAM,
  DEFLATE_STREAM  
} mruby_z_stream_type;

typedef struct {
  z_stream stream;
  int buffer_size;
  char * buffer_start;
  mruby_z_stream_type type;
} mruby_z_stream;
/* MRUBY_BINDING_END */

/*
 * RClass Macros
 * -------------
 *
 * Macros for retrieving the RClass*'s defined by this gem.
 */

/* MRUBY_BINDING: pre_class_macros */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: class_macros */
/* sha: 23169abb3cc59dd79b0ec773a09fc761b3330e97655f5d6bc3c206dbc1c8e5a4 */
/* EDITED */
#define ZLib_module(mrb) mrb_module_get(mrb, "ZLib")
#define GZFile_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "GZFile")
#define GZHeader_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "GZHeader")
#define InternalState_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "InternalState")
#define ZStream_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZStream")
#define ZError_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZError")
#define ZIOError_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZIOError")
#define ZSystemCallError_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZSystemCallError")
#define ZStreamError_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZStreamError")
#define ZBufferError_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZBufferError")
#define ZDataError_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZDataError")
#define ZMemoryError_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZMemoryError")
#define ZVersionError_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZVersionError")
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: post_class_macros */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/*
 * Class initialization function declarations
 * ------------------------------------------
 */

/* MRUBY_BINDING: pre_class_init_decls */
/* sha: 694807446c1a191b0a25d46c63cbd96bc881afb2ca2becdda469cfcd05ad7d22 */
/* EDITED */
#if BIND_GZFile_TYPE
void mrb_ZLib_GZFile_init(mrb_state* mrb);
#endif
#if BIND_GZHeader_TYPE
void mrb_ZLib_GZHeader_init(mrb_state* mrb);
#endif
#if BIND_InternalState_TYPE
void mrb_ZLib_InternalState_init(mrb_state* mrb);
#endif
#if BIND_ZStream_TYPE
void mrb_ZLib_ZStream_init(mrb_state* mrb);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: pre_class_init_decls */
/* sha: 694807446c1a191b0a25d46c63cbd96bc881afb2ca2becdda469cfcd05ad7d22 */
/* EDITED */
#if BIND_GZFile_TYPE
void mrb_ZLib_GZFile_init(mrb_state* mrb);
#endif
#if BIND_GZHeader_TYPE
void mrb_ZLib_GZHeader_init(mrb_state* mrb);
#endif
#if BIND_InternalState_TYPE
void mrb_ZLib_InternalState_init(mrb_state* mrb);
#endif
#if BIND_ZStream_TYPE
void mrb_ZLib_ZStream_init(mrb_state* mrb);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: post_class_init_decls */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/*
 * Macro & Enum definition function declarations
 * ---------------------------------------------
 */
void mruby_ZLib_define_macro_constants(mrb_state* mrb);
void mruby_ZLib_define_enum_constants(mrb_state* mrb);

#endif
