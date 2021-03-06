/*
-----------------------------------------------------------------------------
 $Id: pal_inet.h,v 1.4 2007/10/25 19:50:49 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer for inet.

-----------------------------------------------------------------------------
*/
#ifndef __PAL_INET_H__
#define __PAL_INET_H__

// inet API definitions.
#include "pal_inet.def"
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/icmp6.h>


// inet functions already available in this platform.
#undef pal_inet_pton
#define pal_inet_pton inet_pton

#endif
