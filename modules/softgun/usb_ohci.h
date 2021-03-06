#define OHCI_HcRevision 	(0)
#define OHCI_HcControl		(4)
#define		HcControl_CBSR_MASK	(3<<0)
#define		HcControl_CBSR(x)	((x)&3)
#define		HcControl_PLE		(1<<2)
#define		HcControl_IE		(1<<3)
#define		HcControl_CLE		(1<<4)
#define		HcControl_BLE		(1<<5)
#define		HcControl_HCFS_SHIFT	(6)
#define		HcControl_HCFS_MASK	(3<<6)
#define		HcControl_IR		(1<<8)
#define		HcControl_RWC		(1<<9)
#define		HcControl_RWE		(1<<10)
#define		HcFunctionalStateUsbReset	(0)
#define		HcFunctionalStateUsbResume	(1)
#define		HcFunctionalStateUsbOperational	(2)
#define		HcFunctionalStateUsbSuspend	(3)

#define OHCI_HcCommandStatus	(8)
#define		HcCommandStatus_HCR		(1)
#define		HcCommandStatus_CLF		(1<<1)
#define		HcCommandStatus_BLF		(1<<2)
#define		HcCommandStatus_OCR		(1<<3)
#define		HcCommandStatus_SOC_MASK	(3<<16)
#define		HcCommandStatus_SOC_SHIFT	(16)

#define OHCI_HcInterruptStatus  (0xc)
#define OHCI_HcInterruptEnable	(0x10)
#define OHCI_HcInterruptDisable (0x14)
#define		HCInterrupt_MIE	(1<<31)

/* Valid for Status, Enable and Disable  */
#define		HCInterrupt_SO	(1)
#define		HCInterrupt_WDH	(1<<1)
#define		HCInterrupt_SF	(1<<2)
#define		HCInterrupt_RD	(1<<3)
#define		HCInterrupt_UE	(1<<4)
#define		HCInterrupt_FNO	(1<<5)
#define		HCInterrupt_RHSC  (1<<6)
#define		HCInterrupt_OC	(1<<30)

#define OHCI_HcHCCA		(0x18)
#define OHCI_HcPeriodCurrentED  (0x1c)
#define OHCI_HcControlHeadED	(0x20)
#define OHCI_HcControlCurrentED (0x24)
#define OHCI_HcBulkHeadED	(0x28)
#define OHCI_HcBulkCurrentED	(0x2c)
#define OHCI_HcDoneHead		(0x30)
#define OHCI_HcFmInterval	(0x34)
#define		HcFmInterval_FI_MASK 		(0x3fff)
#define		HcFmInterval_FI_SHIFT 		(0)
#define		HcFmInterval_FSMPS_MASK 	(0x7fff0000)
#define		HcFmInterval_FSMPS_SHIFT	(16)
#define		HcFmInterval_FSMPS(x)		(((x)>>16)&0x7fff)
#define		HcFmInterval_FIT		(1<<31)

#define OHCI_HcFmRemaining	(0x38)
#define OHCI_HcFmNumber		(0x3c)
#define OHCI_HcPeriodicStart	(0x40)
#define OHCI_HcLSThreshold	(0x44)

/* Root Hub Partition */
#define OHCI_HcRhDescriptorA	(0x48)
#define		HcRhDescriptorA_NDP_MASK 	(0xff)
#define		HcRhDescriptorA_NDP_SHIFT 	(0)
#define		HcRhDescriptorA_NPS		(1<<8)
#define		HcRhDescriptorA_PSM		(1<<9)
#define		HcRhDescriptorA_DT		(1<<10)
#define		HcRhDescriptorA_OCPM		(1<<11)
#define		HcRhDescriptorA_NOCP		(1<<12)
#define		HcRhDescriptorA_POTPGT_MASK	(0xff<<24)
#define		HcRhDescriptorA_POTPGT_SHIFT	(24)

#define OHCI_HcRhDescriptorB	(0x4c)
#define 	HcRhDescriptorB_DR_MASK		(0xffff)
#define 	HcRhDescriptorB_DR_SHIFT	(0)
#define 	HcRhDescriptorB_PPCM_MASK	(0xffff<<16)
#define 	HcRhDescriptorB_PPCM_SHIFT	(16)

#define OHCI_HcRhStatus		(0x50)
#define		HcRhStatus_LPS	(1<<0)
#define		HcRhStatus_OCI	(1<<1)
#define		HcRhStatus_DRWE (1<<15)
#define		HcRhStatus_LPSC	(1<<16)
#define		HcRhStatus_CCIC (1<<17)
#define		HcRhStatus_CRWE	(1<<31)

#define OHCI_HcRhPortStatus(port)	(0x54+((port)<<2))
#define		HcRhPortStatus_CCS	(1<<0)
#define 	HcRhPortStatus_PES	(1<<1)
#define		HcRhPortStatus_PSS	(1<<2)
#define		HcRhPortStatus_POCI	(1<<3)
#define		HcRhPortStatus_PRS	(1<<4)
#define		HcRhPortStatus_PPS	(1<<8)
#define		HcRhPortStatus_LSDA	(1<<9)
#define		HcRhPortStatus_CSC	(1<<16)
#define		HcRhPortStatus_PESC	(1<<17)
#define		HcRhPortStatus_PSSC	(1<<18)
#define		HcRhPortStatus_OCIC	(1<<19)
#define		HcRhPortStatus_PRSC	(1<<20)

typedef struct OhciHC OhciHC;

BusDevice *OhciHC_New(char *name, Bus * bus);
void OhciHC_Disable(BusDevice * dev);
void OhciHC_Enable(BusDevice * dev);

/* Page 17 of hcir.pdf Definitions for Endpoint Descriptors */
/* DWORD0 */
#define ED_FA(ed)		((ed)->hwControl&0x7f)
#define ED_EN(ed)		(((ed)->hwControl>>7)&0xf)
#define	ED_D(ed)		(((ed)->hwControl>>11)&0x3)
#define	ED_S(ed)		(((ed)->hwControl>>13)&1)
#define	ED_K(ed)		(((ed)->hwControl>>14)&1)
#define	ED_F(ed)		(((ed)->hwControl>>15)&1)
#define ED_MPS(ed)		(((ed)->hwControl>>16)&0x7ff)

/* DWORD1 */
#define ED_TAILP(ed)		((ed)->hwTailP&~0xfUL)
/* DWORD2 */
#define ED_HEADP(ed)		((ed)->hwHeadP&~0xfUL)
#define ED_C(ed)		(((ed)->hwHeadP>>1)&1)
#define ED_H(ed)		((ed)->hwHeadP&1)
#define ED_NEXTED(ed)	        ((ed)->hwNextED&~0xfUL)

/* Transfer Descriptors */
#define ITD_CC(itd)	(((itd)->hwControl>>28)&0xf)
#define ITD_FC(itd)	(((itd)->hwControl>>24)&0x7)
#define	ITD_DI(itd)	(((itd)->hwControl>>21)&0x7)
#define ITD_SF(itd)	 ((itd)->hwControl&0xffff)

#define ITD_BP(itd) 	(((itd)->hwBP0&~0xfff))
#define ITD_NEXTTD(itd)	(((itd)->hwNextTD&~=0xf))
#define ITD_BE(itd)		((itd)->hwBE)

/* Condition / Completion Codes */
#define CC_NO_ERROR		 (0)
#define CC_CRC			 (1)
#define	CC_BIT_STUFFING 	 (2)
#define CC_DATA_TOGGLE_MISMATCH	 (3)
#define CC_STALL		 (4)
#define CC_DEVICE_NOT_RESPONDING (5)
#define CC_PID_CHECK_FAILURE	 (6)
#define CC_UNEXPECTED_PID	 (7)
#define CC_DATA_OVERRUN		 (8)
#define CC_DATA_UNDERRUN	 (9)
#define CC_BUFFER_OVERRUN	 (0xc)
#define	CC_BUFFER_UNDERRUN	 (0xd)
#define	CC_NOT_ACCESSED		 (0xe)
#define	CC_NOT_ACCESSED2	 (0xf)

#define GTD_R(gtd)		(((gtd)->hwControl>>18)&1)
#define	GTD_DP(gtd)		(((gtd)->hwControl>>19)&3)
#define GTD_DI(gtd)		(((gtd)->hwControl>>21)&3)
#define	GTD_T(gtd)		(((gtd)->hwControl>>24)&1)
#define GTD_EC(gtd)		(((gtd)->hwControl>>26) & 3)
#define GTD_CC(gtd)		(((gtd)->hwControl>>28) & 0xf)
#define GTD_CBP(gtd)		((gtd)->hwCBP)
#define GTD_NEXTTD(gtd)		((gtd)->hwNextTD)
#define GTD_BE(gtd)		((gtd)->hwBE)

#define TD_PID_OUT	(1)
#define TD_PID_IN	(2)
#define TD_PID_SETUP	(0)
