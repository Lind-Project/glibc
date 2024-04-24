
ifeq ($(subdir),wcsmbs)
sysdep_routines += wcscmp-sse2 wcscmp-c wcslen-sse2 wcslen-c \
		   wmemcmp-sse4 wmemcmp-ssse3 wmemcmp-c wcschr-sse2 \
		   wcschr-c wcsrchr-sse2 wcsrchr-c wcscpy-ssse3 wcscpy-c
endif

ifeq ($(subdir),math)
libm-sysdep_routines += s_fma-fma s_fmaf-fma
CFLAGS-s_fma-fma.c += -mavx -mfpmath=sse
CFLAGS-s_fmaf-fma.c += -mavx -mfpmath=sse
endif
