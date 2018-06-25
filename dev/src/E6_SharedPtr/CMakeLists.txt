set(TARGETNAME "E6_SharedPtr")

add_executable(${TARGETNAME}
    src/SharedPtr.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})