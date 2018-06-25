set(TARGETNAME "UniquePtr")

add_executable(${TARGETNAME}
    src/UniquePtr.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})