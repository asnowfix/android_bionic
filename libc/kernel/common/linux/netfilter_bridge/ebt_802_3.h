/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __LINUX_BRIDGE_EBT_802_3_H
#define __LINUX_BRIDGE_EBT_802_3_H

#define EBT_802_3_SAP 0x01
#define EBT_802_3_TYPE 0x02

#define EBT_802_3_MATCH "802_3"

#define CHECK_TYPE 0xaa

#define IS_UI 0x03

#define EBT_802_3_MASK (EBT_802_3_SAP | EBT_802_3_TYPE | EBT_802_3)

struct hdr_ui {
 uint8_t dsap;
 uint8_t ssap;
 uint8_t ctrl;
 uint8_t orig[3];
 __be16 type;
};

struct hdr_ni {
 uint8_t dsap;
 uint8_t ssap;
 __be16 ctrl;
 uint8_t orig[3];
 __be16 type;
};

struct ebt_802_3_hdr {
 uint8_t daddr[6];
 uint8_t saddr[6];
 __be16 len;
 union {
 struct hdr_ui ui;
 struct hdr_ni ni;
 } llc;
};

struct ebt_802_3_info {
 uint8_t sap;
 __be16 type;
 uint8_t bitmask;
 uint8_t invflags;
};

#endif
