--- scsilib/libschily/getfp.c.orig	2003-07-12 23:10:47 UTC
+++ scsilib/libschily/getfp.c
@@ -23,6 +23,7 @@
 #include <mconfig.h>
 #include <standard.h>
 #include <schily.h>
+#include <sys/cdefs.h>
 
 #ifndef	IS_AVOFFSET
 /*
@@ -56,7 +57,7 @@
 
 EXPORT	void	**___fpoff	__PR((char *cp));
 
-EXPORT void **
+EXPORT __noinline void **
 getfp()
 {
 		long	**dummy[1];
@@ -73,7 +74,7 @@ getfp()
  * We need this function to fool GCCs check for returning addresses
  * from outside the functions local address space.
  */
-EXPORT void **
+EXPORT __noinline void **
 ___fpoff(cp)
 	char	*cp;
 {
