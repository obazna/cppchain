project(lib C CXX)

# Use fmtlib for formatting
add_subdirectory(fmt EXCLUDE_FROM_ALL)

# Use spdlog for logging, and tell it to use our version of fmtlib
add_subdirectory(spdlog EXCLUDE_FROM_ALL)
target_compile_definitions(spdlog INTERFACE SPDLOG_FMT_EXTERNAL)