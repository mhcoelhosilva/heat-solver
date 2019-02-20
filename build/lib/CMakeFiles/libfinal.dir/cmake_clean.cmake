file(REMOVE_RECURSE
  "liblibfinal.pdb"
  "liblibfinal.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/libfinal.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
