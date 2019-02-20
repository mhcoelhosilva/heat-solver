add_library(libfinal STATIC cg.hpp heat.hpp matrix.hpp vector.hpp)
set_target_properties(libfinal PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS libfinal DESTINATION lib)
install(FILES cg.hpp heat.hpp matrix.hpp vector.hpp DESTINATION lib)