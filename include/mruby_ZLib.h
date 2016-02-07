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
/* sha: e6204699f59b76f30ddea4f1eea5bb0584aa69aac55268450b325eabd1f477bb */
#define ZLib_module(mrb) mrb_module_get(mrb, "ZLib")
#define GzFile_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "GzFile")
#define GzFileS_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "GzFileS")
#define GzHeader_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "GzHeader")
#define InternalState_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "InternalState")
#define ZStream_class(mrb) mrb_class_get_under(mrb, ZLib_module(mrb), "ZStream")
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: post_class_macros */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/*
 * Class initialization function declarations
 * ------------------------------------------
 */

/* MRUBY_BINDING: pre_class_init_decls */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: pre_class_init_decls */
/* sha: 266af0f99fb28d534cf36d6e95f529f659421a6507668c80442a5a216b44c66d */
#if BIND_GzFile_TYPE
void mrb_ZLib_GzFile_init(mrb_state* mrb);
#endif
#if BIND_GzFileS_TYPE
void mrb_ZLib_GzFileS_init(mrb_state* mrb);
#endif
#if BIND_GzHeader_TYPE
void mrb_ZLib_GzHeader_init(mrb_state* mrb);
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
