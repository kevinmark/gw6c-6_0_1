/*
---------------------------------------------------------------------------
 $Id: tsp_tun.h,v 1.2 2008/04/16 12:12:49 cnepveu Exp $
---------------------------------------------------------------------------
Copyright (c) 2001-2005 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT


  Special thanks to George Koehler and Urs Breinlinger.
---------------------------------------------------------------------------
*/

#ifndef __TSP_TUN_H__
#define __TSP_TUN_H__

#include "config.h"   // tBoolean

void                TunName               ( int tunfd, char* name, size_t name_len );
int                 TunInit               ( char *tun_device );
gw6c_status         TunMainLoop           (int tun, int Socket, tBoolean keepalive,
                                           int keepalive_interval, char *local_address_ipv6,
                                           char *keepalive_address);

#endif

