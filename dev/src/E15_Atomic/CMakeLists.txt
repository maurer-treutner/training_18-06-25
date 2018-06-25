set(TARGETNAME "Atomic")

add_executable(${TARGETNAME}
    src/Atomic.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})