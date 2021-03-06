#include "frat.h"
#define MAX_SUNS 180
#include <stdlib.h>

double *sphereTesselate(int maxlevel,int *nTriangles);
double facetNormal(double *normal,struct Facet_struct *n);
void allocate_material_list();
void fp_fwrite_header();
void            calculate_material_lut();
int find_number_of_materials_in_material_map();
void calculate_sun_elevation_axis();
void            pre_calculate_sun_parameters();
void clearHitPoint();
void gatherPixelStatsForRay();
int getNdefaultMaterials();
int seed_randomise();
int quantise_sky_waveband();
void	Vector_Matrix_multiplication_to_Vector();
int     expand_filename();
int calculate_reflectance_data();
void loadObjectInfo();
void	Matrix_Matrix_multiplication_to_Matrix();
int loadObject();

char *RATgetProgramName(RATobj *ratObj);
int RATgetMemory();
RATobj *RATinit();
void RATprintOptions(RATobj *);
int RATuserParse(RATobj *bb,int thisarg,int argc,char **argv,void *info);
void RATreadObject(RATobj *bb);
void RATstart(RATobj *bb);
int  RATparse(RATobj *bb,int argc,char **argv,void *info); 
void RATsetNsuns(RATobj *bb,int i);
int RATgetNsuns(RATobj *ratObj);
int RATgetNmaterials(RATobj *ratObj);
void RATuserPrintOptions(RATobj *ratObj);
void 	RATsignalInterrupt(int sig);
int RATprintObject(RATobj *ratObj);

/* utilities */
void RATprintObjects(RATobj *ratObj);
double *RATgetBBoxMin(RATobj *ratObj,double *min);
double *RATgetBBoxMax(RATobj *ratObj,double *max);
RATobject *RATgetObjects(RATobj *ratObj,int whichOne,double *min,double *max,int *nsamples,int nHistogramSamples,char *names);
RATvol *RATgetVolumetric(RATobj *ratObj,int *grid,double *extent);
char *RATtranslateMaterial(RATobj *ratObj,int thisMat,int *index);
RATmaterials *RATgetMaterials(RATobj *ratObj,int *nMat);
int RATgetPID();
int RATgetnMaterials(RATobj *ratObj);
double *RATgetSun(RATobj *ratObj);
void RATsetSun(RATobj *,double *a);
int RATgetNWavebands(RATobj *ratObj,double *wavebands);
void RATsetNWavebands(RATobj *ratObj,int n,double *minwavelength,double *bandwidth);
char *RATgetWavefrontFilename(RATobj *ratObj);
void RATsetWavefrontFilename(RATobj *ratObj,char *filename);
int RATisWavefrontFile(RATobj *ratObj);
int RATreadWavefrontFile(RATobj *ratObj);
int RATtraceRay(RATobj *ratObj,double *from,double *direction,double *sunPosition);
int RATtraceRays(RATobj *ratObj,double *from,double *direction,void *nothing);
void RATprintDefinedMaterials(RATobj *ratObj);
RATtree *RATgetRatTree(RATobj *ratObj);
int RATgetRTD(RATobj *ratObj);
RATmaterials *RATgetMaterialsUsed(RATobj *ratObj,int *nMat);
int RATgetVerboseLevel(RATobj *ratObj);
void RATsetVerboseLevel(RATobj *ratObj,int level);

/* system */
int RATgetPID();
#ifndef RAT_MAIN
extern void RATuserInterrupt(RATobj *ratObj,int sig);
#else
void RATuserInterrupt(RATobj *ratObj,int sig);
#endif
