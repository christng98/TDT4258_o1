# -*-makefile-*-
#
# Copyright (C) 2006 by Robert Schwebel
#
# See CREDITS for details about who has contributed to this project.
#
# For further information about the PTXdist project and license conditions
# see the README file.
#

#
# We provide this package
#
CROSS_PACKAGES-$(PTXCONF_CROSS_GCC_FIRST) += cross-gcc-first

#
# Paths and names
#
CROSS_GCC_FIRST_BUILDDIR	= $(CROSS_BUILDDIR)/$(CROSS_GCC)-first-build

# ----------------------------------------------------------------------------
# Get
# ----------------------------------------------------------------------------

$(STATEDIR)/cross-gcc-first.get: $(STATEDIR)/cross-gcc.get
	@$(call targetinfo)
	@$(call touch)

# ----------------------------------------------------------------------------
# Extract
# ----------------------------------------------------------------------------

$(STATEDIR)/cross-gcc-first.extract: $(STATEDIR)/cross-gcc.extract
	@$(call targetinfo)
	@$(call touch)

# ----------------------------------------------------------------------------
# Prepare
# ----------------------------------------------------------------------------

CROSS_GCC_FIRST_PATH	:= PATH=$(CROSS_PATH)
CROSS_GCC_FIRST_ENV	:= $(PTX_HOST_ENV)

#
# autoconf
#
CROSS_GCC_FIRST_AUTOCONF = \
	$(CROSS_GCC_AUTOCONF_COMMON) \
	--prefix=$(CROSS_GCC_FIRST_PREFIX) \
	\
	--disable-shared \
	--enable-languages=c \
	\
	--with-ld=$(PTXCONF_SYSROOT_CROSS)/bin/$(PTXCONF_GNU_TARGET)-ld \
	--with-as=$(PTXCONF_SYSROOT_CROSS)/bin/$(PTXCONF_GNU_TARGET)-as \
	--disable-checking \
	\
	--disable-libmudflap \
	--disable-libssp \
	--disable-libgomp \
	--disable-libquadmath \
	--with-system-zlib

$(STATEDIR)/cross-gcc-first.prepare:
	@$(call targetinfo)
	@$(call clean, $(CROSS_GCC_FIRST_BUILDDIR))
	mkdir -p $(CROSS_GCC_FIRST_BUILDDIR)
	cd $(CROSS_GCC_FIRST_BUILDDIR) && \
		$(CROSS_GCC_FIRST_PATH) $(CROSS_GCC_FIRST_ENV) \
		$(CROSS_GCC_DIR)/configure $(CROSS_GCC_FIRST_AUTOCONF)
	@$(call touch)

# ----------------------------------------------------------------------------
# Compile
# ----------------------------------------------------------------------------

$(STATEDIR)/cross-gcc-first.compile:
	@$(call targetinfo)
	cd $(CROSS_GCC_FIRST_BUILDDIR) && $(CROSS_GCC_FIRST_PATH) \
		$(MAKE) $(PARALLELMFLAGS)
	@$(call touch)

# ----------------------------------------------------------------------------
# Install
# ----------------------------------------------------------------------------

$(STATEDIR)/cross-gcc-first.install:
	@$(call targetinfo)
	cd $(CROSS_GCC_FIRST_BUILDDIR) && \
		$(CROSS_GCC_FIRST_PATH) $(MAKE) install #install-gcc
	ln -sfv libgcc.a `$(CROSS_GCC_FIRST_PREFIX)/bin/$(PTXCONF_GNU_TARGET)-gcc \
		-print-libgcc-file-name | \
		sed 's/libgcc/&_eh/'`
	ln -sfv libgcc.a `$(CROSS_GCC_FIRST_PREFIX)/bin/$(PTXCONF_GNU_TARGET)-gcc \
		-print-libgcc-file-name | \
		sed 's/libgcc/&_s/'`

	@$(call touch)

# ----------------------------------------------------------------------------
# Clean
# ----------------------------------------------------------------------------

cross-gcc-first_clean:
	rm -rf $(STATEDIR)/cross-gcc-first.*
	rm -rf $(CROSS_GCC_FIRST_BUILDDIR)

# vim: syntax=make
