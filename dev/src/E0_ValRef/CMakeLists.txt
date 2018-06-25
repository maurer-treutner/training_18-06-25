set(TARGETNAME "ValRef")

add_executable(${TARGETNAME}
    src/${TARGETNAME}.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})