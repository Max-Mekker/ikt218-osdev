set(OS_MODULE_IO_KEYBOARD_NAME ${OS_KERNEL_NAME}-module-keyboard)
set(OS_MODULE_IO_KEYBOARD_SOURCES
        keyboard/keyboard.cpp

)

add_library(${OS_MODULE_IO_KEYBOARD_NAME} ${OS_MODULE_IO_KEYBOARD_SOURCES})
target_link_libraries(${OS_MODULE_IO_KEYBOARD_NAME} PUBLIC ${OS_LIBRARIES})
target_include_directories(${OS_MODULE_IO_KEYBOARD_NAME}
        PUBLIC .
)

set(OS_LIBRARIES ${OS_LIBRARIES} PARENT_SCOPE)