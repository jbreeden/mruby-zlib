$src = 'test' * 1000

ZLib::Spec.new("ZLib") do
  blurb <<-EOS
Binding to ZLib for MRuby.

Usage
-----

EOS

blurb <<-EOS
### Compress & Uncompress

`compress` & `uncompress` provide a simple API for bulk compression. `compress`
produces a deflate stream wrapped in a zlib header, and `uncompress` reverses
that action.
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
### GZFile APIs

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
      assert ZLib.gzopen('dne.gzip', 'r').nil?
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
    
    it 'After a file is closed, write & flush still appear to work (no exceptions), but have no affect' do
      f = ZLib.gzopen('gzwrite.gz', 'w')
      assert(!f.nil?)
      ZLib.gzwrite(f, $src)
      ZLib.gzclose(f)
      
      assert 16 == ZLib.gzwrite(f, 'x' * 16)
      assert 16 == ZLib.gzwrite(f, 'x' * 16)
      assert 16 == ZLib.gzwrite(f, 'x' * 16)
      assert 16 == ZLib.gzwrite(f, 'x' * 16)
      ZLib.gzflush(f, ZLib::Z_FINISH)
      
      f = ZLib.gzopen('gzwrite.gz', 'r')
      content = ZLib.gzread(f, 10000)
      assert content == $src
      File.delete('gzwrite.gz')
    end
  end
end
