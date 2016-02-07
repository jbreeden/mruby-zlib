#ifndef MRUBY_ZLib_BOXING_HEADER
#define MRUBY_ZLib_BOXING_HEADER

/* MRUBY_BINDING: header */
/* sha: user_defined */

/* MRUBY_BINDING_END */


/*
 * Boxing declarations
 * -------------------
 *
 * These declarations are enabled by the macros in mruby_ZLib_classes.h
 */

/*
* Extra wrapper over native pointer to indicate who owns this memory.
* Owner is mruby (it should be garage collected) or C (it shouldn't be).
*/
typedef struct mruby_to_native_ref_ {
  /* If true, indicates that the object should be freed when
   * mruby garbage collects the ruby object containing this pointer.
   * This is set to true when an object is boxed via the `giftwrap`
   * or `gift_{type}_ptr_set` functions.
   */
  unsigned char belongs_to_ruby;

  /* A pointer to the native object */
  void* obj;

  /* For the convenience of the binding writer,
   * the data pointer can be used to associate arbitrary
   * data with a reference to a C object.
   * 
   * Possible uses:
   * - A function pointer to invoke instead of `free` on GC.
   * - A pointer back to the RObject, to be accessed during GC.
   * - etc.
   */
  void* data;
} mruby_to_native_ref;

/* MRUBY_BINDING: GzFile::boxing_decls */
/* sha: 158aab2e661485b843761756d667ea9c02df0b0f976d55c6c2da91929887dff5 */
#if BIND_GzFile_TYPE
mrb_value
mruby_box_gzFile(mrb_state* mrb, gzFile *unboxed);

mrb_value
mruby_giftwrap_gzFile(mrb_state* mrb, gzFile *unboxed);

void
mruby_set_gzFile_data_ptr(mrb_value obj, gzFile *unboxed);

void
mruby_gift_gzFile_data_ptr(mrb_value obj, gzFile *unboxed);

gzFile *
mruby_unbox_gzFile(mrb_value boxed);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzFileS::boxing_decls */
/* sha: 0be37b5071868519d2ecc86360dd095ef32ab18426593e38413af0c705e0305a */
#if BIND_GzFileS_TYPE
mrb_value
mruby_box_gzFile_s(mrb_state* mrb, gzFile unboxed);

mrb_value
mruby_giftwrap_gzFile_s(mrb_state* mrb, gzFile unboxed);

void
mruby_set_gzFile_s_data_ptr(mrb_value obj, gzFile unboxed);

void
mruby_gift_gzFile_s_data_ptr(mrb_value obj, gzFile unboxed);

gzFile
mruby_unbox_gzFile_s(mrb_value boxed);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GzHeader::boxing_decls */
/* sha: db4abe5b95cbb92d4ee0a3b36ac61adad32757d63047d73968c81892e773334c */
#if BIND_GzHeader_TYPE
mrb_value
mruby_box_gz_header(mrb_state* mrb, gz_header *unboxed);

mrb_value
mruby_giftwrap_gz_header(mrb_state* mrb, gz_header *unboxed);

void
mruby_set_gz_header_data_ptr(mrb_value obj, gz_header *unboxed);

void
mruby_gift_gz_header_data_ptr(mrb_value obj, gz_header *unboxed);

gz_header *
mruby_unbox_gz_header(mrb_value boxed);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: InternalState::boxing_decls */
/* sha: 9d7e1276dfbe52056edac9339d7f65ba2e6c803a510416fd92042f542f1143e6 */
#if BIND_InternalState_TYPE
mrb_value
mruby_box_internal_state(mrb_state* mrb, struct internal_state *unboxed);

mrb_value
mruby_giftwrap_internal_state(mrb_state* mrb, struct internal_state *unboxed);

void
mruby_set_internal_state_data_ptr(mrb_value obj, struct internal_state *unboxed);

void
mruby_gift_internal_state_data_ptr(mrb_value obj, struct internal_state *unboxed);

struct internal_state *
mruby_unbox_internal_state(mrb_value boxed);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: ZStream::boxing_decls */
/* sha: 67336eb48641c33aba509b5b5940690bbe19affec47837a82285e27905cdb52c */
#if BIND_ZStream_TYPE
mrb_value
mruby_box_z_stream(mrb_state* mrb, z_stream *unboxed);

mrb_value
mruby_giftwrap_z_stream(mrb_state* mrb, z_stream *unboxed);

void
mruby_set_z_stream_data_ptr(mrb_value obj, z_stream *unboxed);

void
mruby_gift_z_stream_data_ptr(mrb_value obj, z_stream *unboxed);

z_stream *
mruby_unbox_z_stream(mrb_value boxed);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: footer */
/* sha: user_defined */

/* MRUBY_BINDING_END */

#endif
