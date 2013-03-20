/*
-----------------------------------------------------------------------------
 $Id: tsp_net.h,v 1.12 2008/03/20 16:58:37 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------
*/

#ifndef _TSP_NET_H_
#define _TSP_NET_H_

#include "net.h"

/* definitions and constants */

#define MAXNAME                 1024
#define MAXSERVER               1024
#define SERVER_PORT             3653
#define SERVER_PORT_STR         "3653"
#define PROTOCOLMAXPAYLOADCHUNK 2048
#define PROTOCOLFRAMESIZE       4096
#define PROTOCOLMAXHEADER       70

enum { 
  PROTOCOL_OK, 
  PROTOCOL_ERROR, 
  PROTOCOL_EMEM, 
  PROTOCOL_ESYNTAX, 
  PROTOCOL_ESIZE, 
  PROTOCOL_EREAD 
};

/* structures */

typedef struct stPayload {
  long size, PayloadCapacity;
  char *payload;
} tPayload;


// Public function prototypes.
gw6c_status         tspConnect            ( pal_socket_t*, char *, uint16_t, net_tools_t * );
gw6c_status         tspClose              ( pal_socket_t, net_tools_t * );

sint32_t            tspSendRecv           ( pal_socket_t, tPayload *, tPayload *, net_tools_t * );
sint32_t            tspSend               ( pal_socket_t, tPayload *, net_tools_t * );
sint32_t            tspReceive            ( pal_socket_t, tPayload *, net_tools_t * );

#endif

