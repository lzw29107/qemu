/*****************************************************************************/
/* srp.h -- SCSI RDMA Protocol definitions                                   */
/*                                                                           */
/* Written By: Colin Devilbis, IBM Corporation                               */
/*                                                                           */
/* Copyright (C) 2003 IBM Corporation                                        */
/*                                                                           */
/* This program is free software; you can redistribute it and/or modify      */
/* it under the terms of the GNU General Public License as published by      */
/* the Free Software Foundation; either version 2 of the License, or         */
/* (at your option) any later version.                                       */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/* GNU General Public License for more details.                              */
/*                                                                           */
/* You should have received a copy of the GNU General Public License         */
/* along with this program. If not, see <https://www.gnu.org/licenses/>.     */
/*                                                                           */
/*                                                                           */
/* This file contains structures and definitions for IBM RPA (RS/6000        */
/* platform architecture) implementation of the SRP (SCSI RDMA Protocol)     */
/* standard.  SRP is used on IBM iSeries and pSeries platforms to send SCSI  */
/* commands between logical partitions.                                      */
/*                                                                           */
/* SRP Information Units (IUs) are sent on a "Command/Response Queue" (CRQ)  */
/* between partitions.  The definitions in this file are architected,        */
/* and cannot be changed without breaking compatibility with other versions  */
/* of Linux and other operating systems (AIX, OS/400) that talk this protocol*/
/* between logical partitions                                                */
/*****************************************************************************/
#ifndef PPC_VIOSRP_H
#define PPC_VIOSRP_H

#include "hw/scsi/srp.h"

#define SRP_VERSION "16.a"
#define SRP_MAX_IU_LEN    256
#define SRP_MAX_LOC_LEN 32

union srp_iu {
    struct srp_login_req login_req;
    struct srp_login_rsp login_rsp;
    struct srp_login_rej login_rej;
    struct srp_i_logout i_logout;
    struct srp_t_logout t_logout;
    struct srp_tsk_mgmt tsk_mgmt;
    struct srp_cmd cmd;
    struct srp_rsp rsp;
};

enum viosrp_crq_formats {
    VIOSRP_SRP_FORMAT = 0x01,
    VIOSRP_MAD_FORMAT = 0x02,
    VIOSRP_OS400_FORMAT = 0x03,
    VIOSRP_AIX_FORMAT = 0x04,
    VIOSRP_LINUX_FORMAT = 0x06,
    VIOSRP_INLINE_FORMAT = 0x07
};

enum viosrp_crq_status {
    VIOSRP_OK = 0x0,
    VIOSRP_NONRECOVERABLE_ERR = 0x1,
    VIOSRP_VIOLATES_MAX_XFER = 0x2,
    VIOSRP_PARTNER_PANIC = 0x3,
    VIOSRP_DEVICE_BUSY = 0x8,
    VIOSRP_ADAPTER_FAIL = 0x10,
    VIOSRP_OK2 = 0x99,
};

struct viosrp_crq {
    uint8_t valid;        /* used by RPA */
    uint8_t format;        /* SCSI vs out-of-band */
    uint8_t reserved;
    uint8_t status;        /* non-scsi failure? (e.g. DMA failure) */
    uint16_t timeout;        /* in seconds */
    uint16_t IU_length;        /* in bytes */
    uint64_t IU_data_ptr;    /* the TCE for transferring data */
};

/* MADs are Management requests above and beyond the IUs defined in the SRP
 * standard.
 */
enum viosrp_mad_types {
    VIOSRP_EMPTY_IU_TYPE = 0x01,
    VIOSRP_ERROR_LOG_TYPE = 0x02,
    VIOSRP_ADAPTER_INFO_TYPE = 0x03,
    VIOSRP_HOST_CONFIG_TYPE = 0x04,
    VIOSRP_CAPABILITIES_TYPE = 0x05,
    VIOSRP_ENABLE_FAST_FAIL = 0x08,
};

enum viosrp_mad_status {
    VIOSRP_MAD_SUCCESS = 0x00,
    VIOSRP_MAD_NOT_SUPPORTED = 0xF1,
    VIOSRP_MAD_FAILED = 0xF7,
};

enum viosrp_capability_type {
    MIGRATION_CAPABILITIES = 0x01,
    RESERVATION_CAPABILITIES = 0x02,
};

enum viosrp_capability_support {
    SERVER_DOES_NOT_SUPPORTS_CAP = 0x0,
    SERVER_SUPPORTS_CAP = 0x01,
    SERVER_CAP_DATA = 0x02,
};

enum viosrp_reserve_type {
    CLIENT_RESERVE_SCSI_2 = 0x01,
};

enum viosrp_capability_flag {
    CLIENT_MIGRATED = 0x01,
    CLIENT_RECONNECT = 0x02,
    CAP_LIST_SUPPORTED = 0x04,
    CAP_LIST_DATA = 0x08,
};

/*
 * Common MAD header
 */
struct mad_common {
    uint32_t type;
    uint16_t status;
    uint16_t length;
    uint64_t tag;
};

/*
 * All SRP (and MAD) requests normally flow from the
 * client to the server.  There is no way for the server to send
 * an asynchronous message back to the client.  The Empty IU is used
 * to hang out a meaningless request to the server so that it can respond
 * asynchrouously with something like a SCSI AER
 */
struct viosrp_empty_iu {
    struct mad_common common;
    uint64_t buffer;
    uint32_t port;
};

struct viosrp_error_log {
    struct mad_common common;
    uint64_t buffer;
};

struct viosrp_adapter_info {
    struct mad_common common;
    uint64_t buffer;
};

struct viosrp_host_config {
    struct mad_common common;
    uint64_t buffer;
};

struct viosrp_fast_fail {
    struct mad_common common;
};

struct viosrp_capabilities {
    struct mad_common common;
    uint64_t buffer;
};

struct mad_capability_common {
    uint32_t cap_type;
    uint16_t length;
    uint16_t server_support;
};

struct mad_reserve_cap {
    struct mad_capability_common common;
    uint32_t type;
};

struct mad_migration_cap {
    struct mad_capability_common common;
    uint32_t ecl;
};

struct capabilities {
    uint32_t flags;
    char name[SRP_MAX_LOC_LEN];
    char loc[SRP_MAX_LOC_LEN];
    struct mad_migration_cap migration;
    struct mad_reserve_cap reserve;
};

union mad_iu {
    struct viosrp_empty_iu empty_iu;
    struct viosrp_error_log error_log;
    struct viosrp_adapter_info adapter_info;
    struct viosrp_host_config host_config;
    struct viosrp_fast_fail fast_fail;
    struct viosrp_capabilities capabilities;
};

union viosrp_iu {
    union srp_iu srp;
    union mad_iu mad;
};

struct mad_adapter_info_data {
    char srp_version[8];
    char partition_name[96];
    uint32_t partition_number;
    uint32_t mad_version;
    uint32_t os_type;
    uint32_t port_max_txu[8];    /* per-port maximum transfer */
};

#endif
