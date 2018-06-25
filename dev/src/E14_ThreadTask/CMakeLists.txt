set(TARGETNAME "ThreadTask")

add_executable(${TARGETNAME}
    src/ThreadTask.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

install_targets(/exe ${TARGETNAME})