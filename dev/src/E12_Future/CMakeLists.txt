set(TARGETNAME "Future")

add_executable(${TARGETNAME}
    src/Future.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})