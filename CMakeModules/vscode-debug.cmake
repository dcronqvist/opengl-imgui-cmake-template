function(urlencode input output_variable)
  string(HEX "${input}" hex)
  string(LENGTH "${hex}" length)
  math(EXPR last "${length} - 1")
  set(result "")
  foreach(i RANGE ${last})
    math(EXPR even "${i} % 2")
    if("${even}" STREQUAL "0")
      string(SUBSTRING "${hex}" "${i}" 2 char)
      string(APPEND result "%${char}")
    endif()
  endforeach()
  set("${output_variable}" ${result} PARENT_SCOPE)
endfunction()

# This function creates a custom target called vscode_debug_${target} that will launch the debugger in VSCode when run
function(make_target_debuggable_in_vscode target)
  set(TARGET_OUT "${CMAKE_CURRENT_BINARY_DIR}/${target}${CMAKE_EXECUTABLE_SUFFIX}")
  set(VSCODE_DEBUG_ARGS 
    "{\"type\":\"cppvsdbg\",\"request\":\"launch\",\"program\":\"${TARGET_OUT}\",\"cwd\":\"${CMAKE_CURRENT_LIST_DIR}\",\"just_my_code\":false,\"args\":[]}"
  )
  urlencode("${VSCODE_DEBUG_ARGS}" VSCODE_DEBUG_ARGS_ENCODED)

  find_program(POWERSHELL_PATH NAMES pwsh)
  add_custom_target(vscode_debug_${target}
    COMMAND ${POWERSHELL_PATH} -C Start-Process "vscode-insiders://fabiospampinato.vscode-debug-launcher/launch?args=${VSCODE_DEBUG_ARGS_ENCODED}"
    DEPENDS ${target}
  )
endfunction()
