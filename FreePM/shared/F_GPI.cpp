/*
 $Id: F_GPI.cpp,v 1.3 2003/06/15 17:48:52 evgen2 Exp $
*/
/* F_GPI.cpp */
/* GPI functions of FreePM */
/* DEBUG: section 10    GPI functions of FreePM */
/* ver 0.00 17.09.2002     */

#include <malloc.h>
#include "FreePM.hpp"
#include "F_GPI.hpp"
#include "FreePM_cmd.hpp"

/* for debug()*/
#include <stdio.h>
#include "F_globals.hpp"

/*+---------------------------------+*/
/*| External function prototypes.   |*/
/*+---------------------------------+*/
int _F_SendCmdToServer(int cmd, int data);
int _F_SendGenCmdToServer(int cmd, int par);
int _F_SendGenCmdDataToServer(int cmd, int par, void *data, int datalen);
int _F_SendDataToServer(void *data, int len);
int _F_RecvDataFromServer(void *data, int *len, int maxlen);


/*
 This function draws a rectangular box with the current position
 and a specified position at diagonally  opposite corners.
 #define INCL_GPIPRIMITIVES  Or use INCL_GPI, INCL_PM, Also in COMMON section
 #include <os2.h>

*/

LONG   F_GpiBox(HPS hps,       /*  Presentation-space handle. */
                LONG lControl, /*  Outline and fill control. */
                PPOINTL pptlPoint,/*  Corner point. */
                LONG lHRound,  /*  Corner-rounding control. */
                LONG lVRound)  /*  Corner-rounding control. */
{
//todo
   return 0;
}

BOOL  F_GpiSetColor(HPS hps, LONG lColor)
{   int rc;
#ifdef FREPM_SERVER
    debug(10, 0) (__FUNCTION__ " WARNING: is not yet implemented in server mode\n");

#else  /* FREPM_SERVER */
    rc = _F_SendGenCmdDataToServer(F_CMD_GPI_SET_COLOR, hps, (void *)&lColor, 1);
    debug(10, 0) (__FUNCTION__ "hps=%x, color=%x,rc=%x\n",hps,lColor,rc);
#endif

    return rc;
}

LONG   F_GpiQueryColor(HPS hps)
{ LONG color=0;
    debug(10, 0) (__FUNCTION__ "hps=%x, not yet inclemented\n");
  return color;
}

BOOL   F_GpiMove(HPS hps, PPOINTL pptlPoint)
{   int rc = FALSE;
#ifdef FREPM_SERVER
    debug(10, 0) (__FUNCTION__ " WARNING: is not yet implemented in server mode\n");

#else  /* FREPM_SERVER */
    rc = _F_SendGenCmdDataToServer(F_CMD_GPI_MOVE, hps, (void *)pptlPoint, sizeof(POINTL)/sizeof(int));
    debug(10, 0) (__FUNCTION__ "hps=%x, Point=(%i,%i), rc=%x\n",hps,pptlPoint->x,pptlPoint->y,rc);
#endif
   return rc;
}

LONG  F_GpiLine(HPS hps,  PPOINTL pptlEndPoint)
{   int rc = FALSE;
#ifdef FREPM_SERVER
    debug(10, 0) (__FUNCTION__ " WARNING: is not yet implemented in server mode\n");

#else  /* FREPM_SERVER */
    rc = _F_SendGenCmdDataToServer(F_CMD_GPI_LINE, hps, (void *)pptlEndPoint, sizeof(POINTL)/sizeof(int));
    debug(10, 0) (__FUNCTION__ "hps=%x, Point=(%i,%i), rc=%x\n",
                               hps,pptlEndPoint->x,pptlEndPoint->y,rc);
#endif
   return rc;
}


