/*
 * (C) Copyright 2015, 2016, Freescale Semiconductor, Inc.
 * (C) Copyright 2016-2018, NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/qspi_common.h>
#include <asm/arch/siul.h>
#include <asm/io.h>

void qspi_iomux()
{
	/* CS0, SCK and CK2 use the same base pinmux settings
	 * 0x0020d700 - SIUL2_PORT_MSCR_CTRL_QSPI_CLK_BASE */

	/* QSPI0_A_CS0 - U25 - PK5 */
	writel(SIUL2_PK5_MSCR_MUX_MODE_QSPI_A_CS0 |
	       SIUL2_PORT_MSCR_CTRL_QSPI_CLK_BASE, SIUL2_MSCRn(SIUL2_PK5_MSCR));
	/* QSPI0_A_SCK - V25 - PK6 */
	writel(SIUL2_PK6_MSCR_MUX_MODE_QSPI_A_SCK |
	       SIUL2_PORT_MSCR_CTRL_QSPI_CLK_BASE, SIUL2_MSCRn(SIUL2_PK6_MSCR));

	#ifdef CONFIG_S32_FLASH
	/*
	 * XXX: This signal should not be needed with hyperflash powered at 3V,
	 * but it seems the AHB access blocks without it
	 */
	/* QSPI0_CK2 - B_SCK? V24 - PK13 */
	writel(SIUL2_PK13_MSCR_MUX_MODE_QSPI_CK2 |
	       SIUL2_PORT_MSCR_CTRL_QSPI_CLK_BASE,
	       SIUL2_MSCRn(SIUL2_PK13_MSCR));

	/* QSPI0_A_DQS - U22 - PK7 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DQS, SIUL2_MSCRn(SIUL2_PK7_MSCR));
	writel(SIUL2_PK7_IMCR_MUX_MODE_QSPI_A_DQS,
	       SIUL2_IMCRn(SIUL2_PK7_IMCR_QSPI_A_DQS));
	#else

	/* QSPI0_B_CS0 - W25 - PK12 */
	writel(SIUL2_PK12_MSCR_MUX_MODE_QSPI_B_CS0 |
	       SIUL2_PORT_MSCR_CTRL_QSPI_CLK_BASE, SIUL2_MSCRn(SIUL2_PK12_MSCR));
	/* QSPI0_B_SCK - V24 - PK13 */
	writel(SIUL2_PK13_MSCR_MUX_MODE_QSPI_B_SCK |
	       SIUL2_PORT_MSCR_CTRL_QSPI_CLK_BASE, SIUL2_MSCRn(SIUL2_PK13_MSCR));

	#endif

	/* note: an alternative A_DATA0_3/4_7 CTRL is 0x0028C301/0x0028C302 */
	/* A_DATA 0-3 */
	/* QSPI0_A_D3 - V22 - PK11 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA0_3,
	       SIUL2_MSCRn(SIUL2_PK11_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7,
	       SIUL2_IMCRn(SIUL2_PK11_IMCR_QSPI_A_DATA3));

	/* QSPI0_A_D2 - V21 - PK10 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA0_3,
	       SIUL2_MSCRn(SIUL2_PK10_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7,
	       SIUL2_IMCRn(SIUL2_PK10_IMCR_QSPI_A_DATA2));

	/* QSPI0_A_D1 - U23 - PK9 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA0_3,
	       SIUL2_MSCRn(SIUL2_PK9_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7,
	       SIUL2_IMCRn(SIUL2_PK9_IMCR_QSPI_A_DATA1));

	/* QSPI0_A_D0 - V23 - PK8 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA0_3,
	       SIUL2_MSCRn(SIUL2_PK8_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7,
	       SIUL2_IMCRn(SIUL2_PK8_IMCR_QSPI_A_DATA0));

	#ifdef CONFIG_S32_FLASH
	/* A_DATA 4-7 */
	/* QSPI0_A_DATA7 - R21 - PL2 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA4_7,
	       SIUL2_MSCRn(SIUL2_PL2_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7,
	       SIUL2_IMCRn(SIUL2_PL2_IMCR_QSPI_A_DATA7));

	/* QSPI0_A_DATA6 - U24 - PL1 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA4_7,
	       SIUL2_MSCRn(SIUL2_PL1_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7,
	       SIUL2_IMCRn(SIUL2_PL1_IMCR_QSPI_A_DATA6));

	/* QSPI0_A_DATA5 - U21 - PL0 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA4_7,
	       SIUL2_MSCRn(SIUL2_PL0_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7,
	       SIUL2_IMCRn(SIUL2_PL0_IMCR_QSPI_A_DATA5));

	/* QSPI0_A_DATA4 - W23 - PK15 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA4_7,
	       SIUL2_MSCRn(SIUL2_PK15_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7,
	       SIUL2_IMCRn(SIUL2_PK15_IMCR_QSPI_A_DATA4));

	#else
	/* B_DATA 0-3 */
	/* QSPI0_B_DATA7 - R21 - PL2 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_B_DATA0_3,
	       SIUL2_MSCRn(SIUL2_PL2_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_B_DATA0_3,
	       SIUL2_IMCRn(SIUL2_PL2_IMCR_QSPI_B_DATA3));

	/* QSPI0_B_DATA6 - U24 - PL1 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_B_DATA0_3,
	       SIUL2_MSCRn(SIUL2_PL1_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_B_DATA0_3,
	       SIUL2_IMCRn(SIUL2_PL1_IMCR_QSPI_B_DATA2));

	/* QSPI0_B_DATA5 - U21 - PL0 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_B_DATA0_3,
	       SIUL2_MSCRn(SIUL2_PL0_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_B_DATA0_3,
	       SIUL2_IMCRn(SIUL2_PL0_IMCR_QSPI_B_DATA1));

	/* QSPI0_B_DATA4 - W23 - PK15 */
	writel(SIUL2_PORT_MSCR_CTRL_QSPI_B_DATA0_3,
	       SIUL2_MSCRn(SIUL2_PK15_MSCR));
	writel(SIUL2_PORT_IMCR_MUX_MODE_QSPI_B_DATA0_3,
	       SIUL2_IMCRn(SIUL2_PK15_IMCR_QSPI_B_DATA0));
	#endif


}				/* qspi_iomux */

#ifndef CONFIG_S32_FLASH
int do_qspinor_setup(cmd_tbl_t *cmdtp, int flag, int argc,
			    char * const argv[])
{
	printf("SD/eMMC is disabled. SPI flash is active and can be used!\n");
	qspi_iomux();
	return 0;
}
#endif

/* qspinor setup */
U_BOOT_CMD(
	flsetup, 1, 1, do_qspinor_setup,
	"setup qspi pinmuxing and qspi registers for access to flash",
	"\n"
	"Set up the pinmuxing and qspi registers to access the flash\n"
	"    and disconnect from the SD/eMMC.\n"
);
