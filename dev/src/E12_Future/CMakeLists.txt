set(TARGETNAME "Future")

add_executable(${TARGETNAME}
    src/Future.cpp
)

target_compile_features(${TARGETNAME}
    PRIVATE
    cxx_std_14  
)

target_link_libraries(${TARGETNAME}
    pthread
)

install_targets(/exe ${TARGETNAME})