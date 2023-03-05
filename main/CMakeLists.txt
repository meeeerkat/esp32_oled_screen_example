set(srcs "main.c" "img_buffer/img_buffer.c")
set(include_dirs ".")

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS "${include_dirs}")
