set(TARGETNAME "Lambda")

add_executable(${TARGETNAME}
    src/Lambda.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})