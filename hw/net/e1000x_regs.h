/*******************************************************************************

  Intel PRO/1000 Linux driver
  Copyright(c) 1999 - 2006 Intel Corporation.

  This program is free software; you can redistribute it and/or modify it
  under the terms and conditions of the GNU General Public License,
  version 2, as published by the Free Software Foundation.

  This program is distributed in the hope it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, see <http://www.gnu.org/licenses/>.

  The full GNU General Public License is included in this distribution in
  the file called "COPYING".

  Contact Information:
  Linux NICS <linux.nics@intel.com>
  e1000-devel Mailing List <e1000-devel@lists.sourceforge.net>
  Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497

*******************************************************************************/

/* e1000_hw.h
 * Structures, enums, and macros for the MAC
 */

#ifndef HW_E1000X_REGS_H
#define HW_E1000X_REGS_H

/* PCI Device IDs */
#define E1000_DEV_ID_82542               0x1000
#define E1000_DEV_ID_82543GC_FIBER       0x1001
#define E1000_DEV_ID_82543GC_COPPER      0x1004
#define E1000_DEV_ID_82544EI_COPPER      0x1008
#define E1000_DEV_ID_82544EI_FIBER       0x1009
#define E1000_DEV_ID_82544GC_COPPER      0x100C
#define E1000_DEV_ID_82544GC_LOM         0x100D
#define E1000_DEV_ID_82540EM             0x100E
#define E1000_DEV_ID_82540EM_LOM         0x1015
#define E1000_DEV_ID_82540EP_LOM         0x1016
#define E1000_DEV_ID_82540EP             0x1017
#define E1000_DEV_ID_82540EP_LP          0x101E
#define E1000_DEV_ID_82545EM_COPPER      0x100F
#define E1000_DEV_ID_82545EM_FIBER       0x1011
#define E1000_DEV_ID_82545GM_COPPER      0x1026
#define E1000_DEV_ID_82545GM_FIBER       0x1027
#define E1000_DEV_ID_82545GM_SERDES      0x1028
#define E1000_DEV_ID_82546EB_COPPER      0x1010
#define E1000_DEV_ID_82546EB_FIBER       0x1012
#define E1000_DEV_ID_82546EB_QUAD_COPPER 0x101D
#define E1000_DEV_ID_82541EI             0x1013
#define E1000_DEV_ID_82541EI_MOBILE      0x1018
#define E1000_DEV_ID_82541ER_LOM         0x1014
#define E1000_DEV_ID_82541ER             0x1078
#define E1000_DEV_ID_82547GI             0x1075
#define E1000_DEV_ID_82541GI             0x1076
#define E1000_DEV_ID_82541GI_MOBILE      0x1077
#define E1000_DEV_ID_82541GI_LF          0x107C
#define E1000_DEV_ID_82546GB_COPPER      0x1079
#define E1000_DEV_ID_82546GB_FIBER       0x107A
#define E1000_DEV_ID_82546GB_SERDES      0x107B
#define E1000_DEV_ID_82546GB_PCIE        0x108A
#define E1000_DEV_ID_82546GB_QUAD_COPPER 0x1099
#define E1000_DEV_ID_82547EI             0x1019
#define E1000_DEV_ID_82547EI_MOBILE      0x101A
#define E1000_DEV_ID_82571EB_COPPER      0x105E
#define E1000_DEV_ID_82571EB_FIBER       0x105F
#define E1000_DEV_ID_82571EB_SERDES      0x1060
#define E1000_DEV_ID_82571EB_QUAD_COPPER 0x10A4
#define E1000_DEV_ID_82571PT_QUAD_COPPER 0x10D5
#define E1000_DEV_ID_82571EB_QUAD_FIBER  0x10A5
#define E1000_DEV_ID_82571EB_QUAD_COPPER_LOWPROFILE  0x10BC
#define E1000_DEV_ID_82571EB_SERDES_DUAL 0x10D9
#define E1000_DEV_ID_82571EB_SERDES_QUAD 0x10DA
#define E1000_DEV_ID_82572EI_COPPER      0x107D
#define E1000_DEV_ID_82572EI_FIBER       0x107E
#define E1000_DEV_ID_82572EI_SERDES      0x107F
#define E1000_DEV_ID_82572EI             0x10B9
#define E1000_DEV_ID_82573E              0x108B
#define E1000_DEV_ID_82573E_IAMT         0x108C
#define E1000_DEV_ID_82573L              0x109A
#define E1000_DEV_ID_82574L              0x10D3
#define E1000_DEV_ID_82546GB_QUAD_COPPER_KSP3 0x10B5
#define E1000_DEV_ID_80003ES2LAN_COPPER_DPT     0x1096
#define E1000_DEV_ID_80003ES2LAN_SERDES_DPT     0x1098
#define E1000_DEV_ID_80003ES2LAN_COPPER_SPT     0x10BA
#define E1000_DEV_ID_80003ES2LAN_SERDES_SPT     0x10BB

#define E1000_DEV_ID_ICH8_IGP_M_AMT      0x1049
#define E1000_DEV_ID_ICH8_IGP_AMT        0x104A
#define E1000_DEV_ID_ICH8_IGP_C          0x104B
#define E1000_DEV_ID_ICH8_IFE            0x104C
#define E1000_DEV_ID_ICH8_IFE_GT         0x10C4
#define E1000_DEV_ID_ICH8_IFE_G          0x10C5
#define E1000_DEV_ID_ICH8_IGP_M          0x104D

/* Device Specific Register Defaults */
#define E1000_PHY_ID2_82541x 0x380
#define E1000_PHY_ID2_82544x 0xC30
#define E1000_PHY_ID2_8254xx_DEFAULT 0xC20 /* 82540x, 82545x, and 82546x */
#define E1000_PHY_ID2_82573x 0xCC0
#define E1000_PHY_ID2_82574x 0xCB1

/* Register Set. (82543, 82544)
 *
 * Registers are defined to be 32 bits and  should be accessed as 32 bit values.
 * These registers are physically located on the NIC, but are mapped into the
 * host memory address space.
 *
 * RW - register is both readable and writable
 * RO - register is read only
 * WO - register is write only
 * R/clr - register is read only and is cleared when read
 * A - register array
 */
#define E1000_CTRL     0x00000  /* Device Control - RW */
#define E1000_CTRL_DUP 0x00004  /* Device Control Duplicate (Shadow) - RW */
#define E1000_STATUS   0x00008  /* Device Status - RO */
#define E1000_EECD     0x00010  /* EEPROM/Flash Control - RW */
#define E1000_EERD     0x00014  /* EEPROM Read - RW */
#define E1000_CTRL_EXT 0x00018  /* Extended Device Control - RW */
#define E1000_FLA      0x0001C  /* Flash Access - RW */
#define E1000_MDIC     0x00020  /* MDI Control - RW */
#define E1000_SCTL     0x00024  /* SerDes Control - RW */
#define E1000_FCAL     0x00028  /* Flow Control Address Low - RW */
#define E1000_FCAH     0x0002C  /* Flow Control Address High -RW */
#define E1000_FCT      0x00030  /* Flow Control Type - RW */
#define E1000_VET      0x00038  /* VLAN Ether Type - RW */
#define E1000_ICR      0x000C0  /* Interrupt Cause Read - R/clr */
#define E1000_ICS      0x000C8  /* Interrupt Cause Set - WO */
#define E1000_IMS      0x000D0  /* Interrupt Mask Set - RW */
#define E1000_IMC      0x000D8  /* Interrupt Mask Clear - WO */
#define E1000_IAM      0x000E0  /* Interrupt Acknowledge Auto Mask */
#define E1000_RCTL     0x00100  /* RX Control - RW */
#define E1000_FCTTV    0x00170  /* Flow Control Transmit Timer Value - RW */
#define E1000_TCTL     0x00400  /* TX Control - RW */
#define E1000_TCTL_EXT 0x00404  /* Extended TX Control - RW */
#define E1000_TIPG     0x00410  /* TX Inter-packet gap -RW */
#define E1000_LEDCTL   0x00E00  /* LED Control - RW */
#define E1000_EEMNGCTL 0x01010  /* MNG EEprom Control */
#define E1000_EEMNGDATA    0x01014 /* MNG EEPROM Read/Write data */
#define E1000_FLMNGCTL     0x01018 /* MNG Flash Control */
#define E1000_FLMNGDATA    0x0101C /* MNG FLASH Read data */
#define E1000_FLMNGCNT     0x01020 /* MNG FLASH Read Counter */
#define E1000_EEARBC   0x01024  /* EEPROM Auto Read Bus Control */
#define E1000_FLOP     0x0103C  /* FLASH Opcode Register */
#define E1000_FCRTL    0x02160  /* Flow Control Receive Threshold Low - RW */
#define E1000_FCRTL_A  0x00168  /* Alias to FCRTL */
#define E1000_FCRTH    0x02168  /* Flow Control Receive Threshold High - RW */
#define E1000_RDFH     0x02410  /* Receive Data FIFO Head Register - RW */
#define E1000_RDFH_A   0x08000  /* Alias to RDFH */
#define E1000_RDFT     0x02418  /* Receive Data FIFO Tail Register - RW */
#define E1000_RDFT_A   0x08008  /* Alias to RDFT */
#define E1000_RDFHS    0x02420  /* Receive Data FIFO Head Saved Register - RW */
#define E1000_RDFTS    0x02428  /* Receive Data FIFO Tail Saved Register - RW */
#define E1000_RDFPC    0x02430  /* Receive Data FIFO Packet Count - RW */
#define E1000_TDFH     0x03410  /* TX Data FIFO Head - RW */
#define E1000_TDFH_A   0x08010  /* Alias to TDFH */
#define E1000_TDFT     0x03418  /* TX Data FIFO Tail - RW */
#define E1000_TDFT_A   0x08018  /* Alias to TDFT */
#define E1000_TDFHS    0x03420  /* TX Data FIFO Head Saved - RW */
#define E1000_TDFTS    0x03428  /* TX Data FIFO Tail Saved - RW */
#define E1000_TDFPC    0x03430  /* TX Data FIFO Packet Count - RW */
#define E1000_CRCERRS  0x04000  /* CRC Error Count - R/clr */
#define E1000_ALGNERRC 0x04004  /* Alignment Error Count - R/clr */
#define E1000_SYMERRS  0x04008  /* Symbol Error Count - R/clr */
#define E1000_RXERRC   0x0400C  /* Receive Error Count - R/clr */
#define E1000_MPC      0x04010  /* Missed Packet Count - R/clr */
#define E1000_SCC      0x04014  /* Single Collision Count - R/clr */
#define E1000_ECOL     0x04018  /* Excessive Collision Count - R/clr */
#define E1000_MCC      0x0401C  /* Multiple Collision Count - R/clr */
#define E1000_LATECOL  0x04020  /* Late Collision Count - R/clr */
#define E1000_COLC     0x04028  /* Collision Count - R/clr */
#define E1000_DC       0x04030  /* Defer Count - R/clr */
#define E1000_TNCRS    0x04034  /* TX-No CRS - R/clr */
#define E1000_RLEC     0x04040  /* Receive Length Error Count - R/clr */
#define E1000_XONRXC   0x04048  /* XON RX Count - R/clr */
#define E1000_XONTXC   0x0404C  /* XON TX Count - R/clr */
#define E1000_XOFFRXC  0x04050  /* XOFF RX Count - R/clr */
#define E1000_XOFFTXC  0x04054  /* XOFF TX Count - R/clr */
#define E1000_FCRUC    0x04058  /* Flow Control RX Unsupported Count- R/clr */
#define E1000_PRC64    0x0405C  /* Packets RX (64 bytes) - R/clr */
#define E1000_PRC127   0x04060  /* Packets RX (65-127 bytes) - R/clr */
#define E1000_PRC255   0x04064  /* Packets RX (128-255 bytes) - R/clr */
#define E1000_PRC511   0x04068  /* Packets RX (255-511 bytes) - R/clr */
#define E1000_PRC1023  0x0406C  /* Packets RX (512-1023 bytes) - R/clr */
#define E1000_PRC1522  0x04070  /* Packets RX (1024-1522 bytes) - R/clr */
#define E1000_GPRC     0x04074  /* Good Packets RX Count - R/clr */
#define E1000_BPRC     0x04078  /* Broadcast Packets RX Count - R/clr */
#define E1000_MPRC     0x0407C  /* Multicast Packets RX Count - R/clr */
#define E1000_GPTC     0x04080  /* Good Packets TX Count - R/clr */
#define E1000_GORCL    0x04088  /* Good Octets RX Count Low - R/clr */
#define E1000_GORCH    0x0408C  /* Good Octets RX Count High - R/clr */
#define E1000_GOTCL    0x04090  /* Good Octets TX Count Low - R/clr */
#define E1000_GOTCH    0x04094  /* Good Octets TX Count High - R/clr */
#define E1000_RNBC     0x040A0  /* RX No Buffers Count - R/clr */
#define E1000_RUC      0x040A4  /* RX Undersize Count - R/clr */
#define E1000_RFC      0x040A8  /* RX Fragment Count - R/clr */
#define E1000_ROC      0x040AC  /* RX Oversize Count - R/clr */
#define E1000_RJC      0x040B0  /* RX Jabber Count - R/clr */
#define E1000_MGTPRC   0x040B4  /* Management Packets RX Count - R/clr */
#define E1000_MGTPDC   0x040B8  /* Management Packets Dropped Count - R/clr */
#define E1000_MGTPTC   0x040BC  /* Management Packets TX Count - R/clr */
#define E1000_TORL     0x040C0  /* Total Octets RX Low - R/clr */
#define E1000_TORH     0x040C4  /* Total Octets RX High - R/clr */
#define E1000_TOTL     0x040C8  /* Total Octets TX Low - R/clr */
#define E1000_TOTH     0x040CC  /* Total Octets TX High - R/clr */
#define E1000_TPR      0x040D0  /* Total Packets RX - R/clr */
#define E1000_TPT      0x040D4  /* Total Packets TX - R/clr */
#define E1000_PTC64    0x040D8  /* Packets TX (64 bytes) - R/clr */
#define E1000_PTC127   0x040DC  /* Packets TX (65-127 bytes) - R/clr */
#define E1000_PTC255   0x040E0  /* Packets TX (128-255 bytes) - R/clr */
#define E1000_PTC511   0x040E4  /* Packets TX (256-511 bytes) - R/clr */
#define E1000_PTC1023  0x040E8  /* Packets TX (512-1023 bytes) - R/clr */
#define E1000_PTC1522  0x040EC  /* Packets TX (1024-1522 Bytes) - R/clr */
#define E1000_MPTC     0x040F0  /* Multicast Packets TX Count - R/clr */
#define E1000_BPTC     0x040F4  /* Broadcast Packets TX Count - R/clr */
#define E1000_TSCTC    0x040F8  /* TCP Segmentation Context TX - R/clr */
#define E1000_IAC      0x04100  /* Interrupt Assertion Count */
#define E1000_ICRXPTC  0x04104  /* Interrupt Cause Rx Packet Timer Expire Count */
#define E1000_ICRXDMTC 0x04120  /* Interrupt Cause Rx Descriptor Minimum Threshold Count */
#define E1000_RXCSUM   0x05000  /* RX Checksum Control - RW */
#define E1000_RFCTL    0x05008  /* Receive Filter Control*/
#define E1000_MAVTV0   0x05010  /* Management VLAN TAG Value 0 */
#define E1000_MAVTV1   0x05014  /* Management VLAN TAG Value 1 */
#define E1000_MAVTV2   0x05018  /* Management VLAN TAG Value 2 */
#define E1000_MAVTV3   0x0501c  /* Management VLAN TAG Value 3 */
#define E1000_MTA      0x05200  /* Multicast Table Array - RW Array */
#define E1000_RA       0x05400  /* Receive Address - RW Array */
#define E1000_RA_A     0x00040  /* Alias to RA */
#define E1000_VFTA     0x05600  /* VLAN Filter Table Array - RW Array */
#define E1000_VFTA_A   0x00600  /* Alias to VFTA */
#define E1000_WUC      0x05800  /* Wakeup Control - RW */
#define E1000_WUFC     0x05808  /* Wakeup Filter Control - RW */
#define E1000_WUS      0x05810  /* Wakeup Status - RO */
#define E1000_MANC     0x05820  /* Management Control - RW */
#define E1000_IPAV     0x05838  /* IP Address Valid - RW */
#define E1000_IP4AT    0x05840  /* IPv4 Address Table - RW Array */
#define E1000_IP6AT    0x05880  /* IPv6 Address Table - RW Array */
#define E1000_WUPL     0x05900  /* Wakeup Packet Length - RW */
#define E1000_WUPM     0x05A00  /* Wakeup Packet Memory - RO A */
#define E1000_MFVAL    0x05824  /* Manageability Filters Valid - RW */
#define E1000_MDEF     0x05890  /* Manageability Decision Filters - RW Array */
#define E1000_FFMT     0x09000  /* Flexible Filter Mask Table - RW Array */
#define E1000_FTFT     0x09400  /* Flexible TCO Filter Table - RW Array */

#define E1000_MANC2H     0x05860 /* Management Control To Host - RW */
#define E1000_SW_FW_SYNC 0x05B5C /* Software-Firmware Synchronization - RW */

#define E1000_GCR       0x05B00 /* PCI-Ex Control */
#define E1000_FUNCTAG   0x05B08 /* Function-Tag Register */
#define E1000_GSCL_1    0x05B10 /* PCI-Ex Statistic Control #1 */
#define E1000_GSCL_2    0x05B14 /* PCI-Ex Statistic Control #2 */
#define E1000_GSCL_3    0x05B18 /* PCI-Ex Statistic Control #3 */
#define E1000_GSCL_4    0x05B1C /* PCI-Ex Statistic Control #4 */
#define E1000_GSCN_0    0x05B20 /* 3GIO Statistic Counter Register #0 */
#define E1000_GSCN_1    0x05B24 /* 3GIO Statistic Counter Register #1 */
#define E1000_GSCN_2    0x05B28 /* 3GIO Statistic Counter Register #2 */
#define E1000_GSCN_3    0x05B2C /* 3GIO Statistic Counter Register #3 */
#define E1000_FACTPS    0x05B30 /* Function Active and Power State to MNG */
#define E1000_SWSM      0x05B50 /* SW Semaphore */
#define E1000_FWSM      0x05B54 /* FW Semaphore */
#define E1000_PBACLR    0x05B68 /* MSI-X PBA Clear */

#define E1000_TSYNCRXCTL 0x0B620 /* Rx Time Sync Control register - RW */
#define E1000_TSYNCTXCTL 0x0B614 /* Tx Time Sync Control register - RW */
#define E1000_TIMINCA    0x0B608 /* Increment attributes register - RW */
#define E1000_RXSTMPL    0x0B624 /* Rx timestamp Low - RO */
#define E1000_RXSTMPH    0x0B628 /* Rx timestamp High - RO */
#define E1000_TXSTMPL    0x0B618 /* Tx timestamp value Low - RO */
#define E1000_TXSTMPH    0x0B61C /* Tx timestamp value High - RO */
#define E1000_SYSTIML    0x0B600 /* System time register Low - RO */
#define E1000_SYSTIMH    0x0B604 /* System time register High - RO */
#define E1000_TIMINCA    0x0B608 /* Increment attributes register - RW */
#define E1000_RXSATRL    0x0B62C /* Rx timestamp attribute low - RO */
#define E1000_RXSATRH    0x0B630 /* Rx timestamp attribute high - RO */
#define E1000_TIMADJL    0x0B60C /* Time Adjustment Offset register Low - RW */
#define E1000_TIMADJH    0x0B610 /* Time Adjustment Offset register High - RW */

/* RSS registers */
#define E1000_MRQC      0x05818 /* Multiple Receive Control - RW */
#define E1000_RETA      0x05C00 /* Redirection Table - RW Array */
#define E1000_RSSRK     0x05C80 /* RSS Random Key - RW Array */

#define E1000_RETA_IDX(hash)        ((hash) & (BIT(7) - 1))
#define E1000_RETA_VAL(reta, hash)  (((uint8_t *)(reta))[E1000_RETA_IDX(hash)])

#define E1000_MRQC_EN_TCPIPV4(mrqc)   ((mrqc) & BIT(16))
#define E1000_MRQC_EN_IPV4(mrqc)      ((mrqc) & BIT(17))
#define E1000_MRQC_EN_TCPIPV6EX(mrqc) ((mrqc) & BIT(18))
#define E1000_MRQC_EN_IPV6EX(mrqc)    ((mrqc) & BIT(19))
#define E1000_MRQC_EN_IPV6(mrqc)      ((mrqc) & BIT(20))

#define E1000_MRQ_RSS_TYPE_NONE       (0)
#define E1000_MRQ_RSS_TYPE_IPV4TCP    (1)
#define E1000_MRQ_RSS_TYPE_IPV4       (2)
#define E1000_MRQ_RSS_TYPE_IPV6TCPEX  (3)
#define E1000_MRQ_RSS_TYPE_IPV6EX     (4)
#define E1000_MRQ_RSS_TYPE_IPV6       (5)

#define E1000_ICR_ASSERTED BIT(31)
#define E1000_EIAC_MASK    0x01F00000

/* RFCTL register bits */
#define E1000_RFCTL_ISCSI_DIS           0x00000001
#define E1000_RFCTL_NFSW_DIS            0x00000040
#define E1000_RFCTL_NFSR_DIS            0x00000080
#define E1000_RFCTL_IPV6_DIS            0x00000400
#define E1000_RFCTL_IPV6_XSUM_DIS       0x00000800
#define E1000_RFCTL_IPFRSP_DIS          0x00004000
#define E1000_RFCTL_EXTEN               0x00008000
#define E1000_RFCTL_IPV6_EX_DIS         0x00010000
#define E1000_RFCTL_NEW_IPV6_EXT_DIS    0x00020000

/* TARC* parsing */
#define E1000_TARC_ENABLE BIT(10)

/* SW Semaphore Register */
#define E1000_SWSM_SMBI         0x00000001 /* Driver Semaphore bit */
#define E1000_SWSM_SWESMBI      0x00000002 /* FW Semaphore bit */
#define E1000_SWSM_DRV_LOAD     0x00000008 /* Driver Loaded Bit */

#define E1000_SWSM2_LOCK        0x00000002 /* Secondary driver semaphore bit */

/* Interrupt Cause Read */
#define E1000_ICR_TXDW          0x00000001 /* Transmit desc written back */
#define E1000_ICR_TXQE          0x00000002 /* Transmit Queue empty */
#define E1000_ICR_LSC           0x00000004 /* Link Status Change */
#define E1000_ICR_RXSEQ         0x00000008 /* rx sequence error */
#define E1000_ICR_RXDMT0        0x00000010 /* rx desc min. threshold (0) */
#define E1000_ICR_RXO           0x00000040 /* rx overrun */
#define E1000_ICR_RXT0          0x00000080 /* rx timer intr (ring 0) */
#define E1000_ICR_RXDW          0x00000080 /* rx desc written back */
#define E1000_ICR_MDAC          0x00000200 /* MDIO access complete */
#define E1000_ICR_RXCFG         0x00000400 /* RX /c/ ordered set */
#define E1000_ICR_GPI_EN0       0x00000800 /* GP Int 0 */
#define E1000_ICR_GPI_EN1       0x00001000 /* GP Int 1 */
#define E1000_ICR_GPI_EN2       0x00002000 /* GP Int 2 */
#define E1000_ICR_GPI_EN3       0x00004000 /* GP Int 3 */
#define E1000_ICR_TXD_LOW       0x00008000
#define E1000_ICR_SRPD          0x00010000
#define E1000_ICR_ACK           0x00020000 /* Receive Ack frame */
#define E1000_ICR_MNG           0x00040000 /* Manageability event */
#define E1000_ICR_DOCK          0x00080000 /* Dock/Undock */
#define E1000_ICR_INT_ASSERTED  0x80000000 /* If this bit asserted, the driver should claim the interrupt */
#define E1000_ICR_RXD_FIFO_PAR0 0x00100000 /* queue 0 Rx descriptor FIFO parity error */
#define E1000_ICR_TXD_FIFO_PAR0 0x00200000 /* queue 0 Tx descriptor FIFO parity error */
#define E1000_ICR_HOST_ARB_PAR  0x00400000 /* host arb read buffer parity error */
#define E1000_ICR_PB_PAR        0x00800000 /* packet buffer parity error */
#define E1000_ICR_RXD_FIFO_PAR1 0x01000000 /* queue 1 Rx descriptor FIFO parity error */
#define E1000_ICR_TXD_FIFO_PAR1 0x02000000 /* queue 1 Tx descriptor FIFO parity error */
#define E1000_ICR_ALL_PARITY    0x03F00000 /* all parity error bits */
#define E1000_ICR_DSW           0x00000020 /* FW changed the status of DISSW bit in the FWSM */
#define E1000_ICR_PHYINT        0x00001000 /* LAN connected device generates an interrupt */
#define E1000_ICR_EPRST         0x00100000 /* ME handware reset occurs */
#define E1000_ICR_RXQ0          0x00100000 /* Rx Queue 0 Interrupt */
#define E1000_ICR_RXQ1          0x00200000 /* Rx Queue 1 Interrupt */
#define E1000_ICR_TXQ0          0x00400000 /* Tx Queue 0 Interrupt */
#define E1000_ICR_TXQ1          0x00800000 /* Tx Queue 1 Interrupt */
#define E1000_ICR_OTHER         0x01000000 /* Other Interrupts */

#define E1000_ICR_OTHER_CAUSES (E1000_ICR_LSC  | \
                                E1000_ICR_RXO  | \
                                E1000_ICR_MDAC | \
                                E1000_ICR_SRPD | \
                                E1000_ICR_ACK  | \
                                E1000_ICR_MNG)

/* Interrupt Cause Set */
#define E1000_ICS_TXDW      E1000_ICR_TXDW      /* Transmit desc written back */
#define E1000_ICS_TXQE      E1000_ICR_TXQE      /* Transmit Queue empty */
#define E1000_ICS_LSC       E1000_ICR_LSC       /* Link Status Change */
#define E1000_ICS_RXSEQ     E1000_ICR_RXSEQ     /* rx sequence error */
#define E1000_ICS_RXDMT0    E1000_ICR_RXDMT0    /* rx desc min. threshold */
#define E1000_ICS_RXO       E1000_ICR_RXO       /* rx overrun */
#define E1000_ICS_RXT0      E1000_ICR_RXT0      /* rx timer intr */
#define E1000_ICS_RXDW      E1000_ICR_RXDW      /* rx desc written back */
#define E1000_ICS_MDAC      E1000_ICR_MDAC      /* MDIO access complete */
#define E1000_ICS_RXCFG     E1000_ICR_RXCFG     /* RX /c/ ordered set */
#define E1000_ICS_GPI_EN0   E1000_ICR_GPI_EN0   /* GP Int 0 */
#define E1000_ICS_GPI_EN1   E1000_ICR_GPI_EN1   /* GP Int 1 */
#define E1000_ICS_GPI_EN2   E1000_ICR_GPI_EN2   /* GP Int 2 */
#define E1000_ICS_GPI_EN3   E1000_ICR_GPI_EN3   /* GP Int 3 */
#define E1000_ICS_TXD_LOW   E1000_ICR_TXD_LOW
#define E1000_ICS_SRPD      E1000_ICR_SRPD
#define E1000_ICS_ACK       E1000_ICR_ACK       /* Receive Ack frame */
#define E1000_ICS_MNG       E1000_ICR_MNG       /* Manageability event */
#define E1000_ICS_DOCK      E1000_ICR_DOCK      /* Dock/Undock */
#define E1000_ICS_RXD_FIFO_PAR0 E1000_ICR_RXD_FIFO_PAR0 /* queue 0 Rx descriptor FIFO parity error */
#define E1000_ICS_TXD_FIFO_PAR0 E1000_ICR_TXD_FIFO_PAR0 /* queue 0 Tx descriptor FIFO parity error */
#define E1000_ICS_HOST_ARB_PAR  E1000_ICR_HOST_ARB_PAR  /* host arb read buffer parity error */
#define E1000_ICS_PB_PAR        E1000_ICR_PB_PAR        /* packet buffer parity error */
#define E1000_ICS_RXD_FIFO_PAR1 E1000_ICR_RXD_FIFO_PAR1 /* queue 1 Rx descriptor FIFO parity error */
#define E1000_ICS_TXD_FIFO_PAR1 E1000_ICR_TXD_FIFO_PAR1 /* queue 1 Tx descriptor FIFO parity error */
#define E1000_ICS_DSW       E1000_ICR_DSW
#define E1000_ICS_PHYINT    E1000_ICR_PHYINT
#define E1000_ICS_EPRST     E1000_ICR_EPRST

/* Interrupt Mask Set */
#define E1000_IMS_TXDW      E1000_ICR_TXDW      /* Transmit desc written back */
#define E1000_IMS_TXQE      E1000_ICR_TXQE      /* Transmit Queue empty */
#define E1000_IMS_LSC       E1000_ICR_LSC       /* Link Status Change */
#define E1000_IMS_RXSEQ     E1000_ICR_RXSEQ     /* rx sequence error */
#define E1000_IMS_RXDMT0    E1000_ICR_RXDMT0    /* rx desc min. threshold */
#define E1000_IMS_RXO       E1000_ICR_RXO       /* rx overrun */
#define E1000_IMS_RXT0      E1000_ICR_RXT0      /* rx timer intr */
#define E1000_IMS_RXDW      E1000_ICR_RXDW      /* rx desc written back */
#define E1000_IMS_MDAC      E1000_ICR_MDAC      /* MDIO access complete */
#define E1000_IMS_RXCFG     E1000_ICR_RXCFG     /* RX /c/ ordered set */
#define E1000_IMS_GPI_EN0   E1000_ICR_GPI_EN0   /* GP Int 0 */
#define E1000_IMS_GPI_EN1   E1000_ICR_GPI_EN1   /* GP Int 1 */
#define E1000_IMS_GPI_EN2   E1000_ICR_GPI_EN2   /* GP Int 2 */
#define E1000_IMS_GPI_EN3   E1000_ICR_GPI_EN3   /* GP Int 3 */
#define E1000_IMS_TXD_LOW   E1000_ICR_TXD_LOW
#define E1000_IMS_SRPD      E1000_ICR_SRPD
#define E1000_IMS_ACK       E1000_ICR_ACK       /* Receive Ack frame */
#define E1000_IMS_MNG       E1000_ICR_MNG       /* Manageability event */
#define E1000_IMS_RXQ0      E1000_ICR_RXQ0
#define E1000_IMS_RXQ1      E1000_ICR_RXQ1
#define E1000_IMS_TXQ0      E1000_ICR_TXQ0
#define E1000_IMS_TXQ1      E1000_ICR_TXQ1
#define E1000_IMS_OTHER     E1000_ICR_OTHER
#define E1000_IMS_DOCK      E1000_ICR_DOCK      /* Dock/Undock */
#define E1000_IMS_RXD_FIFO_PAR0 E1000_ICR_RXD_FIFO_PAR0 /* queue 0 Rx descriptor FIFO parity error */
#define E1000_IMS_TXD_FIFO_PAR0 E1000_ICR_TXD_FIFO_PAR0 /* queue 0 Tx descriptor FIFO parity error */
#define E1000_IMS_HOST_ARB_PAR  E1000_ICR_HOST_ARB_PAR  /* host arb read buffer parity error */
#define E1000_IMS_PB_PAR        E1000_ICR_PB_PAR        /* packet buffer parity error */
#define E1000_IMS_RXD_FIFO_PAR1 E1000_ICR_RXD_FIFO_PAR1 /* queue 1 Rx descriptor FIFO parity error */
#define E1000_IMS_TXD_FIFO_PAR1 E1000_ICR_TXD_FIFO_PAR1 /* queue 1 Tx descriptor FIFO parity error */
#define E1000_IMS_DSW       E1000_ICR_DSW
#define E1000_IMS_PHYINT    E1000_ICR_PHYINT
#define E1000_IMS_EPRST     E1000_ICR_EPRST

/* Interrupt Mask Clear */
#define E1000_IMC_TXDW      E1000_ICR_TXDW      /* Transmit desc written back */
#define E1000_IMC_TXQE      E1000_ICR_TXQE      /* Transmit Queue empty */
#define E1000_IMC_LSC       E1000_ICR_LSC       /* Link Status Change */
#define E1000_IMC_RXSEQ     E1000_ICR_RXSEQ     /* rx sequence error */
#define E1000_IMC_RXDMT0    E1000_ICR_RXDMT0    /* rx desc min. threshold */
#define E1000_IMC_RXO       E1000_ICR_RXO       /* rx overrun */
#define E1000_IMC_RXT0      E1000_ICR_RXT0      /* rx timer intr */
#define E1000_IMC_RXDW      E1000_ICR_RXDW      /* rx desc written back */
#define E1000_IMC_MDAC      E1000_ICR_MDAC      /* MDIO access complete */
#define E1000_IMC_RXCFG     E1000_ICR_RXCFG     /* RX /c/ ordered set */
#define E1000_IMC_GPI_EN0   E1000_ICR_GPI_EN0   /* GP Int 0 */
#define E1000_IMC_GPI_EN1   E1000_ICR_GPI_EN1   /* GP Int 1 */
#define E1000_IMC_GPI_EN2   E1000_ICR_GPI_EN2   /* GP Int 2 */
#define E1000_IMC_GPI_EN3   E1000_ICR_GPI_EN3   /* GP Int 3 */
#define E1000_IMC_TXD_LOW   E1000_ICR_TXD_LOW
#define E1000_IMC_SRPD      E1000_ICR_SRPD
#define E1000_IMC_ACK       E1000_ICR_ACK       /* Receive Ack frame */
#define E1000_IMC_MNG       E1000_ICR_MNG       /* Manageability event */
#define E1000_IMC_DOCK      E1000_ICR_DOCK      /* Dock/Undock */
#define E1000_IMC_RXD_FIFO_PAR0 E1000_ICR_RXD_FIFO_PAR0 /* queue 0 Rx descriptor FIFO parity error */
#define E1000_IMC_TXD_FIFO_PAR0 E1000_ICR_TXD_FIFO_PAR0 /* queue 0 Tx descriptor FIFO parity error */
#define E1000_IMC_HOST_ARB_PAR  E1000_ICR_HOST_ARB_PAR  /* host arb read buffer parity error */
#define E1000_IMC_PB_PAR        E1000_ICR_PB_PAR        /* packet buffer parity error */
#define E1000_IMC_RXD_FIFO_PAR1 E1000_ICR_RXD_FIFO_PAR1 /* queue 1 Rx descriptor FIFO parity error */
#define E1000_IMC_TXD_FIFO_PAR1 E1000_ICR_TXD_FIFO_PAR1 /* queue 1 Tx descriptor FIFO parity error */
#define E1000_IMC_DSW       E1000_ICR_DSW
#define E1000_IMC_PHYINT    E1000_ICR_PHYINT
#define E1000_IMC_EPRST     E1000_ICR_EPRST

/* Receive Control */
#define E1000_RCTL_RST            0x00000001    /* Software reset */
#define E1000_RCTL_EN             0x00000002    /* enable */
#define E1000_RCTL_SBP            0x00000004    /* store bad packet */
#define E1000_RCTL_UPE            0x00000008    /* unicast promiscuous enable */
#define E1000_RCTL_MPE            0x00000010    /* multicast promiscuous enab */
#define E1000_RCTL_LPE            0x00000020    /* long packet enable */
#define E1000_RCTL_LBM_NO         0x00000000    /* no loopback mode */
#define E1000_RCTL_LBM_MAC        0x00000040    /* MAC loopback mode */
#define E1000_RCTL_LBM_SLP        0x00000080    /* serial link loopback mode */
#define E1000_RCTL_LBM_TCVR       0x000000C0    /* tcvr loopback mode */
#define E1000_RCTL_DTYP_MASK      0x00000C00    /* Descriptor type mask */
#define E1000_RCTL_DTYP_PS        0x00000400    /* Packet Split descriptor */
#define E1000_RCTL_RDMTS_HALF     0x00000000    /* rx desc min threshold size */
#define E1000_RCTL_RDMTS_QUAT     0x00000100    /* rx desc min threshold size */
#define E1000_RCTL_RDMTS_EIGTH    0x00000200    /* rx desc min threshold size */
#define E1000_RCTL_MO_SHIFT       12            /* multicast offset shift */
#define E1000_RCTL_MO_0           0x00000000    /* multicast offset 11:0 */
#define E1000_RCTL_MO_1           0x00001000    /* multicast offset 12:1 */
#define E1000_RCTL_MO_2           0x00002000    /* multicast offset 13:2 */
#define E1000_RCTL_MO_3           0x00003000    /* multicast offset 15:4 */
#define E1000_RCTL_MDR            0x00004000    /* multicast desc ring 0 */
#define E1000_RCTL_BAM            0x00008000    /* broadcast enable */
/* these buffer sizes are valid if E1000_RCTL_BSEX is 0 */
#define E1000_RCTL_SZ_2048        0x00000000    /* rx buffer size 2048 */
#define E1000_RCTL_SZ_1024        0x00010000    /* rx buffer size 1024 */
#define E1000_RCTL_SZ_512         0x00020000    /* rx buffer size 512 */
#define E1000_RCTL_SZ_256         0x00030000    /* rx buffer size 256 */
/* these buffer sizes are valid if E1000_RCTL_BSEX is 1 */
#define E1000_RCTL_SZ_16384       0x00010000    /* rx buffer size 16384 */
#define E1000_RCTL_SZ_8192        0x00020000    /* rx buffer size 8192 */
#define E1000_RCTL_SZ_4096        0x00030000    /* rx buffer size 4096 */
#define E1000_RCTL_VFE            0x00040000    /* vlan filter enable */
#define E1000_RCTL_CFIEN          0x00080000    /* canonical form enable */
#define E1000_RCTL_CFI            0x00100000    /* canonical form indicator */
#define E1000_RCTL_DPF            0x00400000    /* discard pause frames */
#define E1000_RCTL_PMCF           0x00800000    /* pass MAC control frames */
#define E1000_RCTL_BSEX           0x02000000    /* Buffer size extension */
#define E1000_RCTL_SECRC          0x04000000    /* Strip Ethernet CRC */
#define E1000_RCTL_FLXBUF_MASK    0x78000000    /* Flexible buffer size */
#define E1000_RCTL_FLXBUF_SHIFT   27            /* Flexible buffer shift */


#define E1000_EEPROM_SWDPIN0   0x0001   /* SWDPIN 0 EEPROM Value */
#define E1000_EEPROM_LED_LOGIC 0x0020   /* Led Logic Word */
#define E1000_EEPROM_RW_REG_DATA   16   /* Offset to data in EEPROM read/write registers */
#define E1000_EEPROM_RW_REG_DONE   0x10 /* Offset to READ/WRITE done bit */
#define E1000_EEPROM_RW_REG_START  1    /* First bit for telling part to start operation */
#define E1000_EEPROM_RW_ADDR_SHIFT 8    /* Shift to the address bits */
#define E1000_EEPROM_POLL_WRITE    1    /* Flag for polling for write complete */
#define E1000_EEPROM_POLL_READ     0    /* Flag for polling for read complete */

/* 82574 EERD/EEWR registers layout */
#define E1000_EERW_START        BIT(0)
#define E1000_EERW_DONE         BIT(1)
#define E1000_EERW_ADDR_SHIFT   2
#define E1000_EERW_ADDR_MASK    ((1L << 14) - 1)
#define E1000_EERW_DATA_SHIFT   16
#define E1000_EERW_DATA_MASK   ((1L << 16) - 1)

/* Register Bit Masks */
/* Device Control */
#define E1000_CTRL_FD       0x00000001  /* Full duplex.0=half; 1=full */
#define E1000_CTRL_BEM      0x00000002  /* Endian Mode.0=little,1=big */
#define E1000_CTRL_PRIOR    0x00000004  /* Priority on PCI. 0=rx,1=fair */
#define E1000_CTRL_GIO_MASTER_DISABLE 0x00000004 /*Blocks new Master requests */
#define E1000_CTRL_LRST     0x00000008  /* Link reset. 0=normal,1=reset */
#define E1000_CTRL_TME      0x00000010  /* Test mode. 0=normal,1=test */
#define E1000_CTRL_SLE      0x00000020  /* Serial Link on 0=dis,1=en */
#define E1000_CTRL_ASDE     0x00000020  /* Auto-speed detect enable */
#define E1000_CTRL_SLU      0x00000040  /* Set link up (Force Link) */
#define E1000_CTRL_ILOS     0x00000080  /* Invert Loss-Of Signal */
#define E1000_CTRL_SPD_SEL  0x00000300  /* Speed Select Mask */
#define E1000_CTRL_SPD_10   0x00000000  /* Force 10Mb */
#define E1000_CTRL_SPD_100  0x00000100  /* Force 100Mb */
#define E1000_CTRL_SPD_1000 0x00000200  /* Force 1Gb */
#define E1000_CTRL_BEM32    0x00000400  /* Big Endian 32 mode */
#define E1000_CTRL_FRCSPD   0x00000800  /* Force Speed */
#define E1000_CTRL_FRCDPX   0x00001000  /* Force Duplex */
#define E1000_CTRL_D_UD_EN  0x00002000  /* Dock/Undock enable */
#define E1000_CTRL_D_UD_POLARITY 0x00004000 /* Defined polarity of Dock/Undock indication in SDP[0] */
#define E1000_CTRL_FORCE_PHY_RESET 0x00008000 /* Reset both PHY ports, through PHYRST_N pin */
#define E1000_CTRL_SPD_SHIFT 8          /* Speed Select Shift */

#define E1000_CTRL_EXT_ASDCHK  0x00001000 /* auto speed detection check */
#define E1000_CTRL_EXT_EE_RST  0x00002000 /* EEPROM reset */
#define E1000_CTRL_EXT_LINK_EN 0x00010000 /* enable link status from external LINK_0 and LINK_1 pins */
#define E1000_CTRL_EXT_DRV_LOAD 0x10000000 /* Driver loaded bit for FW */
#define E1000_CTRL_EXT_EIAME   0x01000000
#define E1000_CTRL_EXT_IAME    0x08000000 /* Int ACK Auto-mask */
#define E1000_CTRL_EXT_PBA_CLR 0x80000000 /* PBA Clear */
#define E1000_CTRL_EXT_INT_TIMERS_CLEAR_ENA 0x20000000
#define E1000_CTRL_EXT_SPD_BYPS  0x00008000 /* Speed Select Bypass */

#define E1000_CTRL_SWDPIN0  0x00040000  /* SWDPIN 0 value */
#define E1000_CTRL_SWDPIN1  0x00080000  /* SWDPIN 1 value */
#define E1000_CTRL_SWDPIN2  0x00100000  /* SWDPIN 2 value */
#define E1000_CTRL_SWDPIN3  0x00200000  /* SWDPIN 3 value */
#define E1000_CTRL_SWDPIO0  0x00400000  /* SWDPIN 0 Input or output */
#define E1000_CTRL_SWDPIO1  0x00800000  /* SWDPIN 1 input or output */
#define E1000_CTRL_SWDPIO2  0x01000000  /* SWDPIN 2 input or output */
#define E1000_CTRL_SWDPIO3  0x02000000  /* SWDPIN 3 input or output */
#define E1000_CTRL_ADVD3WUC 0x00100000  /* D3 WUC */
#define E1000_CTRL_RST      0x04000000  /* Global reset */
#define E1000_CTRL_RFCE     0x08000000  /* Receive Flow Control enable */
#define E1000_CTRL_TFCE     0x10000000  /* Transmit flow control enable */
#define E1000_CTRL_RTE      0x20000000  /* Routing tag enable */
#define E1000_CTRL_VME      0x40000000  /* IEEE VLAN mode enable */
#define E1000_CTRL_PHY_RST  0x80000000  /* PHY Reset */
#define E1000_CTRL_SW2FW_INT 0x02000000  /* Initiate an interrupt to manageability engine */

/* Device Status */
#define E1000_STATUS_FD                 0x00000001 /* Full duplex.0=half,1=full */
#define E1000_STATUS_LU                 0x00000002 /* Link up.0=no,1=link */
#define E1000_STATUS_SPEED_10           0x00000000 /* Speed 10Mb/s */
#define E1000_STATUS_SPEED_100          0x00000040 /* Speed 100Mb/s */
#define E1000_STATUS_SPEED_1000         0x00000080 /* Speed 1000Mb/s */
#define E1000_STATUS_PHYRA              0x00000400 /* PHY Reset Asserted */
#define E1000_STATUS_GIO_MASTER_ENABLE  0x00080000

/* EEPROM/Flash Control */
#define E1000_EECD_SK        0x00000001 /* EEPROM Clock */
#define E1000_EECD_CS        0x00000002 /* EEPROM Chip Select */
#define E1000_EECD_DI        0x00000004 /* EEPROM Data In */
#define E1000_EECD_DO        0x00000008 /* EEPROM Data Out */
#define E1000_EECD_FWE_MASK  0x00000030
#define E1000_EECD_FWE_DIS   0x00000010 /* Disable FLASH writes */
#define E1000_EECD_FWE_EN    0x00000020 /* Enable FLASH writes */
#define E1000_EECD_FWE_SHIFT 4
#define E1000_EECD_REQ       0x00000040 /* EEPROM Access Request */
#define E1000_EECD_GNT       0x00000080 /* EEPROM Access Grant */
#define E1000_EECD_PRES      0x00000100 /* EEPROM Present */
#define E1000_EECD_SIZE      0x00000200 /* EEPROM Size (0=64 word 1=256 word) */
#define E1000_EECD_ADDR_BITS 0x00000400 /* EEPROM Addressing bits based on type
                                         * (0-small, 1-large) */
#define E1000_EECD_TYPE      0x00002000 /* EEPROM Type (1-SPI, 0-Microwire) */
#ifndef E1000_EEPROM_GRANT_ATTEMPTS
#define E1000_EEPROM_GRANT_ATTEMPTS 1000 /* EEPROM # attempts to gain grant */
#endif
#define E1000_EECD_AUTO_RD          0x00000200  /* EEPROM Auto Read done */
#define E1000_EECD_SIZE_EX_MASK     0x00007800  /* EEprom Size */
#define E1000_EECD_SIZE_EX_SHIFT    11
#define E1000_EECD_NVADDS    0x00018000 /* NVM Address Size */
#define E1000_EECD_SELSHAD   0x00020000 /* Select Shadow RAM */
#define E1000_EECD_INITSRAM  0x00040000 /* Initialize Shadow RAM */
#define E1000_EECD_FLUPD     0x00080000 /* Update FLASH */
#define E1000_EECD_AUPDEN    0x00100000 /* Enable Autonomous FLASH update */
#define E1000_EECD_SHADV     0x00200000 /* Shadow RAM Data Valid */
#define E1000_EECD_SEC1VAL   0x00400000 /* Sector One Valid */


#define E1000_EECD_SECVAL_SHIFT      22
#define E1000_STM_OPCODE     0xDB00
#define E1000_HICR_FW_RESET  0xC0

#define E1000_SHADOW_RAM_WORDS     2048
#define E1000_ICH_NVM_SIG_WORD     0x13
#define E1000_ICH_NVM_SIG_MASK     0xC0

/* MDI Control */
#define E1000_MDIC_DATA_MASK 0x0000FFFF
#define E1000_MDIC_REG_MASK  0x001F0000
#define E1000_MDIC_REG_SHIFT 16
#define E1000_MDIC_PHY_MASK  0x03E00000
#define E1000_MDIC_PHY_SHIFT 21
#define E1000_MDIC_OP_WRITE  0x04000000
#define E1000_MDIC_OP_READ   0x08000000
#define E1000_MDIC_READY     0x10000000
#define E1000_MDIC_INT_EN    0x20000000
#define E1000_MDIC_ERROR     0x40000000

/* Rx Interrupt Delay Timer */
#define E1000_RDTR_FPD       BIT(31)

/* Tx Interrupt Delay Timer */
#define E1000_TIDV_FPD       BIT(31)

/* Delay increments in nanoseconds for delayed interrupts registers */
#define E1000_INTR_DELAY_NS_RES (1024)

/* Delay increments in nanoseconds for interrupt throttling registers */
#define E1000_INTR_THROTTLING_NS_RES (256)

/* EEPROM Commands - Microwire */
#define EEPROM_READ_OPCODE_MICROWIRE  0x6  /* EEPROM read opcode */
#define EEPROM_WRITE_OPCODE_MICROWIRE 0x5  /* EEPROM write opcode */
#define EEPROM_ERASE_OPCODE_MICROWIRE 0x7  /* EEPROM erase opcode */
#define EEPROM_EWEN_OPCODE_MICROWIRE  0x13 /* EEPROM erase/write enable */
#define EEPROM_EWDS_OPCODE_MICROWIRE  0x10 /* EEPROM erast/write disable */

/* EEPROM Word Offsets */
#define EEPROM_COMPAT                 0x0003
#define EEPROM_ID_LED_SETTINGS        0x0004
#define EEPROM_VERSION                0x0005
#define EEPROM_SERDES_AMPLITUDE       0x0006 /* For SERDES output amplitude adjustment. */
#define EEPROM_PHY_CLASS_WORD         0x0007
#define EEPROM_INIT_CONTROL1_REG      0x000A
#define EEPROM_INIT_CONTROL2_REG      0x000F
#define EEPROM_SWDEF_PINS_CTRL_PORT_1 0x0010
#define EEPROM_INIT_CONTROL3_PORT_B   0x0014
#define EEPROM_INIT_3GIO_3            0x001A
#define EEPROM_SWDEF_PINS_CTRL_PORT_0 0x0020
#define EEPROM_INIT_CONTROL3_PORT_A   0x0024
#define EEPROM_CFG                    0x0012
#define EEPROM_FLASH_VERSION          0x0032
#define EEPROM_CHECKSUM_REG           0x003F

#define E1000_EEPROM_CFG_DONE         0x00040000   /* MNG config cycle done */
#define E1000_EEPROM_CFG_DONE_PORT_1  0x00080000   /* ...for second port */

/* HH Time Sync */
#define E1000_TSYNCTXCTL_MAX_ALLOWED_DLY_MASK 0x0000F000 /* max delay */
#define E1000_TSYNCTXCTL_SYNC_COMP            0x40000000 /* sync complete */
#define E1000_TSYNCTXCTL_START_SYNC           0x80000000 /* initiate sync */

#define E1000_TSYNCTXCTL_VALID                0x00000001 /* Tx timestamp valid */
#define E1000_TSYNCTXCTL_ENABLED              0x00000010 /* enable Tx timestamping */

#define E1000_TSYNCRXCTL_VALID                0x00000001 /* Rx timestamp valid */
#define E1000_TSYNCRXCTL_TYPE_MASK            0x0000000E /* Rx type mask */
#define E1000_TSYNCRXCTL_TYPE_L2_V2           0x00
#define E1000_TSYNCRXCTL_TYPE_L4_V1           0x02
#define E1000_TSYNCRXCTL_TYPE_L2_L4_V2        0x04
#define E1000_TSYNCRXCTL_TYPE_ALL             0x08
#define E1000_TSYNCRXCTL_TYPE_EVENT_V2        0x0A
#define E1000_TSYNCRXCTL_ENABLED              0x00000010 /* enable Rx timestamping */
#define E1000_TSYNCRXCTL_SYSCFI               0x00000020 /* Sys clock frequency */

#define E1000_RXMTRL_PTP_V1_SYNC_MESSAGE      0x00000000
#define E1000_RXMTRL_PTP_V1_DELAY_REQ_MESSAGE 0x00010000

#define E1000_RXMTRL_PTP_V2_SYNC_MESSAGE      0x00000000
#define E1000_RXMTRL_PTP_V2_DELAY_REQ_MESSAGE 0x01000000

#define E1000_TIMINCA_INCPERIOD_SHIFT         24
#define E1000_TIMINCA_INCVALUE_MASK           0x00FFFFFF

/* PCI Express Control */
/* 3GIO Control Register - GCR (0x05B00; RW) */
#define E1000_L0S_ADJUST              (1 << 9)
#define E1000_L1_ENTRY_LATENCY_MSB    (1 << 23)
#define E1000_L1_ENTRY_LATENCY_LSB    (1 << 25 | 1 << 26)

#define E1000_L0S_ADJUST              (1 << 9)
#define E1000_L1_ENTRY_LATENCY_MSB    (1 << 23)
#define E1000_L1_ENTRY_LATENCY_LSB    (1 << 25 | 1 << 26)

#define E1000_GCR_RO_BITS             (1 << 23 | 1 << 25 | 1 << 26)

/* MSI-X PBA Clear register */
#define E1000_PBACLR_VALID_MASK       (BIT(5) - 1)

/* Transmit Descriptor bit definitions */
#define E1000_TXD_DTYP_D     0x00100000 /* Data Descriptor */
#define E1000_TXD_DTYP_C     0x00000000 /* Context Descriptor */
#define E1000_TXD_CMD_EOP    0x01000000 /* End of Packet */
#define E1000_TXD_CMD_IFCS   0x02000000 /* Insert FCS (Ethernet CRC) */
#define E1000_TXD_CMD_IC     0x04000000 /* Insert Checksum */
#define E1000_TXD_CMD_RS     0x08000000 /* Report Status */
#define E1000_TXD_CMD_RPS    0x10000000 /* Report Packet Sent */
#define E1000_TXD_CMD_DEXT   0x20000000 /* Descriptor extension (0 = legacy) */
#define E1000_TXD_CMD_VLE    0x40000000 /* Add VLAN tag */
#define E1000_TXD_CMD_IDE    0x80000000 /* Enable Tidv register */
#define E1000_TXD_STAT_DD    0x00000001 /* Descriptor Done */
#define E1000_TXD_STAT_EC    0x00000002 /* Excess Collisions */
#define E1000_TXD_STAT_LC    0x00000004 /* Late Collisions */
#define E1000_TXD_STAT_TU    0x00000008 /* Transmit underrun */
#define E1000_TXD_CMD_TCP    0x01000000 /* TCP packet */
#define E1000_TXD_CMD_IP     0x02000000 /* IP packet */
#define E1000_TXD_CMD_TSE    0x04000000 /* TCP Seg enable */
#define E1000_TXD_CMD_SNAP   0x40000000 /* Update SNAP header */
#define E1000_TXD_STAT_TC    0x00000004 /* Tx Underrun */
#define E1000_TXD_EXTCMD_TSTAMP 0x00000010 /* IEEE1588 Timestamp packet */

/* Transmit Control */
#define E1000_TCTL_RST    0x00000001    /* software reset */
#define E1000_TCTL_EN     0x00000002    /* enable tx */
#define E1000_TCTL_BCE    0x00000004    /* busy check enable */
#define E1000_TCTL_PSP    0x00000008    /* pad short packets */
#define E1000_TCTL_CT     0x00000ff0    /* collision threshold */
#define E1000_TCTL_COLD   0x003ff000    /* collision distance */
#define E1000_TCTL_SWXOFF 0x00400000    /* SW Xoff transmission */
#define E1000_TCTL_PBE    0x00800000    /* Packet Burst Enable */
#define E1000_TCTL_RTLC   0x01000000    /* Re-transmit on late collision */
#define E1000_TCTL_NRTU   0x02000000    /* No Re-transmit on underrun */
#define E1000_TCTL_MULR   0x10000000    /* Multiple request support */

/* Legacy Receive Descriptor */
struct e1000_rx_desc {
    uint64_t buffer_addr; /* Address of the descriptor's data buffer */
    uint16_t length;     /* Length of data DMAed into data buffer */
    uint16_t csum;       /* Packet checksum */
    uint8_t status;      /* Descriptor status */
    uint8_t errors;      /* Descriptor Errors */
    uint16_t special;
};

/* Extended Receive Descriptor */
union e1000_rx_desc_extended {
    struct {
        uint64_t buffer_addr;
        uint64_t reserved;
    } read;
    struct {
        struct {
            uint32_t mrq;           /* Multiple Rx Queues */
            union {
                uint32_t rss;       /* RSS Hash */
                struct {
                    uint16_t ip_id; /* IP id */
                    uint16_t csum;  /* Packet Checksum */
                } csum_ip;
            } hi_dword;
        } lower;
        struct {
            uint32_t status_error;  /* ext status/error */
            uint16_t length;
            uint16_t vlan;          /* VLAN tag */
        } upper;
    } wb;                           /* writeback */
};

#define MAX_PS_BUFFERS 4

/* Number of packet split data buffers (not including the header buffer) */
#define PS_PAGE_BUFFERS    (MAX_PS_BUFFERS - 1)

/* Receive Descriptor - Packet Split */
union e1000_rx_desc_packet_split {
    struct {
        /* one buffer for protocol header(s), three data buffers */
        uint64_t buffer_addr[MAX_PS_BUFFERS];
    } read;
    struct {
        struct {
            uint32_t mrq;          /* Multiple Rx Queues */
            union {
                uint32_t rss;          /* RSS Hash */
                struct {
                    uint16_t ip_id;    /* IP id */
                    uint16_t csum;     /* Packet Checksum */
                } csum_ip;
            } hi_dword;
        } lower;
        struct {
            uint32_t status_error;     /* ext status/error */
            uint16_t length0;      /* length of buffer 0 */
            uint16_t vlan;         /* VLAN tag */
        } middle;
        struct {
            uint16_t header_status;
            /* length of buffers 1-3 */
            uint16_t length[PS_PAGE_BUFFERS];
        } upper;
        uint64_t reserved;
    } wb; /* writeback */
};

/* Receive Checksum Control bits */
#define E1000_RXCSUM_IPOFLD     0x100   /* IP Checksum Offload Enable */
#define E1000_RXCSUM_TUOFLD     0x200   /* TCP/UDP Checksum Offload Enable */
#define E1000_RXCSUM_PCSD       0x2000  /* Packet Checksum Disable */

#define E1000_RING_DESC_LEN       (16)
#define E1000_RING_DESC_LEN_SHIFT (4)

#define E1000_MIN_RX_DESC_LEN   E1000_RING_DESC_LEN

/* Receive Descriptor bit definitions */
#define E1000_RXD_STAT_DD       0x01    /* Descriptor Done */
#define E1000_RXD_STAT_EOP      0x02    /* End of Packet */
#define E1000_RXD_STAT_IXSM     0x04    /* Ignore checksum */
#define E1000_RXD_STAT_VP       0x08    /* IEEE VLAN Packet */
#define E1000_RXD_STAT_UDPCS    0x10    /* UDP xsum calculated */
#define E1000_RXD_STAT_TCPCS    0x20    /* TCP xsum calculated */
#define E1000_RXD_STAT_IPCS     0x40    /* IP xsum calculated */
#define E1000_RXD_STAT_PIF      0x80    /* passed in-exact filter */
#define E1000_RXD_STAT_IPIDV    0x200   /* IP identification valid */
#define E1000_RXD_STAT_UDPV     0x400   /* Valid UDP checksum */
#define E1000_RXD_STAT_ACK      0x8000  /* ACK Packet indication */
#define E1000_RXD_ERR_CE        0x01    /* CRC Error */
#define E1000_RXD_ERR_SE        0x02    /* Symbol Error */
#define E1000_RXD_ERR_SEQ       0x04    /* Sequence Error */
#define E1000_RXD_ERR_CXE       0x10    /* Carrier Extension Error */
#define E1000_RXD_ERR_TCPE      0x20    /* TCP/UDP Checksum Error */
#define E1000_RXD_ERR_IPE       0x40    /* IP Checksum Error */
#define E1000_RXD_ERR_RXE       0x80    /* Rx Data Error */
#define E1000_RXD_SPC_VLAN_MASK 0x0FFF  /* VLAN ID is in lower 12 bits */
#define E1000_RXD_SPC_PRI_MASK  0xE000  /* Priority is in upper 3 bits */
#define E1000_RXD_SPC_PRI_SHIFT 13
#define E1000_RXD_SPC_CFI_MASK  0x1000  /* CFI is bit 12 */
#define E1000_RXD_SPC_CFI_SHIFT 12

/* RX packet types */
#define E1000_RXD_PKT_MAC       (0)
#define E1000_RXD_PKT_IP4       (1)
#define E1000_RXD_PKT_IP4_XDP   (2)
#define E1000_RXD_PKT_IP6       (5)
#define E1000_RXD_PKT_IP6_XDP   (6)

#define E1000_RXD_PKT_TYPE(t) ((t) << 16)

#define E1000_RXDEXT_STATERR_CE    0x01000000
#define E1000_RXDEXT_STATERR_SE    0x02000000
#define E1000_RXDEXT_STATERR_SEQ   0x04000000
#define E1000_RXDEXT_STATERR_CXE   0x10000000
#define E1000_RXDEXT_STATERR_TCPE  0x20000000
#define E1000_RXDEXT_STATERR_IPE   0x40000000
#define E1000_RXDEXT_STATERR_RXE   0x80000000

#define E1000_RXDPS_HDRSTAT_HDRSP        0x00008000
#define E1000_RXDPS_HDRSTAT_HDRLEN_MASK  0x000003FF

/* Receive Address */
#define E1000_RAH_AV  0x80000000        /* Receive descriptor valid */

/* Offload Context Descriptor */
struct e1000_context_desc {
    union {
        uint32_t ip_config;
        struct {
            uint8_t ipcss;      /* IP checksum start */
            uint8_t ipcso;      /* IP checksum offset */
            uint16_t ipcse;     /* IP checksum end */
        } ip_fields;
    } lower_setup;
    union {
        uint32_t tcp_config;
        struct {
            uint8_t tucss;      /* TCP checksum start */
            uint8_t tucso;      /* TCP checksum offset */
            uint16_t tucse;     /* TCP checksum end */
        } tcp_fields;
    } upper_setup;
    uint32_t cmd_and_length;
    union {
        uint32_t data;
        struct {
            uint8_t status;     /* Descriptor status */
            uint8_t hdr_len;    /* Header length */
            uint16_t mss;       /* Maximum segment size */
        } fields;
    } tcp_seg_setup;
};

/* Filters */
#define E1000_NUM_UNICAST          16  /* Unicast filter entries */
#define E1000_MC_TBL_SIZE          128 /* Multicast Filter Table (4096 bits) */
#define E1000_VLAN_FILTER_TBL_SIZE 128 /* VLAN Filter Table (4096 bits) */

/* Management Control */
#define E1000_MANC_SMBUS_EN      0x00000001 /* SMBus Enabled - RO */
#define E1000_MANC_ASF_EN        0x00000002 /* ASF Enabled - RO */
#define E1000_MANC_R_ON_FORCE    0x00000004 /* Reset on Force TCO - RO */
#define E1000_MANC_RMCP_EN       0x00000100 /* Enable RCMP 026Fh Filtering */
#define E1000_MANC_0298_EN       0x00000200 /* Enable RCMP 0298h Filtering */
#define E1000_MANC_IPV4_EN       0x00000400 /* Enable IPv4 */
#define E1000_MANC_IPV6_EN       0x00000800 /* Enable IPv6 */
#define E1000_MANC_SNAP_EN       0x00001000 /* Accept LLC/SNAP */
#define E1000_MANC_ARP_EN        0x00002000 /* Enable ARP Request Filtering */
#define E1000_MANC_NEIGHBOR_EN   0x00004000 /* Enable Neighbor Discovery
                                             * Filtering */
#define E1000_MANC_ARP_RES_EN    0x00008000 /* Enable ARP response Filtering */
#define E1000_MANC_DIS_IP_CHK_ARP  0x10000000 /* Disable IP address chacking */
                                              /*for ARP packets - in 82574 */
#define E1000_MANC_TCO_RESET     0x00010000 /* TCO Reset Occurred */
#define E1000_MANC_RCV_TCO_EN    0x00020000 /* Receive TCO Packets Enabled */
#define E1000_MANC_REPORT_STATUS 0x00040000 /* Status Reporting Enabled */
#define E1000_MANC_RCV_ALL       0x00080000 /* Receive All Enabled */
#define E1000_MANC_BLK_PHY_RST_ON_IDE   0x00040000 /* Block phy resets */
#define E1000_MANC_EN_MAC_ADDR_FILTER   0x00100000 /* Enable MAC address
                                                    * filtering */
#define E1000_MANC_EN_MNG2HOST   0x00200000 /* Enable MNG packets to host
                                             * memory */
#define E1000_MANC_EN_IP_ADDR_FILTER    0x00400000 /* Enable IP address
                                                    * filtering */
#define E1000_MANC_EN_XSUM_FILTER   0x00800000 /* Enable checksum filtering */
#define E1000_MANC_BR_EN         0x01000000 /* Enable broadcast filtering */
#define E1000_MANC_SMB_REQ       0x01000000 /* SMBus Request */
#define E1000_MANC_SMB_GNT       0x02000000 /* SMBus Grant */
#define E1000_MANC_SMB_CLK_IN    0x04000000 /* SMBus Clock In */
#define E1000_MANC_SMB_DATA_IN   0x08000000 /* SMBus Data In */
#define E1000_MANC_SMB_DATA_OUT  0x10000000 /* SMBus Data Out */
#define E1000_MANC_SMB_CLK_OUT   0x20000000 /* SMBus Clock Out */

#define E1000_MANC_SMB_DATA_OUT_SHIFT  28 /* SMBus Data Out Shift */
#define E1000_MANC_SMB_CLK_OUT_SHIFT   29 /* SMBus Clock Out Shift */

/* FACTPS Control */
#define E1000_FACTPS_LAN0_ON     0x00000004 /* Lan 0 enable */

/* For checksumming, the sum of all words in the EEPROM should equal 0xBABA. */
#define EEPROM_SUM 0xBABA

/* I/O-Mapped Access to Internal Registers, Memories, and Flash */
#define E1000_IOADDR 0x00
#define E1000_IODATA 0x04

#define E1000_VFTA_ENTRY_SHIFT          5
#define E1000_VFTA_ENTRY_MASK           0x7F
#define E1000_VFTA_ENTRY_BIT_SHIFT_MASK 0x1F

#endif /* HW_E1000_REGS_H */
