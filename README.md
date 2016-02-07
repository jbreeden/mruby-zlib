
ZLib
----

Binding to ZLib for MRuby.

Usage
-----


- `ZLib.compress(src)`
  + Compresses `src` with default settings & returns the compressed result.
  + [SKIPPED] Returns a deflate stream wrapped in a zlib header/footer

- `ZLib.uncompress(max_size, src)`
  + Uncompresses the src string (i.e. reverses `ZLib.compress`)
  + Raises a `ZLib::ZDataError` if src is not in the zlib format
  + Raises a `ZLib::ZBufferError` if `max_size` is not >= the size of the uncompressed data
  + Raises a `ZLib::ZDataError` if the input string is incomplete

- `ZLib.gzopen(filename, mode)`
  + Returns a `ZLib::GZFile` based on the given `filename` & `mode` string
  + Open semantics are like C's `fopen` ("w" create a file if it doesn't exist, etc.)
  + Returns `nil` if trying to read a file that doesn't exist

- `ZLib.gzwrite(file, str)`
  + Compresses `str`, then writes it to `file` (a `ZLib::GZFile`)

- `ZLib::gzread(file, size)`
  + Reads up to `size` uncompressed bytes from the compressed GZFile `file`

- ZLib.gzflush(file, flush)
  + Flushes the given file according to the `flush` argument
  + `flush` should be one of `ZLib::Z_NO_FLUSH`, `ZLib::Z_PARTIAL_FLUSH`, `ZLib::Z_SYNC_FLUSH`, `ZLib::Z_FULL_FLUSH`, or `ZLib::Z_FINISH`
  + Should be called on `GZFile`s when finished, to ensure the gz file has the proper footer


SUCCESS [0 failed, 1 skipped, 14 total]
