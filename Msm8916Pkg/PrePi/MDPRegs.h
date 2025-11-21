#ifndef _MDP_REGS_H_
#define _MDP_REGS_H_

#define PIPE_SSPP_SRC_FORMAT                    0x30
#define PIPE_SSPP_SRC_UNPACK_PATTERN            0x34
#define PIPE_BASE				0x1A15000
#define PIPE_BASE1				0x1A17000
#define PIPE_SSPP_SRC_YSTRIDE			0x24

#define MDP_BASE                    (0x1A00000)
#define REG_MDP(off)                (MDP_BASE + (off))
#define MDP_HW_REV                              REG_MDP(0x1000)
#define MDP_VP_0_VIG_0_BASE                     REG_MDP(0x5000)
#define MDP_VP_0_VIG_1_BASE                     REG_MDP(0x7000)
#define MDP_VP_0_RGB_0_BASE                     REG_MDP(0x15000)
#define MDP_VP_0_RGB_1_BASE                     REG_MDP(0x17000)
#define MDP_VP_0_DMA_0_BASE                     REG_MDP(0x25000)
#define MDP_VP_0_DMA_1_BASE                     REG_MDP(0x27000)
#define MDP_VP_0_MIXER_0_BASE                   REG_MDP(0x45000)
#define MDP_VP_0_MIXER_1_BASE                   REG_MDP(0x46000)

#define MDP_CTL_0_BASE                          0x1A02000
#define MDP_CTL_1_BASE                          0x1A02200
#define CTL_FLUSH				0x18

#endif /* _MDP_REGS_H_ */
