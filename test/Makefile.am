TESTS = run-test.sh
TESTS_ENVIRONMENT = NO_MAKE=yes CUTTER="$(CUTTER)"

noinst_LTLIBRARIES = test_dec128.la

INCLUDES = $(CUTTER_CFLAGS) -I$(top_srcdir)/src
LIBS = $(CUTTER_LIBS) $(top_builddir)/src/libdec128.la

LDFLAGS = -module -rpath $(libdir) -avoid-version -no-undefined
test_dec128_la_SOURCES = test_dec128.c test_decode_DPD.c test_encode_DPD.c

echo-cutter:
	@echo $(CUTTER)
