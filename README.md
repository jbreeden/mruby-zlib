
mruby-zlib
----------

Bindings to ZLib for MRuby.

Usage
-----


### `compress` & `uncompress`

`compress` & `uncompress` provide a simple API for bulk compression. `compress`
produces a deflate stream wrapped in a zlib header, and `uncompress` reverses
that action.

Example:

```Ruby
src = 'test' * 10
# => "testtesttesttesttesttesttesttesttesttest"

src.length
# => 40

compressed = ZLib.compress(src)
# => "x\234+I-.)!\002\003\000f\261\021\201"

compressed.length
# => 15

ZLib.uncompress(src.length, compressed)
# => "testtesttesttesttesttesttesttesttesttest"
```

- `ZLib.compress(src)`
  + Compresses `src` with default settings & returns the compressed result.
  + Returns a deflate stream wrapped in a zlib header/footer

- `ZLib.uncompress(max_size, src)`
  + Uncompresses the src string (i.e. reverses `ZLib.compress`)
  + Raises a `ZLib::ZDataError` if src is not in the zlib format
  + Raises a `ZLib::ZBufferError` if `max_size` is not >= the size of the uncompressed data
  + Raises a `ZLib::ZDataError` if the input string is incomplete

### `inflate` & `deflate`

These functions provide a streaming interface for zlib & gzip compression.

Example:

```Ruby
src = "example" * 100

stream = ZLib::ZStream.new
ZLib.deflateInit(stream)
stream.next_in = src
compressed = ZLib.deflate(stream, ZLib::Z_FINISH)
# => "x\234K\255H\314-\310IM\035\245F\251\241F\001\000)h$@"

compressed.length
# => 22

stream = ZLib::ZStream.new
ZLib.inflateInit(stream)
stream.next_in = compressed
ZLib.inflate(stream, ZLib::Z_FINISH)
# => "exampleexampleexampleexampleexampleexampleexampleexampleexampleexample...
```

- `ZLib::deflateInit(stream, level = ZLib::Z_DEFAULT_COMPRESSION)`
  + Initalizes a stream to deflate at the given `level`
  + `level` defaults to 6 (ZLib::Z_DEFAULT_COMPRESSION)
  + Raises a `ZLib::ZStreamError` if called on a previously initialized stream

- `ZLib.deflate(stream, flush)`
  + Deflates all of `stream.next_in`, possibly returning a chunk of the compressed output
  + Will process the remaining input and return all output if `flush` is `ZLib::Z_FINISH`
  + Raises a ZBufferError if `Z_FINISH` is used twice
  + Raises a `ZLib::ZStreamError` if used on a stream that has been finished already

- `ZLib::inflateInit(stream)`
  + Initalizes a stream to inflate data
  + Raises a `ZLib::ZStreamError` if called on a previously initialized stream

- `ZLib.inflate(stream, flush)`
  + Inflates `str`, possibly returning a chunk of the uncompressed output
  + Returns the empty string if the stream has already been finished (TODO: should probably raise)
  + Will process the remaining input and return all output if `flush` is `ZLib::Z_FINISH`

- `ZLib.inflateEnd(stream)` && `ZLib.deflateEnd(stream)`
  + Are used to cleanup native resources of the stream
  + Called automatically by the MRuby GC when the stream is freed
  + Raise a `ZLib::ZStreamError` if the stream already ended, or is of the wrong type

### `GZFile` APIs

These functions provide IO for GZip files similar to C's stdlib `fopen`, `fread`, `fwrite`, etc.

- `ZLib.gzopen(filename, mode)`
  + Returns a `ZLib::GZFile` based on the given `filename` & `mode` string
  + Open semantics are like C's `fopen` ("w" create a file if it doesn't exist, etc.)
  + Returns `nil` if trying to read a file that doesn't exist

- `ZLib.gzwrite(file, str)`
  + Compresses `str`, then writes it to `file` (a `ZLib::GZFile`)

- `ZLib::gzread(file, size)`
  + Reads up to `size` uncompressed bytes from the compressed GZFile `file`

- `ZLib.gzflush(file, flush)`
  + Flushes the given file according to the `flush` argument
  + `flush` should be one of `ZLib::Z_NO_FLUSH`, `ZLib::Z_PARTIAL_FLUSH`,
    `ZLib::Z_SYNC_FLUSH`, `ZLib::Z_FULL_FLUSH`, or `ZLib::Z_FINISH`
  + Should be called on `GZFile`s when finished, to ensure the gz file has the proper footer

- `ZLib.gzclose(file)`
  + Closes the given GZFile `file`
  + Is called automatically when the file is GC'ed, but you may still call it sooner
  + After a file is closed, any attempt to use it will raise a `ZLib::ZIOError`

_The following functions marked [SKIPPED] are implemented already, but lacking automated tests._

- `ZLib.gzsetparams(file, level, strategy)`
  + [SKIPPED] Dynamically update the compression level or strategy

- `ZLib.gztell(file)`
  + [SKIPPED] Tells the currect seek position

- `ZLib.gzrewind(file)`
  + [SKIPPED] Seek to the begining of the file

- `ZLib.gzseek(file, offset, whence)`
  + [SKIPPED] Set the location for the next read/write

- `ZLib.gzputs(file, string)`
  + [SKIPPED] Writes the `string` param (which must not contain null characters) to the file

- `ZLib.gzputc(file, char)` (char should be an int as in `'a'.ord`)
  + [SKIPPED] Writes a character

- `ZLib.gzungetc(char, file)` (char should be an int as in `'a'.ord`)
  + [SKIPPED] Ungets a character

- `ZLib.gzbuffer(file, size)`
  + [SKIPPED] Set the internal buffer size used by this library's functions

- `ZLib.gzclearerr(file)`
  + [SKIPPED] Clears the error and end-of-file flags for file

- `ZLib.gzdirect(file)`
  + [SKIPPED] Returns true if file is being copied directly while reading, or false if file is a gzip stream being decompressed

- `ZLib.gzdopen(fd, mode)`
  + [SKIPPED] gzdopen associates a gzFile * with the file descriptor fd.

- `ZLib.gzeof(file)`
  + [SKIPPED] Returns true if the file is at eof, or else false

- `ZLib.gzerror(file)`
  + [SKIPPED] Returns the error message for the last error which occurred on the given compressed file

- `ZLib.gzgetc`
  + [SKIPPED] Reads one byte from the compressed file.
  + [SKIPPED] Returns the byte (as an int) or -1 in case of end of file or error.

- `ZLib.gzoffset`
  + [SKIPPED] Returns the current offset in the file being read or written
  + [SKIPPED] When reading, the offset does not include as yet unused buffered input
  + [SKIPPED] This information can be used for a progress indicator

- `ZLib.gzgets(file)`
  + [SKIPPED] Reads until a newline or eof


SUCCESS [0 failed, 19 skipped, 51 total]
