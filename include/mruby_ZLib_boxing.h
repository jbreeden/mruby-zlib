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

/* MRUBY_BINDING: GZFile::boxing_decls */
/* sha: d6bcf076df63aa68840dd96e2e9ae4c7a0b1b8d7c26ccde6b4b53120a7a21918 */
#if BIND_GZFile_TYPE
mrb_value
mruby_box_gzFile(mrb_state* mrb, gzFile unboxed);

mrb_value
mruby_giftwrap_gzFile(mrb_state* mrb, gzFile unboxed);

void
mruby_set_gzFile_data_ptr(mrb_value obj, gzFile unboxed);

void
mruby_gift_gzFile_data_ptr(mrb_value obj, gzFile unboxed);

gzFile
mruby_unbox_gzFile(mrb_value boxed);
#endif
/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZFileS::boxing_decls */
/* sha: 29c4bbba1a6b8a1f5015487ccad849a85d3b6ece91ba7a7e5f7ef047e274a751 */

/*** DELETED ***/

/* MRUBY_BINDING_END */

/* MRUBY_BINDING: GZHeader::boxing_decls */
/* sha: b933abe15adda3429bdc46a23d4b0a24e4adf3047796781158138d2a17ea0100 */
#if BIND_GZHeader_TYPE
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
