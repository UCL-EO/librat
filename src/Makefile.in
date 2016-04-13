#
#
#
#       Lewis, RSU, UCL Geography, 1993
#
#
#
#       build executables

# object building
LIBRARY = ../lib

SRCS = 2D_vectors.c cylinder.c fratP.c	perr.c	sky.c 2D_vectors_double.c cylinderTess.c hiplib.c plane.c sphere.c  3D_vectors_double.c	dem.c hips2pbm.c prat_wavefront_read.c	sphereTess.c 4D_vectors.c r250.c spheroid.c disk.c imagelib.c allocate.c images.c random.c bbox.c intersect_objects.c ratFront.c ellipse.c libhipl.c reflectance.c bilinear.c envilib.c error.c material.c useful.c facet.c rpv.c vectors2.c camera.c	volumeRayTrace.c filelib.c mtllib.c write_header.c files.c sensor_rsr.c 

OBJS = $(SRCS:.c=.o)

.PHONY: depend clean

MAIN = librat

$(MAIN):	$(OBJS) 
		mkdir -p  ${LIBRARY}
		${AR} rcv ${LIBRARY}/librat_${ARCH}.a ${OBJS}
		${RANLIB} ${LIBRARY}/librat_${ARCH}.a
		${DYN} -o ${LIBRARY}/librat_${ARCH}.so ${OBJS}

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) ${DEFS} -c $< -D${ARCH} -Iinclude -o $@

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool:	$(LIBTOOL_DEPS)
		$(SHELL) ./config.status libtool

clean:
	$(RM) *.o *~ $(MAIN) ${LIBRARY}/*${ARCH}.a ${LIBRARY}/*${ARCH}.so

depend: 
	makedepend -- -D${ARCH} -Iinclude $(SRCS)

# DO NOT DELETE THIS LINE -- make depend needs it
