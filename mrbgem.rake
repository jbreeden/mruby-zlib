MRUBY_ZLIB_GEM_DIR = File.dirname(__FILE__)

MRuby::Gem::Specification.new('mruby-zlib') do |spec|
  spec.author = 'Jared Breeden'
  spec.license = 'MIT'
  spec.summary = 'Bindings for ZLib'

  spec.linker.libraries << 'z'
end
