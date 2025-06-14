#ifndef HW_NVME_DIF_H
#define HW_NVME_DIF_H

/* from Linux kernel (crypto/crct10dif_common.c) */
static const uint16_t crc16_t10dif_table[256] = {
    0x0000, 0x8BB7, 0x9CD9, 0x176E, 0xB205, 0x39B2, 0x2EDC, 0xA56B,
    0xEFBD, 0x640A, 0x7364, 0xF8D3, 0x5DB8, 0xD60F, 0xC161, 0x4AD6,
    0x54CD, 0xDF7A, 0xC814, 0x43A3, 0xE6C8, 0x6D7F, 0x7A11, 0xF1A6,
    0xBB70, 0x30C7, 0x27A9, 0xAC1E, 0x0975, 0x82C2, 0x95AC, 0x1E1B,
    0xA99A, 0x222D, 0x3543, 0xBEF4, 0x1B9F, 0x9028, 0x8746, 0x0CF1,
    0x4627, 0xCD90, 0xDAFE, 0x5149, 0xF422, 0x7F95, 0x68FB, 0xE34C,
    0xFD57, 0x76E0, 0x618E, 0xEA39, 0x4F52, 0xC4E5, 0xD38B, 0x583C,
    0x12EA, 0x995D, 0x8E33, 0x0584, 0xA0EF, 0x2B58, 0x3C36, 0xB781,
    0xD883, 0x5334, 0x445A, 0xCFED, 0x6A86, 0xE131, 0xF65F, 0x7DE8,
    0x373E, 0xBC89, 0xABE7, 0x2050, 0x853B, 0x0E8C, 0x19E2, 0x9255,
    0x8C4E, 0x07F9, 0x1097, 0x9B20, 0x3E4B, 0xB5FC, 0xA292, 0x2925,
    0x63F3, 0xE844, 0xFF2A, 0x749D, 0xD1F6, 0x5A41, 0x4D2F, 0xC698,
    0x7119, 0xFAAE, 0xEDC0, 0x6677, 0xC31C, 0x48AB, 0x5FC5, 0xD472,
    0x9EA4, 0x1513, 0x027D, 0x89CA, 0x2CA1, 0xA716, 0xB078, 0x3BCF,
    0x25D4, 0xAE63, 0xB90D, 0x32BA, 0x97D1, 0x1C66, 0x0B08, 0x80BF,
    0xCA69, 0x41DE, 0x56B0, 0xDD07, 0x786C, 0xF3DB, 0xE4B5, 0x6F02,
    0x3AB1, 0xB106, 0xA668, 0x2DDF, 0x88B4, 0x0303, 0x146D, 0x9FDA,
    0xD50C, 0x5EBB, 0x49D5, 0xC262, 0x6709, 0xECBE, 0xFBD0, 0x7067,
    0x6E7C, 0xE5CB, 0xF2A5, 0x7912, 0xDC79, 0x57CE, 0x40A0, 0xCB17,
    0x81C1, 0x0A76, 0x1D18, 0x96AF, 0x33C4, 0xB873, 0xAF1D, 0x24AA,
    0x932B, 0x189C, 0x0FF2, 0x8445, 0x212E, 0xAA99, 0xBDF7, 0x3640,
    0x7C96, 0xF721, 0xE04F, 0x6BF8, 0xCE93, 0x4524, 0x524A, 0xD9FD,
    0xC7E6, 0x4C51, 0x5B3F, 0xD088, 0x75E3, 0xFE54, 0xE93A, 0x628D,
    0x285B, 0xA3EC, 0xB482, 0x3F35, 0x9A5E, 0x11E9, 0x0687, 0x8D30,
    0xE232, 0x6985, 0x7EEB, 0xF55C, 0x5037, 0xDB80, 0xCCEE, 0x4759,
    0x0D8F, 0x8638, 0x9156, 0x1AE1, 0xBF8A, 0x343D, 0x2353, 0xA8E4,
    0xB6FF, 0x3D48, 0x2A26, 0xA191, 0x04FA, 0x8F4D, 0x9823, 0x1394,
    0x5942, 0xD2F5, 0xC59B, 0x4E2C, 0xEB47, 0x60F0, 0x779E, 0xFC29,
    0x4BA8, 0xC01F, 0xD771, 0x5CC6, 0xF9AD, 0x721A, 0x6574, 0xEEC3,
    0xA415, 0x2FA2, 0x38CC, 0xB37B, 0x1610, 0x9DA7, 0x8AC9, 0x017E,
    0x1F65, 0x94D2, 0x83BC, 0x080B, 0xAD60, 0x26D7, 0x31B9, 0xBA0E,
    0xF0D8, 0x7B6F, 0x6C01, 0xE7B6, 0x42DD, 0xC96A, 0xDE04, 0x55B3
};

#define CRC64_NVME_POLY 0x9A6C9329AC4BC9B5ULL

static const uint64_t crc64_nvme_table[] = {
    0x0000000000000000ULL, 0x7F6EF0C830358979ULL,
    0xFEDDE190606B12F2ULL, 0x81B31158505E9B8BULL,
    0xC962E5739841B68FULL, 0xB60C15BBA8743FF6ULL,
    0x37BF04E3F82AA47DULL, 0x48D1F42BC81F2D04ULL,
    0xA61CECB46814FE75ULL, 0xD9721C7C5821770CULL,
    0x58C10D24087FEC87ULL, 0x27AFFDEC384A65FEULL,
    0x6F7E09C7F05548FAULL, 0x1010F90FC060C183ULL,
    0x91A3E857903E5A08ULL, 0xEECD189FA00BD371ULL,
    0x78E0FF3B88BE6F81ULL, 0x078E0FF3B88BE6F8ULL,
    0x863D1EABE8D57D73ULL, 0xF953EE63D8E0F40AULL,
    0xB1821A4810FFD90EULL, 0xCEECEA8020CA5077ULL,
    0x4F5FFBD87094CBFCULL, 0x30310B1040A14285ULL,
    0xDEFC138FE0AA91F4ULL, 0xA192E347D09F188DULL,
    0x2021F21F80C18306ULL, 0x5F4F02D7B0F40A7FULL,
    0x179EF6FC78EB277BULL, 0x68F0063448DEAE02ULL,
    0xE943176C18803589ULL, 0x962DE7A428B5BCF0ULL,
    0xF1C1FE77117CDF02ULL, 0x8EAF0EBF2149567BULL,
    0x0F1C1FE77117CDF0ULL, 0x7072EF2F41224489ULL,
    0x38A31B04893D698DULL, 0x47CDEBCCB908E0F4ULL,
    0xC67EFA94E9567B7FULL, 0xB9100A5CD963F206ULL,
    0x57DD12C379682177ULL, 0x28B3E20B495DA80EULL,
    0xA900F35319033385ULL, 0xD66E039B2936BAFCULL,
    0x9EBFF7B0E12997F8ULL, 0xE1D10778D11C1E81ULL,
    0x606216208142850AULL, 0x1F0CE6E8B1770C73ULL,
    0x8921014C99C2B083ULL, 0xF64FF184A9F739FAULL,
    0x77FCE0DCF9A9A271ULL, 0x08921014C99C2B08ULL,
    0x4043E43F0183060CULL, 0x3F2D14F731B68F75ULL,
    0xBE9E05AF61E814FEULL, 0xC1F0F56751DD9D87ULL,
    0x2F3DEDF8F1D64EF6ULL, 0x50531D30C1E3C78FULL,
    0xD1E00C6891BD5C04ULL, 0xAE8EFCA0A188D57DULL,
    0xE65F088B6997F879ULL, 0x9931F84359A27100ULL,
    0x1882E91B09FCEA8BULL, 0x67EC19D339C963F2ULL,
    0xD75ADABD7A6E2D6FULL, 0xA8342A754A5BA416ULL,
    0x29873B2D1A053F9DULL, 0x56E9CBE52A30B6E4ULL,
    0x1E383FCEE22F9BE0ULL, 0x6156CF06D21A1299ULL,
    0xE0E5DE5E82448912ULL, 0x9F8B2E96B271006BULL,
    0x71463609127AD31AULL, 0x0E28C6C1224F5A63ULL,
    0x8F9BD7997211C1E8ULL, 0xF0F5275142244891ULL,
    0xB824D37A8A3B6595ULL, 0xC74A23B2BA0EECECULL,
    0x46F932EAEA507767ULL, 0x3997C222DA65FE1EULL,
    0xAFBA2586F2D042EEULL, 0xD0D4D54EC2E5CB97ULL,
    0x5167C41692BB501CULL, 0x2E0934DEA28ED965ULL,
    0x66D8C0F56A91F461ULL, 0x19B6303D5AA47D18ULL,
    0x980521650AFAE693ULL, 0xE76BD1AD3ACF6FEAULL,
    0x09A6C9329AC4BC9BULL, 0x76C839FAAAF135E2ULL,
    0xF77B28A2FAAFAE69ULL, 0x8815D86ACA9A2710ULL,
    0xC0C42C4102850A14ULL, 0xBFAADC8932B0836DULL,
    0x3E19CDD162EE18E6ULL, 0x41773D1952DB919FULL,
    0x269B24CA6B12F26DULL, 0x59F5D4025B277B14ULL,
    0xD846C55A0B79E09FULL, 0xA72835923B4C69E6ULL,
    0xEFF9C1B9F35344E2ULL, 0x90973171C366CD9BULL,
    0x1124202993385610ULL, 0x6E4AD0E1A30DDF69ULL,
    0x8087C87E03060C18ULL, 0xFFE938B633338561ULL,
    0x7E5A29EE636D1EEAULL, 0x0134D92653589793ULL,
    0x49E52D0D9B47BA97ULL, 0x368BDDC5AB7233EEULL,
    0xB738CC9DFB2CA865ULL, 0xC8563C55CB19211CULL,
    0x5E7BDBF1E3AC9DECULL, 0x21152B39D3991495ULL,
    0xA0A63A6183C78F1EULL, 0xDFC8CAA9B3F20667ULL,
    0x97193E827BED2B63ULL, 0xE877CE4A4BD8A21AULL,
    0x69C4DF121B863991ULL, 0x16AA2FDA2BB3B0E8ULL,
    0xF86737458BB86399ULL, 0x8709C78DBB8DEAE0ULL,
    0x06BAD6D5EBD3716BULL, 0x79D4261DDBE6F812ULL,
    0x3105D23613F9D516ULL, 0x4E6B22FE23CC5C6FULL,
    0xCFD833A67392C7E4ULL, 0xB0B6C36E43A74E9DULL,
    0x9A6C9329AC4BC9B5ULL, 0xE50263E19C7E40CCULL,
    0x64B172B9CC20DB47ULL, 0x1BDF8271FC15523EULL,
    0x530E765A340A7F3AULL, 0x2C608692043FF643ULL,
    0xADD397CA54616DC8ULL, 0xD2BD67026454E4B1ULL,
    0x3C707F9DC45F37C0ULL, 0x431E8F55F46ABEB9ULL,
    0xC2AD9E0DA4342532ULL, 0xBDC36EC59401AC4BULL,
    0xF5129AEE5C1E814FULL, 0x8A7C6A266C2B0836ULL,
    0x0BCF7B7E3C7593BDULL, 0x74A18BB60C401AC4ULL,
    0xE28C6C1224F5A634ULL, 0x9DE29CDA14C02F4DULL,
    0x1C518D82449EB4C6ULL, 0x633F7D4A74AB3DBFULL,
    0x2BEE8961BCB410BBULL, 0x548079A98C8199C2ULL,
    0xD53368F1DCDF0249ULL, 0xAA5D9839ECEA8B30ULL,
    0x449080A64CE15841ULL, 0x3BFE706E7CD4D138ULL,
    0xBA4D61362C8A4AB3ULL, 0xC52391FE1CBFC3CAULL,
    0x8DF265D5D4A0EECEULL, 0xF29C951DE49567B7ULL,
    0x732F8445B4CBFC3CULL, 0x0C41748D84FE7545ULL,
    0x6BAD6D5EBD3716B7ULL, 0x14C39D968D029FCEULL,
    0x95708CCEDD5C0445ULL, 0xEA1E7C06ED698D3CULL,
    0xA2CF882D2576A038ULL, 0xDDA178E515432941ULL,
    0x5C1269BD451DB2CAULL, 0x237C997575283BB3ULL,
    0xCDB181EAD523E8C2ULL, 0xB2DF7122E51661BBULL,
    0x336C607AB548FA30ULL, 0x4C0290B2857D7349ULL,
    0x04D364994D625E4DULL, 0x7BBD94517D57D734ULL,
    0xFA0E85092D094CBFULL, 0x856075C11D3CC5C6ULL,
    0x134D926535897936ULL, 0x6C2362AD05BCF04FULL,
    0xED9073F555E26BC4ULL, 0x92FE833D65D7E2BDULL,
    0xDA2F7716ADC8CFB9ULL, 0xA54187DE9DFD46C0ULL,
    0x24F29686CDA3DD4BULL, 0x5B9C664EFD965432ULL,
    0xB5517ED15D9D8743ULL, 0xCA3F8E196DA80E3AULL,
    0x4B8C9F413DF695B1ULL, 0x34E26F890DC31CC8ULL,
    0x7C339BA2C5DC31CCULL, 0x035D6B6AF5E9B8B5ULL,
    0x82EE7A32A5B7233EULL, 0xFD808AFA9582AA47ULL,
    0x4D364994D625E4DAULL, 0x3258B95CE6106DA3ULL,
    0xB3EBA804B64EF628ULL, 0xCC8558CC867B7F51ULL,
    0x8454ACE74E645255ULL, 0xFB3A5C2F7E51DB2CULL,
    0x7A894D772E0F40A7ULL, 0x05E7BDBF1E3AC9DEULL,
    0xEB2AA520BE311AAFULL, 0x944455E88E0493D6ULL,
    0x15F744B0DE5A085DULL, 0x6A99B478EE6F8124ULL,
    0x224840532670AC20ULL, 0x5D26B09B16452559ULL,
    0xDC95A1C3461BBED2ULL, 0xA3FB510B762E37ABULL,
    0x35D6B6AF5E9B8B5BULL, 0x4AB846676EAE0222ULL,
    0xCB0B573F3EF099A9ULL, 0xB465A7F70EC510D0ULL,
    0xFCB453DCC6DA3DD4ULL, 0x83DAA314F6EFB4ADULL,
    0x0269B24CA6B12F26ULL, 0x7D0742849684A65FULL,
    0x93CA5A1B368F752EULL, 0xECA4AAD306BAFC57ULL,
    0x6D17BB8B56E467DCULL, 0x12794B4366D1EEA5ULL,
    0x5AA8BF68AECEC3A1ULL, 0x25C64FA09EFB4AD8ULL,
    0xA4755EF8CEA5D153ULL, 0xDB1BAE30FE90582AULL,
    0xBCF7B7E3C7593BD8ULL, 0xC399472BF76CB2A1ULL,
    0x422A5673A732292AULL, 0x3D44A6BB9707A053ULL,
    0x759552905F188D57ULL, 0x0AFBA2586F2D042EULL,
    0x8B48B3003F739FA5ULL, 0xF42643C80F4616DCULL,
    0x1AEB5B57AF4DC5ADULL, 0x6585AB9F9F784CD4ULL,
    0xE436BAC7CF26D75FULL, 0x9B584A0FFF135E26ULL,
    0xD389BE24370C7322ULL, 0xACE74EEC0739FA5BULL,
    0x2D545FB4576761D0ULL, 0x523AAF7C6752E8A9ULL,
    0xC41748D84FE75459ULL, 0xBB79B8107FD2DD20ULL,
    0x3ACAA9482F8C46ABULL, 0x45A459801FB9CFD2ULL,
    0x0D75ADABD7A6E2D6ULL, 0x721B5D63E7936BAFULL,
    0xF3A84C3BB7CDF024ULL, 0x8CC6BCF387F8795DULL,
    0x620BA46C27F3AA2CULL, 0x1D6554A417C62355ULL,
    0x9CD645FC4798B8DEULL, 0xE3B8B53477AD31A7ULL,
    0xAB69411FBFB21CA3ULL, 0xD407B1D78F8795DAULL,
    0x55B4A08FDFD90E51ULL, 0x2ADA5047EFEC8728ULL,
};

static inline size_t nvme_pi_tuple_size(NvmeNamespace *ns)
{
    return ns->pif ? 16 : 8;
}

uint16_t nvme_check_prinfo(NvmeNamespace *ns, uint8_t prinfo, uint64_t slba,
                           uint64_t reftag);
uint16_t nvme_dif_mangle_mdata(NvmeNamespace *ns, uint8_t *mbuf, size_t mlen,
                               uint64_t slba);
void nvme_dif_pract_generate_dif(NvmeNamespace *ns, uint8_t *buf, size_t len,
                                 uint8_t *mbuf, size_t mlen, uint16_t apptag,
                                 uint64_t *reftag);
uint16_t nvme_dif_check(NvmeNamespace *ns, uint8_t *buf, size_t len,
                        uint8_t *mbuf, size_t mlen, uint8_t prinfo,
                        uint64_t slba, uint16_t apptag,
                        uint16_t appmask, uint64_t *reftag);
uint16_t nvme_dif_rw(NvmeCtrl *n, NvmeRequest *req);

#endif /* HW_NVME_DIF_H */
