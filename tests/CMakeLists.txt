set(targets "cuckootest" "cuckootest2")

foreach (target ${targets})
    set(Source_Files "${target}.c")
    source_group("${target} Source Files" FILES "${Source_Files}")

    add_executable("${target}" "${Source_Files}")
    target_link_libraries("${target}" PRIVATE "${PROJECT_NAME}")
    set_target_properties(
        "${target}"
        PROPERTIES
        LINKER_LANGUAGE
        C
    )
endforeach ()

# install rules
set(installable_libs "${PROJECT_NAME}_compiler_flags")

if (TARGET "${DEPENDANT_LIBRARY}")
    list(APPEND installable_libs "${DEPENDANT_LIBRARY}")
endif ()
install(TARGETS ${installable_libs} ${targets}
        DESTINATION "bin"
        EXPORT "${EXEC_NAME}Targets")
