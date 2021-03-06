/*
-----------------------------------------------------------------------------
 $Id: gw6c_status.h,v 1.2 2008/03/20 16:58:36 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2008 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.

  This module contains the status context and status number definition for
  the scope of the Gateway6 Client.
  TSP protocol codes are also defined here.

-----------------------------------------------------------------------------
*/
#ifndef __GW6C_STATUS_H__
#define __GW6C_STATUS_H__


// The status API can be defined using simple MACROs or inline functions.
// -> Use MACROs.
#define GW6C_STATUS_MACRO


// The gw6c_status type is defined as a 32-bit unsigned integer.
// The lower 16 bits represent the status number, and the upper 16 bits the 
// status context.
typedef uint32_t gw6c_status;


// Context definitions. Context definitions must be <= 0x0000FFFF.
enum gw6c_status_contexts
{
  CTX_UNSPECIFIED = 0,            // Unspecified context.
  CTX_CFGVALIDATION,              // Configuration validation.
  CTX_NETWORKINIT,                // Network initialization.
  CTX_NETWORKCONNECT,             // Network connection.
  CTX_TSPCAPABILITIES,            // TSP session: Capabilities.
  CTX_TSPAUTHENTICATION,          // TSP session: Authentication.
  CTX_TSPTUNNEGOTIATION,          // TSP session: Tunnel negotiation.
  CTX_TUNINTERFACESETUP,          // Local Tunnel Setup.
  CTX_TUNNELLOOP,                 // Tunnel Lifetime.
  CTX_GW6CTEARDOWN                // Teardown / Exit Process.
};
// Defined locally in tsp_client.c. !!!UPDATE if you ADD/REMOVE contexts!!!
extern const char * GW6CStatusContext[];


// Status definition. Status definitions must be <= 0x0000FFFF.
enum gw6c_status_codes
{
  SUCCESS = 0,
  ERR_WINSOCK_INIT,
  ERR_MEMORY_STARVATION,
  ERR_INVAL_CFG_FILE,
  ERR_INVAL_GW6_ADDRESS,
  ERR_INVAL_CLIENT_ADDR,
  ERR_FAIL_LOG_INIT,
  ERR_FAIL_LAST_SERVER,
  ERR_FAIL_RESOLV_ADDR,
  ERR_FAIL_SOCKET_CONNECT,
  ERR_SOCKET_IO,
  ERR_INVAL_TSP_VERSION,
  ERR_TSP_SERVER_TOO_BUSY,
  ERR_TSP_GENERIC_ERROR,
  ERR_BROKER_REDIRECTION,
  ERR_TUNMODE_NOT_AVAILABLE,
  ERR_AUTHENTICATION_FAILURE,
  ERR_NO_COMMON_AUTHENTICATION,
  ERR_INTERFACE_SETUP_FAILED,
  ERR_BAD_TUNNEL_PARAM,
  ERR_KEEPALIVE_ERROR,
  ERR_KEEPALIVE_TIMEOUT,
  ERR_TUN_LEASE_EXPIRED,
  ERR_TUNNEL_IO,
  ERR_HAP6_INIT,
  ERR_HAP6_SETUP,
  ERR_HAP6_EXPOSE_DEVICES,

  // Events.
  EVNT_BROKER_REDIRECTION = 0x0000E001,
};


// TSP protocol statuses and errors. From HexOS/hexosd/hex_tsp_protocol.h:55
enum tsp_protocol_codes
{
  TSP_PROTOCOL_SUCCESS                    = 200,
  TSP_PROTOCOL_AUTH_FAILED                = 300,
  TSP_PROTOCOL_NO_TUNNELS                 = 301,
  TSP_PROTOCOL_UNSUP_TSP_VER              = 302,
  TSP_PROTOCOL_UNSUP_TUN_MODE             = 303,
  TSP_PROTOCOL_UNDEFINED                  = 310,
  TSP_PROTOCOL_INVALID_REQUEST            = 500,
  TSP_PROTOCOL_INVALID_IPV4               = 501,
  TSP_PROTOCOL_INVALID_IPV6               = 502,
  TSP_PROTOCOL_IPV4_PREFIX_ALREADY_USED   = 506,
  TSP_PROTOCOL_REQ_PREFIX_LEN_UNAVAILABLE = 507,
  TSP_PROTOCOL_DNS_DELEGATION_ERROR       = 509,
  TSP_PROTOCOL_UNSUPP_PREFIX_LEN          = 518,
  TSP_PROTOCOL_MISSING_PREFIX_LEN         = 520,
  TSP_PROTOCOL_REQ_IN_PROGRESS            = 521,
  TSP_PROTOCOL_PREFIX_REQ_FOR_ANONYMOUS   = 522,
  TSP_PROTOCOL_SERVER_TOO_BUSY            = 530,
  // added for redirection PROTOTYPE.
  TSP_PROTOCOL_REDIRECT                   = 1200
};


#define STATUS_SUCCESS_INIT               make_status(CTX_UNSPECIFIED, SUCCESS)

// The status API can be defined using simple MACROs or inline functions.
#ifdef GW6C_STATUS_MACRO

// GW6C status macro definitions.
#define make_status(stat_ctx,stat_num)    ((gw6c_status)(stat_num | (stat_ctx << 16)))
#define status_context(stat)              ((uint32_t)((stat & 0xFFFF0000) >> 16))
#define status_number(stat)               ((uint32_t)(stat & 0x0000FFFF))

#else

// GW6C status inline function definitions.
inline gw6c_status  make_status           ( uint32_t stat_ctx, uint32_t stat_num )
{ return (stat_num | (stat_ctx << 16)); }

inline uint32_t     status_context        ( gw6c_status stat )
{ return ((stat & 0xFFFF0000) >> 16); }

inline uint32_t     status_number         ( gw6c_status stat )
{ return (stat & 0x0000FFFF); }

#endif

#endif  // __GW6C_STATUS_H__
