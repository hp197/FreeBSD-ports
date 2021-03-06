# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	x42-plugins
DISTVERSION=	20180320 # the version is published here: http://gareus.org/misc/x42-plugins.php
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://gareus.org/misc/x42-plugins/
PKGNAMESUFFIX=	-lv2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} # only to allow USE_GITHUB=nodefault for zita4 compatilility patch

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LV2 plugins (submodules)

LICENSE=	GPLv2

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		bash:shells/bash
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		liblo.so:audio/liblo \
		libltc.so:audio/libltc \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libzita-convolver.so:audio/zita-convolver

USES=		gmake localbase pkgconfig tar:xz shebangfix
USE_GITHUB=	nodefault
GH_TUPLE=	x42:convoLV2:f814f1e:x/convoLV2zita4
USE_GNOME=	glib20 pango cairo
USE_XORG=	x11
USE_GL=		glu gl
MAKE_ENV=	BUILDOPENGL=yes BUILDGTK=no LV2DIR=${PREFIX}/lib/lv2 MANDIR=${PREFIX}/man/man1
SHEBANG_FILES=	stepseq.lv2/gridgen.sh

CXXFLAGS+=	-std=c++98

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

SSE_MAKE_ARGS=	PORT_SIMD_FLAGS="-msse -msse2 -mfpmath=sse"

# It suffers from the regression in clang-6: https://bugs.llvm.org/show_bug.cgi?id=36915
LLVM_VER=	50
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

post-patch:
	@${REINPLACE_CMD} 's| -O3||' \
		${WRKSRC}/*.lv2/Makefile
	@${REINPLACE_CMD} 's/__APPLE__/__FreeBSD__/' \
		${WRKSRC}/tuna.lv2/src/spectr.c \
		${WRKSRC}/meters.lv2/src/spectr.c
	@${REINPLACE_CMD} 's|$$(mandir)/man1|$$(MANDIR)|' \
		${WRKSRC}/sisco.lv2/Makefile
	@cd ${WRKSRC} && ${RM} -r convoLV2 && ${MV} convoLV2zita4 convoLV2
	@${REINPLACE_CMD} 's| -msse -msse2 -mfpmath=sse| $$(PORT_SIMD_FLAGS)|' \
		${WRKSRC}/*.lv2/Makefile ${WRKSRC}/convoLV2/Makefile

.include <bsd.port.mk>
