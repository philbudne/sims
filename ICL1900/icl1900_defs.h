/* icl1900_defs.h: ICL1900 simulator definitions 

   Copyright (c) 2017, Richard Cornwell

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   RICHARD CORNWELL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#ifndef _ICL1900_H_
#define _ICL1900_H_

#include "sim_defs.h"                                   /* simulator defns */

/* Definitions for each supported CPU */

#define NUM_DEVS_CDR    0
#define NUM_DEVS_CDP    0
#define NUM_DEVS_LPR    0
#define NUM_DEVS_CON    0
#define NUM_DEVS_MT     0
#define NUM_DEVS_DSK    0
#define NUM_DEVS_DTC    0
#define MAXMEMSIZE      (4096 * 1024)

extern uint32           M[];                            /* Main Memory */

/* Memory */
#define MEMSIZE         (cpu_unit[0].capac)             /* actual memory size */
#define MEMMASK         (MEMSIZE - 1)                   /* Memory bits */


/* Debuging controls */
#define DEBUG_CHAN      0x0000001       /* Show channel fetchs */
#define DEBUG_TRAP      0x0000002       /* Show CPU Traps */
#define DEBUG_CMD       0x0000004       /* Show device commands */
#define DEBUG_DATA      0x0000008       /* Show data transfers */
#define DEBUG_DETAIL    0x0000010       /* Show details */
#define DEBUG_EXP       0x0000020       /* Show error conditions */
#define DEBUG_SNS       0x0000040       /* Shows sense data for 7909 devs */
#define DEBUG_CTSS      0x0000080       /* Shows CTSS specail instructions */
#define DEBUG_PROT      0x0000100       /* Protection traps */

extern DEBTAB dev_debug[];


/* Returns from device commands */
#define SCPE_BUSY       (1)     /* Device is active */
#define SCPE_NODEV      (2)     /* No device exists */

/* Symbol tables */
typedef struct _opcode
{
    const char          *name;
    uint8               type;
}
t_opcode;

#define OP_LDX        0000          /* Load to X */
#define OP_ADX        0001          /* Add to X */
#define OP_NGX        0002          /* Negative to X */
#define OP_SBX        0003          /* Subtract from X */
#define OP_LDXC       0004          /* Load into X with carry */
#define OP_ADXC       0005          /* Add to X with carry */
#define OP_NGXC       0006          /* Negative to X with carry */
#define OP_SBXC       0007          /* Subtract from X with carry */
#define OP_STO        0010          /* Store contents of X */
#define OP_ADS        0011          /* Add X to store */
#define OP_NGS        0012          /* Negative into Store */
#define OP_SBS        0013          /* Subtract from store */
#define OP_STOC       0014          /* Store contents of X with carry */
#define OP_ADSC       0015          /* Add X to store with carry */
#define OP_NGSC       0016          /* Negative into Store with carry */
#define OP_SBSC       0017          /* Subtract from store with carry */
#define OP_ANDX       0020          /* Logical AND into X */
#define OP_ORX        0021          /* Logical OR into X */
#define OP_ERX        0022          /* Logical XOR into X */
#define OP_OBEY       0023          /* Obey instruction at N */
#define OP_LDCH       0024          /* Load Character to X */
#define OP_LDEX       0025          /* Load Exponent */
#define OP_TXU        0026          /* Test X unequal */
#define OP_TXL        0027          /* Test X Less */
#define OP_ANDS       0030          /* Logical AND into store */
#define OP_ORS        0031          /* Logical OR into store */
#define OP_ERS        0032          /* Logical XOR into store */
#define OP_STOZ       0033          /* Store Zero */
#define OP_DCH        0034          /* Deposit Character to X */
#define OP_DEX        0035          /* Deposit Exponent */
#define OP_DSA        0036          /* Deposit Short Address */
#define OP_DLA        0037          /* Deposit Long Address */
#define OP_MPY        0040          /* Multiply */
#define OP_MPR        0041          /* Multiply and Round */
#define OP_MPA        0042          /* Multiply and Accumulate */
#define OP_CDB        0043          /* Convert Decimal to Binary */
#define OP_DVD        0044          /* Unrounded Double Length Divide */
#define OP_DVR        0045          /* Rounded Double Length Divide */
#define OP_DVS        0046          /* Single Length Divide */
#define OP_CBD        0047          /* Convert Binary to Decimal */
#define OP_BZE        0050          /* Branch if X is Zero */
#define OP_BZE1       0051 
#define OP_BNZ        0052          /* Branch if X is not Zero */
#define OP_BNZ1       0053
#define OP_BPZ        0054          /* Branch if X is Positive or zero */
#define OP_BPZ1       0055
#define OP_BNG        0056          /* Branch if X is Positive or zero */
#define OP_BNG1       0057 
#define OP_BUX        0060          /* Branch on Unit indexing */
#define OP_BUX1       0061
#define OP_BDX        0062          /* Branch on Double Indexing */
#define OP_BDX1       0063
#define OP_BCHX       0064          /* Branch on Character Indexing */
#define OP_BCHX1      0065
#define OP_BCT        0066          /* Branch on Count - BC */
#define OP_BCT1       0067
#define OP_CALL       0070          /* Call Subroutine */
#define OP_CALL1      0071
#define OP_EXIT       0072          /* Exit Subroutine */
#define OP_EXIT1      0073
#define OP_BRN        0074          /* Branch unconditional */
#define OP_BRN1       0075
#define OP_BFP        0076          /* Branch state of floating point accumulator */
#define OP_BFP1       0077
#define OP_LDN        0100          /* Load direct to X */
#define OP_ADN        0101          /* Add direct to X */
#define OP_NGN        0102          /* Negative direct to X */
#define OP_SBN        0103          /* Subtract direct from X */
#define OP_LDNC       0104          /* Load direct into X with carry */
#define OP_ADNC       0105          /* Add direct to X with carry */
#define OP_NGNC       0106          /* Negative direct to X with carry */
#define OP_SBNC       0107          /* Subtract direct from X with carry */
#define OP_SLL        0110          /* Shift Left */
#define OP_SLD        0111          /* Shift Left Double */
#define OP_SRL        0112          /* Shift Right  */
#define OP_SRD        0113          /* Shift Right Double*/
#define OP_NORM       0114          /* Nomarlize Single -2 +FP */
#define OP_NORMD      0115          /* Normalize Double -2 +FP */
#define OP_MVCH       0116          /* Move Characters - BC */
#define OP_SMO        0117          /* Supplementary Modifier - BC  */
#define OP_ANDN       0120          /* Logical AND direct into X */
#define OP_ORN        0121          /* Logical OR direct into X */
#define OP_ERN        0122          /* Logical XOR direct into X */
#define OP_NULL       0123          /* No Operation */
#define OP_LDCT       0124          /* Load Count */
#define OP_MODE       0125          /* Set Mode */
#define OP_MOVE       0126          /* Copy N words */
#define OP_SUM        0127          /* Sum N words */
#define OP_FLOAT      0130          /* Convert Fixed to Float +FP */
#define OP_FIX        0131          /* Convert Float to Fixed +FP */
#define OP_FAD        0132          /* Floating Point Add +FP */
#define OP_FSB        0133          /* Floating Point Subtract +FP */
#define OP_FMPY       0134          /* Floating Point Multiply +FP */
#define OP_FDVD       0135          /* Floating Point Divide +FP */
#define OP_LFP        0136          /* Load Floating Point +FP */
#define OP_SFP        0137          /* Store Floating Point +FP */

#define FMASK          077777777
#define CMASK          060000000
#define BM1           0100000000
#define B0             040000000
#define B1             020000000
#define B2             010000000
#define B3             004000000
#define B8             000100000
#define B15            000040000
#define B14            000020000
#define M9             000000777
#define M12            000007777
#define M15            000077777
#define M22            017777777
#define M23            037777777
#define CNTMSK         077700000
#define CHCMSK         017700000
#define NMASK          037777400
#define MMASK          037777000

#define CHAR_DEV       0            /* Device transfers via characters */
#define WORD_DEV       1            /* Device transfers via words */

struct icl_dib {
       uint8       channel;         /* Channel number */
       uint8       type;            /* Type of device */
       t_stat      (*dev_cmd)(uint32 cmd, uint32 *resp);   /* Start io on device */
};

typedef struct icl_dib DIB;

/* Hessitation operations */
int chan_write_char(uint8 channel, uint8 data);
int chan_read_char(uint8 channel, uint8 *data);
int chan_write_word(uint8 channel, uint32 data);
int chan_read_word(uint8 channel, uint32 *data);
int chan_end(uint8 channel);

/* Console tty device routines */
extern t_stat      ctyi_cmd(uint32 cmd, uint32 *resp);
extern t_stat      ctyo_cmd(uint32 cmd, uint32 *resp);

/* Generic devices common to all */
extern DEVICE      cpu_dev; 
extern UNIT        cpu_unit[]; 
extern REG         cpu_reg[];

/* Global device definitions */
extern DEVICE       cty_dev; 
extern DEVICE       cdr_dev; 
extern DEVICE       cdp_dev; 
extern DEVICE       lpr_dev; 
extern DEVICE       dtc_dev; 
extern DEVICE       dsk_dev; 
extern DEVICE       mt_dev; 

#endif /* _ICL1900_H_ */
