command "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
cd "build"
cmake ..\src -G "NMake Makefiles" -DCMAKE_CXX_COMPILER="cl.exe" -DCMAKE_BUILD_TYPE="Release" -DCMAKE_INSTALL_PREFIX="../prefix" -DBOOST_ROOT="C:/Program Files/boost/boost_1_66_0"
NMake
NMake install
cd ..
