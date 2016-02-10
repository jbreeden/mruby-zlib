$src = 'test' * 1000

=begin
You will notice that some of the "specs" here have empty bodies, while some have
no body at all. If a spec has no body, it is reported as skipped. This is a clue
to me that I want to come back and fill in tests. Tests with empty bodies are
not reported as skipped. This should only be done when the spec describes something
that is already tested *in another test*. This way the output doesn't imply
the feature isn't tested, when it is.

TODO: Provide a switch to ignore documentation-only output for test runs.
      (If the doc output looks like a passing test, it confuses your reasoning about the bug)
TODO: Provide a way to "silence" test-only output for documentation generation.
      (Maybe useful for seriously obscure test cases, but mainly as a dual for the above.)
=end

ZLib::Spec.new("mruby-zlib") do
  blurb <<-EOS
Bindings to ZLib for MRuby.

Usage
-----

EOS

blurb <<-EOS
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
# => "x\\234+I-.)!\\002\\003\\000f\\261\\021\\201"

compressed.length
# => 15

ZLib.uncompress(src.length, compressed)
# => "testtesttesttesttesttesttesttesttesttest"
```
EOS
  
  desc '`ZLib.compress(src)`' do
    it 'Compresses `src` with default settings & returns the compressed result.' do
      assert(ZLib.compress($src).length < 100)
    end
    
    # Documentation only
    it "Returns a deflate stream wrapped in a zlib header/footer" do
    end
  end
  
  desc '`ZLib.uncompress(max_size, src)`' do
    it 'Uncompresses the src string (i.e. reverses `ZLib.compress`)' do
      assert ZLib.uncompress($src.length, ZLib.compress($src)) == $src
    end
    
    it 'Raises a `ZLib::ZDataError` if src is not in the zlib format' do
      assert_raises(ZLib::ZDataError) { ZLib.uncompress(100, 'test') }
    end
    
    it 'Raises a `ZLib::ZBufferError` if `max_size` is not >= the size of the uncompressed data' do
      assert_raises(ZLib::ZBufferError) { ZLib.uncompress(5, ZLib.compress($src)) }
    end
    
    it 'Raises a `ZLib::ZDataError` if the input string is incomplete' do
      input = ZLib.compress($src)
      input = input[0..(input.length - 5)]
      assert_raises(ZLib::ZDataError) { ZLib.uncompress($src.length, input) }
    end
  end

blurb <<-EOS
### `inflate` & `deflate`

These functions provide a streaming interface for zlib & gzip compression.

Example:

```Ruby
src = "example" * 100

stream = ZLib::ZStream.new
ZLib.deflateInit(stream)
stream.next_in = src
compressed = ZLib.deflate(stream, ZLib::Z_FINISH)
# => "x\\234K\\255H\\314-\\310IM\\035\\245F\\251\\241F\\001\\000)h$@"

compressed.length
# => 22

stream = ZLib::ZStream.new
ZLib.inflateInit(stream)
stream.next_in = compressed
ZLib.inflate(stream, ZLib::Z_FINISH)
# => "exampleexampleexampleexampleexampleexampleexampleexampleexampleexample...
```
EOS

  desc '`ZLib::deflateInit(stream, level = ZLib::Z_DEFAULT_COMPRESSION)`' do
    it 'Initalizes a stream to deflate at the given `level`' do
    end
  
    it '`level` defaults to 6 (ZLib::Z_DEFAULT_COMPRESSION)' do
    end
    
    it 'Raises a `ZLib::ZStreamError` if called on a previously initialized stream' do
      s = ZLib::ZStream.new
      ZLib.deflateInit(s)
      assert_raises(ZLib::ZStreamError) { ZLib.deflateInit(s) }
    end
  end
  
  desc '`ZLib.deflate(stream, flush)`' do
    it 'Deflates all of `stream.next_in`, possibly returning a chunk of the compressed output' do
      s = ZLib::ZStream.new
      ZLib.deflateInit(s)
      s.next_in = $src
      out = ZLib.deflate(s, ZLib::Z_FINISH)
      
      t = ZLib::ZStream.new
      ZLib.inflateInit(t)
      t.next_in = out
      inflated = ZLib.inflate(t, ZLib::Z_FINISH)
      assert inflated == $src
    end
    
    it 'Will process the remaining input and return all output if `flush` is `ZLib::Z_FINISH`' do
    end
        
    it 'Raises a ZBufferError if `Z_FINISH` is used twice' do
      assert_raises(ZLib::ZBufferError) do
        s = ZLib::ZStream.new
        ZLib.deflateInit(s)
        out = ''
        (1..2).each do |i|
          s.next_in = "test#{i}"
          out << ZLib.deflate(s, ZLib::Z_FINISH)
        end
      end
    end
    
    it 'Raises a `ZLib::ZStreamError` if used on a stream that has been finished already' do
      assert_raises(ZLib::ZStreamError) do
        s = ZLib::ZStream.new
        ZLib.deflateInit(s)
        s.next_in = "test1"
        ZLib.deflate(s, ZLib::Z_FINISH)
        s.next_in = "test2"
        ZLib.deflate(s)
      end
    end
  end
  
  desc '`ZLib::inflateInit(stream)`' do
    it 'Initalizes a stream to inflate data' do
    end
    
    it 'Raises a `ZLib::ZStreamError` if called on a previously initialized stream' do
      s = ZLib::ZStream.new
      ZLib.inflateInit(s)
      assert_raises(ZLib::ZStreamError) { ZLib.inflateInit(s) }
    end
  end
  
  desc '`ZLib.inflate(stream, flush)`' do
    it 'Inflates `str`, possibly returning a chunk of the uncompressed output' do
      s = ZLib::ZStream.new
      ZLib.deflateInit(s)
      out = ''
      (1..9).each do |i|
        s.next_in = "test#{i}"
        out << ZLib.deflate(s)
      end
      out << ZLib.deflate(s, ZLib::Z_FINISH)
      
      t = ZLib::ZStream.new
      ZLib.inflateInit(t)
      t.next_in = out
      inflated = ZLib.inflate(t, ZLib::Z_FINISH)
      assert inflated == ("test1".."test9").to_a.join('')
    end

    it 'Returns the empty string if the stream has already been finished (TODO: should probably raise)' do
      s = ZLib::ZStream.new
      ZLib.deflateInit(s)
      out = ''
      s.next_in = $src
      out << ZLib.deflate(s, ZLib::Z_FINISH)
      
      t = ZLib::ZStream.new
      ZLib.inflateInit(t)
      t.next_in = out[0..100]
      inflated = ZLib.inflate(t, ZLib::Z_FINISH)
      t.next_in = out[101..(out.length)]
      inflated = ZLib.inflate(t, ZLib::Z_FINISH)
      assert inflated == ''
    end
    
    it 'Will process the remaining input and return all output if `flush` is `ZLib::Z_FINISH`' do
    end
  end
  
  desc '`ZLib.inflateEnd(stream)` && `ZLib.deflateEnd(stream)`' do
    it 'Are used to cleanup native resources of the stream' do
    end
    
    it 'Called automatically by the MRuby GC when the stream is freed' do
    end
    
    it 'Raise a `ZLib::ZStreamError` if the stream already ended, or is of the wrong type' do
      s = ZLib::ZStream.new
      ZLib.deflateInit(s)
      out = ''
      s.next_in = $src
      out << ZLib.deflate(s, ZLib::Z_FINISH)
      ZLib.deflateEnd(s)
      assert_raises(ZLib::ZStreamError) { ZLib.deflateEnd(s) }
      assert_raises(ZLib::ZStreamError) { ZLib.inflateEnd(s) }
      
      t = ZLib::ZStream.new
      ZLib.inflateInit(t)
      t.next_in = out[0..100]
      inflated = ZLib.inflate(t, ZLib::Z_FINISH)
      t.next_in = out[101..(out.length)]
      inflated = ZLib.inflate(t, ZLib::Z_FINISH)
      ZLib.inflateEnd(t)
      assert_raises(ZLib::ZStreamError) { ZLib.inflateEnd(t) }
      assert_raises(ZLib::ZStreamError) { ZLib.deflateEnd(t) }
    end
  end
  
blurb <<-EOS
### `GZFile` APIs

These functions provide IO for GZip files similar to C's stdlib `fopen`, `fread`, `fwrite`, etc.
EOS

  desc '`ZLib.gzopen(filename, mode)`' do
    it 'Returns a `ZLib::GZFile` based on the given `filename` & `mode` string' do
      f = ZLib.gzopen('delete_me.gz', 'w')
      assert f.class == ZLib::GZFile
      File.delete('delete_me.gz')
    end
    
    it 'Open semantics are like C\'s `fopen` ("w" create a file if it doesn\'t exist, etc.)' do
    end
    
    it 'Returns `nil` if trying to read a file that doesn\'t exist' do
      assert ZLib.gzopen('dnednednednednedne.gzip', 'r').nil?
    end
  end
  
  desc '`ZLib.gzwrite(file, str)`' do
    it 'Compresses `str`, then writes it to `file` (a `ZLib::GZFile`)' do
      f = ZLib.gzopen('gzwrite.gz', 'w')
      assert(!f.nil?)
      ZLib.gzwrite(f, $src)
      ZLib.gzflush(f, ZLib::Z_FINISH)
      ZLib.gzwrite(f, $src)
      ZLib.gzclose(f)
      
      f = ZLib.gzopen('gzwrite.gz', 'r')
      content = ZLib.gzread(f, 10000)
      assert content == ($src * 2)
      File.delete('gzwrite.gz')
    end
  end
  
  desc '`ZLib::gzread(file, size)`' do
    it 'Reads up to `size` uncompressed bytes from the compressed GZFile `file`' do
      # Tested in ZLib.gzwrite test above
    end
  end
  
  desc '`ZLib.gzflush(file, flush)`' do
    # Tested in ZLib.gzwrite test above
    
    it 'Flushes the given file according to the `flush` argument' do
    end
    
    it "`flush` should be one of `ZLib::Z_NO_FLUSH`, `ZLib::Z_PARTIAL_FLUSH`,\n  `ZLib::Z_SYNC_FLUSH`, `ZLib::Z_FULL_FLUSH`, or `ZLib::Z_FINISH`" do
    end
    
    it 'Should be called on `GZFile`s when finished, to ensure the gz file has the proper footer' do
    end
  end
  
  desc '`ZLib.gzclose(file)`' do
    # Tested in ZLib.gzwrite test above
    
    it 'Closes the given GZFile `file`' do
      # Covered in the "write after close" test
    end
    
    it 'Is called automatically when the file is GC\'ed, but you may still call it sooner' do
    end
    
    it 'After a file is closed, any attempt to use it will raise a `ZLib::ZIOError`' do
      f = ZLib.gzopen('gzwrite.gz', 'w')
      assert(!f.nil?)      
      ZLib.gzclose(f)

      assert_raises(ZLib::ZIOError) { ZLib.gzclose(f) }
      assert_raises(ZLib::ZIOError) { ZLib.gzwrite(f, 'x' * 16) }
      assert_raises(ZLib::ZIOError) { ZLib.gzflush(f, ZLib::Z_FINISH) }
      assert_raises(ZLib::ZIOError) { ZLib.gzgetc(f) }
      assert_raises(ZLib::ZIOError) { ZLib.gzungetc('c'.ord, f) }
      
      File.delete('gzwrite.gz')
    end
  end
  
blurb <<-EOS
_The following functions marked [SKIPPED] are implemented already, but lacking automated tests._
EOS
  
  desc "`ZLib.gzsetparams(file, level, strategy)`" do
    it 'Dynamically update the compression level or strategy'
  end
  
  desc "`ZLib.gztell(file)`" do
    it 'Tells the currect seek position'
  end
  
  desc "`ZLib.gzrewind(file)`" do
    it 'Seek to the begining of the file'
  end
  
  desc "`ZLib.gzseek(file, offset, whence)`" do
    it 'Set the location for the next read/write'
  end
  
  desc "`ZLib.gzputs(file, string)`" do
    it 'Writes the `string` param (which must not contain null characters) to the file'
  end
  
  desc "`ZLib.gzputc(file, char)` (char should be an int as in `'a'.ord`)" do
    it 'Writes a character'
  end
  
  desc "`ZLib.gzungetc(char, file)` (char should be an int as in `'a'.ord`)" do
    it 'Ungets a character'
  end
  
  desc "`ZLib.gzbuffer(file, size)`" do
    it 'Set the internal buffer size used by this library\'s functions'
  end
  
  desc "`ZLib.gzclearerr(file)`" do
    it 'Clears the error and end-of-file flags for file'
  end
  
  desc "`ZLib.gzdirect(file)`" do
    it 'Returns true if file is being copied directly while reading, or false if file is a gzip stream being decompressed'
  end
  
  ## Don't document these. They're useless from MRuby (just use `gzclose`)
  # desc "`ZLib.gzclose_w`" do
  #   it 'Is bound'
  # end
  # 
  # desc "`ZLib.gzclose_r`" do
  #   it 'Is bound'
  # end
  
  desc "`ZLib.gzdopen(fd, mode)`" do
    it 'gzdopen associates a gzFile * with the file descriptor fd.'
  end
  
  desc "`ZLib.gzeof(file)`" do
    it 'Returns true if the file is at eof, or else false'
  end
  
  desc "`ZLib.gzerror(file)`" do
    it 'Returns the error message for the last error which occurred on the given compressed file'
  end
  
  desc "`ZLib.gzgetc`" do
    it 'Reads one byte from the compressed file.'
    it 'Returns the byte (as an int) or -1 in case of end of file or error.'
  end
  
  desc "`ZLib.gzoffset`" do
    it 'Returns the current offset in the file being read or written'
    it 'When reading, the offset does not include as yet unused buffered input'
    it 'This information can be used for a progress indicator'
  end
  
  desc "`ZLib.gzgets(file)`" do
    it 'Reads until a newline or eof'
  end
end
