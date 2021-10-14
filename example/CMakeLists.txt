set(EXEC_NAME "cuckoofilter_example")

set(Source_Files
        "example.c"
)
source_group("Source Files" FILES "${Source_Files}")

add_executable("${EXEC_NAME}" "${Source_Files}")
target_link_libraries("${EXEC_NAME}" PRIVATE "${PROJECT_NAME}")
set_target_properties(
        "${EXEC_NAME}"
        PROPERTIES
        LINKER_LANGUAGE
        C
)

# install rules
set(installable_libs "${EXEC_NAME}" "${PROJECT_NAME}_compiler_flags")

if (TARGET "${DEPENDANT_LIBRARY}")
    list(APPEND installable_libs "${DEPENDANT_LIBRARY}")
endif ()
install(TARGETS ${installable_libs}
        DESTINATION "bin"
        EXPORT "${EXEC_NAME}Targets")
