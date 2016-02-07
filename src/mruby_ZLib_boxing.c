/*
 * Boxing Code (Generated)
 * =======================
 *
 * The code generator learns the data types declared in the C/C++ source files
 * it is run against, and generates this boxing, unboxing, and GC code.
 * 
 * Terms
 * ------
 *
 * ### Boxing
 * In general refers to wrapping a native object in an mrb_value.
 * 
 * ### Gift Wrapping
 * A specific type of boxing, indicating that the object belongs
 * to Ruby and should be free'd when the mrb_value is GC'ed.
 * 
 * ### Unboxing
 * Retrieving the wrapped native object from an mrb_value.
 *
 * Customizing
 * -----------
 * 
 * By default, all data types are assumed to be destructable by the `free`
 * function. To use a custom destructor for your type, tell CTypes with
 * `CTypes.set_destructor`.
 *
 * Example
 * ```
 * // I have `struct GError` objects from glib,
 * // which should be freed with `g_error_free`
 * CTypes.set_destructor('struct GError', 'g_error_free')
 * ```
 */
#include "mruby_ZLib.h"

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFile_boxing */
/* sha: 8dc6ecfb84a60bab981fa393a6ad9ac356c01ad686b1d888f16072d9b8f54b37 */
#if BIND_GzFile_TYPE
/*
 * Boxing implementation for gzFile
 */

static void free_gzFile(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
  free(box);
}

static const mrb_data_type gzFile_data_type = {
   "gzFile", free_gzFile
};

mrb_value
mruby_box_gzFile(mrb_state* mrb, gzFile *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, GzFile_class(mrb), &gzFile_data_type, box));
}

mrb_value
mruby_giftwrap_gzFile(mrb_state* mrb, gzFile *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, GzFile_class(mrb), &gzFile_data_type, box));
}

void
mruby_set_gzFile_data_ptr(mrb_value obj, gzFile *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &gzFile_data_type);
}

void
mruby_gift_gzFile_data_ptr(mrb_value obj, gzFile *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &gzFile_data_type);
}

gzFile *
mruby_unbox_gzFile(mrb_value boxed) {
  return (gzFile *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader_boxing */
/* sha: 49129dd3ba6878140345155873a4177f941bf59df999d0540f5ba25a2131756c */
#if BIND_GzHeader_TYPE
/*
 * Boxing implementation for gz_header
 */

static void free_gz_header(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
  free(box);
}

static const mrb_data_type gz_header_data_type = {
   "gz_header", free_gz_header
};

mrb_value
mruby_box_gz_header(mrb_state* mrb, gz_header *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, GzHeader_class(mrb), &gz_header_data_type, box));
}

mrb_value
mruby_giftwrap_gz_header(mrb_state* mrb, gz_header *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, GzHeader_class(mrb), &gz_header_data_type, box));
}

void
mruby_set_gz_header_data_ptr(mrb_value obj, gz_header *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &gz_header_data_type);
}

void
mruby_gift_gz_header_data_ptr(mrb_value obj, gz_header *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &gz_header_data_type);
}

gz_header *
mruby_unbox_gz_header(mrb_value boxed) {
  return (gz_header *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFileS_boxing */
/* sha: f3d872a45168a6e96c15d2dc2cd1490a92c5c3892a42d42412246831f485782a */
#if BIND_GzFileS_TYPE
/*
 * Boxing implementation for gzFile
 */

static void free_gzFile_s(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
  free(box);
}

static const mrb_data_type gzFile_s_data_type = {
   "gzFile", free_gzFile_s
};

mrb_value
mruby_box_gzFile_s(mrb_state* mrb, gzFile unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, GzFileS_class(mrb), &gzFile_s_data_type, box));
}

mrb_value
mruby_giftwrap_gzFile_s(mrb_state* mrb, gzFile unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, GzFileS_class(mrb), &gzFile_s_data_type, box));
}

void
mruby_set_gzFile_s_data_ptr(mrb_value obj, gzFile unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &gzFile_s_data_type);
}

void
mruby_gift_gzFile_s_data_ptr(mrb_value obj, gzFile unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &gzFile_s_data_type);
}

gzFile
mruby_unbox_gzFile_s(mrb_value boxed) {
  return (gzFile)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState_boxing */
/* sha: 1c6d9f068c83d4272ba3b5982bf6a8ade23d9bda7be26405114d3c246c880ee8 */
#if BIND_InternalState_TYPE
/*
 * Boxing implementation for struct internal_state
 */

static void free_internal_state(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
  free(box);
}

static const mrb_data_type internal_state_data_type = {
   "struct internal_state", free_internal_state
};

mrb_value
mruby_box_internal_state(mrb_state* mrb, struct internal_state *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, InternalState_class(mrb), &internal_state_data_type, box));
}

mrb_value
mruby_giftwrap_internal_state(mrb_state* mrb, struct internal_state *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, InternalState_class(mrb), &internal_state_data_type, box));
}

void
mruby_set_internal_state_data_ptr(mrb_value obj, struct internal_state *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &internal_state_data_type);
}

void
mruby_gift_internal_state_data_ptr(mrb_value obj, struct internal_state *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &internal_state_data_type);
}

struct internal_state *
mruby_unbox_internal_state(mrb_value boxed) {
  return (struct internal_state *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream_boxing */
/* sha: b2f7cedafaaca61355e35ad8d299fb449418390c1be1b24d439a58e49c8b82cc */
#if BIND_ZStream_TYPE
/*
 * Boxing implementation for z_stream
 */

static void free_z_stream(mrb_state* mrb, void* ptr) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)ptr;
  if (box->belongs_to_ruby) {
    if (box->obj != NULL) {
      free(box->obj);
      box->obj = NULL;
    }
  }
  free(box);
}

static const mrb_data_type z_stream_data_type = {
   "z_stream", free_z_stream
};

mrb_value
mruby_box_z_stream(mrb_state* mrb, z_stream *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  return mrb_obj_value(Data_Wrap_Struct(mrb, ZStream_class(mrb), &z_stream_data_type, box));
}

mrb_value
mruby_giftwrap_z_stream(mrb_state* mrb, z_stream *unboxed) {
   mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
   box->belongs_to_ruby = TRUE;
   box->obj = unboxed;
   return mrb_obj_value(Data_Wrap_Struct(mrb, ZStream_class(mrb), &z_stream_data_type, box));
}

void
mruby_set_z_stream_data_ptr(mrb_value obj, z_stream *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = FALSE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &z_stream_data_type);
}

void
mruby_gift_z_stream_data_ptr(mrb_value obj, z_stream *unboxed) {
  mruby_to_native_ref* box = (mruby_to_native_ref*)malloc(sizeof(mruby_to_native_ref));
  box->belongs_to_ruby = TRUE;
  box->obj = unboxed;
  mrb_data_init(obj, box, &z_stream_data_type);
}

z_stream *
mruby_unbox_z_stream(mrb_value boxed) {
  return (z_stream *)((mruby_to_native_ref *)DATA_PTR(boxed))->obj;
}
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */
