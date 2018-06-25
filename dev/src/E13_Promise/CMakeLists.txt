set(TARGETNAME "Promise")

add_executable(${TARGETNAME}
    src/Promise.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})