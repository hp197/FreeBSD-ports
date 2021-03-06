# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	m2000
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	\
		http://www.komkon.org/~dekogel/files/p2000/:code \
		http://www.mavetju.org/download/adopted/:tapes \
		ftp://ftp.komkon.org/pub/EMUL8/P2000/Tapes/:tapes \
		http://www.mavetju.org/download/adopted/:code
DISTFILES=	${PORTNAME:tu}${EXTRACT_SUFX}:code \
		tapeconv.zip:code \
		${M2000TAPES:S/$/.gz:tapes/}
DIST_SUBDIR=	m2000
EXTRACT_ONLY=	${PORTNAME:tu}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable emulator for the Philips P2000 home computer

LICENSE=	NONE # and commercial distribution is explicitly prohibited

M2000TAPES=	3DDoolhof2.cas		\
		BrickWall.cas		\
		Componist.cas		\
		ElevatorHumpie.cas	\
		ErrorSoft1.cas		\
		Fraxxon.cas		\
		KleurenDemo.cas		\
		LazyBug.cas		\
		MachoMan.cas		\
		MonkeyKong.cas		\
		Snakey.cas		\
		SpaceAttack.cas		\
		SpaceFight.cas		\
		SpaceMission.cas	\
		SpeelPalijs.cas		\
		StarTrek.cas		\
		VluchtSimulator.cas

WRKSRC=		${WRKDIR}/P2000
ALL_TARGET=	x
USE_XORG=	x11 xext xi

SUB_FILES=	m2000.sh
PORTDOCS=	M2000.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	${MKDIR} ${WRKDIR}/tapeconv
	${UNZIP_NATIVE_CMD} ${DISTDIR}/${DIST_SUBDIR}/tapeconv.zip -d ${WRKDIR}/tapeconv

post-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKDIR}/tapeconv/PCM2CAS ${WRKDIR}/tapeconv/PCM2CAS.C

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/m2000.sh ${STAGEDIR}${PREFIX}/bin/m2000
	${INSTALL_PROGRAM} ${WRKDIR}/tapeconv/PCM2CAS ${STAGEDIR}${PREFIX}/bin/tapeconv
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/m2000/
	${INSTALL_PROGRAM} ${WRKSRC}/m2000 ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/P2000ROM.bin ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Default.fnt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/BASIC.bin ${STAGEDIR}${DATADIR}
.for f in ${M2000TAPES}
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${f}.gz > ${WRKDIR}/${f}
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${DATADIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/M2000.txt ${STAGEDIR}${DOCSDIR}

post-install:
	@${ECHO_CMD} "Run 'make install-user' to install the tapes in your own directory"

install-user:
	@${ECHO_CMD} "Copying tapes to ${HOME}/.m2000..."
	@${MKDIR} ${HOME}/.m2000
.for f in ${M2000TAPES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${HOME}/.m2000
	@${CHMOD} u+w ${HOME}/.m2000/${f}
.endfor
	@${ECHO_CMD} "Done. Now start it with 'm2000 [tapename]' and execute the commands 'cload' and 'run'"

.include <bsd.port.mk>
