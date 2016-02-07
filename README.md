
ZLib
----

- `ZLib.compress(src)`
  + Compresses `src` with default settings & returns the compressed result.
  + [SKIPPED] Returns a deflate stream wrapped in a zlib header/footer

- `ZLib.uncompress(max_size, src)`
  + Uncompresses the src string (i.e. reverses `ZLib.compress`)
  + Raises a ZLib::ZDataError if src is not in the zlib format
  + Raises a ZLib::ZBufferError if max_size is not >= the size of the uncompressed data
  + Raises a ZLib::ZDataError if the input string is incomplete


SUCCESS [0 failed, 1 skipped, 6 total]
