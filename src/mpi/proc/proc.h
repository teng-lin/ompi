/*
 * $HEADER$
 */

#ifndef LAM_PROC
#define LAM_PROC

#include "lam/lfc/list.h"


extern lam_class_info_t lam_proc_cls;
extern lam_list_t lam_procs;


struct lam_proc_t {
    lam_list_item_t        super;       /* allow proc to be placed on a list */
    char*                  proc_jobid;  /* identifies a unique job */
    int                    proc_vpid;   /* process identifier w/in the job */
    struct mca_pml_proc_t* proc_pml;    /* PML specific proc data */

  /* JMS: need to have the following information:

     - endian info
     - type size info
     - peer parallel job id
     - how am i [mpi] connected (bitmap): spawn (parent/child), 
                                          connect, accept, joint
  */
};
typedef struct lam_proc_t lam_proc_t;


void  lam_proc_init(lam_proc_t*);
void  lam_proc_destroy(lam_proc_t*);

#endif /* LAM_PROC */

