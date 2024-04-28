# Inputs
CXX ?= clang++
AR ?= llvm-ar


INCLUDEDIR := include
BUILDDIR := build
SRCDIR := src
OBJS :=\
  $(BUILDDIR)/camera2d.o                \
  $(BUILDDIR)/camera3d.o                \
  $(BUILDDIR)/circle.o                  \
  $(BUILDDIR)/collision.o               \
  $(BUILDDIR)/color.o                   \
  $(BUILDDIR)/draw.o                    \
  $(BUILDDIR)/keyboard.o                \
  $(BUILDDIR)/line.o                    \
  $(BUILDDIR)/math.o                    \
  $(BUILDDIR)/mouse.o                   \
  $(BUILDDIR)/rlgl.o                    \
  $(BUILDDIR)/rectangle.o               \
  $(BUILDDIR)/rendertexture.o           \
  $(BUILDDIR)/shader.o                  \
  $(BUILDDIR)/texture.o                 \
  $(BUILDDIR)/triangle.o                \
  $(BUILDDIR)/window.o


MADLIB_RUNTIME_HEADERS_PATH := "$(shell madlib config runtime-headers-path)"
MADLIB_RUNTIME_LIB_HEADERS_PATH := "$(shell madlib config runtime-lib-headers-path)"

build: prepare build/libmadraylib.a print_done

prepare:
	@mkdir -p build

print_done:
	@echo "build done.\noutput: build/libmadraylib.a"

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -g -I$(INCLUDEDIR) -I$(MADLIB_RUNTIME_HEADERS_PATH) -I$(MADLIB_RUNTIME_LIB_HEADERS_PATH) -std=c++17 -O1 -fPIC $(CXXFLAGS) -c $< -o $@

build/libmadraylib.a: $(OBJS)
	$(AR) rc $@ $^
