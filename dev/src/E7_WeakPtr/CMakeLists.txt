set(TARGETNAME "E7_WeakPtr")

add_executable(${TARGETNAME}
    src/WeakPtr.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})