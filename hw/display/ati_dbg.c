#include "qemu/osdep.h"
#include "ati_int.h"

#ifdef DEBUG_ATI
struct ati_regdesc {
    const char *name;
    int num;
};

static struct ati_regdesc ati_reg_names[] = {
    {"MM_INDEX", 0x0000},
    {"MM_DATA", 0x0004},
    {"CLOCK_CNTL_INDEX", 0x0008},
    {"CLOCK_CNTL_DATA", 0x000c},
    {"BIOS_0_SCRATCH", 0x0010},
    {"BUS_CNTL", 0x0030},
    {"BUS_CNTL1", 0x0034},
    {"GEN_INT_CNTL", 0x0040},
    {"GEN_INT_STATUS", 0x0044},
    {"CRTC_GEN_CNTL", 0x0050},
    {"CRTC_EXT_CNTL", 0x0054},
    {"DAC_CNTL", 0x0058},
    {"GPIO_VGA_DDC", 0x0060},
    {"GPIO_DVI_DDC", 0x0064},
    {"GPIO_MONID", 0x0068},
    {"I2C_CNTL_1", 0x0094},
    {"AMCGPIO_MASK_MIR", 0x009c},
    {"AMCGPIO_A_MIR", 0x00a0},
    {"AMCGPIO_Y_MIR", 0x00a4},
    {"AMCGPIO_EN_MIR", 0x00a8},
    {"PALETTE_INDEX", 0x00b0},
    {"PALETTE_DATA", 0x00b4},
    {"PALETTE_30_DATA", 0x00b8},
    {"CNFG_CNTL", 0x00e0},
    {"GEN_RESET_CNTL", 0x00f0},
    {"CNFG_MEMSIZE", 0x00f8},
    {"CONFIG_APER_0_BASE", 0x0100},
    {"CONFIG_APER_1_BASE", 0x0104},
    {"CONFIG_APER_SIZE", 0x0108},
    {"CONFIG_REG_1_BASE", 0x010c},
    {"CONFIG_REG_APER_SIZE", 0x0110},
    {"HOST_PATH_CNTL", 0x0130},
    {"MEM_CNTL", 0x0140},
    {"MC_FB_LOCATION", 0x0148},
    {"MC_AGP_LOCATION", 0x014C},
    {"MC_STATUS", 0x0150},
    {"MEM_SDRAM_MODE_REG", 0x0158},
    {"MEM_POWER_MISC", 0x015c},
    {"AGP_BASE", 0x0170},
    {"AGP_CNTL", 0x0174},
    {"AGP_APER_OFFSET", 0x0178},
    {"PCI_GART_PAGE", 0x017c},
    {"PC_NGUI_MODE", 0x0180},
    {"PC_NGUI_CTLSTAT", 0x0184},
    {"MPP_TB_CONFIG", 0x01C0},
    {"MPP_GP_CONFIG", 0x01C8},
    {"VIPH_CONTROL", 0x01D0},
    {"CRTC_H_TOTAL_DISP", 0x0200},
    {"CRTC_H_SYNC_STRT_WID", 0x0204},
    {"CRTC_V_TOTAL_DISP", 0x0208},
    {"CRTC_V_SYNC_STRT_WID", 0x020c},
    {"CRTC_VLINE_CRNT_VLINE", 0x0210},
    {"CRTC_CRNT_FRAME", 0x0214},
    {"CRTC_GUI_TRIG_VLINE", 0x0218},
    {"CRTC_OFFSET", 0x0224},
    {"CRTC_OFFSET_CNTL", 0x0228},
    {"CRTC_PITCH", 0x022c},
    {"OVR_CLR", 0x0230},
    {"OVR_WID_LEFT_RIGHT", 0x0234},
    {"OVR_WID_TOP_BOTTOM", 0x0238},
    {"CUR_OFFSET", 0x0260},
    {"CUR_HORZ_VERT_POSN", 0x0264},
    {"CUR_HORZ_VERT_OFF", 0x0268},
    {"CUR_CLR0", 0x026c},
    {"CUR_CLR1", 0x0270},
    {"LVDS_GEN_CNTL", 0x02d0},
    {"DDA_CONFIG", 0x02e0},
    {"DDA_ON_OFF", 0x02e4},
    {"VGA_DDA_CONFIG", 0x02e8},
    {"VGA_DDA_ON_OFF", 0x02ec},
    {"CRTC2_H_TOTAL_DISP", 0x0300},
    {"CRTC2_H_SYNC_STRT_WID", 0x0304},
    {"CRTC2_V_TOTAL_DISP", 0x0308},
    {"CRTC2_V_SYNC_STRT_WID", 0x030c},
    {"CRTC2_VLINE_CRNT_VLINE", 0x0310},
    {"CRTC2_CRNT_FRAME", 0x0314},
    {"CRTC2_GUI_TRIG_VLINE", 0x0318},
    {"CRTC2_OFFSET", 0x0324},
    {"CRTC2_OFFSET_CNTL", 0x0328},
    {"CRTC2_PITCH", 0x032c},
    {"DDA2_CONFIG", 0x03e0},
    {"DDA2_ON_OFF", 0x03e4},
    {"CRTC2_GEN_CNTL", 0x03f8},
    {"CRTC2_STATUS", 0x03fc},
    {"OV0_SCALE_CNTL", 0x0420},
    {"SUBPIC_CNTL", 0x0540},
    {"PM4_BUFFER_OFFSET", 0x0700},
    {"PM4_BUFFER_CNTL", 0x0704},
    {"PM4_BUFFER_WM_CNTL", 0x0708},
    {"PM4_BUFFER_DL_RPTR_ADDR", 0x070c},
    {"PM4_BUFFER_DL_RPTR", 0x0710},
    {"PM4_BUFFER_DL_WPTR", 0x0714},
    {"PM4_VC_FPU_SETUP", 0x071c},
    {"PM4_FPU_CNTL", 0x0720},
    {"PM4_VC_FORMAT", 0x0724},
    {"PM4_VC_CNTL", 0x0728},
    {"PM4_VC_I01", 0x072c},
    {"PM4_VC_VLOFF", 0x0730},
    {"PM4_VC_VLSIZE", 0x0734},
    {"PM4_IW_INDOFF", 0x0738},
    {"PM4_IW_INDSIZE", 0x073c},
    {"PM4_FPU_FPX0", 0x0740},
    {"PM4_FPU_FPY0", 0x0744},
    {"PM4_FPU_FPX1", 0x0748},
    {"PM4_FPU_FPY1", 0x074c},
    {"PM4_FPU_FPX2", 0x0750},
    {"PM4_FPU_FPY2", 0x0754},
    {"PM4_FPU_FPY3", 0x0758},
    {"PM4_FPU_FPY4", 0x075c},
    {"PM4_FPU_FPY5", 0x0760},
    {"PM4_FPU_FPY6", 0x0764},
    {"PM4_FPU_FPR", 0x0768},
    {"PM4_FPU_FPG", 0x076c},
    {"PM4_FPU_FPB", 0x0770},
    {"PM4_FPU_FPA", 0x0774},
    {"PM4_FPU_INTXY0", 0x0780},
    {"PM4_FPU_INTXY1", 0x0784},
    {"PM4_FPU_INTXY2", 0x0788},
    {"PM4_FPU_INTARGB", 0x078c},
    {"PM4_FPU_FPTWICEAREA", 0x0790},
    {"PM4_FPU_DMAJOR01", 0x0794},
    {"PM4_FPU_DMAJOR12", 0x0798},
    {"PM4_FPU_DMAJOR02", 0x079c},
    {"PM4_FPU_STAT", 0x07a0},
    {"PM4_STAT", 0x07b8},
    {"PM4_TEST_CNTL", 0x07d0},
    {"PM4_MICROCODE_ADDR", 0x07d4},
    {"PM4_MICROCODE_RADDR", 0x07d8},
    {"PM4_MICROCODE_DATAH", 0x07dc},
    {"PM4_MICROCODE_DATAL", 0x07e0},
    {"PM4_CMDFIFO_ADDR", 0x07e4},
    {"PM4_CMDFIFO_DATAH", 0x07e8},
    {"PM4_CMDFIFO_DATAL", 0x07ec},
    {"PM4_BUFFER_ADDR", 0x07f0},
    {"PM4_BUFFER_DATAH", 0x07f4},
    {"PM4_BUFFER_DATAL", 0x07f8},
    {"PM4_MICRO_CNTL", 0x07fc},
    {"CAP0_TRIG_CNTL", 0x0950},
    {"CAP1_TRIG_CNTL", 0x09c0},
    {"RBBM_STATUS", 0x0e40},
    {"PM4_FIFO_DATA_EVEN", 0x1000},
    {"PM4_FIFO_DATA_ODD", 0x1004},
    {"DST_OFFSET", 0x1404},
    {"DST_PITCH", 0x1408},
    {"DST_WIDTH", 0x140c},
    {"DST_HEIGHT", 0x1410},
    {"SRC_X", 0x1414},
    {"SRC_Y", 0x1418},
    {"DST_X", 0x141c},
    {"DST_Y", 0x1420},
    {"SRC_PITCH_OFFSET", 0x1428},
    {"DST_PITCH_OFFSET", 0x142c},
    {"SRC_Y_X", 0x1434},
    {"DST_Y_X", 0x1438},
    {"DST_HEIGHT_WIDTH", 0x143c},
    {"DP_GUI_MASTER_CNTL", 0x146c},
    {"BRUSH_SCALE", 0x1470},
    {"BRUSH_Y_X", 0x1474},
    {"DP_BRUSH_BKGD_CLR", 0x1478},
    {"DP_BRUSH_FRGD_CLR", 0x147c},
    {"DST_WIDTH_X", 0x1588},
    {"DST_HEIGHT_WIDTH_8", 0x158c},
    {"SRC_X_Y", 0x1590},
    {"DST_X_Y", 0x1594},
    {"DST_WIDTH_HEIGHT", 0x1598},
    {"DST_WIDTH_X_INCY", 0x159c},
    {"DST_HEIGHT_Y", 0x15a0},
    {"DST_X_SUB", 0x15a4},
    {"DST_Y_SUB", 0x15a8},
    {"SRC_OFFSET", 0x15ac},
    {"SRC_PITCH", 0x15b0},
    {"DST_HEIGHT_WIDTH_BW", 0x15b4},
    {"CLR_CMP_CNTL", 0x15c0},
    {"CLR_CMP_CLR_SRC", 0x15c4},
    {"CLR_CMP_CLR_DST", 0x15c8},
    {"CLR_CMP_MASK", 0x15cc},
    {"DP_SRC_FRGD_CLR", 0x15d8},
    {"DP_SRC_BKGD_CLR", 0x15dc},
    {"DST_BRES_ERR", 0x1628},
    {"DST_BRES_INC", 0x162c},
    {"DST_BRES_DEC", 0x1630},
    {"DST_BRES_LNTH", 0x1634},
    {"DST_BRES_LNTH_SUB", 0x1638},
    {"SC_LEFT", 0x1640},
    {"SC_RIGHT", 0x1644},
    {"SC_TOP", 0x1648},
    {"SC_BOTTOM", 0x164c},
    {"SRC_SC_RIGHT", 0x1654},
    {"SRC_SC_BOTTOM", 0x165c},
    {"GUI_DEBUG0", 0x16a0},
    {"GUI_DEBUG1", 0x16a4},
    {"GUI_TIMEOUT", 0x16b0},
    {"GUI_TIMEOUT0", 0x16b4},
    {"GUI_TIMEOUT1", 0x16b8},
    {"GUI_PROBE", 0x16bc},
    {"DP_CNTL", 0x16c0},
    {"DP_DATATYPE", 0x16c4},
    {"DP_MIX", 0x16c8},
    {"DP_WRITE_MASK", 0x16cc},
    {"DP_CNTL_XDIR_YDIR_YMAJOR", 0x16d0},
    {"DEFAULT_OFFSET", 0x16e0},
    {"DEFAULT_PITCH", 0x16e4},
    {"DEFAULT_SC_BOTTOM_RIGHT", 0x16e8},
    {"SC_TOP_LEFT", 0x16ec},
    {"SC_BOTTOM_RIGHT", 0x16f0},
    {"SRC_SC_BOTTOM_RIGHT", 0x16f4},
    {"DST_TILE", 0x1700},
    {"WAIT_UNTIL", 0x1720},
    {"CACHE_CNTL", 0x1724},
    {"GUI_STAT", 0x1740},
    {"PC_GUI_MODE", 0x1744},
    {"PC_GUI_CTLSTAT", 0x1748},
    {"PC_DEBUG_MODE", 0x1760},
    {"BRES_DST_ERR_DEC", 0x1780},
    {"TRAIL_BRES_T12_ERR_DEC", 0x1784},
    {"TRAIL_BRES_T12_INC", 0x1788},
    {"DP_T12_CNTL", 0x178c},
    {"DST_BRES_T1_LNTH", 0x1790},
    {"DST_BRES_T2_LNTH", 0x1794},
    {"SCALE_SRC_HEIGHT_WIDTH", 0x1994},
    {"SCALE_OFFSET_0", 0x1998},
    {"SCALE_PITCH", 0x199c},
    {"SCALE_X_INC", 0x19a0},
    {"SCALE_Y_INC", 0x19a4},
    {"SCALE_HACC", 0x19a8},
    {"SCALE_VACC", 0x19ac},
    {"SCALE_DST_X_Y", 0x19b0},
    {"SCALE_DST_HEIGHT_WIDTH", 0x19b4},
    {"SCALE_3D_CNTL", 0x1a00},
    {"SCALE_3D_DATATYPE", 0x1a20},
    {"SETUP_CNTL", 0x1bc4},
    {"SOLID_COLOR", 0x1bc8},
    {"WINDOW_XY_OFFSET", 0x1bcc},
    {"DRAW_LINE_POINT", 0x1bd0},
    {"SETUP_CNTL_PM4", 0x1bd4},
    {"DST_PITCH_OFFSET_C", 0x1c80},
    {"DP_GUI_MASTER_CNTL_C", 0x1c84},
    {"SC_TOP_LEFT_C", 0x1c88},
    {"SC_BOTTOM_RIGHT_C", 0x1c8c},
    {"CLR_CMP_MASK_3D", 0x1A28},
    {"MISC_3D_STATE_CNTL_REG", 0x1CA0},
    {"MC_SRC1_CNTL", 0x19D8},
    {"TEX_CNTL", 0x1800},
    {"RAGE128_MPP_TB_CONFIG", 0x01c0},
    {NULL, -1}
};

const char *ati_reg_name(int num)
{
    int i;

    num &= ~3;
    for (i = 0; ati_reg_names[i].name; i++) {
        if (ati_reg_names[i].num == num) {
            return ati_reg_names[i].name;
        }
    }
    return "unknown";
}
#else
const char *ati_reg_name(int num)
{
    return "";
}
#endif
