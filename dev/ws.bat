command "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
cd "ws"
cmake  ../src -DCMAKE_INSTALL_PREFIX="../prefix" -DBOOST_ROOT="C:/Program Files/boost/boost_1_66_0"
cd ..
