#ifndef _NAS782X_CPU_H
#define _NAS782X_CPU_H

#if !(defined(__KERNEL_STRICT_NAMES) || defined(__ASSEMBLY__))
#include <asm/types.h>
#include <asm/io.h>
#endif /* !(__KERNEL_STRICT_NAMES || __ASSEMBLY__) */

#include <asm/arch/hardware.h>
#include <asm/arch/timer.h>

#ifndef __KERNEL_STRICT_NAMES
#ifndef __ASSEMBLY__

#define BIT(x)                  (1 << (x))

static inline void reg_clear_bit(int reg, int mask)
{
	u32 value;
	value = readl(reg);
	value &= ~mask;
	writel(value, reg);
}

static inline void reg_set_bit(int reg, int mask)
{
	u32 value;
	value = readl(reg);
	value |= mask;
	writel(value, reg);
}

static inline void debug_green_on(void)
{
	writel(0x30000, 0x4410001C);
	writel(0x20000, 0x44100018);
}

static inline void debug_orange_on(void)
{
	writel(0x30000, 0x4410001C);
	writel(0x10000, 0x44100018);
}

static inline void debug_green_off(void)
{
	writel(0x30000, 0x4410001C);
	writel(0x20000, 0x44100014);
}

static inline void debug_orange_off(void)
{
	writel(0x30000, 0x4410001C);
	writel(0x10000, 0x44100014);
}

#endif /* __ASSEMBLY__ */
#endif /* __KERNEL_STRICT_NAMES */

#endif /* _NAS782X_CPU_H */
