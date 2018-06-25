TARGET ?= armhf
PROJECT_DIR := $(CURDIR)/..
#
# Define variables for project build in dev/
#
SOURCE_DIR := $(CURDIR)/src
BUILD_DIR_ROOT := $(CURDIR)/build
BUILD_DIR_HOST := $(BUILD_DIR_ROOT)/host
BUILD_DIR_HOST_DEBUG := $(BUILD_DIR_ROOT)/host_debug

#
# Define target dirs for make install
#
PREFIX_DIR_ROOT ?= $(CURDIR)/prefix
PREFIX_DIR_HOST := $(PREFIX_DIR_ROOT)/host
PREFIX_DIR_HOST_DEBUG := $(PREFIX_DIR_ROOT)/host_debug


#
# Define GENERATOR for CMake
#
GENERATOR := "Unix Makefiles"


#
# CMAKE Flags common for all targets
#
COMMON_CMAKE_FLAGS := -G $(GENERATOR) $(DEBUG_FLAGS)

#
# CMAKE Flags relevant for all host targets
#
HOST_CMAKE_FLAGS := -DEXT_DIR_PREFIX=$(EXT_DIR_PREFIX_HOST) \
	-DCMAKE_DEBUG_POSTFIX="d"

#
# CMake flags for the different targets
# 
HOST_CMAKE_FLAGS_RELEASE := $(HOST_CMAKE_FLAGS) \
	-DCMAKE_BUILD_TYPE=RELEASE \
	-DCMAKE_INSTALL_PREFIX=$(PREFIX_DIR_HOST)


HOST_CMAKE_FLAGS_DEBUG := $(HOST_CMAKE_FLAGS) \
	-DCMAKE_BUILD_TYPE=DEBUG \
	-DCMAKE_INSTALL_PREFIX=$(PREFIX_DIR_HOST_DEBUG)

# 
# Vebose output switched on with 'make VERBOSE=1'
#
VERBOSE ?= 
ifeq ($(VERBOSE),1)
    Q:=
else
	Q:=@
endif

#
# Targets for C++ build
#

all: host host_debug

host: 
	$(Q)mkdir -p $(BUILD_DIR_HOST)
	$(Q)cd ${BUILD_DIR_HOST} && cmake ${COMMON_CMAKE_FLAGS} ${HOST_CMAKE_FLAGS_RELEASE} ${SOURCE_DIR}
	$(Q)make -C ${BUILD_DIR_HOST} VERBOSE=${VERBOSE}

host_debug: 
	$(Q)mkdir -p $(BUILD_DIR_HOST_DEBUG)
	$(Q)cd ${BUILD_DIR_HOST_DEBUG} && cmake ${COMMON_CMAKE_FLAGS} ${HOST_CMAKE_FLAGS_DEBUG} ${SOURCE_DIR}
	$(Q)make -C ${BUILD_DIR_HOST_DEBUG} VERBOSE=${VERBOSE}

clean:
	$(Q)make -C ${BUILD_DIR_HOST} clean

purge:
	$(Q)rm -rf ${BUILD_DIR_ROOT}

help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all            : make release version for target and host"
	@echo "... host		      : make release version for host"
	@echo "... host_debug     : make debug version for target"
	@echo "... clean          : call make clean for cmake generated make files (release)"
	@echo "... purge          : delete all generated directories for project"

