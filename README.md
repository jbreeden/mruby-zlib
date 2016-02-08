
ZLib
----

Binding to ZLib for MRuby.

Usage
-----


### Compress & Uncompress

`compress` & `uncompress` provide a simple API for bulk compression. `compress`
produces a deflate stream wrapped in a zlib header, and `uncompress` reverses
that action.

- `ZLib.compress(src)`
  + Compresses `src` with default settings & returns the compressed result.
  + Returns a deflate stream wrapped in a zlib header/footer

- `ZLib.uncompress(max_size, src)`
  + Uncompresses the src string (i.e. reverses `ZLib.compress`)
  + Raises a `ZLib::ZDataError` if src is not in the zlib format
  + Raises a `ZLib::ZBufferError` if `max_size` is not >= the size of the uncompressed data
  + Raises a `ZLib::ZDataError` if the input string is incomplete

### GZFile APIs

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
  + After a file is closed, write & flush still appear to work (no exceptions), but have no affect

### `inflate` & `deflate`

These functions provide a streaming interface for zlib & gzip compression.

- `ZLib::deflateInit(stream, level = ZLib::Z_DEFAULT_COMPRESSION)`
  + Initalizes a stream to deflate at the given `level`
  + `level` defaults to 6 (ZLib::Z_DEFAULT_COMPRESSION)

- `ZLib.deflate(stream, flush)`
  + Deflates all of `stream.next_in`, possibly returning a chunk of the compressed output

- `ZLib.inflate(stream, str)`
  + Inflates `str`, possibly returning a chunk of the uncompressed output


SUCCESS [0 failed, 0 skipped, 20 total]
